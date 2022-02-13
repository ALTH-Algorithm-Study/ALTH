#include <iostream>
using namespace std;

// 부모 노드의 값 >= 왼쪽 자식 노드의 값
// 부모 노드의 값 <= 오른쪽 자식 노드의 값

struct node {
	int data;
	node* left;
	node* right;
};

struct bst {
public:

	node* root = nullptr;
	node* find(int value) {
		return find_impl(root, value);
	}

	void insert(int value) {
		if (!root)
			root = new node{ value, NULL, NULL };
		else
			insert_impl(root, value);
	}

	void inorder() {
		inorder_impl(root);
	}

	// start 노드에서 큰 것중에 가장 작은 노드를 찾는 함수
	node* successor(node* start) {
		auto current = start->right;
		while (current && current->left)
			current = current->left;

		return current;
	}

	void deleteValue(int value) {
		root = delete_impl(root, value);
	}

private:
	node* find_impl(node* current, int value) {
		if (!current) {
			cout << endl;
			return NULL;
		}

		if (current->data == value) {
			cout << value << "를 찾았습니다. " << endl;
			return current;
		}

		if (value < current->data) {
			cout << current->data << "에서 왼쪽으로 이동합니다. " << endl;
			return find_impl(current->left, value);
		}

		if (value > current->data) {
			cout << current->data << "에서 오른쪽으로 이동합니다. " << endl;
			return find_impl(current->right, value);
		}
	}

	void insert_impl(node* current, int value) {
		if (value < current->data)
		{
			if (!current->left)
				current->left = new node{ value, NULL, NULL };
			else
				insert_impl(current->left, value);
		}
		else {
			if (!current->right)
				current->right = new node{ value, NULL, NULL };
			else
				insert_impl(current->right, value);
		}
	}

	void inorder_impl(node* start) {
		if (!start)
			return;

		inorder_impl(start->left);
		cout << start->data << " ";
		inorder_impl(start->right);
	}

	node* delete_impl(node* start, int value) {
		if (!start)
			return NULL;

		if (value < start->data)
			start->left = delete_impl(start->left, value); // 왼쪽으로 이동
		else if (value > start->data)
			start->right = delete_impl(start->right, value); // 오른쪽으로 이동
		else {
			if (!start->left) // 왼쪽 자식 노드가 없거나 자식이 모두 없는 경우
			{
				auto tmp = start->right;
				delete start;
				return tmp; 
			}

			if (!start->right) { // 오른쪽 자식이 없는 경우
				auto tmp = start->left;
				delete start;
				return tmp;
			}

			auto succNode = successor(start);
			start->data = succNode->data;

			start->right = delete_impl(start->right, succNode->data);
		}
		return start;
	}
};

int main() {
	bst tree;

	tree.insert(12);
	tree.insert(10);
	tree.insert(20);
	tree.insert(8);
	tree.insert(11);
	tree.insert(15);
	tree.insert(28);
	tree.insert(4);
	tree.insert(2);

	cout << "중위 순회" << endl;
	tree.inorder();
	cout << endl;

	tree.deleteValue(12);
	cout << "12를 삭제한 후 중위순회 " << endl;
	
	tree.inorder();

	cout << endl;

	if (tree.find(12))
		cout << "원소 12는 트리에 있습니다. " << endl;
	else
		cout << "원소 12는 트리에 없습니다. " << endl;
}