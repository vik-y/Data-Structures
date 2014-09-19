/*
 * Making a very small Data Structure using Binary Tree and connect it with PHP
 * so that it can take in some custom queries from the web and show the results
 * on browser itself.
 * This is just for learning and fun, no practical use intended
 *
 * PHP Plugin in plugins directory of this Data-Strucutres repository - Under Development
 *
 * A binary tree.
 * Till now it contains insertion and some functions to print trees level by level
 */
#include <stdio.h>
#include <stdlib.h>

struct tree{
	//Val contains the value stored in a node and left and right are the left and right branches
	int val;
	struct tree *left;
	struct tree *right;
};



typedef struct tree tree;

tree * newNode(int value){
	/*
	 * A helper function to make a new node, allocates memory and returns a pointer
	 */
	tree * temp = (tree *)malloc(sizeof(tree));
	temp->val = value;
	temp->left = NULL;
	temp->right = NULL;
}

void printout(tree * tree) {
	/*
	 * A function to printout all the elements of the tree, the order in which it
	 * prints doesn't make much sense, can be used to check insertion and deletion
	 */
   if(tree->left) printout(tree->left);
   printf("%d\n",tree->val);
   if(tree->right) printout(tree->right);
}

void printlevel(tree *tree, int level){
	/*
	 * Base level(root) is 0, assuming that given any level, this function will print all
	 * the elements present in that level
	 */
	if(level==0) printf("%d ", tree->val);
	else{
		printlevel(tree->left, level-1);
		printlevel(tree->right, level-1);
	}
}

void insert(tree **temp, tree *value){
	//pass the pointer to the structure
	if(*temp == NULL){
		*temp = value;
		(*temp)->left = NULL;
		(*temp)->right = NULL;
		return;
	}

	else if(value->val > (*temp)->val){
		printf("inserting on right\n");
		insert(&(*temp)->right, value);
	}
	else if(value->val <= (*temp)->val){
		insert(&(*temp)->left, value);
	}
}


void delete(){
	/*
	 * To be implemented
	 */
}

int search(){
	/*
	 * To be implemented
	 */
}


int main(int argc, char **argv) {
	tree *newtree;
	newtree = (tree *)malloc(sizeof(tree));
	newtree->val = 20;

	//Testing print level function
	insert(&newtree, newNode(50));
	insert(&newtree, newNode(10));

	insert(&newtree, newNode(11));
	insert(&newtree, newNode(5));
	insert(&newtree, newNode(25));
	insert(&newtree, newNode(53));
	printlevel(newtree, 2);


	/*
	 * All features and a working version of this to be implemented
	 */
	return 0;
}



