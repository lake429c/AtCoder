#include<iostream>
using namespace std;
int main()
{
    // 入力
    int a,b,c,x;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> x;
    //ちょうどX円になる組み合わせをカウント
    int cnt=0,sum;
    for(int i=0;i<=a;i++){
      sum = i*500;
      if(sum <= x){
        for(int j=0;j<=b;j++){
          sum = i*500+j*100;
          if(sum <= x){
            for(int k=0;k<=c;k++){
              sum = i*500+j*100+k*50;
              if(sum == x){
                cnt++;
              }else if(sum > x){
                break;
              }
            }
          }else{
            break;
          }
        }
      }else{
        break;
      }
    }
    // 出力
    cout << cnt << endl;
    return 0;
}
