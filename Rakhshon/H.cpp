#include <iostream>

using namespace std;
int n;
int pred[2 * 200100], sum[2 * 200100];
void build_dsu(int n){
    for(int i = 1; i <= n; i++){
        pred[i] = i;
    }
}
int find_pred(int v){
    if(pred[v] == v){
        return v;
    }
    return find_pred(pred[v]);
}
void union_ab(int a, int b){
    a = find_pred(a);
    b = find_pred(b);
    if(a != b){
        n++;
        pred[n] = n;
        pred[a] = n;
        pred[b] = n;
    }
}
int get_experience(int v){
    if(pred[v] == v){
        return sum[v];
    }
    return get_experience(pred[v]) + sum[v];
}
int main() {
    int m;
    cin >> n >> m;
    build_dsu(n);
    for(int i = 1; i <= m; i++){
        string command;
        cin >> command;
        if(command == "add"){
            int x, v;
            cin >> x >> v;
            x = find_pred(x);
            sum[x] += v;
        }
        else if(command == "join"){
            int x, y;
            cin >> x >> y;
            union_ab(x, y);
        }
        else {
            int x;
            cin >> x;
            cout << get_experience(x) << '\n';
        }
    }
    return 0;
}
/*
3 6
add 1 100
join 1 3
add 1 50
get 1
get 2
get 3

 150
0
50

 */
