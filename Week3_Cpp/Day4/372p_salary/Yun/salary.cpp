#include <iostream>
#include <cstring>
using namespace std;//std���ӽ����̽� ����մϴ�

class Employee//Employee Ŭ���� ���
{
private://�ܺο��� �����Ϳ� �������� ���ϵ��� ����(Encap)
	char name[100];
public://�ܺο��� ����� �� �ִ� �Լ��� ���� = �������̽�
	
	Employee(char * name)//������
	{
		strcpy(this->name, name);
	}

	void ShowYourName() const//constŰ����� �߿��� (..?)
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const = 0; // �����Լ�, ��ӹ޾� ����� ģ�����̶� virtual Ű���� ����
	virtual void ShowSalaryInfo() const = 0;

};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	PermanentWorker(char * name, int money)
		: Employee(name), salary(money)
	{}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary :" << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(char *name, int pay)
		:Employee(name), workTime(0), payPerHour(pay)
	{}
	void AddWorkTime(int time)
	{
		workTime += time;
	}

	int GetPay() const
	{
		return workTime*payPerHour;
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};


class SalesWorker : public PermanentWorker 
{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(char *name, int money, double ratio)
		:PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{}
	void AddSalesResult(int value)
	{
		salesResult += value;

	}

	int GetPay() const
	{
		return PermanentWorker::GetPay()
			+ (int)(salesResult*bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "Salary :" << GetPay() << endl << endl;
	}
};

namespace RISK_LEVEL
{
	enum { RISK_A = 30, RISK_B = 20, RISK_C = 10 };
}


class ForeginSalesWorker : public SalesWorker
{
private:
	const int risklevel;
public:
	ForeginSalesWorker(char * name, int money, double ratio, int risk)
		:SalesWorker(name, money, ratio), risklevel(risk)
	{}
	
	int GetRiskPay() const
	{
		return (int)(SalesWorker::GetPay() * risklevel / 100.0);
	}

	int GetPay() const
	{
		return SalesWorker::GetPay() + GetRiskPay();
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary :" << SalesWorker::GetPay() << endl;
		cout << "Riskey Pay :" << GetRiskPay() << endl;

	}

};


class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{}
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalaryInfo()const
	{
		for (int i = 0; i < empNum; i++)
			//sum += empList[i]->GetPay();
			empList[i]->ShowSalaryInfo();
		//		
		//cout << "Salary SUM :" << sum << endl;
	}

	void ShowTotalSalary()const
	{
		int sum = 0;
		///////////////
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		//////////////
		cout << "Salary SUM :" << sum << endl;
	}


	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};


int main(void)
{
	EmployeeHandler handler;

	ForeginSalesWorker *fseller1
		= new ForeginSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeginSalesWorker *fseller2
		= new ForeginSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	handler.ShowAllSalaryInfo();
	return 0;
}




/*
//test
class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "num=" << num << ",";
		cout << "address=" << this << endl;
	}

	void ShowSimpleData()
	{
		cout << num << endl;
	}
	SoSimple * GetThisPointer()
	{
		return this;
	}
};
int main(void)
{
	SoSimple sim1(100); //sim1 ��ü ����(SosimpleŬ����), 100���� �ʱ�ȭ
	SoSimple *ptr1 = sim1.GetThisPointer();
	cout << ptr1 << ",";
	ptr1->ShowSimpleData();
	//sim1��ü�� �ּ� Ȯ��
	cout << &sim1 << endl;
	//�̷����� ��� �ͽ��ϴ�!!


	SoSimple sim2(200);
	SoSimple *ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ",";
	ptr2->ShowSimpleData();
	//sim2 ��ü�� �ּ� Ȯ��
	cout << &sim1 << endl;
	//
	return 0;

}
*/



