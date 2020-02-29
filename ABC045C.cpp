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

// 適当な区切りを入れて足したものを返す
// vector<string>& _sで参照渡ししてたせいで3日躓いてた
lint cut_sum(vector<string> _s, int _at){
  lint sum = 0;
  if(_at < _s.back().size()){
    //_atで区切らない場合
    sum += cut_sum(_s, _at+1);
    //_atで区切る場合
    string tmp = _s.back().substr(_at);
    _s.back().erase(_s.back().begin()+_at, _s.back().end());
    _s.push_back(tmp);
    sum += cut_sum(_s, 1);
  }else{
    for(int i = 0;i < _s.size(); i++){
      // stoi(),stol()では数が大きくなった時に対応できない
      sum += stoll(_s[i]);
    }
  }
  return sum;
}

int main()
{
  std::vector<string> v(1);
  cin >> v[0];

  cout << cut_sum(v, 1) << "\n";
  return 0;
}
