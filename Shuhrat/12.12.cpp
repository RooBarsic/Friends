# include <bits/stdc++.h>
  using namespace std;
  int main(){
	  string s;
	  getline(cin, s);
	  int n = int(s.size());
	  int mx_word_l, mx_word_r, mx_word_size, mx_fraza_l, mx_fraza_r, mx_fraza_size;
	  int word_l, fraza_l;
	  word_l = -1;
	  mx_word_l = mx_word_r = mx_word_size = 0;

	  s += ".";
	  for(int i = 0; i < n; i++){
		  if((word_l != -1) && ((s[i] == ' ') || (s[i] == ',') || (s[i] == '!') || (s[i] == '?') || (s[i] == '.'))){
			  if(mx_word_size < (i - 1) - word_l + 1){
				  mx_word_l = word_l;
				  mx_word_r = i - 1;
				  mx_word_size = mx_word_r - mx_word_l + 1;
			  }
			  word_l = -1;
		  }
		  if((word_l == -1) && ((s[i] != ' ') && (s[i] != ',') && (s[i] != '!') && (s[i] != '?') && (s[i] != '.'))){
			  word_l = i;
			  if(fraza_l == -1) fraza_l = i;
		  }
		  if((fraza_l != -1) && ((s[i] == '.') || (s[i] == '!') || (s[i] == '?'))){
			  if(mx_fraza_size < (i - 1) - fraza_l + 1){
				  mx_fraza_l = fraza_l;
				  mx_fraza_r = i - 1;
				  mx_fraza_size = mx_fraza_r - mx_fraza_l + 1;
			  }
			  fraza_l = -1;
		  }
	  }

	  cout << "max_word = ";
	  string mx_word = "";
	  for(int i = mx_word_l; i <= mx_word_r; i++){
		  mx_word += s[i];
	  }
	  cout << mx_word << '\n';

	  cout << "max_fraza = ";
	  string mx_fraza = "";
	  for(int i = mx_fraza_l; i <= mx_fraza_r; i++){
		  mx_fraza += s[i];
	  }
	  cout << mx_fraza;

	  return 0;
  }
