// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxConnection2.cpp"
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

const int N = 64;
const long long MOD = 1000000007;

int son[N][N], degree[N];
long long dp[N][N][N];

void makeTree(int u, int parent, vector <int> & A, vector <int> & B) {
    degree[u] = 0;
    for (int i = 0; i < (int) A.size(); i++) {
        if (A[i] == u && B[i] != parent) {
            son[u][degree[u]++] = B[i];
            makeTree(B[i], u, A, B);
        }
        if (B[i] == u && A[i] != parent) {
            son[u][degree[u]++] = A[i];
            makeTree(A[i], u, A, B);
        }
    }
}

long long gao(int u, int k, int e) {
    if (dp[u][k][e] != -1) {
        return dp[u][k][e];
    }
    long long & ret = dp[u][k][e];
    if (k == 0) {
        ret = 1;
    } else if (e == degree[u]) {
        ret = k == 1 ? 1 : 0;
    } else {
        ret = 0;
        int v = son[u][e];
        for (int i = 0; i < k; i++) {
            long long p = gao(v, i, 0);
            long long q = gao(u, k - i, e + 1);
            ret += p * q % MOD;
        }
    }
    return ret;
}

class FoxConnection2
{
    public:
        int ways(vector <int> A, vector <int> B, int k) {
            int n = A.size() + 1;
            makeTree(1, 0, A, B);

            long long ret = 0;
            memset(dp, -1, sizeof(dp));
            for (int i = 1; i <= n; i++) {
                ret = (ret + gao(i, k, 0)) % MOD;
            }
            return (int) ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 3; verify_case(0, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; verify_case(1, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 3; verify_case(2, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,2,2,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; verify_case(3, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1,2,2,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 4; verify_case(4, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 923263934; verify_case(5, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(6, Arg3, ways(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FoxConnection2 ___test;
    ___test.run_test(-1);
    return 0;
}
