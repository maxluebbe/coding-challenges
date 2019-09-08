CC=g++
CC_FLAGS=-lm -lcrypt -O2 -pipe

uva10137: uva10137.c
	$(CC) uva10137.c $(CC_FLAGS) 
