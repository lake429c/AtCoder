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
  int a, b, h, m;
  cin >> a >> b >> h >> m;

  // 時刻から極座標を計算
  double pi = M_PI;
  double arcH = -2*pi*h/12 + (-2*pi/12)*m/60 + pi/2, arcM = -2*pi*m/60 + pi/2;
  // 極座標系を直交座標系に変換
  double xH = a*sin(arcH), yH = a*cos(arcH), xM = b*sin(arcM), yM = b*cos(arcM);
  // 距離を計算
  double ans = sqrt(pow(xH-xM,2)+pow(yH-yM,2));

  cout << std::setprecision(10);
  cout << ans << "\n";
  return 0;
}
