// BEGIN CUT HERE

// END CUT HERE
#line 5 "PalindromicSubstringsDiv1.cpp"
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

class PalindromicSubstringsDiv1
{
    public:
        int n;
        string s;
        double palindromesProbability(int l, int r) {
            double p = 1, ret = 0;
            while (l >= 0 && r < n) {
                if (s[l] == '?' || s[r] == '?') {
                    p *= 1.0 / 26;
                } else if (s[l] != s[r]) {
                    p = 0;
                }
                ret += p;
                l--, r++;
            }
            return ret;
        }
        double expectedPalindromes(vector <string> S1, vector <string> S2) {
            s = "";
            for (auto str: S1) {
                s += str;
            }
            for (auto str: S2) {
                s += str;
            }
            n = s.size();
            double ret = 0;
            for (int m = 0; m < n; m++) {
                ret += 1;
                ret += palindromesProbability(m, m + 1);
                ret += palindromesProbability(m - 1, m + 1);
            }
            return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a","a",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.0; verify_case(0, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"z??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.115384615384615; verify_case(1, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"ab","c"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"??","a?"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 7.315088757396449; verify_case(2, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"?"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(3, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"ab?def","?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"f??a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 12.545971779699588; verify_case(4, Arg2, expectedPalindromes(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PalindromicSubstringsDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
