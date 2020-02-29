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
  std::vector<float> x(n);
  std::vector<float> y(n);
  REP(i,n) cin >> x[i] >> y[i];

  if(n == 2){
    cout << sqrt(pow((x[0]-x[1]),2) + pow((y[0]-y[1]),2))/2.0 << "\n";
    return 0;
  }
  // 重心で求めるとダメだった
  /*
  float x_ave = accumulate(ALL(x),0.0)/(float)n;
  float y_ave = accumulate(ALL(y),0.0)/(float)n;
  float max = 0;
  REP(i,n){
    float tmp = pow((x[i]-x_ave),2) + pow((y[i]-y_ave),2);
    if(tmp > max){
      max = tmp;
    }
  }
  */
  // 面積最大となる三角形を見つけて，その外心でいいのか？
  int a=0,b=0,c=0;
  // まず距離最大の2点
  float max = 0.0;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      float tmp = pow((x[i]-x[j]),2) + pow((y[i]-y[j]),2);
      if(tmp > max){
        max = tmp;
        a = i;
        b = j;
      }
    }
  }
  // 次にその二点と他の点とを結んだときにできる面積最大の三角形
  max = 0.0;
  float ed_a = sqrt(pow((x[a]-x[b]),2) + pow((x[a]-x[b]),2));
  REP(i,n){
    if(i != a && i != b){
      float ed_b = sqrt(pow((x[a]-x[i]),2) + pow((x[a]-x[i]),2));
      float ed_c = sqrt(pow((x[i]-x[b]),2) + pow((x[i]-x[b]),2));
      // ヘロンの公式
      float s = (ed_a + ed_b + ed_c) / 2.0;
      float tmp = s*(s-ed_a)*(s-ed_b)*(s-ed_c);
      if(tmp > max){
        max = tmp;
        c = i;
      }
    }
  }

  cout << a << " "  << b << " "  << c << " " << "\n";
  // a,b,cの外心を求める
  float g_y = ((x[c]-x[a])*(x[a]*x[a]+y[a]*y[a]-x[b]*x[b]-y[b]*y[b])-(x[b]-x[a])*(x[a]*x[a]+y[a]*y[a]-x[c]*x[c]-y[c]*y[c]))/(2*(x[c]-x[a])*(y[a]-y[b])-2*(x[b]-x[a])*(y[a]-y[c]));
  float g_x;
  if(x[b]-x[a]!=0){
    g_x = (2*(y[a]-y[b])*g_y-(x[a]*x[a]+y[a]*y[a]-x[b]*x[b]-y[b]*y[b]))/(2*(x[b]-x[a]));
  }else{
    g_x = (2*(y[a]-y[c])*g_y-(x[a]*x[a]+y[a]*y[a]-x[c]*x[c]-y[c]*y[c]))/(2*(x[c]-x[a]));
  }
  cout << a << " "  << b << " "  << c << " " << "\n";
  cout << sqrt(pow((x[a]-g_x),2) + pow((y[a]-g_y),2)) << "\n";
  return 0;
}
