CXXFLAGS = -c -I"include" -Wall -Werror -std=c++26
LINKFLAGS = -lopengl32 -lgdi32
SRC = src/
BUILD = build/

all: $(BUILD)main.exe

$(BUILD)main.exe: $(BUILD)main.o
	g++ $(BUILD)main.o libs/GLFW/libglfw3.a -o $(BUILD)main.exe $(LINKFLAGS)

$(BUILD)main.o: $(SRC)main.cc
	g++ $(CXXFLAGS) $(SRC)main.cc -o $(BUILD)main.o

clean:
	if exist "$(BUILD)" del /F /Q "$(BUILD)\*.*"