#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int a[n], temp[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);

    k = k % n;

    for(int i = 0; i < n; i++) {
        temp[(i + k) % n] = a[i];
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}
