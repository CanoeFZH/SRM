#line 2 "LittleElephantAndRGB.cpp"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cassert>
#include <bitset>
#include <list>
#include <cmath>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

const int N = 2506;

int dp[N][N], len[N][N]; 

class LittleElephantAndRGB
{
	public:
		long long getNumber(vector <string> list, int minGreen) {
			memset(dp, 0, sizeof(dp));
			memset(len, 0, sizeof(len));
			string str = accumulate(list.begin(), list.end(), string(""));
			int n = str.size();
			for(int i = 0; i < n; i++) {
				for(int j = i; j < n; j++) {
					if(len[i][j] >= minGreen) {
						len[i][j + 1] = minGreen;
					} else if(str[j] == 'G') {
						len[i][j + 1] = len[i][j] + 1;
					} else {
						len[i][j + 1] = 0;
					}
				}
			}
			for(int i = 0; i < n; i++) {
				for(int j = 0; j <= i; j++) {
					dp[i + 1][len[j][i + 1]]++;
				}
				for(int j = minGreen; j >= 0; j--) {
					dp[i + 1][j] += dp[i + 1][j + 1];
				}
				for(int j = 0; j <= minGreen; j++) {
					dp[i + 1][j] += dp[i][j];
				}
			}
			long long ret = 0;
			for(int i = n; i >= 0; i--) {
				int length = 0;
				for(int j = i - 1; j >= 0; j--) {
					if(length < minGreen) {
						if(str[j] == 'G') {
							length++;
						} else {
							length = 0;
						}
					}
					ret += dp[j][minGreen - length];
				}
			}
			return ret;
		}

		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { string Arr0[] = {"GRG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 1LL; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
		void test_case_1() { string Arr0[] = {"GG", "GG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 9LL; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
		void test_case_2() { string Arr0[] = {"GRBGRBBRG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 11LL; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
		void test_case_3() { string Arr0[] = {"RRBRBBRRR", "R", "B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; long long Arg2 = 0LL; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
		void test_case_4() { string Arr0[] = {"GRGGGRBRGG", "GGGGGGGG", "BRGRBRB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long long Arg2 = 12430LL; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

		// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LittleElephantAndRGB ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
