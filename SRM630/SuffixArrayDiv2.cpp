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

class SuffixArrayDiv2
{
    public:
        vector <int> getSA(string s) {
            vector <pair <string, int> > p;
            for (int i = 0; i < s.size(); i++) {
                p.push_back(make_pair(s.substr(i), i));
            }
            sort(p.begin(), p.end());
            vector <int> ret;
            for (int i = 0; i < p.size(); i++) {
                ret.push_back(p[i].second);
            }
            return ret;
        }
        string smallerOne(string s) {
            vector <int> sa = getSA(s);
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != 'a') {
                    string t = s;
                    t[i]--;
                    if (sa == getSA(t)) {
                        return "Exists";
                    }
                }
            }
            return "Does not exist";
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abca"; string Arg1 = "Exists"; verify_case(0, Arg1, smallerOne(Arg0)); }
	void test_case_1() { string Arg0 = "bbbb"; string Arg1 = "Exists"; verify_case(1, Arg1, smallerOne(Arg0)); }
	void test_case_2() { string Arg0 = "aaaa"; string Arg1 = "Does not exist"; verify_case(2, Arg1, smallerOne(Arg0)); }
	void test_case_3() { string Arg0 = "examplesareveryweakthinktwicebeforesubmit"; string Arg1 = "Exists"; verify_case(3, Arg1, smallerOne(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    SuffixArrayDiv2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
