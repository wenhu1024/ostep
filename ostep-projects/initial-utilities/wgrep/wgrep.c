#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *lineptr = NULL;
    size_t n = 0;

    if (argc < 2)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    if (argc == 2)
    {
        while ((getline(&lineptr, &n, stdin) > 0))
        {
            if (strstr(lineptr, argv[1]) != NULL)
            {
                printf("%s", lineptr);
            }
        }
    }
    else
    {
        FILE *fp = NULL;
        for (int i = 2; i < argc; ++i)
        {
            fp = fopen(argv[i], "r");
            if (fp == NULL)
            {
                printf("wgrep: cannot open file\n");
                exit(1);
            }
            while ((getline(&lineptr, &n, fp) > 0))
            {
                if (strstr(lineptr, argv[1]) != NULL)
                {
                    printf("%s", lineptr);
                }
            }
            fclose(fp);
        }
    }
    free(lineptr);
    return 0;
}
