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
#include <list>

using namespace std;

class GCDLCMEasy
{
    public:
        vector <list <tuple <int, int, int> > > graph;
        vector <int> value;
    public:
        int gcd(int a, int b) {
            return b == 0 ? a : gcd(b, a % b);
        }

        int lcm(int a, int b) {
            return a / gcd(a, b) * b; 
        }
        
        void reset(int u) {
            if (value[u] != -1) {
                value[u] = -1;
                for (auto edge: graph[u]) {
                    int v, g, l;
                    tie(v, g, l) = edge;
                    reset(v);
                }
            }
        }

        bool dfs(int u, int a) {
            if (value[u] == a) {
                return true;
            } else if (value[u] == -1) {
                value[u] = a;
                for (auto edge: graph[u]) {
                    int v, g, l;
                    tie(v, g, l) = edge;
                    int p = g * l;
                    if (p % a != 0) {
                        return false;
                    } 
                    int b = p / a;
                    if (gcd(a, b) != g || lcm(a, b) != l) {
                        return false;
                    }
                    if (!dfs(v, b)) {
                        return false;
                    }
                }
                return true;
            } else {
                return false;
            }
        }

        string possible(int n, vector <int> A, vector <int> B, vector <int> G, vector <int> L) {
            const string Y = "Solution exists";
            const string N = "Solution does not exist";
            const int UPBOUND = 10000;
            graph.clear();
            graph.resize(n);
            for (int i = 0; i < A.size(); i++) {
                graph[A[i]].push_back(make_tuple(B[i], G[i], L[i]));
            }
            value.clear();
            value.assign(n, -1);
            for (int i = 0; i < n; i++) {
                if (value[i] != -1) {
                    continue;
                }
                bool resolved = false;
                for (int x = 1; x <= UPBOUND; x++) {
                    reset(i);
                    if (dfs(i, x)) {
                        resolved = true;
                        break;
                    }
                }
                if (!resolved) {
                    return N;
                }
            }
            return Y;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {0,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,6,6,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {12,12,12,12}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "Solution exists"; verify_case(0, Arg5, possible(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {0,1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,6,6,6,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {12,12,12,12,12}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "Solution does not exist"; verify_case(1, Arg5, possible(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {123,123}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {456,789}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "Solution does not exist"; verify_case(2, Arg5, possible(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1234}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5678}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "Solution does not exist"; verify_case(3, Arg5, possible(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 6; int Arr1[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 2, 3, 3, 1, 2, 5, 1, 5, 1, 7, 7, 3, 5, 7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {30, 42, 30, 42, 210, 70, 30, 210, 70, 210, 42, 70, 105, 105, 105}
; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "Solution exists"; verify_case(4, Arg5, possible(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 500; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {10}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "Solution exists"; verify_case(5, Arg5, possible(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    GCDLCMEasy ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
