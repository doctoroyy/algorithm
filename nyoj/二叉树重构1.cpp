#include<iostream>
#include<cstring>
using namespace std;
const int maxsize = 100;
struct node {
  node *lchild, *rchild;
  char data;
  node() {
    lchild = NULL;
    rchild = NULL;
  }
};

void rebuildBiTree(node *&root, char *PostOrder, char *InOrder, int len) {
  if (len == 0) {
    root = NULL;
    return;
  }
  root = new node();
  root->data = PostOrder[len - 1];
  //ACBFGE D  ABC D EFG
  //AC B   A B C           
  
  char *root_pos = strchr(InOrder, root->data);
  int l_len = strlen(InOrder) - strlen(root_pos);
  int r_len = len - l_len - 1;
  rebuildBiTree(root->lchild, PostOrder, InOrder, l_len);
  rebuildBiTree(root->rchild, PostOrder + l_len, root_pos + 1, r_len);
}
void PreOrder(node *root) {
  if (root == NULL) return;
  cout << root->data;
  PreOrder(root->lchild);
  PreOrder(root->rchild);
}
void Destroy(BinaryTree *&root) {
  if (root == NULL) return;
  Destroy(root->left_child);
  Destroy(root->right_child);
  delete root;
}
void invertTree(node *root) {
  if (root == NULL) {
    return;
  }
  if (root->lchild != NULL || root->rchild != NULL) {
    node *tmp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = tmp;
  } 
  invertTree(root->lchild);
  invertTree(root->rchild);
}
void levelOrder(node *root) {
  queue <node*> sq;
  sq.push(root);
  while (!sq.empty()) {
    node *p = sq.front();
    cout << p->data << " ";
    sq.pop();
    if (p->lchild != NULL) sq.push(p->lchild);
    if (p->rchild != NULL) sq.push(p->rchild);
  }
}
int main() {
  char PostOrder[maxsize+10], InOrder[maxsize+10];
  while (cin >> PostOrder >> InOrder) {
    node *root = NULL;
    int len = strlen(PostOrder);
    rebuildBiTree(root, PostOrder, InOrder, len);
    
    levelOrder(root);
    
    cout << endl;
  }
}
