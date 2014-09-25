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
	struct tree *parent;
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


//------------Ways to print elements in a binary tree -- starts here

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
	if(level==0 && tree!=NULL) printf("%d ", tree->val);
	else if(tree!=NULL){
		printlevel(tree->left, level-1);
		printlevel(tree->right, level-1);
	}
	else return;
}

void print_preorder(tree *tree){
	//Preorder traversal of a tree
}

void print_postorder(tree *tree){
	//Post order traversal of a trees
}

//---------------Different ways to print tree elements, ends here----------------



void insert(tree **temp, tree *value){
	//pass the pointer to the structure
	if(*temp == NULL){
		*temp = value;
		(*temp)->left = NULL;
		(*temp)->right = NULL;
		return;
	}

	else if(value->val > (*temp)->val){
		//printf("inserting on right\n");
		insert(&(*temp)->right, value);
	}
	else if(value->val <= (*temp)->val){
		insert(&(*temp)->left, value);
	}
}

//----------Delete Starts here ----------------

void delete(tree **temp){
	/*
	 * To be implemented
	 */
	tree *leftchild = (*temp)->left;
	tree *rightchild = (*temp)->right;
	printf("till here\n");
	if(temp!=NULL){
		if(rightchild!=NULL){
			*temp = rightchild;
			printf("till here 1\n");
			tree * templeft = (*temp)->left;
			(*temp)->left = leftchild;
			printf("calling insert\n");
			//if(templeft!= NULL) insert(&(*temp), templeft);
		}
		else if(leftchild!=NULL){
			*temp = leftchild;
			tree * tempright = (*temp)->right;
			(*temp)->right = rightchild;
			if(tempright!= NULL) insert(&(*temp), tempright);
		}
		else{
			printf("assigning null\n");
			*temp = NULL;

		}
	}
}

int search_delete(tree *temp, int val){
	/*
	 * Search Delete function is not working
	 */
	if(temp!=NULL){
		if(temp->val == val) {
			printf("Calling delete function\n");
			delete(&temp);
			return 1;
		}
		if(val>temp->val){
			printf("val greater\n");
			search_delete(temp->right, val);
		}
		else{
			printf("val lesser\n");
			search_delete(temp->left, val);
		}
	}
}

//------------------Delete functions end here -------------------------


//-----------------Search Function starts here ------------------------
int search(tree *temp, int val){
	/*
	 * The search should be of order log(n) because if any element is actually present in the tree
	 * then the time to taken to reach it is dependent on the height of the tree
	 * which is 2^h + 1 = n (h = height of tree, n = number of elements in tree)
	 * h*log(2) = log(n-1), h = log(n-1)/log(2), that's why the search is order log(n)
	 */
	if(temp!=NULL){
		if(temp->val == val) return 1;
		if(val>temp->val){
			search(temp->right, val);
		}
		else{
			search(temp->left, val);
		}
	}
}
//-----------------Search Function ends here ----------------------


//----------------Main function starts here -----------------------

int main(int argc, char **argv) {
	tree *newtree;
	newtree = (tree *)malloc(sizeof(tree));
	newtree->val = 20;

	insert(&newtree, newNode(50));
	insert(&newtree, newNode(10));

	insert(&newtree, newNode(11));
	insert(&newtree, newNode(5));
	insert(&newtree, newNode(25));
	insert(&newtree, newNode(53));
	insert(&newtree, newNode(56));
	printlevel(newtree, 3);

	while(1){
		int temp;
		scanf("%d", &temp);
		//Testing Delete feature
		search_delete(newtree, temp);
		printlevel(newtree, 3);
	}

	/*
	 * All features and a working version of this to be implemented
	 */
	return 0;
}



