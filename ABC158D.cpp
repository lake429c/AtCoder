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

vector<string> split(const string s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
    if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}

int main()
{
  string s;
  cin >> s;
  lint q;
  cin >> q;
  string line;
  getline(cin,line,'\n');  // なんかこれ入れないとおかしくなる
  std::vector<std::vector<string>> query;
  REP(i,q){
    getline(cin,line,'\n');
    query.push_back(split(line, ' '));
  }

  lint cnt = 0;
  REP(i,q){
    if(query[i][0] == "1"){
      // 反転する回数を数える
      cnt++;
    }else{
      // 反転する回数が偶数回である XOR 先頭に追加する
      if((cnt%2 == 0) == (query[i][1] == "1")){
        s.insert(0, query[i][2]);
      }else{
        s.insert(s.size(), query[i][2]);
      }
    }
  }

  // 奇数回反転なら一回反転すれば十分
  if(cnt%2) reverse(s.begin(), s.end());

  cout << s << "\n";
  return 0;
}
