// use one hash
// WA
# include<bits/stdc++.h>
# define sz(s) int(s.size())
using namespace std;
long long mood = 20000ll;
//, 14401, 28573, 13033, 23417, 29173, 15307, 26459, 13367, 929, 23663
//int prost[15] = {1000003, 1000033, 24859, 4889, 13553, 967, 26777, 31357, 3881, 18913, 20173, 18859, 10369, 28591, 12113};
bitset< 20100 > blum[5];
inline int get_hash(string s, int prost){
    if(sz(s) == 0) return 0;
    long long hash = 0ll;
    for(int i = 0, len = sz(s); i < len; i++) {
        hash = ((prost * 1ll * hash)%mood + abs(int(s[i]))) % mood;
    }
    return hash;
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
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        int sum = 0;
        sum += blum[0][get_hash(s, 31)];
        sum += blum[1][get_hash(s + "aba", 1000033)];
        sum += blum[2][get_hash(s + "cafa", 967)];
        sum += blum[3][get_hash(s + "codar", 3881)];
        sum += blum[4][get_hash(s + "moraga", 4889)];
        if(sum != 5){
            ans++;
            blum[0][get_hash(s, 31)] = 1;
            blum[1][get_hash(s + "aba", 1000033)] = 1;
            blum[2][get_hash(s + "cafa", 967)] = 1;
            blum[3][get_hash(s + "codar", 3881)] = 1;
            blum[4][get_hash(s + "moraga", 4889)] = 1;
        }
    }
    cout << ans;
    return 0;
}
