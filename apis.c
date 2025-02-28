#include<stdio.h>
#include<stdlib.h>
#define size 50
int len(char *buffer){
    int s = 0;
    while(buffer[s]!='\0'){
        s++;
    }
    return s;
}
int main(){
    char buffer[size];
    char cuvinte[size][size];
    scanf(" %[^\n]", buffer); 
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cuvinte[i][j]=0;
        }
    }
    for(int i=0, k=0, t=0; buffer[i]!='\0' && i<size; i++){
    //k - linii, t - coloana
        if(buffer[i] == ' ' || buffer[i] == '\0' || buffer[i] == '\n'){
            cuvinte[k][t] = '\0';
            k++;
            t = 0;
            continue;
        }
        cuvinte[k][t++] = buffer[i];
    }
    int tot_words = 0;
    while(tot_words<size && cuvinte[tot_words][0]!='\0') tot_words++;
    for(int i=0; i<tot_words-1; i++){
        for(int j=0; j<tot_words-i-1; j++){
            if(len(cuvinte[j])<len(cuvinte[j+1])){
                char temp[size];
                int t =0;
                while(cuvinte[j][t]!='\0'){
                    temp[t] = cuvinte[j][t];
                    t++;
                }
                temp[t] = '\0';
                t = 0;
                while(cuvinte[j+1][t]!='\0'){
                    cuvinte[j][t] = cuvinte[j+1][t];
                    t++;
                }
                cuvinte[j][t] = '\0';
                t = 0;
                while(temp[t]!='\0'){
                    cuvinte[j+1][t] = temp[t];
                    t++;
                }
                cuvinte[j+1][t] = '\0';
            }
        }
    }
    for(int i=0; i<size && cuvinte[i][0]!='\0'; i++){
        printf("%s\n", cuvinte[i]);
    }

}
