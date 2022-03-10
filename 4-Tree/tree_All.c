#include<stdio.h>
#include<stdlib.h>

//Defining a variable(struct) as node_struct
struct node_struct
{
    int data;
    struct node_struct *right;
    struct node_struct *left;
};
//Type redefinition as node
typedef struct node_struct node;

node* root;

node* insert (node *tree,int number);
void preorder (node *tree);
void postorder (node *tree);
void inorder (node *tree);
int find(node* tree,int key);
int maximum(node *tree);
int minimum(node *tree);
node * delete(node *tree,int key);
int size(node* tree);
int height(node *root);
int leafNode_size(node* tree);
// Swapping two child (left to right, right to left)
void mirror(node* root) ;
int isSame(node* a, node* b); 
// Checking if there is a sum of path is equal to 'sum'
int path(node* root, int sum);
 // Copy odd nodes to another tree
node* copyOdd(node* root, node* root2); 

int main()
{
	node *root = NULL;
	root=insert(root,56);
	root=insert(root,200);
	root=insert(root,26);
	root=insert(root,190);
	root=insert(root,213);
	root=insert(root,18);
	root=insert(root,28);
	root=insert(root,12);
	root=insert(root,24);
	root=insert(root,27);


	printf("\npreorder\n");
	preorder(root);
	printf("\n***\n");
	printf("\ninorder\n");
	inorder(root);
	
	printf("\n***\n");
	printf("\npostorder\n");
	postorder(root);

	mirror(root);
	printf("\npreorder\n");
	preorder(root);
	printf("\n***\n");
	printf("\ninorder\n");
	inorder(root);
	
	printf("\n***\n");
	printf("\npostorder\n");
	postorder(root);

	printf("size : %d ",size(root));
	printf("height : %d ",height(root));
	//printf("size : %d ",leafNode_size(root));


    return 0;
}
node* insert (node *tree,int number)
{
	if(tree == NULL){
		node *newNode= (node *)malloc(sizeof(node));
		newNode -> left = NULL;
		newNode -> right = NULL;
		newNode -> data = number;
		return newNode;
	}
	
	if(tree->data < number){
		tree->right = insert(tree->right,number);
		return tree;
	}
	tree->left = insert (tree->left,number);
	return tree;
}
void preorder (node *tree)
{
	if (tree == NULL)
		return;

	printf("%d ",tree->data);
	preorder(tree->left);
	preorder(tree->right);
}
void postorder (node *tree)
{
	if (tree == NULL)
		return;

	postorder(tree->left);
	postorder(tree->right);
	printf("%d ",tree->data);
}
void inorder (node *tree)
{
	if (tree == NULL)
		return;

	inorder(tree->left);
	printf("%d ",tree->data);
	inorder(tree->right);	
}
int find(node* tree,int key)
{
	if(tree == NULL)
		return -1;
	if(tree->data == key)
		return 1;
	if(find(tree->right,key)==1)
		return 1;
	if(find(tree->left,key)==1)
		return 1;
	return -1;
}
int maximum(node *tree)
{
	if(tree == NULL)
		return 0;
	while(tree->right!=NULL)
		tree=tree->right;
	return tree->data;
}
int minimum(node *tree)
{
	if(tree == NULL)
		return 0;
	while(tree->left!=NULL)
		tree=tree->left;
	return tree->data;
}
node * delete(node *tree,int key)
{
	if(tree==NULL)
		return NULL;
	if(tree->data == key)
	{
		if(tree->left==NULL && tree->right==NULL)
			return NULL;
		if(tree->right!=NULL)
		{
			tree->data = minimum(tree->right);
			tree->right = delete(tree->right, minimum(tree->right));
			return tree;
		}
		tree->data = maximum(tree->left);
		tree->left = delete(tree->left,maximum(tree->left));
		return tree;
	}	
	if(tree->data < key)
	{
		tree->right = delete(tree->right,key);
		return tree;
	}
	tree->left= delete(tree->left,key);
	return tree;
}
int size(node* tree)
{
	static int totalsize = 0;
	if (tree == NULL)
		return 0;
	return size(tree->left) + 1 + size(tree->right);
}
int height(node *root) 
{ 
	if(root == NULL)
		return -1;
	else 
	{
		int left_height, right_height;
		left_height = height(root -> left); 
		right_height = height(root -> right);

		if(right_height > left_height) 
			return right_height + 1;
		else
			return left_height + 1;
	}
}

int leafNode_size(node* tree)
{
	static int totalsize = 0;
	int left = 0,right = 0;
	if (tree == NULL)
	{
		return 0;
	}
	
	if (tree->left == NULL && tree->right == NULL)
		return 1;
	if (tree->left != NULL || tree->right != NULL)
	{
		left = leafNode_size(tree->left);
		right = leafNode_size(tree->right);
		
	}
	totalsize = left + right;
	return totalsize;

}
// Swapping two child (left to right, right to left)
void mirror(node* root) 
{ 
	if(root == NULL)
		return;
	else 
	{
		node* temp;
		mirror(root -> left); 
		mirror(root -> right);
		temp = root -> left; // swap işlemi yapılıyor 
		root -> left = root -> right;
		root -> right = temp;
	}
}
int isSame(node* a, node* b) 
{ 
	if(a == NULL && b == NULL)
		return 1; // İki ağaç da boş ise true döndürür 
	else if(a != NULL && b != NULL)
		return (
			a -> data == b -> data && isSame(a -> left, b -> left) && 
			isSame(a -> right, b -> right) // Koşul doğru ise true döndürür
				);
	else
		return 0;
}
// Checking if there is a sum of path is equal to 'sum'
int path(node* root, int sum) 
{ 
	int pathSum;
	if(root == NULL) 
		return (sum == 0); 
	else 
	{
		pathSum = sum - root -> data;
		return (path(root -> left, pathSum) || 	path(root -> right, pathSum));
	}
}
// Copy odd nodes to another tree
node* copyOdd(node* root, node* root2) 
{ 
	if(root != NULL) 
	{
		if(root -> data % 2 == 1)
			root2 = insert(root2, root -> data);
		root2 = copyOdd(root -> left, root2); 
		root2 = copyOdd(root -> right, root2);
	}
	return root2;
}