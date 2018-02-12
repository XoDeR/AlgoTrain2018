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

// root -> current node
// head -> head of the doubly linked list (Passed by reference)
// prev -> previous processed node (Passed by reference)
void convert(Node* curr, Node*& head, Node* &prev)
{
    // base case: tree is empty
    if (curr == nullptr)
		return;

    // recursively convert left subtree first
	convert(curr->left, head, prev);

	// adjust pointers
	if (prev != nullptr)
	{
	    // set current node's left child to prev
		curr->left = prev;

		// make prev's right child as curr
		prev->right = curr;
	}

    // if prev is null, then update head of DLL as this is first node in inorder
	else
		head = curr;

    // after current node is visited, update previous pointer to current node
	prev = curr;

    // recursively convert right subtree
	convert(curr->right, head, prev);
}

// in-place convert given Binary Tree to a Doubly Linked List
void convert(Node* root)
{
    // to keep track of previous processed node in inorder traversal
	Node* prev = nullptr;

	// convert above binary tree to DLL (using inorder traversal)
    convert(root, root, prev);

    // root is now head of doubly linked list

    // print list
	printDLL(root);
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
