#include<iostream>
#include<queue>
using namespace std;  
const int maxsize = 30;  
struct node {  
  int data;  
  node *lchild, *rchild;  
  node(int x) {
    data = x; 
    lchild = rchild = NULL;
  }  
};
node* build(int *InOrder, int *PreOrder, int len) {
  if (len == 0) {
    return NULL;
  }
  node *root = new node(PreOrder[0]);
  int root_pos;
  for (int i = 0; i < len; i++) {
    if (*PreOrder == InOrder[i]) {
      root_pos = i;
      break;
    }
  }
  //一定要注意判断左右子树元素个数(左子串长度)是否大于零，否则访问到不可访问的
  //内存区域会发生断错误 Segmentation fault
  if (root_pos > 0) { //root_pos为左子串长度
    root->lchild = build(InOrder, PreOrder + 1, root_pos);
  }
  if (len - root_pos - 1 > 0) { // len - root_pos - 1 为右子串长度 
    root->rchild = build(InOrder + root_pos + 1, PreOrder + root_pos + 1, len - root_pos - 1);
  }
  return root;
}
void levelOrder(node *root) {
  queue <node*> sq;
  sq.push(root);
  bool flag = false;
  while (!sq.empty()) {
    node *p = sq.front();
    if (!flag) {
      cout << p->data;
      flag = true;
    } else {
      cout << " " << p->data;
    }
    sq.pop();
    if (p->rchild != NULL) sq.push(p->rchild);
    if (p->lchild != NULL) sq.push(p->lchild);
  }
} 
int main() {  
  int n;
  cin >> n;  
  int InOrder[maxsize+10];
  int preOrder[maxsize+10]; 
  for(int i = 0; i < n; i++)  
    cin >> InOrder[i];  
  for(int i = 0; i < n; i++)  
    cin >> preOrder[i];  
  node *root = build(InOrder, preOrder, n); 
  levelOrder(root);   
  return 0;
}
