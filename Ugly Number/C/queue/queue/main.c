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
#include "queue.h"

void UniqueEnqueue(LinkQueue *Q, QElemType x);

void GetNumber(int n);

int main() {
//--------------debug-------------------------------
//      LinkQueue Q;
//      InitQueue(&Q);
//      for (int i = 0, j = 1; i < 1500; i ++, j++) {
//          InsertQueue(&Q, 1, j);
//      }
//      QueuePtr p = Q.front;
//      while (p != Q.rear) {
//          p = p->next;
//          printf("%ld ", p->data);
//      }
//      printf("\n");
//-----------------------------------------------------
 //----------------start---------------------------------
    clock_t start, finish;
    double times;
    start = clock();
    GetNumber(1500);
    //finished: 0.003948s 2017-09-09
    finish = clock();
    times = (double)(finish-start)/CLOCKS_PER_SEC;
    printf("finished: %fs\n", times);
    return 0;
//-----------------finished--------------------------------
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











