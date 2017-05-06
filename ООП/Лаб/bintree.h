#ifndef _BINTREE_H_
#define _BINTREE_H_
#include <iostream>

// ����������� ���
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
	bool isnull; // ������� ������
	void Init();
public:
	Node();// ������ �����������
	Node(const char *name);//���� 3
	Node(const Node &node);//���� 3, ����������� �����������
	void AddNode(const char *name);
	void DelTree();
	void Print();
	bool isNull();
	~Node();//���� 3, ����������
	// ���� 4
	Node& getByName(const char* name);
	Node& operator=(const Node& another);
	Node& operator<<(const char* name);
	Node& operator>(const char* name);
	Node& operator[](const char* name);
	friend std::ostream& operator<<(std::ostream& os, const Node&);
};
#endif