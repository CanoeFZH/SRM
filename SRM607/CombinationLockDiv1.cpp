// BEGIN CUT HERE

// END CUT HERE
#line 5 "CombinationLockDiv1.cpp"
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

const int N = 2510;
const int MAX_OPT = 5510;
const int INFINITE = 1 << 30;
const int OPT [] = {1, 9};

int dp[N][MAX_OPT][2], d[N];

class CombinationLockDiv1
{
    public:
        int n;
        int gao(int p, int x, int rotate) {
            if (dp[p][x][rotate] != -1) {
                return dp[p][x][rotate];
            }
            int & ret = dp[p][x][rotate];
            if (p == n) {
                ret = 0;
            } else {
                ret = INFINITE;
                for (int r = 0; r < 2; r++) {
                    for (int add = 0; add <= 9 && add + x < MAX_OPT; add++) {
                        if ((d[p] + OPT[rotate] * (x + add)) % 10 == 0) {
                            ret = min(ret, add + gao(p + 1, x + add, rotate));
                        }
                    }
                    for (int remove = 0; remove <= x && remove <= 9; remove++) {
                        if ((d[p] + OPT[rotate] * (x - remove)) % 10 == 0) {
                            ret = min(ret, gao(p + 1, x - remove, rotate));
                        }
                    }
                    int z = OPT[rotate] * d[p] % 10;
                    ret = min(ret, z + gao(p + 1, z, rotate ^ 1));
                }
            }
            return ret;
        }
        int minimumMoves(vector <string> P, vector <string> Q) {
            string S = accumulate(P.begin(), P.end(), string(""));
            string T = accumulate(Q.begin(), Q.end(), string(""));
            this->n = S.size();
            for (int i = 0; i < n; i++) {
                d[i] = (S[i] - T[i] + 10) % 10;
            }
            memset(dp, -1, sizeof(dp));
            return gao(0, 0, 0);
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"123"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"112"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"6","07"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"","60","7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4567"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"020"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"909"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(4, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"4423232218340"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"6290421476245"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 18; verify_case(5, Arg2, minimumMoves(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CombinationLockDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
