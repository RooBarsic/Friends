// Optimized for using 3 blum
// Memory Limit
# include<bits/stdc++.h>
# define sz(s) int(s.size())
using namespace std;
int mood = 500000;
//, 14401, 28573, 13033, 23417, 29173, 15307, 26459, 13367, 929, 23663
int prost[15] = {500009, 31, 24859, 4889, 13553, 967, 26777, 31357, 3881, 18913, 20173, 18859, 10369, 28591, 12113};
bitset< 505000 > blum_arr[3];
inline int get_hash(string s, int prost){
    if(sz(s) == 0) return 0;
    long long hash = 0ll;
    for(int i = 0, len = sz(s); i < len; i++) {
        hash = ((prost * 1ll * hash)%mood + abs(int(s[i]))) % mood;
    }
    return hash;
}
int check_blum(string s){
    int sum = 0;
    sum += blum_arr[0][get_hash(s, prost[0])];
    sum += blum_arr[0][get_hash(s, prost[1])];
    sum += blum_arr[0][get_hash(s, prost[2])];
    sum += blum_arr[0][get_hash(s, prost[3])];
    sum += blum_arr[0][get_hash(s, prost[4])];
    sum += blum_arr[1][get_hash(s, prost[5])];
    sum += blum_arr[1][get_hash(s, prost[6])];
    sum += blum_arr[1][get_hash(s, prost[7])];
    sum += blum_arr[1][get_hash(s, prost[8])];
    sum += blum_arr[1][get_hash(s, prost[9])];
    sum += blum_arr[2][get_hash(s, prost[10])];
    sum += blum_arr[2][get_hash(s, prost[11])];
    sum += blum_arr[2][get_hash(s, prost[12])];
    sum += blum_arr[2][get_hash(s, prost[13])];
    sum += blum_arr[2][get_hash(s, prost[14])];
    return sum;
}
void add_blum(string s){
    blum_arr[0][get_hash(s, prost[0])] = 1;
    blum_arr[0][get_hash(s, prost[1])] = 1;
    blum_arr[0][get_hash(s, prost[2])] = 1;
    blum_arr[0][get_hash(s, prost[3])] = 1;
    blum_arr[0][get_hash(s, prost[4])] = 1;
    blum_arr[1][get_hash(s, prost[5])] = 1;
    blum_arr[1][get_hash(s, prost[6])] = 1;
    blum_arr[1][get_hash(s, prost[7])] = 1;
    blum_arr[1][get_hash(s, prost[8])] = 1;
    blum_arr[1][get_hash(s, prost[9])] = 1;
    blum_arr[2][get_hash(s, prost[10])] = 1;
    blum_arr[2][get_hash(s, prost[11])] = 1;
    blum_arr[2][get_hash(s, prost[12])] = 1;
    blum_arr[2][get_hash(s, prost[13])] = 1;
    blum_arr[2][get_hash(s, prost[14])] = 1;
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
        sum += blum_arr[0][get_hash(s, prost[0])];
        sum += blum_arr[0][get_hash(s, prost[1])];
        sum += blum_arr[0][get_hash(s, prost[2])];
        sum += blum_arr[0][get_hash(s, prost[3])];
        sum += blum_arr[0][get_hash(s, prost[4])];
        sum += blum_arr[1][get_hash(s, prost[5])];
        sum += blum_arr[1][get_hash(s, prost[6])];
        sum += blum_arr[1][get_hash(s, prost[7])];
        sum += blum_arr[1][get_hash(s, prost[8])];
        sum += blum_arr[1][get_hash(s, prost[9])];
        sum += blum_arr[2][get_hash(s, prost[10])];
        sum += blum_arr[2][get_hash(s, prost[11])];
        sum += blum_arr[2][get_hash(s, prost[12])];
        sum += blum_arr[2][get_hash(s, prost[13])];
        sum += blum_arr[2][get_hash(s, prost[14])];
        if(sum != 15){
            ans++;blum_arr[0][get_hash(s, prost[0])] = 1;
            blum_arr[0][get_hash(s, prost[1])] = 1;
            blum_arr[0][get_hash(s, prost[2])] = 1;
            blum_arr[0][get_hash(s, prost[3])] = 1;
            blum_arr[0][get_hash(s, prost[4])] = 1;
            blum_arr[1][get_hash(s, prost[5])] = 1;
            blum_arr[1][get_hash(s, prost[6])] = 1;
            blum_arr[1][get_hash(s, prost[7])] = 1;
            blum_arr[1][get_hash(s, prost[8])] = 1;
            blum_arr[1][get_hash(s, prost[9])] = 1;
            blum_arr[2][get_hash(s, prost[10])] = 1;
            blum_arr[2][get_hash(s, prost[11])] = 1;
            blum_arr[2][get_hash(s, prost[12])] = 1;
            blum_arr[2][get_hash(s, prost[13])] = 1;
            blum_arr[2][get_hash(s, prost[14])] = 1;
        }
    }
    cout << ans;
    return 0;
}
