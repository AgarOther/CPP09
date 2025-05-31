/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 03:10:35 by scraeyme          #+#    #+#             */
/*   Updated: 2025/05/31 11:16:34 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

template <typename T>
bool isDuplicate(T &sequence, int n)
{
	for (typename T::iterator it = sequence.begin(); it != sequence.end(); it++)
	{
		if (*it == n)
			return (true);
	}
	return (false);
}

template <typename T>
bool isSorted(T &sequence)
{
	int tmp;

	for (typename T::iterator it = sequence.begin(); it != sequence.end(); it++)
	{
		if (it == sequence.begin())
		{
			tmp = *it;
			continue;
		}
		if (tmp > *it)
			return (false);
		tmp = *it;
	}
	return (true);
}

template <typename T>
void binaryInsertion(T &values, int value)
{
	int left = 0;
	int right = values.size();
	int mid;
	
	while (left < right)
	{
		mid = (left + right) / 2;
		if (value < values[mid])
			right = mid;
		else
			left = mid + 1;
	}
	values.insert(values.begin() + left, value);
}

template <typename T>
T getJacobsthal(int size)
{
	T jacobsthal;
	T remaining;
	int j0;
	int j1;
	int next;
	int i;

	j0 = 0;
	j1 = 1;
	i = 1;
	while (j1 < size)
	{
		jacobsthal.push_back(j1);
		next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
		i++;
	}
	for (int i = 0; i < size; i++)
	{
		if (std::find(jacobsthal.begin(), jacobsthal.end(), i) == jacobsthal.end())
			remaining.push_back(i);
	}
	for (typename T::iterator it = remaining.begin(); it != remaining.end(); it++)
		jacobsthal.push_back(*it);
	return (jacobsthal);
}

template <typename T>
T fordJohnson(T &values)
{
	T smallValues;
	T bigValues;
	T smallSorted;
	T result;
	T jacobsthal;
	T addedIndices;
	int first;
	int second;
	int value;
	int jacobIndex;

	if (values.size() <= 1)
		return (values);
	for (typename T::iterator it = values.begin(); it != values.end(); it++)
	{
		first = *it;
		it++;
		if (it == values.end())
		{
			bigValues.push_back(first); 
			break;
		}
		second = *it;
		smallValues.push_back(std::min(first, second));
		bigValues.push_back(std::max(first, second));
	}
	smallSorted = fordJohnson(smallValues);
	result = smallSorted;
	if (!bigValues.empty())
	{
		binaryInsertion(result, *bigValues.begin());
		bigValues.erase(bigValues.begin());
	}
	jacobsthal = getJacobsthal<T >(bigValues.size());
	for (typename T::iterator it = jacobsthal.begin(); it != jacobsthal.end(); it++)
	{
		jacobIndex = *it;
		if (jacobIndex >= static_cast<int>(bigValues.size()))
			continue;
		if (std::find(result.begin(), result.end(), bigValues[jacobIndex]) == result.end())
		{
			value = bigValues[jacobIndex];
			binaryInsertion(result, value);
			addedIndices.push_back(jacobIndex);
		}
	}
	return (result);
}
