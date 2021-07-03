ENTRY_SOURCE := fileio/t_readv.c
LIBRARY_SOURCES := lib/*.c

INCLUDE_DIRS := -Ilib -Ifileio
SOURCES := $(ENTRY_SOURCE) $(LIBRARY_SOURCES) 
WARNINGS := -Wno-format-truncation

all:
	gcc -g $(INCLUDE_DIRS) $(WARNINGS) $(SOURCES) -o $(patsubst %.c,%,$(notdir $(ENTRY_SOURCE)))

clean:
	rm -rf $(patsubst %.c,%,$(notdir $(ENTRY_SOURCE)))
