#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void fInBytes(FILE *fp)
{
    char c;

    for (int i = 0; i < 10; i++)
    {
        c = fgetc(fp);

        if (c == EOF) 
        { 
            for (int j = 0; j < 10 - i; j++) //For last line line-up 
            {
                printf("\t"); 
                return; 
            }
        }

        printf("%02x ", c);
    }

    printf("\t");
}

void fInChars(FILE *fp)
{
    char c;

    for (int i = 0; i < 10; i++)
    {
        c = fgetc(fp);
        if (c == EOF) { return; }

        if (isprint((unsigned char) c)) { printf("%c", c); }
        else { printf("%c", '.'); }
    }

    printf("\n");
}

void fOffset(FILE *fp)
{}

int fCountChar(FILE *fp)
{
    char c;
    int count = 0; //Counts characters

    //Iterate through file
    while ((c = fgetc(fp)) != EOF)
    {
        count++;
    }
    
    return count;
}

int main(void)
{
    FILE *fp1 = fopen("/root/Documents/Uni/CSCU9V4/Practical-8/testfile.txt", "r");
    FILE *fp2 = fopen("/root/Documents/Uni/CSCU9V4/Practical-8/testfile.txt", "r");
    FILE *fp3 = fopen("/root/Documents/Uni/CSCU9V4/Practical-8/testfile.txt", "r");

    if (fp1 == NULL)
    {
        printf("Failed opening %s\n", "testfile.txt");
        exit(EXIT_FAILURE);
    }

    int chars = fCountChar(fp3);

    for (int i = 0; i < chars; i += 10)
    {
        fInBytes(fp1);
        fInChars(fp2);
    }
}
