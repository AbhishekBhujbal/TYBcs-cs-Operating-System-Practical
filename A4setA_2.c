#include <stdio.h>
#define MAX 20

int frames[MAX], ref[MAX], mem[MAX][MAX], faults, m, n;
int counter[MAX], time = 0;  

void accept() {
    printf("Enter no.of frames: ");
    scanf("%d", &n);
    printf("Enter no.of references: ");
    scanf("%d", &m);
    printf("Enter reference string:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &ref[i]);
}

void disp() {
    for (int i = 0; i < m; i++)
        printf("%3d", ref[i]);
    printf("\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%3d", mem[i][j] ? mem[i][j] : ' ');
        printf("\n");
    }
    printf("Total Page Faults: %d\n", faults);
}

int search(int pno) {
    for (int i = 0; i < n; i++)
        if (frames[i] == pno)
            return i;
    return -1;
}

int findLRU() {
    int min = time, pos = 0;
    for (int i = 0; i < n; i++) {
        if (counter[i] < min) {
            min = counter[i];
            pos = i;
        }
    }
    return pos;
}

void lru() {
    for (int i = 0; i < m; i++) {
        int pos = search(ref[i]);

        if (pos == -1) {  
            pos = findLRU();  
            frames[pos] = ref[i];
            faults++;
        }

        counter[pos] = ++time; 

        for (int j = 0; j < n; j++)
            mem[j][i] = frames[j]; 
    }
}

void main() {
    accept();
    lru();
    disp();
}


/*#include<stdio.h>
#define MAX 20

int frames[MAX],ref[MAX],mem[MAX][MAX],faults,sp,m,n,time[MAX];
void accept()
{
int i;
printf("Enter no.of frames:");
scanf("%d", &n);
printf("Enter no.of references:");
scanf("%d", &m);
printf("Enter reference string:\n");
for(i=0;i<m;i++)
{
printf("[%d]=",i);
scanf("%d",&ref[i]);
}
}
void disp()
{
int i,j;
for(i=0;i<m;i++)
printf("%3d",ref[i]);
printf("\n\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
if(mem[i][j])
printf("%3d",mem[i][j]);
else
printf(" ");
}
printf("\n");
}
printf("Total Page Faults: %d\n",faults);
}
int search(int pno)
{
int i;
for(i=0;i<n;i++)
{

if(frames[i]==pno)
return i;
}
return -1;
}
int get_lru()
{
int i,min_i,min=9999;
for(i=0;i<n;i++)
{
if(time[i]<min)
{
min = time[i];
min_i = i;
}
}
return min_i;
}

void lru()
{
int i,j,k;
for(i=0;i<m && sp<n;i++)
{
k=search(ref[i]);
if(k==-1)
{
frames[sp]=ref[i];
time[sp]=i;
faults++;
sp++;
for(j=0;j<n;j++)
mem[j][i]=frames[j];
}
else
time[k]=i;
}
for(;i<m;i++)
{
k = search(ref[i]);
if(k==-1)
{
sp = get_lru();

frames[sp] = ref[i];
time[sp] = i;
faults++;
for(j=0;j<n;j++)
mem[j][i] = frames[j];
}
else
time[k]=i;
}
}

int main()
{
accept();
lru();
disp();
return 0;
}*/

