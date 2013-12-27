// BEGIN CUT HERE  
/* 

*/  
// END CUT HERE  
#line 7 "LittleElephantAndSubset.cpp"  
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

const int MOD = 1000000007;
const int SET = (1 << 10);

long long dp[SET], number[SET];

class LittleElephantAndSubset  
{  
    public:  
        int n;
        void getCount(long long x, int mask) {
            if (x > n) {
                return;
            }
            number[mask]++;
            for(int i = 0; i <= 9; i++) {
                if(!((1 << i) & mask)) { 
                    getCount(x * 10LL + i, mask | (1 << i));
                }
            }
        }
        int getNumber(int N) { 
            n = N;

            memset(number, 0, sizeof(number));
            for(int i = 1; i <= 9; i++) {
                getCount(i, 1 << i);
            }

            memset(dp, 0, sizeof(dp));
            dp[0] = 1;
            for(int i = 0; i < SET; i++) {
                for(int j = i + 1; j < SET; j++) {
                    if((i & j) == 0) {
                        dp[i | j] = (dp[i | j] + dp[i] * number[j] % MOD) % MOD;
                    }
                }
            }

            long long ret = 0;
            for(int i = 1; i < SET; i++) {
                ret = (ret + dp[i]) % MOD;
            }

            return (int) ret;
        }  

        // BEGIN CUT HERE
    public:
        void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
    private:
        template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
        void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
        void test_case_0() { int Arg0 = 3; int Arg1 = 7; verify_case(0, Arg1, getNumber(Arg0)); }
        void test_case_1() { int Arg0 = 10; int Arg1 = 767; verify_case(1, Arg1, getNumber(Arg0)); }
        void test_case_2() { int Arg0 = 47; int Arg1 = 25775; verify_case(2, Arg1, getNumber(Arg0)); }
        void test_case_3() { int Arg0 = 4777447; int Arg1 = 66437071; verify_case(3, Arg1, getNumber(Arg0)); }

        // END CUT HERE

};  

// BEGIN CUT HERE  
int main()  
{  
    LittleElephantAndSubset ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE 
