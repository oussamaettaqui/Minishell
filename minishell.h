/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:12:38 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/24 12:54:37 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

extern int			g_exit_status;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				sorted;
	int				env_member;
	struct s_env	*next;
}					t_env;

typedef enum s_token_type
{
	T_CHAR,
	T_PIPE,
	T_R_IN,
	T_R_OUT,
	T_APP,
	T_HERD,
	T_EOF,
	T_ERROR,
	T_DOLLAR,
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	int				is_expand;
}					t_token;

typedef struct s_lexer
{
	char			*src;
	char			c;
	unsigned int	i;
	size_t			src_len;
	int				ex_s;

}					t_lexer;

typedef struct s_parser
{
	t_token			*current;
	struct s_parser	*next;

}					t_parser;

typedef struct s_args
{
	char			*cmd;
	struct s_args	*next;
}					t_args;

typedef struct s_cmds
{
	t_args			*cmd;
	int				fd_in;
	int				fd_out;
	struct s_cmds	*next;

}					t_cmds;

typedef struct s_flags
{
	int				f;
	int				s;
}					t_f;

typedef struct s_helper_st
{
	int				flag;
	char			*value;
	char			*tmp;
}					t_helper_st;

typedef struct s_helper_st2
{
	char			*v;
	char			*src;
	char			*key;
	int				i;
}					t_helper_st2;

typedef struct s_helper_st3
{
	int				fd_in;
	int				fd_out;
	int				check;
	int				flag;
}					t_helper_st3;

typedef struct s_helper_st4
{
	t_args			*cmd;
	t_parser		*prev;
	t_parser		*parser;
	t_cmds			*cmds;
}					t_helper_st4;

typedef struct s_helper_st5
{
	t_cmds			*head;
	t_args			*cmd;
	t_args			*cmd_next;
	t_args			*prev;
	int				flag;
}					t_helper_st5;

typedef struct s_exec
{
	char			**av;
	char			**env;
	int				**fds;
	int				ac;
	int				fd;
	int				id_pipe;
	int				cmd_pos;
	int				number_cmd;
	t_cmds			*cmds_lst;
	t_env			*env_l;
}					t_exec;

typedef struct s_cd_struct
{
	char			str[1024];
	char			str1[1024];
	t_env			*pwd;
	t_env			*oldpwd;
	t_env			*home;
	int				check;
}					t_cd_struct;

typedef struct s_export_st
{
	t_env			*element;
	char			*key;
	char			*value;
	char			*str;
	size_t			pos;
}					t_export_st;

typedef struct s_read_st
{
	char			*line;
	t_env			*list;
	t_parser		*parser;
	t_cmds			*cmds;
	char			*display;
	int				f;
}					t_read_st;

// welcom.c
void				welcom(void);
//****utils *****

// read2_help.c
void				read2_help(void);
// end_read.c;
void				end_read(t_read_st *vars);
// initialize_parser.c
t_parser			*initialize_parser(char *line, t_env **env);
// sigint_handler.c
void				sigint_handler(int sig);
// create_env_struct.c
void				create_env_struct(t_env **list, char **env);
// get_display.c
char				*get_display(void);
// ft_atoi.c

unsigned long long	ft_atoi(const char *str);
// ft_strjoin_b.c

char				*ft_strjoin_b(char *s1, char *s2);
// void ft_convert_env.c

char				**ft_convert_env(t_env **env);
// ft_read.c

int					ft_read(int ac, char **env);

// ft_isalpha.c
int					ft_isalpha(int c);

// display_env.c
void				display_env(t_env *list);

// append_node_env.c
void				append_node(t_env **list, char *line, size_t pos,
						int check);

// append_node_parser.c
void				append_node_parser(t_parser **list, t_token *token);
t_parser			*ft_lstlast_parser(t_parser *list);

// append_node_cmds.c
void				append_node_cmds(t_cmds **list, t_args *cmd, int *fd_in,
						int *fd_out);
