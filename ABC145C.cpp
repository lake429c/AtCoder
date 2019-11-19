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
  int n;
  cin >> n;
  std::vector<std::vector<float>> dist(n,std::vector<float>(2));
  REP(i,n) cin >> dist[i][0] >> dist[i][1];

  std::vector<std::vector<float>> v1(n, std::vector<float>(n,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      v1[i][j] = sqrt(pow(dist[i][0]-dist[j][0],2)+pow(dist[i][1]-dist[j][1],2));
    }
  }
  std::vector<std::vector<float>> v2 = v1;
  for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
      if(i==j) continue;
      v2[i][j] += v2[0][i];
    }
  }
  return 0;
}
