ENTRY_SOURCE := fileio/seek_io.c
LIBRARY_SOURCES := lib/*.c
OTHER_SOURCES :=

INCLUDE_DIRS := -Ilib -Ifileio
SOURCES := $(ENTRY_SOURCE) $(LIBRARY_SOURCES) $(OTHER_SOURCES) 

all:
	gcc $(INCLUDE_DIRS) $(SOURCES) -o $(patsubst %.c,%,$(notdir $(ENTRY_SOURCE)))

clean:
	rm -rf $(patsubst %.c,%,$(notdir $(ENTRY_SOURCE)))
