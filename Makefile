ENTRY_SOURCE := fileio/copy.c
LIBRARY_SOURCES := lib/*.c
OTHER_SOURCES := 

INCLUDE_DIRS := -Ilib -Ifileio
SOURCES := $(ENTRY_SOURCE) $(LIBRARY_SOURCES) $(OTHER_SOURCES) 

all: $(SOURCES)
	gcc $(INCLUDE_DIRS) $(SOURCES)

clean:
	rm *.out