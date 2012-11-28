OPTS  = -Wall -Wextra -g
OPTI  = -O3 -pipe
OBJS  = *.o
FILES = main.cpp class/*.cpp

launch: head
	g++ $(OPTS) $(OBJS) -o gare

opti: head-opti
	g++ $(OPTS) $(OPTI) $(OBJS) -o gare
	
head: $(FILES)
	g++ $(OPTS) -c $(FILES)
	
head-opti: $(FILES)
	g++ $(OPTS) $(OPTI) -c $(FILES)
	
clean:
	rm *.o gare

cleaner : clean
	rm *~ class/*~
	
