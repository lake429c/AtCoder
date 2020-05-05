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

int n, m;
vector<vector<int>> cnct;
vector<bool> reached;

// 深さ優先探索でグラフを見ながら閉路があるか確認する
int looped(int node, int parent){
  int cnt = 0;
  reached[node] = true;
  for(int next : cnct[node]){
    if(reached[next]){
      // 親ノードでないのに到達済み=>閉路である
      if(next != parent) cnt++;
      continue;
    }
    cnt += looped(next, node);
  }
  return cnt;
}


int main()
{
  cin >> n >> m;
  // 隣接リスト
  cnct.assign(n,vector<int>(0));
  REP(i,m){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    cnct[a].push_back(b);
    cnct[b].push_back(a);
  }
  /*
  // 隣接リストの表示
  REP(i,n){
    cout << i+1 << " : ";
    REP(j,cnct[i].size()){
      cout << cnct[i][j]+1 << " ";
    }
    cout << "\n";
  }
  */

  // その頂点を訪れたかどうか
  reached.assign(n, false);
  int cnt = 0;
  REP(i,n){
    if(reached[i]) continue;
    // 閉路がないならカウント
    if(looped(i, -1) == 0) cnt++;
  }

  cout << cnt << "\n";
  return 0;
}
