// TL
# include<bits/stdc++.h>
# define sz(s) int(s.size())
using namespace std;
int mood = 500000;
//, 20173, 18859, 10369, 28591, 12113, 14401, 28573, 13033, 23417, 29173, 15307, 26459, 13367, 929, 23663
int prost[10] = {500009, 31, 24859, 4889, 13553, 967, 26777, 31357, 3881, 18913};
bitset< 505000 > blum_arr[2];
int get_hash(string s, int prost){
    if(sz(s) == 0) return 0;
    long long hash = 0ll;
    for(int i = 0, len = sz(s); i < len; i++) {
        hash = ((prost * 1ll * hash)%mood + abs(int(s[i]))) % mood;
    }
    return hash;
}
int check_blum(string s){
    int sum = 0;
    for(int blum = 0; blum <= 1; blum++){
        for(int j = 5 * blum, k = j + 5; j < k; j++){
            sum += blum_arr[blum][get_hash(s, prost[j])];
        }
    }
    return sum;
}
void add_blum(string s){
    for(int blum = 0; blum <= 1; blum++){
        for(int j = 5 * blum, k = j + 5; j < k; j++){
            blum_arr[blum][get_hash(s, prost[j])] = 1;
        }
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
    int n, ans = 0;
    for(int i = 1; i <= 10; i++){
        int a = (rand()^rand()) % 10;
        int b = (rand()^rand()) % 10;
        swap(prost[a], prost[b]);
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        if(check_blum(s) != 10){
            ans++;
            add_blum(s);
        }
    }
    cout << ans;
    return 0;
}
