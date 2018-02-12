#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int key;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = nullptr;

	return node;
}

// Function to insert given key into the tree
void insert(Node*& root, string level, int key)
{
	// tree is empty
	if (level.length() == 0)
	{
		root = newNode(key);
		return;
	}

	int i = 0;
	Node* ptr = root;
	while (i < level.length() - 1)
	{
		if (level[i++] == 'L')
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}

	if (level[i] == 'L')
		ptr->left = newNode(key);
	else
		ptr->right = newNode(key);
}

// Iterative function to print left view of given binary tree
void leftView(Node* root)
{
    // return if tree is empty
	if (root == nullptr)
		return;

    // create an empty queue and enqueue root node
    list<Node*> queue;
	queue.push_back(root);

    // pointer to store current node
	Node* curr = nullptr;

    // run till queue is not empty
	while (!queue.empty())
	{
		// calculate number of nodes in current level
		int size = queue.size();
		int i = 0;

		// process every node of current level and enqueue their
		// non-empty left and right child to queue
		while (i++ < size)
		{
			curr = queue.front();
			queue.pop_front();

			// if this is first node of current level, print it
			if (i == 1)
				cout << curr->key << " ";

			if (curr->left)
				queue.push_back(curr->left);

			if (curr->right)
				queue.push_back(curr->right);
		}
	}
}

// main function
int main()
{
	Node* root = nullptr;
	vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LR", 4}, {"RL", 5},
		{"RR", 6}, {"RLL", 7}, {"RLR", 8}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	leftView(root);

	return 0;
}
