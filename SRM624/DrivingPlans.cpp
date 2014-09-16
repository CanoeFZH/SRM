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

const int V = 2048;
const int MOD = 1000000009;

class DrivingPlans
{
    public:
        int N;
        vector <pair <int, int> > adj[V];
        void dijkstra(vector <int> & d, int s) {
            const int INF = 1 << 28;
            set <pair <int, int> > Q;
            d.resize(N, INF);
            d[s] = 0;
            for (int i = 0; i < N; i++) {
                Q.insert({INF, i});
            }
            Q.insert({0, s});
            while(!Q.empty()) {
                auto it = Q.begin();
                int u = it->second;
                Q.erase(it);
                for (auto &it: adj[u]) {
                    int v = it.first, w = it.second;
                    if (d[v] > d[u] + w) {
                        Q.erase(Q.find({d[v], v}));
                        d[v] = d[u] + w;
                        Q.insert({d[v], v});
                    }
                }
            }
        }

        int count(int N, vector <int> A, vector <int> B, vector <int> C) {
            this->N = N;
            for (int i = 0; i < V; i++) {
                adj[i].clear();
            }
            for (int i = 0; i < A.size(); i++) {
                A[i]--, B[i]--;
                adj[A[i]].push_back(make_pair(B[i], C[i]));
                adj[B[i]].push_back(make_pair(A[i], C[i]));
            }
            vector <int> d[2];
            dijkstra(d[0], 0);
            dijkstra(d[1], N - 1);
            for (int u = 0; u < N; u++) {
                for (auto& it: adj[u]) {
                    int v = it.first, w = it.second;
                    if (w == 0) {
                        if (d[0][u] + d[1][v] == d[0][N - 1] || d[1][v] + d[0][u] == d[1][0]) {
                            return -1;
                        }
                    }
                }
            }
            vector <int> dIndex(N);
            for (int i = 0; i < N; i++) {
                dIndex[i] = i;
            }
            vector <long long> dp(N, 0);
            dp[0] = 1;
            sort(dIndex.begin(), dIndex.end(), [&] (int a, int b) {
                    return d[0][a] < d[0][b];
                    });
            for (int u: dIndex) {
                for (auto &it: adj[u]) {
                    int v = it.first, w = it.second;
                    if (d[0][u] + w == d[0][v]) {
                        dp[v] = (dp[u] + dp[v]) % MOD;
                    }
                }
            }
            return dp[N - 1];
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {1,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {1,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {1,1,2,3,4,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4,5,6,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,2,2,3,3,4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    DrivingPlans ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
