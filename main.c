#include "stdio.h"

int main()
{
    char text[] = "cat dog hen duck goat pig horse rabbit sheep cow lion tiger wolf fox elephant cock hippo reindeer owl eagle sparrow swallow";

    int letterCount = 0;
    int letterCountOccurency[16] = { 0 };

    int totalWords = 0;

    printf("List of words in string:\n\n");

    for(int i = 0; i < sizeof(text) / sizeof(text[0]); i++)
    {
        if(text[i] == ' ' || text[i] == '\0')
        {
            if (letterCount)
            {
                letterCountOccurency[letterCount-1]++;

                for(int j = letterCount; j > 0; j--)
                    printf("%c", (j == letterCount) ? text[i-j]-32 : text[i-j]);

                printf("\n");
            }
            letterCount = 0;
        }
        else
            letterCount++;
    }
    printf("\n");

    for(int i = 0; i < 16; i++)
    {
        if(letterCountOccurency[i])
        {
            printf("The number of words with %d characters is %2d.\n", i + 1, letterCountOccurency[i]);
            totalWords += letterCountOccurency[i]; // Tohle by mohlo byt i mimo podminku, ale proc pricitat nulu kdyz uz mam podminku
        }
    }

    printf("\nThe total number of words is %3d.\n", totalWords);

    return 0;
}
