CFLAGS	= -Wall
LDLIBS	= -lm
CXXFLAGS = $(CFLAGS)

TARGS = binomialToPoisson print_test 

all: $(TARGS)

binomialToPoisson: binomial.o poisson.o gener.o binomialToPoisson.o print.o
print_test: print_test.o print.o

clean:
	$(RM) *.o $(TARGS)

