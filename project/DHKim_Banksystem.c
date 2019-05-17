#define ENDMSG_RUTIN do{puts("Program terminated!!\n\n");}while(0);
#define WAITKEY_RUTIN do{printf("\ncontinue to press any key");fflush(stdin);getc(stdin);}while(0);
#define MID_DBL_LINE do{puts("=====================================================");}while(0);
#define MAXLEN 100 //max len of buf

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void disp_calendar(int year, int month);
int get_weekday(int year, int month);
int get_weekday(int year, int month);
int leap_check(int year);
int app_Launcher(int mode);
//int print_accinfo(struct account myacc);//


int dispmenu(void);
int loginout(void);
int accprint(void);
int banktrns(void);
int withdraw(void);
int depositm(void);
int checkdps(void);
int calprint(void);
int levamesg(void);
int gamemode(void);



struct account {
	char *Name;
	
	int deposit;
	int trust;
	
	char ID[MAXLEN];
	char PW[MAXLEN];
	
};
struct account cur_user;

int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int loginflag = 0;
char ID_admin[] = "admin";
char PW_admin[] = "admin";
char *msgfreq[10] ;


int main(void)
{
	
	return app_Launcher(1);
}


int app_Launcher(int mode) {
	//mode 1 : nomal mode
	//mode 2 : debug mode
	int num=1;

	while (num)
	{
		num = dispmenu();
		switch (num) {
		
		case 1:loginout();
			break;
		
		case 2:accprint();
			break;
		
		case 3:banktrns();
			break;
			
		case 4:withdraw();
			break;
		
		case 5:depositm();
			break;
						
		case 6:checkdps();
			break;

		case 7:calprint();
			break;
		
		case 8:levamesg();
			break;
		
		case 9:gamemode();
			break;
			
		default:
			ENDMSG_RUTIN	
			exit(1);
			break;
		}
	}
    //PAUSE;
}

// �޴� ��� �� ���� ��ȣ ��ȯ
int dispmenu(void)
{
	int num;
	MID_DBL_LINE 
	puts("\n===[ Welcome DHKim BANK!! ]===\n");
	puts("===[ Select your menu ]=========");
	puts(">> 1. Login / Logout");
	puts(">> 2. account info print");
	puts(">> 3. Bank Transfer");
	puts(">> 4. withdraw money");
	puts(">> 5. Deposit money");
	puts(">> 6. Deposit Check");
	puts(">> 7. Calender");
	puts(">> 8. Leave a Message");
	puts(">> 9. Program Vision");
	puts(">> 0. Exit");
	MID_DBL_LINE 
	printf(">>insert your menu number : "); 
	scanf("%d", &num);
	//puts("\n");
	return num;
}

int loginout (void) {
	int idok=0, pwok=0;
	char buf[MAXLEN];
	char ch;
	
	puts("======admin ID / Passward Check=====");
	printf("ID : ");
	scanf("%s",&buf);
	if( loginflag == 0 )
		if( 0 == strcmp(ID_admin,buf) ) {
			printf("PW : ");
			scanf("%s",&buf);
			if( 0 == strcmp(PW_admin,buf) ) {
				MID_DBL_LINE 
				puts("administor loginned!! WEEEELLLLLCOME");
				MID_DBL_LINE 
				loginflag=1;	
				WAITKEY_RUTIN
			}
		}
		else {
			puts("ID is wrong!");
			WAITKEY_RUTIN
			return;
		}
	else if( loginflag == 1) {
		puts("already admin login");
		printf("do you want Logout? (Y/N)");
		scanf("%c",&ch);
		if(ch == 'Y' || ch == 'y') {
			puts("outout! bye bye");
			WAITKEY_RUTIN
		}
		else {
			puts("cancled");
			WAITKEY_RUTIN
		}
	}
	
		
	
}

