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
node* build(int *PreOrder, int *InOrder, int len) {
  node* root = new node(PreOrder[0]);
  int root_pos;
  for (int i = 0; i < len; i++) {
    if (PreOrder[0] == InOrder[i]) {
      root_pos = i;
      break;
    }
  }
  if (root_pos > 0) {
    root->lchild = build(PreOrder + 1, InOrder, root_pos);
  }
  if (len - root_pos - 1) {
    root->rchild = build(PreOrder + root_pos + 1, InOrder + root_pos + 1, len - root_pos - 1);
  }
  return root;
}
void levelOrder(node* root) {
  queue<node*> q;
  q.push(root);
  while (!q.empty()) {
    node* tmp = q.front();
    q.pop();
    if (tmp->rchild) {
      cout << " " << tmp->ele;
    }
    if (tmp->lchild) {
      cout << " " << tmp->ele;
    }
  }
}

int main() {
  int n;
  int PreOrder[100], InOrder[100];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> InOrder[i];
  for (int i = 0; i < n; i++) cin >> PreOrder[i];
  node* root = build(PreOrder, InOrder, n);
  levelOrder(root);
  return 0;
}

