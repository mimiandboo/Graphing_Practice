all: flightPlan.o adjacencyList.o
	g++ flightPlan.o adjacencyList.o -o flightPlan

flightPlan.o:
	g++ -c flightPlan.cpp

adjacencyList.o:
	g++ -c adjacencyList.cpp

cleanall:
	rm -f *.o all
	rm output
	rm flightPlan
	rm List
