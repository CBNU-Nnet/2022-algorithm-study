#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);

    int c;
    char* Name;
    for(int i=0;i<n;i++){
        scanf("%d",&c);
        int max=0;
        for(int j=0;j<c;j++){
            int price;
            char* str;
            str=(char*)malloc(sizeof(char)*20);
            scanf("%d %s",&price,str);
            if(price>max){
                max=price;
                Name=str;
            }


        }
        printf("%s\n",Name);
    }
    return 0;
}