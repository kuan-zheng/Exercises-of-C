#include <stdio.h>

void linear_probing(int m, int n, int b[]) {
    int hash = m % n;
    int i = 0;
    while (i < n && b[(hash + i) % n] != -1) {
        i++;
    }
    b[(hash + i) % n] = m;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n], b[n], c[n];
    
    for (int i = 0; i < n; i++) {
        b[i] = -1;
        a[i] = -1;
        c[i] = -1;
    }
    
    int j = 0, m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        c[i] = m;
        if (m >= 0) {
            a[j] = m;
            j++;
        }
    }
    
    // 冒泡排序正数数组
    for (int k = 0; k < j; k++)
        for (int i = 0; i < j - 1; i++)
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
    
    int flag = 0;
    while (flag == 0) {
        for (int i = 0; i < j; i++) b[i] = -1;
        for (int i = 0; i < j; i++)
            linear_probing(a[i], n, b);
        
        for (int i = 0; i < n; i++) {
            if (i == n - 1 && b[i] == c[i]) {
                flag = 1;
                break;
            }
            if (b[i] != c[i]) {
                int temp;
                for (int k = 0; k < j; k++)
                    if (a[k] == c[i]) {
                        temp = a[k];
                        a[k] = a[i];
                        a[i] = temp;
                    }
                break;
            }
        }
        if (flag == 1) break;
    }
    
    printf("%d", a[0]);
    for (int i = 1; i < j; i++)
        printf(" %d", a[i]);
    
    return 0;
}
for(int i=1;i<j;i++)
    printf(" %d",a[i]);

}