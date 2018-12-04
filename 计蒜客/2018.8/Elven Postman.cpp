#include<iostream>
using namespace std;
struct Node {
	int data;
	Node *left, *right;
	Node() {}
	Node(int x):data(x), left(NULL), right(NULL) {}
};
class BinaryTree {
	public:
		Node *root;
		BinaryTree() { root = NULL;	}
		void Create() { 
			int n, x;
			cin >> n;
			for(int i = 0; i < n; i++) {
				cin >> x;
				insert(x);
			}
		}
		void insert(int x) { insert(root, x); }
		void insert(Node *&t, int x) {
			if(t == NULL) {
				t = new Node;
				t->data = x;
				t->left = t->right = NULL;
			}
			if(t->data == x)
				return;
			else if(t->data > x)
				insert(t->left, x);
			else
				insert(t->right, x);
		}
		Node *search(Node *t, int x) {
			if(t == NULL)
				return NULL;		
			if(t->data == x) {
				cout << endl;
				return NULL;
			}			
			if(t->data > x) {
				cout << "E"; 
				return search(t->left, x);
			}			
			else{
				cout << "W";
				return search(t->right, x);
			}
		}	
};
int main() {
	int t, n, x;
	cin >> t;
	while(t--) {
		BinaryTree bt;
		bt.Create();
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> x;
			bt.search(bt.root, x);
		}
	}		
} 
