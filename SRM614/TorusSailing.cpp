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

const int N = 128;

class TorusSailing
{
    public:
        double expectedTime(int n, int m, int goalX, int goalY) {
            double E[N][N];
            for (int it = 0; it < 10000; it++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (i == 0 && j == 0) {
                            continue;
                        }
                        E[i][j] = 1 + 0.5 * (E[(i - 1 + n) % n][j] + E[i][(j - 1 + m) % m]);
                    }
                }
            }
            return E[goalX][goalY];
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; double Arg4 = 4.0; verify_case(0, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 0; int Arg3 = 2; double Arg4 = 8.0; verify_case(1, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 10; int Arg2 = 3; int Arg3 = 2; double Arg4 = 51.80060107964039; verify_case(2, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 99; int Arg3 = 99; double Arg4 = 9992.616372325532; verify_case(3, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    TorusSailing ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
