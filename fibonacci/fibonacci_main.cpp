#include <time.h>
#include <chrono>
#include "fibonacci.h"

enum {Matrix=0, Recursive=1, Loop=2, Formula=3};

using namespace std;

int eval_fibonacci_timecomplexity(string method, int num_entries, vector< vector<long long> > *perf_matrix_pt);

int main(int , const char**)
{
	vector<int> num_entries {5, 10, 15, 20, 25, 30,  40, 45};
	vector< vector<long long> > performance(4);
	vector<string> algorithms {"matrix", "formula", "loop", "recursive"};

	for(auto method : algorithms)
		for(auto n : num_entries)
			eval_fibonacci_timecomplexity(method, n, &performance);
	
	for(auto array : performance)
	{
		for(auto array_element : array)
			cout << array_element << ", ";
		cout << endl;
	}

	return 0;
}

int eval_fibonacci_timecomplexity(string method, int num_entries, vector< vector<long long> > *perf_mat_pt)
{
	
	long long n;
	int sign=1;

	if(num_entries<0 && abs(num_entries)%2==0)   // if N is negative and divisible by 2 then Nth fibonacci must be negative
		sign=-1;

	if(method.compare("matrix")==0)
	{	
		auto start = std::chrono::high_resolution_clock::now();
		for( int i=1; i<num_entries; ++i  )
			n = matrix((long long)i);
	
		auto elapsed = std::chrono::high_resolution_clock::now() - start;
		perf_mat_pt->at(Matrix).push_back(std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count());
	    	return(0);
	}   
	// -------------------------------------------------------------------------------------------------------------
	
	else if(method.compare("loop")==0)
	{	
		auto start = std::chrono::high_resolution_clock::now();
		for( int i=1; i<num_entries; ++i  )
			n = loop((int)i);
	
		auto elapsed = std::chrono::high_resolution_clock::now() - start;
		perf_mat_pt->at(Loop).push_back(std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count());
    		return(0);
	}   
	// -------------------------------------------------------------------------------------------------------------
	
	else if(method.compare("formula")==0)
	{	
		auto start = std::chrono::high_resolution_clock::now();
		for( int i=1; i<num_entries; ++i  )
			n = binets_formula((int)i);
	
		auto elapsed = std::chrono::high_resolution_clock::now() - start;
		perf_mat_pt->at(Formula).push_back(std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count());
	    	return(0);
	}   
	// -------------------------------------------------------------------------------------------------------------
	
	else if(method.compare("recursive")==0)
	{	
		auto start = std::chrono::high_resolution_clock::now();
		for( int i=1; i<num_entries; ++i  )
			n = recursive((int)i);
	
		auto elapsed = std::chrono::high_resolution_clock::now() - start;
		perf_mat_pt->at(Recursive).push_back(std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count());
    		return(0);
	}   
	// -------------------------------------------------------------------------------------------------------------
	
	else
		return(1);
}
