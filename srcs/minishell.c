/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:48:01 by nthoach           #+#    #+#             */
/*   Updated: 2024/03/28 20:49:49 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../headers/minishell.h"

/*
Event function in case of readline hook - in this program, it do nothing 
*/
int	event(void)
{
	return (0);
}
/*
Action when CTRL + C is pressed, three cases:
(1) If not inside a heredoc
(2) If inside a command
(3) If not inside a command and in a heredoc
*/

void	sigint_handle(int sig)
{
	if (g_state != HEREDOC_IN)
		ft_putstr_fd("\n", 2);
	if (g_state == CMD_IN)
	{
		g_state = CTRL_C;
		rl_replace_line("", 0);
		rl_redisplay();
		rl_done = 1;
		return ;
	}
	else if (g_state == HEREDOC_IN)
	{
		g_state = HEREDOC_STOP;
		rl_replace_line("", 0);
		rl_redisplay();
		rl_done = 1;
		return ;		
	}
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void) sig;
}
/*
CTRL + \ handling
*/
void	sigquit_handle(int sig)
{
	if (g_state == CMD_IN)
	{
		g_state = CTRL_BS;
		rl_replace_line("", 0);
		rl_redisplay();
		rl_done = 1;
		ft_putstr_fd("Quit: ", 2);
		ft_putnbr_fd(sig, 2);
		ft_putchar_fd('\n', 2);
		return ;
	}
}
//frees double pointer
void	free_double_ptr(void **ptr)
{
	int	i;

	i = 0;
	while (*ptr && ptr && ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	if (ptr)
		free(ptr);
}

// duplicates the passed string
char	**ft_dup_arr(char **envp)
{
	char	**envp_copy;
	size_t	i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	envp_copy = ft_calloc(i + 1, sizeof(char *));
	if (!envp_copy)
		return (NULL);
	i = 0;
	while(envp[i] != NULL)
	{
		envp_copy[i] = ft_strdup(envp[i]);
		if (envp_copy[i] == NULL)
		{
			free_double_ptr((void **) envp_copy);
			return (envp_copy);
		}
		i++;
	}
	return (envp_copy);
}

/*
initilization routine for signal handling using GNU Readline library
1) Disable readline's default handling behavior, Readline will
not catch signals such as SIGINT and SIGQUIT
2) Set the variable rl_event_hook to function "event",
in this minishell, event function do nothing
3) Set functions for SIGINT and SIGQUIT 
*/
// void	ini_sigs(void)
// {
// 	rl_catch_signals = 0;
// 	rl_event_hook = event;
// 	signal(SIGINT, sigint_handle);
// 	signal(SIGQUIT, sigquit_handle);
// }

/* copies the existing environment variables (arr) and
 adding a new variable (str) at the end of the copied list */
char	**whileloop_add_var(char **env, char **rtn, char *str)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (env[i + 1] == NULL)
		{
			rtn[i] = ft_strdup(str);
			rtn[i + 1] = ft_strdup(env[i]);
		}
		else
			rtn[i] = ft_strdup(env[i]);
		if (rtn[i] == NULL)
		{
			free_double_ptr((void **)rtn);
			return (rtn);
		}
		i++;
	}
	if (env[0] == NULL)
		rtn[0] = ft_strdup(str);
	return (rtn);
}

int	ft_error(int error)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (error == 0)
		ft_putstr_fd("syntax error near unexpected token 'newline'\n",
			STDERR_FILENO);
	else if (error == 1)
		ft_putstr_fd("memory error: unable to assign memory\n", STDERR_FILENO);
	else if (error == 2)
		ft_putstr_fd("syntax error: unable to locate closing quotation\n",
			STDERR_FILENO);
	else if (error == 4)
		ft_putstr_fd("Failed to create pipe\n", STDERR_FILENO);
	else if (error == 5)
		ft_putstr_fd("Failed to fork\n", STDERR_FILENO);
	else if (error == 6)
		ft_putstr_fd("outfile: Error\n", STDERR_FILENO);
	else if (error == 7)
		ft_putstr_fd("infile: No such file or directory\n", STDERR_FILENO);
	else if (error == 8)
		ft_putendl_fd("Path does not exist", STDERR_FILENO);
	else if (error == 9)
		ft_putendl_fd("Path does not exist", STDERR_FILENO);
	return (EXIT_FAILURE);
}

/*
it takes arr and adds str and return rtn which is composed of both
it allocates memory for the additional variable and return it
*/
char	**add_var(char **arr, char *str)
{
	char	**rtn;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(i + 2, sizeof(char *));
	if (!rtn)
	{
		ft_error(1);
		return (NULL);
	}
	i = 0;
	whileloop_add_var(arr, rtn, str);
	return (rtn);
}
void	validate_pwd(t_mnsh *mnsh)
{
	char	**tmp;
	char	*var;

	if (!mnsh->envp)
		mnsh->envp = (char **) ft_calloc(2, sizeof(char *));
	if (!mnsh->pwd || !mnsh->old_pwd)
	{
		mnsh->pwd = getcwd(NULL, 0); // get current directory in unistd.h
		mnsh->old_pwd = NULL;
		tmp = mnsh->envp;
		var = ft_strjoin("PWD=", mnsh->pwd);
		mnsh->envp = add_var(mnsh->envp, var); // add environment variable
		free_double_ptr((void **) tmp);
		free(var);
		var = ft_strjoin("OLDPWD=", mnsh->old_pwd);
		tmp = mnsh->envp;
		mnsh->envp = add_var(mnsh->envp, var); //
		free_double_ptr((void **) tmp);
		free(var);
	}
}

