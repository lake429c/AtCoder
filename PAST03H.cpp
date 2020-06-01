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
  int n, l;
  cin >> n >> l;
  vector<bool> hurdle(l+1, false);
  REP(i,n){
    int tmp;
    cin >> tmp;
    hurdle[tmp] = true;
  }
  vector<int> t(3);
  cin >> t[0] >> t[1] >> t[2];

  // t1<t2<t3を仮定
  int time = 0, sunuke = 0;
  while(sunuke < l){
    //cout << sunuke << "\n";
    if(!hurdle[sunuke+1]){
      sunuke++;
      time += t[0];
    }else if(!hurdle[sunuke+2]){
      sunuke += 2;
      time += t[0]+t[1];
    }else{
      if(sunuke+3 == l){
        sunuke += 3;
        time += t[0]/2+2*t[1]+t[1]/2;
      }else{
        sunuke += 4;
        time += t[0]+3*t[1];
        if(hurdle[sunuke]) time += t[2];
      }
    }
  }

  cout << time << "\n";
  return 0;
}
