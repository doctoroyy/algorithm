#include<iostream>
#include<queue>
using namespace std;
const int maxsize = 30;
struct node {
  node *lchild=NULL, *rchild=NULL;
  int data;
};
node *rebuildBiTree(int *InOrder,int *PreOrder,int n) {  
    if(n == 0)  
    return NULL;  
      
    node *root = new node;
    root->data = PreOrder[0];
    int root_pos;  
      
    for(int i = 0; i < n; i++) {
      if(InOrder[i] == PreOrder[0]) {
        root_pos = i;
        break;
      } 
    }
    //在中序遍历种找到根节点的位置  
    if(root_pos > 0)  
    root->lchild = rebuildBiTree(InOrder,PreOrder+1,root_pos);  
    if(n - root_pos - 1 > 0)  
    root->rchild = rebuildBiTree(InOrder[root_pos + 1], PreOrder[root_pos + 1],n - root_pos -1);  
      
    return root;  
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
  int PreOrder[30] = {4,1,3,2,6,5,7}, InOrder[7] = {1,2,3,4,5,6,7};
  int n = 7;
  node *root = NULL;
//   root = rebuildBiTree(PreOrder, InOrder, n);
//   levelOrder(root);
  cout << endl;
}
