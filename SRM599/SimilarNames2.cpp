// BEGIN CUT HERE  
/* 
    
*/  
// END CUT HERE  
#line 7 "SimilarNames2.cpp"  
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

const int N = 50;
const long long MOD = 1000000007LL;

class SimilarNames2  
{  
    public: 
        vector <string> names;
        int prefixCache[N][N];

        int isPrefix(int a, int b) {
            if (prefixCache[a][b] != -1) {
                return prefixCache[a][b];
            }
            int & ret = prefixCache[a][b];
            if (names[b].size() < names[a].size()) {
                ret = 0;
            } else if (names[b].substr(0, names[a].size()) != names[a]) {
                ret = 0; 
            } else {
                ret = 1;
            }
            return ret;
        }
        int count(vector <string> names, int L) {   
        
            this->names = names;
            int n = names.size();
            long long dp[L + 1][n];
            memset(dp, 0, sizeof(dp));
            memset(prefixCache, -1, sizeof(prefixCache));
            for (int i = 0; i < n; i++) {
                dp[1][i] = 1;
            }
            for (int i = 2; i <= L; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        if (j != k && isPrefix(k, j) == 1) {
                            dp[i][j] += dp[i - 1][k];
                        }
                    }
                    dp[i][j] %= MOD;
                }
            }
                
            long long ret = 0;
            for (int i = 0; i < n; i++) {
                ret = (ret + dp[L][i]) % MOD;
            }
            for (int i = 1; i <= n - L; i++) {
                ret = (ret * i) % MOD;
            }
            return (int) ret;
        }  
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a", "aa", "aaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"hideo", "hideto", "hideki", "hide"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 6; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"aya", "saku", "emi", "ayane", "sakura", "emika", "sakurako"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 24; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"taro", "jiro", "hanako"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"alice", "bob", "charlie"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"ryota", "ryohei", "ryotaro", "ryo", "ryoga", "ryoma", "ryoko", "ryosuke", "ciel", "lun",
 "ryuta", "ryuji", "ryuma", "ryujiro", "ryusuke", "ryutaro", "ryu", "ryuhei", "ryuichi", "evima"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 276818566; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
  
};  

// BEGIN CUT HERE  
int main()  
{  
    SimilarNames2 ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE 
