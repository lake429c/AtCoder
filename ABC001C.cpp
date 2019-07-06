#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    // 整数の入力
    int deg,dis;
    cin >> deg >> dis;
    // 風向き計算
    // dgとnewsでpythonの辞書型のようなものを表現している
    float dg[16];
    dg[0] = 11.25;
    for(int i=1;i<16;i++){
      dg[i] = dg[i-1]+22.5;
    }
    string news[16] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE",
                      "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
    string dir;
    for(int i=0;i<16;i++){
      if(deg < dg[i]*10){
        dir = news[i];
        break;
      }else{
        dir = news[0];
      }
    }
    // 風力計算
    float wind[12] = {0.2, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8,
                      17.1, 20.7, 24.4, 28.4, 32.6};
    int w;
    for(int i=0;i<12;i++){
      if(round((dis/60.0)*10) <= wind[i]*10){
        w = i;
        break;
      }else{
        w = 12;
      }
    }
    // 風力0なら風向きなし
    if(w == 0){
      dir = "C";
    }
    // 出力
    cout << dir << " " << w << endl;
    return 0;
}
