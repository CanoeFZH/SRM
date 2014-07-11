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

const int N = 30;

class HappyLetterDiv1
{
    public:
        int n, letterNumber[N];
        bool canBeLeft() {
            vector <int> v;
            for (int i = 0; i < 26; i++) {
                if (letterNumber[i] != 0) {
                    v.push_back(letterNumber[i]);
                }
            }
            sort(v.begin(), v.end());
            while(v.size() > 1) {
                v[0]--;
                v.back()--;
                sort(v.begin(), v.end());
                while(v.size() && v[0] == 0) {
                    v.erase(v.begin());
                }
            }
            if (v.size()) {
                return false;
            } else {
                return true;
            }
        }
        string getHappyLetters(string letters) {
            memset(letterNumber, 0, sizeof(letterNumber));
            n = letters.size();
            for (int i = 0; i < n; i++) {
                letterNumber[letters[i] - 'a']++;
            }
            string ret = "";
            for (int i = 0; i < 26; i++) {
                for (int j = 1; j <= letterNumber[i]; j++) {
                    letterNumber[i] -= j;
                    if (canBeLeft()) {
                        ret += 'a' + i;
                        letterNumber[i] += j;
                        break;
                    }
                    letterNumber[i] += j;
                }
            }
            return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aabbacccc"; string Arg1 = "abc"; verify_case(0, Arg1, getHappyLetters(Arg0)); }
	void test_case_1() { string Arg0 = "aaaaaaaccdd"; string Arg1 = "a"; verify_case(1, Arg1, getHappyLetters(Arg0)); }
	void test_case_2() { string Arg0 = "ddabccadb"; string Arg1 = "abcd"; verify_case(2, Arg1, getHappyLetters(Arg0)); }
	void test_case_3() { string Arg0 = "aaabbb"; string Arg1 = ""; verify_case(3, Arg1, getHappyLetters(Arg0)); }
	void test_case_4() { string Arg0 = "rdokcogscosn"; string Arg1 = "cos"; verify_case(4, Arg1, getHappyLetters(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    HappyLetterDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
