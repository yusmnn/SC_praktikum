#include <bits/stdc++.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct Node{ 
  int data;
  Node *left;
  Node *right;
};

Node *root = NULL, *n = NULL, *temp = NULL;

int getOption(){
	int input;
	system("cls");
	cout << "Menu: " << endl;
	cout << "1. Insert Node" << endl;
	cout << "2. Pencarian data" << endl;
	cout << "3. Hapus Node" << endl;
	cout << "4. Binary tree traversal" << endl;
	cout << "5. Keluar" << endl;
	cout << "Masukkan Pilihan 1 - 5 : ";
	cin >> input;
	return input;
}

bool isEmpty(){
	if(root == NULL)
		return true;
	else
	return false;
}

Node *createNode(int data){
	n = new Node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void insert(Node *&root, int data){
	if (root==NULL)
		root = createNode(data);
	else if (data <= root->data)
		insert(root->left, data);
	else if (data > root->data)
		insert(root->right, data);
}

void levelOrder(){
	if (root==NULL) return;

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
	cout << q.front()->data << " ";
		if(q.front()->left != NULL)
			q.push(q.front()->left);
		if(q.front()->right != NULL)
			q.push(q.front()->right);
			q.pop();
	}
}

void preOrder(Node *root){
	if (root==NULL) return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder_asc(Node *root){
	if (root==NULL) return;
	inOrder_asc(root->left);
	cout << root->data << " ";
	inOrder_asc(root->right);
}

void inOrder_Desc(Node *root){
	if (root==NULL) return;
	inOrder_Desc(root->right);
	cout << root->data << " ";
	inOrder_Desc(root->left);
}

void postOrder(Node *root){
	if (root==NULL) return;
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " ";
}

bool cari(Node *root, int data){
	if (root==NULL)
		return false;
	else if(data < root->data)
		return cari(root->left, data);
	else if(data > root->data)
		return cari(root->right, data);
	else
		return true;
}

Node *cariMin(Node *root){
	if (root==NULL)
		return NULL;
	while(root->left != NULL)
		root = root->left;
	return root;
}

void hapus(Node *&root, int data){
	if (root==NULL)
		return;
	else if(data < root->data)
		return hapus(root->left, data);
	else if(data > root->data)
		return hapus(root->right, data);
	else{
	// kasus I
	if (root->left == NULL && root->right == NULL){
		delete(root);
		root=NULL;
		}
		// kasus II
	else if (root->left == NULL){
		temp = root;
		root = root->right;
		delete(temp);
		temp=NULL;
		}
		else if (root->right == NULL){
		temp = root;
		root = root->left;
		delete(temp);
		temp=NULL;
	}
	// kasus III
	else{
		temp = cariMin(root->right);
		root->data = temp->data;
		hapus(root->right, root->data);
		}
	}
}

int main(){
	int pilihan, i, temp;
	
	do
	{
		pilihan = getOption();
		
		switch(pilihan)
		{
			case 1:
				system("cls");
				cout << "masukkan data: ";
				cin >> i;
				insert(root,i);
				cout << "Data " << i << " berhasil dimasukkan ";
				break;
			case 2:
				system("cls");
				if(isEmpty()){
					cout << "Tree Masih Kosong ";
				}
				else{
					cout << "Masukkan data yang akan dicari:";
					cin >> temp;
					if(temp == root->data){// parameter masih salah
						cari(root,temp);				
						cout << "data " << temp << " berhasil di temukan";				
					}
					else{
						cout << "data " << temp << " tidak ditemukan ";
					}					
				}
				break;
			case 3:
				system("cls");
				if(isEmpty()){
					cout << "Tree Masih Kosong ";
				}
				else{
					cout << "Masukkan data yang akan dihapus:";
					cin >> temp;
					if(temp == root->data){//parameter masih salah	
						hapus(root,temp);		
						cout << "data " << temp << " berhasil dihapus";				
					}
					else{
						cout << "data " << temp << " tidak ditemukan ";
					}					
				}
				break;
			case 4:
				system("cls");
				if(isEmpty()){
					cout << "Tree masih Kosong..";
				}
				else{
					cout << "Binary Tree Traversal" << endl;
					cout << "====================" << endl;
					cout << "1. Level order" << endl;
					cout << "2. Preorder" << endl;
					cout << "3. Inorder (ASC)" << endl;
					cout << "4. Inorder (DESC)" << endl;
					cout << "5. Postorder" << endl;
					cout << "6. Batal" << endl;
					cout << "Masukkan pilihan [1..6] : ";
					cin >> pilihan;
					system("cls");
					if(pilihan == 1){
						cout << "Binary Tree Traversal" << endl;
						cout << "==================" << endl;
						cout << "Level order: ";
						levelOrder();
					}
					else if(pilihan == 2){
						cout << "Binary Tree Traversal" << endl;
						cout << "==================" << endl;
						cout << "PreOrder : ";
						preOrder(root);
					}
					else if(pilihan == 3){
						cout << "Binary Tree Traversal" << endl;
						cout << "==================" << endl;
						cout << "InOrder (ASC) : ";
						inOrder_asc(root);
					}				
					else if(pilihan == 4){
						cout << "Binary Tree Traversal" << endl;
						cout << "==================" << endl;
						cout << "InOrder (DESC) : ";
						inOrder_Desc(root);
					}
					else if(pilihan == 5){
						cout << "Binary Tree Traversal" << endl;
						cout << "==================" << endl;
						cout << "PostOrder : ";
						postOrder(root);
					}
					else if(pilihan == 6){
					return main();
					}
					else{
						cout << "Pilihan tidak ditemukan ";
						getch();
						return main();
					}
				}				
				break;
			case 5:
				exit(0);
			default:
				cout << "Pilihan tidak ditemukan";
				getch();
				return main();		
		}getch();	
	}while(pilihan >= 1 && pilihan <= 5);
  return 0;
}


















