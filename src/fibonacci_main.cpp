#include <time.h>
#include <chrono>
#include "fibonacci.h"

enum {Matrix=0, Recursive=1, Loop=2, Formula=3};

using namespace std;

int eval_fibonacci_timecomplexity(string method, int num_entries, vector< vector<long long> > *perf_matrix_pt, vector< vector<long long> > *result_mat_pt);

int main(int , const char**)
{
	vector<int> num_entries {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
	vector< vector<long long> > time_perf (4);
	vector< vector<long long> > resulting_n (4);
	vector<string> algorithms {"matrix", "formula", "loop", "recursive"};

	for(auto method : algorithms)
		for(auto n : num_entries)
			eval_fibonacci_timecomplexity(method, n, &time_perf, &resulting_n);
	
	cout <<  "\n#############################################################\n";

	for(auto array : time_perf)
	{
		cout << "\tEecution time for n_entries"  << endl;
		for(auto array_element : array)
			cout << array_element << ", ";
		cout << endl;
	}
	
	cout << "\n#############################################################\n";

	for( auto array: resulting_n  )
	{
	
		cout << "\tNth FIBONACCI NUMBER" << endl;
		for(auto array_element : array)
			cout << array_element << ", ";
		cout << endl;
	}

	return 0;
}

int eval_fibonacci_timecomplexity(string method, int num_entries, vector< vector<long long> > *perf_mat_pt, vector< vector<long long> > *result_mat_pt)
{
	
	vector< long long > n;
	int sign=1;

	if(num_entries<0 && abs(num_entries)%2==0)   // if N is negative and divisible by 2 then Nth fibonacci must be negative
		sign=-1;

	if(method.compare("matrix")==0)
	{	
		auto start = std::chrono::high_resolution_clock::now();
		for( int i=1; i<num_entries; ++i  )
			n.push_back(matrix((long long)i));

		auto elapsed = std::chrono::high_resolution_clock::now() - start;

		cout << "Matrix for " << num_entries << " yields: " << n.back() << endl;
		perf_mat_pt->at(Matrix).push_back(std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count());
	    	
		// merge results with previously obtained results and sort
		result_mat_pt->at(Matrix).insert(result_mat_pt->at(Matrix).end(), n.begin(), n.end());
		set<long long> set( result_mat_pt->at(Matrix).begin(), result_mat_pt->at(Matrix).end()  );
		result_mat_pt->at(Matrix).assign( set.begin(), set.end()  );
		sort( result_mat_pt->at(Matrix).begin(), result_mat_pt->at(Matrix).end()  );

		return(0);
	}   
	// -------------------------------------------------------------------------------------------------------------
	
	else if(method.compare("loop")==0)
	{	
		auto start = std::chrono::high_resolution_clock::now();
		for( int i=1; i<num_entries; ++i  )
			n.push_back(loop((int)i));
	
		auto elapsed = std::chrono::high_resolution_clock::now() - start;
		cout << "Loop for " << num_entries << " yields: " << n.back() << endl;
		perf_mat_pt->at(Loop).push_back(std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count());

		// merge results with previously obtained results and sort
		result_mat_pt->at(Loop).insert(result_mat_pt->at(Loop).end(), n.begin(), n.end());
		set<long long> set( result_mat_pt->at(Loop).begin(), result_mat_pt->at(Loop).end()  );
		result_mat_pt->at(Loop).assign( set.begin(), set.end()  );
		sort( result_mat_pt->at(Loop).begin(), result_mat_pt->at(Loop).end()  );
    		
		return(0);
	}   
	// -------------------------------------------------------------------------------------------------------------
	
	else if(method.compare("formula")==0)
	{	
		auto start = std::chrono::high_resolution_clock::now();
		for( int i=1; i<num_entries; ++i  )
			n.push_back(binets_formula((int)i));
	
		auto elapsed = std::chrono::high_resolution_clock::now() - start;
		cout << "Formula for " << num_entries << " yields: " << n.back() << endl;
		perf_mat_pt->at(Formula).push_back(std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count());
		
		// merge results with previously obtained results and sort
		result_mat_pt->at(Formula).insert(result_mat_pt->at(Formula).end(), n.begin(), n.end());
		set<long long> set( result_mat_pt->at(Formula).begin(), result_mat_pt->at(Formula).end()  );
		result_mat_pt->at(Formula).assign( set.begin(), set.end()  );
		sort( result_mat_pt->at(Formula).begin(), result_mat_pt->at(Formula).end()  );
	    	
		return(0);
	}   
	// -------------------------------------------------------------------------------------------------------------
	
	else if(method.compare("recursive")==0)
	{	
		auto start = std::chrono::high_resolution_clock::now();
		for( int i=1; i<num_entries; ++i  )
			n.push_back(recursive((int)i));
	
		auto elapsed = std::chrono::high_resolution_clock::now() - start;
		cout << "Recursive for " << num_entries << " yields: " << n.back() << endl;
		perf_mat_pt->at(Recursive).push_back(std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count());
		
		// merge results with previously obtained results and sort
		result_mat_pt->at(Recursive).insert(result_mat_pt->at(Recursive).end(), n.begin(), n.end());
		set<long long> set( result_mat_pt->at(Recursive).begin(), result_mat_pt->at(Recursive).end()  );
		result_mat_pt->at(Recursive).assign( set.begin(), set.end()  );
		sort( result_mat_pt->at(Recursive).begin(), result_mat_pt->at(Recursive).end()  );
 
		return(0);
	}   
	// -------------------------------------------------------------------------------------------------------------
	
	else
		return(1);
}
