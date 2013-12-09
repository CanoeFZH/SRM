#line 2 "FoxAndGo3.cpp"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cassert>
#include <bitset>
#include <list>
#include <cmath>
#include <string>
#include <vector>
#include <numeric>
#include <climits>

using namespace std;

const int V = 2508;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

struct edge {
	int v, c, rev;
};

vector <edge> E[V];
bool used[V];

void init() { 
	memset(used, false, sizeof(used));
	for(int i = 0; i < V; i++) {
		E[i].clear();
	}
}

void addEdge(int u, int v, int c) {
	E[u].push_back((edge) {v, c, E[v].size()});
	E[v].push_back((edge) {u, 0, E[u].size() - 1});
}

int dfs(int u, int t, int flow) {
	if(u == t) return flow;
	used[u] = true;
	for(int i = 0; i < (int) E[u].size(); i++) {
		edge & e = E[u][i];
		if(!used[e.v] && e.c > 0) { 
			int f = dfs(e.v, t, min(flow, e.c));
			if(f > 0) {
				e.c -= f;
				E[e.v][e.rev].c += f;
				return f;
			}
		}
	}
	return 0;
}

int maxFlow(int s, int t) { 
	int ret = 0;
	while(true) {
		memset(used, false, sizeof(used));
		int flow = dfs(s, t, INT_MAX / 2);
		if (flow == 0) {
			break;
		}
		ret += flow;
	}
	return ret;
}

class FoxAndGo3
{
	public:
		int maxEmptyCells(vector <string> board) {
			init();
			int n = board.size(), m = board[0].size(), ret = 0;
			int s = n * m, t = n * m + 1;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					if(board[i][j] == 'o') {
						ret++;
						addEdge(s, i * m + j, 1);
						for(int k = 0; k < 4; k++) { 
							int nextI = i + dx[k];
							int nextJ = j + dy[k];
							if(nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m 
									&& board[nextI][nextJ] == '.') {
								addEdge(i * m + j, nextI * m + nextJ, 1);
							}
						}
					} else if (board[i][j] == '.') {
						ret++;
						addEdge(i * m + j, t, 1);
					}
				}
			}
			ret -= maxFlow(s, t);
			return ret;
		}
		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { string Arr0[] = {"o.o",
			".o.",
			"o.o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, maxEmptyCells(Arg0)); }
		void test_case_1() { string Arr0[] = {"...",
			".o.",
			"..."}
		; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, maxEmptyCells(Arg0)); }
		void test_case_2() { string Arr0[] = {"xxxxx",
			"xxoxx",
			"xo.ox",
			"xxoxx",
			"xxxxx"}
		; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, maxEmptyCells(Arg0)); }
		void test_case_3() { string Arr0[] = {".xox.",
			".o.ox",
			"x.o.o",
			"ox.ox",
			".ox.."}
		; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, maxEmptyCells(Arg0)); }
		void test_case_4() { string Arr0[] = {"o.o.o",
			".ox..",
			"oxxxo",
			"..x..",
			"o.o.o"}
		; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(4, Arg1, maxEmptyCells(Arg0)); }
		void test_case_5() { string Arr0[] = {"...",
			"...",
			"..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(5, Arg1, maxEmptyCells(Arg0)); }

		// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndGo3 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
