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

class BitTree 
{
    private:
        vector <int> C;
    public:
        void init(int n) {
            C.assign(n, 0);
        }

        inline int lowbit(int x) {
            return x & (-x);
        }

        void add(int x, int value) {
            while(x < C.size()) {
                C[x] += value;
                x += lowbit(x);
            }
        }

        int sum(int x) { // (0, x]
            int ret = 0;
            while(x > 0) {
                ret += C[x];
                x -= lowbit(x);
            }
            return ret;
        }

        int sum (int left, int right) { // (left, right]
            return sum(right) - sum(left);
        }
};

class GraphInversions
{
    static const int N = 1024;
    static const int INF = 1 << 28;
    public:
    BitTree bitTree;
    vector <int> E[N], V;
    vector <bool> vis;
    int dfs(int pre, int u, int pathLength, int inversion) {
        if (pathLength == 1) {
            return inversion;
        }
        int ret = INF;
        vis[u] = true;
        bitTree.add(V[u], 1);
        for (int & v: E[u]) {
            if (pre != v && !vis[v]) {
                ret = min(ret, dfs(u, v, pathLength - 1, inversion + bitTree.sum(V[v] - 1)));
            }
        }
        bitTree.add(V[u], -1);
        vis[u] = false;
        return ret;
    }
    int getMinimumInversions(vector <int> A, vector <int> B, vector <int> V, int K) {
        int n = A.size();
        this->V = V;
        for (int i = 0; i < n; i++) {
            E[i].clear();
        }
        for (int i = 0; i < n; i++) {
            E[A[i]].push_back(B[i]);
            E[B[i]].push_back(A[i]);
        }
        int ret = INF;
        for (int i = 0; i < n; i++) {
            bitTree.init(N);
            vis.assign(N, false);
            ret = min(ret, dfs(-1, i, K, 0));
        }
        return ret == INF ? -1 : ret;
    }


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
