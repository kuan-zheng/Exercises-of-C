/**
 * 题目：判断一个整数是否为素数
 *
 * 思考演进：
 *   v1: 暴力遍历 2→n-1，O(n)  ✅ 正确但慢
 *   v2: 优化为检查 2→√n，只需 O(√n)
 *       原理：若 n 有大于 √n 的因子，必有小于 √n 的配对因子
 */

#include <stdio.h>
#include <math.h>

int main() {
    int n, i, isPrime = 1;

    printf("请输入一个整数: ");
    scanf("%d", &n);

    // 优化：只检查到 sqrt(n)，且跳过偶数
    if (n <= 1) {
        isPrime = 0;
    } else if (n == 2) {
        isPrime = 1;
    } else if (n % 2 == 0) {
        isPrime = 0;
    } else {
        int limit = (int)sqrt(n);
        for (i = 3; i <= limit; i += 2) {
            if (n % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime)
        printf("%d 是素数\n", n);
    else
        printf("%d 不是素数\n", n);

    return 0;
}
