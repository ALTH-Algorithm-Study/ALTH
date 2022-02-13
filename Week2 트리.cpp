#include <iostream>
#include <queue>
using namespace std;

struct node {
	string position;
	node* first;
	node* second;
};

struct org_tree {
	node* root;

	static org_tree create_org_structure(const string& pos) {
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	} // init tree

	static node* find(node* root, const string& value) {
		if (root == NULL) {
			return NULL;
		}
		if (root->position == value)
			return root;

		auto firstFound = find(root->first, value); // 왼쪽 우선 탐색
		if (firstFound != NULL)
			return firstFound;

		return find(root->second, value);
	}

	// 새로운 원소를 추가하는 함수
	bool addSubordinate(const string& manager, const string& subordinate) { // manager 아래에 subordinate 노드를 추가하는 함수
		auto managerNode = find(root, manager);

		if (!managerNode) {
			cout << manager << "을 찾을 수 없습니다. " << endl;
			return false;
		}

		if (managerNode->first && managerNode->second) { // managerNode의 자식 노드의 왼쪽, 오른쪽이 이미 있으면
			cout << manager << " 아래에 " << subordinate << " 를 추가할 수 없습니다. " << endl;
			return false;
		}

		if (!managerNode->first)
			managerNode->first = new node{ subordinate, NULL, NULL };
		else
			managerNode->second = new node{ subordinate, NULL, NULL };

		cout << manager << " 아래에 " << subordinate << "를 추가했습니다. " << endl;

		return true;
	}

	// 전위 순회
	static void preorder(node* start) {
		if (!start)
			return;

		cout << start->position << endl;
		preorder(start->first);
		preorder(start->second);
	}

	// 중위 순회
	static void inorder(node* start) {
		if (!start)
			return;
		
		inorder(start->first);
		cout << start->position << endl;
		inorder(start->second);
	}

	// 후위 순회 
	static void postorder(node* start) {
		if (!start)
			return;
		postorder(start->first);
		postorder(start->second);
		cout << start->position << endl;
	}

	// 레벨 순서 순회 방법
	static void levelOrder(node* start) {
		if (!start)
			return;

		queue<node*> q;
		q.push(start); // 루트노드

		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				auto current = q.front();
				q.pop();
				cout << current->position << ", "; 
				if (current->first)
					q.push(current->first);
				if (current->second)
					q.push(current->second);
			}
			cout << endl;
		}
	}
};


int main() {
	auto tree = org_tree::create_org_structure("CEO"); // root is CEO
	
	tree.addSubordinate("CEO", "부사장");
	tree.addSubordinate("부사장", "IT부장");
	tree.addSubordinate("부사장", "마케팅부장");
	tree.addSubordinate("IT부장", "보안팀장");
	tree.addSubordinate("IT부장", "앱개발팀장");
	tree.addSubordinate("마케팅부장", "물류팀장");
	tree.addSubordinate("마케팅부장", "홍보팀장");
	tree.addSubordinate("부사장", "재무부장");

	cout << endl;

	org_tree::levelOrder(tree.root);

	cout << endl;

	org_tree::preorder(tree.root);

	cout << endl;

	org_tree::inorder(tree.root);

	cout << endl;

	org_tree::postorder(tree.root);
}