#include<iostream>
using namespace std;
int main()
{
    //N枚のカード
    int n;
    cin >> n;
    //スペース区切りで各カードの数
    int l,i=0,a[100];
    while(cin>>l){
      a[i] = l;
      i++;
      if(i == n) break;
    }
    //カードを交互にとる
    int alice=0,bob=0,max,ele,trn=0;
    while(1){
      max=0;
      for(int i=0;i<n;i++){
        if(a[i] > max){
          max = a[i];
          ele = i;
        }
      }
      if(max == 0) break;
      a[ele] = 0;
      if(trn == 0){
        alice += max;
        trn = 1;
      }else{
        bob += max;
        trn = 0;
      }
    }
    // 出力
    cout << alice-bob << endl;
    return 0;
}
