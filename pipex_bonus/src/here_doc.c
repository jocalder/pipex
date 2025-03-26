/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:48:28 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/26 19:05:39 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	put_here_doc(t_info *info, int *fd)
{
	char	*line;
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			ft_putstr_fd("> ", STDOUT_FILENO);
			line = get_next_line(STDIN_FILENO);
			if (!line || (ft_strncmp(line, info->limiter, info->len) == 0))
			{
				if (line)
					free(line);
				break ;
			}
			write(fd[1], line, ft_strlen(line));
			free(line);
		}
		close(fd[1]);
		free(info->limiter);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	close(fd[1]);
}

void	here_doc_process(char **argv, char **envp, t_info *info)
{
	int fd[2];
	
	if (info->pid != 0 || ft_strncmp(argv[1], "here_doc", 8) != 0)
		return ;
	if (pipe(fd) == -1)
		ft_perror(FAIL_PIPE);
	info->i = 3;
	info->limiter = ft_strdup(argv[2]);
	if (!info->limiter)
		ft_perror(FAIL_ALLOC);
	info->len = ft_strlen(info->limiter);
	put_here_doc(info, fd);
	if (dup2(fd[0], 0) == -1 || dup2(info->fd[1], 1) == -1)
	{	
		if (close(fd[0]) == -1 || close(info->fd[1]) == -1)
			ft_perror(FAIL_CLOSE_FD);
		ft_perror(FAIL_CHILD);
	}
	if (close(fd[0]) == -1)
		ft_perror(FAIL_CLOSE_FD);
	execute_command(argv[info->i], envp);
	exit(EXIT_SUCCESS);
}

