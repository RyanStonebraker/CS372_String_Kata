CC := clang++
CFLAGS := -std=c++14 -I dependencies -I include -Wall -Werror
SOURCES := $(wildcard *.cpp)
TEST_SOURCES := $(wildcard tests/*.cpp)
TARGET := bin/string_kata

tests: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) $(TEST_SOURCES) -o $(TARGET)

run_tests:
	$(TARGET)

.PHONY : clean
clean :
	-rm $(TARGET)
