#include "fibonacci.h"

long long recursive(int n){
    if(n<1){
        printf("Bad Parameter");
        return -1;
    }
    if(n==1 || n==2)
        return 1;
    else
        return recursive(n-1) + recursive(n-2);
}

