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

class TaroJiroGrid
{
    public:
        int n;
        vector <string> grid;
        bool check() {
            for (int j = 0; j < n; j++) {
                int maxCnt = 0, consecutive = 1;
                for (int i = 1; i < n; i++) {
                    if (grid[i - 1][j] != grid[i][j]) {
                        maxCnt = max(consecutive, maxCnt);
                        consecutive = 1;
                    } else {
                        consecutive += 1;
                    }
                }
                if (grid[n - 2][j] == grid[n - 1][j]) {
                    maxCnt = max(maxCnt, consecutive);
                }
                if (maxCnt > n / 2) {
                    return false;
                }
            }
            return true;
        }

        int get1(int x) {
            int ret = 0;
            while(x) {
                ret ++;
                x &= x - 1;
            }
            return ret;
        }
        int getNumber(vector <string> g) {
            this->grid = g;
            n = grid.size();
            char chRaw[] = {'B', 'W', 'B', 'W'};
            char chNext[] = {'W', 'B', 'W', 'B'};
            int ret = 1024;
            for (int it = 0; it < n; it++) {
                int index[] = {n / 2, n / 2, it, it};
                for (int i = 0; i < 16; i++) {
                    this->grid = g;
                    for (int j = 0; j < 4; j++) {
                        if ((i >> j) & 1) {
                            for (int k = 0; k < n; k++) {
                                if (g[index[j]][k] == chRaw[j]) {
                                    grid[index[j]][k] = chNext[j];
                                }
                            }
                        }
                    }
                    if (check()) {
                        ret = min(ret, get1(i));
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
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"WB",
 "BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arr0[] = {"WB",
 "WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arr0[] = {"WB",
 "WB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arr0[] = {"WBBW",
 "WBWB",
 "WWBB",
 "BWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arr0[] = {"WBBWBB",
 "BBWBBW",
 "WWBWBW",
 "BWWBBB",
 "WBWBBW",
 "WWWBWB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    TaroJiroGrid ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
