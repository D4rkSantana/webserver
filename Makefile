NAME = webserv

CC = c++
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = -I library/include
DIR_SOURCES = library/src
DIR_OBJS = obj


DIR_TESTS = library/tests/src/
INCLUDES_TESTS = -I library/test/include
DIR_TEST_OBJS = obj/tests

SOURCES := $(wildcard $(DIR_SOURCES)/*.cpp)
SOURCES += main.cpp

OBJS := $(patsubst $(DIR_SOURCES)/%.cpp,$(DIR_OBJS)/%.o,$(filter-out main.cpp,$(SOURCES)))
OBJS += $(DIR_OBJS)/main.o

TESTS := $(wildcard $(DIR_TESTS)/*.cpp)
TESTS += $(wildcard $(DIR_SOURCES)/*.cpp)

TEST_OBJS := $(patsubst $(DIR_TESTS)/%.cpp,$(DIR_TEST_OBJS)/%.o,$(TESTS))

all: $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SOURCES)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DIR_OBJS)/main.o: main.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DIR_TEST_OBJS)/%.o: $(DIR_TESTS)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) $(INCLUDES_TESTS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

test: $(TEST_OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) $(INCLUDES_TESTS) $^ -o test_runner
	./test_runner

clean:
	$(RM) $(DIR_OBJS) $(DIR_TEST_OBJS) test_runner

fclean: clean
	$(RM) $(NAME) 

re: fclean all

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --log-file="web_leaks.txt" ./$(NAME)

.PHONY: all clean fclean re val test
