#include <stdio.h>
int main(void) 
{
	
	int rnum[6]={0,0,0,0,0,0};
	int i=0,j=0;
	int buff= 0;
	int jb = 0;
	//�����
	printf("�Էµ� �ζǹ�ȣ : ");
	for(i=0;i<6;i++) {
		printf("\t%d",rnum[i]);
	}
	puts(""); 
	//
	for(i=1;i<7;i++) {
		printf("�ζ� ��ȣ �Է� : ");
		scanf("%d", &buff);
	 	printf("buff = %d\n",buff);
		jb=1;
		
		for(j=0;j<i;j++) {
			if( buff == rnum[i] ) {
				jb=0;
				break;
			}
		}
		
		if(jb) {
			rnum[i-1]= buff;
		}
		else {
			printf("���� ��ȣ�� �ֽ��ϴ�!");
			i=i-1;
		}
		 
	}
	
	
	printf("�Էµ� �ζǹ�ȣ : ");
	for(i=0;i<6;i++) {
		printf("\t%d",rnum[i]);
	}
	
}
