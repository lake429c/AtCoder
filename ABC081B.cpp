#include<iostream>
using namespace std;
int main()
{
    //N個の整数
    int n;
    cin >> n;
    //スペース区切りで各整数
    int l,i=0,a[200];
    while(cin>>l){
      a[i] = l;
      i++;
      if(i == n) break;
    }
    //2で割っていく
    int cnt=0,flag=0;
    while(1){
      for(int i=0;i<n;i++){
        if(a[i]%2 == 0){
          a[i] /= 2;
        }else{
          flag = 1;
          break;
        }
      }
      if(flag == 1) break;
      cnt++;
    }
    // 出力
    cout << cnt << endl;
    return 0;
}
