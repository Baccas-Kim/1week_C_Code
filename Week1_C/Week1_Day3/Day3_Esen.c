#include <stdio.h>
/*
int main(void)
{
	int i=0,buf=0;
	const int ans = 17;
	for(i=1 ; i<=30 ; i++) {
		printf("insert number (1~30) : ");
		scanf("%d",&buf);
		
		if(buf==ans) {
			puts("success!!");
			puts("success!!");
			puts("success!!");
			break;
		}
		else {
			puts("wrong ans");
			if(buf<ans) {
				puts("UP");
			}
			else {
				puts("DOWN");
			}
		}
	}
	
	return 0;
}

================================================================

int main(void) 
{
int a;
int *pa;

 pa = &a;
 *pa=10;
 
 printf("*pa �����ͷ� ��� : %d",*pa);
 printf("a print by var name %d",*(&*(&a)));

	return 0;
}
================================================================
int main(void)
{
	char c1, c2,c3;
	
	scanf("%c%c", &c1,&c2);
	printf("[%c%c]",c1,c2,c3);
	return 0;
}

================================================================

int main(void)
{
	int res;
	char ch;
	
	while(1)
	{
		res = scanf("%c", &ch);
		if(res == -1) break;
		printf("%d ",ch);
		
	}
	return 0;
}


================================================================

int main(void)
{
	int num, grade;
	
	printf("�й��Է� : ");
	scanf("%d" , &num);
	fflush(stdin);
	printf("�����Է� :");
	grade = getchar();
	printf("�й� : %d, ���� : %c",num, grade);
	
	return 0;
}


================================================================

int main (void) 
{
	printf("�ּҰ� : 0x%x\n","mango");
	printf("ù ��° ���� : %c\n",*"mango");
	printf("�� ��° ���� : %c\n",*("mango"+1));
	printf("�� ��° ���� : %c\n","mango"[2]);
}


================================================================

int main(void)
{
	char *dessert = "appleasdsdfsfd";
	
	printf("���� �Ľ��� %s �Դϴ� \n",dessert);
	dessert = "banana";
	printf("���� �Ľ��� %s �Դϴ� \n",dessert);
	
	//*(dessert +0 )= 'k';
	//printf("??? �Ľ��� %s �Դϴ� \n",dessert);
	
	return 0;
	
}


================================================================
*/
int main(void)
{
	char str[10];
	
	printf("������ ���Ե� ���ڿ�\n");
	fgets (str, sizeof(str),stdin);
	printf("�Էµ� ���ڿ��� %s �Դϴ� \n",str);
	
	//*(dessert +0 )= 'k';
	//printf("??? �Ľ��� %s �Դϴ� \n",dessert);
	
	return 0;
	
}
