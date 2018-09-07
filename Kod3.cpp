bool cmp(char a, char b){
  char a1, b1;
  if(('A' <= a) && (a <= 'Z')) a1 = char( int(a) - int('A') + int('a') );
  else a1 = a;
  if(('A' <= b) && (b <= 'Z')) b1 = char( int(b) - int('A') + int('a') );
  else b1 = b;
  
