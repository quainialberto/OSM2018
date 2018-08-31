CPP = g++
CF  = --std=c++11 -O3 -Wall -ffast-math
PAR = -fopenmp

##############################################################################
all: pi.o pi_MC.o quadratic.o hello_name.o speedup.o root_newton.o #par_pi.o
############################################################################## 

## pi
pi.o : pi.cpp
	$(CPP) $(CF) pi.cpp -o pi.o

## pi Monte Carlo
pi_MC.o : pi_MC.cpp
	$(CPP) $(CF) pi_MC.cpp -o pi_MC.o

## pi parallel
#par_pi.o : par_pi.cpp
#	$(CPP) $(CF) $(PAR) par_pi.cpp -o par_pi.o

## quadratic
quadratic.o : quadratic.cpp
	$(CPP) $(CF) quadratic.cpp -o quadratic.o

## hello name
hello_name.o : hello_name.cpp
	$(CPP) $(CF) hello_name.cpp -o hello_name.o

## speedup
speedup.o : speedup.cpp
	$(CPP) $(CF) speedup.cpp -o speedup.o

## root_newton
root_newton.o : root_newton.cpp
	$(CPP) $(CF) root_newton.cpp -o root_newton.o
####################################################################### 

clean :
	rm -f *.o
