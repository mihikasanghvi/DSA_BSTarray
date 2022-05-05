#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bstarray.h"
int main()
{
 int i,j;
 tree *BST;
 BST->size = 10;
 init_BST(&BST);
 printf("Enter the number of elements you want to enter: ");
 scanf("%d",&i);
 for(int a=0;a<i;a++){
	 printf("\nEnter the element: ");
	 scanf("%d",&j);
	 insert(&BST,j);
 }
// insert(&BST, 2);
// insert(&BST, 4);
// insert(&BST, 1);
 //insert(&BST, 3);
 inorder(BST, 0);
 printf("\n");
 postorder(BST,0);
  printf("\n");
 preorder(BST,0);
 printf("\n");

 int count = countNodes(BST, 0);
 printf("\nThe number of nodes: %d",count);
 if(isComplete(BST, 0, count) == 1) {
  printf("\nThe tree is complete\n");
 }
else{
	printf("\nThe tree is not complete");
 return 0;
}
