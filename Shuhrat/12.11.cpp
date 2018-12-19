# include <bits/stdc++.h>
  using namespace std;
  set< string > st_words, st_predlozeniya;
  map< string, int > mp_kol_words, mp_kol_predlozeniya;
  int main(){
	  string s;
	  getline(cin, s);
	  s += ".";
	  int n = int(s.size());

	  string word = "", predlozenie = "";
	  int flag = 0;
	  for(int i = 0; i < n; i++){
		  if((word.size() > 0) && ((s[i] == ' ') || (s[i] == ',') || (s[i] == '!') || (s[i] == '?') || (s[i] == '.'))){
			  mp_kol_words[word]++;
			  st_words.insert(word);
			  word = "";
		  }
		  if((s[i] != ' ') && (s[i] != ',') && (s[i] != '!') && (s[i] != '?') && (s[i] != '.')){
			  word += s[i];
			  flag = 1;
		  }
		  if((flag == 1) && (s[i] != '!') && (s[i] != '?') && (s[i] != '.')){
            predlozenie += s[i];
		  }
		  if((predlozenie.size() > 0) && ((s[i] == '.') || (s[i] == '!') || (s[i] == '?'))){
			  mp_kol_predlozeniya[predlozenie]++;
			  st_predlozeniya.insert(predlozenie);
			  predlozenie = "";
			  flag = 0;
		  }
	  }

	  cout << " words : " << '\n';
	  for(word : st_words){
		  cout << word << '\n' << " kol = " << mp_kol_words[word] << '\n';
	  }

	  cout << '\n' << " predlozeniya : " << '\n';
	  for(predlozenie : st_predlozeniya){
		  cout << predlozenie << '\n' << " kol = " << mp_kol_predlozeniya[predlozenie] << '\n';
	  }

	  return 0;
  }
