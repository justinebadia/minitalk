/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:28:43 by jbadia            #+#    #+#             */
/*   Updated: 2021/07/27 15:08:24 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include<signal.h>
# include<unistd.h>
# include<stdlib.h>

void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	error_msg(char *str);

#endif