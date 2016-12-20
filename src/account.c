
#include <stdio.h>
#include "account.h"
#include <string.h>

double withdraw(Act* act,double atm)
{
	return act->balance = act->balance + atm;
}//存款
double deposite(Act* act,double atm)
{
	return act->balance = act->balance -atm;
}//取款
int changepasswd(Act* act,int pwd)
{
	return act->passwd = pwd;
}//修改密码
void display(Act* act)
{
	printf("name:%s\tid:%s\tbalance:%f\tpasswd:%d\tjifen:%d \n",act->name,act->id,act->balance,act->passwd,act->jf);
}//打印
