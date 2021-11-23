#include <iostream>
#define MAX_STACK 7
using namespace std;


/*
LIFO (last in first out) -> nilai terakhir lebih dulu dilayani
push: penambahan nilai baru ke stack
pop: pengambilan elemen pada stack
CreateStack : membuat stack baru
EmptyStack : proses pengecekan stack telah terisi atau tidak
FullStack : proses cek kapasitas stack mencapai kapasitasnya
DestroyStack : mengosongkan isi dari stack
*/

struct Stack{
	int elemen[MAX_STACK];
	int top;
};

void createStack(Stack &stack){
	stack.top = -1;
}

bool isEmpty(Stack stack){
	return stack.top == -1;
}

bool isFull(Stack stack){
	return stack.top == MAX_STACK-1;
}

void push(Stack &stack, int i){
	if (isFull(stack)) return;
	
	stack.top++;
	stack.elemen[stack.top] = i;
}

void pop(Stack &stack, int &i){
	if (isEmpty(stack)) return;
	
	i = stack.elemen[stack.top];
	stack.top--;
}

int main(){
	Stack s;
	int x;
	createStack(s);
	push(s, 5);
	push(s, 10);
	push(s, 4);
	push(s, 8);
	push(s, 11);
	push(s, 13);
	push(s, 15);
	push(s, 25);
	pop(s, x);
	pop(s, x);
	push(s, 21);

	cout << "Isi stack : ";
	for(int i=s.top; i>=0; i--) cout << s.elemen[i] << " ";
	cout << "\nNilai top : " << s.top << endl;
	cout << "Nilai x   : " << x << endl;
	return 0;
}
