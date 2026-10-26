#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
typedef struct { int numerator; unsigned int denominator; } Rational;
long long gcdll(long long a,long long b) {
    if(a<0) a=-a;
    while(b){ long long t=a%b; a=b; b=t; }
    return a?a:1;
}
bool normalize(long long n,long long d,Rational* r) {
    if(d<=0) return false;
    long long g=gcdll(n,d);n/=g;d/=g;
    if(n<INT_MIN || n>INT_MAX || (unsigned long long)d>UINT_MAX) return false;
    r->numerator=(int)n;r->denominator=(unsigned int)d;return true;
}
bool sum(Rational a,Rational b,Rational* r) {
    return normalize((long long)a.numerator*b.denominator+(long long)b.numerator*a.denominator,
                     (long long)a.denominator*b.denominator,r);
}
bool product(Rational a,Rational b,Rational* r) {
    return normalize((long long)a.numerator*b.numerator,(long long)a.denominator*b.denominator,r);
}
int compare(Rational a,Rational b) {
    long long left=(long long)a.numerator*b.denominator;
    long long right=(long long)b.numerator*a.denominator;
    return (left>right)-(left<right);
}
void printR(Rational a) { printf("%d/%u",a.numerator,a.denominator); }
int main() {
    Rational a,b,s,p;
    printf("First fraction (numerator denominator): ");
    if(scanf("%d%u",&a.numerator,&a.denominator)!=2 || !a.denominator) return 1;
    printf("Second fraction: ");
    if(scanf("%d%u",&b.numerator,&b.denominator)!=2 || !b.denominator) return 1;
    if(normalize(a.numerator,a.denominator,&s)){printf("Reduced first: ");printR(s);printf("\n");}
    if(normalize(b.numerator,b.denominator,&p)){printf("Reduced second: ");printR(p);printf("\n");}
    if(sum(a,b,&s)){printf("Sum: ");printR(s);printf("\n");}else printf("Sum exceeds Rational range\n");
    if(product(a,b,&p)){printf("Product: ");printR(p);printf("\n");}else printf("Product exceeds Rational range\n");
    printf("Comparison: %d\n",compare(a,b));
    return 0;
}
