CXX = g++
CC = gcc
CXXFLAGS = -std=c++11 -Wall -I.
CFLAGS = -Wall -I.
LDFLAGS = -L. -static-libgcc -static-libstdc++

# 源文件
SOURCES = main.cpp \
		Graph.cpp \
		Queue.cpp \
		Stack.cpp \
		FavoritesManager.cpp \
		Auth.cpp \
		Admin.cpp \
		dataManager.cpp

# 目标文件
OBJECTS = $(SOURCES:.cpp=.o) sqlite3.o
TARGET = NavSystem.exe

all: $(TARGET)

# 编译规则
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

sqlite3.o: sqlite3.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

clean:
	del /Q *.o *.exe

.PHONY: all clean 