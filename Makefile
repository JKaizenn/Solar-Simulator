CXX = g++
CC = gcc
ROOT = solarSim
CXXFLAGS = -I$(ROOT)/include -I$(ROOT)/vendor -I$(ROOT)/vendor/glad -I$(ROOT)/vendor/glm \
           -I$(ROOT)/vendor/khr -I$(ROOT)/vendor/stb_image \
           -I$(ROOT)/vendor/imgui -I$(ROOT)/vendor/imgui/backends -std=c++23
CFLAGS = -I$(ROOT)/include -I$(ROOT)/vendor -I$(ROOT)/vendor/glad -I$(ROOT)/vendor/khr

SRCS = $(wildcard $(ROOT)/src/*.cpp)
OBJS = $(SRCS:$(ROOT)/src/%.cpp=bin/%.o)
GLAD_OBJ = bin/glad.o

IMGUI_SRCS = $(ROOT)/vendor/imgui/imgui.cpp \
             $(ROOT)/vendor/imgui/imgui_draw.cpp \
             $(ROOT)/vendor/imgui/imgui_tables.cpp \
             $(ROOT)/vendor/imgui/imgui_widgets.cpp \
             $(ROOT)/vendor/imgui/backends/imgui_impl_glfw.cpp \
             $(ROOT)/vendor/imgui/backends/imgui_impl_opengl3.cpp
IMGUI_OBJS = $(IMGUI_SRCS:$(ROOT)/vendor/imgui/%.cpp=bin/imgui/%.o)

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
    LIBS = -L$(ROOT)/vendor/glfw/lib \
           -lglfw3 \
           -framework OpenGL \
           -framework Cocoa \
           -framework IOKit \
           -framework CoreVideo
else
    LIBS = -lglfw \
           -lGL \
           -ldl \
           -lpthread \
           -lX11 \
           -lXrandr \
           -lXi \
           -lXinerama \
           -lXcursor
endif

bin/main: $(OBJS) $(GLAD_OBJ) $(IMGUI_OBJS)
	$(CXX) $(CXXFLAGS) $^ $(LIBS) -o $@

bin/%.o: $(ROOT)/src/%.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin/glad.o: $(ROOT)/src/glad.c
	@mkdir -p bin
	$(CC) $(CFLAGS) -c $< -o $@

bin/imgui/%.o: $(ROOT)/vendor/imgui/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f bin/*.o bin/imgui/*.o bin/imgui/backends/*.o bin/main