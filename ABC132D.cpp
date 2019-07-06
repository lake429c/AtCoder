#include<bits/stdc++.h>
using namespace std;
using lint = long long int;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

#define MOD 1000000007

lint ncr(int n, int r){
  //rを大きいほうにしておく
  if(r<n/2.0) r = n-r;
  //(n-r)!の因数の配列
  vector<int> div(n-r+1,1);
  FOR(i, 1, n-r+1) div[i]=i;
  lint result=1;
  //n(n-1)...(r+1)/(n-r)!
  IFOR(i, r+1, n+1){
    int tmp=i;
    IREP(j,n-r+1){
      //(n-r)!のなかで割り切るものがあれば随時割っていく
      if(div[j]!=1 && tmp%div[j]==0){
        tmp/=div[j];
        div[j]=1;
      }
    }
    //なるべく小さいもの同士の掛け算にできる
    result*=tmp;
  }
  return result;
}

int main()
{
  int n,k;
  cin >> n >> k;
  lint result;
  REP(i,k){
    result = ncr(n-k+1,i+1)*ncr(k-1,i);
    result = result%MOD;
    cout << result << endl;
  }
  return 0;
}
