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
  lint n, m;
  cin >> n >> m;
  vector<vector<lint>> cnct(n);
  REP(i,m){
    lint a, b;
    cin >> a >> b;
    a--;
    b--;
    cnct[a].push_back(b);
    cnct[b].push_back(a);
  }

  // 各部屋の部屋1からの距離と道しるべ
  vector<lint> dist(n, n);
  vector<lint> sign(n, -1);
  dist[0] = 0;
  sign[0] = 0;
  queue<lint> que;
  que.push(0);
  // 幅優先探索で部屋1からの距離を求めてゆく
  while(que.size()){
    lint node = que.front();
    que.pop();
    for(lint x : cnct[node]){
      // 未探索ならキューに追加
      if(dist[x] == n) que.push(x);
      // 距離と道しるべの更新
      if(dist[node]+1 < dist[x]){
        dist[x] = dist[node]+1;
        sign[x] = node;
      }
    }
  }

  // 連結成分がひとつならYes，そうでないならNo
  auto itr = find(ALL(sign), -1);
  if(itr != sign.end()){
    cout << "No\n";
  }else{
    cout << "Yes\n";
    FOR(i,1,sign.size()){
      cout << sign[i]+1 << "\n";
    }
  }

  return 0;
}
