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

class DivisorsPower
{
    public:
        long long getAnswer(map <long long, int> & pMap, int divisor) {
            long long number = 1;
            for (auto& p: pMap) {
                if (p.second % divisor != 0) {
                    return -1;
                } else {
                    number *= (p.second / divisor + 1);
                }
            }
            if(number != divisor) {
                return -1;
            }
            long long ret = 1;
            for (auto &p: pMap) {
                int pNumber = p.second / divisor;
                for (int i = 0; i < pNumber; i++) {
                    ret *= p.first;
                }
            }
            return ret;
        }
        long long findArgument(long long n) {
            map <long long, int> pMap;
            int maxP = -1;
            for (long long i = 2; i * i <= n; i++) {
                int cnt = 0;
                while(n % i == 0) {
                    n /= i;
                    cnt++;
                }
                if (cnt != 0) {
                    maxP = max(maxP, cnt);
                    pMap[i] = cnt;
                }
            }
            if (n != 1) {
                maxP = max(maxP, 1);
                pMap[n] = 1;
            }
            for (int i = maxP; i >= 1; i--) {
                long long ret = getAnswer(pMap, i);
                if (ret != -1) {
                    return ret;
                }
            }
            return -1;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 2LL; verify_case(0, Arg1, findArgument(Arg0)); }
	void test_case_1() { long long Arg0 = 10LL; long long Arg1 = -1LL; verify_case(1, Arg1, findArgument(Arg0)); }
	void test_case_2() { long long Arg0 = 64LL; long long Arg1 = 4LL; verify_case(2, Arg1, findArgument(Arg0)); }
	void test_case_3() { long long Arg0 = 10000LL; long long Arg1 = 10LL; verify_case(3, Arg1, findArgument(Arg0)); }
	void test_case_4() { long long Arg0 = 2498388559757689LL; long long Arg1 = 49983883LL; verify_case(4, Arg1, findArgument(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    DivisorsPower ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
