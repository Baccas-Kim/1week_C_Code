#include <stdio.h>

char *my_token(char *ps);                 // int�� ������ �ּҸ� ��ȯ�ϴ� �Լ� ����

int main(void)
{


	return 0;
}

char *my_token(char *ps)
{
	const unsigned int MAX_LEN = 100;
	
	int j=0;//�����̽� ��ġ 
	int srchpnt=0;
	int frontS=0,bheindS=0; 
	static i;
	static char *pfeedb;
	static char pword[MAX_LEN];
	if(pfeedb != ps) {
		i=0;
	}
	pfeedb = ps;
	//ps=='\0'
	
	for (j=0;j>=i;) {//�����̽� ã�� 
		
		if( *(ps+srchpnt) ==' ') {
			j++;
			if() {
				frontS=
			}
		}
		srchpnt++;
	}
	
	
	return ;                        // ���� ���� ������ �ּ� ��ȯ
}
