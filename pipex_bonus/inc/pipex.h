/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:27:08 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/03/26 19:07:14 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>

# define USAGE			"./pipex file1 first_command ... last_command file2"
# define FAIL_PIPE		"Failed pipe function"
# define FAIL_FORK		"Failed fork function"
# define FAIL_WAIT		"Failed waitpid function"
# define FAIL_OPEN_FD	"Failed to open fd"
# define FAIL_CLOSE_FD	"Failed to close fd"
# define FAIL_FLOW		"Failure to redirect flows"
# define FAIL_CHILD		"Failure to redirect flows in child process"
# define FAIL_MID		"Failure to redirect flows in middle process"
# define FAIL_PARENT	"Failure to redirect flows in parent process"
# define FAIL_ALLOC		"Failed memory allocation"

typedef struct s_info
{
	int		i;
	int		fd[2];
	int 	fd_tmp[2];
	int 	pre_fd;
	int		infile;
	int		outfile;
	char	*limiter;
	size_t	len;
	pid_t	pid;
	pid_t 	pid_tmp;
} t_info;

void	set_info(t_info *info);
void	execute_command(char *argv, char **envp);
void 	check_process(char **argv, char **envp, t_info *info, int argc);
void	middle_process(char **argv, char **envp, t_info info, int pre_fd);
void	here_doc_process(char **argv, char **envp, t_info *info);

#endif
