/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:07:48 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/10/09 20:17:01 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	custom_error(char *header, char *msg)
{
	ft_putstr_fd(header, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

//a funcao free deve ser utilizada de dentro para fora em todos os niveis
void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]); 
	free(str);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**envp_paths;
	char	*part_path;
	char	*cmd_path;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	envp_paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (envp_paths[++i])
	{
		part_path = ft_strjoin(envp_paths[i], "/");
		cmd_path = ft_strjoin(part_path, cmd);
		free (part_path);
		if (access(cmd_path, F_OK) == 0)
		{
			free_split(envp_paths);
			return (cmd_path);
		}
		free (cmd_path);
	}
	free_split(envp_paths);
	custom_error(cmd, "Error: command not found");
	return (NULL);
}

//(127)codigo usado p/ indicar q o comando n foi encontrado
void	execute(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	if (av[0])
	{
		cmd = ft_split(av, ' ');
		path = find_path(cmd[0], envp);
		if (!path)
		{
			free_split(cmd);
			free(path);
			exit(127);
		}
		if (execve(path, cmd, envp) == -1)
		{
			free_split(cmd);
			free(path);
			exit_error("Error: execve");
		}
	}
	else
	{
		ft_putstr_fd("Error execute: Bad arguments.\n", 2);
		exit(1);
	}
}
