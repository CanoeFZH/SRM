// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysCandyGame.cpp"
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

const int INF = 1 << 30;

class EllysCandyGame
{
    public:
        int n;
        map <vector <int>, int> memo;
        vector <int> take(vector <int> boxes, int index) {
            if (index - 1 >= 0) {
                boxes[index - 1] *= 2;
            }
            if (index + 1 < n) {
                boxes[index + 1] *= 2;
            }
            boxes[index] = 0;
            return boxes;
        }

        int gao(vector <int> boxes) {
            if (memo.find(boxes) != memo.end()) {
                return memo[boxes];
            }
            int & ret = memo[boxes];
            ret = -INF;
            for (int i = 0; i < n; i++) {
                if (boxes[i] != 0) {
                    ret = max(ret, boxes[i] - gao(take(boxes, i)));
                }
            }
            if (ret == -INF) {
                ret = 0;
            }
            return ret;
        }

        string getWinner(vector <int> sweets) {
            memo.clear();
            n = sweets.size();
            int maxDiff = gao(sweets);
            if (maxDiff > 0) {
                return "Elly";
            } else if (maxDiff < 0) {
                return "Kris";
            } else {
                return "Draw";
            }
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {20, 50, 70, 0, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Kris"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { int Arr0[] = {42, 13, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Elly"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { int Arr0[] = {10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Draw"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { int Arr0[] = {3, 1, 7, 11, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Kris"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { int Arr0[] = {41, 449, 328, 474, 150, 501, 467, 329, 536, 440}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Kris"; verify_case(4, Arg1, getWinner(Arg0)); }
	void test_case_5() { int Arr0[] = {177, 131, 142, 171, 411, 391, 17, 222, 100, 298}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Elly"; verify_case(5, Arg1, getWinner(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    EllysCandyGame ___test;
    ___test.run_test(-1);
    return 0;
}
