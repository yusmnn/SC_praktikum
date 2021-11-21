#include <iostream>
#include <conio.h>

using namespace std;

struct node{
	int data;
	node *next;
};

node *head = NULL, *tail=NULL, *x=NULL, *n=NULL;

/*prototype*/
int getOption();
bool isEmpty();
int getJmlNode();
//create
void createNode(int i);
//insert
void addNodeFront(int i);
void addNodeMidle(int i,int j);
void addNodeLast(int i);
//delete
void deleteNodeFront();
void deleteNodeMidle(int i);
void deleteNodelast();
//read
void readNode();

int main(){
	int pilihan,i,j;
	
	do
	{
		
		pilihan = getOption();
		
		enum option{CREATE=1, INSERT, DELETE, READ, FINISH};
		
		switch(pilihan)
		{
			
			case CREATE:
				if(isEmpty()){
					cout << "Masukkan nilai" << endl;
					cout << "==============" << endl;
					cin >> i;
					createNode(i);
					cout << "nilai " << i << " berhasil dimasukkan ke node awal.";					
				}				
				else
					cout << "Node awal sudah dibuat" << endl;
				break;				
			case INSERT:
				if(isEmpty())
					cout << "Node awal belum dibuat" << endl;
				else{
					cout << "1. Tambah node depan" << endl;
					cout << "2. Tambah node tengah" << endl;
					cout << "3. Tambah node belakang" << endl;
					cout << "4. Batal" << endl;
					cout << "\npilih 1 - 4 : ";
					cin >> pilihan;
					if(pilihan == 1){
						system("cls");
						cout << "Tambah node di depan" << endl;
						cout << "====================" << endl;
						cout << "Masukkan nilai : "; cin >> i;
						cout << endl;
						addNodeFront(i);
						cout << "nilai " << i << " berhasil dimasukkan di node paling depan.";
						break;
					}
					else if(pilihan == 2){
						if(getJmlNode() == 1)
							cout << "Tambah node di tengah gagal, Isi Node minimal 2" << endl;
						else{
							system("cls");
							cout << "Tambah node di tengah" << endl;
							cout << "=====================" << endl << endl;
							cout << "Node dimasukkan setelah node dengan nilai : "; cin >> j;
							cout << "masukkan nilai node baru                  : "; cin >> i; 
							addNodeMidle(i,j);
							cout << endl;
							cout << "nilai " << i << " berhasil dimasukkan di node tengah.";							
						}
						break;
					}
					else if(pilihan == 3){
						system("cls");
						cout << "Tambah Node di belakang" << endl;
						cout << "=======================" << endl;
						cout << "Masukkan nilai node : "; cin >> i;
						addNodeLast(i);
						cout << endl;
						cout << "Nilai " << i << " Berhasil dimasukkan ke node belakang.";						
						break;
					}
					else if(pilihan == 4){
						system("cls");
						break;
					}
					else
					system("cls");
					cout << "PIlihan tidak ditemukan" << endl;				
				}
				break;
				
			case DELETE:
				system("cls");
				if(isEmpty()){
					cout << "Node awal belum dibuat.";
				}
				else{
					system("cls");
					cout << "1. Hapus node depan" << endl;
					cout << "2. Hapus node tengah" << endl;
					cout << "3. Hapus node belakang" << endl;
					cout << "4. Batal" << endl;
					cout << "Pilih 1 - 4 : "; cin >> pilihan;
					
					if(pilihan == 1){
						system("cls");
						deleteNodeFront();
						cout << "Node paling depan berhasil dihapus.";
						break;
					}
					else if(pilihan == 2){
						system("cls");
						cout << "Masukkan nilai pada node yang akan dihapus : ";
						cin >> i;
						deleteNodeMidle(i);
						cout << "Node dengan nilai " << i << " berhasil dihapus.";						
						break;
					}
					else if(pilihan == 3){
						system("cls");
						deleteNodelast();
						cout << "Node paling akhir berhasil di hapus.";
						break;
					}
					else if(pilihan == 4){
						system("cls");
						break;
					}
					else{
						system("cls");
						cout << "Pilihan tidak ditemukan." << endl;
					}					
				}
				break;
				
			case READ:
				if(isEmpty()){
					cout << "Linked List masih kosong" << endl;
				}
				else{
					cout << "\t ISI NODE" << endl;
					cout << "============================" << endl << endl;
					readNode();					
				}
				break;
				
			case FINISH:
				system("cls");
				cout << "AKHIR PROGRAM" << endl;
				cout << "=============" << endl;
				return 0;
				break;
				
			default:
				cout << "Pilihan tidak ditemukan" << endl;
			
		}getch();
		
	}while(pilihan >= 1 and pilihan <=5);
	
	return 0;
}


//fungsi melihat jumlsh node
int getJmlNode(){
	x = head;
	int i=0;
	while(x!=NULL){
		i++;
		x = x->next;
	}
	return i;
}

//Fungsi CREATE
void createNode(int i){
	n = new node;
	n->data = i;
	tail = n;
	head = n;
	tail->next = NULL;
}

//2. fungsi INSERT
void addNodeFront(int i){
	n = new node;
	n->data = i;
	n->next = head;
	head = n;
}

void addNodeMidle(int i,int j){
	x = head;
	while (x->data != j) x = x->next;
	n = new node;
	n->data = i;
	n->next = x->next;
	x->next = n;
}

void addNodeLast(int i){
	n = new node;
	n->data = i;
	tail->next = n;
	tail = n;
	tail->next = NULL;
}

//3. fungsi DELETE
void deleteNodeFront(){
	x = head;
	head = head->next;
	delete x;
	x = NULL;
}

void deleteNodeMidle(int i){
	node *temp = NULL;
	x = head;
	while(x->data != i){
		temp = x;
		x = x->next;
	}
	temp->next = x->next;
	delete (x);
	x = NULL;
}

void deleteNodelast(){
	x = head;
	while(x->next != tail) x = x->next;
	tail = x;
	delete (x->next);
	tail->next = NULL;
}

//4. fungsi READ
void readNode(){
	x = head;
	while(x != NULL){
		cout << x->data;
		cout << " -> ";
		x = x->next;
	}
}

// fungsi node kosong
bool isEmpty(){
	if ( head==NULL){
		return true;
	}else {
		return false;
	}
}

// PILIHAN
int getOption(){
	int i;
	system("cls");
	cout << "Menu:" << endl;
	cout << "1. Buat node" << endl;
	cout << "2. Tambah node" << endl;
	cout << "3. Hapus node" << endl;
	cout << "4. Tampil node" << endl;
	cout << "5. Keluar" << endl;
	cout << "Pilih 1 - 5 : ";
	cin >> i;
	system("cls");
	return i;
}
