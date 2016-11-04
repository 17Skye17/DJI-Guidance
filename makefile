CC=g++
CFLAGS=-Wall -std=c++11

TARGET=CalculatePosition
SRCS= Point.cpp
INC=-I./Onboard-SDK/osdk-core/inc -I./Onboard-SDK/osdk-wrapper/inc -I./Onboard-SDK/platform/linux/inc
OBJS=Point.o CalculatePosition.o
CalculatePosition:Point.o CalculatePosition.o
	echo $(CFLAGS)
	$(CC) -o $@ $^
clean:
	rm -rf CalculatePosition.o Point.o
Point.o:Point.cpp
	echo $(CFLAGS)
	$(CC) -Wall -std=c++11 $(CFLAGS)  $(INC) -o $@ -c $<
CalculatePosition.o:CalculatePosition.cpp
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<
