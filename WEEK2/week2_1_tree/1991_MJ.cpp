#include <iostream>
#include <queue>

using namespace std;

struct node { // 이진트리를 위한 기본 구조
	string position; 
	node* first;
	node* second;
};

struct org_tree {
	node* root;

	// 루트 노드를 생성하는 함수
	static org_tree create_org_structure(const string& pos) {
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	}

	static node* find(node* root, const string& value) { // 팀섹(현재 노드이거나 서브트리에 있으므로 순서대로 탐색)
		if (root == NULL) return NULL;
		if (root->position == value) return root;

		auto firstFound = org_tree::find(root->first, value);

		if (firstFound != NULL) return firstFound;

		return org_tree::find(root->second, value);
	}

	bool addSub(const string& manager, const string& sub, int LR) {
		auto managerNode = org_tree::find(root, manager);

		if (!managerNode) {
			return false;
		}

		if (managerNode->first && managerNode->second) {
			return false;
		}

		if (!managerNode->first && LR==0) {
			managerNode->first = new node{ sub, NULL, NULL }; // 왼쪽 서브트리가 없으면 왼쪽에 추가
		}
		else if (!managerNode->second && LR == 1) {
			managerNode->second = new node{ sub, NULL, NULL }; // 오른쪽 서브트리가 ㅇ없으면 오른쪽에 추가
		}
		return true;
	}
};

static void preOrder(node* start) { // preOrde : 전위순회 : 현재노드 -> 왼쪽 서브 노드 -> 오른쪽 서브 노드
	if (!start) return;

	cout << start->position;
	preOrder(start->first);
	preOrder(start->second);
}

static void inOrder(node* start) { // in-Order : 중위 순회 :왼쪽 노드 -> 현재 노드 -> 오른쪽 노드
	if (!start) return;

	inOrder(start->first);
	cout << start->position;
	inOrder(start->second);
}

static void postOrder(node* start) { // post order : 후위 순회 : 두 자식 노드 먼저 방문 -> 현재 노드
	if (!start) return;

	postOrder(start->first);
	postOrder(start->second);
	cout << start->position;
}

int main() {
	int N; // node
	cin >> N;
	string alp[3];
	auto tree = org_tree::create_org_structure("A");

	while (N>0) {
		for (int i = 0; i < 3; i++) {
			cin >> alp[i];
			if (i == 2) {
				if (alp[1] != ".")
					tree.addSub(alp[0], alp[1], 0);
				if (alp[2] != ".")
					tree.addSub(alp[0], alp[2], 1);
			}
			
		}
		N--;
	}

	preOrder(tree.root);
	cout << endl;
	inOrder(tree.root);
	cout << endl;
	postOrder(tree.root);

	return 0;
}