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

const int N = 128;

bool vis[N];

class RadioRange
{
    public:
        vector <int> x, y, r;
        int n, z;
        double min_R, max_R;
        void dfs(int u) {
            vis[u] = true;
            double R = sqrt(x[u] * 1.0 * x[u] + y[u] * 1.0 * y[u]);
            max_R = max(max_R, min(R + r[u], z + 0.0));
            min_R = min(min_R, min(max(R - r[u], 0.0), z + 0.0));
            for (int v = 0; v < n; v++) {
                long long distance = (x[u] - x[v]) * 1LL * (x[u] - x[v]) + (y[u] - y[v]) * 1LL *(y[u] - y[v]);
                long long R = (r[u] + r[v]) * 1LL * (r[u] + r[v]);
                if (distance <= R && !vis[v]) {
                    dfs(v);
                }
            }
        }
        double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z) {
            n = X.size(), x = X, y = Y, r = R, z = Z;
            vector <pair <double, double> > segment;
            memset(vis, false, sizeof(vis));
            for (int i = 0; i < n; i++) {
                if(!vis[i]) {
                    max_R = -1e30, min_R = 1e30;
                    dfs(i);
                    segment.push_back(make_pair(min_R, -max_R));
                }
            } 
            sort(segment.begin(), segment.end());
            double sum = 0;
            int i = 0;
            while(i < segment.size()) {
                double l = segment[i].first, r = -segment[i].second;
                int j = i + 1;
                while(j < segment.size() && segment[j].first <= r) {
                    r = max(r, -segment[j].second);
                    j++;
                }
                sum += r - l;
                i = j;
            }
            return 1 - sum / z;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; double Arg4 = 0.5; verify_case(0, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; double Arg4 = 0.0; verify_case(1, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; double Arg4 = 0.4142135623730951; verify_case(2, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {11, -11, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 11, -11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 10, 10, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 31; double Arg4 = 0.3548387096774194; verify_case(3, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; double Arg4 = 1.0; verify_case(4, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000000000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000000000; double Arg4 = 0.41421356237309503; verify_case(5, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {20, -20, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 20, -20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50, 50, 50, 50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 100; double Arg4 = 0.3; verify_case(6, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_7() { int Arr0[] = {0, -60, -62, -60, 63, -97}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-72, 67, 61, -8, -32, 89}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6, 7, 8, 7, 5, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 918; double Arg4 = 0.9407071068962471; verify_case(7, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    RadioRange ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
