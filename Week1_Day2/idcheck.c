/*
 * idcheck.c 
 * modifly by DHKim 2019-05-14
 */

#include "wshop1.h"
/*
 *
int strtoNum(char *str, int s, int e);
int leap_year(int year);
int formatErrorCheck(char *p_num);
int isY(void);
void idCheck(void);
 *
 */
int main(void)
{
	char *errormsg[] = {
			"�ֹε�Ϲ�ȣ ���̰� Ʋ�Ƚ��ϴ�.",
			"�߸� �Էµ� ����ȣ�Դϴ�.",
			"�߸� �Էµ� �Ϲ�ȣ�Դϴ�.",
			"����ε� ���� ��¥�Դϴ�.",
			"���� ��ȣ�� �߸� �ԷµǾ����ϴ�.",
			"�����ڵ� ������ �ֹε�Ϲ�ȣ�Դϴ�." };
	char p_num[15];
	int errorno = 0;

	do {
		printf("\"-\"�� ������ Ȯ���� �ֹε�Ϲ�ȣ 13�ڸ��� �Է��ϼ��� : "); 
		scanf("%s", p_num);

		errorno = formatErrorCheck(p_num);
		if (errorno >= 0)
			printf("%s\n", errormsg[errorno]);
		else
			printf("�ùٸ� �ֹε�Ϲ�ȣ�Դϴ�.\n");
	} while (isY());

	return 0;
}

