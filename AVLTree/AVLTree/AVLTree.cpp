#include "stdafx.h"
#include<iostream>
using namespace std;

struct node // структура для представления узлов дерева
{
	int key;
	unsigned char height;
	node* left;
	node* right;
	node(int k) { key = k; left = right = 0; height = 1; }
};



class BinaryTree {
public:
	BinaryTree() { root = NULL; }// constructor
	bool isEmpty() { return root == NULL; }
	bool isFull() { return false; }
	void preorder();
	void inorder();
	void postorder();
	void makeEmpty();
	int size() { return size_rec(root); }
	node * root;
protected:

	void preorder_rec(node *p);
	void inorder_rec(node *p);
	void postorder_rec(node *p);
	int size_rec(node *p);
	void makeEmpty_rec(node *p);
};//class BinaryTree
  //////////////////////////////////////////////////////////////////////////////////
void BinaryTree::preorder()
{
	cout << "   preorder sequence of nodes: \n";
	if (root == NULL)
		cout << "tree is empty\n";
	else {
		preorder_rec(root);
		cout << ";\n";
	}
}//preorder
void BinaryTree::preorder_rec(node *p)
{
	if (p != NULL) {
		cout << ", " << p->key;
		preorder_rec(p->left);
		preorder_rec(p->right);
	}//if 
}//preoder_rec

void BinaryTree::inorder()
{
	cout << "   inorder sequence of nodes: \n";
	if (root == NULL)
		cout << "tree is empty\n";
	else {
		inorder_rec(root);
		cout << ";\n";
	}
}//inorder
void BinaryTree::inorder_rec(node *p)
{
	if (p != NULL) {
		inorder_rec(p->left);
		cout << ", " << p->key;
		inorder_rec(p->right);
	}//if 
}//inoder_rec

void BinaryTree::postorder()
{
	cout << "   postorder sequence of nodes: \n";
	if (root == NULL)
		cout << "tree is empty\n";
	else {
		postorder_rec(root);
		cout << ";\n";
	}
}//postorder
void BinaryTree::postorder_rec(node *p)
{
	if (p != NULL) {
		postorder_rec(p->left);
		postorder_rec(p->right);
		cout << ", " << p->key;
	}//if 
}//postoder_rec
 //----------------------------------------
void BinaryTree::makeEmpty()
{
	node *p = root;
	makeEmpty_rec(p);
	root = NULL;
}//makeEmpty();
void BinaryTree::makeEmpty_rec(node *p)
{
	if (p != NULL) {
		makeEmpty_rec(p->left);
		makeEmpty_rec(p->right);
		delete p;
	}//if 
}// makeEmpty_rec(TNode *p)
 //----------------------------------------
int BinaryTree::size_rec(node *p)
{
	if (p == NULL)	return 0;
	else 		return size_rec(p->left) + size_rec(p->right) + 1;
}// size_rec



class BalancedBinarySearchTree : public BinaryTree {
protected:
	bool search_rec(int item, node *p);
	node* addNode_rec(int item, node *p);
	node* deleteNode_rec(int item, node *p);
	node* delete_NodeFound(node *p);
	node* SymmetricalBBST_rec(node* rootOrig, node* rootCopy);
	node* Add(node *p, int item);
public:
	BalancedBinarySearchTree() :BinaryTree() {}  // Base class constructor is used.
	bool search(int item);
	void deleteNode(int item);
	unsigned char height(node* p);
	int bfactor(node* p);
	void fixheight(node* p);
	node* rotateright(node* p);
	node* rotateleft(node* q);
	node* balance(node* p);
	node* insert(node* p, int k);
	node* findmin(node* p);
	node* removemin(node* p);
	node* remove(node* p, int k);
	BalancedBinarySearchTree SymmetricalBBST(BalancedBinarySearchTree D);

};//class BinarySearchTree}

bool BalancedBinarySearchTree::search(int item)
{
	return search_rec(item, root);
}//search

bool BalancedBinarySearchTree::search_rec(int item, node *p)
{
	if (p == NULL)		return false;
	if (p->key == item)	return true;
	else    	if (p->key > item)	 return search_rec(item, p->left);
	else   			return search_rec(item, p->right);
}//search_rec
 //----------------------------------------

unsigned char BalancedBinarySearchTree::height(node* p)
{
	return p ? p->height : 0;
}

