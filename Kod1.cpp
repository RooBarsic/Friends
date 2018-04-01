https://drive.google.com/file/d/1sJIAf20X8T4hMZVXVWDsQGGGVcJTSoVN/view
# include <algorithm>
# include <math.h>
  using namespace std;
  struct uchenik{
      string name, srname;
      int m, f, i, id;
      uchenik(){
          name = "";
          srname = "";
          m = 0;
          f = 0;
          i = 0;
          id = 0;
      }
      long long sr3()
      {
          return m + f + i;
      }
  };
  bool cmp(uchenik a, uchenik b)
  {
      if(a.sr3() > b.sr3()) return 1;
      if((a.sr3() == b.sr3()) && (a.id < b.id)) return 1;
      return 0;
  }
  int main()
  {
      long long n, i;
      uchenik arr[100010];
      cin >> n;
      for(i = 1; i <= n; i++){
        cin >> arr[i].srname >> arr[i].name >> arr[i].m >> arr[i].f >> arr[i].i;
        arr[i].id = i;
      }
      sort(arr + 1, arr + 1 + n, cmp);
      for(i = 1; i <= n; i++){
        cout << arr[i].srname << " " << arr[i].name << "\n "[i == n];
      }
      return 0;
  }
