#include "bintree.h"
#include <string>
#include <iostream>
#include <exception>

void AddNode(SNode *node, const char *data){
	static char buffer[12] = { 0 };
	int i = 0;

	// На случай, если длина строки равна 10
	for (i = 0; i < 10 && node->name[i]; i++) buffer[i] = node->name[i];
	buffer[i] = 0;

	std::string s1(buffer), s2(data);
	// Если вставляемая строка меньше текущей
	if (s1 > s2){
		if (!node->left){
			SNode *newnode = new SNode;
			newnode->left = newnode->right = NULL;

			int i = 0;
			for (i = 0; i < 10 && data[i]; i++) newnode->name[i] = data[i];
			if (i < 10) newnode->name[i] = 0;
			node->left = newnode;
		}
		// Идти в левое поддерево
		else{ AddNode(node->left, data); }
	}
	// Если вставляемая строка больше текущей
	if (s1 < s2){
		if (!node->right){
			SNode *newnode = new SNode;
			newnode->left = newnode->right = NULL;
			
			int i = 0;
			for (i = 0; i < 10 && data[i]; i++) newnode->name[i] = data[i];
			if (i < 10) newnode->name[i] = 0;
			node->right = newnode;
		}
		// Идти в правое поддерево
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

	// Вывести имя
	for (i = 0; i < 10 && tree->name[i]; i++) buffer[i] = tree->name[i];
	buffer[i] = 0;
	std::cout << buffer << std::endl;

	// Идти в левое поддерево, если оно есть
	if (tree->left) PrintTree(tree->left);
	// Идти в правое поддерево, если оно есть
	if (tree->right) PrintTree(tree->right);
}
// Лаба 3
Node::Node(){
	Init();
}
// Лаба 3
Node::Node(const char *name){
	Init();
	int i = 0;
	for (i = 0; i < 10 && name[i]; i++) this->name[i] = name[i];
	if (i < 10) this->name[i] = 0;
	isnull = false;
}

// Лаба 3, конструктор копирования
Node::Node(const Node &node){
	if (this->left)	this->left->DelTree();	
	if (this->right) this->right->DelTree();

	memcpy(this, &node, sizeof(Node));
}

bool Node::isNull(){ return this->isnull; }
// Лаба 2
void Node::Init(){
	left = right = NULL;
	isnull = true;
	memset(name, 0, 10);
}
// Лаба 2
void Node::AddNode(const char *name){
	static char buffer[12] = { 0 };
	int i = 0;

	// На случай, если длина строки равна 10
	for (i = 0; i < 10 && this->name[i]; i++) buffer[i] = this->name[i];
	buffer[i] = 0;

	std::string s1(this->name), s2(name);
	// Если вставляемая строка меньше текущей
	if (s1 > s2){
		if (!this->left){
			this->left = new Node(name);
		}
		// Идти в левое поддерево
		else{ this->left->AddNode(name); }
	}
	// Если вставляемая строка больше текущей
	if (s1 < s2){
		if (!this->right){
			this->right = new Node(name);
		}
		// Идти в правое поддерево
		else{ this->right->AddNode(name); }
	}
}
// Лаба 2
void Node::DelTree(){
	if (this->left) this->left->DelTree();
	this->left = NULL;
	if (this->right) this->right->DelTree();
	this->right = NULL;
	void *data = this;
	delete data;
}
// Лаба 2
void Node::Print(){
	static char buffer[12] = { 0 };
	int i = 0;
	if (this->isnull){ 
		std::cout << "null" << std::endl; return; }

	// Вывести имя
	for (i = 0; i < 10 && this->name[i]; i++) buffer[i] = this->name[i];
	buffer[i] = 0;
	std::cout << buffer << std::endl;

	// Идти в левое поддерево, если оно есть
	if (this->left) this->left->Print();
	// Идти в правое поддерево, если оно есть
	if (this->right) this->right->Print();
}
//Лаба 4
Node& Node::operator=(const Node& another){
	if (this->left)	this->left->DelTree();
	if (this->right) this->right->DelTree();
	memcpy(this, &another, sizeof(Node));
	return *this;
}
//Лаба 4, оператор вставки в левое поддерево
Node& Node::operator<<(const char* name){
	if (this->left) this->left->AddNode(name);
	else{
		this->left = new Node(name);
	}
	return *this;
}
//Лаба 4, оператор вставки в правое поддерево
Node& Node::operator>(const char* name){
	if (this->right) this->right->AddNode(name);
	else{
		this->right = new Node(name);
	}
	return *this;
}
//Лаба 4, взятие узла по имени
Node& Node::getByName(const char* name){
	static char buffer[12] = { 0 };
	int i = 0;
	static Node null;

	for (i = 0; i < 10 && this->name[i]; i++) buffer[i] = this->name[i];
	buffer[i] = 0;

	std::string s1(buffer), s2(name);
	if (s1 == s2) return *this;// Вернуть текущий узел
	// Искать в левом поддереве
	if (s1>s2 && this->left) return this->left->getByName(name);
	// Искать в правом поддереве
	if (s1<s2 && this->right) return this->right->getByName(name);
	
	return null;
}
Node& Node::operator[](const char *name){
	return this->getByName(name);
}
//Лаба 4, оператор вывода дерева
std::ostream& operator<<(std::ostream& os, const Node& node){
	// Буфер для формирования Си строки
	static char buffer[12] = { 0 };
	int i = 0;
	for (i = 0; i < 10 && node.name[i]; i++) buffer[i] = node.name[i];
	buffer[i] = 0;

	os << buffer<<std::endl;
	//Распечатка левого поддерева
	if (node.left) os << *node.left;
	//Распечатка правого поддерева
	if (node.right) os << *node.right;
	return os;
}
// Лаба 3, деструктор
Node::~Node(){
	if (this->left) this->left->DelTree();
	if (this->right) this->right->DelTree();
	memset(this, 0, sizeof(Node));
}