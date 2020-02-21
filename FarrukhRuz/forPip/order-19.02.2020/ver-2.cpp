# include <bits/stdc++.h>
  using namespace std;
  struct SimpleTree{
	  int x, count;
	  SimpleTree *leftTree;
	  SimpleTree *rightTree;
	  SimpleTree(int x) : x(x), count(1), leftTree(NULL), rightTree(NULL) {}
  };
  typedef SimpleTree* TreeNode;
  int tree_height;
  vector<int> candidates;
  
  int get_count(TreeNode tree){
	  if(tree == NULL) return 0;
	  return tree->count;
  }
  
  void add_node(TreeNode &tree, int x){
	  if(tree == NULL) tree = new SimpleTree(x);
	  if(tree->x == x) return;
	  if(tree->x < x) add_node(tree->rightTree, x);
	  else add_node(tree->leftTree, x);
	  tree->count = get_count(tree->leftTree) + get_count(tree->rightTree) + 1;
  }
  
  int count_deep(TreeNode tree){
	  if(tree == NULL) return 0;
	  return max(count_deep(tree->leftTree), count_deep(tree->rightTree)) + 1;
  }
  
  void print_tree(TreeNode tree){
	  if(tree != NULL){
		  cout << tree->x << " ";
		  print_tree(tree->leftTree);
		  print_tree(tree->rightTree);
	  }
  }
  
  void find_candidates(TreeNode tree, int h = 1){
	  if(tree == NULL) return;
	  if(h == (tree_height + 1) / 2){
		  if(get_count(tree->leftTree) > get_count(tree->rightTree)){
			  candidates.push_back(tree->x);
		  }
	  }
	  else {
		  find_candidates(tree->leftTree, h + 1);
		  find_candidates(tree->rightTree, h + 1);
	  }
  }
  
  TreeNode merge_nodes(TreeNode left, TreeNode right){
	  if(left == NULL) return right;
	  if(right == NULL) return left;
	  right->leftTree = merge_nodes(left, right->leftTree);
	  return right;
  }
  
  void remove_x(TreeNode tree, TreeNode pred, int x){
	  if(tree == NULL) return;
	  if(tree->x == x){
		  if((pred->leftTree != NULL) && (pred->leftTree->x == tree->x)){
			  pred->leftTree = merge_nodes(tree->leftTree, tree->rightTree);
		  } 
		  else {
			  pred->rightTree = merge_nodes(tree->leftTree, tree->rightTree);
		  }
	  }
	  else if(x < tree->x) remove_x(tree->leftTree, tree, x);
	  else remove_x(tree->rightTree, tree, x);
  }

  int main(){
	TreeNode tree = NULL;
	long long x;
	while(cin >> x){
		add_node(tree, x);
	}
	
	tree_height = count_deep(tree);
	
	find_candidates(tree);
	
	sort(candidates.begin(), candidates.end());

	int mid_x = candidates[candidates.size() / 2];
	
	remove_x(tree, NULL, mid_x);
		
	print_tree(tree);
	
  }















