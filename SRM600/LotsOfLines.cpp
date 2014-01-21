// BEGIN CUT HERE  
/* 
    
*/  
// END CUT HERE  
#line 7 "LotsOfLines.cpp"  
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

const int N = 1210;

int sum[N][N];

class LotsOfLines  
{  
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    public:  
        long long countDivisions(int A, int B) {   

            memset(sum, 0, sizeof(sum));
            for (int i = 1; i < A; i++) {
                for (int j = 1; j < B; j++) {
                    int delta = gcd(i, j) == 1 ? 1 : 0;
                    sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + delta;
                }
            }
            long long ret = 1;
            for (int a = 0; a < A; a++) {
                for (int b = 0; b < B; b++) {
                    ret++; // a == a'
                    if (a != 0) { //  a < a'
                        ret += 1 + sum[a][b] + sum[a][B - 1 - b];
                    }
                }
            }
            return ret;
        }  
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; long long Arg2 = 2LL; verify_case(0, Arg2, countDivisions(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; long long Arg2 = 9LL; verify_case(1, Arg2, countDivisions(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; long long Arg2 = 17LL; verify_case(2, Arg2, countDivisions(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1200; long long Arg2 = 1201LL; verify_case(3, Arg2, countDivisions(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 9; long long Arg2 = 638LL; verify_case(4, Arg2, countDivisions(Arg0, Arg1)); }

// END CUT HERE
  
};  

// BEGIN CUT HERE  
int main()  
{  
    LotsOfLines ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE 
