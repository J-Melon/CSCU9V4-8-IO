#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//This does not include whitespace
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

int main(void)
{
    printf("Number of characters in file: %d\n", fCountChar("sam.txt"));
    printf("Number of words in file: %d\n", fCountWords("sam.txt"));
    printf("Number of lines in file: %d\n", fCountLines("sam.txt"));
    
    return 0;
}
