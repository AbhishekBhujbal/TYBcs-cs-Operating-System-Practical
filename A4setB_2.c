#include<stdio.h>
#define MAX 20
int frames[MAX], ref[MAX], mem[MAX][MAX], faults, sp, m, n, freq[MAX] = {0};

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
        if (frames[i] == pno) return i;
    return -1;
}

int find_MFU() {
    int max_freq = -1, index = 0;
    for (int i = 0; i < n; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            index = i;
        }
    }
    return index;
}

void mfu() {
    for (int i = 0; i < m; i++) {
        int pos = search(ref[i]);
        if (pos == -1) {  // Page fault
            pos = (faults < n) ? faults : find_MFU();
            frames[pos] = ref[i];
            freq[pos] = 1;
            faults++;
        } else {
            freq[pos]++;
        }
        for (int j = 0; j < n; j++)
            mem[j][i] = frames[j];
    }
}

void main() {
    accept();
    mfu();
    disp();
}

/*#include<stdio.h>
#define MAX 20

int frames[MAX],ref[MAX],mem[MAX][MAX],faults,
sp,m,n,count[MAX];

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

int get_mfu(int sp)
{
int i,max_i,max=-9999;

i=sp;
do
{
if(count[i]>max)
{
max = count[i];
max_i = i;
}
i=(i+1)%n;
}while(i!=sp);

return max_i;
}

void mfu()
{
int i,j,k;

for(i=0;i<m && sp<n;i++)
{
k=search(ref[i]);
if(k==-1)
{
frames[sp]=ref[i];
count[sp]++;
faults++;
sp++;

for(j=0;j<n;j++)
mem[j][i]=frames[j];
}
else
count[k]++;

}

sp=0;
for(;i<m;i++)
{
k = search(ref[i]);
if(k==-1)
{
sp = get_mfu(sp);
frames[sp] = ref[i];
count[sp]=1;
faults++;
sp = (sp+1)%n;

for(j=0;j<n;j++)
mem[j][i] = frames[j];
}
else
count[k]++;
}
}


int main()
{
accept();
mfu();
disp();

return 0;
}*/
