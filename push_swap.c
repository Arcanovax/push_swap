/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthetcha <mthetcha@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:44:31 by mthetcha          #+#    #+#             */
/*   Updated: 2025/12/09 09:51:48 by mthetcha         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 1)
		return (0);
	while (argv[i])
	{
		printf("%d ", argv[i]);
		i++;
	}


}
