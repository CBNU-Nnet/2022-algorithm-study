#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
int main()
{
    int m, n, max_m;
    int toggle=0;
    
    scanf("%d", &n);
    scanf("%d", &m);
    max_m = m;
    for(int i =0;i<n;i++){
        int in, out;
        scanf("%d %d", &in, &out);
        m += in-out;
        if(m<0){
            toggle = 1;
        }
        max_m=MAX(max_m, m);
    }
    if(toggle==0) printf("%d", max_m);
    else printf("0");
}
