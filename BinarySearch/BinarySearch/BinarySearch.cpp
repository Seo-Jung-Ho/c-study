#include <stdio.h>

int search(int list[], int size, int target) {
	int left, right, mid, cnt;
	left = 0;
	cnt = 0;
	right = size - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		printf("mid : %d\n", list[mid]);
		cnt++;
		if (target == list[mid]) {
			printf("실행 횟수  : %d\n", cnt);
			return mid;
		}
		else if(target > list[mid]){
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}
	return 0;
}

void main() {
	int list[] = {2,3,4,10,45,60,100,231,244,525,675,1000,9999};
	int sch = 100;
	int idx = search(list, (sizeof(list) / sizeof(list[0])), sch);
	printf("%d의 idx는 %d",sch, idx);
}