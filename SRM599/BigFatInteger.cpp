// BEGIN CUT HERE  
/* 
    
*/  
// END CUT HERE  
#line 7 "BigFatInteger.cpp"  
#include <cstdlib>  
#include <cctype>  
#include <cstring>  
#include <cstdio>  
#include <cmath>  
#include <algorithm>  
#include <vector>  
#include <string>  
#include <iostream>  
#include <sstream>  
#include <map>  
#include <set>  
#include <queue> 
#include <stack>  
#include <fstream>  
#include <numeric>  
#include <iomanip>  
#include <bitset>  
#include <list>  
#include <stdexcept>  
#include <functional>  
#include <utility>  
#include <ctime>  

using namespace std;  

const int oo = 1 << 30;

class BigFatInteger  
{  
    public:  
        int getStep(int x) {
            int ret = 0, base = 1;
            while (base < x) {
                ret += 1;
                base <<= 1;
            }
            return ret;
        }
        int minOperations(int A, int B) {   
            vector <int> r;
            for (int p = 2; p <= A / p; p++) {
                int rTmp = 0;
                while(A % p == 0) {
                    rTmp += B;
                    A /= p;
                }
                if (rTmp != 0) {
                    r.push_back(rTmp);
                }
            }
            if (A != 1) {
                r.push_back(B);
            }
            int ret = 0;
            for (int x : r) {
                ret = max(ret, getStep(x));
            }
            ret += r.size();
            return ret;
        }  
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 162; int Arg1 = 1; int Arg2 = 4; verify_case(1, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 999983; int Arg1 = 9; int Arg2 = 5; verify_case(2, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 360; int Arg1 = 8; int Arg2 = 8; verify_case(3, Arg2, minOperations(Arg0, Arg1)); }

// END CUT HERE
  
};  

// BEGIN CUT HERE  
int main()  
{  
    BigFatInteger ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE 
