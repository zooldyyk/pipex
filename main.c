/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:25:24 by eschmid           #+#    #+#             */
/*   Updated: 2022/11/28 11:30:33 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

char	*get_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free (tmp);
		if (access(command, F_OK) == 0)
			return (command);
		free (command);
		paths++;
	}
	return (NULL);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
		return (msg("error\n"));
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		msg_error("error\n");
	pipex.outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR);
	if (pipex.outfile < 0)
		msg_error("error\n");
	if (pipe(pipex.pipe) == -1)
		msg_error("error\n");
	pipex.paths = get_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		return (msg("error\n"));
	if (pipex.pid1 == 0)
		child1(pipex, av, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		return (msg("error\n"));
	if (pipex.pid2 == 0)
		child2(pipex, av, envp);
	close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_parent(&pipex);
	return (0);
}
