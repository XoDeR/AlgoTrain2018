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

// Function to find next node of given node in the same level 
// in given binary tree
Node* findRightNode(Node* root, int val)
{
    // return null if tree is empty
	if (root == nullptr)
		return nullptr;

    // create an empty queue and enqueue root node
	list<Node*> queue;
	queue.push_back(root);

    // pointer to store current node
	Node* front = nullptr;

    // run till queue is not empty
	while (!queue.empty())
	{
		// calculate number of nodes in current level
		int size = queue.size();

		// process every node of current level and enqueue their
		// non-empty left and right child to queue
		while (size--)
		{
			front = queue.front();
			queue.pop_front();

			// if desired node is found, return its next right node
			if (front->key == val)
			{
				// if next right node doesn't exists, return null
			    if (queue.empty())
                    return nullptr;
			    return queue.front();
			}

			if (front->left)
				queue.push_back(front->left);

			if (front->right)
				queue.push_back(front->right);
		}
	}

	return nullptr;
}


// main function
int main()
{
	Node* root = nullptr;
	/* Construct below Tree
	          1
	        /  \
	       /    \
	      2      3
	     / \      \
	    4   5      6
	              / \
                 7   8
	*/
	vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LL", 4}, {"LR", 5},
		{"RL", 6}, {"RLL", 7}, {"RLR", 8}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

    Node *right = findRightNode(root, 5);
	if (right)
        cout << "Right Node is " << right->key;
	else
        cout << "Right Node doesn't exists";

	return 0;
}
