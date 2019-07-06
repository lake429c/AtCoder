#include<iostream>
using namespace std;
int main()
{
    // スペース区切りの整数の入力
    int a,b;
    cin >> a >> b;
    //偶奇の判定
    string s;
    if((a*b)%2 == 0){
      s = "Even";
    }else{
      s = "Odd";
    }
    // 出力
    cout << s << endl;
    return 0;
}
