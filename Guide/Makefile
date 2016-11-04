#定义编译器
CXX     = g++
#定义生成文件
TARGET  = main
#定义生成依赖文件 
OBJECTS = main.o DJI_utility.o
#定义头文件包含目录
CFLAGS  = -g -Wall -I/usr/local/include -I../../../include
#定义动态链接库路径、opencv路径及选项
LDFLAGS = -Wl,-rpath,./ -lpthread -lrt -L./ -L/usr/local/lib/ -lDJI_guidance -lusb-1.0 `pkg-config --cflags --libs opencv` 
$(TARGET) : $(OBJECTS)
    $(CXX) -o $(TARGET) $(OBJECTS) $(LDFLAGS)
main.o : main.cpp DJI_utility.h
    $(CXX) $(CFLAGS) -c main.cpp DJI_utility.h
DJI_utility.o : DJI_utility.cpp DJI_utility.h
    $(CXX) $(CFLAGS) -c DJI_utility.cpp DJI_utility.h
clean:
    rm -rf *.o *.gch *.avi $(TARGET)
