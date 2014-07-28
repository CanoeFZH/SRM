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

const int N = 100086;

int cutFlag[N];

class MyLongCake
{
    public:
        int cut(int n) {
            int copy = n;
            memset(cutFlag, 0, sizeof(cutFlag));
            vector <int> primer;
            for (int i = 2; i * i <= copy; i++) {
                if (copy % i == 0) {
                    primer.push_back(i);
                    while(copy % i == 0) {
                        copy /= i;
                    }
                }
            }
            if (copy != 1) {
                primer.push_back(copy);
            }
            for (auto &p: primer) {
                for (int i = p; i < n; i += p) {
                    cutFlag[i] = 1;
                }
            }
            int ret = 1;
            for (int i = 0; i < n; i++) {
                if (cutFlag[i] == 1) {
                    ret++;
                }
            }
            return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 4; verify_case(0, Arg1, cut(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; verify_case(1, Arg1, cut(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 7; verify_case(2, Arg1, cut(Arg0)); }
	void test_case_3() { int Arg0 = 100000; int Arg1 = 60000; verify_case(3, Arg1, cut(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    MyLongCake ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
