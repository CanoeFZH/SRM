// BEGIN CUT HERE  
/* 
    
*/  
// END CUT HERE  
#line 7 "TPS.cpp"  
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

const int oo = (1 << 28);
const int N = 50;
const int M = 2500;

class TPS  
{  
    public:  
        bitset <M> coverSet[N];
        int minBeacons, n, d[N][N];
        void gao(bitset <M> invalidSet, long long mask, int beacons) {
            if(invalidSet.none()) {
                minBeacons = min(minBeacons, beacons);
                return;
            }
            for(int i = 0; i < n; i++) {
                if((1LL << i) & mask) {
                    continue;
                }
                if(invalidSet != (coverSet[i] & invalidSet)) {
                    gao(invalidSet & coverSet[i], mask | (1LL << i), beacons + 1);
                }
                if(beacons >= minBeacons) {
                    return;
                }
            }
        }
        int minimalBeacons(vector <string> linked) {   
            n = linked.size();
            if(n <= 2) return n - 1;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(i == j) {
                        d[i][j] = 0;
                    } else if(linked[i][j] == 'Y') {
                        d[i][j] = 1;
                    } else { 
                        d[i][j] = oo;
                    }
                }
            }
            for(int k = 0; k < n; k++) {
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
            for(int i = 0; i < n; i++) {
                coverSet[i].reset();
            }
            for(int k = 0; k < n; k++) {
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        if(d[k][i] == d[k][j] && i < j && k != i && k != j) {
                            coverSet[k].set(i * n + j);
                        }
                    }
                }
            }
            bitset <M> invalidSet;
            for(int i = 0; i < n * n; i++) {
                invalidSet.set(i);
            }
            minBeacons = oo;
            gao(invalidSet, 0, 0);
            int ret = minBeacons;
            return ret;
        }  
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYNN",
 "YNYN",
 "NYNY",
 "NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimalBeacons(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYYY",
 "YNNN",
 "YNNN",
 "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minimalBeacons(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNYNNNNNNN",
 "NNNNNYNNNN",
 "YNNYNNYNNN",
 "NNYNYNNYNN",
 "NNNYNYNNYN",
 "NYNNYNNNNY",
 "NNYNNNNNNN",
 "NNNYNNNNNN",
 "NNNNYNNNNN",
 "NNNNNYNNNN"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minimalBeacons(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNYNNYNN",
 "YNYNYNNYN",
 "NYNNNYNNY",
 "YNNNNNNNN",
 "NYNNNNNNN",
 "NNYNNNNNN",
 "YNNNNNNNN",
 "NYNNNNNNN",
 "NNYNNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minimalBeacons(Arg0)); }
	void test_case_4() { string Arr0[] = {"NYYYYYYYYY",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, minimalBeacons(Arg0)); }
	void test_case_5() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, minimalBeacons(Arg0)); }

// END CUT HERE
  
};  

// BEGIN CUT HERE  
int main()  
{  
    TPS ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE 
