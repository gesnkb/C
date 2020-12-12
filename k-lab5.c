#include <stdio.h>
#include <math.h>
#define LIMIT 10

void InitArraySquare(int array[], int size)
{
for(int i = 0; i <= LIMIT; i++){
    array[i] = i * i;
}
}

void InitArrayLinear(int array[], int size)
{
for(int i = 0; i <= LIMIT; i++){
    array[i] = i;
}
}

void PrintArray(int array[], int size)
{
    for(int i = 0; i < LIMIT; i++){
        printf("%d\n", array[i]);
    }
}
 
void SumArrays(int array1[], int array2[], int size)
{
    int sum = 0;

    for(int i = 0; i < LIMIT; i++){
        sum = sum + array1[i] + array2[i];
    }
        printf("%d\n", sum);
}

void MultArrays(int array1[], int array2[], int size)
{
    int product = 0;

    for(int i = 0; i < LIMIT; i++){
        product = product +  array1[i] * array2[i];
    }
        printf("%d\n", product);
}



int main(void)
{
    int firstarray[LIMIT];
    int secondarray[LIMIT];

InitArraySquare(firstarray, LIMIT);
    PrintArray(firstarray, LIMIT);
    printf("Array 1:\n");

InitArrayLinear(secondarray, LIMIT);
    PrintArray(secondarray, LIMIT);
    printf("Array 2:\n");

    SumArrays(firstarray, secondarray, LIMIT);
    printf("Sum of elements of array:\n");

    MultArrays(firstarray, secondarray, LIMIT);
    printf("Product of arrays:\n");


}



