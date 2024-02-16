/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:21:43 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/02/16 21:32:55 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <cstdlib>
# include <vector>

class PmergeMe
{
	public:
		PmergeMe(int ac, char *av[]);
		PmergeMe(PmergeMe const &src);
		~PmergeMe();

		PmergeMe	&operator=(PmergeMe const &rhs);

		void	parseSequence(int ac, char *av[]);
		void	merge_insert();

	private:
		std::vector<int>	_vec_seq;
		// char **_sequence;
};

#endif
