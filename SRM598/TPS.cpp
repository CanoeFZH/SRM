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

const int N = 64;
const int oo = 1 << 28;

int dp[N][N][2];

class TPS  
{  
    public: 
        int n;
        vector <string> linked;

        int gao(int u, int parent, int must) {
            int & ret = dp[u][parent][must];
            if (ret != -1) {
                return ret;
            }
            ret = oo;
            int sum = 0, son = 0;
            for (int v = 0; v < n; v++) {
                if (v != parent && linked[u][v] == 'Y') {
                    son++;
                    sum += gao(v, u, 1);
                }
            }

            if (son == 0) {
                ret = must;
            } else {
                int choice = oo;
                for (int v = 0; v < n; v++) {
                    if (v != parent && linked[u][v] == 'Y') {
                        choice = min(sum - gao(v, u, 1) + gao(v, u, 0), choice);
                    }
                }

                ret = min(ret, 1 + choice);
                if (parent != n) {
                    if (must == 1 && son == 1) {
                        ret = min(ret, sum);
                    } else {
                        ret = min(ret, choice);
                    }
                }
            }
            return ret;
        }

        int minimalBeacons(vector <string> linked) {   
            this->linked = linked;
            memset(dp, -1, sizeof(dp));
            n = linked.size();
            int ret = oo;
            for (int i = 0; i < n; i++) {
                ret = min(gao(i, n, 0), ret);
            }
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
