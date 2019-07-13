    #include<bits/stdc++.h>
    using namespace std;
    bitset<100010> krr[1000];
    int arr[100010];
    map< int, int > mp_id;
    void build(int k, int n){
        for(int i = 1; i <= n; i++){
            krr[i / k][arr[i]] = 1;
        }
    }
    bitset<100010> getBitsFromKrr(int l, int r){
        bitset<100010> res;
        for(int i = l; i <= r; i++){
            res |= krr[i];
        }
        return res;
    }
    bitset<100010> getBitsFromArr(int l, int r){
        bitset<100010> res;
        for(int i = l; i <= r; i++){
            res[arr[i]] = 1;
        }
        return res;
    }
    int getAns(int k, int n, int l, int r){
        int left = (l / k);
        int right = (r / k);
        if((left == right) || (left + 1 == right)){
            return getBitsFromArr(l, r).count();
        }
        else {
            bitset<100010> ans = getBitsFromKrr(left + 1, right - 1);
            while(l / k != left + 1){
                ans[arr[l]] = 1;
                l++;
            }
            while(r / k != right - 1){
                ans[arr[r]] = 1;
                r--;
            }
            return ans.count();
        }
    }
    int main(){
        srand(time(NULL));
        ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
        int n, q, id;
        cin >> n >> q;
        id = 0;
        for(int i = 1; i <= n; i++){
            cin >> arr[i]; 
            if(mp_id[arr[i]] == 0){
                id++;
                mp_id[arr[i]] = id;
            }
            arr[i] = mp_id[arr[i]];
        }
        
        int k = sqrt(n);
        build(k, n);
        
        for(int i = 1; i <= q; i++){
            int x, y;
            cin >> x >> y;
            cout << getAns(k, n, x, y) << '\n';
        }
        return 0;
    }
