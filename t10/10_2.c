#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct { char hor; int vert; } Chessfield;
bool inputField(Chessfield* f) {
    if (scanf(" %c%d", &f->hor, &f->vert) != 2) return false;
    f->hor=(char)tolower((unsigned char)f->hor);
    return f->hor>='a' && f->hor<='h' && f->vert>=1 && f->vert<=8;
}
bool queenMove(Chessfield a, Chessfield b) {
    int dx=abs(a.hor-b.hor), dy=abs(a.vert-b.vert);
    return (dx || dy) && (dx==0 || dy==0 || dx==dy);
}
int main() {
    Chessfield a,b;
    printf("Start field (e.g. a5): "); if (!inputField(&a)) return 1;
    printf("Destination field: "); if (!inputField(&b)) return 1;
    printf("%s\n", queenMove(a,b)?"Queen can move in one turn":"Queen cannot move in one turn");
    return 0;
}
