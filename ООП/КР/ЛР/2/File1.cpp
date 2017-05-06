 #pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream>
using namespace std;
class Node
{
	private:
	char name[10];	//имя узла
	Node * left;		//левая ветвь
	Node * right;	//правая ветвь
	public:
		Init(){
			Node *Tree;
			this->left=NULL;
			this->right=NULL;
		};
		AddNode(char text[10]){
			if(this->left==NULL){
				this->left=new Node;
				this->left->left=this->left->right=NULL;
				*this->left->name=text[10];

			}
				if(this->right==NULL){
				this->right=new Node;
				this->right->left=this->right->right=NULL;
				*this->right->name=text[10];

			}

		};
		DelTree(Node *&MyTree){
		   if(*&MyTree!=NULL){
			DelTree(MyTree->left);
			DelTree(MyTree->right);
			delete MyTree;
			}

		};
		Print(){
		  while(left||right){

			cout << name;


		  }

		};
};
 int _tmain(int argc, _TCHAR* argv[])
{
	Node Tree;
	Tree.Init();
	Tree.AddNode("test");
	cin.get();




}
