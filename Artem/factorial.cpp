#include<iostream>
using namespace std;
int main(){
   long long k, fact, i;
   cin >> k;
   fact = 1;
   for(i = 1; i <= k; i++){
        fact = (fact * i);
        while(fact % 10 == 0){
            fact = fact / 10;
        }
        if(fact > 100000000){
            fact = fact % 100000000;
        }
   }
   cout << fact % 10;
   return 0;
}
