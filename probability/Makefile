CFLAGS	= -Wall -g
LDLIBS	= -lm
CXXFLAGS = $(CFLAGS)

TARGS = dist print_test 

all: $(TARGS)

#binomialToPoisson: binomial.o poisson.o gener.o binomialToPoisson.o print.o
dist: binomial.o poisson.o distribution.o dist.o print.o
print_test: print_test.o print.o

clean:
	$(RM) *.o $(TARGS)

