//
// Created by cata-884 on 2/4/25.
//

#include "NumberList.h"
#include<stdio.h>
#include<cstring>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void NumberList::init() {
    this->count = 0;
    memset(this->numbers, 0, sizeof(this->numbers));
}
bool NumberList::Add(int x) {
    if(this->count>=10) return false;
    numbers[this->count] = x;
    this->count++;
    return true;
}

void heapify(int arr[], int i, int n) {
    int largest = i;
    int left = i*2+1;
    int right = i*2+2;
    if(left<n && arr[i]<arr[left]) {
        largest = left;
    }
    if(right<n && arr[largest]<arr[right]) {
        largest = right;
    }
    if(largest!=i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, largest, n);
    }
}
void NumberList::sort() {
    for(int i=this->count/2 - 1; i>=0; i--) {
        heapify(this->numbers, i, this->count);
    }
    for(int i=this->count - 1; i>=1; i--) {
        swap(&this->numbers[i],&this->numbers[0]);
        heapify(this->numbers, 0, i);
    }
}
void NumberList::print() {
    if(this->count>-1) {
        for(int i=0; i<this->count; i++) {
            printf("%d ", this->numbers[i]);
        }
    }
}

