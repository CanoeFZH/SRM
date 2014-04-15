// BEGIN CUT HERE

// END CUT HERE
#line 5 "AlienAndSetDiv2.cpp"
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
const int N = 110;

#define gSet set <int, greater <int> >
map <gSet, long> dp[N];

class AlienAndSetDiv2
{
    public:
        int K;
        long gao (int n, gSet unmatched) {
            auto q = dp[n].find(unmatched);
            long ret = 0;
            if (q == dp[n].end()) {
                if (n == 0) {
                    if (unmatched.size() == 0) {
                        ret = 1;
                    }
                } else {
                    if (unmatched.size() == 0) {
                        ret = 2 * gao(n - 1, {n});
                    } else {
                        int maxUnmatched = *unmatched.begin();
                        gSet newSet = unmatched;
                        newSet.erase(newSet.begin());
                        ret += gao(n - 1, newSet);
                        if (n + K != maxUnmatched) {
                            gSet newSet = unmatched;
                            newSet.insert(n);
                            ret += gao(n - 1, newSet);
                        }
                    }
                    ret %= MOD;
                }
                dp[n][unmatched] = ret;
            } else {
                ret = q->second;
            }
            return ret;
        }
        int getNumber(int N, int K) {
            this-> K = K;
            return gao(2 * N, {});
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 4; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 8; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 44; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 184756; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    AlienAndSetDiv2 ___test;
    ___test.run_test(-1);
    return 0;
}
