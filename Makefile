# Makefile
TARGET_MAIN := prog
TARGET_LIB  := libutil.a

CFLAGS  := -Wall -O2 -I. -std=c++11
CC      := g++
LDFLAGS :=
LD      := g++
LIBS    := -lpthread

SOURCES :=  queue.cpp \
            module.cpp \
            router.cpp \
            terminal.cpp

# MAIN_SOURCE := main.cpp
# MAIN_SOURCE := test_queue.cpp
# MAIN_SOURCE := test_module.cpp
MAIN_SOURCE := test_router.cpp

OBJS        := ${SOURCES:.cpp=.o}
MAIN_OBJS   := ${MAIN_SOURCE:.cpp=.o}

.PHONY: all test clean

all: $(TARGET_MAIN)

$(TARGET_MAIN): $(MAIN_OBJS) $(TARGET_LIB)
	$(LD) $(LDFLAGS) $(MAIN_OBJS) $(TARGET_LIB) -o $(TARGET_MAIN) $(LIBS)

$(TARGET_LIB): $(OBJS)
	ar r $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(MAIN_OBJS)
	rm -f $(TARGET_LIB)
	rm -f $(TARGET_MAIN)
