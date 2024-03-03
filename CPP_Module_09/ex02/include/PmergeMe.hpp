/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:21:43 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/02/28 22:59:58 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <cstdlib>
# include <vector>
// # include <utility>
# include <algorithm>
# include <ctime>
# include <deque>

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
