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

const long long INF = 1LL << 63;

class DivisorsPower
{
    public:
        int d(long long x) {
            int ret = 0;
            for (long long i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    if (i * i == x) {
                        ret += 1;
                    } else {
                        ret += 2;
                    }
                }
            }
            return ret;
        }
        long long findArgument(long long n) {
            for (int i = 63; i >= 2; i--) {
                long long x = pow(n, 1.0 / i);
                for (long long j = max(1LL, x - 1); j <= x + 1; j++) {
                    long long copy = n;
                    for (int k = 0; k < i; k++) {
                        if (copy % j != 0) {
                            copy = -1;
                            break;
                        }
                        copy /= j;
                    }
                    if (copy != 1 || i != d(j)) {
                        continue;
                    }
                    return j;
                }
            }
            return -1;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 2LL; verify_case(0, Arg1, findArgument(Arg0)); }
	void test_case_1() { long long Arg0 = 10LL; long long Arg1 = -1LL; verify_case(1, Arg1, findArgument(Arg0)); }
	void test_case_2() { long long Arg0 = 64LL; long long Arg1 = 4LL; verify_case(2, Arg1, findArgument(Arg0)); }
	void test_case_3() { long long Arg0 = 10000LL; long long Arg1 = 10LL; verify_case(3, Arg1, findArgument(Arg0)); }
	void test_case_4() { long long Arg0 = 2498388559757689LL; long long Arg1 = 49983883LL; verify_case(4, Arg1, findArgument(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    DivisorsPower ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
