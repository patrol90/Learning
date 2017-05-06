#include <stdio.h>
#include <string.h>
#include <iostream>

#include "bintree.h"

int main(int argc, char **argv){
	SNode *snode = new SNode;
	// Лабораторная 1
	snode->left = snode->right = 0;
	strcpy_s(snode->name, 10, "start");
	snode->name[5] = 0;
	
	setlocale(LC_ALL, "RUSSIAN");
	std::cout << "Лабораторная 1" << std::endl;
	std::cout << "Состояние дерева до вставки" << std::endl;
	PrintTree(snode);	

	AddNode(snode, "g4e3ee");
	AddNode(snode, "2393w3w9");
	AddNode(snode, "`9i3wdd");
	std::cout << "Состояние дерева после вставки" << std::endl;
	PrintTree(snode);
	// Лабораторные 2 и 3
	std::cout << "Лабораторные 2 и 3" << std::endl;
	std::cout << "Состояние дерева до вставки" << std::endl;
	Node node("lab2");
	node.Print();
	node.AddNode("ty54rrtr");
	node.AddNode("w33w0odr03w");
	node.AddNode("3w032i3");
	node.AddNode("node name");
	std::cout << "Состояние дерева после вставки" << std::endl;
	node.Print();
	// Лабораторная 4
	std::cout << "Лабораторная 4" << std::endl;
	std::cout << "node[node name]" << std::endl;
	Node node1;

	node1 = node["node name"];
	node1.Print();

	std::cout << "node[node]" << std::endl;
	
	node1 = node["node"];
	node1.Print();

	std::cout << "Состояние дерева до вставки влево" << std::endl;
	node.Print();
	
	std::cout << "Состояние дерева после вставки влево" << std::endl;
	node << "pogoda";
	node.Print();
	std::cout << "Состояние дерева после вставки вправо" << std::endl;
	node > "snow";
	node.Print();
	std::cout << "Распечатка дерева через поток ostream" << std::endl;
	std::cout << node << std::endl;

	getchar();
	return 0;
}