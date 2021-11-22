#include <iostream>
#include <conio.h>

using namespace std;

struct Node{
int data;
Node *link;
};

Node *top=NULL, *n=NULL, *x=NULL;

void push(int i){
n = new Node;
n->data = i;
n->link = top;
top = n;
}

void pop(int &p){
if(top == NULL) return;

p = top->data;
x = top;
top = top->link;
delete(x);
x=NULL;
}

void tampil(){
x = top;
while(x!=NULL){
cout << x->data << ” “;
x = x->link;
}
}

int getJmlNode(){
x = top;
int i=0;
while(x!=NULL){
i++;
x = x->link;
}
return i;
}

bool isEmpty(){
if (top==NULL){
return true;
} else {
return false;
}
}

int main(){
int x,i;
int pilihan;
do{
system(“cls”);
cout<<“menu qeue “<<endl;
cout<<“1. push data”<<endl;
cout<<“2. pop data”<<endl;
cout<<“3. Tampil”<<endl;
cout<<“masukkan pilihan : [1….3]”;
cin>>pilihan;

system(“cls”);
switch (pilihan){

case 1: {
cout<<“masukkan nilai untuk di push : “<<endl;
cin>>i;
push(i);
cout<<“data dengan nilai : “<<i<<“berhasil di push”<<endl;
break;
}
case 2: {
if (top==NULL){
cout<<“data masih kosong”<<endl;
} else {
cout<<“nilai berhasil di pop”<<endl;
pop(i);
}
break;
}
case 3: {
if (top==NULL){
cout<<“data masih kosong”<<endl;
} else {
cout<<“menampilkan isi data :”<<endl;
cout<<“======================”<<endl;
tampil();
}
break;
}
} getch();
} while (pilihan >=1 && pilihan<=3);
}
