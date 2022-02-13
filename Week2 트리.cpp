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

		auto firstFound = find(root->first, value); // ���� �켱 Ž��
		if (firstFound != NULL)
			return firstFound;

		return find(root->second, value);
	}

	// ���ο� ���Ҹ� �߰��ϴ� �Լ�
	bool addSubordinate(const string& manager, const string& subordinate) { // manager �Ʒ��� subordinate ��带 �߰��ϴ� �Լ�
		auto managerNode = find(root, manager);

		if (!managerNode) {
			cout << manager << "�� ã�� �� �����ϴ�. " << endl;
			return false;
		}

		if (managerNode->first && managerNode->second) { // managerNode�� �ڽ� ����� ����, �������� �̹� ������
			cout << manager << " �Ʒ��� " << subordinate << " �� �߰��� �� �����ϴ�. " << endl;
			return false;
		}

		if (!managerNode->first)
			managerNode->first = new node{ subordinate, NULL, NULL };
		else
			managerNode->second = new node{ subordinate, NULL, NULL };

		cout << manager << " �Ʒ��� " << subordinate << "�� �߰��߽��ϴ�. " << endl;

		return true;
	}

	// ���� ��ȸ
	static void preorder(node* start) {
		if (!start)
			return;

		cout << start->position << endl;
		preorder(start->first);
		preorder(start->second);
	}

	// ���� ��ȸ
	static void inorder(node* start) {
		if (!start)
			return;
		
		inorder(start->first);
		cout << start->position << endl;
		inorder(start->second);
	}

	// ���� ��ȸ 
	static void postorder(node* start) {
		if (!start)
			return;
		postorder(start->first);
		postorder(start->second);
		cout << start->position << endl;
	}

	// ���� ���� ��ȸ ���
	static void levelOrder(node* start) {
		if (!start)
			return;

		queue<node*> q;
		q.push(start); // ��Ʈ���

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
	
	tree.addSubordinate("CEO", "�λ���");
	tree.addSubordinate("�λ���", "IT����");
	tree.addSubordinate("�λ���", "�����ú���");
	tree.addSubordinate("IT����", "��������");
	tree.addSubordinate("IT����", "�۰�������");
	tree.addSubordinate("�����ú���", "��������");
	tree.addSubordinate("�����ú���", "ȫ������");
	tree.addSubordinate("�λ���", "�繫����");

	cout << endl;

	org_tree::levelOrder(tree.root);

	cout << endl;

	org_tree::preorder(tree.root);

	cout << endl;

	org_tree::inorder(tree.root);

	cout << endl;

	org_tree::postorder(tree.root);
}