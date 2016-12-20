#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

typedef struct account Act;

struct account
{
	char name[20];//用户名
	int passwd;//密码
	double balance; //余额
	char id[20];		//卡号
	int jf;     //积分
};

double withdraw(Act* act,double atm);//存款
double deposite(Act* act,double atm);//取款
int changepasswd(Act* act,int pwd);//修改密码
void display(Act* act);//打印

#endif