/*
//350p
class Employee {
private:
	char name[100];
public:
	Employee(char * name)
	{
		strcpy(this->name, name);
	}
	
	void ShowYourName() const
	{
		cout << "name : " << name << endl;

	}

	virtual int GetPay() const
	{
		return 0;
	}

	virtual void ShowSalaryInfo() const
	{
	}
};

class PermanetWorker : public Employee
{
private:
	int salary;
public:
	PermanetWorker(char * name, int money)
		: Employee(name), salary(money)
	{}

	virtual int GetPay() const
	{
		return salary;
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salay : " << GetPay() << endl << endl;

	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalaryInfo()const
	{
		for (int i = 0; i < empNum; i++)
			//sum += empList[i]->GetPay();
			empList[i]->ShowSalaryInfo();
			//		
		//cout << "Salary SUM :" << sum << endl;
	}
	
	void ShowTotalSalary()const
	{
		int sum = 0;
		///////////////
		for (int i = 0; i < empNum; i++)
		sum += empList[i]->GetPay();
		//////////////
		cout << "Salary SUM :" << sum << endl;
	}


	~EmployeeHandler()
	{
	for (int i = 0; i < empNum; i++)
	delete empList[i];
	}

	};

	int main(void)
	{
	EmployeeHandler handler;


	handler.AddEmployee(new PermanetWorker("KIM", 1000));
	handler.AddEmployee(new PermanetWorker("LEE", 1500));
	handler.AddEmployee(new PermanetWorker("JUN", 1700));

	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();
	}
	*/




/*
//347p
using namespace std;
class First
{
public:
	virtual void MyFunc() { cout << "First Func" << endl; }
};

class Second : public First
{
public:
	virtual void MyFunc() { cout << "Second Func" << endl; }
};

class Third : public Second
{
public:
	virtual void MyFunc() { cout << "third Func" << endl; }
};

int main(void)
{
	Third * tptr = new Third();
	Second * sptr = tptr;
	First * fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	
	delete tptr;
	return 0;

}
*/

/*
//test
using namespace std;
int main(int argc, char* *argv)
{
	cout << "helloworld!" << endl;

	return 0;
}

*/




/*
//331p
class Employee {
private:
	char name[100];
public:
	Employee(char * name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name : " << name << endl;

	}
};

class PermanetWorker : public Employee
{
private :
	int salary;
public :
	PermanetWorker(char * name, int money)
		: Employee(name), salary(money)
	{}

	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salay : " << GetPay() << endl << endl;

	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{}
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalaryInfo()const
	{
//		
		//for (int i = 0; i < empNum; i++)
		//sum += empList[i]->GetPay();
//		
		//cout << "Salary SUM :" << sum << endl;
	}
	/*
	void ShowTotalSalary()const
	{
		int sum = 0;
	//	
		//for (int i = 0; i < empNum; i++)
		//sum += empList[i]->GetPay();
		//////////////
		cout << "Salary SUM :" << sum << endl;

	}
	

	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}

};

int main(void)
{
	EmployeeHandler handler;

	
	handler.AddEmployee(new PermanetWorker("KIM", 1000));
	handler.AddEmployee(new PermanetWorker("LEE", 1000));
	handler.AddEmployee(new PermanetWorker("JUN", 1000));

	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();
}
*/




/*
//
class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	FruitSeller(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}

	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	void ShowSalesResult() const
	{
		cout << "�������" << numOfApples << endl;
		cout << "�Ǹż���" << myMoney << endl;

	}
};


class Buyer
{
private:
	int myMoney;
	int numOfApples;

public:
	Buyer(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}

	void BuyApples(FruitSeller &seller, int money)
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;

	}

	void ShowBuyResult() const
	{
		cout << "�����ܾ�" << myMoney << endl;
		cout << "�������" << numOfApples << endl;

	}
};

int main(void)
{
	FruitSeller seller(1000, 20, 0);
	Buyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "�����Ǹ���" << endl;
	seller.ShowSalesResult();

	cout << "���ϱ�����" << endl;
	buyer.ShowBuyResult();

}
*/





/*
//172p
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass(int n1 = 0, int n2 = 0)
	{
		cout << "constructor called" << endl;
		num1 = n1;
		num2 = n2;
	}
	~SimpleClass(void)
	{
		cout << "destructor called" << endl;
	}
	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}

};

int main(void)
{
	SimpleClass sc1();
	SimpleClass Mysc = sc1();
	Mysc.ShowData();
	return 0;
}

SimpleClass sc1()
{
	SimpleClass sc(20, 30);
	return sc;
}
*/