t_cmds				*ft_lstlast_cmds(t_cmds *list);
// append_node_cmd.c
void				append_node_cmd(t_args **list, char *cmd);

// file name function
char				**ft_split(char *s, char c);
size_t				ft_strlen(char *s);
size_t				ft_strlen_2char(char **str);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_substr(char *s, unsigned int start, size_t len);
char				*ft_strdup(char *s1);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strrchr(char *str, int c);
char				*ft_itoa(int n);
int					ft_strchr(char *str, int c);
int					ft_lstsize_parser(t_parser *lst);
int					ft_lstsize_cmds(t_cmds *lst);
int					ft_strncmp(char *s1, char *s2, size_t n);
void				ft_putendl_fd(char *s, int fd);

//****free
// free_double_pointer.c
void				free_double_pointer(char **str);
// ft_lstclear.c
void				ft_lstclear(t_env **lst);
// free_double_pointer.c
void				ft_free_line(char **str);
void				ft_free_if_ex(char *str);

// ft_lstclear_env.c

void				ft_lstclear_env(t_env **lst);

// ft_lstclear_parser.c
void				ft_lstclear_parser(t_parser **lst);

// ft_lstclear_cmds.c
void				ft_lstclear_cmds(t_cmds **lst);

// ft_lstclear_cmd.c
void				ft_lstclear_cmd(t_args **lst);

// fre_two_char.c
void				free_tow_char(char *s1, char *s2);

// *****parsing*****

// *** lexer ***
// init_token.c
t_token				*init_token(char *value, t_token_type type, int is_expand);

// init_parser.c
void				init_parser(t_parser **parser, t_lexer *lexer, t_env **env);
// init_lexer.c
t_lexer				*init_lexer(char *value);
void				lexer_advance(t_lexer *lexer);
void				lexer_skip_whitespace(t_lexer *lexer);
t_token				*get_next_token(t_lexer *lexer, t_env **env,
						t_token *token);

// lexer_check.c
t_token				*check_redirect_out(t_lexer *lexer);
t_token				*check_redirect_in(t_lexer *lexer);
t_token				*check_char(t_lexer *lexer, t_env **env,
						t_token *prev_token);

// lexer_check_utils.c
unsigned int		get_len_of_it(t_lexer *lexer, char c);
char				*handl_double_quotes(char *tmp, t_token *prev_token,
						char *value, int *flag);
char				*check_char_main_helper(t_lexer *lexer, t_env **env,
						t_token *prev_token, t_helper_st *st);
void				init_helper_st(t_helper_st *st);

// fetching_string.c
char				*single_quotes(t_lexer *lexer, t_token *prev_token);
char				*double_quotes(t_lexer *lexer, t_env **env,
						t_token *prev_token);
char				*dollar(t_lexer *lexer, t_env **env, t_token *prev_token);
int					check_quotes(t_lexer *lexer, char q);
int					check_dollar_(t_lexer *lexer, char q, int i);

// fetching_string_helper.c
int					check_condition_is_correct(char prev, t_lexer *lexer);
int					check_posibilty_of_expand(t_lexer *lexer, int check,
						t_token *prev_token);
char				*minimize_c_convert_ex_status(t_lexer *lexer,
						t_helper_st *st);
char				*minimize_dollar_and_dash(t_lexer *lexer, t_helper_st *st);
char				*minimize_same_cases(t_lexer *lexer, t_helper_st *st);

// fitching_string_helper_1.c
char				*minimize_else(t_lexer *lexer, t_helper_st *st);
char				*minimize_case_d_s_quotes(t_lexer *lexer, t_helper_st *st,
						t_env **env, t_token *prev_token);
char				*minize_first_conditions(t_lexer *lexer, t_env **env,
						t_helper_st *st, t_token *prev_token);
char				*check_flags_and_join(t_helper_st *st);
char				*if_no_prev_befor_token(t_helper_st *st, int i, char *v,
						t_env **env);

