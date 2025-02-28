#include<stdio.h>
#define MAXLINE 50
#define MAXLENGTH 150
int atoi(char *buffer){
    int s = 0;
    int i = 0;
    while(i<MAXLENGTH){
        if(buffer[i] == '\n' || buffer[i] == '\0' || buffer[i] == ' ') return s;
        int numar = (buffer[i]-'0');
        s = s*10 + numar;
        i++;
    }
    return s; //nu prea are cum sa ajunga aici
}
int main(){
    FILE *fptr = fopen("in.txt", "r+");
    if(fptr==NULL) {
        printf("eroare\n");
        return -1;
    }
    char buffer[MAXLENGTH];
    int sum = 0;
    while(fgets(buffer, MAXLENGTH, fptr)){
        printf("%d ", sum);
        sum+=atoi(buffer);
    }
    printf("%d \n", sum);
    fclose(fptr);
    return 0;
}

