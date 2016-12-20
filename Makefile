bin/atm:./obj/account.o ./obj/bank.o ./obj/admin.o ./obj/user.o ./obj/screen.o ./obj/atm.o
	gcc ./obj/*.o -o ./bin/atm 

obj/bank.o:./src/bank.c 
	gcc -c src/bank.c -o obj/bank.o -Iinclude
obj/admin.o:./src/admin.c 
	gcc -c src/admin.c -o obj/admin.o -Iinclude
obj/user.o:./src/user.c 
	gcc -c src/user.c -o  obj/user.o -Iinclude
obj/screen.o:./src/screen.c
	gcc -c src/screen.c -o obj/screen.o -Iinclude
obj/atm.o:./src/atm.c 
	gcc -c src/atm.c -o obj/atm.o -Iinclude
obj/account.o:./src/account.c 
	gcc -c src/account.c -o obj/account.o -Iinclude

clean:
	rm ./obj/*
