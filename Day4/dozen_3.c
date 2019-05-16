#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init_intro(char (*intro[80]), char **pint);
int input_intro(char(*intro[80]));
void sort_intro(char **pint, int cnt);
void printf_intro(int mode, void *vp, int cnt);
int convert_string(const void *a, const void *b);

int main(void)
{
	char intro[10][80]; //10x80
	char *pint[10];
	int cnt;
	
	 
	
	init_intro(intro, pint);
	cnt = input_intro(intro);
	sort_intro(pint, cnt);
	printf_intro(1, pint, cnt);//0�� ���� �Էµ� �λ縻, 1�� ���ĵ� �λ縻 
	printf_intro(0, intro, cnt);

	return 0;
}
//Ű����� �λ縻 �Է� �� ������ �����Ͽ� ���
//�̾ �Է��� ������� �ٽ��ѹ� ���
//������ �Է��� ���ڿ��� �ٲ��� �ʰ� ������ �迭�� ���� ������ ����
 

//init�� intro ���� 
void init_intro(char (*intro[80]), char **pint) {
	int i=0;
	for(i=0;i<10;i++) {
		pint[i] = intro+i;
		//*pint[i] = intro+i;
		//pint[i] = intro[i]; 
	}
}

int input_intro(char(*intro[80])) {
	int l_cnt;
	char buffer[80];
	while( 1 ) {//end�� �ԷµǸ� ���� //�λ縻 ���� 
		printf("�λ縻 �Է� : ");
		fgets(buffer,sizeof(buffer),stdin);	//���Լ� ���¹� , �Է¹޾� �� ����
		printf("�Է¹��� ���ڿ� %s",buffer);
		if( 0 == strcmp("end",buffer )) {
			break;
		}
		else {
			strcpy(intro[l_cnt],buffer);
		}
		l_cnt++;
	}
	
	return l_cnt; 
}


//�λ縻 ������ ����
void sort_intro(char **pint, int cnt) {
	int i,j;
	for(i=0;i<9;i++ ) {
		for(j=0;j<9;j++) {
			if (strcpy(pint[i],pint[j]))
            {
            	/*
                temp        = data[j];
                data[j]     = data[j + 1];
                data[j + 1] = temp;
                */
            }
		}
	}
	  
}


 //0�� ���� �Էµ� �λ縻, 1�� ���ĵ� �λ縻
void printf_intro(int mode, void *vp, int cnt) {
	int i,j; 
	if(mode) {//���ĵ� �λ縻 
		//���ĵ� �λ縻 �� pint������ �迭�� �̿� 
		//vp ��  pint �� �����µ�, �� ������ �����ϱ� 
	} 
	else {//���� �Էµ� �λ縻 vp�� �̿��� intro2�����迭 ���ڿ����//2�����迭�� �Է¹޴� �迭������ 
		for(i=0;i<10;i++) {
			puts(vp+i);
		}
		
	}
}

int convert_string(const void *a, const void *b) {
    
}


