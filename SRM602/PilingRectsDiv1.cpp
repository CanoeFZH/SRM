// BEGIN CUT HERE  
/* 
    
*/  
// END CUT HERE  
#line 7 "PilingRectsDiv1.cpp"  
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

class PilingRectsDiv1  
{  
    public:  
#define x first
#define y second
        int N;
        vector <pair <long long, long long> > R;
        long long gao() {
            sort(R.begin(), R.end());
        
            multiset <long long> l, r;
            for (int i = 0; i < N; i++) {
                l.insert(R[i].y);
                r.insert(R[i + N].y);
            }

            long long ret = R[0].x * (*l.begin()) + R[N].x * (*r.begin());
            for (int i = N - 1; i >= 1; i--) {
                l.erase(l.find(R[i].y));
                l.insert(*r.begin());
                r.erase(r.begin());
                r.insert(R[i].y);
                ret = max(ret, R[0].x * (*l.begin()) + R[i].x * (*r.begin()));
            }
            return ret;
        }

        long long getmax(int N, vector <int> XS, vector <int> YS, int XA, int XB, int XC, int YA, int YB, int YC) {   
            this->N = N;
            R.resize(2 * N);
            for (int i = 0; i < XS.size(); i++) {
                R[i] = make_pair(XS[i], YS[i]);
            }
            for (int i = XS.size(); i < 2 * N; i++) {
                R[i] = make_pair((R[i - 1].x * XA + XB) % XC + 1, 
                            (R[i - 1].y * YA + YB) % YC + 1);
            }
            for (int i = 0; i < 2 * N; i++) {
                if (R[i].x > R[i].y) {
                    swap(R[i].x, R[i].y);
                }
            }
            long long ret = gao();
            for (int i = 0; i < 2 * N; i++) {
                swap(R[i].x, R[i].y);
            }
            ret = max(ret, gao());
            return ret;
        }  
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,5,3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 0; int Arg5 = 1; int Arg6 = 0; int Arg7 = 0; int Arg8 = 1; long long Arg9 = 14LL; verify_case(0, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {7,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; int Arg4 = 0; int Arg5 = 10; int Arg6 = 2; int Arg7 = 7; int Arg8 = 9; long long Arg9 = 56LL; verify_case(1, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {5,6,9,10,4,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9,5,8,6,8,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 0; int Arg5 = 1; int Arg6 = 0; int Arg7 = 0; int Arg8 = 1; long long Arg9 = 69LL; verify_case(2, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 10000; int Arr1[] = {1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000000000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 93827162; int Arg4 = 91238127; int Arg5 = 98231267; int Arg6 = 92138287; int Arg7 = 98563732; int Arg8 = 99381279; long long Arg9 = 1240119561532788LL; verify_case(3, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {375,571,973,896,460,930,583,530,657,590}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {284,37,994,699,941,745,166,884,270,708}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 428; int Arg4 = 1000; int Arg5 = 788; int Arg6 = 851; int Arg7 = 125; int Arg8 = 894; long long Arg9 = 420515LL; verify_case(4, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_5() { int Arg0 = 34734; int Arr1[] = {898,579,465,665,875,391,583,901,326,133,656,562,701,707,492,617,455,441,382,952,689,656,334,877,120,318,497,25,569,962,845,562,632,898,882,498,595,889,382,507,791,548,810,606,105,869,569,970,322,974}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {83,18,492,27,339,622,851,915,464,347,287,210,282,166,976,167,968,769,14,383,454,983,319,165,185,315,795,851,124,287,846,745,19,639,894,828,540,420,147,452,501,670,466,554,166,1,446,808,508,172}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 569; int Arg4 = 185; int Arg5 = 285; int Arg6 = 741; int Arg7 = 304; int Arg8 = 296; long long Arg9 = 10050LL; verify_case(5, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE
  
};  

// BEGIN CUT HERE  
int main()  
{  
    PilingRectsDiv1 ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE 
