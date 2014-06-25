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
#include <queue>

using namespace std;

const int N = 2048;
const int INF = 1 << 30;

int d[N][N + 1];

class EmoticonsDiv1
{
    public:
        int printSmiles(int smiles) {
            memset(d, 0x5f, sizeof(d));
            d[1][0] = 0;
            pair <int, int> s = make_pair(1, 0);
            queue <pair <int, int> > q;
            q.push(s);
            while(!q.empty()) {
                pair <int, int> u = q.front();
                q.pop();
                int smile = u.first, clipboard = u.second;
                int update = d[smile][clipboard] + 1;
                if (d[smile][smile] > update) {
                    d[smile][smile] = update;
                    q.push(make_pair(smile, smile));
                }
                if (smile + clipboard < N && d[smile + clipboard][clipboard] > update) {
                    d[smile + clipboard][clipboard] = update;
                    q.push(make_pair(smile + clipboard, clipboard));
                }
                if (smile > 1 && d[smile - 1][clipboard] > update) {
                    d[smile - 1][clipboard] = update;
                    q.push(make_pair(smile - 1, clipboard));
                }
            }
            int ret = INF;
            for (int i = 0; i < N; i++) {
                ret = min(d[smiles][i], ret);
            }
            return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; verify_case(0, Arg1, printSmiles(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; verify_case(1, Arg1, printSmiles(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 5; verify_case(2, Arg1, printSmiles(Arg0)); }
	void test_case_3() { int Arg0 = 18; int Arg1 = 8; verify_case(3, Arg1, printSmiles(Arg0)); }
	void test_case_4() { int Arg0 = 11; int Arg1 = 8; verify_case(4, Arg1, printSmiles(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    EmoticonsDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
