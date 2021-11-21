#include <iostream>
#include <conio.h>

/* nama: Yusman
	kelas: A5 (TI)
*/

using namespace std;

struct node{
  int data;
  node *link;
};

node *top = NULL, *n = NULL, *x = NULL;

int jumlah = 0, nilai_pop;

int isEmpty(){
	if(top == NULL)
		return true;
	else
		return false;
}

void push(int i){
	n = new node;
	n->data = i;
	n->link = top;
	top = n;
	jumlah = jumlah++;
}

void pop(){
	x = top;
	x = x->link;
	nilai_pop = top->data;
	delete top;
	top = x;
	jumlah = jumlah++;
}

void tampil(){
	x = top;
	while(x != NULL){
		cout << x->data << " -> ";
		x = x->link;
	}
}

int main(){

  int pilihan, i;
	enum option{PUSH=1,POP,TAMPIL,KELUAR};
		
	do
	{
		system("cls");
	  cout << "Pilihan" << endl;
	  cout << "1. Push stack" << endl;
	  cout << "2. pop stack" << endl;
	  cout << "3. Tampil stack" << endl;
	  cout << "4. keluar" << endl;
	  cout << "Pilih 1 - 4 : ";
	  cin >> pilihan;
		
		switch(pilihan)
		{
			case PUSH:
				system("cls");
				cout << "Masukkan nilai : ";
				cin >> i;
				push(i);
				cout << "nilai " << i << " berhasil di push ke stack. ";				
				break;
			case POP:
				system("cls");
				if(isEmpty()){
					cout << "Isi stack kosong. ";
				}
				else{
					pop();
					cout << "Nilai top berhasil di pop. ";
				}
				break;
			case TAMPIL:
				system("cls");
				if(isEmpty()){
					cout << "Isi stack kosong";
				}
				else{
					cout << "\tISI STACK" << endl;
					cout << "==========================" << endl;
					tampil();
				}
				break;
			case KELUAR:
				system("cls");
				cout << "AKHIR PROGRAM"<< endl;
				cout << "============="<< endl;
				getch();
				return 0;
				break;
			default:
				cout << "pilihan tidak ditemukan. ";
			 	getch();
			 	return main();
		}getch();		
	}while(pilihan <=4 and pilihan >=1);
		  
  return 0;
}















