CXX = g++
CC = gcc
CXXFLAGS = -Iinclude -Ivendor -Ivendor/glad -Ivendor/glm -Ivendor/khr -Ivendor/stb_image -std=c++23
CFLAGS = -Iinclude -Ivendor -Ivendor/glad -Ivendor/khr

SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:src/%.cpp=bin/%.o)
GLAD_OBJ = bin/glad.o

LIBS = -Llib \
       -lglfw3 \
       -framework OpenGL \
       -framework Cocoa \
       -framework IOKit \
       -framework CoreVideo

bin/main: $(OBJS) $(GLAD_OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LIBS) -o $@

bin/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin/glad.o: src/glad.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f bin/*.o bin/main