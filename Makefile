NAME	= mysh

TEST_NAME	= units

CC	= gcc

RM	= rm -f *.g* $(TEST_NAME) -R report rapport.info ./include/*.h.*

SRCS_TEST	= ./tests/get_next_line_test.c \
		./tests/my_putstr_test.c \
		./tests/my_strlen_test.c \
		./tests/my_strcmp_test.c

SRCS	=

SRC_MAIN	= ./src/main.c \

LIB	= ./lib/my_putchar.c \
	./lib/get_next_line.c \
	./lib/my_putstr.c \
	./lib/my_strlen.c \
	./lib/my_strcmp.c \

OBJS	= $(LIB:.c=.o) \
	$(SRCS:.c=.o) \
	$(SRC_MAIN:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wextra -g3

TEST_FLAGS = -I ./include/ -lcriterion --coverage -l c_graph_prog

all: $(NAME)

## COMPILES THE LIB, SRCS, SRC_MAIN
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -l c_graph_prog

## RUN THE TESTS ON THE SRCS AND LIB FILES
tests_run:
	$(CC) $(SRCS) $(LIB) $(SRCS_TEST) -o $(TEST_NAME) $(TEST_FLAGS)
	./$(TEST_NAME)

## SHOW IN HTML STYLE THE COVERAGE
show_coverage:
	$(CC) $(SRCS_TEST) $(SRCS) -o $(TEST_NAME) $(TEST_FLAGS)
	./units
	lcov --directory ./ -c -o rapport.info
	genhtml -o ./report -t "code coverage report" rapport.info
	xdg-open ./report/index.html &>/dev/null

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
