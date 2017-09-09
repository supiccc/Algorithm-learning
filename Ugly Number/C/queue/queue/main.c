//
//  main.c
//  queue
//
//  Created by 陈树沛 on 08/09/2017.
//  Copyright © 2017 supiccc. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define OVERFLOW 0
#define ERROR 0

typedef int Status;
typedef long QElemType;

//定义一个结点内有数据域和指向下一个结点的指针域
typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

//定义一个队列含有一个头指针和一个尾指针
typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue (LinkQueue *Q);

Status DestroyQueue (LinkQueue *Q);

Status InsertQueue (LinkQueue *Q, int i, QElemType e);

long DeleteQueue (LinkQueue *Q);

int LengthQueue (LinkQueue *Q);

void UniqueEnqueue(LinkQueue *Q, QElemType x);

void GetNumber(int n);

int main() {
    clock_t start, finish;
    double times;
//    LinkQueue Q;
//    InitQueue(&Q);
//    for (int i = 0, j = 1; i < 1500; i ++, j++) {
//        InsertQueue(&Q, 1, j);
//    }
//    QueuePtr p = Q.front;
//    while (p != Q.rear) {
//        p = p->next;
//        printf("%d ", p->data);
//    }
//    printf("\n");
//    QueuePtr e = NULL;
//    e = DeleteQueue(&Q, e);
//    printf("%d\n", e->data);
//    e = DeleteQueue(&Q, e);
//    printf("%d\n", e->data);
//    e = DeleteQueue(&Q, e);
//    printf("%d\n", e->data);
    start = clock();
    GetNumber(1500);
    //finished: 0.003948s 2017-09-09
    finish = clock();
    times = (double)(finish-start)/CLOCKS_PER_SEC;
    printf("finished: %fs\n", times);
    return 0;
}

Status InitQueue (LinkQueue *Q) {
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front) {
        exit(OVERFLOW);
    }
    return OK;
}

Status DestroyQueue (LinkQueue *Q) {
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

Status InsertQueue (LinkQueue *Q, int i, QElemType e) {
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p) {
        exit(OVERFLOW);
    }
    if (i == LengthQueue(Q) + 1) {
        p->data = e;
        p->next = NULL;
        Q->rear->next = p;
        Q->rear = p;
    }
    else if (i <= LengthQueue(Q) && i > 0) {
        QueuePtr q = Q->front;
        i -= 1;
        while (i) {
            q = q->next;
            i -= 1;
        }
        p->data = e;
        p->next = q->next;
        q->next = p;
    }
    return OK;
}

long DeleteQueue (LinkQueue *Q) {
    if (Q->front == Q->rear) {
        return ERROR;
    }
    //队尾 p = Q->rear
    //队头
    QueuePtr p = Q->front->next;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    QElemType e = p->data;
    free(p);
    return e;
}

int LengthQueue (LinkQueue *Q) {
    if (Q->front == Q->rear) {
        return 0;
    }
    int count = 1;
    QueuePtr p = Q->front->next;
    while (p != Q->rear) {
        count += 1;
        p = p->next;
    }
    return count;
}

void UniqueEnqueue(LinkQueue *Q, QElemType x) {
    int i = 1;
    QueuePtr p = Q->front;
    while (p != Q->rear) {
        p = p->next;
        if (p->data < x) {
            i += 1;
        } else {
            break;
        }
    }
    if (p->data == x) {
        return;
    }
    InsertQueue(Q, i, x);
}

void GetNumber(int n){
    LinkQueue Q;
    InitQueue(&Q);
    QElemType e = 0;
    InsertQueue(&Q, 1, 1);
//    QueuePtr p = Q.front;
//    while (p != Q.rear) {
//        p = p->next;
//        printf("%d ", p->data);
//    }
//    printf("\n");
    while (n > 0) {
        e = DeleteQueue(&Q);
        QElemType a = e * 2;
        QElemType b = e * 3;
        QElemType c = e * 5;
        UniqueEnqueue(&Q, a);
        UniqueEnqueue(&Q, b);
        UniqueEnqueue(&Q, c);
        n -= 1;
    }
    printf("%ld\n", e);
}











