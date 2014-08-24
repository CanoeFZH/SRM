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

class UniformBoard
{
    public:
        int cnt[3], rectangleCnt[3], n;
        vector <string> board;
        bool can(int r, int c, int startR, int startC, int K) {
            memset(rectangleCnt, 0, sizeof(rectangleCnt));
            for (int i = startR; i < startR + r; i++) {
                for (int j = startC; j < startC + c; j++) {
                    if (board[i][j] == '.') {
                        rectangleCnt[0]++;
                    } else if (board[i][j] == 'A') {
                        rectangleCnt[1]++;
                    } else if (board[i][j] == 'P') {
                        rectangleCnt[2]++;
                    }
                }
            }
            while(K > 0) {
                int step = 0;
                if (rectangleCnt[2] > 0 && cnt[0] - rectangleCnt[0] > 0) {
                    step = min(rectangleCnt[2], cnt[0] - rectangleCnt[0]);
                    step = min(step, K);
                    rectangleCnt[2] -= step;
                    rectangleCnt[0] += step;
                    K -= step;
                } else if (cnt[1] - rectangleCnt[1] > 0 && rectangleCnt[0] > 0) {
                    step = min(cnt[1] - rectangleCnt[1], rectangleCnt[0]);
                    step = min(step, K);
                    rectangleCnt[1] += step;
                    rectangleCnt[0] -= step;
                    K -= step;
                } else {
                    break;
                }
            }
            if (rectangleCnt[1] == r * c) {
                return true;
            } else {
                return false;
            }
        }
        int getBoard(vector <string> board, int K) {
            this->board = board;
            n = board.size();
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == '.') {
                        cnt[0]++;
                    } else if (board[i][j] == 'A') {
                        cnt[1]++;
                    } else if (board[i][j] == 'P') {
                        cnt[2]++;
                    }
                }
            }
            int ret = 0;
            for (int r = 1; r <= n; r++) {
                for (int c = 1; c <= n; c++) {
                    for (int i = 0; i + r - 1 < n; i++) {
                        for (int j = 0; j + c - 1 < n; j++) {
                            if (can(r, c, i, j, K)) {
                                ret = max(ret, r * c);
                            }
                        }
                    }
                }
            }
            return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AP",
 ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AP",
 ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"PPP",
 "APA",
 "A.P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(2, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AAA",
 "PPP",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(3, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 0; verify_case(4, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"PPAAPA..AP",
 "PPA.APAP..",
 "..P.AA.PPP",
 "P.P..APAA.",
 "P.P..P.APA",
 "PPA..AP.AA",
 "APP..AAPAA",
 "P.P.AP...P",
 ".P.A.PAPPA",
 "..PAPAP..P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 15; verify_case(5, Arg2, getBoard(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    UniformBoard ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
