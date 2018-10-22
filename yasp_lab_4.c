# include <stdio.h>
#include <stdlib.h>

  struct snode{
	  int *value;  // value that node saved
	  struct snode *next;
  };
  typedef struct snode list_node;
  
  int get_value(list_node *node){
	  if(node == NULL) return 0;
	  return *(node->value);
  }
  
  list_node* list_create(int x){
	  list_node *list = malloc(sizeof(list_node));
	  list->value = malloc(sizeof(int));
	  *(list->value) = x;
	  list->next = NULL;
	  return list;
  }
  
  list_node* list_add_front(int x, list_node *list){
	  list_node *node1 = list_create(x);
	  node1->next = list;
	  return node1;
  }
  
  void list_add_back(list_node *list, int x){
	  if(list == NULL) list = list_create(x);
	  else list_add_back((list->next), x);
  }
  
  int list_get(int index, list_node *list){
	  while((index > 0) && (list != NULL)){
		  index--;
		  list = (list->next);
	  }
	  return get_value(list);
  }
  
  void list_free(list_node *list){
	  while(list != NULL){
		  list_node *list2 = (list->next);
		  free(&(list->value));
		  free(list->next);
		  free(list);
		  list = list2;
	  }
  }
  
  int list_length(list_node *list){
	  int len = 0;
	  for(; list; list = (list->next)){
		  len++;
	  }
	  return len;
  }
  
  list_node *list_node_at(list_node *list, int index){
	  while((index > 0) && (list != NULL)){
		  index--;
		  list = (list->next);
	  }
	  return list;
  }
	  
  long list_sum(list_node *list){
	  long sum = 0;
	  while(list != NULL){
		  sum += *(list->value);
		  list = (list->next);
	  }
	  return sum;
  }
  
  void outlist(list_node *list){
	  if((list->next) == list) printf(" NULL ssss");
	  printf(" list values : ");
	  int k = 0;
	  while(list != NULL){
		  printf("%d ", *(list->value));
		  if((list->next) == NULL) printf(" NULL ");
		  list = list->next;
		  k++;
		  if( k == 10) break;
	  }
	  printf("\n");
  }
	
  int main(){
	  list_node *list = list_create(5);
	  outlist(list);
  }
