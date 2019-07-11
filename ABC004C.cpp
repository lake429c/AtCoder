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

int main(){
  lint n;
  cin >> n;
  int cards[6]={};
  lint tmp;
  REP(i,6){
    if(i == 0) tmp = n%30;
    else tmp = (30-(5*i)+n)%30;
    if(tmp == 0 || (tmp >= 26 && tmp <= 29)) cards[0] = i+1;
    else if(tmp == 1 || (tmp >= 22 && tmp <= 25)) cards[1] = i+1;
    else if(tmp == 2 || (tmp >= 18 && tmp <= 21)) cards[2] = i+1;
    else if(tmp == 3 || (tmp >= 14 && tmp <= 17)) cards[3] = i+1;
    else if(tmp == 4 || (tmp >= 10 && tmp <= 13)) cards[4] = i+1;
    else if(tmp >= 5 && tmp <= 9) cards[5] = i+1;
  }
  REP(i,6) cout << cards[i];
  cout << endl;
  return 0;
}
