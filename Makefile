CXX = g++
CXXFLAGS = -std=c++11 -Wall
INCLUDES = -I$(shell brew --prefix nlohmann-json)/include
LIBS = -lcurl

all: chatty_chat

chatty_chat: main.o Chatty.o
	$(CXX) $(CXXFLAGS) -o chatty_chat main.o Chatty.o $(LIBS)

main.o: main.cpp Chatty.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c main.cpp

Chatty.o: Chatty.cpp Chatty.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Chatty.cpp

clean:
	rm -f *.o chatty_chat