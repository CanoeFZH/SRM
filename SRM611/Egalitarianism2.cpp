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

const double INF = 1e30;
const int N = 22;

double w[N][N];
int father[N];

class Egalitarianism2
{
    public:
        int n;
        int getSet(int u) {
            return father[u] == u ? u : father[u] = getSet(father[u]);
        }
        double eculid(double x0, double y0, double x1, double y1) {
            double dx = x0 - x1;
            double dy = y0 - y1;
            return sqrt(dx * dx + dy * dy);
        }
        double KruskalMST(double m) {
            vector <pair <double, pair <int, int> > > E;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    double value = (w[i][j] - m) * (w[i][j] - m);
                    E.push_back(make_pair(value, make_pair(i, j)));
                }
            }
            for (int i = 0; i < n; i++) {
                father[i] = i;
            }
            sort(E.begin(), E.end());
            double mean = 0;
            vector <double> MSTValue;
            for (auto e: E) {
                int u = e.second.first, v = e.second.second;
                if (getSet(u) != getSet(v)) {
                    MSTValue.push_back(w[u][v]);
                    mean += w[u][v] / (n - 1);
                    father[getSet(u)] = getSet(v);
                    if ((int) MSTValue.size() == n - 1) {
                        break;
                    }
                }
            }
            double ret = 0;
            for (double value: MSTValue) {
                ret += (value - mean) * (value - mean);
            }
            ret = sqrt(ret / (n - 1));
            return ret;
        }
        double minStdev(vector <int> x, vector <int> y) {
            n = x.size();
            
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    w[i][j] = eculid(x[i], y[i], x[j], y[j]);
                }
            }
            double ret = INF;
            for (int i = 0; i < n * n; i++) {
                for (int j = i + 1; j < n * n; j++) {
                    double m = (w[i / n][i % n] + w[j / n][j % n]) / 2;
                    ret = min(ret, KruskalMST(m));
                }
            }
            return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5; verify_case(1, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {12,46,81,56}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,45,2,67}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.102799971320928; verify_case(2, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,3,9,10,15,16}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.9428090415820632; verify_case(3, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {167053, 536770, -590401, 507047, 350178, -274523, -584679, -766795, -664177, 267757, -291856, -765547, 604801, -682922, -404590, 468001, 607925, 503849, -499699, -798637}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-12396, -66098, -56843, 20270, 81510, -23294, 10423, 24007, -24343, -21587, -6318, -7396, -68622, 56304, -85680, -14890, -38373, -25477, -38240, 11736}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 40056.95946451828; verify_case(4, Arg2, minStdev(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-306880, 169480, -558404, -193925, 654444, -300247, -456420, -119436, -620920, -470018, -914272, -691256, -49418, -21054, 603373, -23656, 891691, 258986, -453793, -782940}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-77318, -632629, -344942, -361706, 191982, 349424, 676536, 166124, 291342, -268968, 188262, -537953, -70432, 156803, 166174, 345128, 58614, -671747, 508265, 92324}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 36879.15127634308; verify_case(5, Arg2, minStdev(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main(){
    Egalitarianism2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
