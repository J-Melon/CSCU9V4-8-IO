#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int fCountChar(const char *filename)
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
        count++;
    }

    fclose(fp);
    
    return count;
}

int fCountWords(const char *filename)
{
    FILE *fp = fopen (filename, "r");

    //File doesn't exist or something
    if (fp == NULL)
    {
        printf("Failed opening %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char c;
    int lastSpace = 1; //Checks if the last character was a space 
    int count = 0; //Counts words

    //Iterate through file
    while ((c = fgetc(fp)) != EOF)
    {
        if (isspace((unsigned char) c))
        {
            lastSpace = 1;
        }
        else if (lastSpace)
        {
            count++;
            lastSpace = 0;
        }
    }

    return count;
}

int fCountLines(const char *filename)
{
    FILE *fp = fopen (filename, "r");

    //File doesn't exist or something
    if (fp == NULL)
    {
        printf("Failed opening %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char c;
    int count = 0; //Counts lines

    //Iterate through file
    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '\n')
        {
            count++;
        }
    }

    return count;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Please only use one agrument.");
        exit(EXIT_FAILURE);
    }

    printf("Number of characters in file: %d\n", fCountChar(argv[1]));
    printf("Number of words in file: %d\n", fCountWords(argv[1]));
    printf("Number of lines in file: %d\n", fCountLines(argv[1]));
    
    return 0;
}
