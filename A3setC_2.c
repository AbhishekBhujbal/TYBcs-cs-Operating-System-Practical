#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct process_info {
    char pname[20];
    int at, bt, ct, bt1;
    struct process_info *next;
} NODE;

NODE *first = NULL;
int n, ts, time = 0;

void add_process(char *name, int at, int bt) {
    NODE *p = (NODE *)malloc(sizeof(NODE));
    strcpy(p->pname, name);
    p->at = at;
    p->bt = p->bt1 = bt;
    p->next = NULL;
    if (!first) first = p;
  
    else{
        NODE *last=first;
        while(last->next)last=last->next;
        last->next=p;
    }
}

void round_robin() {
    int n1 = 0;
    NODE *p;
    while (n1 < n) {
        p = first;
        while (p != NULL) {
            if (p->at <= time && p->bt1 > 0) {
                int exec_time = (p->bt1 < ts) ? p->bt1 : ts;
                time += exec_time;
                p->bt1 -= exec_time;
                if (p->bt1 == 0) {
                    p->ct = time;
                    n1++;
                }
            }
            p = p->next;
        }
    }
}

void print_result() {
    NODE *p = first;
    float total_tat = 0, total_wt = 0;
    printf("pname\tat\tbt\tct\ttat\twt\n");
    while (p) {
        int tat = p->ct - p->at, wt = tat - p->bt;
        total_tat += tat;
        total_wt += wt;
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p->pname, p->at, p->bt, p->ct, tat, wt);
        p = p->next;
    }
    printf("Avg TAT=%.2f\tAvg WT=%.2f\n", total_tat / n, total_wt / n);
}

void main() {
    char pname[20];
    int at, bt;
    printf("Enter no.of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter process name, arrival time, and burst time: ");
        scanf("%s %d %d", pname, &at, &bt);
        add_process(pname, at, bt);
    }
    printf("Enter time slice: ");
    scanf("%d", &ts);
    
    round_robin();
    print_result();
     
}
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct process_info {
    char pname[20];
    int at, bt, ct, bt1;
    struct process_info *next;
} NODE;

NODE *first = NULL, *last = NULL;
int n, ts, time = 0;

void add_process(char *name, int at, int bt) {
    NODE *p = (NODE *)malloc(sizeof(NODE));
    strcpy(p->pname, name);
    p->at = at;
    p->bt = p->bt1 = bt;
    p->next = NULL;
    if (!first) first = p;
    else{
    	NODE *last=first;
	while(last->next)last=last->next;
	last->next=p;
    }
}

void print_result() {
    NODE *p = first;
    float total_tat = 0, total_wt = 0;
    printf("pname\tat\tbt\tct\ttat\twt\n");
    while (p) {
        int tat = p->ct - p->at, wt = tat - p->bt;
        total_tat += tat;
        total_wt += wt;
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p->pname, p->at, p->bt, p->ct, tat, wt);
        p = p->next;
    }
    printf("Avg TAT=%.2f\tAvg WT=%.2f\n", total_tat / n, total_wt / n);
}

void main() {
    char pname[20];
    int at, bt;
    printf("Enter no.of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter process name, arrival time, and burst time: ");
        scanf("%s %d %d", pname, &at, &bt);
        add_process(pname, at, bt);
    }
    printf("Enter time slice: ");
    scanf("%d", &ts);
    
    round_robin();
    print_result();
    
   
}
*/


/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct process_info {
    char pname[20];
    int at, bt, ct, bt1;
    struct process_info *next;
} NODE;

NODE *first = NULL, *last = NULL;
int n, ts, time = 0;

void add_process(char *name, int at, int bt) {
    NODE *p = (NODE *)malloc(sizeof(NODE));
    strcpy(p->pname, name);
    p->at = at;
    p->bt = p->bt1 = bt;
    p->next = NULL;
    if (!first) first = p;
    else last->next = p;
    last = p;
}

void accept_info() {
    char pname[20];
    int at, bt;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter process name, arrival time, and burst time: ");
        scanf("%s %d %d", pname, &at, &bt);
        add_process(pname, at, bt);
    }
    printf("Enter time slice: ");
    scanf("%d", &ts);
}

void print_result() {
    NODE *p = first;
    float total_tat = 0, total_wt = 0;
    printf("pname\tat\tbt\tct\ttat\twt\n");
    while (p) {
        int tat = p->ct - p->at, wt = tat - p->bt;
        total_tat += tat;
        total_wt += wt;
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p->pname, p->at, p->bt, p->ct, tat, wt);
        p = p->next;
    }
    printf("Avg TAT=%.2f\tAvg WT=%.2f\n", total_tat / n, total_wt / n);
}

void round_robin() {
    int completed = 0;
    NODE *p;
    while (completed < n) {
        for (p = first; p; p = p->next) {
            if (p->at <= time && p->bt1 > 0) {
                int exec_time = (p->bt1 < ts) ? p->bt1 : ts;
                time += exec_time;
                p->bt1 -= exec_time;
                if (p->bt1 == 0) {
                    p->ct = time;
                    completed++;
                }
            }
        }
    }
}

int main() {
    accept_info();
    round_robin();
    print_result();
    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct process_info {
    char pname[20];
    int at, bt, ct, bt1;
    struct process_info *next;
} NODE;

NODE *first = NULL, *last = NULL;
int n, ts, time = 0, k = 0;

void add_process(char *name, int at, int bt) {
    NODE *p = (NODE *)malloc(sizeof(NODE));
    strcpy(p->pname, name);
    p->at = at;
    p->bt = p->bt1 = bt;
    p->next = NULL;
    if (!first) first = p;
    else last->next = p;
    last = p;
}

void accept_info() {
    char pname[20];
    int at, bt;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter process name, arrival time, and burst time: ");
        scanf("%s %d %d", pname, &at, &bt);
        add_process(pname, at, bt);
    }
    printf("Enter time slice: ");
    scanf("%d", &ts);
}

