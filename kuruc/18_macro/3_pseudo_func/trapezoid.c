#include <stdio.h>

#define GET_TRAPEZOID_ARE(A, B, H) (A + B) * H / 2

int main(void) {
    int up, down, h, s;

    printf("上底, 下底, 高さ(,区切りで入力)：");
    scanf("%d, %d, %d", &up, &down, &h);
    s = GET_TRAPEZOID_ARE(up, down, h);
    printf("面積:%d\n", s);

    return 0;
}