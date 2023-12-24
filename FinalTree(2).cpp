/*
	Name: FinalTree
	Copyright: 2022
	Author: Faizan Khan
	Date: 12/12/22 12:01
	Description: Created a class called FinalTree
	with member items lchild, rchild, and data.
	Also some basic tree operations and have
	an instance called June13Tree
*/

#include <iostream>
using namespace std;

// Tree items and operations
class FinalTree
{
	public:
		int data;
		FinalTree *lchild;
		FinalTree *rchild;
		FinalTree();
		FinalTree(int, FinalTree*, FinalTree*);
		FinalTree *createNode(int);
		void preOrder(FinalTree *);
		void inOrder(FinalTree *);
		void postOrder(FinalTree *);
};

// Set data value to 0, the left and right child nodes are NULL before entering input
FinalTree::FinalTree()
{
	data = 0;
	lchild = rchild = nullptr;
}

// Pass data to the data value and the left and right child nodes
FinalTree::FinalTree(int value, FinalTree *left, FinalTree *right)
{
	data = value;
	lchild = left;
	rchild = right;
}

// Set data value to 0 as no pre-existing data and get input to make the tree
FinalTree *FinalTree::createNode(int data)
{
	data = 0;
	cout << "Enter some data for the tree ";
	cin >> data;
	FinalTree *newNode = new FinalTree();
	newNode->data = data;
	newNode->lchild = newNode->rchild = nullptr;
	return newNode;
}

// The preorder transversal will start at root, then left, then right
void FinalTree::preOrder(FinalTree *root)
{
	if (root == NULL)
	{
		return;
	}
	
	cout << root->data << " ";
	preOrder(root->lchild);
	preOrder(root->rchild);
}

// The inorder transversal order is to go left, then root, then right
void FinalTree::inOrder(FinalTree *root)
{
	if (root == NULL)
	{
		return;
	}
	
	inOrder(root->lchild);
	cout << root->data << " ";
	inOrder(root->rchild);
}

// The postorder transversal order is to go left, then right, then root
void FinalTree::postOrder(FinalTree *root)
{
	if (root == NULL)
	{
		return;
	}
	
	postOrder(root->lchild);
	postOrder(root->rchild);
	cout << root->data << " ";
}

// Main function
int main()
{
	int value;
	int leftValue;
	int rightValue;
	FinalTree *root;
	
	// Level 1 (Root)
	FinalTree June13Tree(value, 0, 0);
	root = June13Tree.createNode(value);
	
	// Level 2 (Left and right node)
	FinalTree *lchild = June13Tree.createNode(leftValue);
	root->lchild = lchild;
	FinalTree *rchild = June13Tree.createNode(rightValue);
	root->rchild = rchild;
	
	// Level 3 (Left and right node children)
	lchild->lchild = June13Tree.createNode(leftValue);
	lchild->rchild = June13Tree.createNode(leftValue);	
	rchild->lchild = June13Tree.createNode(rightValue);
	rchild->rchild = June13Tree.createNode(rightValue);
	
	// Level 4 (left and right node children's children)
	lchild->lchild->lchild = June13Tree.createNode(leftValue);
	lchild->lchild->rchild = June13Tree.createNode(leftValue);
	lchild->rchild->lchild = June13Tree.createNode(leftValue);
	lchild->rchild->rchild = June13Tree.createNode(leftValue);
	rchild->lchild->lchild = June13Tree.createNode(rightValue); 
	rchild->lchild->rchild = June13Tree.createNode(rightValue);
	rchild->rchild->lchild = June13Tree.createNode(rightValue);
	rchild->rchild->rchild = June13Tree.createNode(rightValue);
	
	// Display the preorder transversal
	cout << "PreOrder: ";
	June13Tree.preOrder(root);
	cout << endl;
	
	// Display the inorder transversal
	cout << "InOrder: ";
	June13Tree.inOrder(root);
	cout << endl;
	
	// Display the postorder transversal
	cout << "PostOrder: ";
	June13Tree.postOrder(root);
	cout << endl;
	return 0;
}