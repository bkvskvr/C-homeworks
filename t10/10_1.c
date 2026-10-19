#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

struct Date { int year; int month; int day; };
typedef struct Date Date;
typedef struct Chessfield_ { char hor; unsigned char vert; } Chessfield;
typedef struct { double x, y; } Point;
typedef struct { Point a, b; } Rect;
typedef struct { int degree; double* a; } Polynomial;

bool inputDate(Date* d) {
    printf("Input year, month, day: ");
    return scanf("%d%d%d", &d->year, &d->month, &d->day) == 3;
}
void printDate(Date d) { printf("%d-%d-%d\n", d.year, d.month, d.day); }
bool inputChessfield(Chessfield* f) {
    printf("Chess field (e.g. a5): ");
    int v;
    if (scanf(" %c%d", &f->hor, &v) != 2) return false;
    if (v < 1 || v > 8) return false;
    f->vert = (unsigned char)v;
    f->hor = (char)tolower((unsigned char)f->hor);
    return f->hor >= 'a' && f->hor <= 'h' && f->vert >= 1 && f->vert <= 8;
}
void printChessfield(Chessfield f) { printf("%c%d\n", f.hor, f.vert); }
bool inputPoint(Point* p) { return scanf("%lf%lf", &p->x, &p->y) == 2; }
void printPoint(Point p) { printf("(%.2f, %.2f)", p.x, p.y); }
bool inputRect(Rect* r) {
    printf("Two opposite vertices (x1 y1 x2 y2): ");
    return inputPoint(&r->a) && inputPoint(&r->b);
}
void printRect(Rect r) { printPoint(r.a); printf(" - "); printPoint(r.b); printf("\n"); }
bool inputPolynomial(Polynomial* p) {
    printf("Polynomial degree (0..1000): ");
    if (scanf("%d", &p->degree) != 1 || p->degree < 0 || p->degree > 1000) return false;
    p->a = (double*)malloc((p->degree + 1) * sizeof(double));
    if (!p->a) return false;
    for (int i=0; i<=p->degree; ++i) {
        printf("a[%d]: ", i);
        if (scanf("%lf", &p->a[i]) != 1) { free(p->a); p->a = NULL; return false; }
    }
    return true;
}
void printPolynomial(const Polynomial* p) {
    for (int i=p->degree; i>=0; --i) {
        printf("%s(%.3f)*x^%d", i==p->degree?"":" + ", p->a[i], i);
    }
    printf("\n");
}
int main() {
    Date d; Chessfield f; Rect r; Polynomial poly={0,NULL};
    if (inputDate(&d)) printDate(d); else return 1;
    if (inputChessfield(&f)) printChessfield(f); else { printf("Invalid chess field\n"); return 1; }
    if (inputRect(&r)) printRect(r); else return 1;
    if (inputPolynomial(&poly)) { printPolynomial(&poly); free(poly.a); }
    else { printf("Invalid polynomial or memory allocation failed\n"); return 1; }
    return 0;
}
