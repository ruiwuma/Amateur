#ifndef __USER_H__
#define __USER_h__
#include "bank.h"

char* user_login();//登录
void withdraw_action(Bank* bank,char* curId);//存款
void deposite_action(Bank* bank,char* curId);//取款
void treasfer_action(Bank* bank,char* curId);//转帐
void lottery_draw(Bank* bank,char* curId);//抽奖
void user_view(Bank* bank,char* curId);//查询
void user_exec(Bank* bank);//用户执行
void kudo(Bank*bank, char *curId);
void lottery(Bank* bank,char* curId);
//void changePwd_action(Bank* bank);//修改密码



#endif
