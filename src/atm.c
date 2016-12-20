#include <stdio.h>
#include "bank.h"
#include "atm.h"
#include "admin.h"
#include "screen.h"
#include "user.h"

#define BANKDAT "./doc/bank.dat"

enum ATMOPS{EXIT,USER,ADMIN,ABOUT};
void atm_run()
{
//	Bank* bank = create_bank(10);
	Bank* bank = load_atm(BANKDAT);
	if (bank == NULL)
	{
		print_err("Power On faile!\n");
		return;
	}
	int opt;
	while(1)
	{
		m_clear();//清屏
		displayWelcome();
		printf("loading...\n");
		m_sleep();
		m_clear();
		displayAtmMenu();
		opt = getInt();
		switch(opt)
		{
			case USER:
				user_exec(bank);
			//	sava_atm(BANKDAT,bank);
				break;
			case ABOUT:
				displayAbout();
			//	sava_atm(BANKDAT,bank);
				wait_opt();
				break;
			case ADMIN:
				admin_exec(bank);
			//	sava_atm(BANKDAT,bank);
				break;
			case EXIT:
				save_atm(BANKDAT,bank);
				//destroy_bank(bank);
				displayByebye();
				return;
			default:
				printf("error option try again\n");
				save_atm(BANKDAT,bank);
				break;
		}
	}
}

int main(void)
{
	atm_run();
	return 0;
}

Bank* load_atm(char* filename)
{
	FILE* fp = fopen(filename,"rw");
	if(fp == NULL)
	{
		Bank* bank = create_bank(0);
		print_err("In load open.dat file!\n");
		return bank;
	}
	int counter;
	fread(&counter,sizeof(int),1,fp);
	Bank* bank = create_bank(counter);
	bank->counter = counter;
	fread(bank->act,sizeof(Act),counter,fp);
	fclose(fp);
	return bank;

}

void save_atm(char* filename,Bank* bank)
{
	FILE* fp = fopen(filename,"wb");
	if(fp == NULL)
	{
		print_err("open bank.dat faile!\n");
		return;
	}
	fwrite(&bank->counter,sizeof(int),1,fp);
	fwrite(bank->act,sizeof(Act),bank->counter,fp);
	fclose(fp);
}

