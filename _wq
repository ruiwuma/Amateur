#include "account.h"
#include <stdio.h>
#include "user.h"
#include "atm.h"
#include "bank.h"
#include "screen.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

enum USEROPS{RET,DEPO,WITH,TRAN,QUERY,LOTTERY};


#define BANKDAT "./doc/bank.dat"

char* user_login(Bank* bank)
{
	int i = 0;
	char id[20]={'0'};
	int pwd = 0;
	Act* tmp = NULL;
	for(i=0;i<3;i++)
	{
		printf("\n\t\tUser ID:  ");
		scanf("%s",id);
		tmp = find(bank,id);
		if (tmp == NULL)
		{
			printf("User ID error!\n");
			m_sleep();
			continue;
		}
		//输入密码不回显
		system("sttd -echo");
		printf("\t\tpasswd: ");
		scanf("%d",&pwd);
		//密码回显
		system("sttd echo");
		if(pwd!=tmp->passwd)
		{
			printf("\t\tPasswd error!\n");
			m_sleep();
			continue;
		}
		break;
	}
	if(i==3)
	{
		printf("YOu have try 3 time!\n");
		return NULL;
	}
	return tmp->id;
}

void withdraw_action(Bank* bank,char* curId)
{
	double amt;
	Act *tmp;
	printf("--------------WITHDRAW-----------\n");
	printf("\n\t\tInput: ");
	scanf("%lf",&amt);
	int ret = withdraw_if(bank,curId,amt);
	if(ret == 1)
		printf("wITHdraw faile!\n");
	else
	{
		printf("success!\n");
		tmp = find(bank, curId);
		tmp->jf += amt/10000;
		printf("\t\t\tJifen: %d\n",tmp->jf);
		save_atm(BANKDAT,bank);
	}
}
void deposite_action(Bank* bank,char* curId)
{
	double amt;
	printf("-----------DEPOAITEE--------\n");
	printf("\n\n\t\tInput: ");
	scanf("%lf",&amt);
	int ret = deposit_if(bank,curId,amt);
	if(ret==1)
		printf("deposite faile!\n");
	else if(ret ==2)
		printf("shortage of balance");
	else 
		printf("success");
}
void treasfer_action(Bank* bank,char* curId)
{
	char dst_id[20];
	double amt;
	printf("--------- TRANSFER--------");
	printf("\n\n\t destination ID: ");
	scanf("%s",dst_id);
	printf("\t\tTransfer Money: ");
	scanf("%lf",&amt);
	int ret = transfer_if(bank ,curId,dst_id,amt);
	if(ret==1)
		printf("Not Enough Money!\n");
	if(ret==2)
		printf("DST ID Can't be found!\n");
	else
		printf("Success!\n");

}

void lottery_draw(Bank* bank,char* curId)
{
	int opt,flag = 1;
	//Act *tmp;
	printf("\t\t\tWelcome to lotterydraw\n");
	while(flag)
	{
		printf("\t\t\t******************************\n\
				0)退出\n\
				1)积分抽奖(十积分抽奖一次)\n\
				2)积分兑奖(十积分兑换一次)\n\
			*******************************\n");
	//	m_clear();
		printf("\t\t\tInput your choice: \n");
		opt = getInt();
		m_clear();
		switch(opt)
		{
			case 0:
				flag = 0;
			//	displayByebye();
				return;
				//抽奖
			case 1:
	//			printf("10 jifen one\n");
				printf("===============lotterydraw================\n\
		1)iphone6 plus\n\
		2)iphone6\n\
		3)micAir\n\
		4)icar\n\
		5)iglass\n\
		6)thanks participate\n\
==========================================\n");
				kudo(bank,curId);
				return;
				//选奖品
			case 2:
				printf("\t\tplease choice follow lotterydraw: \n ");
				printf("\t\t\t1)iphone5s\n\
			2)iphone5\n\
			3)iphone4s\n\
			4)iphone4\n");
				lottery(bank,curId);
				return;
		}
		wait_opt();
	}
}

void lottery(Bank* bank,char* curId)
{
	int opt;
	Act *tmp;
	opt = getInt();
	tmp = find(bank,curId);
	if(tmp->jf>=10)
	{
		if(opt==1)
			tmp->jf = tmp->jf - 10;
		else if(opt == 2)
			tmp->jf = tmp->jf - 9;
		else if(opt == 3)
			tmp->jf = tmp->jf - 8;
		else
			tmp->jf = tmp->jf - 7;
		save_atm(BANKDAT,bank);
		m_sleep();
	}
	else 
		printf("jifen not enough!\n");
		return;
}

void kudo(Bank*bank,char *curId)
{
	int ret;
	Act *tmp;
	tmp = find(bank,curId);
	srand(time(NULL));
	if(tmp->jf >= 10)
	{
		ret = rand()%6+1;
		printf("%d\n",ret);
		tmp->jf = tmp->jf - 10;
		save_atm(BANKDAT,bank);
		m_sleep();
	}
	else
		printf("jifen not enough!\n");
		m_sleep();
		return;
}
void user_view(Bank* bank,char* curId)
{
	show_one(bank,curId);
}
void user_exec(Bank* bank)
{
	int opt,flag = 1;
	char* id = user_login(bank);
	if(id==NULL)
	{
		printf("login faile!\n");
		return;
	}
	while(flag)
	{
		m_clear();
		displayUserMenu();
		printf("Input your choice: ");
		opt = getInt();
		m_clear();
		switch(opt)
		{
			case DEPO:
				deposite_action(bank,id);
				break;
			case WITH:
				withdraw_action(bank,id);
				break;
			case TRAN:
				treasfer_action(bank,id);
				break;

			case QUERY:
				user_view(bank,id);
				break;
			case RET:
				flag =0;
				displayByebye();
				return;
			case LOTTERY:
				lottery_draw(bank, id);
				break;
			default:
				printf("Error Option,Try again\n");
				break;
		}
		wait_opt();
	}
}
