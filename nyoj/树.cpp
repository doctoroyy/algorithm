#include<cstdio>
#include<iostream>
//#include<malloc.h>
//#define MaxSize 100
using namespace std;
typedef char DataType;
typedef struct node {
  DataType data;
  node *left_child, *right_child; 
}BinaryTree;
int count, level, num;
BinaryTree *Creat_BinaryTree(BinaryTree *&root) {
  char x;
  cin >> x;
  if (x == '#') return NULL;
  root = new BinaryTree;
  root->data = x;
  root->left_child = Creat_BinaryTree(root->left_child);
  root->right_child = Creat_BinaryTree(root->right_child);
  return root;
}

void Destroy(BinaryTree *&root) {
  if (root == NULL) return;
  Destroy(root->left_child);
  Destroy(root->right_child);
  delete root;
}

//void PreOrder(BinaryTree *&root) {
//  if (root == NULL) return;
//  printf("%c ", root->data);
//  PreOrder(root->left_child);
//  PreOrder(root->right_child);
//}
//
//void InOrder(BinaryTree *&root) {
//  if (root == NULL) return;
//  PreOrder(root->left_child);
//  printf("%c ", root->data);
//  PreOrder(root->right_child);
//}
//
//void PostOrder(BinaryTree *&root) {
//  if (root == NULL) return;
//  PreOrder(root->left_child);
//  PreOrder(root->right_child);
//  printf("%c ", root->data);
//}
//void LevelOrder(BinaryTree *&root) {
//  BinaryTree *q[MaxSize];
//  int front = 0, rear = 0;
//  BinaryTree *p;
//  if (root == NULL) return;
//  q[rear] = root;
//  rear = (rear + 1) % MaxSize;
//  while (front != rear) {
//    p = q[front];
//    front = (front + 1) % MaxSize;
//    printf("%c ", p->data);
//    if (p->left_child) {
//      q[rear] = p->left_child;
//      rear = (rear + 1) % MaxSize;
//    }
//    if (p->right_child) {
//      q[rear] = p->right_child;
//      rear = (rear + 1) % MaxSize;
//    }
//  }
//}

void levelOrder(BinaryTree *&root) {
  if (count == level) {
    if (num == 1) {
      printf("%c", root->data);
    } else {
      printf("~%c", root->data);
    }
    num++;
  }
  if (root->left_child) {
    count++;
    levelOrder(root->left_child);
    count--;
  }
  if (root->right_child) {
    count++;
    levelOrder(root->right_child);
    count--;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    BinaryTree *root = NULL;
    root = Creat_BinaryTree(root);
    num = count = 1;
    getchar();
    getchar();
    scanf("%d", &level);
    levelOrder(root);
    printf("\n");
    Destroy(root);
  }
  
}
