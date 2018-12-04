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

void rebuildBiTree(node *&root, char *PreOrder, char *InOrder, int len) {
  if (len == 0) {
    root = NULL;
    return;
  }
  root = new node();
  root->data = PreOrder[0];
  //D BAC EGF   ABC D EFG
  
  char *root_pos = strchr(InOrder, root->data);
  int l_len = strlen(InOrder) - strlen(root_pos);
  int r_len = len - l_len - 1;
  rebuildBiTree(root->lchild, PreOrder + 1, InOrder, l_len);
  rebuildBiTree(root->rchild, PreOrder + l_len + 1, root_pos + 1, r_len);
}
void PostOrder(node *root) {
  if (root == NULL) return;
  PostOrder(root->lchild);
  PostOrder(root->rchild);
  cout << root->data;
}
int main() {
  char PreOrder[maxsize+10], InOrder[maxsize+10];
  while (cin >> PreOrder >> InOrder) {
    node *root = NULL;
    int len = strlen(PreOrder);
    rebuildBiTree(root, PreOrder, InOrder, len);
    PostOrder(root);
    cout << endl;
  }
}
