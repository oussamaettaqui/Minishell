# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 15:12:41 by oettaqui          #+#    #+#              #
#    Updated: 2024/07/24 12:55:31 by oettaqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBREADLINE		= -L /goinfre/$(USER)/homebrew/opt/readline/lib -lreadline
INCREADLINE		= -I /goinfre/$(USER)/homebrew/opt/readline/include
SRCS = utils/ft_split.c utils/ft_strlen_2char.c	utils/ft_strlen.c utils/ft_strjoin.c utils/ft_substr.c\
		utils/ft_strdup.c utils/ft_strcmp.c utils/ft_read.c utils/append_node_env.c  utils/ft_putendl_fd.c\
		utils/ft_lstsize.c utils/ft_strncmp.c utils/ft_strchr.c free/ft_lstclear_cmds.c \
		utils/append_node_parser.c utils/append_node_cmds.c \
		utils/append_node_cmd.c free/ft_lstclear_parser.c free/ft_lstclear_cmd.c \
		utils/display_env.c free/ft_lstclear_env.c parsing/lexer/init_token.c parsing/lexer/lexer_check_utils.c\
		parsing/lexer/init_parser.c parsing/lexer/init_lexer.c  free/ft_free_if_ex.c\
		parsing/lexer/lexer_check.c parsing/lexer/fetching_string.c utils/ft_itoa.c \
		parsing/lexer/get_char.c parsing/lexer/expand.c parsing/lexer/check_parser.c \
		parsing/parse/start_parsing.c parsing/parse/here_doc.c parsing/parse/expand_in_parser.c\
		parsing/parse/init_fds.c parsing/parse/convert_to_double_pointer.c free/free_two_char.c\
		parsing/parse/check_error_cmds.c main.c	execution/execex/process3.c execution/execex/process2.c\
		execution/execex/ft_work.c	execution/execex/give_table_pipes.c\
		execution/execex/process1.c		execution/execex/check_command.c\
		execution/execex/get_path.c		execution/execex/free_array_pipes.c\
		execution/builtins/ft_cd.c		execution/builtins/ft_env.c\
		execution/builtins/ft_pwd.c		execution/builtins/ft_unset.c\
		execution/builtins/ft_export.c 		execution/ft_exec.c\
		execution/builtins/ft_echo.c 	free/free_double_pointer.c	free/ft_lstclear.c\
		utils/ft_strjoin_b.c	utils/ft_convert_env.c	parsing/parse/handling_redirections.c\
		parsing/parse/realloc_value.c utils/ft_isalpha.c utils/ft_atoi.c parsing/parse/handling_redirections_helper_2.c\
		execution/builtins/ft_exit.c parsing/lexer/expand_utils_0.c parsing/lexer/expand_utils_1.c\
		parsing/lexer/expand_utils_1_0.c parsing/lexer/check_char_helper.c	parsing/lexer/fitching_string_helper.c\
		parsing/lexer/print_error_quotes.c parsing/lexer/fitching_string_helper_1.c parsing/lexer/fitching_string_helper_2.c\
		execution/utils_execution/check_equal.c parsing/parse/handling_redirections_helper.c parsing/parse/expand_in_parser_helper.c\
		execution/utils_execution/ft_get_key.c	execution/utils_execution/ft_lstsize.c	execution/utils_execution/find_equal.c\
		execution/utils_execution/ft_display_env_sorted.c	execution/utils_execution/check_valid.c		execution/utils_execution/ft_strjoin_b_exec.c\
		execution/utils_execution/check_builtins.c	execution/utils_execution/close_fds.c	execution/utils_execution/ft_lstsize_cmds_b.c\
		execution/utils_execution/complete_work.c	utils/get_display.c		utils/create_env_struct.c	utils/sigint_handler.c	utils/initialize_parser.c\
		utils/end_read.c	utils/read2_help.c parsing/parse/start_parsing_helper.c parsing/parse/start_parsing_main_helper.c\
		parsing/parse/handling_redirections_main_helper.c parsing/parse/opening_files.c parsing/parse/minimize_handling_redirections.c\
		parsing/parse/ft_herdoc_f.c		execution/execex/sig_p.c welcom.c\
		
OBJS = ${SRCS:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

# all: ${NAME}

# $(NAME): ${OBJS}
# 	${CC} ${CFLAGS} $(INCREADLINE) ${OBJS} $(LIBREADLINE) -o ${NAME}

# clean:
# 	${RM} ${OBJS}

# fclean: clean
# 	${RM} ${NAME}

# re: fclean all

# .PHONY: all clean fclean re

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

all:$(NAME)

.SILENT:
%.o: %.c
	@printf "$(GREEN)Compiling....$(RESET)\r"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) $(INCREADLINE) $(OBJS) $(LIBREADLINE) -o $(NAME) 
	@echo "$(GREEN)Compilation done!✅ $(RESET)"

clean:
	@$(RM) -rf $(OBJS)
	@echo "$(RED)deleting: Object files$(RESET)"

fclean:clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re