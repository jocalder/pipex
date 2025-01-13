/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:10:37 by jocalder          #+#    #+#             */
/*   Updated: 2025/01/03 21:03:57 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

void	ft_error(void);
char	*ft_find_path(char *cmd, char **envp);
void	ft_execute_command(char *argv, char **envp);
ssize_t	get_next_line(char **line);
void	ft_child_process(char **argv, char **envp, int *fd);
void	ft_parent_process(char **argv, char **envp, int *fd);

#endif