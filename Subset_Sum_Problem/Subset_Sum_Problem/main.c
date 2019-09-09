#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#define MAX 16
#define SET_SIZE 4
// Sorting 됐다는 가정

int Set[SET_SIZE] = { 2,3,4,8 };
int biSet[SET_SIZE] = { 0,0,0,0 };
int Subset[MAX] = { 0, };
int T = 9;
clock_t start, end;

int main() {
	int count = 0;
	int temp = 0;
	int total = 0;
	bool flag = false;

	printf("Main Set = { ");
	for (int i = 0; i < SET_SIZE; i++) printf("%d, ", Set[i]);
	printf(" }\n\n");

	printf("Target is %d\n\n", T);

	printf("Answer is ");
	start = clock();
	while (count < MAX) {
		for (int i = 0; i < SET_SIZE; i++) {
			temp = pow(2, i);
			if (count % temp == 0) {
				if (biSet[(SET_SIZE - 1) - i] == 0) biSet[(SET_SIZE - 1) - i] = 1;
				else biSet[(SET_SIZE - 1) - i] = 0;
			}
		}

		for (int i = 0; i < SET_SIZE; i++) total = total + (Set[i] * biSet[i]);
		Subset[count] = total;
		total = 0;

		if (Subset[count++] == T) {
			printf("yes\t");
			printf(" { ");
			for (int i = 0; i < SET_SIZE; i++)
				if (biSet[i] != 0) printf("%d, ", Set[i]);
			printf(" }\n\n");	
			flag = true;
			break;
		}
	}
	if (!flag) printf("no\n\n");
	end = clock();

	printf("SubSet = { ");
	for (int i = 0; i < MAX; i++) printf("%d, ", Subset[i]);
	printf(" }\n\n");

	printf("실행시간 : %f\n", (float)(end - start)/CLOCKS_PER_SEC);

	return 0;
}


/*if (biSet[3] == 0) biSet[3] = 1;
else biSet[3] = 0;

if (count % 2 == 0) {
if (biSet[2] == 0) biSet[2] = 1;
else biSet[2] = 0;
}

if (count % 4 == 0) {
if (biSet[1] == 0) biSet[1] = 1;
else biSet[1] = 0;
}

if (count % 8 == 0) {
if (biSet[0] == 0) biSet[0] = 1;
else biSet[0] = 0;
}*/