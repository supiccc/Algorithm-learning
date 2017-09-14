//
//  main.c
//  multi-queue
//
//  Created by 陈树沛 on 14/09/2017.
//  Copyright © 2017 supiccc. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

QElemType min(QElemType q1, QElemType q2, QElemType q3);

void GetNumber(int n);

int main(int argc, const char * argv[]) {
    
    clock_t start, finished;
    double times;
    start = clock();
    
    // insert code here...
    
//----------------debug-------------------
//    LinkQueue Q;
//    InitQueue(&Q);
//    EnQueue(&Q, 1);
//    QueuePtr p = Q.front;
//    while (p != Q.rear) {
//        p = p->next;
//        printf("%ld\n", p->data);
//    }
//----------------------------------------
    
//-----------start--------------------
    GetNumber(1500);
//  finished：0.000422s  2017-09-15
    
    finished = clock();
    times = (double)(finished - start)/CLOCKS_PER_SEC;
    printf("finished: %fs\n", times);
    return 0;
}

QElemType min(QElemType q1, QElemType q2, QElemType q3) {
    QElemType num = 0;
    if (q1 <= q2) {
        if (q1 <= q3) {
            num = q1;
        }
    } else {
        if (q2 <= q3) {
            num = q2;
        } else {
            num = q3;
        }
    }
    return num;
}


void GetNumber(int n){
    if (n == 1) {
        printf("%d\n", 1);
    } else {
        LinkQueue Q1;
        InitQueue(&Q1);
        EnQueue(&Q1, 2);
        LinkQueue Q2;
        InitQueue(&Q2);
        EnQueue(&Q2, 3);
        LinkQueue Q3;
        InitQueue(&Q3);
        EnQueue(&Q3, 5);
        QElemType x = 0;
        while (n > 1) {
            x = min(HeadQueue(&Q1), HeadQueue(&Q2), HeadQueue(&Q3));
            if (x == HeadQueue(&Q1)) {
                DeleteQueue(&Q1);
                EnQueue(&Q1, 2 * x);
                EnQueue(&Q2, 3 * x);
                EnQueue(&Q3, 5 * x);
            } else if (x == HeadQueue(&Q2)) {
                DeleteQueue(&Q2);
                EnQueue(&Q2, 3 * x);
                EnQueue(&Q3, 5 * x);
            } else {
                DeleteQueue(&Q3);
                EnQueue(&Q3, 5 * x);
            }
            n -= 1;
        }
        printf("%ld\n", x);
    }
}
