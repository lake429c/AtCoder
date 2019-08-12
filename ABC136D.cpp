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

int main()
{
  string s;
  cin >> s;

  lint n = s.size();
  std::vector<int> rl(n,0);
  REP(i,n) if(s[i]=='L') rl[i] = 1;
  std::vector<lint> child(n);
  REP(i,n) child[i] = i;

  std::vector<lint> result(n,0);
  //子供の移動
  REP(i,n){
    while(1){
      //RLという並びのところにいるかどうか
      if(rl[child[i]] == 0 && rl[child[i]+1] == 1){
        result[child[i]] += 1;
        break;
      }
      if(rl[child[i]] == 1 && rl[child[i]-1] == 0){
        result[child[i]] += 1;
        break;
      }
      // 二回移動
      if(rl[child[i]] == 0) child[i] += 1; //R
      else child[i] -= 1; //L
      if(rl[child[i]] == 0) child[i] += 1; //R
      else child[i] -= 1; //L
    }
  }

  REP(i,n){
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}
