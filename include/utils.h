/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:29:03 by jbadia            #+#    #+#             */
/*   Updated: 2021/07/27 15:36:05 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include<signal.h>
# include<unistd.h>
# include<stdlib.h>
# include<sys/types.h>

void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);

#endif