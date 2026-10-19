#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
typedef struct Mountain { char name[128]; double height; } Mountain;
bool inputMountain(Mountain* m) {
    printf("Name (one word) and height: ");
    return scanf("%127s%lf",m->name,&m->height)==2;
}
void printMountain(Mountain m){printf("%s: %.2f m\n",m.name,m.height);}
int highest(const Mountain* a,int n){
    int best=0;
    for(int i=1;i<n;++i) if(a[i].height>a[best].height) best=i;
    return best;
}
int findByName(const Mountain* a,int n,const char* name){
    for(int i=0;i<n;++i) if(strcmp(a[i].name,name)==0) return i;
    return -1;
}
int main(){
    int n;printf("Number of mountains (1..10000): ");
    if(scanf("%d",&n)!=1 || n<1 || n>10000) return 1;
    Mountain* a=(Mountain*)malloc(n*sizeof(Mountain));if(!a)return 1;
    for(int i=0;i<n;++i) if(!inputMountain(&a[i])){free(a);return 1;}
    printf("Highest mountain: ");printMountain(a[highest(a,n)]);
    char query[128];printf("Mountain name to find: ");
    if(scanf("%127s",query)!=1){free(a);return 1;}
    int index=findByName(a,n,query);
    if(index==-1) printf("Mountain not found\n");else printMountain(a[index]);
    free(a);return 0;
}
