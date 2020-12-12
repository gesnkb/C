#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ALPHATEST1 "abc67890efghijk123z"
#define UPPERTEST1 "AbCDefghijKLMNOpqrSTUVwxyZ"
#define UPPERTEST2 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int IsAlpha(char *s)
{
    for(int i = 0; s[i] != '\0'; i++){
        if( isalpha(s[i])== 0){
            return 0;
        }
    }
    return 1;
}

int IsUpper(char *s)
{
    for(int i = 0; s[i] != '\0'; i++){
        if( s[i] >= 'a' && s[i] <= 'z'){
            return 0;
        }
    }
    return 1;
}

void ToUpper(char *s)
{
    int i = 0;

    while(s[i] != '\0'){
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = s[i] - 32;
        }
        i++;
    }
}


int main(void)
{
    char sUpperTest1[] = UPPERTEST1;
    char sUpperTest2[] = UPPERTEST2;

    if(IsAlpha(ALPHATEST1))
    {
        printf("ALPHATEST1 is all alpha\n");
    }
    else
    {
        printf("ALPHATEST1 is not all alpha\n");
    }
    if(IsUpper(sUpperTest1))
    {
        printf("UPPERTEST1 is all upper case: %s\n", sUpperTest1);
    }
    else
    {
        ToUpper(sUpperTest1);
        printf("The upper case version of UPPERTEST1 is: %s\n", sUpperTest1);
    }
    if(IsUpper(sUpperTest2))
    {
        printf("UPPERTEST2 is all upper case: %s\n", sUpperTest2);
    }
    else
    {
        ToUpper(sUpperTest2);
        printf("The upper case version of UPPERTEST2 is: %s\n", sUpperTest2);
    }

    return 0;

}
