#include <stdio.h>

int total(int kor, int eng, int mat);
double average(int tot);
void print_title(void);


int main(void) {
	int a=0,b=0,c=0;
	
	printf("�� ������ ���� �Է� : ");
	scanf("%d %d %d",&a,&b,&c);


	print_title();
	
	
	printf("%d\t %d\t %d\t %d\t %1f",a,b,c,total(a,b,c),average(total(a,b,c)));
	return 0;	
}



int total(int kor, int eng, int mat) {
	
	return (kor+eng+mat);
}


double average(int tot) {
	return ((double)tot/3);
}


void print_title(void) {
	puts("  ===<����ǥ>===   ");
	puts("===================");
	puts("");
	puts("-------------------");
	puts("����\t����\t����\t����\t���"); 
	return;
}


