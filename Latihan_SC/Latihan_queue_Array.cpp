#include <iostream>
#include <conio.h>
#define MAX_QUEUE 5

using namespace std;

struct Queue{
	int elemen[1000];
	int front;
	int rear;
	int jml;
};

void createQueue(Queue &queue){
	queue.front = 0;
	queue.rear  = -1;
	queue.jml   = 0;
}

bool isEmpty(Queue queue){
	return queue.jml == 0;
}

bool isFull(Queue queue){
	return queue.jml == MAX_QUEUE;
}

void enQueue(Queue &queue, int i){
	if (isFull(queue)) return;
	
	queue.rear++;
	queue.jml++;
	queue.elemen[queue.rear] = i;
}

void deQueue(Queue &queue, int &i){
	if (isEmpty(queue)) return;
	
	i = queue.elemen[queue.front];
	queue.front++;
	queue.jml--;
}


int main(){
	int pilihan, i;
	Queue q;

	do{
		system("cls");
		cout << "Implementasi Queue dengan Array" << endl;
		cout << "===============================\n" << endl;
		cout << "Menu:" << endl;
		cout << "1. Enqueue Data" << endl;
		cout << "2. Dequeue Data" << endl;
		cout << "3. Tampil Isi Queue" << endl;
		cout << "4. Kosongkan Queue" << endl;
		cout << "5. Keluar" << endl;
		cout << "Masukkan pilihan [1..5] :";
		cin >> pilihan;

		enum option{ENQUEUE=1, DEQUEUE,TAMPIL,KOSONG,KELUAR};

		switch(pilihan)
		{
			case ENQUEUE:
			system("cls");
				if(isFull(q)){
					cout << "Queue penuh, enqueue dibatalkan...";
				}
				else{
					cout << "Enqueue" << endl;
					cout << "=======" << endl;
					cout << "Masukkan data:";
					cin >> i;
					enQueue(q,i);
					cout << "nilai " << i << " berhasil dimasukkan. ";
				}
			break;
			case DEQUEUE:
			system("cls");
			cout << "test";
			break;
			case TAMPIL:
			system("cls");
			cout << "test";
			break;
			case KOSONG:
			system("cls");
			cout << "test";
			break;
			case KELUAR:
				system("cls");
				cout << "AKHIR PROGRAM" << endl;
				cout << "=============" << endl;
				return 0;
			default:
			cout << "Pilihan tidak ditemukan. ";
			getch();
			return main();
		}getch();
	}while (pilihan >= 1 and pilihan <= 5);
return 0;
}
