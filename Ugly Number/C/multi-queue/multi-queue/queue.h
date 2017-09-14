//
//  queue.h
//  queue
//
//  Created by 陈树沛 on 11/09/2017.
//  Copyright © 2017 supiccc. All rights reserved.
//

#ifndef queue_h
#define queue_h

typedef int Status;
typedef long QElemType;


#define OK 1
#define OVERFLOW 0
#define ERROR 0

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

Status EnQueue (LinkQueue *Q, QElemType e);

long DeleteQueue (LinkQueue *Q);

long HeadQueue (LinkQueue *Q);

int LengthQueue (LinkQueue *Q);

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

Status EnQueue (LinkQueue *Q, QElemType e) {
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p) {
        exit(OVERFLOW);
    }
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return  OK;
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

long HeadQueue (LinkQueue *Q) {
    if (Q->front == Q->rear) {
        return ERROR;
    }
    QueuePtr p = Q->front->next;
    QElemType e = p->data;
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


#endif /* queue_h */
