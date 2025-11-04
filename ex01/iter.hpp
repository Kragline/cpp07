#pragma once

#include <iostream>

template <typename T, typename F>
void	iter(T *array, size_t length, F func)
{
	if (!array || !length)
		return ;
	
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T, typename F>
void	iter(const T *array, size_t length, F func)
{
	if (!array || !length)
		return ;
	
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}
