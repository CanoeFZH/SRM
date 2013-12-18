#line 2 "BitwiseAnd.cpp"
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

class BitwiseAnd
{
	public:
		vector<long long> lexSmallest(vector<long long> subset, int N) {
			const int B = 60;

			int mask[B];
			vector <long long> ret = subset;
			int K = subset.size();
			memset(mask, -1, sizeof(mask));
			for(int i = 0; i < K; i++) {
				set <int> st;
				for(int j = 0; j < i; j++) {
					st.insert(j);
				}
				for(int j = 0; j < B; j++) {
					if(subset[i] & (1LL << j)) {
						if (mask[j] == -1) {
							mask[j] = i;
						} else if (mask[j] >= 0) {
							st.erase(mask[j]);
							mask[j] = -2;
						} else {
							return {};
						}
					}
				}
				if(!st.empty()) {
					return {};
				}
			}

			for(int i = K; i < N; i++) {
				set <int> st;
				for(int j = 0; j < i; j++) {
					st.insert(j);
				}
				long long x = 0;
				int zeroChange = N - i - 1;
				for(int j = 0; j < B; j++) {
					if(mask[j] == -1) {
						if(zeroChange > 0) {
							x |= 1LL << j;
							zeroChange--;
							mask[j] = i;
						}
					} else if (mask[j] >= 0) {
						if(st.find(mask[j]) != st.end()) {
							x |= 1LL << j;
							st.erase(mask[j]);
							mask[j] = -2;
						}
					}
				}
				if(!st.empty() || zeroChange > 0) {
					return {};
				}
				ret.push_back(x);
			}

			sort(ret.begin(), ret.end());
			return ret;
		}

		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
		void test_case_0() { long Arr0[] = {14, 20}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long Arr2[] = {14, 18, 20 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, lexSmallest(Arg0, Arg1)); }
		void test_case_1() { long Arr0[] = {11, 17, 20}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long Arr2[] = { }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, lexSmallest(Arg0, Arg1)); }
		void test_case_2() { long Arr0[] = {99, 157}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long Arr2[] = {99, 157, 262, 296 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, lexSmallest(Arg0, Arg1)); }
		void test_case_3() { long Arr0[] = {1152921504606846975}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long Arr2[] = { }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, lexSmallest(Arg0, Arg1)); }
		void test_case_4() { long Arr0[] = {}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; long Arr2[] = {15, 113, 402, 676, 840 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, lexSmallest(Arg0, Arg1)); }
		void test_case_5() { long Arr0[] = {1, 3, 5, 7, 9, 11}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; long Arr2[] = { }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, lexSmallest(Arg0, Arg1)); }

		// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BitwiseAnd ___test;
	___test.run_test(-1);
	return 0;
}
