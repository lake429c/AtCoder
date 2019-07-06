#include<iostream>
using namespace std;
int main()
{
    //入力
    string s;
    cin >> s;
    //'1'をカウント
    int cnt;
    for(int i=0;i<3;i++){
      if(s[i] == '1'){
        cnt++;
      }
    }
    // 出力
    cout << cnt << endl;
    return 0;
}
