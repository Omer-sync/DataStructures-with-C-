// Tree with only given char nodes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining a variable(struct) as node_struct
struct node_struct
{
    char data;
    struct node_struct *right;
    struct node_struct *left;
};
//Type redefinition as node
typedef struct node_struct node;

node* root;

node* insert (node *tree,char number);
void preorder (node *tree);
void postorder (node *tree);
void inorder (node *tree);
void Find_Min_Max_NonRecursive( node *p, char *min, char *max);
char Find_Min_Max_Recursive( node *p, char *min, char *max);





int main()
{
	node *root = NULL;
	root=insert(root,'F');
    root=insert(root,'B');
    root=insert(root,'I');
    root=insert(root,'E');
    root=insert(root,'C');
    //root=insert(root,'A');
    root=insert(root,'H');
    root=insert(root,'G');
    root=insert(root,'D');
    char a, b;

    Find_Min_Max_Recursive(root,&a,&b);
    printf("%c , , %c",a,b);
    
 


	printf("\npre\n");
	preorder(root);
	printf("\n***\n");
	printf("\nin\n");
	inorder(root);
	
	printf("\n***\n");
	printf("\npost\n");
	postorder(root);
	//printf("size : %d ",size(root));
	//printf("size : %d ",leafNode_size(root));


    return 0;
}
node* insert (node *tree,char number)
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

	printf("%c ",tree->data);
	preorder(tree->left);
	preorder(tree->right);
}
void postorder (node *tree)
{
	if (tree == NULL)
		return;

	postorder(tree->left);
	postorder(tree->right);
	printf("%c ",tree->data);
}
void inorder (node *tree)
{
	if (tree == NULL)
		return;

	inorder(tree->left);
	printf("%c ",tree->data);
	inorder(tree->right);	
}
void Find_Min_Max_NonRecursive( node *p, char *min, char *max)
{
    node *maximum_iter = p;
    node *minimum_iter = p;

	while(maximum_iter->right!=NULL)
		maximum_iter=maximum_iter->right;
	*max = (maximum_iter->data);
    while(minimum_iter->left!=NULL)
		minimum_iter=minimum_iter->left;
	*min = (minimum_iter->data);
}
char Find_Min_Max_Recursive( node *p, char *min, char *max)
{
	if (p->left == NULL || p->right == NULL)
	{

		return p->data;
	}
	if (p->right != NULL)
	{
		*max = Find_Min_Max_Recursive(p->right,min,max);
	}
	if (p->left != NULL)
	{
		*min = Find_Min_Max_Recursive(p->left,min,max);
	}
	
	
}