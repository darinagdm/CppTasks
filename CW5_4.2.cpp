#include <stdio.h>

int main(){
    int n;
    printf("n=");
    scanf("%d",&n);
    printf("%d != %d",n,1);
    for(int i=2;i<=n;i++){
        printf("*%d",i);
    }
    printf("\n %d != %d",n,n);
    for(int i=n-1;i>=1;i--){
        printf("*%d",i);
    }
}
