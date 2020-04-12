#include <bits/stdc++.h>
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


int N;
// 隣接リスト
vector<vector<int>> connected_nodes;
// 再帰関数の結果
vector<vector<int>> memo;

int search(int x, unsigned int came){
  int cnt = 0;
  // 頂点xを探索済みに
  came |= (1<<x);
  vector<int> stack;
  // 隣接ノードのうち探索済みでないものをスタックに積む
  for(int i : connected_nodes[x]){
    if(!(came & (1<<i))){
      stack.push_back(i);
    }
  }
  while(stack.size() != 0){
    if(memo[*(stack.end()-1)][came] != -1){
      // 探索済みであれば結果を返す
      cnt += memo[*(stack.end()-1)][came];
    }else{
      // スタックのパスを探索
      cnt += search(*(stack.end()-1), came);
    }
    stack.pop_back();
  }
  // すべての頂点を訪れているのなら1を返す
  int tmp = 0;
  REP(i, N) if(came & (1<<i)) tmp++;
  if(tmp == N) return 1;
  return cnt;

}

int main()
{
  int m;
  cin >> N >> m;
  connected_nodes = vector<vector<int>>(N);
  memo = vector<vector<int>>(N, vector<int>(1<<N, -1));
  REP(i,m){
    int a, b;
    cin >> a >> b;
    connected_nodes[a-1].push_back(b-1);
    connected_nodes[b-1].push_back(a-1);
  }

  unsigned int came = 0;

  cout << search(0, came) << "\n";
  return 0;
}
