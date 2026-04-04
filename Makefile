CXX = g++
CC = gcc
CXXFLAGS = -Iinclude -Ivendor -Ivendor/glad -Ivendor/glm -Ivendor/khr -Ivendor/stb_image \
           -Ivendor/imgui -Ivendor/imgui/backends -std=c++23
CFLAGS = -Iinclude -Ivendor -Ivendor/glad -Ivendor/khr

SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:src/%.cpp=bin/%.o)
GLAD_OBJ = bin/glad.o

IMGUI_SRCS = vendor/imgui/imgui.cpp \
             vendor/imgui/imgui_draw.cpp \
             vendor/imgui/imgui_tables.cpp \
             vendor/imgui/imgui_widgets.cpp \
             vendor/imgui/backends/imgui_impl_glfw.cpp \
             vendor/imgui/backends/imgui_impl_opengl3.cpp
IMGUI_OBJS = $(IMGUI_SRCS:vendor/imgui/%.cpp=bin/imgui/%.o)

LIBS = -Lvendor/glfw/lib \
       -lglfw3 \
       -framework OpenGL \
       -framework Cocoa \
       -framework IOKit \
       -framework CoreVideo

bin/main: $(OBJS) $(GLAD_OBJ) $(IMGUI_OBJS)
	$(CXX) $(CXXFLAGS) $^ $(LIBS) -o $@

bin/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin/glad.o: src/glad.c
	$(CC) $(CFLAGS) -c $< -o $@

bin/imgui/%.o: vendor/imgui/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f bin/*.o bin/imgui/*.o bin/imgui/backends/*.o bin/main