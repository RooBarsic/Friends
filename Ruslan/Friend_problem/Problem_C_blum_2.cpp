# include<bits/stdc++.h>
# define sz(s) int(s.size())
using namespace std;
int mood = 500000;
int prost[25];
bitset< 505000 > blum_arr1, blum_arr2;
int get_hash(string s, int prost){
    if(sz(s) == 0) return 0;
    long long hash = 0ll;
    for(int i = 0, len = sz(s); i < len; i++) {
        hash = ((prost * 1ll * hash)%mood + abs(int(s[i]))) % mood;
    }
    return hash;
}
int check_blum(string s){
    int k = 0;
    for(int i = 1; i <= 11; i++){
        k += blum_arr1[get_hash(s, prost[i])];
    }
    for(int i = 12; i <= 22; i++){
        k += blum_arr2[get_hash(s, prost[i])];
    }
    return k;
}
void add_blum(string s){
    for(int i = 1; i <= 11; i++){
        blum_arr1[get_hash(s, prost[i])] = 1;
    }
    for(int i = 12; i <= 22; i++){
        blum_arr2[get_hash(s, prost[i])] = 1;
    }
}
int check_prost(int n){
    for(int i = 2, k = int(sqrt(n)); i <= k; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}
int main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    prost[1] = 500009;
    prost[2] = 31;
    prost[3] = 487811;
    prost[4] = 305237;
    prost[5] = 158881;
    prost[6] = 419047;
    prost[7] = 113417;
    prost[8] = 208189;
    prost[9] = 309433;
    prost[10] = 78121;
    prost[11] = 44771;
    prost[12] = 377459;
    prost[13] = 227111;
    prost[14] = 33427;
    prost[15] = 53939;
    prost[16] = 479263;
    prost[17] = 150721;
    prost[18] = 445199;
    prost[19] = 229693;
    prost[20] = 103043;
    prost[21] = 231493;
    prost[22] = 225569;
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        if(check_blum(s) != 22){
            ans++;
            add_blum(s);
        }
    }
    cout << ans;
    return 0;
}
