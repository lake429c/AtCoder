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
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> cnct(n);
  REP(i,m){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    cnct[a].push_back(b);
    cnct[b].push_back(a);
  }
  vector<int> color(n);
  REP(i,n) cin >> color[i];
  vector<vector<int>> query(q);
  REP(i,q){
    int a, b, c;
    cin >> a >> b;
    b--;
    query[i].push_back(a);
    query[i].push_back(b);
    if(a == 2){
      cin >> c;
      query[i].push_back(c);
    }
  }

  REP(i,q){
    cout << color[query[i][1]] << "\n";
    if(query[i][0] == 1){
      for(int x : cnct[query[i][1]]){
        color[x] = color[query[i][1]];
      }
    }else{
      color[query[i][1]] = query[i][2];
    }
  }
  return 0;
}
