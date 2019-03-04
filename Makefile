SOURCE = generator.c
ITEM = lab04

test : generator
	./generator
	
generator : generator.c
	gcc -g -Wall -o generator generator.c
	
clean :
	-rm generator $(ITEM)_$(USER).tar.gz
	
submit: $(SOURCE)
	mkdir $(ITEM)_$(USER)
	cp -p $(SOURCE) $(ITEM)_$(USER)
	tar -cvzf $(ITEM)_$(USER).tar.gz $(ITEM)_$(USER)
	rm -r $(ITEM)_$(USER)
	echo Turn in $(ITEM)_$(USER).tar.gz on myCourses	
