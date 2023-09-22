/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:07:48 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/09/22 16:53:23 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
//a funcao free deve ser utilizada de dentro para fora em todos os niveis do array de arrays
void	free_split(char **str)
{
	int	i;
	
	i = 0;
	while(str[i])
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
	custom_error(cmd, "command not found");
	return (NULL);
}

void	execute(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free_split(cmd);
		free(path);
		exit(127); //codigo usado p/ indicar q o comando n foi encontrado
	}
	if (execve(path, cmd, envp) == -1)
	{
		free_split(cmd);
		free(path);
		exit_error("Error execute");
	}
}