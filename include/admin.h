#ifndef __ADMIN_H__
#define __ADMIN_H__
#include "bank.h"

int admin_login();//登录
void add_action(Bank* bank);//开户操作
void del_action(Bank* bank);//销户操作
void changePwd_action(Bank* bank);//修改密码
void show_all_action(Bank* bank);//显示所有用户
void admin_exec(Bank* bank);//管理员执行操作函数
//void lottery_draw(Bank*bank,char* curId);//抽奖函数
#endif
