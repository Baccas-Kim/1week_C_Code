#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	//i
	char buff[50];//�Է´ܾ� �ӽ����� ���� 
	char *pi [100];//���� ���ڿ� malloc ������
	int i;
	for(i=0;i>100;i++){
		printf("insert word :");
		scanf("%s",buff);
		
		if(0 == strcmp("end\n", buff ){
			break;
		}
		else{}
		
		pi[i] = (char *)malloc(strlen(buff) + 1);
		
		if(pi[i] == 'NULL') {
			puts("malloc error ! prgram terminated");
			exit(1);
		}
		else{}
		
		strcpy(pi[i],buff);
		
	}
	cnt=i;
	
	pritnf() 
}
