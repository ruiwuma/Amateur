#ifndef __SCREEN_H__
#define __SCREEN_H__

	int getInt();//获取用户输入的整型数{scanf("")}
	void print_err(char* str);//错误处理函数
	void m_clear();//清屏
	void m_sleep();//休眠
	void wait_opt();//等待回车健
	void displayWelcome();//打印欢迎界面
	void displayAtmMenu();//打印选择账户界面
	void displayAdminMenu();//打印管理员菜单界面
	void displayUserMenu();//打印普通用户菜单界面
	void displayByebye();//打印退出界面

	void displayAbout();//打印系统信息
	void readFile(char* filename);//读取文件内容
#endif
