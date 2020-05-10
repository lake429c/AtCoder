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
  lint n, k;
  cin >> n >> k;
  vector<lint> a(n);
  REP(i,n){
    lint tmp;
    cin >> tmp;
    tmp--;
    a[i] = tmp;
  }

  vector<lint> seen(n, false);
  vector<lint> way;
  lint next = 0;
  while(!seen[next]){
    seen[next] = true;
    way.push_back(next);
    next = a[next];
  }

  auto itr = find(ALL(way), next);
  lint loop_begin = distance(way.begin(), itr);
  lint loop_size = way.size() - loop_begin;
  lint res;
  if(k <= loop_begin) res = way[k];
  else{
    k -= loop_begin;
    k %= loop_size;
    res = way[loop_begin+k];
  }

  //cout << loop_begin << " " << loop_size << "\n";
  cout << res+1 << "\n";
  return 0;
}
