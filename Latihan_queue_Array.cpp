#include <iostream>
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
	Queue q;
	int x;
	createQueue(q);
	enQueue(q, 10);
	enQueue(q, 2);
	enQueue(q, 3);
	deQueue(q, x);
	enQueue(q, 15);
	enQueue(q, 17);
	enQueue(q, 22);
	enQueue(q, 25);
	deQueue(q, x);
	deQueue(q, x);
	enQueue(q, 21);
	
	cout << "Isi Queue     : ";
	for(int i=q.rear; i>=q.front; i--) cout << q.elemen[i] << " ";
	cout << "\nNilai front   : " << q.front << endl;
	cout << "Nilai rear    : " << q.rear << endl;
	cout << "Nilai jml item: " << q.jml << endl;
	cout << "Nilai x       : " << x << endl;
	
}
