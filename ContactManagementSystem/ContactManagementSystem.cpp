#include<iostream>
#include<string>
#define Max 1000
using namespace std;

void Showmenu() 
{
	cout << "**********************" << endl;
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****0.退出通讯录*****" << endl;
	cout << "**********************" << endl;
};

struct Information 
{//联系人结构体
	string name;
	int age;
	int sex;//1.男 2.女
	string num;
}information;

struct Contact 
{//通讯录结构体
	Information information[Max];
	int acnum = 0;//实际人数
}contact;

void Addnum(Contact * contact) 
{
	if (contact->acnum == 1000)
		cout << "通讯录已满" << endl;
	else//开始添加
	{
		cout << "姓名" << endl;
		cin >> contact->information[contact->acnum].name;
		cout << "年龄" << endl;
		cin >> contact->information[contact->acnum].age;
		cout << "性别(1 = 男，2 = 女)" << endl;
		int sex = 0;
		while (true) 
		{
			cin >> sex;
			if (sex == 1 || sex == 2) 
			{
				contact->information[contact->acnum].sex = sex;
				break;
			}
			else
				cout << "输入错误，请重新输入" << endl;
		}
		cout << "电话" << endl;
		cin >> contact->information[contact->acnum].num;
		++contact->acnum;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
};

void Show(Contact * contact) 
{
	if (contact->acnum == 0) 
	{
		cout << "通讯录中没有对象" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < contact->acnum; i++)
		{
			cout << "姓名：" << contact->information[i].name << endl;
			cout << "年龄：" << contact->information[i].age << endl;
			string Sex;
			if (contact->information[i].sex == 1)
				Sex = "男";
			else
				Sex = "女";
			cout << "性别：" << Sex << endl;
			cout << "电话号码：" << contact->information[i].num << endl;
			system("pause");
			system("cls");
		}
	}
}

int Exist(Contact* contact, string Name) 
{
	for (int i = 0; i < contact->acnum; i++) 
	{
		if (Name == contact->information[i].name)
			return i;
	}
	return -1;
}

void Delete(Contact* contact)
{
	string name;
	cout << "输入要删除的人的姓名" << endl;
	cin >> name;
	int ret = Exist(contact, name);
	if (ret == -1)
	{
		cout << "通讯录中没有对象" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (ret; ret < contact->acnum; ret++)
		{
			contact->information[ret] = contact->information[ret + 1];
		}
		contact->acnum--;
		cout << "删除成功" << endl;
		system("pause");
		system("cls");
	}
}

void Find(Contact* contact) {
	string name;
	cout << "输入要查找的人的姓名" << endl;
	cin >> name;
	int ret = Exist(contact, name);
	if (ret == -1)
	{
		cout << "不存在此人" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "姓名：" << contact->information[ret].name << endl;
		cout << "年龄：" << contact->information[ret].age << endl;
		string Name;
		if (contact->information[ret].age == 1)
			Name = "男";
		else
			Name = "女";
		cout << "性别：" << Name << endl;
		cout << "电话号码：" << contact->information[ret].num << endl;
		system("pause");
		system("cls");
	}
}

void Change(Contact* contact)
{
	string name;
	cout << "请输入想要修改的人的姓名" << endl;
	cin >> name;
	int ret = Exist(contact, name);
	if (ret == -1)
	{
		cout << "不存在此人" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "姓名" << endl;
		cin >> contact->information[ret].name;
		cout << "年龄" << endl;
		cin >> contact->information[ret].age;
		cout << "性别(1 = 男，2 = 女)" << endl;
		cin >> contact->information[ret].sex;
		cout << "电话" << endl;
		cin >> contact->information[ret].num;
		cout << "修改成功" << endl;
		system("pause");
		system("cls");
	}
}

void Clear(Contact* contact)
{
	contact->acnum = 0;
	cout << "清除成功" << endl;
	system("pause");
	system("cls");
}


int main() 
{

	int select = 0;
	while (true) 
	{
		Showmenu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			system("cls");
			Addnum(&contact);
			break;
		case 2://显示联系人
			system("cls");
			Show(&contact);
			break;
		case 3://删除联系人
			system("cls");
			Delete(&contact);
			break;
		case 4://查找联系人
			system("cls");
			Find(&contact);
			break;
		case 5://修改联系人
			Change(&contact);
			system("cls");
			break;
		case 6://清空联系人
			Clear(&contact);
			system("cls");
			break;
		case 0://退出系统
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	system("pause");
	return 0;
}