#include "fibonacci.h"

// Using matrix exponentiation we can find nth fibonacci in log(N) time complexity

long long matrix(long long  n)
{
    n=abs(n);   // We take absolute value for calculation

    Matrix rslt(1,0,0,1);  // Resultant Matrix
    Matrix base(1,1,1,0);  // Base Matrix

    while(n>0)
    {
        if(n&1)
            rslt=rslt*base;
        base=base*base;
        n>>=1;
    }

    return rslt.c;  // Fib(n)
}

