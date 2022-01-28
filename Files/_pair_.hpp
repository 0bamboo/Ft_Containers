/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pair_.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:25:01 by abdait-m          #+#    #+#             */
/*   Updated: 2022/01/27 23:07:38 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PAIR__HPP
#define _PAIR__HPP

namespace ft{
	
	template<typename _T1, typename _T2>
	class pair{
		
		public:
			
			typedef _T1		_firstType;
			typedef _T2		_secondType;
			
			_firstType		_first;
			_secondType		_second;

			// Constructors:
			pair() : _first(), _second() { }
			
			pair(const _firstType& f, const _secondType& s) : _first(f), _second(s) { }
			
			template<typename X, typename Y>
			pair(const pair<X, Y>& _pair) : _first(_pair._first), _second(_pair._second) { }

			pair&	operator = (const pair& _pair)
			{
				if (this != &_pair)
				{
					this->_first = _pair._first;
					this->_second = _pair._second;
				}
				return (*this);
			}
			
			~pair() { }

	}; // END! class pair 

	// Relational operators :
	
	template<typename _T1, typename _T2>
	bool	operator == (const pair<_T1, _T2>& _right, const pair<_T1, _T2>& _left)
	{
		return (_right._first == _left._first && _right._second == _left._second);
	}
	
	template<typename _T1, typename _T2>
	bool	operator != (const pair<_T1, _T2>& _right, const pair<_T1, _T2>& _left)
	{
		return (!(_right == _left));
	}

	template<typename _T1, typename _T2>
	bool	operator < (const pair<_T1, _T2>& _right, const pair<_T1, _T2>& _left)
	{
		return (_right._first < _left._second || (!(_left._first < _right._first) && _right._second < _left._second));
	}

	template<typename _T1, typename _T2>
	bool	operator <= (const pair<_T1, _T2>& _right, const pair<_T1, _T2>& _left)
	{
		return (!(_left < _right));
	}

	template<typename _T1, typename _T2>
	bool	operator > (const pair<_T1, _T2>& _right, const pair<_T1, _T2>& _left)
	{
		return (_left < _right);
	}

	template<typename _T1, typename _T2>
	bool	operator >= (const pair<_T1, _T2>& _right, const pair<_T1, _T2>& _left)
	{
		return (!(_right < _left));
	}
	
	// make_pair :
	template<typename _T1, typename _T2>
	pair<_T1, _T2>	make_pair(_T1 _first, _T2 _second)
	{
		return (pair<_T1, _T2>(_first, _second));
	}
	
};


#endif
