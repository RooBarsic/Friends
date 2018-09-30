#include <bits/stdc++.h>
  using namespace std;
  struct My_dec{
    int begin = 0, end = 0, size = 0, mx_size = 2;
    int *buffer = new int[mx_size];

    int check_index(int index){
      if((0 <= index) && (index < mx_size)) return index;
      if(mx_size <= index) return 0;
      if(index < 0) return mx_size - 1;
    }

    void make_new_buffer(){
      int *save_buffer = buffer;

      buffer = new int[mx_size * 2];
      for(int i = 0; i < size; i++){
        buffer[i] = save_buffer[begin];
        begin = check_index(begin + 1);
      }

      mx_size = mx_size * 2;
      begin = 0;
      end = size - 1;
    }

    void push_front(int x){
      if(size == mx_size) make_new_buffer();
      if(size == 0) buffer[begin] = x;
      else {
        begin = check_index(begin - 1);
        buffer[begin] = x;
      }
      size++;
    }

    void push_back(int x){
      if(size == mx_size) make_new_buffer();
      if(size == 0) buffer[end] = x;
      else {
        end = check_index(end + 1);
        buffer[end] = x;
      }
      size++;
    }

    int pop_front(){
      if(size == 0) return -1;
      else {
        int x = buffer[begin];
        begin = check_index(begin + 1);
        size--;
        return x;
      }
    }

    int pop_back(){
      if(size == 0) return -1;
      else {
        int x = buffer[end];
        end = check_index(end - 1);
        size--;
        return x;
      }
    }
  };

  int main(){
    My_dec dec;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
      int a, b;
      cin >> a >> b;
      if(a == 1) dec.push_front(b);
      else if(a == 3) dec.push_back(b);
      else {
        int x;
        if(a == 2) x = dec.pop_front();
        else if(a == 4) dec.pop_back();
        if(x != b){
          cout << "NO";
          return 0;
        }
      }
    }
    cout << "YES";
    return 0;
  }
