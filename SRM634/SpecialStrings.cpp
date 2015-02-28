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

class SpecialStrings
{
    public:
        bool special(const string & s) {
            int n = s.size();
            for (int i = 1; i < n; i++) {
                if (s.substr(0, i) >= s.substr(i, n - i)) {
                    return false;
                }
            }
            return true;
        }

        string findNext(string current) {
            if (current == "0") {
                return "1";
            }
            int n = current.size();
            string next = current;
            for (int i = n - 1; i >= 0; i--) {
                if (current[i] == '0') {
                    if (i == 0) {
                        return "";
                    }
                    next[i] = '1';
                    for (int j = i + 1; j < n; j++) {
                        next[j] = '0';
                        if (!special(next)) {
                            next[j] = '1';
                        }
                    }
                    return next;
                }
            }
            return "";
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "01"; string Arg1 = ""; verify_case(0, Arg1, findNext(Arg0)); }
	void test_case_1() { string Arg0 = "00101"; string Arg1 = "00111"; verify_case(1, Arg1, findNext(Arg0)); }
	void test_case_2() { string Arg0 = "0010111"; string Arg1 = "0011011"; verify_case(2, Arg1, findNext(Arg0)); }
	void test_case_3() { string Arg0 = "000010001001011"; string Arg1 = "000010001001101"; verify_case(3, Arg1, findNext(Arg0)); }
	void test_case_4() { string Arg0 = "01111111111111111111111101111111111111111111111111"; string Arg1 = "01101111011111111"; verify_case(4, Arg1, findNext(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    SpecialStrings ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
