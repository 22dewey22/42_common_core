/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:52:34 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/02/18 06:17:18 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <errno.h>
# include <fcntl.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <libft_stuff.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# define SUCCESS 0
# define OUTFILE_NO_W 1
# define PIPE_ERROR 1
# define READ_ERROR 2
# define WRITE_ERROR 3
# define MALLOC_ERROR 4
# define FORK_ERROR 5
# define EXECVE_ERROR 6
# define DUP2_ERROR 7
# define OPEN_ERROR 1
# define PATH_NOT_FOUND 127
# define SAME_FILE 10
# define NOTHING_READ 11
# define INVALID_ARGS 12
# define HERE_DOC 1
# define PERMISSION_DENIED 126

typedef struct s_cmds
{
	int				count;
	char			*bin;
	char			**args;
	struct s_cmds	*next;
}					t_cmds;

typedef char		t_bool;

typedef struct s_prog
{
	int				ac;
	char			**av;
	char			**envp;
	char			**paths;
	t_bool			here_doc;
	int				here_doc_fd;
	char			here_doc_name[50];
	char			*infile;
	int				infile_fd;
	char			*outfile;
	int				outfile_fd;
	char			*limiter;
	t_cmds			*first_cmd;
	int				error;
	int				last_pid;
}					t_prog;

/*cmds_exec.c*/
int					px_execute_cmd(t_prog *state, t_cmds *cmd);
void				px_exec_abs_cmd(t_prog *state, t_cmds *cmd);
int					px_exec_rel_cmd(t_prog *state, t_cmds *cmd);
/*cmds_parsing.c */
int					px_parse_cmds(t_prog *state);
int					px_addback_cmd_list(t_prog *state, char *av);
int					px_place_cmd(t_prog *state, t_cmds *new);
int					px_free_cmd_list(t_prog *state, int error);
/*general_parsing.c*/
int					px_parse_path(t_prog *state);
void				px_get_outfile(t_prog *state);
/*init.c*/
int					px_init_prog(t_prog *state, int ac, char **av, char **envp);
void				px_init_dup(t_prog *state);
/*misc.c*/
int					px_splittable_arg(t_cmds *new, char *av);
int					px_weird_arg(t_cmds *new, char *av);
int					px_only_spaces(char *av);
void				px_error_msg(char *file);
int					px_kill_switch(t_prog *state, int error);
/*parsing_mandatory.c*/
int					px_parse_entries(t_prog *state);
int					px_parse_files(t_prog *state);
/*processes.c*/
int					px_pipex_loop(t_prog *state);
int					pipex_magic(t_prog *state, t_cmds *cmd);
void				px_parent(t_cmds *cmd, int *pipe_fd);
void				px_child(t_prog *state, t_cmds *cmd, int *pipe_fd);
/****BONUSES****/
/*here_doc_bonus.c*/
int					px_generate_random(char *output, int size);
int					px_get_heredoc(t_prog *state);
int					px_create_hd_file(t_prog *state);
int					px_write_heredoc(t_prog *state);
/*parsing_bonus.c*/
int					px_parse_entries_bonus(t_prog *state);
int					px_parse_files_bonus(t_prog *state);

#endif
