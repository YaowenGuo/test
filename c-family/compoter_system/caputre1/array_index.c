/*************************************************************************
	> File Name: array_index.c
	> Author: YaowenGuo
	> Mail: 1441250996@qq.com 
	> Created Time: Sun Jun 20 22:09:26 2021
 ************************************************************************/

#include<stdio.h>

typedef struct {
	int a[2];
	float d;
} struct_t;

double fun(int i) {
	volatile struct_t s;
	s.d = 3.14;
	s.a[i] = 1073741824;
	return s.d;
}

int main() {
	printf("index 1: %f\n", fun(1));
	printf("index 2: %f\n", fun(2));
}
