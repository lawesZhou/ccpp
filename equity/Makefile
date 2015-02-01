CPPFLAGS = -I /usr/include/qt4/QtCore -I /usr/include/qt4 \
	   -I /usr/include/qt4/QtGui $(shell mysql_config --cflags)
	   
CXX = g++
CXXFLAG = -Wall 
LDLIBS_QT = -lQtCore -lQtGui
LDLIBS_MYSQL = $(shell mysql_config --libs)
LD = g++

TARGS = qt mysql_connect
all: $(TARGS)

qt:qt.o mypainterwidget.o
	g++ $^ -o $@ $(LDLIBS_QT)
mysql_connect: mysql_connect.o
	g++ $^ -o $@ $(LDLIBS_MYSQL)

clean:
	$(RM) *.o $(TARGS)
