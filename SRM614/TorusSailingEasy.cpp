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

const int N = 20;

class TorusSailingEasy
{
    public:
        double E[N][N];
        double expectedTime(int n, int m, int goalX, int goalY) {
            double ret = -1;
            int x = 0, y = 0;
            bool can = false;
            while(true) {
                x = (x + 1) % n;
                y = (y + 1) % m;
                if (x == goalX && y == goalY) {
                    can = true;
                }
                if (x == 0 && y == 0) {
                    break;
                }
            }
            if(can) {
                for (int it = 0; it < 100000; it++) {
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (i == 0 && j == 0) {
                                continue;
                            }
                            E[i][j] = 1 + 0.5 * (E[(i - 1 + n) % n][(j - 1 + m) % m] + 
                                                 E[(i + 1 + n) % n][(j + 1 + m) % m]);
                        }
                    }
                }
                ret = E[goalX][goalY];
            }
            return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; double Arg4 = 1.0; verify_case(0, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; int Arg3 = 1; double Arg4 = -1.0; verify_case(1, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; double Arg4 = 2.0; verify_case(2, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 1; int Arg3 = 3; double Arg4 = 27.0; verify_case(3, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    TorusSailingEasy ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