int accprint (void) {
	int i=0;
	
	for(i=0;i<10;i++) {//
		puts("����ü�����͸� �Ѱܹ޾� ���������� ����ϴ� �Լ� ����");
			//print_accinfo(/*acc ����ü �ּ�*/);
			
	}
	MID_DBL_LINE
	puts("\nend of the Lisht") ;
	MID_DBL_LINE
	WAITKEY_RUTIN
}

int banktrns (void) {
	if(loginflag) {
		//����� �ܾ�, �۱ݰ���, �ݾ� 
	}
	else {
		puts("Login First!");
		WAITKEY_RUTIN
	}

}

int withdraw (void) {
	
	if(loginflag) {
	}
	else {
		puts("Login First!");
		WAITKEY_RUTIN
	}

}

int depositm (void) {
	if(loginflag) {
		printf("ID : %s",cur_user.ID);//��� �߰����� �ʿ� 
		printf("deposit : %d",9999999);
	}
	else {
		puts("Login First!");
		WAITKEY_RUTIN
	}
}

int checkdps (void) {
	
}

int calprint (void) {
	char buf;
	disp_calendar(2019, 5);
	printf("continue to any key");
	fflush(stdin);
	getc(stdin);
}

int levamesg (void) {
	
}

int gamemode (void) {
	puts("\n\n");
	puts("======Comming soon======");
	puts("Meeting reservation");
	puts("FILE I/O-> Save : data.csv ");
	puts("Calculator");
	puts("Double Linked List custmer ");
	puts("");
	printf("continue to any key");
	fflush(stdin);
	getc(stdin);
}


int print_accinfo(struct account myacc) {
	printf("User name : $s\n", myacc.Name);
	printf("User deposit : %d\n", myacc.deposit);
	printf("User trust : %d\n", myacc.trust);
	printf("User Identiti : ", myacc.ID);
	printf("User password : ", myacc.PW);
	
	return 0;
	
}


//==================================================
//re-used func
int leap_check(int year)
{
	if(year%4!=0) return 0;
	else if(year%100!=0) return 1;
	else if(year%400==0) return 1;
	else return 0;
}

// ����� ���� �ϼ� ���

int get_days(int year, int month)
{
	int days =0;
	days=mdays[month-1];
	if(leap_check(year) && month==2) ++days;  // �����̰� 2���̸� 29�Ϸ� ���
	return days;
}

// ���� ���ϴ� �Լ�
int get_weekday(int year, int month)
{
	int i, tot=0;

	// 1����� year-1�⵵������ �� �ϼ� ����
	for(i=1; i<year; i++){
		if(leap_check(i)) tot+=366;
		else tot+=365;
	}

	// 1������ month-1�� ������ �� �ϼ� ����
	for(i=0; i<month-1; i++){
		tot+=mdays[i];
	}

	// �����̰� ���� 3�� �̻��̸� 2���� 29���̹Ƿ� �Ϸ縦 ���Ѵ�.
	if(leap_check(year) && month>=3) tot++;

	// ����� 1���� ����
	tot++;

	return tot%7;  // ���� ��ġ ��ȯ
}

// �޷� ���
void disp_calendar(int year, int month)
{
	int i=0;
	int cnt=0; 			 // ���� ������ �� �ٿ� 7���� ����ϱ� ���� ����
	int start;                // 1���� ��µ� ���� ���� ��ġ
	int days;                // ��� ���� ������ ��

	start = get_weekday(year, month);                                          // 1���� ��µ� ���� ���� ��ġ ���
	days =get_days(year, month);

	printf("\n============< %4d. %2d >============\n\n", year, month);
	printf("------------------------------------\n");
	printf("%5s%5s%5s%5s%5s%5s%5s\n", "Sun","Mon","Tue","Wed","Thu","Fri","Sat");
	printf("------------------------------------\n");

	// �տ������� ���� ��ġ���� ���� ���
	for(i=0; i<start; i++){
		printf("%5c", ' ');
		cnt++;  // ���鵵 �� ���� �Ϻη� ī��Ʈ�Ѵ�.
	}

	// ��¥ ��� (1 ~ �� ���� ����� �� ��)
	for(i=1; i<=days; i++){
		printf("%5d", i);
		cnt++;  // ����� ������ ī��Ʈ
		if(cnt%7==0) printf("\n");  // �� �ٿ� 7���� ��µǸ� �� �ٲ۴�.
	}
	printf("\n");
	printf("------------------------------------\n");

}



