#include<iostream>
#include<algorithm> /* std::equal */
#include<string> /* substr */
using namespace std;
int main()
{
    // 文字列の入力
    string s;
    cin >> s;
    // Sを後ろから削っていく
    string p[4] = {"dream","dreamer","erase","eraser"};
    int flag=0,l;
    while(1){
      l = (int)(s.length());
      if(l == 0){
        flag = 1;
        break;
      }else if(l < 5){
        break;
      }
      if(equal(s.end()-5, s.end(), p[0].begin()) || equal(s.end()-5, s.end(), p[2].begin())){
        s = s.substr(0,l-5);
      }else if(equal(s.end()-7, s.end(), p[1].begin())){
        s = s.substr(0,l-7);
      }else if(equal(s.end()-6, s.end(), p[3].begin())){
        s = s.substr(0,l-6);
      }else{
        break;
      }
    }
    // 出力
    if(flag == 1){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
    return 0;
}
