#include "bintree.h"
#include <string>
#include <iostream>
#include <exception>

void AddNode(SNode *node, const char *data){
	static char buffer[12] = { 0 };
	int i = 0;

	// �� ������, ���� ����� ������ ����� 10
	for (i = 0; i < 10 && node->name[i]; i++) buffer[i] = node->name[i];
	buffer[i] = 0;

	std::string s1(buffer), s2(data);
	// ���� ����������� ������ ������ �������
	if (s1 > s2){
		if (!node->left){
			SNode *newnode = new SNode;
			newnode->left = newnode->right = NULL;

			int i = 0;
			for (i = 0; i < 10 && data[i]; i++) newnode->name[i] = data[i];
			if (i < 10) newnode->name[i] = 0;
			node->left = newnode;
		}
		// ���� � ����� ���������
		else{ AddNode(node->left, data); }
	}
	// ���� ����������� ������ ������ �������
	if (s1 < s2){
		if (!node->right){
			SNode *newnode = new SNode;
			newnode->left = newnode->right = NULL;
			
			int i = 0;
			for (i = 0; i < 10 && data[i]; i++) newnode->name[i] = data[i];
			if (i < 10) newnode->name[i] = 0;
			node->right = newnode;
		}
		// ���� � ������ ���������
		else{ AddNode(node->right, data); }
	}
}
void DelTree(SNode *tree){
	if (tree->left) DelTree(tree->left);
	delete tree->left; tree->left = NULL;

	if (tree->right) DelTree(tree->right);
	delete tree->right; tree->right = NULL;
}
void PrintTree(SNode *tree){
	static char buffer[12] = { 0 };
	int i = 0;

	// ������� ���
	for (i = 0; i < 10 && tree->name[i]; i++) buffer[i] = tree->name[i];
	buffer[i] = 0;
	std::cout << buffer << std::endl;

	// ���� � ����� ���������, ���� ��� ����
	if (tree->left) PrintTree(tree->left);
	// ���� � ������ ���������, ���� ��� ����
	if (tree->right) PrintTree(tree->right);
}
// ���� 3
Node::Node(){
	Init();
}
// ���� 3
Node::Node(const char *name){
	Init();
	int i = 0;
	for (i = 0; i < 10 && name[i]; i++) this->name[i] = name[i];
	if (i < 10) this->name[i] = 0;
	isnull = false;
}

// ���� 3, ����������� �����������
Node::Node(const Node &node){
	if (this->left)	this->left->DelTree();	
	if (this->right) this->right->DelTree();

	memcpy(this, &node, sizeof(Node));
}

bool Node::isNull(){ return this->isnull; }
// ���� 2
void Node::Init(){
	left = right = NULL;
	isnull = true;
	memset(name, 0, 10);
}
// ���� 2
void Node::AddNode(const char *name){
	static char buffer[12] = { 0 };
	int i = 0;

	// �� ������, ���� ����� ������ ����� 10
	for (i = 0; i < 10 && this->name[i]; i++) buffer[i] = this->name[i];
	buffer[i] = 0;

	std::string s1(this->name), s2(name);
	// ���� ����������� ������ ������ �������
	if (s1 > s2){
		if (!this->left){
			this->left = new Node(name);
		}
		// ���� � ����� ���������
		else{ this->left->AddNode(name); }
	}
	// ���� ����������� ������ ������ �������
	if (s1 < s2){
		if (!this->right){
			this->right = new Node(name);
		}
		// ���� � ������ ���������
		else{ this->right->AddNode(name); }
	}
}
// ���� 2
void Node::DelTree(){
	if (this->left) this->left->DelTree();
	this->left = NULL;
	if (this->right) this->right->DelTree();
	this->right = NULL;
	void *data = this;
	delete data;
}
// ���� 2
void Node::Print(){
	static char buffer[12] = { 0 };
	int i = 0;
	if (this->isnull){ 
		std::cout << "null" << std::endl; return; }

	// ������� ���
	for (i = 0; i < 10 && this->name[i]; i++) buffer[i] = this->name[i];
	buffer[i] = 0;
	std::cout << buffer << std::endl;

	// ���� � ����� ���������, ���� ��� ����
	if (this->left) this->left->Print();
	// ���� � ������ ���������, ���� ��� ����
	if (this->right) this->right->Print();
}
//���� 4
Node& Node::operator=(const Node& another){
	if (this->left)	this->left->DelTree();
	if (this->right) this->right->DelTree();
	memcpy(this, &another, sizeof(Node));
	return *this;
}
//���� 4, �������� ������� � ����� ���������
Node& Node::operator<<(const char* name){
	if (this->left) this->left->AddNode(name);
	else{
		this->left = new Node(name);
	}
	return *this;
}
//���� 4, �������� ������� � ������ ���������
Node& Node::operator>(const char* name){
	if (this->right) this->right->AddNode(name);
	else{
		this->right = new Node(name);
	}
	return *this;
}
//���� 4, ������ ���� �� �����
Node& Node::getByName(const char* name){
	static char buffer[12] = { 0 };
	int i = 0;
	static Node null;

	for (i = 0; i < 10 && this->name[i]; i++) buffer[i] = this->name[i];
	buffer[i] = 0;

	std::string s1(buffer), s2(name);
	if (s1 == s2) return *this;// ������� ������� ����
	// ������ � ����� ���������
	if (s1>s2 && this->left) return this->left->getByName(name);
	// ������ � ������ ���������
	if (s1<s2 && this->right) return this->right->getByName(name);
	
	return null;
}
Node& Node::operator[](const char *name){
	return this->getByName(name);
}
//���� 4, �������� ������ ������
std::ostream& operator<<(std::ostream& os, const Node& node){
	// ����� ��� ������������ �� ������
	static char buffer[12] = { 0 };
	int i = 0;
	for (i = 0; i < 10 && node.name[i]; i++) buffer[i] = node.name[i];
	buffer[i] = 0;

	os << buffer<<std::endl;
	//���������� ������ ���������
	if (node.left) os << *node.left;
	//���������� ������� ���������
	if (node.right) os << *node.right;
	return os;
}
// ���� 3, ����������
Node::~Node(){
	if (this->left) this->left->DelTree();
	if (this->right) this->right->DelTree();
	memset(this, 0, sizeof(Node));
}