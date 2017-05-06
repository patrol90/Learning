#include <stdio.h>
#include <string.h>
#include <iostream>

#include "bintree.h"

int main(int argc, char **argv){
	SNode *snode = new SNode;
	// ������������ 1
	snode->left = snode->right = 0;
	strcpy_s(snode->name, 10, "start");
	snode->name[5] = 0;
	
	setlocale(LC_ALL, "RUSSIAN");
	std::cout << "������������ 1" << std::endl;
	std::cout << "��������� ������ �� �������" << std::endl;
	PrintTree(snode);	

	AddNode(snode, "g4e3ee");
	AddNode(snode, "2393w3w9");
	AddNode(snode, "`9i3wdd");
	std::cout << "��������� ������ ����� �������" << std::endl;
	PrintTree(snode);
	// ������������ 2 � 3
	std::cout << "������������ 2 � 3" << std::endl;
	std::cout << "��������� ������ �� �������" << std::endl;
	Node node("lab2");
	node.Print();
	node.AddNode("ty54rrtr");
	node.AddNode("w33w0odr03w");
	node.AddNode("3w032i3");
	node.AddNode("node name");
	std::cout << "��������� ������ ����� �������" << std::endl;
	node.Print();
	// ������������ 4
	std::cout << "������������ 4" << std::endl;
	std::cout << "node[node name]" << std::endl;
	Node node1;

	node1 = node["node name"];
	node1.Print();

	std::cout << "node[node]" << std::endl;
	
	node1 = node["node"];
	node1.Print();

	std::cout << "��������� ������ �� ������� �����" << std::endl;
	node.Print();
	
	std::cout << "��������� ������ ����� ������� �����" << std::endl;
	node << "pogoda";
	node.Print();
	std::cout << "��������� ������ ����� ������� ������" << std::endl;
	node > "snow";
	node.Print();
	std::cout << "���������� ������ ����� ����� ostream" << std::endl;
	std::cout << node << std::endl;

	getchar();
	return 0;
}