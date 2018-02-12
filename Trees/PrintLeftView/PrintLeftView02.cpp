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

// traverse nodes in reverse pre-order
/*
void leftView(Node *root, int level, auto &map)
{
	if (root == nullptr)
		return;

    // insert the current node and level information into the map
	map[level] = root->key;

	// recurse for right subtree before left subtree
	leftView(root->right, level + 1, map);
	leftView(root->left, level + 1, map);
}
*/

// traverse nodes in pre-order fashion
void leftView(Node *root, int level, auto &map)
{
	if (root == nullptr)
		return;

    // if level is visited for the first time, insert the current node
    // and level information into the map
	if (map.find(level) == map.end())
        map[level] = root->key;

	leftView(root->left, level + 1, map);
    leftView(root->right, level + 1, map);
}

// Function to print left view of given binary tree
int leftView(Node *root)
{
    // create an empty map to store first node for each level
	map<int, int> map;

	// traverse the tree and fill map
	leftView(root, 1, map);

	// iterate through the map and print left view
	for (auto it: map)
		cout << it.second << " ";
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
