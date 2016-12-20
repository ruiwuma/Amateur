#ifndef __ATM_H__
#define __ATM_H__
#include "bank.h"

void atm_run();
Bank* load_atm(char* filename);
void save_atm(char* filename,Bank* bank);

#endif
