#include <stdio.h>
#include <stdbool.h>
typedef struct { unsigned int hryvnias; unsigned int kopiykas; } Price;
bool inputPrice(Price* p) {
    printf("Price (hryvnias kopiykas): ");
    if(scanf("%u%u",&p->hryvnias,&p->kopiykas)!=2) return false;
    return p->kopiykas<100;
}
void printPrice(Price p) { printf("%u UAH %02u kop.\n",p.hryvnias,p.kopiykas); }
int main(){ Price p;if(!inputPrice(&p)){printf("Invalid price\n");return 1;}printPrice(p);return 0; }
