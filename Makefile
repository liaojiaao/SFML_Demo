# 编译器和编译选项
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I/usr/include/SFML/

# 库链接选项
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# 目标文件
OBJ = main.o

# 可执行文件名
TARGET = sfml-app

# 默认目标
all: $(TARGET)

# 构建可执行文件
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

# 编译源文件生成目标文件
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# 清理构建文件
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
