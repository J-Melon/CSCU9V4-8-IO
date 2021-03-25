#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int fInChar(const char *filename)
{
    FILE *fp = fopen (filename, "r");
    
    //File doesn't exist or something
    if (fp == NULL)
    {
        printf("Failed opening %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char c;
    int count = 0; //Counts characters

    //Iterate through file
    while ((c = fgetc(fp)) != EOF)
    {
        if (isprint((unsigned char) c))
        {
            printf("%c", c);
        }
        else
        {
            printf("%c", '.');
        }

        count++;

        if (count % 10 == 0)
        {
            printf("\n");
        }
    }

    fclose(fp);
    
    return count;
}

int fInBytes(const char *filename)
{
    FILE *fp = fopen (filename, "r");
    
    //File doesn't exist or something
    if (fp == NULL)
    {
        printf("Failed opening %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char c;
    int count = 0; //Counts characters

    //Iterate through file
    while ((c = fgetc(fp)) != EOF)
    {
        printf("%02x ", c);
        count++;

        if (count % 10 == 0)
        {
            printf("\n");
        }
    }

    fclose(fp);
    
    return count;
}


int main(int argc, char *argv[])
{
    printf("File in characters: \n\n");
    fInChar(argv[1]);

    printf("\n\n");

    printf("File in bytes: \n\n");
    fInBytes(argv[1]);

    return 0;
}
