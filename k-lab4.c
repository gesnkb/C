#include <stdio.h>
#include <math.h>
double Power( double base, int exponent)
{
    double result = base;

    if( exponent < 1 || 100 < exponent ){
        exponent = 1;
    }
    if( exponent != 1 ){

       result = result * Power(base, exponent -1);
    }

    return result;
}

void DoTest( double base, int exponent )
{
    printf("Test Power(%lf,%d)\n", base, exponent);

if(Power(base, exponent) == pow(base, exponent) ){
    printf("Succeeded! *\n");

}
else{
    printf("Failed. *\n");
}
}

int main( void )
{
    printf("** Welcome to the Power Calculation Program **\n\n");

    DoTest(1,1);
    DoTest(2,2);
    DoTest(1.05,10);
    DoTest(1.05, 100);
    DoTest(-1,2);
    DoTest(-1.05,10);
    DoTest(5,101);
    DoTest(5.3,0);
    DoTest(5.7,-1);
return 0;
}









