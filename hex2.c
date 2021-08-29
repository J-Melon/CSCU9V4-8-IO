#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void fInBytes(FILE *fp)
{
    char c; //Currently read char
    
    //Iterate ten bytes across
    for (int i = 0; i < 10; i++)
    {
        c = fgetc(fp);

        if (c == EOF) 
        { 
            //For last line line-up (last characters in right place)
            for (int j = 0; j < 10 - i; j++) { printf("   "); }

            printf("  "); //Spaces tab gap between bytes and characters

            return; 
        }

        printf("%02x ", c &0xff); //Bytes
    }

    printf("\t"); //End byte line
}

void fInChars(FILE *fp)
{
    char c; //Currently read char

    //Iterate ten characters across
    for (int i = 0; i < 10; i++)
    {
        c = fgetc(fp);

        if (c == EOF) { return; }

        if (isprint((unsigned char) c)) { printf("%c", c); }
        else { printf("%c", '.'); }
    }

    printf("\n");
}

int fCountChar(FILE *fp)
{
    char c;
    int count = 0; //Counts characters

    //Iterate through file
    while ((c = fgetc(fp)) != EOF) { count++; }
    
    return count;
}

int main(int argc, char *argv[])
{
    FILE *fp1 = fopen(argv[1], "rb"); //For bytes
    FILE *fp2 = fopen(argv[1], "r"); //For characters
    FILE *fp3 = fopen(argv[1], "r"); //For iterating line by line

    if (fp1 == NULL)
    {
        printf("Failed opening %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int chars = fCountChar(fp3);

    printf("Offset\t\t    Bytes\t\tCharacters\n");
    printf("------  -----------------------------   ----------\n");

    // Loops line by line for x lines according to length of file (chars)
    for (int i = 0; i < chars; i += 10)
    {
        printf("%d\t", i); //Offset 

        fInBytes(fp1);
        fInChars(fp2);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;
}
