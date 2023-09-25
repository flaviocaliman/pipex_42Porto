/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:00:00 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/09/25 14:56:45 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_envp(char **envp)
{
	int	i;
	int	check;

	i = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) && envp[i][6])
			check = 1;
	}
	if (!check)
	{
		exit_error("Error check_envp");
		exit(1);
	}
}

//1o dup2: redireciona a saida padrao STDOUT para fd[1]
//2o dup2: redireciona a entrada padrao STDIN para filein
void	child_process(char **av, char **envp, int *fd)
{
	int	filein;

	filein = open(av[1], O_RDONLY, 0777);
	if (filein == -1)
		exit_error("Error filein");
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execute(av[2], envp);
}

void	parent_process(char **av, char **envp, int *fd)
{
	int	fileout;

	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		exit_error("Error fileout");
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute(av[3], envp);
}

//waitpid: wait the child_process
int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	child_pid;

	check_envp(envp);
	if (ac == 5)
	{
		if (pipe(fd) == -1)
			exit_error("Error pipe");
		child_pid = fork();
		if (child_pid == -1)
			exit_error("Error fork");
		if (child_pid == 0)
			child_process(av, envp, fd);
		waitpid(child_pid, NULL, 0);
		parent_process(av, envp, fd);
	}
	else
		exit_error("Error: bad arguments.");
	return (0);
}
