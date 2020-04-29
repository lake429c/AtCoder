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
  int k;
  cin >> k;

  vector<bool> reached(k,false);
  vector<int> dist(k);
  queue<lint> que;
  que.push(1);
  while(que.size() != 0){
    lint i = que.front();
    reached[i] = true;
    if(!reached[(i+1)%k]){
      que.push((i+1)%k);
      dist[(i+1)%k] = dist[i]+1;
    }else if(dist[(i+1)%k] > dist[i]+1) dist[(i+1)%k] = dist[i]+1;
    if(!reached[(i*10)%k]){
      que.push((i*10)%k);
      dist[(i*10)%k] = dist[i]+1;
    }else if(dist[(i*10)%k] > dist[i]+1) dist[(i*10)%k] = dist[i]+1;
    que.pop();
  }

  cout << dist[0] << "\n";
  return 0;
}
