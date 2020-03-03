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

// 連結木リストを作成する
void cnct_tree(std::vector<std::vector<lint>> _fs, std::vector<bool>& _rc, std::vector<std::vector<lint>>& _cl, int _ind, int _mn){
  if(_cl.size() == _ind) _cl.push_back(std::vector<lint>(1,_mn));
  if(_rc[_mn]){
    _rc[_mn] = false;  // 探索済みに
    REP(i,_fs[_mn].size()){
      if(_rc[_fs[_mn][i]]){
        _cl[_ind].push_back(_fs[_mn][i]);
        cnct_tree(_fs,_rc,_cl,_ind,_fs[_mn][i]);
      }
    }
  }
  return;
}

int main()
{
  lint n, m, k;
  cin >> n >> m >> k;
  std::vector<lint> a(m);
  std::vector<lint> b(m);
  REP(i,m) cin >> a[i] >> b[i];
  std::vector<lint> c(k);
  std::vector<lint> d(k);
  REP(i,k) cin >> c[i] >> d[i];

  // 隣接リストを作る
  std::vector<std::vector<lint>> friends(n);
  REP(i,m){
    friends[a[i]-1].push_back(b[i]-1);
    friends[b[i]-1].push_back(a[i]-1);
  }
  // ブロックリストを作る
  std::vector<std::vector<lint>> blocks(n);
  REP(i,k){
    blocks[c[i]-1].push_back(d[i]-1);
    blocks[d[i]-1].push_back(c[i]-1);
  }

  // 連結成分リストを作成する
  std::vector<bool> reach(n,true);
  std::vector<std::vector<lint>> connected_tree;
  REP(i,n){
    if(reach[i]){
      cnct_tree(friends,reach,connected_tree,connected_tree.size(),i);
    }
  }

  // 結果の計算
  REP(i,n){
    int res = 0;
    REP(j,connected_tree.size()){
      auto index = find(connected_tree[j].begin(),connected_tree[j].end(),i);
      if(index != connected_tree[j].end()){
        // 連結木内にないブロック関係は消す
        for(int l=0;l<blocks[i].size();l++){
          if(find(connected_tree[j].begin(),connected_tree[j].end(),blocks[i][l]) == connected_tree[j].end()){
            blocks[i].erase(blocks[i].begin()+l);
          }
        }
        // 主な計算方法
        res = connected_tree[j].size() - friends[i].size() - blocks[i].size() - 1;
        break;
      }
    }
    cout << res << " ";
  }
  cout << "\n";

  return 0;
}
