#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    FILE *fp = NULL;
    int cnt = 1;
    char last, current;

    for (int i = 1; i < argc; ++i)
    {
        fp = fopen(argv[i], "rb");
        if (fp == NULL)
        {
            printf("wzip: can not open file\n");
        }
        if (i == 1)
        {
            if (fread(&last, sizeof(char), 1, fp) != 1)
            {
                printf("wzip: cannot zip empty file\n");
                fclose(fp);
                exit(1);
            }
        }

        while (fread(&current, sizeof(char), 1, fp) == 1)
        {
            if (last == current)
            {
                ++cnt;
            }
            else
            {
                fwrite(&cnt, sizeof(int), 1, stdout);
                fwrite(&last, sizeof(char), 1, stdout);
                last = current;
                cnt = 1;
            }
        }
        fclose(fp);
    }
    fwrite(&cnt, sizeof(int), 1, stdout);
    fwrite(&last, sizeof(char), 1, stdout);

    return 0;
}
