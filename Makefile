SOURCE = sorter.c
ITEM = 350_p01_whitney

test : sorter
	./sorter
	
sorter : sorter.c
	gcc -g -Wall -o sorter sorter.c
	
clean :
	-rm sorter $(ITEM)_$(USER).tar.gz
	
submit: $(SOURCE)
	mkdir $(ITEM)_$(USER)
	cp -p $(SOURCE) $(ITEM)_$(USER)
	tar -cvzf $(ITEM)_$(USER).tar.gz $(ITEM)_$(USER)
	rm -r $(ITEM)_$(USER)
	echo Turn in $(ITEM)_$(USER).tar.gz on myCourses	