int BalancedBinarySearchTree::bfactor(node* p)
{
	return height(p->right) - height(p->left);
}

void BalancedBinarySearchTree::fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl>hr ? hl : hr) + 1;
}
node* BalancedBinarySearchTree::rotateright(node* p) // правый поворот вокруг p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* BalancedBinarySearchTree::rotateleft(node* q) // левый поворот вокруг q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* BalancedBinarySearchTree::balance(node* p) // балансировка узла p
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

node* BalancedBinarySearchTree::insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
	if (!p) return new node(k);
	if (k<p->key)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balance(p);
}

node* BalancedBinarySearchTree::findmin(node* p) // поиск узла с минимальным ключом в дереве p 
{
	return p->left ? findmin(p->left) : p;
}

node* BalancedBinarySearchTree::removemin(node* p) // удаление узла с минимальным ключом из дерева p
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

node* BalancedBinarySearchTree::remove(node* p, int k) // удаление ключа k из дерева p
{
	if (!p) return 0;
	if (k < p->key)
		p->left = remove(p->left, k);
	else if (k > p->key)
		p->right = remove(p->right, k);
	else //  k == p->key 
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if (!r) return q;
		node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

void BalancedBinarySearchTree::deleteNode(int item)
{
	if (search(item))
		root = deleteNode_rec(item, root);
	else
		cout << "Item not foud: item not deleted\n";
}//deleteNode

node* BalancedBinarySearchTree::deleteNode_rec(int item, node *p)
{
	if (item < p->key)		p->left = deleteNode_rec(item, p->left);
	else    	if (item > p->key)	p->right = deleteNode_rec(item, p->right);
	else			p = delete_NodeFound(p);
	return p;
}//deleteNode_rec

node* BalancedBinarySearchTree::delete_NodeFound(node *p)  //It deletes the node referenced by p.
{
	if (p->left == NULL) {
		node* temp = p->right;
		delete p;
		return temp;
	}
	else        if (p->right == NULL) {
		node* temp = p->left;
		delete p;
		return temp;
	}
	else
	{
		node *p1 = p->right; //root of the right subtree of the node to delete
		while (p1->left != NULL)  //searching for leftmost node in the right subtree
		{
			p1 = p1->left;
		}
		p->key = p1->key; //assigning data member of the leftmost node
						  //delete leftmost node in the right subtree instead of the original node
		p->right = deleteNode_rec(p->key, p->right);
		return p;
	}//else
}//delete_NodeFound

BalancedBinarySearchTree BalancedBinarySearchTree::SymmetricalBBST(BalancedBinarySearchTree D)
{
	BalancedBinarySearchTree C;
	C.root = SymmetricalBBST_rec(D.root, C.root);
	return C;
}

node* BalancedBinarySearchTree::SymmetricalBBST_rec(node* rootOrig, node* rootCopy)
{
	if (rootCopy == NULL) {
		rootCopy = new node(rootOrig->key);
		rootCopy->left = rootCopy->right = NULL;
	}//if
	else if (rootOrig->key < rootCopy->key)
	{
		if (rootOrig->left != nullptr)			
		rootCopy->right = SymmetricalBBST_rec(rootOrig, rootCopy->right);
		else {
			rootCopy->right = Add(rootCopy->right, rootOrig->key);
		}
	}
	else 
	{
		if (rootOrig->right != nullptr)
			Add(rootCopy->left, rootOrig->key);
		else 
			rootCopy->left = Add(rootCopy->left, rootOrig->key);
	}
	if (rootOrig->left != nullptr)
		SymmetricalBBST_rec(rootOrig->left, rootCopy);
	if (rootOrig->right != nullptr)
		SymmetricalBBST_rec(rootOrig->right, rootCopy);

	return rootCopy;
}



node* BalancedBinarySearchTree::Add(node *p, int item)
{
	p = new node(item);
	p->left = p->right = NULL;
	return p;
}//addNode_rec






void main()
{
	BalancedBinarySearchTree A;
	A.root = A.insert(A.root, 15);
	A.root = A.insert(A.root, 14);
	A.root = A.insert(A.root, 16);
	A.root = A.insert(A.root, 18);

	A.postorder();
	A.preorder();
	A.inorder();
	cout << "\n";
	BalancedBinarySearchTree B = A.SymmetricalBBST(A);
	A.postorder();
	B.postorder();
	B.preorder();
}//main