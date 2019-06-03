#include <chrono>
#include "fibonacci.h"

enum {Matrix=0, Recursive=1, Loop=2, Formula=3};

using namespace std;
using namespace std::chrono;

typedef chrono::duration<long int, std::ratio<1, 1000000> > timedelta_t;
void eval_fibonacci_timecomplexity(int num_entries, vector< vector<timedelta_t> > *perf_matrix_pt);

int main(int , const char**)
{
    vector<int> num_entries {5, 10, 20, 40, 60, 70};
    vector< vector<timedelta_t> > performance(4);


    for(auto n : num_entries)
    {
    	eval_fibonacci_timecomplexity(n, &performance);
    }

    for(auto method : performance)
    {
	for(auto array_element : method)
		cout << array_element.count() << ", ";
	cout << endl;
    
    }
    
    return 0;
}

void eval_fibonacci_timecomplexity(int num_entries, vector< vector<timedelta_t> > *perf_mat_pt)
{
	
    long long n;
    
    int sign=1;
    if(num_entries<0 && abs(num_entries)%2==0)   // if N is negative and divisible by 2 then Nth fibonacci must be negative
        sign=-1;

    auto start = high_resolution_clock::now();
    //n = matrix((long long)num_entries);
    auto stop = high_resolution_clock::now();

    //perf_mat_pt->at(Matrix).push_back(duration_cast<microseconds>(stop - start));
    //cout<< "MATRIX -  " << perf_mat_pt->at(Matrix).back().count() << " microseconds for " << num_entries << " entries\n";
    // -------------------------------------------------------------------------------------------------------------
    
    //start = high_resolution_clock::now(); 
    //n = recursive((int)num_entries);
    //stop = high_resolution_clock::now();

    //perf_mat_pt->at(Recursive).push_back(duration_cast<microseconds>(stop - start));
    //cout<< "NAIVE_RECURSION -  " << perf_mat_pt[Recursive][FiveEntries].count() << " microseconds for " << num_entries, << " entries\n";
    // -------------------------------------------------------------------------------------------------------------
    
    start = high_resolution_clock::now(); 
    n = loop((int)num_entries);
    stop = high_resolution_clock::now();
    
    perf_mat_pt->at(Loop).push_back(duration_cast<microseconds>(stop - start));
    cout<< "LOOP " << n << " -  " << perf_mat_pt->at(Loop).back().count() << " microseconds for " << num_entries << " entries\n";
    // -------------------------------------------------------------------------------------------------------------
    
    //start = high_resolution_clock::now(); 
    //n = binets_formula((int)num_entries);
    //stop = high_resolution_clock::now();
    
    //perf_mat_pt->at(Formula).push_back(duration_cast<microseconds>(stop - start));
    //cout<< "BINETS_FORMULA -  " << perf_mat_pt[Formula][FiveEntries].count() << " microseconds for " << num_entries, << " entries\n";
    // -------------------------------------------------------------------------------------------------------------
}
