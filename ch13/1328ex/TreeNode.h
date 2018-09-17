#include <iostream>

using namespace std;

class TreeNode{
public:
	TreeNode();
	TreeNode(const TreeNode& t);
	~TreeNode();

private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree{
public:
	BinStrTree();
	BinStrTree(const BinStrTree& b);
	~BinStrTree();
private:
	TreeNode *root;
};


TreeNode::TreeNode()
{

}

TreeNode::TreeNode(const TreeNode& t)
{
	
}

TreeNode::~TreeNode()
{

}

BinStrTree::BinStrTree()
{
	
}
