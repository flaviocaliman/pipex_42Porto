/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:05:37 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/09/25 15:04:20 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <signal.h>
# include "libft/libft.h"

void	exit_error(char *str);
void	custom_error(char *header, char *msg);
void	free_split(char **str);
char	*find_path(char *cmd, char **envp);
void	execute(char *av, char **envp);
void	check_envp(char **envp);
void	child_process(char **av, char **envp, int *fd);
void	parent_process(char **av, char **envp, int *fd);

#endif
