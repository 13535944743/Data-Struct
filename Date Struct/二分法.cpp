#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
double f(double x) 
{
    return 8 * pow(x, 4) + 7 * pow(x, 3) + 2 * pow(x, 2) + 3 * x + 6;
}
double find(double y, double left, double right)
{
    double mid = (left + right) / 2;
    while( fabs(y - f(mid)) >= 0.0001) {
        
        if (f(mid) == y) {
            return mid;
        }
        else if (f(mid) > y) right = mid - 1;
        else left = mid + 1;
        mid = (left + right) / 2;
    }
    return mid;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        double y;
        cin >> y;
        if (f(0) < y && f(100) > y) {
            printf("%.4f\n", find(y, 0, 100));
        }
        else cout << "No solution!" << endl;
    }
    return 0;
}