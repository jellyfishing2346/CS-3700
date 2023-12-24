/*
Name: Tree Data Structures
Copyright: 2022
Author: Faizan Khan
Date: 09/11/22 21:42
Description: Design a tree type to have
some member elements for the root node,
left node, and right node.
*/

#include <iostream>
using namespace std;

// This struct holds a data value and the left and right pointer nodes
struct Tree
{
int data;
Tree *left;
Tree *right;
Tree() {}
  
};

// This class handles the following tree member functions by function overload
class treeOperations
{
private:

  void insertTreeNode(int, Tree*);
  Tree *search(int);
  void destroyTreeNode(Tree *);
  void displayPreOrder(Tree *);
  void displayInOrder(Tree *);
  void displayPostOrder(Tree *);

public:
  treeOperations();
  ~treeOperations();
  void insertTreeNode(int);
  Tree *search(int, Tree*);
  void destroyTreeNode();
  void displayPreOrder();
  void displayInOrder();
  void displayPostOrder();
  Tree *root;
};

// In the constructor set the root node to null, in starting the tree
treeOperations::treeOperations()
{
	root = NULL;
}

// In the destructor, call the destroy function to dispose of the tree nodes
treeOperations::~treeOperations()
{
	destroyTreeNode();
}

// Destroy the following existing nodes in the tree 
void treeOperations::destroyTreeNode(Tree *rootPtr)
{
	// Check if the root node is not null
    if (rootPtr != NULL)
    {
		// If so, then destroy the left and right subtrees in tranversing
        destroyTreeNode(rootPtr->left);
        destroyTreeNode(rootPtr->right);
        delete rootPtr;
    }
}

// Insert a node to the tree data structure
void treeOperations::insertTreeNode(int value, Tree* root)
{
	// Check if the value is less than the root's existing element
    if (value < root->data)
    {
		// Then check if the root pointing to the left node is not null
        if (root->left != NULL)
        {
			// Insert a value to the left subtree, if the left node is not null
        	insertTreeNode(value, root->left);
        }
        else
        {
			// Set the left node as the acting root for the original root
            root->left = new Tree();
            root->left->data = value;
            root->left->left = NULL;
            root->left->right = NULL;
        }
    }

	// Check if the value is greater than the new node's existing element
    else if (value > root->data)
    {
		// Then check if the new node pointing to the right node is not null
        if (root->right != NULL)
        {
			// Insert a value to the right subtree,if the right node is not null
        	insertTreeNode(value, root->right);
        }
        else
        {
			// Set the right node as the acting root for the original root
            root->right = new Tree();
            root->right->data = value;
            root->right->left = NULL;
            root->right->right = NULL;
        }
    }
}

// Search through the tree recursively for existing notes
Tree *treeOperations::search(int value, Tree *root)
{
	// Check if the root pointer is not null
    if (root != NULL)
    {
		// If so, give the root pointer an existing element
        if (value == root->data)
        {
			// Then return the root pointer
        	return root;
        }
		// Check if the value is less than the root pointing to a data element
        if (value < root->data)
        {
			// If so, return a value for the root to point at the left node
        	return search(value, root->left);
        }
        else
        {
			// Otherwise, return a value for the root to point at the right node
        	return search(value, root->right);
        }
    }
	// If the root pointer is null, then simply return null
    else
    {
    	return NULL;
    }
}

// Insert a node to the tree
void treeOperations::insertTreeNode(int value)
{
	// Check if the root pointer is not null
    if (root != NULL)
    {
		// Then insert a node for the root
    	insertTreeNode(value, root);
    }
    else
    {
		// Otherwise the root pointer is to point at a newly inserted node value
        root = new Tree();
        root->data = value;
        root->left = NULL;
        root->right = NULL;
    }
}

// Recursively return the search for existing node values to the root
Tree *treeOperations::search(int value)
{
	return search(value, root);
}

// Calling the destroy function reservely to ensure memory is not wasted
void treeOperations::destroyTreeNode()
{
	destroyTreeNode(root);
    cout << "\nDestroying existing nodes in the tree to preserve memory\n";
}

// This function is in encharge of the preorder tranversal
void treeOperations::displayPreOrder(Tree * root)
{
	// If the root is null, then return no value
    if (root == NULL)
    {
    	return;
    }

	// The order is data->left->right
    cout << root->data << " ";
    displayPreOrder(root->left);
    displayPreOrder(root->right);
}

// Call the preorder tranversal recursively by passing the root node
void treeOperations::displayPreOrder() {
    displayPreOrder(root);
    cout << endl;
}

// This function handles the in order tranversal 
void treeOperations::displayInOrder(Tree * root)
{
	// If the root is null, then return no value
    if (root == NULL)
    {
    	return;
    }

	// The order is left->data->right
    displayInOrder(root->left);
    cout << root->data << " ";
    displayInOrder(root->right);
}

// Call the in order tranversal recursively by passing the root node
void treeOperations::displayInOrder() {
    displayInOrder(root);
    cout << endl;
}

// This function handles the post order tranversal
void treeOperations::displayPostOrder(Tree * root)
{
  // If the root is null, return no value
  if (root == NULL)
  {
  	return;
  }

  // The order is left->right->data
  displayPostOrder(root->left);
  displayPostOrder(root->right);
  cout << root->data << " ";
}

// Call the post order tranversal recursively by passing the root node
void treeOperations::displayPostOrder() {
    displayPostOrder(root);
}

// Main function
int main()
{
    // Create a class pointer
    treeOperations* tree = new treeOperations(); 

	// Root node(Level 1)
    tree->insertTreeNode(4);

	// Left node and right node(Level 2)
	tree->insertTreeNode(2);
	tree->insertTreeNode(5);

	// Left node children (Level 3)
	tree->insertTreeNode(1);
	tree->insertTreeNode(3);

	// Right node child to the right (Level 3)
	tree->insertTreeNode(7);

	// Right node descendant to the right (Level 4)
	tree->insertTreeNode(15);

	// Print the preorder tranversal for the tree
    cout << "Preorder for the tree: ";
    tree->displayPreOrder();

	// Print the inorder tranversal for the tree
    cout << "Inorder for the tree: ";
    tree->displayInOrder();

	// Print the postorder tranversal for the tree
    cout << "Postorder for the tree: ";
    tree->displayPostOrder();

	// Call the destroy function to ensure the nodes are not wasting memory
	tree->destroyTreeNode();
    system("PAUSE");
    return 0;
}