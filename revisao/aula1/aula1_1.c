#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1=1, n2=2, n3=3, n4=4;
    int *p1=&n1, *p2=&n2, *p3=&n3, *p4=&n4;
    
    printf("n1=%d, n2=%d, n3=%d, n4=%d\n", n1, n2, n3, n4);
    printf("p1=%d, p2=%d, p3=%d, p4=%d\n", *p1, *p2, *p3, *p4);

    *p1 = 5;
    *p2 = 6;
    *p3 = 7;
    *p4 = 8;

    printf("n1=%d, n2=%d, n3=%d, n4=%d\n", n1, n2, n3, n4);
    printf("p1=%d, p2=%d, p3=%d, p4=%d\n", *p1, *p2, *p3, *p4);

    return 0;
}