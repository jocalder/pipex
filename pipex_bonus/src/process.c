/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:54:52 by jocalder          #+#    #+#             */
/*   Updated: 2025/03/25 21:12:40 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "pipex.h"

void	check_process(char **argv, char **envp, t_info *info, int argc)
{
	if (argc < 6 || info->pid == 0 || ft_strncmp(argv[1], "here_doc", 8) == 0)
		return ;
	if (!info)
		ft_perror(FAIL_ALLOC);
	info->i = 2;
	info->pre_fd = info->fd[0];
	while (info->i < argc - 2)
	{
		set_info(info);
		if (pipe(info->fd_tmp) == -1)
			ft_perror(FAIL_PIPE);
		info->pid_tmp = fork();
		if (info->pid_tmp == -1)
			ft_perror(FAIL_FORK);
		if (info->pid_tmp == 0)
			middle_process(argv, envp, *info, info->pre_fd);
		else
		{
			if (close(info->fd_tmp[1]) == -1 || close(info->pre_fd) == -1)
				ft_perror(FAIL_CLOSE_FD);
			info->pre_fd = info->fd_tmp[0];
		}
	}
	info->fd[0] = info->pre_fd;
}
void	middle_process(char **argv, char **envp, t_info info, int pre_fd)
{
	if (dup2(pre_fd, STDIN_FILENO) == -1
		|| dup2(info.fd_tmp[1], STDOUT_FILENO) == -1)
		ft_perror(FAIL_MID);
	if (close(pre_fd) == -1 || close(info.fd_tmp[0]) == -1
		|| close(info.fd_tmp[1]) == -1 || close(info.fd[1]) == -1)
		ft_perror(FAIL_CLOSE_FD);
	execute_command(argv[info.i], envp);
}