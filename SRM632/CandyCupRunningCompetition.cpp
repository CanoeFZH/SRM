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

const int V = 2015;
const long long MOD = 1000000007;

class CandyCupRunningCompetition
{
    public:
        int fa[V];
        long long pow3[V];
        
        void init(int n) {
            for (int u = 0; u < n; u++) {
                fa[u] = u;
            }
        }

        int find(int u) {
            return fa[u] = fa[u] == u ? u : find(fa[u]);
        }

        void merge(int u, int v) {
            fa[find(u)] = find(v);
        }

        int findMaximum(int n, vector <int> A, vector <int> B) {
            init(n);
            int m = A.size();
            pow3[0] = 1;
            for (int i = 1; i < m; i++) {
                pow3[i] = pow3[i - 1] * 3 % MOD;
            }
            long long ret = 0;
            int s = 0, t = n - 1;
            for (int i = m - 1; i >= 0; i--) { // sum(3 ^ 0 + ... 3 ^ n) < 3 ^ (n + 1)
                int u = A[i], v = B[i];
                if ((find(s) == find(u) && find(v) == find(t)) ||
                        (find(s) == find(v) && find(u) == find(t))) {
                    ret = (ret + pow3[i]) % MOD;
                    // no adge added
                } else {
                    merge(u, v);
                    // adding edge
                }
            }
            return (int) ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, findMaximum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {0,1,0,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(1, Arg3, findMaximum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, findMaximum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(3, Arg3, findMaximum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 6; int Arr1[] = {1,1,2,0,4,3,0,1,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,2,3,1,5,5,2,4,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 39; verify_case(4, Arg3, findMaximum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    CandyCupRunningCompetition ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
