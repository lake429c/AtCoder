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

int main()
{
  int n, m;
  cin >> n >> m;
  std::vector<int> u(m);
  std::vector<int> v(m);
  REP(i,m){
    cin >> u[i] >> v[i];
  }

  std::vector<std::vector<int>> trees;
  int penalty = 0;
  REP(i,m){
    bool tmp = true;
    for(int j = 0;j<trees.size();j++){
      // 辺を構成する両点が既に含まれる集合が存在する
      if(find(trees[j].begin(),trees[j].end(),u[i]) != trees[j].end() && find(trees[j].begin(),trees[j].end(),v[i]) != trees[j].end()){
        penalty++;
        tmp = false;
        break;
      }
      // 木を伸ばす
      else if(find(trees[j].begin(),trees[j].end(),u[i]) != trees[j].end()){
        trees[j].push_back(v[i]);
        tmp = false;
        break;
      }else if(find(trees[j].begin(),trees[j].end(),v[i]) != trees[j].end()){
        trees[j].push_back(u[i]);
        tmp = false;
        break;
      }
    }
    // 両点を含む集合が存在しない
    if(tmp){
      trees.push_back(std::vector<int>{u[i],v[i]});
    }
  }

  // 孤立した点の数 = n - sum(辺を持つ点の数)
  int sum = 0;
  REP(i,trees.size()) sum += trees[i].size();

  cout << trees.size() - penalty + n - sum << "\n";
  return 0;
}
