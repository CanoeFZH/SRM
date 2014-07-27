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

class AmebaDiv1
{
    public:
        int count(vector <int> X) {
            set <int> S, xS;
            for (auto &x: X) {
                xS.insert(x);
            }
            for (int i = 0; i < X.size(); i++) {
                set <int> possibleSet;
                possibleSet.insert(X[i]);
                for (int j = i - 1; j >= 0; j--) {
                    if (possibleSet.find(X[j]) != possibleSet.end()) {
                        possibleSet.erase(X[j]);
                    }
                    if (possibleSet.find(2 * X[j]) != possibleSet.end()) {
                        possibleSet.insert(X[j]);
                    }
                }
                if (possibleSet.size() != 0) {
                    S.insert(X[i]);
                    if (xS.find(2 * X[i]) != xS.end()){
                        S.erase(2 * X[i]);
                    }
                }
            }
            return S.size();
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {2,2,2,2,2,2,4,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,4,8,16,32,64,128,256,1024,2048}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arr0[] = {854,250,934,1000,281,250,281,467,854,562,934,1000,854,500,562}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    AmebaDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
