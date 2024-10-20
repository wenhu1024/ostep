#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024

void mycat(const char *filename)
{
    static char buffer[SIZE];

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("wcat: cannot open file\n");
        exit(1);
    }

    while (fgets(buffer, SIZE, fp) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(fp);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return 0;
    }

    for (int i = 1; i < argc; ++i)
    {
        mycat(argv[i]);
    }

    return 0;
}
