#include "admin.h"
#include "bank.h"
#include "screen.h"
#include "account.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Bank* create_bank(int max)
{
	Bank* b=(Bank*)malloc(sizeof(Bank));
	if(b == NULL)
		return NULL;

	memset(b,0,sizeof(Bank));

	b->max_no=max;
	b->counter=0;

	b->act = (Act*)calloc(max,sizeof(Act));

	if(b->act == NULL)
	{
		free(b);
		b = NULL;
		return NULL;
	}
	return b;
}


void destory_bank(Bank* bank)
{
	if(bank->act == NULL)
		free(bank->act);
	free(bank);
	if(bank == NULL)
		return;
}
void show_all(Bank* bank)
{
	int i=0;
	for(i=0;i < bank->counter;i++)
	{
		display(&(bank->act[i]));
	} 
}

Act* find(Bank* bank,char *id)
{
	int i;
	for(i = 0; i< bank->counter;i++){
		if(strcmp(bank->act[i].id,id) == 0)
		{
			return &bank->act[i];
		}
	}
	printf("Can't find the account\n");
	return NULL;
}


int add_account(Bank* bank,Act* act)
{
	Act *tmp = find(bank,act->id);
	if(tmp != NULL)
		return 1;
	if(bank->counter >= bank->max_no)
	{
		Act *tmp = bank->act;
		bank->act = (Act*)realloc(bank->act,\
				(bank->max_no+5)*sizeof(Act));

		if(bank->act== NULL)
		{
			bank->act = tmp;
			return 2;
		}
		bank->max_no +=5;
	}
		bank->act[bank->counter++] = *act;
		return 1;
	}
				
int del_account(Bank* bank,char* id)
{
	Act *tmp = find(bank,id);
	if(tmp == NULL)
		return 1;
	int i,j;
	for(i=0;i<bank->counter;i++)
	{
		if(!strcmp(bank->act[i].id,id))
				{
				for(j=i;j<bank->counter-1;j++)
				{
				bank->act[j] = bank->act[j+1];
				}
				break;
		}
	}
	bank->counter--;
	return 0;

}
int changePwd_if(Bank* bank,char* id,int oldpwd,int pwd)
{
	Act* tmp = find(bank,id);
	if(tmp == NULL)
		return 1;
	if(tmp->passwd != oldpwd)
		return 2;
	changepasswd(bank->act,pwd);
	return 0;
  
}
int transfer_if(Bank* bank,char*  src_id,char* dst_id,double amt)
{
	int ret = deposit_if(bank,src_id,amt);
	if(ret != 0)
	   return 1;
	ret = withdraw_if(bank,dst_id,amt);
	if(ret != 0)
	{
		withdraw_if(bank,src_id,amt);
		return 2;
	}
   return 0;
}

		

int  withdraw_if(Bank* bank,char* id, double amt)
{
	Act* tmp=find(bank,id);
	if(tmp == NULL)
		return 1;
	withdraw(tmp,amt);
		return 0;
}
int deposit_if(Bank* bank,char* id,double amt)
{
	Act* tmp=find(bank,id);
	if(tmp == NULL)
	     return 1;
	if(amt > tmp->balance)
		return 2;
	deposite(tmp,amt);
	return 0;

}
int  show_one(Bank* bank,char* id)
{
	Act* tmp = find(bank,id);
	if(tmp == NULL)
		return 1;
	display(tmp);
	return 0;
}













