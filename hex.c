#include <stdio.h>
#include <stdlib.h>

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
        printf("%c", c);
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
        printf("%x ", c);
    }

    fclose(fp);
    
    return count;
}
int main(void)
{
    printf("File in characters: \n\n"); 
    fInChar("testfile.txt");

    puts("");

    printf("File in bytes: \n\n"); 
    fInBytes("testfile.txt");

    return 0;
}
