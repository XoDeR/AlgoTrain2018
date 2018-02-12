#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int data;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
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

// Function to print root to leaf paths without using recursion
void printTopToBottomPath(unordered_map<int, int> parent, int key)
{
	while (key = parent[key])
		cout << key << " ";

	cout << endl;
}

// iterative function to set parent nodes for all nodes of binary tree
// in given map. The function is similar to iterative pre-order traversal
void setParent(Node* root, unordered_map<int, int> &parent)
{
	// create an empty stack and push root node to it
	stack<Node*> stack;
	stack.push(root);

	// run till stack is not empty
	while (!stack.empty())
	{
		// Pop the top item from stack
		Node* curr = stack.top();
		stack.pop();

		// push its right child to stack and set its parent in the map
		if (curr->right)
		{
			parent[curr->right->data] = curr->data;
			stack.push(curr->right);
		}

		// push its left child to stack and set its parent in the map
		if (curr->left)
		{
			parent[curr->left->data] = curr->data;
			stack.push(curr->left);
		}
	}
}

// Iterative function to print all ancestors of given node in a binary tree
void printAncestors(Node* root, int node)
{
    // Base Case
	if (root == nullptr)
		return;

    // create a empty map to store parent pointers of binary tree nodes
	unordered_map<int, int> parent;

	// set parent of root node as null
	parent[root->data] = 0;

    // set parent nodes for all nodes of binary tree
    setParent(root, parent);

    // print ancestors of given node using parent map
	printTopToBottomPath(parent, node);
}

// main function
int main()
{
	Node* root = nullptr;

	/* Construct below tree
		  1
		/   \
	   /	 \
	  2	      3
	   \	 / \
	    4   5   6
           / \
          7   8
    */

    vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LR", 4},
		{"RL", 5}, {"RR", 6}, {"RLL", 7}, {"RRR", 8}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	int node = 7;
	printAncestors(root, node);

	return 0;
}
