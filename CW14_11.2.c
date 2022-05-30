#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    const char* fname = "F.dat";
    FILE* F = fopen(fname, "wb");
    if(F==NULL){
        fprintf(stderr, "Error open file %s", fname);
        return -1;
    }
    
    int n;
    printf("n=");
    scanf("%d",&n);
    double x;
    for(int i=0;i<n;i++){
        printf("x=");
        scanf("%lf",&x);
        fwrite(&x,1,sizeof(x),F);
    }
    fclose(F);
    
    double a;
    printf("a=");
    scanf("%lf",&a);
    
    F = fopen(fname,"rb");
    
    double mas[10];
    const char* fname2 = "G.dat";
    FILE* G = fopen(fname2,"wb");
    int i=0;
    int k=0;
    while(1){
        if(feof(F)) break;
        fread(&x,1,sizeof(double),F);
        if(fabs(x)<a){
            fwrite(&x,1,sizeof(x),G);
        }
        else{
            mas[k++] = x;
        }
        i++;
    }
    
    fclose(F);
    fclose(G);
    
    G = fopen(fname2,"rb");
    i=0;
    while(1){
        if(feof(G)) break;
        fread(&x,1,sizeof(double),G);
        printf("x%d=%lf, ",i++,x);
    }
    fclose(G);
    
    F = fopen(fname,"wb");
    fwrite(mas,k,sizeof(double),F);
    F = freopen(fname,"rb",F);
    i=0;
    while(1){
        if(feof(F)) break;
        fread(&x,1,sizeof(double),F);
        printf("x%d=%lf, ",i++,x);
    }
    fclose(F);
}
