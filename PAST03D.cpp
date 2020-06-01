#include<bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
using pqueg = priority_queue<int, vector<int>, greater<int>>;
using pquel = priority_queue<int, vector<int>, less<int>>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
int lcm(int a, int b){
  return a / __gcd(a, b) * b;
}
int r_int(int a, int b){
  return rand() % b + a;
}
const lint mod=1e9+7;

int main()
{
  int n;
  cin >> n;
  vector<string> s(5);
  REP(i,5) cin >> s[i];

  FOR(i,1,n+1){
    int num, base = 4*i-1;
    // #の数を数える
    int cnt = 0;
    REP(x,5){
      REP(y,3){
        if(s[x][base-y] == '#') cnt++;
      }
    }
    switch (cnt) {
      case 8:
        num = 1;
        break;
      case 9:
        num = 4;
        break;
      case 7:
        num = 7;
        break;
      case 13:
        num = 8;
        break;
      case 12:
        if(s[2][base-1] == '.') num = 0;
        if(s[1][base] == '.') num = 6;
        if(s[3][base-2] == '.') num = 9;
        break;
      case 11:
        if(s[1][base] == '.') num = 5;
        else if(s[3][base-2] == '.') num = 3;
        else num = 2;
        break;
    }
    cout << num;
  }
  cout << "\n";
  return 0;
}
