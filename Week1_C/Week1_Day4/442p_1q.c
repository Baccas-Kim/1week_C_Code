#include <stdio.h>


int main(void)
{
	int arr[5][6]={0};
	
	int i,j;

	int sum;
	 
	//�ʱ�ȭ : �⺻�� �ֱ� 
	for(i=0;i<4;i++) {
		for(j=0;j<5;j++) {
			arr[i][j]=(i*5)+j+1;
		}
		
	}

	//���� �� �ֱ� 
	for(i=0;i<4;i++) {
		for(j=0;j<5;j++) {
			arr[i][5] +=arr[i][j];
		}	
		
	}
	
	//���� �� �ֱ� 
	for(i=0;i<6;i++) {
		for(j=0;j<4;j++) {
			arr[4][i] +=arr[j][i];
		}	
		
	}
	//*/
	//��� 
	for(i=0;i<5;i++) {
		for(j=0;j<6;j++) {
			printf("%d\t",arr[i][j]);		
		}
		puts("");
	}
	

	return 0;
}


