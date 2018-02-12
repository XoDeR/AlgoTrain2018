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

// Function to find diameter of the binary tree. Note that the function
// returns the height of the subtree rooted at given node and diameter
// is updated within the function as it is passed by reference
int getDiameter(Node* root, int &diameter)
{
    // base case: tree is empty
	if (root == nullptr)
		return 0;

    // get heights of left and right subtrees
	int left_height = getDiameter(root->left, diameter);
	int right_height = getDiameter(root->right, diameter);

	// calculate diameter "through" the current node
	int max_diameter = left_height + right_height + 1;

	// Update Maximum Diameter (Note that diameter "excluding" the current
    // node in subtree rooted at current node is already updated as we're
    // doing postorder traversal)
	diameter = max(diameter, max_diameter);

	// important - return height of subtree rooted at current node
	return max(left_height, right_height) + 1;
}

int getDiameter(Node* root)
{
	int diameter = 0;
	getDiameter(root, diameter);

	return diameter;	
}

// main function
int main()
{
	Node* root = nullptr;
	vector<pair<string, int> > keys =
	{
        {"", 1}, {"L", 2}, {"R", 3}, {"LR", 4},
        {"RL", 5}, {"RR", 6}, {"RLL", 7}, {"RLR", 8}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	cout << "The diameter of the tree is " << getDiameter(root);

	return 0;
}
