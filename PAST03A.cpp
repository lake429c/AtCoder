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
  string s, t;
  cin >> s;
  cin >> t;

  string up_s = s, up_t = t;
  std::locale l = std::locale::classic();
  REP(i,3){
    up_s[i] = toupper(up_s[i], l);
    up_t[i] = toupper(up_t[i], l);
  }
  if(s == t) cout << "same\n";
  else if(up_s == up_t) cout << "case-insensitive\n";
  else cout << "different\n";
  return 0;
}
