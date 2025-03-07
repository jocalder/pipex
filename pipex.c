/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:10:14 by jocalder          #+#    #+#             */
/*   Updated: 2025/01/14 17:28:44 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"

void	ft_child_process(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
	{
		perror("Error al abrir el archivo de entrada");
		ft_error();
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1 || dup2(filein, STDIN_FILENO) == -1)
	{
		perror("Error al redirigir los flujo en el proceso hijo");
		ft_error();
	}
	close(fd[0]);
	close(filein);
	close(fd[1]);
	ft_execute_command(argv[2], envp);
}

void	ft_parent_process(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
	{
		perror("Error al abrir archivo de salida");
		ft_error();
	}
	if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(fileout, STDOUT_FILENO) == -1)
	{
		perror("Error al redirigir los flujos en el proceso padre");
		ft_error();
	}
	close(fd[1]);
	close(fileout);
	close(fd[0]);
	ft_execute_command(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error();
		pid1 = fork();
		if (pid1 == -1)
			ft_error();
		if (pid1 == 0)
			ft_child_process(argv, envp, fd);
		waitpid(pid1, NULL, 0);
		ft_parent_process(argv, envp, fd);
	}
	else
		ft_error();
	return (0);
}
