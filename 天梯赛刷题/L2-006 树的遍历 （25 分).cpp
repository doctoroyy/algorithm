#include<iostream>
#include<queue>
using namespace std;
struct node {
  node *lchild, *rchild;
  int ele;
  node (int x) {
    ele = x;
    lchild = rchild = NULL;
  }
};

node* build(int *InOrder, int *PostOrder, int len) {
  int root_pos = -1;
  node* root = new node(PostOrder[len - 1]);
  for (int i = 0; i < len; i++) {
    if (root->ele == InOrder[i]) {
      root_pos = i;
      break;
    }
  }
  int llen = root_pos;
  int rlen = len - llen - 1;
  if (llen > 0) {
    root->lchild = build(InOrder, PostOrder, llen);
  }
  if (rlen > 0) {
    root->rchild = build(InOrder + root_pos + 1, PostOrder + root_pos, rlen);
  }
  return root;
}
void levelOrder(node* root) {
  queue<node*> q;
  q.push(root);
  
  node* tmp = q.front();
  q.pop();
  if (tmp->lchild) q.push(tmp->lchild);
  if (tmp->rchild) q.push(tmp->rchild);
  cout << tmp->ele;
  
  while (!q.empty()) {
    node* tmp = q.front();
    q.pop();
    if (tmp->lchild) q.push(tmp->lchild);
    if (tmp->rchild) q.push(tmp->rchild);
    cout << " " << tmp->ele;
  }
}
int main() {
  int n;
  cin >> n;
  int InOrder[40], PostOrder[40];
  for (int i = 0; i < n; i++) {
    cin >> PostOrder[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> InOrder[i];
  }
  node* root = build(InOrder, PostOrder, n);
  levelOrder(root);
  return 0;
}

