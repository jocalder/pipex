/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:09:57 by jocalder          #+#    #+#             */
/*   Updated: 2025/01/03 21:04:38 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

char	*ft_find_path(char *cmd, char **envp)
{
	int	i;
	char	**directories;
	char	*command_path;
	char	*command;
	
	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4))
			i++;
	directories = ft_split(envp[i] + 5, ":");
	while (directories[i])
	{
		command_path = ft_strjoin(directories[i], "/");
		command = ft_strjoin(command_path, cmd);
		free(command_path);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
	}
	i = -1;
	while (directories[++i])
		free(directories[i]);
	free(directories);
}

void	ft_execute_command(char *argv, char **envp)
{
	int		i;
	char	**cmd;
	char	*command_path;

	i = 0;
	cmd = ft_split(argv, ' ');
	command_path = ft_find_path(cmd[0], envp);
	if (!command_path)
	{
		while (command_path[++i])
			free(command_path[i]);
		free(command_path);
		ft_error();
	}
	if (execve(command_path, cmd, envp) == -1)
		ft_error();
}	

ssize_t	get_next_line(char **line)
{
	char	*buffer;
	char	c;
	int	i;
	ssize_t		bytes;

	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	bytes = read(0, &c, 1);
	i = 0;
	while (bytes && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (bytes);
}
