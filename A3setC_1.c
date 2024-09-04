#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct process_info {
    char pname[20];
    int at, bt, ct, bt1, proc;//
    struct process_info *next;
} NODE;

NODE *first = NULL;
int n, time = 0, k = 0;

void add_process(char *name, int at, int bt, int proc) {//
    NODE *p = (NODE *)malloc(sizeof(NODE));
    strcpy(p->pname, name);
    p->at = at;
    p->bt = p->bt1 = bt;
    p->proc = proc;//
    p->next = NULL;
    if (!first) first = p;
    else {
        NODE *last = first;
        while (last->next) last = last->next;
        last->next = p;
    }
}

NODE *get_priority() {//
    NODE *p = first, *min_p = NULL;
    int min = 9999;
    while (p) {
        if (p->at <= time && p->bt1 > 0 && p->proc < min) {//
            min = p->proc;//
            min_p = p;
        }
        p = p->next;
    }
    return min_p;
}

void priority() {
    int n1 = 0;
    while (n1 < n) {
        NODE *p = get_priority();
        if (!p) time++;  
        else {
            time++;  
            p->bt1--;  
            if (p->bt1 == 0) {
                p->ct = time; 
                n1++;
            }
        }
    }
}
void print_result() {
    NODE *p = first;
    float total_tat = 0, total_wt = 0;
    printf("pname\tat\tbt\tpri\tct\ttat\twt\n");//
    while (p) {
        int tat = p->ct - p->at, wt = tat - p->bt;
        total_tat += tat;
        total_wt += wt;
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->pname, p->at, p->bt, p->proc, p->ct, tat, wt);//
        p = p->next;
    }
    printf("Avg TAT=%.2f\tAvg WT=%.2f\n", total_tat / n, total_wt / n);
}

void main() {
    char pname[20];
    int at, bt, proc;//
    printf("Enter no.of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter process name, arrival time, burst time, and priority: ");//
        scanf("%s %d %d %d", pname, &at, &bt, &proc);//
        add_process(pname, at, bt, proc);//
    }
    priority();
    print_result();
}
