#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
struct queue {
  int size;
  int front;
  int rear;
  char *Q;
};
void create(struct queue *q) {
  printf("enter the size of string you want: \n");
  scanf("%d", &q->size);
  q->Q = (char *)malloc((q->size) * sizeof(char));
}
void initialise(struct queue *q) {
  q->front = -1;
  q->rear = -1;
}
void palindrome(struct queue *q) {
  int count = 0;
  for (int i = 0; i < q->size; i++) {
    char a = q->Q[i];
    char b = q->Q[(q->size) - i - 1];
    if (toupper(a) != toupper(b)) {

      break;
    } else {
      count++;
    }
  }
  if (q->size == count) {
    printf("\nIt is a palindrome\n");
  } else {
    printf("\n It is not a palindrome\n");
  }
}
int isempty(struct queue *q) {
  if (q->front == -1) {
    return 1;
  }
  return 0;
}
void display(struct queue *q) {
  if (isempty(q)) {
    printf("no elements to display\n");
  } else if (q->front <= q->rear) {
    for (int i = (q->front); i <= (q->rear); i++) {
      printf("%c", q->Q[i]);
    }
  } else {
    for (int i = (q->front); i <= (q->size - 1); i++) {
      printf("\n%c", q->Q[i]);
    }
    for (int i = 0; i <= (q->rear); i++) {
      printf("\n%c", q->Q[i]);
    }
  }
}
int isfull(struct queue *q) {
  if (q->front == ((q->rear) + 1) % (q->size)) {
    return 1;
  } else {
    return 0;
  }
}

void insertfromrear(struct queue *q, char key) {
  if (isfull(q)) {
    printf("queue is full, cant insert\n");
  } else if (isempty(q)) {
    q->front = 0;
    q->rear++;
    q->Q[q->rear] = key;
  } else {
    q->rear = ((q->rear) + 1) % (q->size);
    q->Q[q->rear] = key;
  }
}

void insertfromfront(struct queue *q, char key) {
  if (isfull(q)) {
    printf("char cannot be inserted,  queue is full \n");
  } else if (isempty(q)) {
    q->front = 0;
    q->rear++;
    q->Q[q->front] = key;
  } else {
    if ((q->front) == 0) {
      q->front = q->size - 1;
      q->Q[q->front] = key;
    } else {
      q->front--;
      q->Q[q->front] = key;
    }
  }
}

char deletefromfront(struct queue *q) {
  if (isempty(q)) {
    printf("Queue is Empty.\n");

  } else if (q->front == q->rear) {
    char key = q->Q[q->front];
    q->front = q->rear = -1;
    return key;
  } else {
    if (q->front == ((q->size) - 1)) {
      int key = q->Q[q->front];
      q->front = 0;
      return key;
    } else {
      int key = q->Q[q->front];
      (q->front)++;
      return key;
    }
  }
}
char deletefromrear(struct queue *q) {
  {
    if (isempty(q)) {
      printf("Queue is Empty.\n");

    } else if (q->front == q->rear) {
      int key = q->Q[q->front];
      q->front = q->rear = -1;
      return key;
    } else {
      if (q->rear == 0) {
        int key = q->Q[q->rear];
        q->rear = (q->size) - 1;
        return key;
      } else {
        int key = q->Q[q->rear];
        (q->rear)--;
        return key;
      }
    }
  }
}
int main() {
  struct queue q;
  initialise(&q);
  create(&q);
  insertfromrear(&q, 'p');
  insertfromrear(&q, 'r');
  insertfromrear(&q, 'o');
  insertfromrear(&q, 'g');
  insertfromrear(&q, 'r');
 insertfromrear(&q, 'a');
 insertfromrear(&q, 'm');
 insertfromrear(&q, 'm');
  insertfromrear(&q, 'i');
   insertfromrear(&q, 'n');
    insertfromrear(&q, 'g');
  display(&q);
  palindrome(&q);

  return 0;
}