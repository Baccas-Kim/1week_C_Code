#include <stdio.h>
int my_strcmp(char * str1,char * str2);
//������ 0 ��ȯ ,����ũ��1, �ڰ�ũ��2; 

int main (void)
{
	char str1[20],str2[20];
	printf("insert 1st string to compare:");
	scanf("%s",str1);
	printf("insert 2nd string to compare:");
	scanf("%s",str2);

	switch(my_strcmp(str1,str2))
	{
		case (1) : printf("%s �� �� Ů�ϴ�\n",str1);
			break;
		
		case (-1) : printf("%s �� �� Ů�ϴ�\n",str2);
			break;
	
		case (0) : printf("������ ���ڿ� %s == %s \n",str1,str2);
			break;	
		
		default : puts("ERROR!"); 
	}
	
	return 0;
}


int my_strcmp(char *str1,char *str2)
{
	int i=0;
	char buf;
	int flag = 0;
	while ( (*str1 == *str2 ) && *str1=='\0' ) 	{
		str1++;
		str2++;
	}
	if(*str1 > *str2 ) {
		return 1 ;
	}
	else if(*str1 < *str2 )	{
		return -1;
	}
	else {
		return 0;
	}
}	
