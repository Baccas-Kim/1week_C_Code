#include <stdio.h>
int primesv(unsigned int num);

int main(void)
{
	unsigned int buf=0;
	
	do {
		puts("2�̸��� �� �Է½� ����˴ϴ�");
		
		printf("2�̻��� ������ �Է��ϼ��� : ");
		scanf("%d",&buf);
		
		if(buf>2){
			if(primesv(buf)) {
				puts("Prime number!");
			}
			else {
				puts("NO Prime");
					
			}
		}
	}while(buf>2);
	puts("program Terminated!");
	return 0;
}


int primesv(unsigned int num)
{
	if (num==1) {
		return num;//in case of prime!
	}
	else if(0==num%(num-1)) {
		return 0;
	}
	else {
		primesv(num-1);	
	}
}
