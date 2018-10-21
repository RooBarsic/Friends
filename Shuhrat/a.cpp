# include <bits/stdc++.h>
  using namespace std;
  typedef unsigned long long llu;
  vector< llu > fibon;
  void calcFibon(){
	  llu f1 = 1ll, f2 = 1ll;
	  long long mx = (1ll << 63ll);
	  while(f2 < mx){
		  fibon.push_back(f2);
		  f1 = f1 + f2;
		  swap(f1, f2);
	  }
  }
  int find_next(llu x){
	  int l = 0;
	  int r = int(fibon.size());
	  while(l + 1 < r){
		  int m = ((l + r) >> 1);
		  if(x <= fibon[m]) r = m;
		  else l = m;
	  }
	  if(fibon[r] <= x) return r;
	  return l;
  }
  int main(){
	  llu n;
	  cin >> n;
	  calcFibon();
	  int mask[int(fibon.size())];
	  fill(mask, mask + int(fibon.size()), 0);
	  while(n > 0){
		  int x = find_next(n);
		  n -= fibon[x];
		  mask[x] = 1;
	  }
	  int flag = 0;
	  for(int i = int(fibon.size()); i >= 0; i--){
		  if(mask[i] == 1) flag = 1;
		  if(flag == 1) cout << mask[i];
	  }
  }
