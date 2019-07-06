#include<iostream>
using namespace std;
int main()
{
    //N段重ねの鏡餅
    int n;
    cin >> n;
    //各餅の直径
    int l,i=0,d[100];
    while(cin>>l){
      d[i] = l;
      i++;
      if(i == n) break;
    }
    //大きい順に餅を重ねる
    int cnt=0,max;
    while(1){
      max=0;
      for(int i=0;i<n;i++){
        if(d[i] > max) max = d[i];
      }
      if(max == 0) break;
      cnt++;
      for(int i=0;i<n;i++){
        if(d[i] == max) d[i] = 0;
      }
    }
    // 出力
    cout << cnt << endl;
    return 0;
}
