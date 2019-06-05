#include "fibonacci.h"

// Using matrix exponentiation we can find nth fibonacci in log(N) time complexity

long long matrix(long long  n)
{
    long long temp=n;  // For printing the resultant Matrix

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

    // Uncomment below line to see Required Matrix..
    // printMatrix(temp, rslt);

    //
    // [ rslt.a   rslt.b ]     [Fib(n+1)  Fib(n)  ]
    //                    =>
    // [ rslt.c   rslt.d ]     [Fib(n)    Fib(n-1)]
    //

    return rslt.c;  // Fib(n)
}

