#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bstarray.h"

void init_BST(tree **BST) {
 (*BST)->arr = (int *)malloc((*BST)->size * sizeof(int));
 for (int i = 0; i < (*BST)->size; i++) {
  (*BST)->arr[i] = INT_MIN;
 }
}

void insert(tree **BST, int data) {
 int pos = 0;
 while(pos<(*BST)->size) {
  if((*BST)->arr[pos] == INT_MIN) {
   (*BST)->arr[pos] = data;
   return;
  }
  else {
   if(data < (*BST)->arr[pos]) {
    pos = 2 * pos + 1;
   }
   else {
    pos = 2 * pos + 2;
   }
  }
 }
 if(pos>=(*BST)->size) {
  (*BST)->arr = (int *)realloc((*BST)->arr, 3 * (*BST)->size * sizeof(int));
  for (int i = (*BST)->size; i < 3 * (*BST)->size; i++) {
   (*BST)->arr[i] = INT_MIN;
  }
  (*BST)->size *= 3;
  (*BST)->arr[pos] = data;
 }
}

void inorder(tree *BST, int index) {
 if(index >= BST->size || BST->arr[index] == INT_MIN) {
  return;
 }
 inorder(BST, index * 2 + 1);
 printf("%d, ", BST->arr[index]);
 inorder(BST, index * 2 + 2);
}

void preorder(tree *BST, int index) {
 if(index >= BST->size || BST->arr[index] == INT_MIN) {
  return;
 }
 printf("%d, ", BST->arr[index]);
 preorder(BST, index * 2 + 1);
 preorder(BST, index * 2 + 2);
}

void postorder(tree *BST, int index) {
 if(index >= BST->size || BST->arr[index] == INT_MIN) {
  return;
 }
 postorder(BST, index * 2 + 1);
 postorder(BST, index * 2 + 2);
 printf("%d, ", BST->arr[index]);
}

int countNodes(tree *BST, int index) {
 if(BST->arr[index] == INT_MIN || index>=BST->size) {
  return 0;
 }
 return 1 + countNodes(BST, index * 2 + 1) + countNodes(BST, index * 2 + 2);
}

int isComplete(tree *BST, int index, int count) {
 if(BST->arr[index] == INT_MIN) {
  return 1;
 }
 if(index >= count) {
  return 0;
 }
 if(isComplete(BST, index * 2 + 1, count) && isComplete(BST, index * 2 + 2, count)) {
  return 1;
 }
 else {
  return 0;
 }
}
