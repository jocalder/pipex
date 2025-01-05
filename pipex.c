/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:10:14 by jocalder          #+#    #+#             */
/*   Updated: 2025/01/03 21:55:51 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		ft_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execve(argv[2], envp);
}

void	ft_parent_process(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		ft_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execve(argv[3], envp);
}

int	main(char *argc, char **argv, char **envp)
{
	int	fd[2];
	pid_t	pid1;
	pipe(fd);

	pid1 = fork();
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error();
		if (pid1 == -1)
			ft_error();
		if (pid1 == 0)
			ft_child_process(argv, envp, fd);
		waitpid(pid1, NULL, 0);
		ft_parent_process(argv, envp, fd);
	}
	return (0);
}
