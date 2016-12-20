#include "admin.h"
#include <unistd.h>
#include <stdio.h>
#include "screen.h"
#include <stdlib.h>

int getInt()
{
	int n;
	scanf("%d",&n);
	return n;
}//获取用户输入的整型数{scanf("")}
void print_err(char* str)
{
	printf("%s\n",str);
}//错误处理函数
void m_clear()
{
	system("clear");//调用系统命令清屏
}//清屏
void m_sleep()
{
	system("sleep 1");//调用系统函数
}//休眠
void wait_opt()
{
	printf("press 'Enter' to continue...\n");
	getchar();
	getchar();
}//等待回车健
void displayWelcome()
{
	readFile("./doc/welcome_info");
}//打印欢迎界面
void displayAtmMenu()
{
	readFile("./doc/bank.menu");
}//打印选择账户界面
void displayAdminMenu()
{
	readFile("./doc/admin_menu");
//	printf("-----------Admin Menu--------\n");
//	printf("1.ADD\n2.DEL\n3.MOD\n4.SHOW\n0.EXIT\n");
//	printf("------------------------------------\n");
}//打印管理员菜单界面
void displayUserMenu()
{
	readFile("./doc/user_menu");
}//打印普通用户菜单界面
void displayByebye()
{
	readFile("./doc/byebye");

}//打印退出界面

void displayAbout()
{
	readFile("./doc/copyright.txt");
}
void readFile(char* filename)//读取文件内容
{
	FILE *fp = fopen(filename,"r");
	if(fp == NULL)
	{
		print_err("open menu_file faile!\n");
		return;
	}
	int ch;
	printf("\33[?25l]");//隐藏光标
	while((ch = fgetc(fp))!= EOF)
	{
		if(ch == '\n')
			usleep(5000);
		fputc(ch,stdout);
	}
//	printf("\33[?25h]");//显示光标
	fclose(fp);
}
