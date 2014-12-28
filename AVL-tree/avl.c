/*
 * AVL Tree
 * Reference: AVL Tree Geeks for Geeks
 * NOTE: Most of the code segment was taken from geeksforgeeks as the code quality was superb
 */

//Delete function yet to be added and made functional
//Add support for values to be added and stored on a file if the application is closed to increase the lifecycle of the datastructure

/*
 * Assumptions made in the following code -
 * Height of the root node =
 */
#include<stdio.h>
#include<stdlib.h>

//AN AVL Tree Node
struct node
{
	int val;
	struct node *left;
	struct node *right;
	int height;
};

int max(int a, int b)
{
	return (a > b)? a : b;
}


int height(struct node *N)
{
	//Returns height of the Node N
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum of two integers


/* Helper function that allocates a new node with the given val and
    NULL left and right pointers. */
struct node* newNode(int val)
{
	struct node* node = (struct node*)
                        		malloc(sizeof(struct node));
	node->val   = val;
	node->left   = NULL;
	node->right  = NULL;
	node->height = 1;  // new node is initially added at leaf, a
	return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node *rightRotate(struct node *y)
{
	/*
		 * Consider this Tree for rotation
		 *      y									x
		 *     / \								   /  \
		 *    x   T3      after right rotate      T1   y
		 *   / \								      / \
		 *  T1  T2                                   T2  T3
		 *
		 *  So if we are asked to rotate around a node y we have to replace the memory location of
		 *  y with that of x and put x->right as y and y->left as t2 - as simple as that
		 */
	struct node *x = y->left; //Getting the left child of y
	struct node *T2 = x->right; //Getting the right child of the left child of y

	// Perform rotation
	x->right = y;
	y->left = T2;

	/*
	 * Rotation has been done, now we have to change the height as required
	 * Height of Subtrees T1, T2 and T3 will remain the same as we don't need to change them
	 * But height of x has changed and so has the height of y
	 * Also - height of ancestor doesn't need to be changed. because we have to do that after the insertion
	 * It will be taken care of in the insert function
	 */
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// Return new root address
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x)
{
	struct node *y = x->right;
	struct node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	//  Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(struct node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct node* insert(struct node* node, int val)
{
	/*
	 * Note :
	 * Insert function also updates the height of the ancestors while reaching to the node recursively.
	 * How it works:
	 * First it checks if the given node is NULL or not, if it's null it straightaway assigns it the value and returns the address.
	 * If it's not null, it decides whether to go left or to right,
	 */
	/* 1.  Perform the normal BST rotation */
	if (node == NULL)
		return(newNode(val));

	if (val < node->val)
		node->left  = insert(node->left, val);
	else
		node->right = insert(node->right, val);

	/* 2. Update height of this ancestor node */
	node->height = max(height(node->left), height(node->right)) + 1;
	//printf("Height of node: %d udpated to : %d\n", node->val, node->height);

	/* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced*/

	int balance = getBalance(node);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && val < node->left->val)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && val > node->right->val)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && val > node->left->val)
	{
		node->left =  leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && val < node->right->val)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(struct node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->val);
		preOrder(root->left);
		preOrder(root->right);
	}
}


void printheight(struct node *y){
	//Prints height of each node in PreOrder sequencce
	if(y==NULL)
		return;
	else{
		printf("Heght of %d is %d\n", y->val, y->height);
		printheight(y->left);
		printheight(y->right);
	}

}
/* Drier program to test above function*/
int main()
{
	struct node *root = NULL;

	/* Constructing tree given in the above figure */
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);
	root = insert(root, 1);
	root = insert(root, 15);

	/* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
	 */

	printf("Pre order traversal of the constructed AVL tree is \n");
	preOrder(root);
	printf("\n");
	printheight(root);
	return 0;
}
