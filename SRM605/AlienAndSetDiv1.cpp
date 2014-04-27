// BEGIN CUT HERE

// END CUT HERE
#line 5 "AlienAndSetDiv1.cpp"
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

const int MAX_N = 54;
const int MAX_K = 10;
const long long MOD = 1000000007;

long long dp[MAX_N * 2][MAX_N * 2][1 << MAX_K];

class AlienAndSetDiv1
{
    public:
        int K;
        long long gao(int n, int g, int mask) {
            if (dp[n][g][mask] != -1) {
                return dp[n][g][mask];
            }
            long long & ret = dp[n][g][mask];
            ret = 0;
            if (n == 0) {
                ret = (g == 0 && mask == 0) ? 1 : 0;
            } else {
                if (g == 0 && mask == 0) {
                    if (K == 1) {
                        ret = 2 * gao(n - 1, 1, 0);
                    } else {
                        ret = 2 * gao(n - 1, 0, 1);
                    }
                } else {
                    if (g > 0) {
                        int nextMask = mask << 1, nextG = g - 1;
                        if (nextMask & (1 << (K - 1))) {
                            nextMask ^= 1 << (K - 1);
                            nextG++;
                        }
                        ret = gao(n - 1, nextG, nextMask);
                    }
                    int nextMask = (mask << 1) | 1, nextG = g;
                    if (nextMask & (1 << (K - 1))) {
                        nextMask ^= (1 << (K - 1));
                        nextG++;
                    }
                    ret += gao(n - 1, nextG, nextMask);
                }
            }
            ret %= MOD;
            return ret;
        }
        int getNumber(int N, int K) {
            this-> K = K;
            memset(dp, -1, sizeof(dp));
            return gao(2 * N, 0, 0);
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 20; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 14; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 7; int Arg2 = 40; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    AlienAndSetDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
