# include <stdio.h>
#include <stdlib.h>

  struct snode{
	  int value;  // value that node saved
	  struct snode *next;
  };
  typedef struct snode list_node;
  
  int get_value(list_node *node){
	  if(node == NULL) return 0;
	  return (node->value);
  }
  
  list_node* list_create(int x){
	  list_node list = {x, NULL};
	  list_node *addr_list = &list;
	  return addr_list;
  }
  
  void outlist(list_node *list){
	  if((list->next) == list) printf(" NULL ssss");
  }
  
  int main(){
	  list_node *list = list_create(5);
	  if((list->next) == list) printf(" NULL dadaad");
	  outlist(list);
	  printf("%d \n", get_value(list));
	  list = list_add_front(3, list);
	  outlist(list);
  }
