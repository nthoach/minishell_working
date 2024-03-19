/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:00:38 by marvin            #+#    #+#             */
/*   Updated: 2024/02/20 05:55:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdint.h> 
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *s, const char *need, size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

typedef struct s_formats
{
	int	minus;
	int	zero;
	int	dot;
	int	sharp;
	int	space;
	int	plus;
	int	width;
	int	precision;
	int	sign;
	int	len_digit;
	int	len_total;
	int	err;
}	t_formats;

/* "cspdiuxX%" flags for mandatory */
/* "-0.# +" flags for bonus */
/* two numbers for length-width */
/* sign for printing sign or not*/

int			ft_printf(const	char *s_in, ...);
int			print_types(va_list ap, t_formats *formats, char **s);
void		get_flags(t_formats *formats, char **s);
void		get_width_prcn(int *width, char **s);
int			print_c(char c, t_formats *formats);
int			print_s(char *s, t_formats *formats);
int			print_p(unsigned long p, t_formats *formats);
int			print_di(int n, t_formats *formats);
int			print_di1(t_formats *formats, int n);
int			print_di2(t_formats *formats, int n);
int			print_di3(t_formats *formats, int n);
int			print_di4(t_formats *formats, int n);
int			print_u(unsigned int u, t_formats *formats);
int			print_x(unsigned int x, t_formats *formats, char c);
int			print_precision(t_formats *formats, int no_digit);
int			print_width(t_formats *formats, int len_total, char c);
int			print_sign(t_formats *formats, int n);
void		print_hex(unsigned long n, char x, t_formats *formats, int *np);
int			print_0x(t_formats *formats, char c, unsigned int x);
int			len_s_base(unsigned long n, int base);
int			len_uint(unsigned int n, t_formats formats, int base);
int			len_int(int n);
int			totalize_len(int n, int no_digit, t_formats *formats);
int			total_len(int precision, int len_u);
void		ft_putpnbr(unsigned int n, t_formats *formats, int *np);
void		ft_putnbr(long n, int *p_np, int *err);
int			ft_putxstr(char *s, int len, int *err);
int			ft_putnchar(char c, int n, int *err);

size_t		gnl_len(char	*s);
void		gnl_bzero(void *s, size_t n);
void		*gnl_calloc(size_t count, size_t size);
char		*add_text(char *store_in, char *buffer);
size_t		gnl_strchr(char	*buffer, char chr);
char		*extract_line(char *store_text);
char		*take_remain(char	*store_in);
char		*read_line(char	*store_text, int fd);
char		*get_next_line(int fd);
char		*get_next_line_err(int fd, int err);

#endif