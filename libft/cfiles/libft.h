/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:15:54 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/20 23:47:54 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

char			*ft_itoa(int nbr);
int				ft_atoi(const char *str);
int				ft_isalnum(int ch);
int				ft_isalpha(int ch);
int				ft_isascii(int ch);
int				ft_isdigit(int ch);
int				ft_isprint(int ch);
int				ft_tolower(int ch);
int				ft_toupper(int ch);

void			*ft_calloc(size_t nitems, size_t size);
void			ft_bzero(void *dest, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t num);
void			*ft_memccpy(void *dest, const void *src, int c, size_t count);
void			*ft_memmove(void *dest, const void *src, size_t count);
void			*ft_memset(void *dest, int c, size_t count);
const	void	*ft_memchr(const void *buf, int c, size_t count);
int				ft_memcmp(const void *buf1, const void *buf2, size_t count);

size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strdup(const char *s);
char			*ft_ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int ch);
int				ft_strncmp(const char *str1, const char *str2, size_t num);

char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);

t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
int				ft_lstsize(t_list *lst);
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));

#endif
