/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_no_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:32:54 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/03/17 19:51:49 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	find_path(char *command, char **envp, char **path)
{
	int		i;
	char	**directories;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return ;
	directories = ft_split(envp[i] + 5, ':');
	if (!directories)
		ft_perror(FAIL_ALLOC);
	i = -1;
	while (directories[++i])
	{
		*path = so_strjoin(directories[i], "/");
		if (!*path)
			ft_exit_free(EXIT_FAILURE, FAIL_ALLOC, directories);
		*path = ft_strjoin(*path, command);
		if (!*path)
			ft_exit_free(EXIT_FAILURE, FAIL_ALLOC, directories);
		if (access(*path, F_OK) == 0)
			return (free_array(directories));
		free(*path);
	}
	return (free_array(directories));
}

static void	execute_command(char *argv, char **envp)
{
	char	**command;
	char	*path;

	command = ft_split(argv, ' ');
	if (!command)
		ft_perror(FAIL_ALLOC);
	path = NULL;
	find_path(command[0], envp, &path);
	if (!path)
	{
		free(path);
		ft_exit_free(EXIT_FAILURE, NULL, command);
	}
	if (execve(path, command, envp) == -1)
	{
		free(path);
		ft_exit_free(EXIT_FAILURE, NULL, command);
	}
}

static void	child_process(char **argv, char **envp, int *fd, pid_t pid)
{
	int	filein;

	if (pid != 0)
		return ;
	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
		ft_perror(FAIL_OPEN_FD);
	if (dup2(fd[1], STDOUT_FILENO) == -1 || dup2(filein, STDIN_FILENO) == -1)
	{
		if (close(filein) == -1 || close(fd[0]) == -1
			|| close(fd[1]) == -1)
			ft_perror(FAIL_CLOSE_FD);
		ft_perror(FAIL_CHILD);
	}
	if (close(filein) == -1 || close(fd[0]) == -1
		|| close(fd[1]) == -1)
		ft_perror(FAIL_CLOSE_FD);
	execute_command(argv[2], envp);
}

static void	parent_process(char **argv, char **envp, int *fd, pid_t pid)
{
	int	fileout;

	if (pid == 0)
		return ;
	if (waitpid(pid, NULL, 0) == -1)
		ft_perror(FAIL_WAIT);
	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		ft_perror(FAIL_OPEN_FD);
	if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(fileout, STDOUT_FILENO) == -1)
	{
		if (close(fileout) == -1 || close(fd[0]) == -1
			|| close(fd[1]) == -1)
			ft_perror(FAIL_CLOSE_FD);
		ft_perror(FAIL_PARENT);
	}
	if (close(fileout) == -1 || close(fd[0]) == -1
		|| close(fd[1]) == -1)
		ft_perror(FAIL_CLOSE_FD);
	execute_command(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		ft_perror(USAGE);
	if (pipe(fd) == -1)
		ft_perror(FAIL_PIPE);
	pid = fork();
	if (pid == -1)
		ft_perror(FAIL_FORK);
	child_process(argv, envp, fd, pid);
	parent_process(argv, envp, fd, pid);
	return (0);
}
