#include <stdio.h>
#include <stddef.h>

void PromptAndGetStrings(char *prompt, char output[][256])
{
    printf(" 1. %s\n", prompt);
    scanf("%s", &output[0][0]);

    printf(" 2. %s\n", prompt);
    scanf("%s", &output[1][0]);

    printf(" 3. %s\n", prompt);
    scanf("%s", &output[2][0]);
}

unsigned int StrLen(char * string)
{
    unsigned int slength = 0;

    while(*string != '\0'){
        slength++;
        string++;
    }

    return slength;
}
void ReverseString(char *string)
{
    int length;
    int i;
    char *begin;
    char *end;
    char temp;

    length = StrLen(string);
    begin = string;
    end = string;

    for(i = 0; i < length - 1; i++)
        end++;

        for( i = 0; i < length/2; i++){
            temp = *end;
            *end = *begin;
            *begin = temp;

            begin++;
            end--;
        }

        printf("Reversed string: %s with a length of: %d\n", string, length);
}

int main(void)
{
    char output[3][256];
    char *prompt1;
    prompt1 = " Please enter a string:\0";

    char *string1 = &output[0][0];
    char *string2 = &output[1][0];
    char *string3 = &output[2][0];

    printf("*** Welcome to Lab 7 ***\n");

    PromptAndGetStrings(prompt1, output);

    int length1 = StrLen(string1);
    printf("You entered: %s with a length of: %d\n", string1, length1);

    int length2 = StrLen(string2);
    printf("You entered: %s with a length of: %d\n", string2, length2);

    int length3 = StrLen(string3);
    printf("You entered: %s with a length of: %d\n", string3, length3);

    ReverseString(string1);
    ReverseString(string2);
    ReverseString(string3);

    printf("*** Thanks for doing Lab 7 ***\n");



    return 0;
}
