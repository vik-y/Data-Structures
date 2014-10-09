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
	return temp;
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

void printtree(tree *temp){
	//A function to test if the state of tree
	printlevel(temp, 0);
	printf("\n");
	printlevel(temp, 1);
	printf("\n");
	printlevel(temp, 2);
	printf("\n");
	printlevel(temp, 3);
	printf("\n");
	printlevel(temp, 4);
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
	if(*temp == NULL && value!=NULL){
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

tree * get_min_value(tree *temp){
	tree *newtemp = temp;
	while(newtemp->left!=NULL) newtemp =  newtemp->left;
	return newtemp;
}

int search_delete(tree **temp, int value){
	/*
	 * Searches if the "value" exists, delete it if it exists
	 */
	if(*temp!=NULL){
			if((*temp)->val == value){
				//Storing the left and right node because the node is going to be deleted and these
				//values will be lost
				tree *leftchild = (*temp)->left;
				tree *rightchild = (*temp)->right;

				//As the tree will have to be rotated we are going to see where the leftnode has to be inserted
				//because we are going to replace the null node with rightnode
				tree * tempmin = get_min_value(*temp);
				if(rightchild!=NULL){
					free(*temp); //Deallocating memory from the node which is being deleted
					*temp = rightchild;
					tempmin->left = leftchild;
					printf("Done assigning\n");
				}
				else *temp = leftchild;

				return 1;
			}
			else if(value > (*temp)->val){
				search_delete(&(*temp)->right, value);
			}
			else{
				search_delete(&(*temp)->left, value);
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
	return 0 ;
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
	insert(&newtree, newNode(100));

	printlevel(newtree, 3);
	printf("\n");
	printtree(newtree);


	search_delete(&newtree, 50);
	printf("\n");
	printtree(newtree)	;


	//Delete to be implemented
	//Free memory when you delete or replace a node

	/*
	 * All features and a working version of this to be implemented
	 */
	return 0;
}
