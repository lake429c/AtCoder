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

bool others(lint a, lint x1, lint y1, lint x2, lint y2, std::vector<std::vector<lint>>& mat){
  if(x1 > x2){
    lint tmp = x1;
    x1 = x2;
    x2 = tmp;
  }
  if(y1 > y2){
    lint tmp = y1;
    y1 = y2;
    y2 = tmp;
  }
  for(lint i=x1;i<=x2;i++){
    for(lint j=y1;j<=y2;j++){
      if(!(mat[i][j] == a || mat[i][j] == -1)) return false;
    }
  }
  return true;
}

int main()
{
  lint h,w,k;
  cin >> h >> w >> k;
  std::vector<string> s(h);
  REP(i,h) cin >> s[i];

  std::vector<std::vector<lint>> strw(k,std::vector<lint>(4,-1));
  lint cnt = 0;
  for(int i = 0;i<h;i++){
    for(int j = 0;j<w;j++){
      if(s[i][j] == '#'){
        strw[cnt][0] = i;
        strw[cnt][1] = j;
        strw[cnt][2] = i;
        strw[cnt][3] = j;
        cnt++;
      }
    }
  }

  std::vector<std::vector<lint>> result(h,std::vector<lint>(w,-1));
  REP(i,k) result[strw[i][0]][strw[i][1]] = i+1;

  REP(i,k){
    while(strw[i][3]+1 < w && others(i+1,strw[i][0],strw[i][1],strw[i][2],strw[i][3]+1,result)){
      strw[i][3]++;
    }
    while(strw[i][1]-1 >= 0 && others(i+1,strw[i][0],strw[i][1]-1,strw[i][2],strw[i][3],result)){
      strw[i][1]--;
    }
    while(strw[i][2]+1 < h && others(i+1,strw[i][0],strw[i][1],strw[i][2]+1,strw[i][3],result)){
      strw[i][2]++;
    }
    while(strw[i][0]-1 >= 0 && others(i+1,strw[i][0]-1,strw[i][1],strw[i][2],strw[i][3],result)){
      strw[i][0]--;
    }

    lint x1=strw[i][0],y1=strw[i][1],x2=strw[i][2],y2=strw[i][3];
    if(x1 > x2){
      lint tmp = x1;
      x1 = x2;
      x2 = tmp;
    }
    if(y1 > y2){
      lint tmp = y1;
      y1 = y2;
      y2 = tmp;
    }
    for(lint j=x1;j<=x2;j++){
      for(lint k=y1;k<=y2;k++){
        result[j][k] = i+1;
      }
    }

  }

  REP(i,h){
    REP(j,w) cout << result[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