void print_result() {
    NODE *p = first;
    float total_tat = 0, total_wt = 0;
    printf("pname\tat\tbt\tct\ttat\twt\n");
    while (p) {
        int tat = p->ct - p->at;
        int wt = tat - p->bt;
        total_tat += tat;
        total_wt += wt;
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p->pname, p->at, p->bt, p->ct, tat, wt);
        p = p->next;
    }
    printf("Avg TAT=%.2f\tAvg WT=%.2f\n", total_tat / n, total_wt / n);
}

void round_robin() {
    int completed = 0;
    while (completed < n) {
        NODE *p = first;
        while (p && p->at <= time && p->bt1 == 0) p = p->next;
        if (!p) { time++; continue; }

        if (p->bt1 > ts) { time += ts; p->bt1 -= ts; }
        else { time += p->bt1; p->bt1 = 0; p->ct = time; completed++; }

        NODE *temp = first;
        if (temp->bt1 == 0) first = temp->next;
        else { first = temp->next; last->next = temp; last = temp; temp->next = NULL; }
    }
}

int main() {
    accept_info();
    round_robin();
    print_result();
    return 0;
}*/

/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct process_info
{
char pname[20];
int at,bt,ct,bt1;
struct process_info *next;
}NODE;
int n,ts;
NODE *first,*last;
void accept_info()
{
NODE *p;
int i;
printf("Enter no.of process:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
 p = (NODE*)malloc(sizeof(NODE));
 printf("Enter process name:");
 scanf("%s",p->pname);
 printf("Enter arrival time:");
 scanf("%d",&p->at);
 printf("Enter first CPU burst time:");
 scanf("%d",&p->bt);
 p->bt1 = p->bt;

 p->next = NULL;
 if(first==NULL)
 first=p;
 else
 last->next=p;
 last = p;
}
printf("Enter time slice:");
scanf("%d",&ts);
}
void print_output()
{
NODE *p;
float avg_tat=0,avg_wt=0;
printf("pname\tat\tbt\tct\ttat\twt\n");
p = first;
while(p!=NULL)
{
 int tat = p->ct-p->at;
 int wt = tat-p->bt;

 avg_tat+=tat;
 avg_wt+=wt;
 printf("%s\t%d\t%d\t%d\t%d\t%d\n",
 p->pname,p->at,p->bt,p->ct,tat,wt);

 p=p->next;
}
printf("Avg TAT=%f\tAvg WT=%f\n",
 avg_tat/n,avg_wt/n);
}
void print_input()
{
NODE *p;
p = first;
printf("pname\tat\tbt\n");
while(p!=NULL)
{
 printf("%s\t%d\t%d\n",
 p->pname,p->at,p->bt1);
 p = p->next;
}
}
void sort()
{
NODE *p,*q;
int t;
char name[20];
p = first;
while(p->next!=NULL)
{
 q=p->next;
 while(q!=NULL)
 {
 if(p->at > q->at)
 {
 strcpy(name,p->pname);
 strcpy(p->pname,q->pname);
 strcpy(q->pname,name);
 t = p->at;
 p->at = q->at;
 q->at = t;

 t = p->bt;
 p->bt = q->bt;
 q->bt = t;
 t = p->ct;
 p->ct = q->ct;
 q->ct = t;
 t = p->bt1;
 p->bt1 = q->bt1;
 q->bt1 = t;
 }
 q=q->next;
 }
 p=p->next;
}
}
int time;
int is_arrived()
{
NODE *p;
p = first;
while(p!=NULL)
{
 if(p->at<=time && p->bt1!=0)
 return 1;
 p=p->next;
}
return 0;
}
NODE * delq()
{
NODE *t;
t = first;
first = first->next;
t->next=NULL;
return t;
}
void addq(NODE *t)
{
last->next = t;
last = t;
}
struct gantt_chart
{
int start;
char pname[30];
int end;
}s[100],s1[100];
int k;
void rr()
{
int prev=0,n1=0;
NODE *p;
while(n1!=n)
{
 if(!is_arrived())
 {
 time++;
 s[k].start = prev;
 strcpy(s[k].pname,"*");
 s[k].end = time;
 k++;
 prev=time;
 }
 else
 {
 p = first;
 while(1)
 {
 if(p->at<=time && p->bt1!=0)
 break;
 p = delq();
 addq(p);
 p = first;
 }
 if(p->bt1<=ts)
 {
 time+=p->bt1;
 p->bt1=0;
 }
 else
 {
 time+=ts;
 p->bt1-=ts;
 }
 p->ct = time;
 s[k].start = prev;
 strcpy(s[k].pname,p->pname);
 s[k].end = time;
 k++;
 prev = time;

 if(p->bt1==0) n1++;
 p = delq();
 addq(p);
 }
 print_input();
}
}
void print_gantt_chart()
{
int i,j,m;
s1[0] = s[0];
for(i=1,j=0;i<k;i++)
{
 if(strcmp(s[i].pname,s1[j].pname)==0)
 s1[j].end = s[i].end;
 else
 s1[++j] = s[i];
}
printf("%d",s1[0].start);
for(i=0;i<=j;i++)
{
 m = (s1[i].end - s1[i].start);
 for(k=0;k<m/2;k++)
 printf("-");
 printf("%s",s1[i].pname);
 for(k=0;k<(m+1)/2;k++)
 printf("-");
 printf("%d",s1[i].end);
}
}
int main()
{
accept_info();
sort();
rr();
print_output();
print_gantt_chart();
return 0;
}*/
