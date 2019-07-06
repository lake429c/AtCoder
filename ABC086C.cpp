#include<iostream>
#include<vector>
using namespace std;
int main()
{
    // 入力
    int n;
    cin >> n;
    vector<vector<int>> data(n+1, vector<int>(3));
    int x,cnt=3;
    data[0][0] = 0;
    data[0][1] = 0;
    data[0][2] = 0;
    while(cin >> x){
      data[cnt/3][cnt%3] = x;
      cnt++;
      if(cnt/3 == n+1) break;
    }
    //
    int flag=1,a,b;
    for(int i=0;i<n;i++){
      a = data[i][1]+data[i][2];
      b = data[i+1][1]+data[i+1][2];
      if(!(data[i][0]%2 == a%2)) flag=0;
      if(!(data[i+1][0]-data[i][0] >= abs(b-a))) flag=0;
      if(flag == 0) break;
    }
    // 出力
    if(flag == 1){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
    return 0;
}
