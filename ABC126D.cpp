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

lint n;
vector<vector<plint>> cnct;
vector<int> seen;

void dfs(lint node, int color){
  seen[node] = color;
  for(plint next : cnct[node]){
    // 隣接していて，かつ未探索ノードを探す
    if(next.second != 0 && seen[next.first] == -1){
      // 辺の長さが偶数なら同じ色で塗る
      if(next.second%2 == 0) dfs(next.first, color);
      else dfs(next.first, (color+1)%2);
    }
  }
}

int main()
{
  cin >> n;
  cnct.assign(n, vector<plint>(0));
  REP(i,n-1){
    lint x, y, edge;
    cin >> x >> y >> edge;
    x--;
    y--;
    cnct[x].push_back({y, edge});
    cnct[y].push_back({x, edge});
  }

  seen.assign(n, -1);
  dfs(0, 0);

  REP(i,n) cout << seen[i] << "\n";
  return 0;
}
