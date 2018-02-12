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

// Helper function to print given doubly linked list
void printDLL(Node* &head)
{
	Node* curr = head;
	while (curr != nullptr)
	{
		cout << curr->data << " ";
		curr = curr->right;
	}
}

// Function to in-place convert given Binary Tree to a Doubly Linked List
// by doing reverse inorder traversal
void convert(Node* root, Node* &head)
{
    // base case: tree is empty
	if (root == nullptr)
		return;

    // recursively convert right subtree first
	convert(root->right, head);

	// insert current node in the beginning of DLL
	root->right = head;

	if (head != nullptr)
		head->left = root;

	head = root;

    // recursively convert left subtree
    convert(root->left, head);
}

// in-place convert given Binary Tree to a Doubly Linked List
void convert(Node* root)
{
    // head of doubly linked list
	Node* head = nullptr;

	// convert above binary tree to DLL
	convert(root, head);

	// print list
	printDLL(head);
}

// main function
int main()
{
	/* Construct below tree
		  1
		/   \
	   /	 \
	  2	      3
	 / \	 / \
	4   5   6   7
    */

    vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LL", 4}, {"LR", 5},
		{"RL", 6}, {"RR", 7}
	};

	Node* root = nullptr;
    for (auto pair: keys)
		insert(root, pair.first, pair.second);

    convert(root);

	return 0;
}
