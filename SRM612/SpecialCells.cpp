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

const int V = 64;
const int E = V * V * 2;
const int INF = 1 << 29;

int d[V], how[V], eCapacity[E], eU[E], eV[E], eCost[E];
int eIndex = 0;

void addEdge(int u, int v, int capacity, int cost) {
    eU[eIndex] = u, eV[eIndex] = v, eCapacity[eIndex] = capacity, eCost[eIndex++] = cost;
    eU[eIndex] = v, eV[eIndex] = u, eCapacity[eIndex] = 0, eCost[eIndex++] = -cost;
}

pair <int, int> minCostMaxFlow(int n, int s, int t) {
    int flow = 0, cost = 0;
    for (;;) {
       for (int i = 0; i < n; i++) {
           d[i] = INF;
       }
       d[s] = 0;
       for(;;) {
           bool done = true;
           for (int e = 0; e < eIndex; e++) {
               if (eCapacity[e] > 0) {
                   int u = eU[e], v = eV[e], cost = eCost[e];
                   if (d[v] > d[u] + cost) {
                       d[v] = d[u] + cost;
                       how[v] = e;
                       done = false;
                   }
               }
           }
           if (done) {
               break;
           }
       }
       if (d[t] >= INF / 2) {
           break;
       }
       int augment = INF;
       for (int v = t; v != s; v = eU[how[v]]) {
           augment = min(augment, eCapacity[how[v]]);
       }
       for (int v = t; v != s; v = eU[how[v]]) {
           int e = how[v];
           eCapacity[e] -= augment;
           eCapacity[e ^ 1] += augment;
       }
       flow += augment;
       cost += d[t] * augment;
    }
    pair <int, int> ret = make_pair(cost, flow);
    return ret;
}

class SpecialCells
{
    public:
        int guess(vector <int> x, vector <int> y) {
            eIndex = 0;
            map <int, int> xMap, yMap;
            set <pair <int, int> > pairSet;
            int n = x.size();
            for (int i = 0; i < n; i++) {
                xMap[x[i]]++;
                yMap[y[i]]++;
                pairSet.insert(make_pair(x[i], y[i]));
            }
            int grpahVertexNumber = xMap.size() + yMap.size() + 2;
            int s = grpahVertexNumber - 2, t = grpahVertexNumber - 1, xIndex = 0, yIndex = xMap.size();
            for (map <int, int> :: iterator it = xMap.begin(); it != xMap.end(); it++, xIndex++) {
                addEdge(s, xIndex, it->second, 0);
            }
            for (map <int, int> :: iterator it = yMap.begin(); it != yMap.end(); it++, yIndex++) {
                addEdge(yIndex, t, it->second, 0);
            }
            xIndex = 0; 
            for (map <int, int> :: iterator it = xMap.begin(); it != xMap.end(); it++, xIndex++) {
                yIndex = xMap.size();
                for (map <int, int> :: iterator jt = yMap.begin(); jt != yMap.end(); jt++, yIndex++) {
                    int cost = pairSet.find(make_pair(it->first, jt->first)) == pairSet.end() ? 0 : 1;
                    addEdge(xIndex, yIndex, 1, cost);
                }
            }
            pair <int, int> mcmf = minCostMaxFlow(grpahVertexNumber, s, t);
            int ret = mcmf.first;
            return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, guess(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, guess(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,1,2,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(2, Arg2, guess(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(3, Arg2, guess(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,100000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, guess(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    SpecialCells ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
