#include <stdio.h>
#define MIN(a, b) (((a) > (b)) ? (b) : (a))

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    int a, b;
    int p_6=1000, p_1 =1000;
    for(int i=0;i<m;i++){
        scanf("%d %d", &a, &b);
        p_6 = MIN(p_6, a);
        p_1 = MIN(p_1, b);
    }
    int sum_p;
    if(p_1*6<p_6) sum_p = n*p_1;
    else sum_p = (n/6)*p_6 + MIN(p_1*(n%6), p_6)
    
    printf("%d", sum_p);
}