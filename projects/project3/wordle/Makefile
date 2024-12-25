TARGET       = sim
TEST		 = test
OBJS         = wordle.o wordleFuncs.o
TESTOBJS	 = tests.o wordleFuncs.o
REBUILDABLES = $(TARGET) $(OBJS) $(TEST) $(TESTOBJS)
CC           = g++
FLAGS        = -Wuninitialized -Werror -std=c++17

# Note: You shouldn't have to change anything below this line.

# Driver rules ...
$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

$(TEST): $(TESTOBJS)
	$(CC) $(FLAGS) -o $@ $^

# Standard rules ...
%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

# Additional make options ...
clean:
	@rm -f $(REBUILDABLES)
	@echo "All rebuildables deleted!"
