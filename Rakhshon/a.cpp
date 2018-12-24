# include<bits/stdc++.h>
# define sz(s) int(s.size())
using namespace std;

int arr[100100];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + n);
    deque< int > deq;
    int i = n;
    while(1 <= i){
        int j = i - 1;
        while((1 <= j) && (arr[i] == arr[j])){
            j--;
        }
        j++;
        if(i - j + 1 > 2){
            cout << "-1";
            return ;
        }
        if(i - j + 1 == 2){
            deq.push_front(arr[i]);
            deq.push_back(arr[j]);
        }
        else {
            deq.push_front(arr[i]);
        }
        i = j - 1;
    }
    
    for(int i = 1, k1 = sz(deq); i <= k1; i++){
        cout << deq.front() << " ";
        deq.pop_front();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int k = 1;
    while(k > 0){
        solve();
        cout << '\n';
        k--;
    }
}
