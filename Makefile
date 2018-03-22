NAME	= mysh

TEST_NAME	= units

CC	= gcc

RM	= rm -f *.g* $(TEST_NAME) -R report rapport.info ./include/*.h.*


SRCS	= ./src/check_args.c \
	./src/initialisation_shell/copy_environement.c \
	./src/initialisation_shell/initialisation_shell.c \
	./src/initialisation_shell/set_env_echec_mode.c \
	./src/initialisation_shell/initialisation_backup.c \
	./src/shell_loop/parsing/get_command_line.c \
	./src/shell_loop/parsing/get_number_instruction.c \
	./src/shell_loop/shell_loop.c

SRC_MAIN	= ./src/main.c \

SRCS_TEST	= ./tests/get_next_line_test.c \
		./tests/my_putstr_test.c \
		./tests/my_strlen_test.c \
		./tests/my_strcmp_test.c \
		./tests/check_args_test.c \
		./tests/copy_environement_test.c \
		./tests/set_env_echec_mode_test.c \
		./tests/initialisation_backup_test.c \
		./tests/initialisation_shell_test.c \
		./tests/get_number_instruction_test.c

LIB	= ./lib/my_putchar.c \
	./lib/get_next_line.c \
	./lib/my_putstr.c \
	./lib/my_strlen.c \
	./lib/my_strcmp.c \
	./lib/my_number_row.c \
	./lib/my_strcpy.c \
	./lib/my_get_env.c

OBJS	= $(LIB:.c=.o) \
	$(SRCS:.c=.o) \
	$(SRC_MAIN:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wextra -g3

TEST_FLAGS = -I ./include/ -lcriterion --coverage

all: $(NAME)

## COMPILES THE LIB, SRCS, SRC_MAIN
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

## RUN THE TESTS ON THE SRCS AND LIB FILES
tests_run:
	$(CC) $(SRCS) $(LIB) $(SRCS_TEST) -o $(TEST_NAME) $(TEST_FLAGS)
	./$(TEST_NAME)

## SHOW IN HTML STYLE THE COVERAGE
show_coverage:
	$(CC) $(SRCS_TEST) $(SRCS) $(LIB) -o $(TEST_NAME) $(TEST_FLAGS)
	./units
	lcov --directory ./ -c -o rapport.info
	genhtml -o ./report -t "code coverage report" rapport.info
	xdg-open ./report/index.html &>/dev/null

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
