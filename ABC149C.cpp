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
  lint x;
  cin >> x;


  std::vector<lint> primes(100003,0);
  primes[0] = 2;
  for(int i=1;i<primes.size();i++){
    primes[i] = primes[i-1] + 1;
  }

  lint cnt=0;
  while(1){
    if(primes[cnt]!=0){
      for(int i=cnt+1;i<primes.size();i++){
        if(primes[i]%primes[cnt]==0){
          primes.erase(primes.begin()+i);
        }
      }
    }
    if(primes[cnt]>=x){
      cout << primes[cnt] << "\n";
      break;
    }
    cnt++;
  }

  return 0;
}
