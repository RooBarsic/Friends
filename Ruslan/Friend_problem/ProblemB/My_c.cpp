#include<bits/stdc++.h>
using namespace std;

struct Item{
    double right, pred;
    int id;
} dat[100100];

map< double, int > kol_equal;

int trr[100100];
int sum_0x(int x){
  int s = 0;
  for(; x >= 0; x = (x & (x + 1)) - 1){
      s += trr[x];
  }
  return s;
}
void upd_t(int x, int det){
  for(; x < 100010; x = (x | (x + 1))){
      trr[x] += det;
  }
}
int sum_lr(int l, int r){
  return sum_0x(r) - sum_0x(l - 1);
}

bool cmpPred(Item a, Item b){
    if(a.pred < b.pred) return 1;
    return 0;
}
bool cmpRight(Item a, Item b){
    if(a.right < b.right) return 1;
    return 0;
}

int main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    double answer, auc = 0.0, count = 0.0;
   
    for(int i = 1; i <= n; i++){
        //cin >> right[i] >> pred[i];
        cin >> dat[i].right >> dat[i].pred;
    }
    sort(dat + 1, dat + 1 + n, cmpPred);
    for(int i = 1; i <= n; i++){
        dat[i].id = i;
        upd_t(i, 1);
        kol_equal[dat[i].pred]++;
    }
   
    sort(dat + 1, dat + 1 + n, cmpRight);
    int last = 1;
    for(int i = 1; i <= n; i++){
        kol_equal[dat[i].pred]--;
        upd_t(dat[i].id, 0);
        if(dat[i].right != dat[last].right){
            count += (i - 1 - last + 1) * (n - i + 1);
            for(int j = last; j < i; j++){
                auc += 0.5 * kol_equal[dat[i].pred];
                auc += 1.0 + sum_lr(dat[i].id, n);
            }
        }
    }
   
    answer = auc / count;
    cout << fixed << setprecision(9) << answer;
   
    return 0;
}
