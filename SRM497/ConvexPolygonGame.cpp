#line 5 "ConvexPolygonGame.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

const int BOUND = 200010;

class ConvexPolygonGame {
    public:
        bool collinear(long long x0, long long y0, 
                long long x1, long long y1, 
                long long x2, long long y2) { 
            long long area = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
            if (area == 0LL) {
                return true;
            } else {
                return false;
            }
        }
        double getY(double x0, double y0, 
                double x1, double y1,
                double x) { 
            double p = (y1 - y0) * (x - x0), q = x1 - x0;
            double y = y0 + p / q;
            return y;
        }
        string winner(vector <int> X, vector <int> Y) {
            int minX = *min_element(X.begin(), X.end());
            int maxX = *max_element(X.begin(), X.end());
            int n = X.size();
            vector <int> pX, pY;
            for (int x = minX; x <= maxX; x++) {
                int minY = -BOUND, maxY = BOUND;
                for (int i = 0; i < n; i++) {
                    int x0 = X[i], x1 = X[(i + 1) % n];
                    int y0 = Y[i], y1 = Y[(i + 1) % n];
                    if (x0 < x1) {
                        if (x == x0) {
                            minY = max(minY, y0 + 1);
                        } else if (x == x1) {
                            minY = max(minY, y1 + 1); 
                        } else if (x0 < x && x < x1) {
                            int y = ceil(getY(x0, y0, x1, y1, x));
                            minY = max(minY, y);
                        }
                    } else if (x0 > x1) {
                        if (x == x0) {
                            maxY = min(maxY, y0 - 1);
                        } else if (x == x1) {
                            maxY = min(maxY, y1 - 1);
                        } else if (x1 < x && x < x0) {
                            int y = floor(getY(x0, y0, x1, y1, x));
                            maxY = min(maxY, y);
                        }
                    } else if (x0 == x && x1 == x) {
                        minY = min(y0, y1) + 1;
                        maxY = max(y0, y1) - 1;
                    }
                }
                if (minY <= maxY) {
                    int delta = maxY - minY + 1;
                    if ((int) pX.size() + delta > BOUND) {
                        return "Masha";
                    } else {
                        for (int y = minY; y <= maxY; y++) {
                            pX.push_back(x);
                            pY.push_back(y);
                        }
                    }
                }
            }
            for (int i = 2; i < (int) pX.size(); i++) {
                if (!collinear(pX[0], pY[0], pX[1], pY[1], pX[i], pY[i])) {
                    return "Masha";
                }
            }
            return "Petya";
        }
        // BEGIN CUT HERE
    public:
        void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
    private:
        template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
        void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
        void test_case_0() { int Arr0[] = {0, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Petya"; verify_case(0, Arg2, winner(Arg0, Arg1)); }
        void test_case_1() { int Arr0[] = {0, 4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(1, Arg2, winner(Arg0, Arg1)); }
        void test_case_2() { int Arr0[] = {0, 100, 100, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(2, Arg2, winner(Arg0, Arg1)); }
        void test_case_3() { int Arr0[] = {0, 50, 100, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Petya"; verify_case(3, Arg2, winner(Arg0, Arg1)); }
        void test_case_4() { int Arr0[] = {-100000, 100000, 100000, -100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, -1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(4, Arg2, winner(Arg0, Arg1)); }

        // END CUT HERE

};

// BEGIN CUT HERE
int main()  
{  
    ConvexPolygonGame ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE
