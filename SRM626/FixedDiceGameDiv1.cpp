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

const int N = 64;

double p[2][N][N * N]; 

class FixedDiceGameDiv1
{
    public:
        void getP(double p[][N * N], int n, int f) {
            p[0][0] = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= N * N; j++) {
                    for (int k = 1; k <= f && k + j <= N * N; k++) {
                        p[i + 1][j + k] += p[i][j] / f;
                    }
                }
            }
        }
        double getExpectation(int a, int b, int c, int d) {
            memset(p, 0, sizeof(p));
            getP(p[0], a, b);
            getP(p[1], c, d);
            double ret = 0, pWin = 0;
            for (int i = 1; i <= a * b; i++) {
                for (int j = 1; j < i && j <= c * d; j++) {
                    pWin += p[0][a][i] * p[1][c][j];
                }
            }
            if (pWin == 0) {
                ret = -1;
            } else {
                for (int i = 1; i <= a * b; i++) {
                    for (int j = 1; j < i && j <= c * d; j++) {
                        ret += i * p[0][a][i] * p[1][c][j];
                    }
                }
                ret /= pWin;
            }
            return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; int Arg3 = 5; double Arg4 = 2.0; verify_case(0, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; double Arg4 = 3.0; verify_case(1, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; double Arg4 = 3.4999999999999996; verify_case(2, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 50; int Arg3 = 30; double Arg4 = -1.0; verify_case(3, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 11; int Arg2 = 50; int Arg3 = 50; double Arg4 = 369.8865999182022; verify_case(4, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    FixedDiceGameDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
