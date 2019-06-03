#include <chrono>
#include "fibonacci.h"

enum {Matrix=0, Recursive=1, Loop=2, Formula=3};

using namespace std;
using namespace std::chrono;

typedef chrono::duration<long int, std::ratio<1, 1000000> > timedelta_t;

int main(int , const char**)
{
    vector<int> num_entries {5, 10, 20, 40, 60, 70};
    vector< vector<timedelta_t> > performance(4);


    for(auto : num_entries)
    {
    	eval_fibonacci_timecomplexity(num_entries, &performance);
    }

    
    return 0;
}

void eval_fibonacci_timecomplexity(int num_entries, vector< vector<timedelta_t> > *perf_matrix)
{
	
    long long  N, n;
    
    int sign=1;
    if(N<0 && abs(N)%2==0)   // if N is negative and divisible by 2 then Nth fibonacci must be negative
        sign=-1;

    auto start = high_resolution_clock::now();
    n = matrix((long long)N);
    auto stop = high_resolution_clock::now();

    performance[Matrix].push_back(duration_cast<microseconds>(stop - start));
    cout<< "MATRIX -  " << performance[Matrix][FiveEntries].count() << " milliseconds for " << N << " entries\n";
    // -------------------------------------------------------------------------------------------------------------
    
    start = high_resolution_clock::now(); 
    n = recursive((int)N);
    stop = high_resolution_clock::now();

    performance[Recursive].push_back(duration_cast<microseconds>(stop - start));
    cout<< "NAIVE_RECURSION -  " << performance[Recursive][FiveEntries].count() << " milliseconds for " << N << " entries\n";
    // -------------------------------------------------------------------------------------------------------------
    
    start = high_resolution_clock::now(); 
    n = loop((int)N);
    stop = high_resolution_clock::now();
    
    performance[Loop].push_back(duration_cast<microseconds>(stop - start));
    cout<< "LOOP -  " << performance[Loop][FiveEntries].count() << " milliseconds for " << N << " entries\n";
    // -------------------------------------------------------------------------------------------------------------
    
    start = high_resolution_clock::now(); 
    n = binets_formula((int)N);
    stop = high_resolution_clock::now();
    
    performance[Formula].push_back(duration_cast<microseconds>(stop - start));
    cout<< "BINETS_FORMULA -  " << performance[Formula][FiveEntries].count() << " milliseconds for " << N << " entries\n";
    // -------------------------------------------------------------------------------------------------------------
}
