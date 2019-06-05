#ifndef FIBONACCI_H_INCLUDED
#define FIBONACCI_H_INCLUDED

#include <vector>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>

//
// ----------------- DEFINES MACROS ---------------------- //
//

using namespace std;
#define mod 1000000007  // Take mod for large values

//
// ----------------- DEFINES MAIN METHODS ---------------- //
//

long long recursive(int n);
long long loop(int n);
long long binets_formula(int n);
long long matrix(long long n);

//
// ----------------- DEFINES AUX METHODS ---------------- //
//


//
// ----------------- DEFINES STRUCTS ---------------------- //
//

struct Matrix{

    long long a,b,c,d;

    // constructor
    Matrix(long long w=0, long long x=0, long long y=0, long long z=0){ a=w; b=x; c=y; d=z; }

    // operator overloading
    Matrix operator * (const Matrix &mat) const{

        long long new_a = (a*mat.a+b*mat.c)%mod;
        long long new_b = (a*mat.b+b*mat.d)%mod;    // 2*2 matrix multiplication
        long long new_c = (c*mat.a+d*mat.c)%mod;
        long long new_d = (c*mat.b+d*mat.d)%mod;

        return Matrix(new_a, new_b, new_c ,new_d);
    }
};

#endif
