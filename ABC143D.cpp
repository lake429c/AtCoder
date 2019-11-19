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

int main()
{
  lint n;
  cin >> n;
  std::vector<int> l(n);
  REP(i,n) cin >> l[i];

  sort(ALL(l));
  std::vector<int> l_type(1, l[0]);
  std::vector<int> l_num(1000, 0);
  l_num[l[0]-1]++;
  for(int i=1;i<n;i++){
    if(l[i] != l_type[l_type.size()-1]) l_type.push_back(l[i]);
    l_num[l[i]-1]++;
  }

  unsigned long int cnt = 0;
  for(int i=0;i<l_type.size()-2;i++){
    for(int j=i+1;j<l_type.size()-1;j++){
      for(int k=j+1;k<l_type.size();k++){
        if(l_type[k] >= l_type[i] + l_type[j]) break;
        if(l_type[i] < l_type[j] + l_type[k] && l_type[j] < l_type[k] + l_type[i]){
          cnt += l_num[l_type[i]-1]*l_num[l_type[j]-1]*l_num[l_type[k]-1];
        }
      }
    }
  }

  cout << cnt << "\n";
  return 0;
}
