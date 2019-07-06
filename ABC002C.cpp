#include<bits/stdc++.h>
using namespace std;
int main()
{
    // 整数の入力
    int x[3], y[3];
    cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
    //
    double result;
    result = abs((x[1]-x[0])*(y[2]-y[0])-(y[1]-y[0])*(x[2]-x[0]))/2.0;
    //
    cout << fixed;
    cout << setprecision(1) << result << endl;
    return 0;
}
