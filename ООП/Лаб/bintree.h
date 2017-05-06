#ifndef _BINTREE_H_
#define _BINTREE_H_
#include <iostream>

// Структурный тип
struct SNode
{
	char name[10];
	SNode *left;
	SNode *right;
};

void AddNode(SNode *node, const char *data);
void DelTree(SNode *tree);
void PrintTree(SNode *tree);

class Node
{
private:
	char name[10];
	Node *left;
	Node *right;
	bool isnull; // Нулевой объект
	void Init();
public:
	Node();// Пустой конструктор
	Node(const char *name);//Лаба 3
	Node(const Node &node);//Лаба 3, конструктор копирования
	void AddNode(const char *name);
	void DelTree();
	void Print();
	bool isNull();
	~Node();//Лаба 3, деструктор
	// Лаба 4
	Node& getByName(const char* name);
	Node& operator=(const Node& another);
	Node& operator<<(const char* name);
	Node& operator>(const char* name);
	Node& operator[](const char* name);
	friend std::ostream& operator<<(std::ostream& os, const Node&);
};
#endif