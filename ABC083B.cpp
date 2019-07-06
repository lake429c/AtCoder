#include<iostream>
using namespace std;
int main()
{
    //スペース区切りで入力
    int n,a,b;
    cin >> n >> a >> b;
    // 計算
    int sum=0,x,s;
    for(int i=1;i<=n;i++){
      x=i; s=0;
      s += x/1000;
      x = x%1000;
      s += x/100;
      x = x%100;
      s += x/10;
      x = x%10;
      s += x;
      if(s >= a && s <= b) sum += i;
    }
    // 出力
    cout << sum << endl;
    return 0;
}
