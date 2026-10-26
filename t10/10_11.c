#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char surname[80];
    char city[80];
    char street[80];
    int house;
    int apartment;
} Resident;
bool inputResident(Resident* p){
    printf("Surname city street house apartment (one-word names): ");
    return scanf("%79s%79s%79s%d%d",p->surname,p->city,p->street,&p->house,&p->apartment)==5;
}
bool sameAddressDifferentCities(Resident a,Resident b){
    return strcmp(a.city,b.city)!=0 && strcmp(a.street,b.street)==0 &&
           a.house==b.house && a.apartment==b.apartment;
}
void printResident(Resident p){
    printf("%s, %s, %s %d, apartment %d\n",p.surname,p.city,p.street,p.house,p.apartment);
}
int main(){
    int n;printf("Number of residents (2..10000): ");
    if(scanf("%d",&n)!=1 || n<2 || n>10000) return 1;
    Resident* a=(Resident*)malloc(n*sizeof(Resident)); if(!a)return 1;
    for(int i=0;i<n;++i) if(!inputResident(&a[i])){free(a);return 1;}
    for(int i=0;i<n;++i)for(int j=i+1;j<n;++j){
        if(sameAddressDifferentCities(a[i],a[j])){
            printf("Found two residents:\n"); printResident(a[i]);printResident(a[j]);
            free(a);return 0;
        }
    }
    printf("No such pair\n");free(a);return 0;
}
