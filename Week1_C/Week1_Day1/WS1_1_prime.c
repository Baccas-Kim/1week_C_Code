//primenumber
#include <stdio.h>
int main(void) {
	int val=0, i=0;
	int pridca=0; 
	do {
		
		printf("���ڸ� �Է��ϼ��� <���� : 0> :");
		scanf( "%d" ,&val);
		//out of range exception will be add 
		if (val == 0) {
			puts("bye~");
			return 0;
		}
		if (val == 1) {
			printf("�Ҽ��� �ƴմϴ�, 1�Է�\n");
		}
		 
		
		i=val-1;
		
		while( i >= 2 ) {
			if(0 == (val%i)) {
				printf("�Ҽ��� �ƴմϴ�\n");
				break;
			}
			else {
				i--;
			}
		}
		
		if(i==1) {
			printf("�Ҽ� �Դϴ�\n");
		}
		 
		
	}while(1);

return 0;
}
