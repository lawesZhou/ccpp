CPPFLAGS = $(shell mysql_config --cflags)
	   
CXX = g++
CXXFLAGS = -Wall 
LDLIBS_MYSQL = $(shell mysql_config --libs)
LD = g++

TARGS = test
all: $(TARGS)

test: test.o static_data.o
	g++ $^ -o $@ $(LDLIBS_MYSQL)

clean:
	$(RM) *.o $(TARGS)
