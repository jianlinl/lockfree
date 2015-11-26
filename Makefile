all : mutex1 freelock1 freelock2 myspinlock kfifo

mutex1 : mutex1.cpp timer.cpp
	g++ -g -Wall -o $@ $^ -lpthread
freelock1 : freelock1.cpp timer.cpp
	g++ -g -Wall -o $@ $^ -lpthread
freelock2 : freelock2.cpp timer.cpp
	g++ -g -Wall -o $@ $^ -lpthread
myspinlock : myspinlock.cpp timer.cpp
	g++ -g -Wall -o $@ $^ -lpthread
kfifo : ./kernelfifo/main.cpp ./kernelfifo/unlockQueue.cpp 
	g++ -g -Wall -o $@ $^ -lpthread

clean :
	rm mutex1 freelock1 freelock2 myspinlock kfifo
