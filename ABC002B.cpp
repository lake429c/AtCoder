#include<iostream>
using namespace std;
int main()
{
    // 整数の入力
    string s;
    cin >> s;
    // 文字列の入力
    int cnt=0;
    for(int i=0;i<s.length();i++){
      cout << s.size() << i << endl;
      if(s[i]=='a' || s[i]=='i' || s[i]=='u' || s[i]=='e' || s[i]=='o'){
        s.erase(s.begin() + i);
        i -= 1;
      }
    }
    //
    cout << s << endl;
    return 0;
}
