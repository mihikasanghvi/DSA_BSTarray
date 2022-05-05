#include <stdio.h>
#include <stdlib.h>
#include "partb.h"

Node* newNode(int key)
{
 Node* node = (Node*)malloc(sizeof(Node));
 node->key = key;
 node->left = node->right = NULL;

 return node;
}

void inorder(Node* root)
{
 if (root == NULL) {
  return;
 }

 inorder(root->left);
 printf("%d ", root->key);
 inorder(root->right);
}

Node* constructBST(int postorder[], int start, int end)
{
 if (start > end) {
  return NULL;
 }

 Node* node = newNode(postorder[end]);

 int i;
 for (i = end; i >=start; i--)
 {
  if (postorder[i] < node->key) {
   break;
  }
 }

 node->right = constructBST(postorder, i + 1, end - 1);

 node->left = constructBST(postorder, start, i);

 return node;
}
