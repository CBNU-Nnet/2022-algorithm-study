#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int * array = (int*)malloc(sizeof(int));
    for(int i =0;i<n;i++){
        scanf("%d", &array[i]);
    }
    
    int m=0, y=0;
    for(int i=0;i<n;i++){
        m += (array[i]/60+1)*15;
        
        y += (array[i]/30+1)*10;

    }
    //printf("%d %d", m, y);
    if (m<y) printf("M %d", m);
    else if (m==y) printf("Y M %d", y);
    else printf("Y %d", y);
    
    free(array);
    return 0;
}