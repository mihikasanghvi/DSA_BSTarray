typedef struct tree {
 int size;
 int *arr;
} tree;

void init_BST(tree **BST);
void insert(tree **BST, int data);
void inorder(tree *BST, int index);
void preorder(tree *BST, int index);
void postorder(tree *BST, int index);
int countNodes(tree *BST, int index);
int isComplete(tree *BST, int index, int count);