// fitching_string_helper_2.c
char				*if_prev_exist_befor_token(t_helper_st *st, int i, char *v,
						t_env **env);
char				*join_tow_time_and_free(t_helper_st *st);
char				*minimize_else_dollar(t_helper_st *st, t_token *prev_token,
						int i, t_env **env);
char				*minimize_dollar_function(t_helper_st *st,
						t_token *prev_token, t_env **env, int i);

// print_error_quotes.c
void				print_error_quotes(int f, t_token *prev_token);

// get_char.c
char				*get_char(t_lexer *lexer);

// expand.c
char				*expand(char *tmp, t_env **env);
char				*expand_dollar(t_lexer *lexer, t_env **env);
char				*get_value_of_expand(t_lexer *lexer, t_env **env);
char				*add_char(char *v, char c);

// expand_utils_0.c
char				*if_v_not_empty(char *v, char c);
char				*get_value_of_expand_0(char *tmp, t_env **env, int *flag);
char				*expand_dollar_0(t_lexer *lexer, t_env **env, int flag,
						char *tmp);
// expand_utils_1.c
char				*if_get_tmp_value(char *tmp, t_lexer *lexer, t_f *flags);
int					check_condition(t_lexer *lexer);
char				*condition_case_status(char *tmp, t_lexer *lexer);
char				*get_value_of_expand_1(t_lexer *lexer, char *tmp, int *flag,
						t_f *flags);
// expand_utils_1_0.c
t_f					*init_flags(t_f *flags);

// check_parser.c
int					check_parser(t_parser **parser, t_env **env);
int					check_dollar_char(char *lexer, char q);

// check_char_helper.c
char				*single_quotes_case(char *tmp, int *flag,
						t_token *prev_token, char *value);
char				*double_quotes_case(char *tmp, t_token *prev_token,
						char *value);
char				*dollar_case(t_lexer *lexer, int *flag, t_env **env,
						t_token *prev_token);
char				*check_char_helper(int *flag, char *tmp, char *value);
int					check_conditions(t_lexer *lexer);

// *** parser ***
// ft_herdoc_f.c
void				ft_herdoc_f(t_helper_st5 *st, t_cmds **cmds, t_env **env);
// handling_redirections.c
t_cmds				*handling_redirections(t_cmds **cmds, t_env **env);
t_args				*ft_get_redirection(t_args *cmd);
t_args				*ft_get_prev(t_args *cmd);
// handling_redirections_helper.c
int					condition_redirec_in(t_args *current, t_args *cmd);
int					condition_redirec_out(t_args *current, t_args *cmd);
int					condition_redirec_app(t_args *current, t_args *cmd);
int					condition_redirec_here(t_args *current, t_args *cmd);
void				error_syntax(t_cmds **cmds);

// handling_redirections_helper_2.c
void				helper_function_1(t_helper_st5 *st);
void				helper_function_2(t_helper_st5 *st);
void				helper_function_3(t_helper_st5 *st, t_cmds **cmds,
						t_env **env);

// handling_resirections_main_helper.c
void				print_error_syntax(t_args *cmd);
void				print_error_syntax_or_permision(t_args *cmd);
void				error_deleting_file_here_doc(t_cmds **cmds);
t_args				*update_head(t_cmds *head, t_args *cmd);
void				init_t_helper_st5(t_cmds **cmds, t_helper_st5 *st);

// opening_files.c
int					open_redir_in(t_cmds *head, t_args *cmd);
int					open_redir_out(t_cmds *head, t_args *cmd);
int					open_redir_appand(t_cmds *head, t_args *cmd);
int					open_redir_here_doc(t_cmds *head);

// start_parsing.c
t_cmds				*start_parsing(t_parser *parser, t_env **list);
void				hand_case_export(t_parser *prev, t_parser *parser,
						t_args **cmd, int *flag);
