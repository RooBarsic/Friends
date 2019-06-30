#include<bits/stdc++.h>
using namespace std;
 
int main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    double right[n], pred[n];
    double answer, auc = 0.0, count = 0.0;
   
    for(int i = 1; i <= n; i++){
        cin >> right[i] >> pred[i];
    }
   
    for (int i = 1; i <= n; i++){
        for (int j = i; i <= n; j++){
            if(right[i] > right[j]){
                count += 1.0;
                if(pred[i] > pred[j])
                    auc += 1.0;
                if(pred[i] == pred[j])
                    auc += 0.5;
            } else if(right[i] < right[j]) {
                count += 1.0;
                if(pred[i] < pred[j])
                    auc += 1.0;
                if(pred[i] == pred[j])
                    auc += 0.5;
            }
        }
    }
   
    answer = auc / count;
    cout << fixed << setprecision(9) << answer;
   
    return 0;
 }
