
BINDIR = ./bin

CXX = /usr/bin/g++
CXXFLAGS = -Wall
CXXFLAGS += -I .

SOURCES = $(wildcard $(CURDIR)/*.cpp)
OBJECTS = $(patsubst $(CURDIR)/%.cpp, $(CURDIR)/%.o, $(SOURCES)) 