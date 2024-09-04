#include <stdio.h>
#define MAX 20

int frames[MAX], ref[MAX], mem[MAX][MAX], faults, m, n;

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
int predict(int current_ref) {
    int farthest = current_ref, index = -1;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = current_ref + 1; j < m; j++) {
            if (frames[i] == ref[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == m)  
            return i;
    }
    return (index == -1) ? 0 : index;
}

void opt() {
    for (int i = 0; i < m; i++) {
        if (search(ref[i]) == -1) {  
            if (faults < n)  
                frames[faults] = ref[i];
            else {  
                int pos = predict(i);
                frames[pos] = ref[i];
            }
            faults++;
            for (int j = 0; j < n; j++)
                mem[j][i] = frames[j];  
        }
    }
}

void main() {
    accept();
    opt();
    disp();
   
}


/*#include<stdio.h>
int main()
{
int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max,
faults = 0;
printf("Enter number of frames: ");
scanf("%d", &no_of_frames);

printf("Enter number of pages: ");
scanf("%d", &no_of_pages);

printf("Enter page reference string: ");

for(i = 0; i < no_of_pages; ++i){
scanf("%d", &pages[i]);
}

for(i = 0; i < no_of_frames; ++i){
frames[i] = -1;
}

for(i = 0; i < no_of_pages; ++i){
flag1 = flag2 = 0;

for(j = 0; j < no_of_frames; ++j){
if(frames[j] == pages[i]){
flag1 = flag2 = 1;
break;
}
}

if(flag1 == 0){
for(j = 0; j < no_of_frames; ++j){
if(frames[j] == -1){
faults++;
frames[j] = pages[i];
flag2 = 1;
break;
}
}
}

if(flag2 == 0){
flag3 =0;

for(j = 0; j < no_of_frames; ++j){
temp[j] = -1;

for(k = i + 1; k < no_of_pages; ++k){
if(frames[j] == pages[k]){
temp[j] = k;
break;
}
}
}

for(j = 0; j < no_of_frames; ++j){
if(temp[j] == -1){
pos = j;
flag3 = 1;
break;
}
}

if(flag3 ==0){
max = temp[0];
pos = 0;

for(j = 1; j < no_of_frames; ++j){
if(temp[j] > max){
max = temp[j];
pos = j;
}
}
}
frames[pos] = pages[i];
faults++;
}

printf("\n");

for(j = 0; j < no_of_frames; ++j){
printf("%d\t", frames[j]);
}
}

printf("\n\nTotal Page Faults = %d", faults);

return 0;
}*/
