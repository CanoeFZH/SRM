#line 2 "AstronomicalRecords.cpp"
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
#include <climits>

using namespace std;

const int N = 64;

int dp[N][N];

class AstronomicalRecords
{
	public:
		int n, m;
		vector <int> aTmp, bTmp;
		vector <long long> a, b;
		int gao(int aIdx, int bIdx) {
			a.clear(), b.clear();
			long long p = aTmp[aIdx], q = bTmp[bIdx];
			for(int i = 0; i < n; i++) {
				a.push_back(aTmp[i] * q);
			}
			for(int i = 0; i < m; i++) {
				b.push_back(bTmp[i] * p);
			}
			memset(dp, 0, sizeof(dp));
			for(int i = 0; i <= n; i++) {
				for(int j = 0; j <= m; j++) {
					if(i == 0 || j == 0) {
						dp[i][j] = 0;
					} else {
						dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
						int delta = a[i - 1] == b[j - 1] ? 1 : 0;
						dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + delta);
					}
				}
			}
			int ret = n + m - dp[n][m];
			return ret;
		}
		int minimalPlanets(vector <int> A, vector <int> B) {
			int ret = INT_MAX;
			n = A.size(), m = B.size();
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					aTmp = A, bTmp = B;
					ret = min(ret, gao(i, j));
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
		void test_case_0() { int Arr0[] = {1,2,1,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1,2,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, minimalPlanets(Arg0, Arg1)); }
		void test_case_1() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4,6,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, minimalPlanets(Arg0, Arg1)); }
		void test_case_2() { int Arr0[] = {2,3,2,3,2,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {600,700,600,700,600,700,600}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(2, Arg2, minimalPlanets(Arg0, Arg1)); }
		void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,7,8,9,10,11,12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(3, Arg2, minimalPlanets(Arg0, Arg1)); }
		void test_case_4() { int Arr0[] = {100000000,200000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {200000000,100000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, minimalPlanets(Arg0, Arg1)); }

		// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AstronomicalRecords ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
