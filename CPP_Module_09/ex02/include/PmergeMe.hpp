/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:21:43 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/03/06 19:59:49 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <cstdlib>
# include <vector>
# include <algorithm>
# include <ctime>
# include <deque>
# include <list>

class PmergeMe
{
	public:
		PmergeMe(int ac, char *av[]);
		PmergeMe(PmergeMe const &src);
		~PmergeMe();

		PmergeMe	&operator=(PmergeMe const &rhs);

		void	parseSequence(int ac, char *av[]);
		void	merge_insert_vector();
		void	merge_insert_deque();

	private:
		std::vector<int>	_sequence;
};

#endif
