#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *head = NULL, *tail = NULL,*n = NULL, *x = NULL;

int getOption(){
	int input;
	
	system("cls");
	cout << "Menu:" << endl;
	cout << "1. Buat Node Awal" << endl;
	cout << "2. Tambah Node" << endl;
	cout << "3. Hapus Node" << endl;
	cout << "4. Tampil Data" << endl;
	cout << "5. Keluar\n" << endl;
	cout << "Masukkan pilihan [1..5] :";
	cin >> input;
	return input;
}

bool isEmpty(){
	if (head == NULL)
		return true;
	else
		return false;
}

void tambahDepan(int i){
	n = new Node;
	n->data = i;
	n->next = head;
	head = n;
}
//create node awal
void nodeBaru(int i){
	n = new Node;
	n->data = i;
	head = n;
	tail = n;
	tail->next = NULL;
}

void tambahDepan(int i){
	
}

int main(){
	int pilihan,i;
	
	do
	{
		pilihan = getOption();
		enum option{BUAT=1,TAMBAH,HAPUS,TAMPIL,KELUAR};
		
		switch(pilihan)
		{
			case BUAT:
				system("cls");
					if(isEmpty()){
						cout << "Buat Node Awal" << endl;
						cout << "==============\n" << endl;
						cout << "Masukkkan Nilai : ";
						cin >> i;
						nodeBaru(i);
						cout << "Nilai " << i << " Berhasil Dimasukkan ke node awal. ";	
					}
					else{
						cout << "Node awal sudah dibuat...";
					}
				break;
			case TAMBAH:
				system("cls");
					if(isEmpty()){
						cout << "Node awal belum dibuat. ";
					}
					else{
						cout << "pilihan:" << endl;
						cout << "1. Tambah Node Depan" << endl;
						cout << "2. Tambah Node Tengah" << endl;
						cout << "3. Tambah Node Belakang" << endl;
						cout << "4. Batal\n" << endl;
						cout << "Pilih 1 - 4 : ";
						cin >> pilihan;
						
					}
				break;
			case HAPUS:
				system("cls");
				break;
			case TAMPIL:
				system("cls");
				break;
			case KELUAR:
				exit(0);
			default:
				cout << "Pilihan tidak ditemukan. ";	
		}getch();		
	}while(pilihan >= 1 and pilihan <=5);
	
return 0;
}








