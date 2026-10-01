#include <stdio.h>

int main() {
    int prev, curr;
    int sign_changes = 0;

    printf("Enter a number (0 to exit): ");
    scanf("%d", &prev);

    if (prev != 0) {
        do {
            printf("Enter a number (0 to exit): ");
            scanf("%d", &curr);

            if (curr != 0) {
                if ((prev > 0 && curr < 0) || (prev < 0 && curr > 0)) {
                    sign_changes++;
                }
                prev = curr;
            }
        } while (curr != 0);
    }

    printf("Number of sign changes: %d\n", sign_changes);

    return 0;
}