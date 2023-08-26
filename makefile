main.exe: SDBAPP.obj SDB.obj
	gcc SDBAPP.obj SDB.obj -o main.exe

SDBAPP.obj: SDBAPP.c SDB.h
	gcc -c SDBAPP.c -o SDBAPP.obj

SDB.obj: SDB.c SDB.h
	gcc -c SDB.c -o SDB.obj
