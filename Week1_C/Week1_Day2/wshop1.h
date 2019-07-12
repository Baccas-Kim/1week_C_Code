#include <stdio.h>
#include <string.h>

int strtoNum(char *str, int s, int e);
int leap_year(int year);
int formatErrorCheck(char *p_num);
int isY(void);
int vaild_num(char *p_num);
void idCheck(void);

int strtoNum(char *str, int s, int e)
{
	int num = 0;
	int multi = 1;
	int idx;
	int diff = '1' - 1;

	for (idx = e; idx >= s; idx--) {
		num += multi * (str[idx] - diff);
		multi *= 10;
	}
	return num;
}


//KDH : ���� �ʿ��� -1 
int leap_year(int year)
{
//	int leap = 0;
	
	if(year%4) {
		if(year%100) {
			if(year%400) {
				return 1;
			}
			else {
				return -5000; // Error code
			}
		}
		else {}
		return 1;
	}
	else {
	return 0;	
	}
	return 0;
	// TODO: �̰��� �ڵ带 �ۼ��ϼ���.
	// ���� return =1, ��� = return 0 
}

int formatErrorCheck(char *p_num)
{
	int dayofmonth[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int check_num;
	int i, mod = 0, sum = 0;
	int year, leap = 0;

	// �ֹι�ȣ ���̴� 13
	if (strlen(p_num) != 13) {
		return 0;
	}
	
	// ���� 12���� �Ѿ�� �� �ȴ�.
	if (strtoNum(p_num,2,3)>12) {
		return 1;
	}
	
	// ���� ������ ��¥�� �Ѿ�� �� �ȴ�.
	if (strtoNum(p_num,4,5)>dayofmonth[strtoNum(p_num,4,5)]) {
		return 2;
	}
	// �����̸� 1
	year = (strtoNum(p_num, 6, 6) <= 2) ? 1900 : 2000;
	year += strtoNum(p_num, 0, 1);
	leap = leap_year(year);
	
	// 2���̰� ����̸� 29�� ������ �� �ȴ�.
	// DHKim �� : �����Ҽ� ���� ���� -> ��� 2019���� 2�� 29�� ����ڴ� ������ ��ȿ �ֹι�ȣ? 
	if ( (strtoNum(p_num,2,3) == 2) && (0!=strtoNum(p_num,0,1)%4) && ( strtoNum(p_num,4,5) == 29 ) ) {
		return 3;
	}
	
	if (p_num[6] - '0' < 1 || p_num[6] - '0' > 4) {
		return 4;
	}

	mod = vaild_num(p_num);
	// �ֹι�ȣ �����ڵ�(�����ѹ�) �˻�
	if (mod != p_num[12] - '0'){
		return 5;
	}
		

	return -1;
}

int isY(void)
{
	char answer;
	printf("�ٽ� �Է��Ͻðڽ��ϱ�? (y/n) ");
	fflush(stdin);
	scanf("%c", &answer);
	if (answer == 'Y' || answer == 'y')
		return 1;
	return 0;
}



//KDH : ���� �ʿ��� -1
int vaild_num(char *p_num) 
{
	int i=0,sum=0,rmd_11=0,rmd_10=0;
	for(i=1 ; i<(13+1) ; i++ ) {
		sum += strtoNum(p_num,i,i)*(i+1);	
	}
	rmd_11 = sum%11;
	rmd_10 = (11-rmd_11)%10;
	
	return rmd_10;
}
