#include <stdio.h>
#include <stdlib.h>
#include "partb.h"

int main(void)
{
 int i,j;
 printf("Enter the number of elements: ");
 scanf("%d",&i);
 int postorder[100]={};
 for(int a=0; a<i;a++){
	 printf("\nEnter element: ");
	 scanf("%d",&j);
	 postorder[a]=j;
 }
 //int postorder[] = { 8, 12, 10, 16, 25, 20, 15 };
// int n = sizeof(postorder)/sizeof(postorder[0]);
// struct Node* root = constructBST(postorder, 0, n - 1);
 struct Node* root = constructBST(postorder,0,i-1);
 printf("Inorder traversal of BST is ");
 inorder(root);
 return 0;
}

