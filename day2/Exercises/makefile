####################################################################### 
all: pi.exec quadratic.exec root_newton.exec hello_name.exec speedup.exec
####################################################################### 

## pi
pi.exec : pi.cpp
	g++ pi.cpp -o pi.exec

## quadratic
quadratic.exec : quadratic.cpp
	g++ quadratic.cpp -o quadratic.exec

## root newton
root_newton.exec : root_newton.cpp
	g++ root_newton.cpp -o root_newton.exec

## hello name
hello_name.exec : hello_name.cpp
	g++ hello_name.cpp -o hello_name.exec

## speedup
speedup.exec : speedup.cpp
	g++ speedup.cpp -o speedup.exec

####################################################################### 

clean :
	rm -f *.exec
