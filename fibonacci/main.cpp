#include "fibonacci.h"
#include <time.h>

enum Tests {Matrix=0, Recursive, Loop, Formula};

using namespace std;

int main()
{
    long method[4][6];	// 6 entry_size's for each of the 4 methods
    long long  N, n;
    cin>>N; // Input Number

    int sign=1;
    if(N<0 && abs(N)%2==0)   // if N is negative and divisible by 2 then Nth fibonacci must be negative
        sign=-1;

    n = matrix((long long)N);
    cout<<"MATRIX - Nth fibonacci number is: ";
    cout<<( sign * n )<<endl;
   
    n = recursive((int)N);
    cout<<"NAIVE_RECURSION - Nth fibonacci number is: ";
    cout<<( sign * n )<<endl;
    
    n = loop((int)N);
    cout<<"LOOP - Nth fibonacci number is: ";
    cout<<( sign * n )<<endl;
    
    n = binets_formula((int)N);
    cout<<"BINETS_FORMULA - Nth fibonacci number is: ";
    cout<<( sign * n )<<endl;

    return 0;
}
