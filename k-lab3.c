#include <stdio.h>
#include <math.h>
int main ( void )
{
    int KeepGoing = 0;

    do{
        int n;
        int sum = 0;

        printf("Enter the high limit of the summation you wish to calculate:\n");
        scanf("%d", &n);

        switch (n < 0){
            case 1:
            printf("** Error: You must enter a non negative number:\n ");
            break;

            default:
            printf("Calculating summations up to %d\n", n);
            for( int i = 0; i <= n; i++){
                sum = sum + i;
                printf(" Summation (0..%d) = %d\n", i, sum);
            }

        }

        printf("Enter 0 to quit or 1 to continue:\n");
        scanf("%d", &KeepGoing);

    }while(KeepGoing ==1); 



    return 0;
}
