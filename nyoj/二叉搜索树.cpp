#include<iostream>
using namespace std;
int a, b;
struct node {
	int data;
	node * lchild;
	node * rchild;
	node * parent;
	node() {
    lchild = NULL;
    rchild = NULL;
  }
};

void create(node *&root) {
	if (root->data >= b) return;
	root->lchild->parent = root->rchild->parent = root;

	root->lchild->data = root->data * 2;
	root->rchild->data = root->data * 10 + 1;
	create(root->lchild);
	create(root->rchild);
}
void print(node *root) {
  cout << root->lchild->data << "  " << root->lchild->data << endl;
  print(root->lchild);
  print(root->rchild);
} 
int main() {
  cin >> a >> b;
	node *root = NULL;
	root->data = a;
	create(root);
	print(root);
}
