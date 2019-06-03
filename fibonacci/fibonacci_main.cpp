#include <time.h>
#include "fibonacci.h"

enum {Matrix=0, Recursive=1, Loop=2, Formula=3};

using namespace std;
using namespace std::chrono;

//typedef chrono::duration<long int, std::ratio<1, 1000000> > timedelta_t;
void eval_fibonacci_timecomplexity(int num_entries, vector< vector<double> > *perf_matrix_pt);

int main(int , const char**)
{
    vector<int> num_entries {5, 10, 20, 40, 60, 70};
    vector< vector<double> > performance(4);


    for(auto n : num_entries)
    {
    	eval_fibonacci_timecomplexity(n, &performance);
    }

    for(auto method : performance)
    {
	for(auto array_element : method)
		cout << array_element << ", ";
	cout << endl;
    
    }
    
    return 0;
}

void eval_fibonacci_timecomplexity(int num_entries, vector< vector<double> > *perf_mat_pt)
{
	
    long long n;
    
    int sign=1;
    if(num_entries<0 && abs(num_entries)%2==0)   // if N is negative and divisible by 2 then Nth fibonacci must be negative
        sign=-1;

    clock_t start = clock();
    n = matrix((long long)num_entries);
    clock_t stop = clock();

    perf_mat_pt->at(Matrix).push_back((double)(stop - start)/CLOCKS_PER_SEC);
    cout<< "MATRIX -  " << perf_mat_pt->at(Matrix).back() << " milliseconds for " << num_entries << " entries\n";
    // -------------------------------------------------------------------------------------------------------------
    
    start = clock(); 
    n = recursive((int)num_entries);
    stop = clock();

    perf_mat_pt->at(Recursive).push_back((double)(stop - start)/CLOCKS_PER_SEC);
    cout<< "NAIVE_RECURSION -  " << perf_mat_pt->at(Recursive).back() << " milliseconds for " << num_entries << " entries\n";
    // -------------------------------------------------------------------------------------------------------------
    
    start = clock(); 
    n = loop((int)num_entries);
    stop = clock();
    
    perf_mat_pt->at(Loop).push_back((double)(stop - start)/CLOCKS_PER_SEC);
    cout<< "LOOP " << n << " -  " << perf_mat_pt->at(Loop).back() << " milliseconds for " << num_entries << " entries\n";
    // -------------------------------------------------------------------------------------------------------------
    
    start = clock(); 
    n = binets_formula((int)num_entries);
    stop = clock();
    
    perf_mat_pt->at(Formula).push_back((double)(stop - start)/CLOCKS_PER_SEC);
    cout<< "BINETS_FORMULA -  " << perf_mat_pt->at(Formula).back() << " milliseconds for " << num_entries << " entries\n";
    // -------------------------------------------------------------------------------------------------------------
}
