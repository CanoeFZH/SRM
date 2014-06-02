// BEGIN CUT HERE

// END CUT HERE
#line 5 "VocaloidsAndSongs.cpp"
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

const int N = 64;
const int MOD = 1000000007;

int dp[2][N][N][N];

class VocaloidsAndSongs
{
    public:
        void update(int & a, int b) {
            a = (a + b) % MOD;
        }
        int count(int S, int gumi, int ia, int mayu) {
            memset(dp, 0, sizeof(dp));
            dp[0][0][0][0] = 1;
            for (int s = 0; s < S; s++) {
                int c = s & 1, n = (s + 1) & 1;
                for (int g = 0; g <= gumi; g++) {
                    for (int i = 0; i <= ia; i++) {
                        for (int m = 0; m <= mayu; m++) {
                            dp[n][g][i][m] = 0;
                        }
                    }
                }
                for (int g = 0; g <= gumi; g++) {
                    for (int i = 0; i <= ia; i++) {
                        for (int m = 0; m <= mayu; m++) {
                            update(dp[n][g + 1][i][m], dp[c][g][i][m]);
                            update(dp[n][g][i + 1][m], dp[c][g][i][m]);
                            update(dp[n][g][i][m + 1], dp[c][g][i][m]);
                            update(dp[n][g + 1][i + 1][m], dp[c][g][i][m]);
                            update(dp[n][g + 1][i][m + 1], dp[c][g][i][m]);
                            update(dp[n][g][i + 1][m + 1], dp[c][g][i][m]);
                            update(dp[n][g + 1][i + 1][m + 1], dp[c][g][i][m]);
                        }
                    }
                }
            }
            return dp[S & 1][gumi][ia][mayu];
        } 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 6; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; int Arg4 = 9; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 50; int Arg1 = 10; int Arg2 = 10; int Arg3 = 10; int Arg4 = 0; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 18; int Arg1 = 12; int Arg2 = 8; int Arg3 = 9; int Arg4 = 81451692; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 198591037; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    VocaloidsAndSongs ___test;
    ___test.run_test(-1);
    return 0;
}
