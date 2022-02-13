#include <iostream>
#include <utility>
using namespace std;
#define endl "\n"

struct node {
	int value;
	node* parent;
	node* left;
	node* right;
};

struct tree {
	node* root; 

	static tree init() {
		tree a;
		a.root = new node{1, NULL, NULL, NULL};
		return a;
	}

	node * find(node * root, int findValue) {
		if (!root)
			return NULL;

		if (root->value == findValue)
			return root; // 현재 노드를 반환

		auto firstFound = find(root->left, findValue);
		if (firstFound != NULL)
			return firstFound;

		return find(root->right, findValue);
	}

	void insert(int size, pair<int, int>* arr) {
		for (int i = 0; i < size; i++) {
			if (find(root, arr[i].first) != NULL) {
				node* foundNode = tree::find(root, arr[i].first);

				if (foundNode->left == NULL)
					foundNode->left = new node{ arr[i].second, foundNode, NULL , NULL };
				else
					foundNode->right = new node{ arr[i].second, foundNode, NULL, NULL };
			}
			else {
				node* foundNode = tree::find(root, arr[i].second);
				if (foundNode->left == NULL)
					foundNode->left = new node{ arr[i].first, foundNode, NULL, NULL };
				else
					foundNode->right = new node{ arr[i].first, foundNode, NULL, NULL };
			}
		}
	}

	void print(int size) {
		for (int i = 2; i < size + 1; i++) {
			node * foundNode = find(root, i);
			cout << foundNode->parent->value << endl;
		}
	}
};

int n;
pair<int,int > *arr;
int parent, child;


void input() {
	cin >> n;  // 7
	arr = new pair<int, int>[n]; 
	for (int i = 0; i < n -1 ; i++) {
		cin >> parent >> child;
		arr[i] = make_pair(parent, child);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	auto tree = tree::init();
	tree.insert(n-1, arr);
	tree.print(n);

	return 0;
}