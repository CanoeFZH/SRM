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

class PotentialArithmeticSequence
{
    public:
        vector <int> d;
        map <int, vector <int> > mv;
        int tailZero(int x) {
            int ret = 0;
            for (int i = x; !(i & 1) && i; i >>= 1) {
                ret++;
            }
            return ret;
        }
        bool isOK(int s, int t) {
            if (t == s) {
                return true;
            }
            int maxBit = -1, MAX_BIT = 6, maxBitIndex = -1;
            for (int i = s; i <= t; i++) {
                if (maxBit < d[i]) {
                    maxBit = d[i];
                    maxBitIndex = i;
                }
            }
            if(maxBit == 0) {
                return false;
            }
            if (maxBit > MAX_BIT) {
                maxBit = MAX_BIT;
            }
            int bitMask = 1 << maxBit;
            for (int i = maxBitIndex - 1; i >= s; i--) {
                bitMask--;
                if (bitMask <= 0) {
                    return false;
                }
                if (tailZero(bitMask) != d[i]) {
                    return false;
                }
            }
            bitMask = 1 << maxBit;
            for (int i = maxBitIndex + 1; i <= t; i++) {
                bitMask++;
                if (tailZero(bitMask) != d[i]) {
                    return false;
                }
            }
            return true;
        }
        int numberOfSubsequences(vector <int> d) {
            this->d = d;
            int n = d.size(), ret = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    if (isOK(i, j)) {
                        ret += 1;
                    }
                }
            }
            return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,0,2,0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(0, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_1() { int Arr0[] = {0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,0,0,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_3() { int Arr0[] = {0,100,0,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(3, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_4() { int Arr0[] = {1,11,3,0,1,0,1,0,1,0,1,0,3,0,2,0,0,0,0,1,2,3,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; verify_case(4, Arg1, numberOfSubsequences(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    PotentialArithmeticSequence ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
