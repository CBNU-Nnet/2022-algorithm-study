#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int alpha[26] = {2, 22, 222,3,33,333,4,44,444,5,55,555,6,66,666,7,77,777,7777,8,88,888,9,99,999,9999};
    int chan[9];
    int d;
    for(int i=0;i<9;i++){
        scanf("%d", &d);
        chan[d-1]=i+1;
    }
    
    char str[100];
    scanf("%s", str);
    char answer[500];
    char buffer[4];
    int cy = strlen(str);
    for(int i =0;i<cy;i++){
        sprintf(buffer, "%d", alpha[str[i]-97]);
        strcat(answer, buffer);
        if(alpha[str[i]-97]%10 == alpha[str[i+1]-97]%10){
			strcat(answer, "#");
		}
    }
    printf("%c", answer[0]);
    for(int i =1;i<strlen(answer);i++){
        if(answer[i] == '#'){
            printf("%c", answer[i]);
            continue;
        }
        printf("%d", chan[answer[i]-'0'-1]);
    }
}