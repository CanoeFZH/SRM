// BEGIN CUT HERE  
/* 
    
*/  
// END CUT HERE  
#line 7 "FindPolygons.cpp"  
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

const int N = 2501 * 2501;
const int oo = 1 << 28;

int squares[N + 1];

class FindPolygons  
{  
    public:  
        double minimumPolygon(int L) {   

            memset(squares, -1, sizeof(squares));
            for (int i = 1; i * i <= N; i++) {
                squares[i * i] = i;
            }
            vector <pair <int, int> > v;
            int maxLength = L / 2;
            for (int c = 1; c <= maxLength; c++) {
                for(int a = 0; a <= c; a++) {
                    int b2 = c * c - a * a;
                    if (squares[b2] != -1) {
                        v.push_back({a, squares[b2]});
                    }
                }
            }
            
            int best = oo;
            for(int i = 0; i < (int) v.size(); i++) {
                for(int j = i + 1; j < (int) v.size(); j++) {
                    int x1 = v[i].first, y1 = v[i].second;
                    int x2 = v[j].first, y2 = v[j].second;
                    int deltaX = x1 - x2, deltaY = y1 - y2;
                    int c2 = deltaX * deltaX + deltaY * deltaY;
                    if (c2 <= N && squares[c2] != -1 && x1 * y2 - x2 * y1 != 0) {
                        int a = squares[x1 * x1 + y1 * y1];
                        int b = squares[x2 * x2 + y2 * y2];
                        int c = squares[c2];
                        if (a + b + c == L) {
                            best = min(best, max({a, b, c}) - min({a, b, c}));
                        }
                    }
                }
            }

            double ret = -1;
            if (best != oo) {
                ret = (double) best;
            } else if (L % 2 == 0 && L != 2) {
                ret = L % 4 == 0 ? 0 : 1;
            }
            return ret;
        }  
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; double Arg1 = 0.0; verify_case(0, Arg1, minimumPolygon(Arg0)); }
	void test_case_1() { int Arg0 = 5; double Arg1 = -1.0; verify_case(1, Arg1, minimumPolygon(Arg0)); }
	void test_case_2() { int Arg0 = 12; double Arg1 = 2.0; verify_case(2, Arg1, minimumPolygon(Arg0)); }
	void test_case_3() { int Arg0 = 4984; double Arg1 = 819.0; verify_case(3, Arg1, minimumPolygon(Arg0)); }

// END CUT HERE
  
};  

// BEGIN CUT HERE  
int main()  
{  
    FindPolygons ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE 
