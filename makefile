CF= g++ -c -std=c++11 -g

all: a5 

a5: linked_list.o node.o tools.o driver.o
	g++ -g linked_list.o node.o tools.o driver.o -o a5 

linked_list.o: linked_list.cpp
	$(CF) linked_list.cpp

node.o: node.cpp
	$(CF) node.cpp

tools.o: tools.cpp
	$(CF) tools.cpp

driver.o: driver.cpp
	$(CF) driver.cpp

clean:
	rm *.o a5 
