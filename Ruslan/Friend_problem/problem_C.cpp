# include<bits/stdc++.h>
# define sz(s) int(s.size())
using namespace std;
int mood = 500000;
int get_hash1(string s){
    long long prost = 500009ll;
    if(sz(s) == 0) return 0;
    long long hash = 0ll;
    for(int i = 0, len = sz(s); i < len; i++) {
        hash = ((prost * 1ll * hash)%mood + abs(int(s[i]))) % mood;
    }
    return hash;
}
int arr[505000];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        arr[i] = get_hash1(s);
    }
    sort(arr + 1, arr + 1 + n);
    int ans = 1;
    for(int i = 2; i <= n; i++){
        if(arr[i - 1] != arr[i]) ans++;
    }
    cout << ans;
    return 0;
}
