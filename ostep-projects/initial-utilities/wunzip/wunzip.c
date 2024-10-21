#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    FILE *fp = NULL;
    int cnt;
    char c;

    for (int i = 1; i < argc; ++i)
    {
        fp = fopen(argv[i], "rb");
        if (fp == NULL)
        {
            printf("wzip: can not open file\n");
        }
        while ((fread(&cnt, sizeof(int), 1, fp) == 1) && (fread(&c, sizeof(char), 1, fp) == 1))
        {
            while (cnt--)
            {
                printf("%c", c);
            }
        }

        fclose(fp);
    }
    return 0;
}
