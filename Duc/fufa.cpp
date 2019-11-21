#include <bits/stdc++.h>
#define sz(s) int(s.size())
using namespace std;
int arr[20010];
int tmin[4 * 20010], lazy[4 * 20010];
int tmax[4 * 20010];
void build_tree(int v, int tl, int tr){
    if(tl == tr){
        tmin[v] = tmax[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        int v1 = (v << 1);
        int v2 = v1 + 1;
        build_tree(v1, tl, tm);
        build_tree(v2, tm + 1, tr);
        tmin[v] = min(tmin[v1], tmin[v2]);
        tmax[v] = max(tmax[v1], tmax[v2]);
    }    
}
void push_t(int v, int tl, int tr){
    if(lazy[v] != 0){
        tmin[v] = tmax[v] = lazy[v];
        if(tl != tr){
            int v1 = (v << 1);
            int v2 = v1 + 1;
            lazy[v1] = lazy[v];
            lazy[v2] = lazy[v];
        }
        lazy[v] = 0;
    }
}
int get_mn(int v, int tl, int tr, int le, int ri){
    push_t(v, tl, tr);
    if((tr < le) || (ri < tl)){
        return 10000000;
    }
    else if((le <= tl) && (tr <= ri)){
        return tmin[v];
    }
    else {
        int tm = (tl + tr) / 2;
        int v1 = (v << 1);
        int v2 = v1 + 1;
        return min(get_mn(v1, tl, tm, le, ri), get_mn(v2, tm + 1, tr, le, ri));
    }
}
int get_mx(int v, int tl, int tr, int le, int ri){
    push_t(v, tl, tr);
    if((tr < le) || (ri < tl)){
        return -10000000;
    }
    else if((le <= tl) && (tr <= ri)){
        return tmax[v];
    }
    else {
        int tm = (tl + tr) / 2;
        int v1 = (v << 1);
        int v2 = v1 + 1;
        return max(get_mx(v1, tl, tm, le, ri), get_mx(v2, tm + 1, tr, le, ri));
    }
}
void update_t(int v, int tl, int tr, int le, int ri, int x){
    push_t(v, tl, tr);
    if((tr < le) || (ri < tl)){
        return ;
    }
    else if((le <= tl) && (tr <= ri)){
        lazy[v] = x;
        push_t(v, tl, tr);
    }
    else {
        int tm = (tl + tr) / 2;
        int v1 = (v << 1);
        int v2 = v1 + 1;
        update_t(v1, tl, tm, le, ri, x);
        update_t(v2, tm + 1, tr, le, ri, x);
        tmin[v] = min(tmin[v1], tmin[v2]);
        tmax[v] = max(tmax[v1], tmax[v2]);
    }
}
int main() {
    int q, n, m;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    build_tree(1, 1, n);
    while(q > 0){
        q--;
        int a, b, l, r;
        cin >> a >> b >> l >> r;
        int mx = get_mx(1, 1, n, l, r);
        if((mx == a) && (mx == get_mn(1, 1, n, l, r))){
            update_t(1, 1, n, l, r, b);
            cout << "1" << '\n';
        }
        else {
            cout << "0" << '\n';
        }
    }
    return 0;
}
