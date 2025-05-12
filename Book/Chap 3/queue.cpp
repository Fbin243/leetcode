#include <iostream>
using namespace std;

const int N = 100;

struct Queue {
  int data[N];
  int front = 0;
  int rear = 0;
};

int size(Queue* q) { return (q->rear - q->front + N) % N; }

bool isEmpty(Queue* q) { return q->front == q->rear; }

bool isFull(Queue* q) { return size(q) == (N - 1); }

void print(Queue* q) {
  for (int i = q->front; (i % N) != q->rear; i++) {
    cout << q->data[i % N] << " ";
  }
}

void enqueue(Queue* q, int value) {
  if (isFull(q)) {
    cout << "Queue is full !\n";
    return;
  };
  q->data[q->rear] = value;
  q->rear = (q->rear + 1) % N;
}

int dequeue(Queue* q) {
  if (isEmpty(q)) {
    cout << "Queue is empty !\n";
    return -1;
  }
  int value = q->data[q->front];
  q->front = (q->front + 1) % N;
  return value;
}

int front(Queue* q) { return q->data[q->front]; }

int main() {
  Queue* q = new Queue();
  dequeue(q);

  for (int i = 0; i < N; i++) {
    enqueue(q, i);
  }

  print(q);
  return 0;
}
