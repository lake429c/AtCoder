#include<iostream>
using namespace std;
int main()
{
    //スペース区切りでN枚，sum円
    int n,sum;
    cin >> n >> sum;
    // 計算
    int x=0,y=0,z=0;
    bool flg=false;
    x = sum/10000;
    sum -= x*10000;
    y = sum/5000;
    sum -= y*5000;
    z = sum/1000;
    sum -= z*1000;
    if(x+y+z > n) flg = true;
    // +1 +5 +9  +4
    while(x+y+z < n){
      if(n-x-y-z <= 1 && x > 0){
        x--;
        y += 2;
      }else if(n-x-y-z <= 4 && y > 0){
        y--;
        z += 5;
      }else if(n-x-y-z <= 5 && x > 0){
        x--;
        y++;
        z += 5;
      }else if(n-x-y-z <= 9 && x > 0){
        x--;
        y += 10;
      }else{

      }
      if(x+y+z > n) flg = true;
    }
    if(flg || sum != 0){
      x = -1;
      y = -1;
      z = -1;
    }
    // 出力
    cout << x << ' ' << y << ' '<< z << endl;
    return 0;
}
