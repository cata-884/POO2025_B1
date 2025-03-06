#include "NumberList.h"
#include<stdio.h>
int main(int argc, char* argv[]){
    NumberList lista;
    lista.init();
    int nums;
    scanf("%d", &nums);
    while(nums--) {
        int exemplu;
        scanf("%d", &exemplu);
        lista.Add(exemplu);
    }
    lista.sort();
    lista.print();
    return 0;
}
