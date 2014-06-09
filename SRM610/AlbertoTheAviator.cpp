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
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 64;
const int FUEL = 5028;

int dp[N][FUEL];

class AlbertoTheAviator
{
    public:
        int n;
        vector <int> duration, refuel, id;
        int gao(int idx, int fuel) {
            if(dp[idx][fuel] != -1) {
                return dp[idx][fuel];
            }
            int & ret = dp[idx][fuel];
            ret = 0;
            if (idx == n) {
                return ret;
            } else {
                ret = max(ret, gao(idx + 1, fuel));
                int realIndex = id[idx];
                if (fuel >= duration[realIndex]) {
                    ret = max(ret, gao(idx + 1, fuel - duration[realIndex] + refuel[realIndex]) + 1);
                }
            }
            return ret;
        }
        int MaximumFlights(int F, vector <int> duration, vector <int> refuel) {
            this->n = duration.size();
            this->duration = duration;
            this->refuel = refuel;
            id.resize(n, 0);
            for (int i = 0; i < n; i++) {
                id[i] = i;
            }
            sort(id.begin(), id.end(), [&] (int i, int j) {
                    return refuel[i] > refuel[j];
                    });
            memset(dp, -1, sizeof(dp));
            return gao(0, F);
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, MaximumFlights(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {8, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, MaximumFlights(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 12; int Arr1[] = {4, 8, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 0, 0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(2, Arg3, MaximumFlights(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 9; int Arr1[] = {4, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, MaximumFlights(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 100; int Arr1[] = {101}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(4, Arg3, MaximumFlights(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1947; int Arr1[] = {2407, 2979, 1269, 2401, 3227, 2230, 3991, 2133, 3338, 356, 2535, 3859, 3267, 365}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2406, 793, 905, 2400, 1789, 2229, 1378, 2132, 1815, 355, 72, 3858, 3266, 364}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(5, Arg3, MaximumFlights(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    AlbertoTheAviator ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
