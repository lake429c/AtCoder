#include<iostream>
using namespace std;
int main()
{
    //スペース区切りでN枚，sum円
    int n,sum;
    cin >> n >> sum;
    // 計算
    int x=0,y=0,z=0,res,flag=0;
    for(z=0;z<=n;z++){
      res = z*1000;
      if(res <= sum){
        for(y=0;y<=n-z;y++){
          res = z*1000+y*5000;
          if(res <= sum){
            for(x=0;x<=n-z-y;x++){
              res = z*1000+y*5000+x*10000;
              if(res == sum && x+y+z == n) {
                flag = 1;
                break;
              }
            }
          }
          if(flag == 1) break;
        }
      }
      if(flag == 1) break;
    }
    if(10000*x+5000*y+1000*z != sum){
      x = -1;
      y = -1;
      z = -1;
    }
    // 出力
    cout << x << ' ' << y << ' '<< z << endl;
    return 0;
}
