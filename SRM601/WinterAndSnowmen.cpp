// BEGIN CUT HERE  
/* 
    
*/  
// END CUT HERE  
#line 7 "WinterAndSnowmen.cpp"  
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

const int N = 2046;
const int MAX_BITS = 11;
const int MOD = 1000000007;

int dp[N][1 << MAX_BITS][2];

class WinterAndSnowmen  
{  
    public:  
        int N, M, B;
        int gao(int t, int z, int b) {
            if (dp[t][z][b] != -1) {
                return dp[t][z][b];
            }
            int & res = dp[t][z][b];
            if (t == 0) {
                if (z == 1 && b == 0) {
                    res = 1;
                } else {
                    res = 0;
                }
            } else { 
                res = gao(t - 1, z, b);
                int BIT = t >> B;
                if (t <= N) {
                    res = (res + gao(t - 1, z ^ BIT, b ^ (BIT & 1))) % MOD;
                } 
                if (t <= M) { 
                    res = (res + gao(t - 1, z ^ BIT, b)) % MOD;
                }
            }
            return res;
        }
        int getNumber(int N, int M) {   
            int res = 0, t = max(N, M);
            this->N = N, this->M = M;
            for (int i = 0; i < MAX_BITS; i++) {
                memset(dp, -1, sizeof(dp));
                B = i;
                res = (gao(t, 0, 0) + res) % MOD;
            }
            return res;
        }  
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 47; int Arg1 = 74; int Arg2 = 962557390; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 74; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 216; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 47; int Arg1 = 74; int Arg2 = 962557390; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE
  
};  

// BEGIN CUT HERE  
int main()  
{  
    WinterAndSnowmen ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE 
