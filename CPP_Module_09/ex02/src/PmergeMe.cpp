/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:21:33 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/03/06 21:55:17 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

PmergeMe::PmergeMe(int ac, char *av[])
{
	parseSequence(ac, av);

	std::cout << "Before:\t ";
	for (std::vector<int>::iterator it = _sequence.begin(); it != _sequence.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	merge_insert_vector();
	merge_insert_deque();
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe::~PmergeMe()
{
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */


void	checkDigit(std::string num)
{
	for (size_t i = 0; i < num.length(); ++i)
	{
		if (!isdigit(num[i]))
			throw std::runtime_error("sequence must contains only positive int");
	}
	if (atoi(num.c_str()) <= 0)
		throw std::runtime_error("sequence must contains only positive int");
}

void	PmergeMe::parseSequence(int ac, char *av[])
{
	std::string	num;
	
	for	(int i = 1; i < ac; ++i)
	{
		num = av[i];
		checkDigit(num);
		_sequence.push_back(atoi(num.c_str()));
	}
}

size_t		jacobsthal(int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

template<typename T, typename U>
void	insertionSort(T &sortedSeq, T &unsortedSeq, U &pairSeq)
{
	size_t	i = 3;
	int		lastElem = -1;
	
	if (unsortedSeq.size() == sortedSeq.size())	// Check if odd number of elements
		lastElem = *(unsortedSeq.end() - 1);
	for (size_t jacobIndex = jacobsthal(i); jacobsthal(i - 1) <= unsortedSeq.size(); jacobIndex = jacobsthal(++i))
	{
		size_t prev_jacobIndex = jacobsthal(i - 1);
		size_t index = jacobIndex;

		if (jacobIndex >= unsortedSeq.size())
			index = unsortedSeq.size();
		while (index > prev_jacobIndex)
		{
			typename T::iterator it_target;
			if (unsortedSeq[index - 1] != lastElem)
				it_target = std::lower_bound(sortedSeq.begin(), sortedSeq.end(), pairSeq[index - 1].first);
			else // If odd element the last element is not in pairSeq
				it_target = sortedSeq.end();

			typename T::iterator insert_pos = std::upper_bound(sortedSeq.begin(), it_target, unsortedSeq[index - 1]);
			
			sortedSeq.insert(insert_pos, unsortedSeq[index - 1]);
			index--;
		}
	}
}

template<typename T>
void	merge(T &seq, int start, int mid, int end)
{
	int	leftDataSize = mid - start + 1;
	int	rightDataSize = end - mid;

	T	leftData(leftDataSize);
	T	rightData(rightDataSize);

	for (int i = 0; i < leftDataSize; i++)
		leftData[i] = seq[start + i];
	for (int i = 0; i < rightDataSize; i++)
		rightData[i] = seq[mid + i + 1];
	
	int i = 0, j = 0, k = start;
	for (; i < leftDataSize && j < rightDataSize; ++k)
	{
		if (leftData[i].first < rightData[j].first)
		{
			seq[k] = leftData[i];
			++i;
		}
		else
		{
			seq[k] = rightData[j];
			++j;
		}
	}
	
	for (; i < leftDataSize; ++i, ++k)
		seq[k] = leftData[i];

	for (; j < rightDataSize; ++j, ++k)
		seq[k] = rightData[j];
}

template<typename T>
void	mergeSort(T &seq, int start, int end)
{
	if (start < end)
	{
		int	mid = (start + end) / 2;
		mergeSort(seq, start, mid);
		mergeSort(seq, mid + 1, end);
		merge(seq, start, mid, end);
	}
}

void	PmergeMe::merge_insert_vector()
{
	clock_t start = clock();
	
	//	1.	Group the elements of X into [n/2] pairs of elements, arbitrarily,
	//		leaving one element unpaired if there is an odd number of elements.
	std::vector<std::pair<int, int> > pairSeq;
	
	for (size_t i = 1; i < _sequence.size(); i += 2)
	{
		pairSeq.push_back(std::make_pair(_sequence[i - 1], _sequence[i]));
	}

	int	lastElem = 0;
	if (_sequence.size() % 2 == 1)
		lastElem = *(_sequence.end() - 1);
	
	// 2.	Perform [n/2] comparisons, one per pair,
	// 		to determine the larger of the two elements in each pair.
	for (size_t i = 0; i < pairSeq.size(); i++)
	{
		if (pairSeq[i].first < pairSeq[i].second)
			std::swap(pairSeq[i].first, pairSeq[i].second);
	}
	
	// 3.	Recursively sort the [n/2] larger elements from each pair,
	// 		creating a sorted sequence S of [n/2] of the input elements,
	//		in ascending order.
	mergeSort(pairSeq, 0, pairSeq.size() - 1);

	std::vector<int> sortedSeq;
	for (size_t i = 0; i < pairSeq.size(); i++)
	{
		sortedSeq.push_back(pairSeq[i].first);
	}
	std::vector<int> unsortedSeq;
	for (size_t i = 0; i < pairSeq.size(); i++)
	{
		unsortedSeq.push_back(pairSeq[i].second);
	}
	if (lastElem)
		unsortedSeq.push_back(lastElem);
	
	// 4.	Insert at the start of S the element that was paired with the first
	// 		and smallest element of S.
	sortedSeq.insert(sortedSeq.begin(), *(unsortedSeq.begin()));

	// 5.	Insert the remaining [n/2] - 1 elements of X \ S into S,
	//		one at a time, with a specially chosen insertion ordering described
	// 		below. Use binary search in subsequences of S (as described below)
	// 		to determine the position at which each element should be inserted.
	// 		Source : https://en.wikipedia.org/wiki/Merge-insertion_sort
	insertionSort(sortedSeq, unsortedSeq, pairSeq);

	clock_t end = clock();

	std::cout << "After:\t ";
	for (std::vector<int>::iterator it = sortedSeq.begin(); it != sortedSeq.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	double elapsed_time_us = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of \t" << _sequence.size() << " elements with std::vector : " << elapsed_time_us << " us" << std::endl;

	// std::cout << "TEST IF SORTED :" << std::endl;
	// for (size_t i = 1; i < sortedSeq.size(); ++i)
	// {
	// 	if (sortedSeq[i] < sortedSeq[i - 1])
	// 	{
	// 		std::cout << sortedSeq[i - 1] << " > " << sortedSeq[i] << std::endl;
	// 	}
	// }
}

void	PmergeMe::merge_insert_deque()
{
	clock_t start = clock();
	
	//	1.
	std::deque<std::pair<int, int> > pairSeq;
	
	for (size_t i = 1; i < _sequence.size(); i += 2)
	{
		pairSeq.push_back(std::make_pair(_sequence[i - 1], _sequence[i]));
	}

	int	lastElem = 0;
	if (_sequence.size() % 2 == 1)
		lastElem = *(_sequence.end() - 1);
	
	// 2.
	for (size_t i = 0; i < pairSeq.size(); i++)
	{
		if (pairSeq[i].first < pairSeq[i].second)
			std::swap(pairSeq[i].first, pairSeq[i].second);
	}
	
	// 3.
	mergeSort(pairSeq, 0, pairSeq.size() - 1);

	std::deque<int> sortedSeq;
	for (size_t i = 0; i < pairSeq.size(); i++)
	{
		sortedSeq.push_back(pairSeq[i].first);
	}
	std::deque<int> unsortedSeq;
	for (size_t i = 0; i < pairSeq.size(); i++)
	{
		unsortedSeq.push_back(pairSeq[i].second);
	}
	if (lastElem)
		unsortedSeq.push_back(lastElem);
	
	// 4.
	sortedSeq.insert(sortedSeq.begin(), *(unsortedSeq.begin()));

	// 5.
	insertionSort(sortedSeq, unsortedSeq, pairSeq);

	clock_t end = clock();

	double elapsed_time_us = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	
	std::cout << "Time to process a range of \t" << _sequence.size() << " elements with std::deque : " << elapsed_time_us << " us" << std::endl;

	// std::cout << "TEST IF SORTED :" << std::endl;
	// for (size_t i = 1; i < sortedSeq.size(); ++i)
	// {
	// 	if (sortedSeq[i] < sortedSeq[i - 1])
	// 	{
	// 		std::cout << sortedSeq[i - 1] << " > " << sortedSeq[i] << std::endl;
	// 	}
	// }
}
