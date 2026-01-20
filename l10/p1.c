#include <stdio.h>
#include <math.h>

typedef struct comp {
    int re, im;
} com;

com adunare(com c1, com c2) {
    com c3;
    c3.re = c1.re + c2.re;
    c3.im = c1.im + c2.im;
    return c3;
}

com scadere(com c1, com c2) {
    com c3;
    c3.re = c1.re - c2.re;
    c3.im = c1.im - c2.im;
    return c3;
}

com inmultire(com c1, com c2) {
    com c3;
    c3.re = c1.re * c2.re - c1.im * c2.im;
    c3.im = c1.re * c2.im + c1.im * c2.re;
    return c3;
}

double modul(com c) {
    // Formula: sqrt(re^2 + im^2)
    double res = sqrt((double)c.re * c.re + (double)c.im * c.im);
    return res;
}

int main() {
    com c1, c2, r;
    
    printf("Enter c1 (re im) and c2 (re im): ");
    // Added & for scanf to pass the memory addresses
    if (scanf("%d %d %d %d", &c1.re, &c1.im, &c2.re, &c2.im) != 4) {
        return 1;
    }

    r = adunare(c1, c2);
    printf("Suma: %d + %di\n", r.re, r.im);

    r = scadere(c1, c2);
    printf("Diferenta: %d + %di\n", r.re, r.im);

    r = inmultire(c1, c2);
    printf("Produs: %d + %di\n", r.re, r.im);

    // Modul returns a double, not a 'com' struct
    double m = modul(c1);
    printf("Modul c1: %.2f\n", m);
    
    return 0;
}
