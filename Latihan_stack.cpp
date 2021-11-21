#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct node{
  int data;
  node *link;
};

node *top = NULL, *n = NULL, *x = NULL;
int jumlah = 0, nilai_pop;

//prtotype
int getOption();
bool isEmpty();
void push(int i);
void pop();
void tampil();

int main(){
  
  int pilihan,i;

    do
    {
      pilihan = getOption();

      enum option{PUSH= 1,POP, TAMPIL, FINISH};

      switch(pilihan)
      {
        case PUSH:
          system("cls");
          cout << "Masukkan nilai : ";
          cin >> i;
          push(i);
          cout << "nilai " << i << " berhasil di push. ";
        break;

        case POP:
          system("cls");
          if(isEmpty()){
            cout << "push stack lebih dulu. ";
          }
          else{
            pop();
            cout << "Nilai berhasil di pop. ";
          }
          break;

        case TAMPIL:
          system("cls");
          if(isEmpty()){
            cout << "stack kosong!" << endl;
          }
          else{
            cout << "\tISI STACK" << endl;
            cout << "=========================" << endl;
            tampil();
          }
        break;

        case FINISH:
          system("cls");
          cout << "AKHIR PROGRAM" << endl << endl;
          return 0;
          default:
          cout << "pilihan tidak ditemukan. ";
          getch();
          return main();
      }getch();     
    } while (pilihan <= 5 and pilihan >=1);

return 0;
}

void tampil(){
  x = top;
  while(x != NULL){
    cout << x->data << " ";
    x = x->link;
  }
}

void pop(){
  x = top;
  x = x->link;
  nilai_pop = top->data;
  delete top;
  top = x;
  jumlah++;
}

void push(int i){
  n = new node;
  n->data = i;
  n->link = top;
  top = n;
  jumlah = jumlah++;
}

bool isEmpty(){
  if(top == NULL)
    return true;
  else
    return false; 
}

int getOption(){
  int input;
  system("cls");
  cout << "Menu:" << endl;
  cout << "1.Push stack" << endl;
  cout << "2.Pop stack" << endl;
  cout << "3.Tampilkan" << endl;
  cout << "4.Batal" << endl;
  cout << "Pilih 1 - 4: ";
  cin >> input;

  return input;
}