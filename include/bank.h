#ifndef __BANK_H__
#define __BANK_H__

#include "account.h"
typedef struct bank Bank;

struct bank
{
	Act *act;//账户
	int max_no;//能开通最大的账户数
	int counter;//当前开通的账户数

};

Bank* create_bank(int max);//创建银行
void destroy_bank(Bank* bank);//销毁银行
void show_all(Bank* bank);//显示所有账户
Act* find(Bank* bank,char *id);//查找账户

int add_account(Bank* bank,Act* act);//添加账户
int del_account(Bank* bank,char* id);//删除账户
int changePwd_if(Bank* bank,char* id,int oldpwd,int pwd);//修改密码

int transfer_if(Bank* bank,char* src_id,char* dst_id,double amt);//转帐
int withdraw_if(Bank* bank,char* id,double amt);//存款
int deposit_if(Bank* bank,char* id,double amt);//取款
int show_one(Bank* bank,char* id);//查找单个用户

#endif
