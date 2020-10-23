
# Define the name of our executable
BIN = euler

# Use a wildcard command to find all files ending in .c
# These are all saved in the SRC variable
SRC := $(wildcard *.c)

# Cflags are the flags to the compiler
CFLAGS = -lm

# all and clean does not have any file association
# So they are "phony" make targets, ie commands not associated directly with files
.PHONY: all
.PHONY: clean

# To run the all command, we depend on the BIN (pointers) file
# When we run just "make" make will use the all target
all: $(BIN)

# To obtain BIN (pointers) we must compile all SRC
# $(CC) is the C compiler
# $(SRC) is all the .c files 
# -o is a compiler flag that renames the binary executable to the next argument
# $(BIN) is the name of the executable (pointers) 
$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)


# Remove any file named pointers when we run "make clean"
clean:
	rm -f $(BIN)