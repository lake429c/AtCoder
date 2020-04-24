#include<bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
const lint mod=1e9+7;

int find_i(string s, char c){
  auto itr = find(s.begin(), s.end(), c);
  size_t index = distance(s.begin(), itr);
  return (int)index;
}

int main()
{
  string s, t;
  cin >> s;
  cin >> t;

  // sの一部をtに変えられるものの中で辞書順最小の物をresにする
  string res = s.substr(0);
  REP(i, s.size()-t.size()+1){
    string tmp = s.substr(0);
    REP(j,t.size()){
      if(s[i+j] != '?' && s[i+j] != t[j]) break;
      tmp[i+j] = t[j];
    }
    if(res.find(t) == -1 || (tmp.find(t) != -1 && tmp < res)){
      res = tmp.substr(0);
    }
  }
  // ?をaに変える
  REP(i, s.size()) if(res[i] == '?') res[i] = 'a';

  if(res.find(t) == -1) cout << "UNRESTORABLE\n";
  else cout << res << "\n";
  return 0;
}
