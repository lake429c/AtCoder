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
  lint x;
  cin >> x;

  int range = 200;
  map<int, lint> sqrt5;
  for(int i = -1*range;i<=range;i++) sqrt5[i] = pow(i,5);

  for(int i = -1*range;i<range;i++){
    for(int j = i+1;j<=range;j++){
      if(sqrt5[j]-sqrt5[i] == x){
        cout << j << " " << i << "\n";
        return 0;
      }
    }
  }

  return 0;
}
