#include "fibonacci.h"

long long binets_formula(int n)
{
    // as we use sqrt(5), pre-calculate it to make the formula look neater
    double sqrt5 = sqrt(5);

    long long F_n = ( pow((1 + sqrt5), n) - pow((1 - sqrt5), n) ) / ( pow(2, n) * sqrt5 );

    return F_n;
}
