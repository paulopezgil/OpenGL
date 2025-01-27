CXXFLAGS = -c -I"../../include" -Wall -Werror -std=c++26
LINKFLAGS = -lopengl32 -lgdi32
LIBS = $(wildcard ../../libs/**/*.a)

all: main.exe

main.exe: main.o handleException.o $(LIBS)
	g++ main.o handleException.o $(LIBS) -o main.exe $(LINKFLAGS)

main.o: main.cc
	g++ $(CXXFLAGS) main.cc -o main.o

handleException.o: handleException.cc
	g++ $(CXXFLAGS) handleException.cc -o handleException.o

clean:
	del /F /Q *.o *.exe