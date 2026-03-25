#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int minSum = abs(a[0] + a[1]);
    int x = a[0], y = a[1];

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = abs(a[i] + a[j]);
            if(sum < minSum) {
                minSum = sum;
                x = a[i];
                y = a[j];
            }
        }
    }

    printf("%d %d", x, y);

    return 0;
}