/*

int get_checkRange(char* what, int min, int max) {
	int input = 0;
	printf("> %s(%d-%d) : ", what, min, max); 
	scanf("%d", &input);
	if ((input < min) || (input > max))     // ��� ������ ���ڰ� �ƴϸ� ��ȯ
	{
		printf("@ ��ȿ�� ��ȣ�� �ƴմϴ�!\n");
		return -1;
	}
	return input;
}

void deleteFromIDList(int dno) {
	int i=0;

	for (i = dno; i < (e_cnt - 1); i++)
	{
		e_num[i] = e_num[i + 1];
		e_pwd[i] = e_pwd[i + 1];
	}
	e_cnt--;										// ��ϵ� ��� �� ����
}

void insertToIDList(int id, int pwd) {
	e_num[e_cnt] = id;
	e_pwd[e_cnt] = pwd;
	e_cnt++;                                   // ��ϵ� ��� �� ����
	printf("# %d���� ��ϵǾ����ϴ�!\n", id);
}

void printIDList(){
	int i=0;

	printf("\n>> ���� ��ϵ� ���(��й�ȣ) : ");
	for (i = 0; i < e_cnt; i++)
	{
		printf("%5d(%d)", e_num[i], e_pwd[i]);
	}
	printf("\n\n");
}


void deleteID(int dno) {
	char yn = 0;

	printf("@ �̹� ��ϵǾ����ϴ�!\n");
	printf("@ ���� �Ͻðڽ��ϱ�(Y/N)?"); 

	fflush(stdin);
	scanf("%c", &yn);
	if ((yn == 'Y') || (yn == 'y'))
	{
		deleteFromIDList(dno);
		printf("@ %d���� ���� �Ǿ����ϴ�!\n", e_num[dno]);
		printIDList();
	}
	printf("@ ��� �Ǿ����ϴ�!\n");
}

void insertID(int id){
	int pwd = 0;
	int cnt =  sizeof(e_num) / sizeof(e_num[0]);    	// �ִ� ����ο� �� ���
	if (e_cnt == cnt)                          						// ����ο� ���� �ִ� �ο� ���� ������ ��ȯ
	{
		printf("@ ��� �ο��� �ʰ��Ǿ����ϴ�!");
		return;
	}
	pwd = get_checkRange("��й�ȣ", 0, 9999);
	if (pwd == 0)  return;
	insertToIDList(id, pwd);
	printIDList();
}

// ��� ��� / ����
void enroll_num(void)//1:���or ���� �Լ� 
{
	int num,pwd;                          			// ���, ��й�ȣ 
	int index;                                  // ����� �ִ� �迭�� ��ġ
	int buf=0;
	int ch=0;

	if (login_num != 0)                   // �̹� �α��� �� ���¸� ��ȯ
	{
		printf("@ �α׾ƿ� �� ����� �� �ֽ��ϴ�!\n");
		return;
	}
	else {
	
		printf("\n[ ��� ���/���� ]\n\n");
	
	    // todo: ��� ��� / ���� �ڵ� �ۼ�
	    printf("> ���(1-9999) :");
	    scanf("%d", &num);
		
		if(is_enroll_num(num)) {//����� �� ��Ͽ��� Ȯ�� ��ϵ������� 1 ������ 0 
				deleteID(1);
			//�������θ� ���� �ڵ���� ������� scanf yn�ڵ� ������. 
			
		}
		else {
			printf("> ��й�ȣ(0-9999) :");
		    scanf("%d", &pwd);
		    printf("# %d���� ��ϵǾ����ϴ�!\n\n",num);
		    printf(" ���� ��ϵ� ���(��й�ȣ)  :  %d (%d)", num  , pwd);
		    insertToIDList(num,pwd);
		    printf("e_cnt : %d",e_cnt);
		}
	}
	return;
	
}

// �α��� / �α׾ƿ�
void login_out(void)
{
	int num, pwd;
	int index;
	
	if(login_num) {//�α��λ���?
		puts("# �α׾ƿ� �Ǿ����ϴ�!");
		login_num = 0;
		return; 
	}
	
	else {//�α��� �ȵ� ��� ������ �ڵ� 
		 
		puts("\n\r[ �α��� ] \n\r");
		printf("> ��� :");
		scanf("%d",&num); 
		printf("> ��й�ȣ :");
		scanf("%d",&pwd); 
		
		//is_vaild_accunt(num,pwd) 1=��ȿ,0=��ȿ
		if( is_vaild_accunt(num,pwd) ) {//��ü ������� �Էµ� ��ȣ�� Ȯ�� 
			
		//todo �α��� �÷���  
			login_num = num;
			puts("# �α��� �Ǿ����ϴ�!");
		}
		else{
			puts(" ��й�ȣ�� Ʋ�Ƚ��ϴ�! ");
		}
	 
	}
	//�α��� üũ 
	

}

// ��ϵ� ��ȣ���� Ȯ�� ��ϵ������� 1 ������ 0 
int is_enroll_num(int num)
{
	int i;
	
	for(i=0;i<e_cnt;i++) {
		if(num==e_num[i]) {
			return 1;
		}
		else {
			
		} 
		
	}
	// todo: ��ϵ� ��ȣ���� Ȯ�� �ڵ� �ۼ�

	return 0;
}


//int is_vaild_accunt(int num,int pwd);//�Լ� �߰��� 1=��ȿ,0=��ȿ
int is_vaild_accunt(int num,int pwd)
{
	int i;
	puts("\r\nis_vaild_accunt\r\n");
	
	for(i=0 ; i<(e_cnt+2) ; i++) {
		if(e_num == num && e_pwd == pwd) {
			return 1;
		}
		else {}
		
	puts("\r\nis_vaild_accunt run loop\r\n");
	}
	
	
	return 0;
}

// ȸ�ǽ� ���� ���
void input_schedule(void)
{
	int year, month, day;    // �������� �Է��� ��

	if (login_num == 0)      // �α��ε��� �ʾҴٸ� ��ȯ
	{
		printf("@ �α��� �� ����� �� �ֽ��ϴ�!\n");
		return;
	}

	printf("\n[ ȸ�ǽ� ���� ]\n\n");

	printf("> ��, �� �Է� : ");
	scanf("%d%d", &year, &month);
	// todo: ȸ�ǽ� ���� ��� �ڵ� �ۼ�





	printf("@ ȸ�ǽ� ������ ��ϵǾ����ϴ�!\n");

}

// �ش� ��¥�� ���� ������ �� Ȯ��, ���� ��� 0 ��ȯ
int on_schedule(int year, int month, int day)
{
	int cnt = 0;
	int i;
    // todo: year, month, day�� �ش��ϴ� ������ �� ��ȯ

	return cnt;
}

// ȸ�ǽ� ���� ���� ��ȸ
void search_schedule(void)
{
	int year, month, day;    // ���� ���¸� �˻��� ��
	int cnt;                		    // ���� �� ��

	if (login_num == 0)      // �α��ε��� �ʾҴٸ� ��ȯ
	{
		printf("@ �α��� �� ����� �� �ֽ��ϴ�.\n");
		return;
	}

	printf("\n[ ȸ�ǽ� ���� ���� ��ȸ ]\n\n");

	printf("> ��, �� �Է� : ");
	scanf("%d%d", &year, &month);
	// todo: ȸ�ǽ� ���� ���� Ȯ�� �ڵ� �ۼ�





	printf("@ %d���� ����� �������� �ֽ��ϴ�!\n", cnt);

}


//=======< ���⼭ ���ʹ� �޷� ��� ���� �Լ� >=================================================

// ���� �˻� �Լ�

*/
