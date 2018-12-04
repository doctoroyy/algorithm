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
int main() {
  char PostOrder[maxsize+10], InOrder[maxsize+10];
  while (cin >> PostOrder >> InOrder) {
    node *root = NULL;
    int len = strlen(PostOrder);
    rebuildBiTree(root, PostOrder, InOrder, len);
    PreOrder(root);
    cout << endl;
  }
}
