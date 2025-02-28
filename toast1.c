#include <stdio.h>

int main() {
    int n, k, l, c, d, p, nl, np;
    scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);

    int total_drink = k * l;           // Total băutură (ml)
    int total_slices = c * d;          // Total felii de lămâie
    int total_salt = p;                // Total sare (g)

    // Resurse necesare pentru un toast pe persoană
    int drink_per_toast = n * nl;      // Băutură necesară pentru n prieteni
    int slices_per_toast = n * 1;      // 1 felie per persoană
    int salt_per_toast = n * np;       // Sare necesară pentru n prieteni

    int max_toasts = 0;

    // Calculează numărul maxim de toasturi posibile
    while (total_drink >= drink_per_toast &&
           total_slices >= slices_per_toast &&
           total_salt >= salt_per_toast) {
        max_toasts++;
        total_drink -= drink_per_toast;
        total_slices -= slices_per_toast;
        total_salt -= salt_per_toast;
    }

    printf("%d\n", max_toasts);
    return 0;
}
