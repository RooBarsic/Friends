# include<bits/stdc++.h>
# define sz(s) int(s.size())
using namespace std;
int mood = 500000;
bool blum_arr[505000];
int get_hash1(string s){
    long long prost = 500009ll;
    if(sz(s) == 0) return 0;
    long long hash = 0ll;
    for(int i = 0, len = sz(s); i < len; i++) {
        hash = ((prost * 1ll * hash)%mood + abs(int(s[i]))) % mood;
    }
    return hash;
}
int get_hash2(string s){
    long long prost = 31ll;
    if(sz(s) == 0) return 0;
    long long hash = 0ll;
    for(int i = 0, len = sz(s); i < len; i++) {
        hash = ((prost * 1ll * hash)%mood + abs(int(s[i]))) % mood;
    }
    return hash;
}
int check_blum(string s){
    int k = 0;
    k += blum_arr[get_hash1(s)];
    k += blum_arr[get_hash2(s)];
    return k;
}
void add_blum(string s){
    blum_arr[get_hash1(s)] = 1;
    blum_arr[get_hash2(s)] = 1;
}
int main(){
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        if(check_blum(s) != 2){
            ans++;
            add_blum(s);
        }
    }
    cout << ans;
    return 0;
}
