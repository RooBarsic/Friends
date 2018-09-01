# include <bits/stdc++.h>
  using namespace std;
  int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  vector< string > tasks[40];
  int main()
  {
    long long Q, month; 
      cin >> Q;
    month = 1;
    for(int i = 1; i <= Q; i++){
      string comand;
      cin >> comand;
      if(comand == "ADD"){
        string task;
        int day;
        cin >> day >> task;
        tasks[day].push_back(task);
      }
      else if(comand == "NEXT"){
        int newMonth = (month % 12) + 1;
        for(int j = days[month] + 1; j <= days[newMonth]; j++){
          tasks[j].clear();
        }
        for(int j = days[newMonth] + 1; j <= days[month]; j++){
          for(string task : tasks[j]){
            tasks[days[newMonth]].push_back(task);
          }
        }
        month = newMonth;
      }
      else if(comanf == "DUMP") {
        int day;
        cin >> day;
        for(string task : tasks[day]){
          cout << task << " ";
        }
        cout << '\n';
      }
    }
    return 0;
  }
