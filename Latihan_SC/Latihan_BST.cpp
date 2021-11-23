#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *root=NULL, *n=NULL, *temp=NULL;

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

void inOrder(Node *root){
	if (root==NULL) return;
	
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void inOrderDesc(Node *root){
	if (root==NULL) return;
	inOrderDesc(root->right);
	cout << root->data << " ";
	inOrderDesc(root->left);
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
			hapus(root->right, data);
		}
	}
}

bool isEmpty(){
	if (root==NULL){
		return true;
} else {
	return false;
}
}

int main(){
	int pilihan,n,num,temp;
	do{
	system("cls");
	cout<<"menu pilihan : "<<endl;
	cout<<"1. Masukkan Node"<<endl;
	cout<<"2. Tampilkan dalam bentuk levelOrder"<<endl;
	cout<<"3. Tampilkan dalam bentuk preOrder"<<endl;
	cout<<"4. Tampilkan dalam bentuk inOrder"<<endl;
	cout<<"5. Tampilkan dalam bentuk inOrder desc"<<endl;
	cout<<"6. Tampilkan dalam bentuk postOrder"<<endl;
	cout<<"7. Cari NOde"<<endl;
	cout<<"8. Hapus Node"<<endl;
	cout<<"9. exit"<<endl;
	cout<<"MASUKKAN PILIHAN [1....9] : ";
	cin>>pilihan;
	
	system("cls");
	switch(pilihan)
	
	{
		case 1: {
			
			cout<<"masukkan node baru"<<endl;
			cout<<"=============="<<endl;
			cout<<"masukkan nilai"<<endl;
			cin>>n;
			insert(root,n);
			cout<<"berhasil "<<endl;

			break;
		}
		case 2: {
			if(isEmpty()){
				cout<<"node belum dibuat"<<endl;
			} else {
				cout<<"menampilkan dalam bentuk levelorder"<<endl;
				cout<<"==================="<<endl;
				levelOrder();
				cout<<"\n";
				cout<<endl;
			}
			break;
		}
		case 3: {
			if(isEmpty()){
				cout<<"node belum dibuat"<<endl;
			} else {
				cout<<"menampilkan dalam bentuk preorder"<<endl;
				cout<<"==================="<<endl;
				preOrder(root);
				cout<<endl;
			}
			break;
		}
		case 4: {
			if(isEmpty()){
				cout<<"node belum dibuat"<<endl;
			} else {
				cout<<"menampilkan dalam bentuk inorder"<<endl;
				cout<<"==================="<<endl;
				inOrder(root);
				cout<<endl;
			}
			break;
		}
		case 5: {
			if(isEmpty()){
				cout<<"node belum dibuat"<<endl;
			} else {
				cout<<"menampilkan dalam bentuk inorder  (desc)"<<endl;
				cout<<"==================="<<endl;
				inOrderDesc(root);
				cout<<endl;
			break;
		}
		case 6: {
			if(isEmpty()){
				cout<<"node belum dibuat"<<endl;
			} else {
				cout<<"menampilkan dalam bentuk postorder"<<endl;
				cout<<"==================="<<endl;
				postOrder(root);
				cout<<endl;
			break;
		}
		case 7: {
			if(isEmpty()){
				cout<<"node belum dibuat"<<endl;
			} else {
				cout<<"masukkan nilai node yang ingin dicari"<<endl;
				cout<<"==================="<<endl;
				cin>>n;
				cari(root,n);
				cout<<"node dengan nilai : "<<n<<" berhasil ditemukan"<<endl;
			break;
		}
		case 8: {
			if(isEmpty()){
				cout<<"node belum dibuat"<<endl;
			} else {
				cout<<"masukkan nilai node yang akan dihapus"<<endl;
				cout<<"==================="<<endl;
				cin>>n;
				hapus(root,n);
				cout<<"node : "<<n<<" berhasi di hapus "<<endl;
			break;
		}
	}
	}
	}	
	}
	} system("pause");
	} while(pilihan>=1 && pilihan<=8);
}