int					check_condition_export(t_parser *prev, t_parser *parser);

// start_parsing_helper.c
void				init_t_helper(t_helper_st3 *st);
int					check_expand_possibility(t_parser *prev, t_parser *parser);
void				start_parsing_helper_0(t_parser *parser, t_helper_st3 *st,
						t_cmds **cmds, t_helper_st4 *s);
void				start_parsing_helper_1(t_args **cmd, t_helper_st3 *st,
						t_parser *parser);
void				start_parsing_helper_2(t_parser *parser, t_helper_st3 *st);

// start_parsing_main_helper.c
void				init_t_helper_4(t_helper_st4 *s, t_parser *parser0);
void				start_parsing_main_helper(t_helper_st4 *s,
						t_helper_st3 *st);
char				*case_new_line(t_helper_st4 *s);
char				*case_expand_in_parser(t_helper_st4 *s, t_env **env);

// minimize_handling_redirections.c
int					check_redirection_in(t_cmds *head, t_cmds **cmds,
						t_args *cmd, t_helper_st5 *st);
int					check_redirection_out(t_cmds *head, t_cmds **cmds,
						t_args *cmd, t_helper_st5 *st);
int					check_redirection_appand(t_cmds *head, t_cmds **cmds,
						t_args *cmd, t_helper_st5 *st);

// here_doc.c
int					here_doc(char *av, int infd, t_env **env, t_cmds *head);

// expand_in_parser.c
char				*expand_in_parser(char *s, t_env **env);
char				*expand_in_here_doc(char *s, t_env **env);
char				*add_char_char(char *v, char c);

// expand_in_parser_helper.c
char				*expand_exit_status(char *src, char *key);
char				*expnad_dollar_only(char *src, char *key, char *s, int i);
void				init_helper_st2(t_helper_st2 *st);
// init_fds.c
void				init_fds(int *fd_in, int *fd_out);

// convert_to_double_pointer.c
char				**convert_to_double_pointer(t_args *cmd);

// check_error_cmds.c
int					check_error_cmds(t_cmds *cmds);

// realloc_value.c
char				*realloc_value(char *value);

//******************execution********************
// ft_exec.c
t_env				*ft_exec(t_env *env, t_cmds *cmds);
//*********execex**********
// sig_p.c
void				sig_p(int sig);
// ft_work.c
void				ft_work(t_env *env, t_cmds *cmds_lst);
// give_table_pipes.c
int					**give_table_pipes(int number_cmd);
// process1.c
void				process1(t_exec data, int pid1);
// process3.c
void				process3(t_exec data, int pid3);
// process2.c
void				process2(t_exec data, int pid2);
// get_path.c
char				*get_path(char **env);
// free_array_pipes.c
void				free_array_pipes(int **array, int number_pipe);
// check_command.c
int					check_command(char **paths, char **commands, char **env);

//*******builtins*********
// ft_exit.c
void				ft_exit(char **cmds, int i);
// ft_echo.c
void				ft_echo(char **cmds);
// ft_cd.c
void				ft_cd(char **cmds, t_env *env);
// ft_env.c
void				ft_env(t_env *env, char **cmds);
// ft_pwd.c
void				ft_pwd(void);
////ft_export.c
void				ft_export(char **cmds, t_env *env);
// ft_unset.c
t_env				*ft_unset(char **cmds, t_env **env);

// *********utils_execution*********
t_env				*ft_get_key(t_env *env, char *key);
size_t				ft_lstsize(t_env *lst);
size_t				check_equal(char *str);
size_t				find_equal(char *str);
void				ft_display_env_sorted(t_env *env);
int					check_valid(char *str);
char				*ft_strjoin_b_exec(char *s1, char *s2);
int					check_builtins(char **commands, t_exec data);
void				close_fds(t_exec data);
size_t				ft_lstsize_cmds_b(t_cmds *lst);
void				complete_work(t_exec *data);

#endif