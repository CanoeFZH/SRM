// BEGIN CUT HERE

// END CUT HERE
#line 5 "BigO.cpp"
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

vector <int> scc, sccG[N];
int dp[N], reach[N][N], sccId[N];
bool compressed[N];

class BigO
{
    public:
        int gao(int u) {
            if (dp[u] != -1) {
                return dp[u];
            }
            int & ret = dp[u];
            ret = 0;
            for (int i = 0; i < sccG[u].size(); i++) {
                int v = sccG[u][i];
                ret = max(ret, gao(v));
            }
            if (compressed[u]) {
                ret += 1;
            }
            return ret;
        }

        int minK(vector <string> graph) {
            memset(reach, 0, sizeof(reach));
            int n = graph.size();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (graph[i][j] == 'Y') {
                        reach[i][j] = 1;
                    }
                }
            }
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        reach[i][j] |= reach[i][k] & reach[k][j];
                    }
                }
            }
            int sccIndex = 0;
            memset(sccId, -1, sizeof(sccId));
            for (int i = 0; i < n; i++) {
                if (sccId[i] == -1) {
                    scc.clear();
                    scc.push_back(i);
                    sccId[i] = sccIndex;
                    compressed[sccIndex] = false;
                    for (int j = i + 1; j < n; j++) {
                        if (reach[i][j] == 1 && reach[j][i] == 1) {
                            compressed[sccIndex] = true;
                            scc.push_back(j);
                            sccId[j] = sccIndex;
                        }
                    }
                    if (scc.size() > 1) {
                        for (int u: scc) {
                            int degree = 0;
                            for (int v: scc) {
                                if (u != v && graph[u][v] == 'Y') {
                                    degree++;
                                }
                            }
                            if (degree > 1) {
                                return -1;
                            }
                        }
                    }
                    sccIndex++;
                }
            }
            for (int i = 0; i < sccIndex; i++) {
                sccG[i].clear();
                set <int> component;
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        if (graph[j][k] == 'Y' && sccId[j] == i && sccId[k] != i) {
                            component.insert(sccId[k]);
                        }
                    }
                }
                for (int x: component) {
                    sccG[i].push_back(x);
                }
            }

            memset(dp, -1, sizeof(dp));
            int ret = 0;
            for (int i = 0; i < sccIndex; i++) {
                ret = max(ret, gao(i) - 1);
            }
            return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYYN", "YNNN", "NNNY", "NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minK(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYNNN",
 "NNYNN",
 "NNNYN",
 "NNNNY",
 "NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minK(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYNNN",
 "YNNNN",
 "NNNYN",
 "NNNNY",
 "NNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minK(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYYYNYYYNNYYYYYYNYNN",
 "NNNNYNYYNNYYYNYYNYYN",
 "NYNNYYYNNNYYYYNYNYNN",
 "NYYNNYYYYNNNYYNNYNYY",
 "NYNYNNNNNNYYYYYNYYYN",
 "YNNNNNNYNNYNNYYYYYYY",
 "NNYYNNNNNYNYNYNNYNYY",
 "NNYNYYNNNNYNYNYYYYNN",
 "NYYNYYNNNYNNYYYNYNYN",
 "YYNNYNNYYNYNNNNNYNNN",
 "YYNYYNNYYYNYYNYNYYYY",
 "YYNNYYNYNYNNNNYNNNNY",
 "NNYYNYYYNNNNNYYYYYNY",
 "YNNNYNNNNYNNNNNYNNNY",
 "YYYYNYYNNYNNNNNYNNNN",
 "NYYYYNYNYYNNYNNNYNNY",
 "YYYYYNNNYYYYNYYYNNYN",
 "NNYNNYNYNYNNNNNNYNYN",
 "YYNYYNNNNNYNNYNYNNNY",
 "YYYYNYNYYNNYNYNYNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, minK(Arg0)); }
	void test_case_4() { string Arr0[] = {"NYNYYYNYYYNYYNYYNYYNYYNYNNYYYYNNNYYNNNYNYYNYNNNYNY",
 "NNNNNNNNNNNNNNNNYNNNYNNNNNYNYNYNNNNNNYNNNNNNNNNNNN",
 "NYNYYYYNYNYYNNYYYYYYYYYYNYYYNYYYYYYNNYYYYYYYNNYYYY",
 "NYNNYYNNNNNNNNNNNYNNNYNYNNYNYNYYNYYNNYYYNNNNNNNYYY",
 "NNNNNNNNNNNNYNNYYNNNYNNNNYNNYNNYNNYNNYNYNNNNNNNYYN",
 "NNNNNNNNNNNNNNNNYNNNYNNNNNNNNNYNNNNNNYNNNNNNNNNNNN",
 "YYNYNNNYNYYYYNYYYYYYYYYYNYYYYYYYNYYNNYNYYYYYNNYNYY",
 "NYNYYNNNYYNNYNNYYYNNYYNYNYYNYYYNNNYNNYYYNNNNNNNYYY",
 "NYNYYYNYNYNNNNNYYYNNNNNNNYYNYYYYNYYNNYYYNNNNNNNYYY",
 "NYNNNYNNNNNNNNNYYNNNYNNNNNYNYNYNNYYNNYNYNNNYNNNNYN",
 "NYNYYYNNYYNYYNYNYYNYYYNYNYYNYYYYNYNNNNYYYYNYNNNYNY",
 "NYNNYYNNNYNNYNNYYYNNYYNNNYYNYYNNNYYNNNNYNNNYNNNYYY",
 "NNNNNNNNNNNNNNNYYNNNYNNNNNNNYNNYNYNNNYYNNNNNNNNYNN",
 "YYYYNYYYYYYYYNYYYYNYYYYYYYYYYYNYYNYYYNYYYYYNNYYNYN",
 "NYNYYNNYYYNYYNNYYYNYNYNYNYYNYYYYNYYNNYYYYYNYNNNNNY",
 "NYNNNNNNNNNNNNNNYNNNYNNNNNYNYNYYNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNN",
 "NYNNNYNNNNNNNNNYYNNNNNNNNNNNYNYYNYYNNYNNNNNNNNNYYN",
 "NYNYYYNNYYNYNNYYYYNYYYNYNYYYYNNYNNYNNYNYYYYNNNYYYY",
 "NNNYYYNNNYNYYNNYYYNNYYNNNYYNYYYYNYYNNNYYNYNYNNNYYY",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNNNYNNNNNNNNNYNNNNNNNNNYYNYYYYNYYNNYNNNNNNNNNYYN",
 "YYNYYYNNYYNYYNYNYYNYNYNYNYYYYYYYNYNNNYYYYYNYNNYYYY",
 "NYNYYYNNNNNNYNNNYYNNYYNNNYYNYYYYNYYNNYYYNNNNNNNYNY",
 "YNNNYYYYYYYYYNYYYYYYYYYNNYYNYNYNYNNYYYYYYYNYNNYYYY",
 "NYNNNYNNNNNNNNNYYNNNYNNNNNYNYNYYNYYNNNNYNNNNNNNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN",
 "NYNYYYNYYYNYNNNNYYNYYNNYNYYNYYYYNYYNNNNNYYNYNNYYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
 "NYNNNYNNNNNNNNNYYNNNYNNNNNNNNNYYNYYNNNNYNNNNNNNYYY",
 "NNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNYNNNYNNNNNYNNNYNNNNNNNNNNNNNNNNNNN",
 "NYNYYNNYYYNNNNNYYYNYYYNNNYYYYYYYNYYNNYYYYNNYNNNNYY",
 "NNNNNNNNNNNNNNNYYNNNYNNNNNYNYNYYNNNNNYNNNNNNNNNNNN",
 "NYNNNNNNNNNNNNNNYNNNYNNNNNYNNNYYNNNNNNNNNNNNNNNYNN",
 "NYNYYYYYNYYYYNYYYYYYNYYYNNNYYYYYNYYNYNYYYYYYNYYYNY",
 "YYNYYYNYYYNNNNNYNYYYYNYNNNYYYYYYNYYNNYYNYNNYNNYNNY",
 "NNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNNNYNNNNNNNNNYYNNNNYNNNNYNYNNYNNNNNYNYNNNNNNNYNN",
 "NYNNNYNNNNNNNNNYYNNNNNNNNYYNYNYNNYYNNNNNNNNNNNNYNN",
 "NYNYYYNYYYNYNNNNNYNNYYNYNNYNNYYYNYYNNYYYNNNNNNNYYY",
 "NYNYYNNNNYNYYNNYYYNYYYNNNYYNYYYNNYYNNYYYNNNYNNNNYY",
 "NYNYNYNYYYNYYNYYNYNYNYYYNNYYYYYYNNNNNYYYNYNYNNYNYY",
 "NYNNNYNNNYNNNNNYYYNNYNNNNNYNYNNNNYYNNYNYNNNNNNNYYN",
 "YYYNNYNYYYNYNNYYYYYNYYNYNYYYYYNYYNYNYYYYYNNYNNYNYN",
 "YYNNYYYYYYYNYNYYNYYYYYYYYYYNYYYNYYYNNYYYYNYYNNYYYY",
 "NYNNYYNYYYNNYNNYYYNYNYNYNYYNNYYNNYNNNYYYNYNYNNNNYY",
 "NNNNNNNNNNNNNNNNYNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNYNNNNNYNYNYNNNNNNYNNNNNNNNNYNN",
 "NYNNYYNNNNNNNNNYYNNNNNNNNYYNYNNYNYYNNYNYNNNNNNNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, minK(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    BigO ___test;
    ___test.run_test(-1);
    return 0;
}
