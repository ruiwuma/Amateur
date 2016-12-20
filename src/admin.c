#include "screen.h"
#include <stdio.h>
#include "bank.h"
#include <string.h>
#include <stdlib.h>
#include "admin.h"
#include "account.h"

enum adminOps{RET,ADD,DEL,MOD,SHOW};
int admin_login()
{
	int i,flag = 0;
	char name[20]={'\0'};
	char pwd[20] = {'\0'};
	for(i=0;i<3;i++)
	{
	//	displayWelcome();
		m_clear();
		printf("\n\n\tAdmin Account:  ");
		scanf("%s",name);
		if(strcmp(name,"admin"))
		{
			printf("\n\t\tAdmin Account error!\n");
			m_sleep(1);
			continue;
		}
		//密码输入不回显
		system("stty -echo");
		printf("\n\t\tPasswd: ");
		scanf("%s",pwd);
		//回复回显
		system("stty echo");
		if(strcmp(pwd,"admin"))
		{
			printf("\n\t\tAdmin Passwd error!\n");
			m_sleep(1);
			continue;
		}
		flag = 1;
		break;
	}
	return flag;
}//登录
void add_action(Bank* bank)
{
	Act new;
	printf("\n\n\t\tInput ID: ");
	scanf("%s",new.id);
	printf("\t\tInput Name: ");
	scanf("%s",new.name);
	printf("\t\tInput Passwd: ");
	scanf("%d",&new.passwd);
	printf("\t\tInput open money");
	scanf("%lf",&new.balance);
	printf("\t\tInput jifen: ");
	scanf("%d",&new.jf);

	int ret = add_account(bank,&new);
	if (ret ==1)
		printf("Account is already exited!\n");
	else if(ret ==2 )
		printf("System error!\n");
	else
		printf("Add Account success!\n");
}//开户操作
void del_action(Bank* bank)
{
	char id[20];
	printf("\n\n\t\tInput Del Account: ");
	scanf("%s",id);
	show_one(bank,id);
	int ret = del_account(bank,id);
	if (ret == 1)
		printf("\n\t\tAccount is not exited\n");
	else
	{
		printf("\n\t\tDelete success!\n");
	}
}//销户操作
void changePwd_action(Bank* bank)
{
	char id[20];
	int oldpwd;
	int newpwd;
	int tmp;
	printf("Input Account ID: ");
	scanf("%s",id);
	printf("Input Old Passwd: ");
	scanf("%d",&oldpwd);
	printf("Input New Passwd: ");
	scanf("%d",&newpwd);
	printf("Confire New Passwd: ");
	scanf("%d",&tmp);
	if(newpwd!=tmp)
		printf("Not The Same!");
	int ret = changePwd_if(bank,id,oldpwd,newpwd);
	if(ret==1)
		printf("Account Can't be found!\n");
	else if(ret == 2)
		printf("Old Passwd ISeRROR!\n");
	else
		printf("Change Passwd Success!\n");
}//修改密码
void show_all_action(Bank* bank)
{
	show_all(bank);
}//显示所有用户
void admin_exec(Bank* bank)
{

	int opt;
	int flag= 1;
	if(admin_login())
	{
		while(flag)
		{
			displayAdminMenu();
			opt =getInt();
			switch(opt)
			{
				case ADD:
					add_action(bank);
					break;
				case DEL:
					del_action(bank);
					break;
				case MOD:
					changePwd_action(bank);
						break;
				case SHOW:
						show_all_action(bank);
						break;
				case RET:
						flag = 0;
					displayByebye();
					break;
				default:
					printf("Error opt Try again!\n");
					break;
			}
			wait_opt();
		}
	}
}//管理员执行操作函数

