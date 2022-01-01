/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _trait_types_.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 18:37:30 by abdait-m          #+#    #+#             */
/*   Updated: 2022/01/01 20:01:21 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TRAIT_TYPES_HPP
# define _TRAIT_TYPES_HPP

# include <iostream>

namespace ft
{
	template<bool Cond, class T = void>
	struct enable_if { };
	 
	template<class T>
	struct enable_if<true, T>
	{
		typedef T type; 
	};

	/* is_integral */
	template <class T>
	struct is_integral
	{
		static const bool value = false;
	};
	/* bool */
	template <>
	struct is_integral<bool>
	{
		static const bool value = true;
	};
	/* char */ 
	template <>
	struct is_integral<char>
	{
		static const bool value = true;
	};
	/* wchar_t */
	template <>
	struct is_integral<wchar_t>
	{
		static const bool value = true;
	};
	/* char16_t */
	template <>
	struct is_integral<char16_t>
	{
		static const bool value = true;
	};
	/* char32_t */
	template <>
	struct is_integral<char32_t>
	{
		static const bool value = true;
	};
	/* signed char */
	template <>
	struct is_integral<signed char>
	{
		static const bool value = true;
	};
	/* short int */
	template <>
	struct is_integral<short int>
	{
		static const bool value = true;
	};
	/* int */
	template <>
	struct is_integral<int>
	{
		static const bool value = true;
	};
	/* long int */
	template <>
	struct is_integral<long int>
	{
		static const bool value = true;
	};
	/* long long int */
	template <>
	struct is_integral<long long int>
	{
		static const bool value = true;
	};
	/* unsigned  char */
	template <>
	struct is_integral<unsigned char>
	{
		static const bool value = true;
	};
	/* unsigned short int */
	template <>
	struct is_integral<unsigned short int>
	{
		static const bool value = true;
	};
	/* unsigned int */
	template <>
	struct is_integral<unsigned int>
	{
		static const bool value = true;
	};
	/* unsigned long int */
	template <>
	struct is_integral<unsigned long int>
	{
		static const bool value = true;
	};
	/* unsigned long long int */
	template <>
	struct is_integral<unsigned long long int>
	{
		static const bool value = true;
	};
	
}

#endif