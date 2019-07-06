#include<iostream>
using namespace std;
int main()
{
    // 整数の入力
    int a,b;
    cin >> a;
    if (a < 100) {
      b = 0;
    }else if (a >= 100 && a <= 5000) {
      b = a/100;
    }else if(a >= 6000 && a <= 30000) {
      b = a/1000 + 50;
    }else if(a >= 35000 && a <= 70000) {
      b = (a/1000 -30)/5 + 80;
    }else if (a > 70000) {
      b = 89;
    }
    // 出力
    if (b < 10) {
      cout << "0" << to_string(b) <<endl;
    }else{
      cout << to_string(b) << endl;
    }
    return 0;
}
