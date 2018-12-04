#include<iostream>
#include<queue>
using namespace std;
queue <string> res;
struct node {
  string data;
  node *left_child, *right_child; 
};

node *Creat_BinaryTree(node *&root) {
  char x;
  cin >> x; 
  if (x == '#' || x == '@') return NULL;
  root = new node;
  root->data = x;
  root->left_child = Creat_BinaryTree(root->left_child);
  root->right_child = Creat_BinaryTree(root->right_child);
  return root;
}

void Destroy(node *&root) {
  if (root == NULL) return;
  Destroy(root->left_child);
  Destroy(root->right_child);
  delete root;
}
 
void PreOrder(node *&root, int i, int level) {
  if (root == NULL) return;
  if (i == level) {
    cout << root->data;
    res.push(root->data);
    return;
  }
  
  PreOrder(root->left_child, i+1, level);
  PreOrder(root->right_child, i+1, level);
}
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
////    if (front == level) {
//      printf("%d : %c\n", front, p->data);
////    }
//    
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
int main() {
  node *root = NULL;
  root = Creat_BinaryTree(root);
  int level;
  cin >> level;
  PreOrder(root, 1, level);
  int sum = res.size();
  for (int i = 0; i < sum; i++) {
    cout << res.front() << "~";
    res.pop();
  }
  Destroy(root);
}
