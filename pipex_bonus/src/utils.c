/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:56:22 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/03/26 19:03:01 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_info(t_info *info)
{
	info->i = 0;
	info->pre_fd = 0;
	info->infile = 0;
	info->outfile = 0;
	info->limiter = NULL;
	info->len = 0;
	info->pid = 0;
	info->pid_tmp = 0;
}

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

void	execute_command(char *argv, char **envp)
{
	char	**command;
	char	*path;

	command = ft_split(argv, ' ');
	if (!command)
		ft_perror(FAIL_ALLOC);
	find_path(command[0], envp, &path);
	if (!path)
		ft_exit_free(EXIT_FAILURE, NULL, command);
	if (execve(path, command, envp) == -1)
	{
		free(path);
		ft_exit_free(EXIT_FAILURE, NULL, command);
	}
}
