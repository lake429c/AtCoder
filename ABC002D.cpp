#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
    // 整数の入力
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    vector<int> y(m);
    for(int i=0;i<m;i++){
      cin >> x[i] >> y[i];
    }
    //
    vector<vector<int>> rel(n,vector<int>(n));
    for(int i=0;i<m;i++){
      rel[x[i]][y[i]] = 1;
    }
    //
    cout << rel[n-1][n-1] << endl;
    return 0;
}
