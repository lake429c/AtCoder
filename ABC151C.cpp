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
  lint n,m;
  cin >> n >> m;
  std::vector<lint> p(m);
  std::vector<string> s(m);
  REP(i,m){
    cin >> p[i] >> s[i];
  }

  if(m == 0){
    cout << "0 0 \n";
    return 0;
  }
  lint crt_num=0, pnt_num=0;
  std::vector<int> crt_list(n,0),pnt_list(n,0);
  for(int i=0;i<m;i++){
    if(s[i].compare("AC") == 0 && crt_list[p[i]-1] == 0){
      crt_list[p[i]-1] = 1;
      crt_num++;
    }else if(s[i].compare("WA") == 0 && crt_list[p[i]-1] == 0){
      pnt_list[p[i]-1]++;
    }
  }

  REP(i,n){
    if(crt_list[i] == 1){
      pnt_num += pnt_list[i];
    }
  }
  cout << crt_num << " " << pnt_num << "\n";
  return 0;
}
