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
	./src/shell_loop/shell_loop.c \
	./src/shell_loop/free_array_string.c \
	./src/shell_loop/parsing/get_pipe_number.c \
	./src/shell_loop/parsing/fill_up_instruction.c \
	./src/shell_loop/parsing/get_pipe.c \
	./src/shell_loop/parsing/get_redirect.c \
	./src/shell_loop/parsing/check_env_variable.c \
	./src/shell_loop/parsing/fix_extra_space.c \
	./src/shell_loop/display_prompt.c \
	./src/shell_loop/execution/builtins/cd_built.c \
	./src/shell_loop/execution/builtins/env_built.c \
	./src/shell_loop/execution/builtins/setenv_built.c \
	./src/shell_loop/execution/builtins/unsetenv_built.c \
	./src/shell_loop/execution/builtins/exit_built.c \
	./src/shell_loop/execution/builtins/exec_builtins.c \
	./src/shell_loop/execution/builtins/is_builtins.c \
	./src/shell_loop/execution/builtins/cd_special_cases.c \
	./src/shell_loop/execution/builtins/put_new_old_pwd.c \
	./src/shell_loop/execution/builtins/error_wrong_folder.c \
	./src/shell_loop/execution/builtins/save_old_pwd.c \
	./src/shell_loop/execution/get_redirected.c \
	./src/shell_loop/execution/multiple_execution.c \
	./src/shell_loop/execution/execute_command.c \
	./src/shell_loop/execution/create_pipe.c \
	./src/shell_loop/execution/exec_pipe.c \
	./src/shell_loop/execution/redirect_pipe.c \
	./src/shell_loop/execution/error_exec.c \
	./src/shell_loop/execution/dup_my_pipe.c \
	./src/shell_loop/execution/get_path_exec.c \
	./src/shell_loop/execution/get_execution_file_path.c \
	./src/shell_loop/execution/exit_prog.c \
	./src/shell_loop/execution/simple_execution.c \
	./src/shell_loop/execution/check_sig.c \
	./src/shell_loop/execution/close_redirect.c

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
		./tests/get_number_instruction_test.c \
		./tests/get_pipe_number_test.c \
		./tests/get_pipe_test.c \
		./tests/analyse_redirect_test.c \
		./tests/analyse_redirect_2_test.c \
		./tests/check_env_variable_test.c \
		./tests/get_command_line_1_test.c \
		./tests/cd_builtin_test.c \
		./tests/cd_builtin_crash_test.c \

LIB	= ./lib/my_putchar.c \
	./lib/get_next_line.c \
	./lib/my_putstr.c \
	./lib/my_strlen.c \
	./lib/my_strcmp.c \
	./lib/my_number_row.c \
	./lib/my_strcpy.c \
	./lib/my_get_env.c \
	./lib/my_str_to_words_array.c \
	./lib/my_get_line_env.c

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