/* gets hold of the present working directory
and old pwd from the copied envp (utils->envp)
*/
int	get_pwd(t_mnsh *mnsh)
{
	int	i;

	i = 0;
	mnsh->pwd = 0;
	mnsh->old_pwd = 0;
	//ft_printf("0k-2.1");
	while (mnsh->envp && mnsh->envp[i])
	{
		if (!ft_strncmp(mnsh->envp[i], "PWD=", 4))
			mnsh->pwd = ft_substr(mnsh->envp[i], 4, ft_strlen(mnsh->envp[i]) - 4);
		else if (!ft_strncmp(mnsh->envp[i], "OLDPWD=", 7))
			mnsh->old_pwd = ft_substr(mnsh->envp[i], 7, ft_strlen(mnsh->envp[i]) - 7);
		i++;
		//ft_printf("0k-2.1");//
	}
	validate_pwd(mnsh);
	return (1);
}
void	ini_mnsh(t_mnsh *mnsh, char **envp)
{
	mnsh->cmd = 0;
	mnsh->path = 0;
	mnsh->pwd = 0;
	mnsh->old_pwd = 0;
	mnsh->pipe = 0;
	mnsh->pid = 0;
	mnsh->envp = 0;
	mnsh->reset = false;
	//ft_printf("0k-2.1");
	//ft_memset(mnsh, 0, sizeof(t_mnsh));
	if (*envp != 0)
		mnsh->envp = ft_dup_arr(envp);
	//ft_printf("0k-2.1");
	get_pwd(mnsh);
}
// frees memory associated with a cmd
void	free_cmd(t_cmd *cmd)
{
	t_redir	*ptr;
	t_redir	*del;

	if (cmd->h_filename)
		free(cmd->h_filename);
	if (cmd->arg)
		free_double_ptr((void **) cmd->arg);
	ptr = cmd->redirect;
	while (ptr)
	{
		del = ptr;
		ptr = ptr->next;
		if (del->path)
			free(del->path);
		free(del);
	}
	if (cmd)
		free(cmd);
}

// resets utils variables
int	reset_mnsh(t_mnsh *mnsh)
{
	t_cmd	*ptr;
	t_cmd	*del;

	ptr = mnsh->cmd;
	while (ptr)
	{
		del = ptr;
		ptr = ptr->next;
		free_cmd(del);
	}
	if (mnsh->input)
		free(mnsh->input);
	if (mnsh->pid)
		free(mnsh->pid);
	mnsh->reset = true;
	free_double_ptr((void **) mnsh->path);
	return (1);
}

// free memory on exit
void	free_mnsh(t_mnsh *mnsh)
{
	if (mnsh->pwd)
		free(mnsh->pwd);
	if (mnsh->old_pwd)
		free(mnsh->old_pwd);
	free_double_ptr((void **) mnsh->envp);
}

void	loop_mnsh(t_mnsh *mnsh)
{
	while (1)
	{
		mnsh->input = readline("minishell>");
		implement_mnsh(mnsh);//
		if (!mnsh->input)
		{
			reset_mnsh(mnsh);
			free_mnsh(mnsh);
			ft_printf("exit\n");
			exit(0);
		}
		else if (mnsh->input[0] == '\0')
		{
			reset_mnsh(mnsh);
			continue ;
		}
		//add_history(mnsh->input);
		//if (parse_input(mnsh))
		//	prepare_executor(mnsh);
		reset_mnsh(mnsh);
	}
}

/* the main program of minishell
1) Initilization of "t_mishell struct""
2) initilizaion of signals
3) running loops of minishell
4) free the memory
*/
int	main(int ac, char **av, char **envp)
{
	t_mnsh	mnsh;

	if (ac > 1 || av[1])
	{
		ft_printf("no argument needed, i.e., ./minishell");
		exit(0);
	}
	//ini_sigs();
	rl_catch_signals = 0;
	rl_event_hook = event;
	signal(SIGINT, sigint_handle);
	signal(SIGQUIT, sigquit_handle);
	// while (*envp)
	// {
	// 	ft_printf("%s\n", *envp);
	// 	envp++;
	// }	
	ini_mnsh(&mnsh, envp);
	//ft_printf("0k-2");
	ft_printf("\n\n%s\n\n", "Starting Minishell...");
	loop_mnsh(&mnsh);
	free_mnsh(&mnsh);
	return (0);
}