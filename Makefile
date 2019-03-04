SOURCE = prog1sorter.c
ITEM = 350_p01_whitney

test : prog1sorter
	./prog1sorter
	
prog1sorter : prog1sorter.c
	gcc -g -Wall -o prog1sorter prog1sorter.c
	
clean :
	-rm prog1sorter $(ITEM)_$(USER).tar.gz
	
submit: $(SOURCE)
	mkdir $(ITEM)_$(USER)
	cp -p $(SOURCE) $(ITEM)_$(USER)
	tar -cvzf $(ITEM)_$(USER).tar.gz $(ITEM)_$(USER)
	rm -r $(ITEM)_$(USER)
	echo Turn in $(ITEM)_$(USER).tar.gz on myCourses	
