#pragma warning(disable:4996)
#include <stdio.h>
int main(){
    int x1,x2,y1,y2,c1,c2;
    scanf("%d %d %d %d %d %d",&x1,&y1,&c1,&x2,&y2,&c2);
    
    for(int i = -999; i <= 999 ; i++){
        for(int j = -999; j<= 999; j++){
            if (x1 * i + y1 * j == c1 && x2 * i + y2 * j == c2) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    
    return 0;
}
