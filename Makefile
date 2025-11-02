var := $(patsubst %.c, %.o,$(wildcard *.c))
calc.exe : $(var)
	gcc -o APC $(var)
clean :
	rm *.o *.exe 