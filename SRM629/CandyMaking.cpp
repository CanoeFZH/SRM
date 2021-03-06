// BEGIN CUT HERE

// END CUT HERE
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class CandyMaking
{
    public:
        double findSuitableDensity(vector <int> containerVolume, vector <int> desiredWeight) {
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, findSuitableDensity(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000,2000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1000.0; verify_case(1, Arg2, findSuitableDensity(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10,20,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4000,2000,1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 5250.0; verify_case(2, Arg2, findSuitableDensity(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1234,1541,3321,1234,123,123,3414,123,12,2442,1421,1223,3232,1123,2121}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3213,1231,232143,44312,132132,142424,123123,41341,41244,21312,232131,2312,2322,11,2223}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 983673.2727272725; verify_case(3, Arg2, findSuitableDensity(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {30621,30620,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 999999.9999673415; verify_case(4, Arg2, findSuitableDensity(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    CandyMaking ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
