#include <stdio.h>
#include <math.h>

void GetPromptString(char *output)
{
    scanf("%s", output);
}

void GetPromptAndGetInteger(char *prompt, int *output)
{
    printf(" %s: ", prompt);
    scanf(" %d ", output);

}

void GetProduct(int a, int b, int *product)
{
    *product = a * b;
}

int main(void)
{
    char output[31];

    char output2[31];

    printf("********\n * Welcome to Lab 6 *\n ********\n");
    
    printf("Enter the prompt for a:\n");
    GetPromptString(output);

    printf("Enter the prompt for b:\n");
    GetPromptString(output2);
    
    int response;
    int response2;

    int *output3 = &response;
    int *output4 = &response2;

    GetPromptAndGetInteger(output, output3);
    GetPromptAndGetInteger(output2, output4);
    
    int a = *output3;
    int b = *output4;
    int product;
    GetProduct(a, b, &product);
    printf("The product of %d and %d is %d\n", a, b, product);

    return 0;

}
