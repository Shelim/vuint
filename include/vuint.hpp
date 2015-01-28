/*
 * VARIABLE LENGTH UNSIGNED INT (in C++ '11)
 *
 * AUTHOR: Piotr Kosek (student - Faculty of Physics and Applied Informatics, University of Lodz)
 * CONTACT: piotr-kosek@tlen.pl
 * LICENSE: X11 License (MIT)
 * VERSION: 0.1 (2014/10/28)
 * __________________________________________________________________________________________________
 *
 * CONSTRAINS:
 *		o sizeof(vuint<len>) == len / 8
 *		o There is no memory allocation in any method
 *		o Well-defined for every int characteristics that is well-defined in C++ standard
 *		o Never crashes (division by 0 yelds in undefined behaviour, but still won't crash)
 *		o Never casts exceptions
 *		o Works with iostream, utilizing all stream flags (such as hex)
 * __________________________________________________________________________________________________
 *
 * LIMITATION:
 *		o It's NOT thread-safe (especially for streams!)
 *		o When using binary operator (such as +) on variable length arguments, the result
 *			length is equal to length of the LEFT operator.
 *				e.g.
 *			vuint<8> a = 255;
 *			vuint<16> b = 255;
 *			a + b; // the result type is vuint<8> and the value will overflow
 * __________________________________________________________________________________________________
 *
 * Copyright (c) 2014 Piotr Kosek
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 * A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 * __________________________________________________________________________________________________
 *
 * CHANGELOG:
 *		o 2014/10/28 - initial version
 * __________________________________________________________________________________________________
 *
 */

#pragma once
#ifndef V_UINT_HPP_INCLUDED
#define V_UINT_HPP_INCLUDED

#include<cstdint>
#include<cstring>
#include<algorithm>
#include<iostream>

template<int len> class vuint
{

public:

	static_assert((len % 8) == 0, "vuint only supports a multiple of 8 as length");
	static_assert(len != 0, "vuint cannot be empty!");

	vuint()
	{
		fill(0);
	}
	vuint(uint8_t v)
	{
		setval(v);
	}
	vuint(uint16_t v)
	{
		setval(v);
	}
	vuint(uint32_t v)
	{
		setval(v);
	}
	vuint(uint64_t v)
	{
		setval(v);
	}
	vuint(int8_t v)
	{
		setval(v);
	}
	vuint(int16_t v)
	{
		setval(v);
	}
	vuint(int32_t v)
	{
		setval(v);
	}
	vuint(int64_t v)
	{
		setval(v);
	}
	explicit vuint(float v)
	{
		setval((int64_t)v);
	}
	explicit vuint(double v)
	{
		setval((int64_t)v);
	}
	explicit vuint(long double v)
	{
		setval((int64_t)v);
	}

	vuint(const vuint<len> & v)
	{
		memcpy(dat, v.dat, len / 8);
	}

	template<int len2> vuint(const vuint<len2> & v)
	{
		setval2(v);
	}

	vuint<len> & operator=(const vuint<len> & v)
	{
		memcpy(dat, v.dat, len / 8);
		return *this;
	}

	vuint<len> & operator=(uint8_t v)
	{
		setval(v);
		return *this;
	}

	vuint<len> & operator=(uint16_t v)
	{
		setval(v);
		return *this;
	}

	vuint<len> & operator=(uint32_t v)
	{
		setval(v);
		return *this;
	}

	vuint<len> & operator=(uint64_t v)
	{
		setval(v);
		return *this;
	}

	vuint<len> & operator=(int8_t v)
	{
		setval(v);
		return *this;
	}

	vuint<len> & operator=(int16_t v)
	{
		setval(v);
		return *this;
	}

	vuint<len> & operator=(int32_t v)
	{
		setval(v);
		return *this;
	}

	vuint<len> & operator=(int64_t v)
	{
		setval(v);
		return *this;
	}

	template<int len2> vuint<len> & operator=(const vuint<len2> & v)
	{
		setval2(v);
		return *this;
	}

	vuint<len>& operator++ ()
	{
		for (int_fast32_t i = 0; i < len / 8; i++)
		{
			if (dat[addra(i)] != 0xFF)
			{
				++dat[addra(i)];
				break;
			}
			else
			{
				dat[addra(i)] = 0;
			}
		}
		return *this;
	}

	vuint<len> operator++ (int)
	{
		vuint<len> r(*this);
		++(*this);
		return r;
	}

	vuint<len>& operator-- ()
	{
		for (int_fast32_t i = 0; i < len / 8; i++)
		{
			if (dat[addra(i)] != 0x00)
			{
				--dat[addra(i)];
				break;
			}
			else
			{
				dat[addra(i)] = 0xFF;
			}
		}
		return *this;
	}

	vuint<len> operator-- (int)
	{
		vuint<len> r(*this);
		--(*this);
		return r;
	}


	template<int len2> vuint<len> & operator +=(const vuint<len2> & v)
	{
		uint16_t sum = 0;

		int_fast32_t p = std::min((int_fast32_t)len / 8, (int_fast32_t)len2 / 8);

		for (int_fast32_t i = 0; i < p; i++)
		{
			sum = geta(i) + v.geta(i) + (sum >> 8);
			seta(i, sum & 0xFF);
		}

		for (int_fast32_t i = p; i < len / 8; i++)
		{
			sum = geta(i) + (sum >> 8);
			seta(i, sum & 0xFF);
		}

		return *this;
	}
	vuint<len> & operator +=(uint8_t v)
	{
		return this->operator+=(vuint<8>(v));
	}
	vuint<len> & operator +=(uint16_t v)
	{
		return this->operator+=(vuint<16>(v));
	}
	vuint<len> & operator +=(uint32_t v)
	{
		return this->operator+=(vuint<32>(v));
	}
	vuint<len> & operator +=(uint64_t v)
	{
		return this->operator+=(vuint<64>(v));
	}
	vuint<len> & operator +=(int8_t v)
	{
		return this->operator+=(vuint<8>(v));
	}
	vuint<len> & operator +=(int16_t v)
	{
		return this->operator+=(vuint<16>(v));
	}
	vuint<len> & operator +=(int32_t v)
	{
		return this->operator+=(vuint<32>(v));
	}
	vuint<len> & operator +=(int64_t v)
	{
		return this->operator+=(vuint<64>(v));
	}

	template<int len2> vuint<len> & operator -=(const vuint<len2> & v)
	{
		int16_t diff = 0;
		uint8_t take = 0;

		for (int_fast32_t i = 0; i < len / 8; i++)
		{
			diff = geta(i) - ((i < (len2 / 8)) ? v.geta(i) : 0) - take;
			if (diff < 0)
			{
				take = 1;
				diff += 256;
			}
			else
				take = 0;

			seta(i, (uint8_t)diff);
		}

		return *this;
	}

	vuint<len> & operator -=(uint8_t v)
	{
		return this->operator-=(vuint<8>(v));
	}
	vuint<len> & operator -=(uint16_t v)
	{
		return this->operator-=(vuint<16>(v));
	}
	vuint<len> & operator -=(uint32_t v)
	{
		return this->operator-=(vuint<32>(v));
	}
	vuint<len> & operator -=(uint64_t v)
	{
		return this->operator-=(vuint<64>(v));
	}
	vuint<len> & operator -=(int8_t v)
	{
		return this->operator-=(vuint<8>(v));
	}
	vuint<len> & operator -=(int16_t v)
	{
		return this->operator-=(vuint<16>(v));
	}
	vuint<len> & operator -=(int32_t v)
	{
		return this->operator-=(vuint<32>(v));
	}
	vuint<len> & operator -=(int64_t v)
	{
		return this->operator-=(vuint<64>(v));
	}

	template<int len2> vuint<len> & operator *=(const vuint<len2> & v)
	{
		vuint<len> arg = *this;
		fill(0);

		for (int_fast32_t i = 0; i < len2; i++)
		{
			if (v.getbit(i))
			{
				*this += arg << i;
			}
		}

		return *this;
	}
	vuint<len> & operator *=(uint8_t v)
	{
		return this->operator*=(vuint<8>(v));
	}
	vuint<len> & operator *=(uint16_t v)
	{
		return this->operator*=(vuint<16>(v));
	}
	vuint<len> & operator *=(uint32_t v)
	{
		return this->operator*=(vuint<32>(v));
	}
	vuint<len> & operator *=(uint64_t v)
	{
		return this->operator*=(vuint<64>(v));
	}
	vuint<len> & operator *=(int8_t v)
	{
		return this->operator*=(vuint<8>(v));
	}
	vuint<len> & operator *=(int16_t v)
	{
		return this->operator*=(vuint<16>(v));
	}
	vuint<len> & operator *=(int32_t v)
	{
		return this->operator*=(vuint<32>(v));
	}
	vuint<len> & operator *=(int64_t v)
	{
		return this->operator*=(vuint<64>(v));
	}

	template<int len2> vuint<len> & operator /=(const vuint<len2> & v)
	{
		vuint<len> arg = *this;
		vuint<len> r;
		fill(0);
		r.fill(0);

		for (int_fast32_t i = len - 1; i >= 0; i--)
		{
			r <<= 1;
			r.setbit(0, arg.getbit(i));
			if (r >= v)
			{
				r -= v;
				setbit(i, 1);
			}
		}
		return *this;
	}


	vuint<len> & operator /=(uint8_t v)
	{
		return this->operator/=(vuint<8>(v));
	}
	vuint<len> & operator /=(uint16_t v)
	{
		return this->operator/=(vuint<16>(v));
	}
	vuint<len> & operator /=(uint32_t v)
	{
		return this->operator/=(vuint<32>(v));
	}
	vuint<len> & operator /=(uint64_t v)
	{
		return this->operator/=(vuint<64>(v));
	}
	vuint<len> & operator /=(int8_t v)
	{
		return this->operator/=(vuint<8>(v));
	}
	vuint<len> & operator /=(int16_t v)
	{
		return this->operator/=(vuint<16>(v));
	}
	vuint<len> & operator /=(int32_t v)
	{
		return this->operator/=(vuint<32>(v));
	}
	vuint<len> & operator /=(int64_t v)
	{
		return this->operator/=(vuint<64>(v));
	}

	template<int len2> vuint<len> & operator %=(const vuint<len2> & v)
	{
		vuint<len> arg = *this;
		vuint<len> q;
		fill(0);
		q.fill(0);

		for (int_fast32_t i = len - 1; i >= 0; i--)
		{
			*this <<= 1;
			this->setbit(0, arg.getbit(i));
			if (*this >= v)
			{
				*this -= v;
				q.setbit(i, 1);
			}
		}
		return *this;
	}

	vuint<len> & operator %=(uint8_t v)
	{
		return this->operator%=(vuint<8>(v));
	}
	vuint<len> & operator %=(uint16_t v)
	{
		return this->operator%=(vuint<16>(v));
	}
	vuint<len> & operator %=(uint32_t v)
	{
		return this->operator%=(vuint<32>(v));
	}
	vuint<len> & operator %=(uint64_t v)
	{
		return this->operator%=(vuint<64>(v));
	}
	vuint<len> & operator %=(int8_t v)
	{
		return this->operator%=(vuint<8>(v));
	}
	vuint<len> & operator %=(int16_t v)
	{
		return this->operator%=(vuint<16>(v));
	}
	vuint<len> & operator %=(int32_t v)
	{
		return this->operator%=(vuint<32>(v));
	}
	vuint<len> & operator %=(int64_t v)
	{
		return this->operator%=(vuint<64>(v));
	}

	template<int len2> vuint<len> & operator ^=(const vuint<len2> & v)
	{
		int_fast32_t p = std::min((int_fast32_t)len / 8, (int_fast32_t)len2 / 8);

		for (int_fast32_t i = 0; i < p; i++)
		{
			seta(i, geta(i) ^ v.geta(i));
		}

		return *this;
	}

	vuint<len> & operator ^=(uint8_t v)
	{
		return this->operator^=(vuint<8>(v));
	}
	vuint<len> & operator ^=(uint16_t v)
	{
		return this->operator^=(vuint<16>(v));
	}
	vuint<len> & operator ^=(uint32_t v)
	{
		return this->operator^=(vuint<32>(v));
	}
	vuint<len> & operator ^=(uint64_t v)
	{
		return this->operator^=(vuint<64>(v));
	}
	vuint<len> & operator ^=(int8_t v)
	{
		return this->operator^=(vuint<8>(v));
	}
	vuint<len> & operator ^=(int16_t v)
	{
		return this->operator^=(vuint<16>(v));
	}
	vuint<len> & operator ^=(int32_t v)
	{
		return this->operator^=(vuint<32>(v));
	}
	vuint<len> & operator ^=(int64_t v)
	{
		return this->operator^=(vuint<64>(v));
	}


	template<int len2> vuint<len> & operator |=(const vuint<len2> & v)
	{
		int_fast32_t p = std::min((int_fast32_t)len / 8, (int_fast32_t)len2 / 8);

		for (int_fast32_t i = 0; i < p; i++)
		{
			seta(i, geta(i) | v.geta(i));
		}

		return *this;
	}

	vuint<len> & operator |=(uint8_t v)
	{
		return this->operator|=(vuint<8>(v));
	}
	vuint<len> & operator |=(uint16_t v)
	{
		return this->operator|=(vuint<16>(v));
	}
	vuint<len> & operator |=(uint32_t v)
	{
		return this->operator|=(vuint<32>(v));
	}
	vuint<len> & operator |=(uint64_t v)
	{
		return this->operator|=(vuint<64>(v));
	}
	vuint<len> & operator |=(int8_t v)
	{
		return this->operator|=(vuint<8>(v));
	}
	vuint<len> & operator |=(int16_t v)
	{
		return this->operator|=(vuint<16>(v));
	}
	vuint<len> & operator |=(int32_t v)
	{
		return this->operator|=(vuint<32>(v));
	}
	vuint<len> & operator |=(int64_t v)
	{
		return this->operator|=(vuint<64>(v));
	}


	template<int len2> vuint<len> & operator &=(const vuint<len2> & v)
	{
		int_fast32_t p = std::min((int_fast32_t)len / 8, (int_fast32_t)len2 / 8);

		for (int_fast32_t i = 0; i < p; i++)
		{
			seta(i, geta(i) & v.geta(i));
		}

		for (int_fast32_t i = len2 / 8; i < len / 8; i++)
		{
			seta(i, 0);
		}

		return *this;
	}

	vuint<len> & operator &=(uint8_t v)
	{
		return this->operator&=(vuint<8>(v));
	}
	vuint<len> & operator &=(uint16_t v)
	{
		return this->operator&=(vuint<16>(v));
	}
	vuint<len> & operator &=(uint32_t v)
	{
		return this->operator&=(vuint<32>(v));
	}
	vuint<len> & operator &=(uint64_t v)
	{
		return this->operator&=(vuint<64>(v));
	}
	vuint<len> & operator &=(int8_t v)
	{
		return this->operator&=(vuint<8>(v));
	}
	vuint<len> & operator &=(int16_t v)
	{
		return this->operator&=(vuint<16>(v));
	}
	vuint<len> & operator &=(int32_t v)
	{
		return this->operator&=(vuint<32>(v));
	}
	vuint<len> & operator &=(int64_t v)
	{
		return this->operator&=(vuint<64>(v));
	}

	vuint<len> operator~()
	{
		vuint<len> ret;

		for (int_fast32_t i = 0; i < len / 8; i++)
		{
			ret.seta(i, ~geta(i));
		}

		return ret;
	}

	template<int len2> vuint<len> & operator >>=(const vuint<len2> & v)
	{
		int32_t max1 = len;
		int32_t max2 = v;
		if (len > v)
		{
			for (int_fast32_t i = 0; i < len - v; i++)
			{
				setbit(i, getbit(i + v));
			}
			for (int_fast32_t i = len - v; i < len; i++)
			{
				setbit(i, false);
			}
		}
		else
		{
			fill(0);
		}

		return *this;
	}
	vuint<len> & operator >>=(uint8_t v)
	{
		return this->operator>>=(vuint<8>(v));
	}
	vuint<len> & operator >>=(uint16_t v)
	{
		return this->operator>>=(vuint<16>(v));
	}
	vuint<len> & operator >>=(uint32_t v)
	{
		return this->operator>>=(vuint<32>(v));
	}
	vuint<len> & operator >>=(uint64_t v)
	{
		return this->operator>>=(vuint<64>(v));
	}
	vuint<len> & operator >>=(int8_t v)
	{
		return this->operator>>=(vuint<8>(v));
	}
	vuint<len> & operator >>=(int16_t v)
	{
		return this->operator>>=(vuint<16>(v));
	}
	vuint<len> & operator >>=(int32_t v)
	{
		return this->operator>>=(vuint<32>(v));
	}
	vuint<len> & operator >>=(int64_t v)
	{
		return this->operator>>=(vuint<64>(v));
	}

	template<int len2> vuint<len> & operator <<=(const vuint<len2> & v)
	{
		for (int_fast32_t i = len - 1; i >= v; i--)
		{
			setbit(i, getbit(i - v));
		}
		for (int_fast32_t i = std::min((int_fast32_t)len, (int_fast32_t)v) - 1; i >= 0; i--)
		{
			setbit(i, false);
		}

		return *this;
	}
	vuint<len> & operator <<=(uint8_t v)
	{
		return this->operator<<=(vuint<8>(v));
	}
	vuint<len> & operator <<=(uint16_t v)
	{
		return this->operator<<=(vuint<16>(v));
	}
	vuint<len> & operator <<=(uint32_t v)
	{
		return this->operator<<=(vuint<32>(v));
	}
	vuint<len> & operator <<=(uint64_t v)
	{
		return this->operator<<=(vuint<64>(v));
	}
	vuint<len> & operator <<=(int8_t v)
	{
		return this->operator<<=(vuint<8>(v));
	}
	vuint<len> & operator <<=(int16_t v)
	{
		return this->operator<<=(vuint<16>(v));
	}
	vuint<len> & operator <<=(int32_t v)
	{
		return this->operator<<=(vuint<32>(v));
	}
	vuint<len> & operator <<=(int64_t v)
	{
		return this->operator<<=(vuint<64>(v));
	}

	operator uint8_t () const
	{
		return convert<uint8_t>();
	}

	operator uint16_t () const
	{
		return convert<uint16_t>();
	}

	operator uint32_t () const
	{
		return convert<uint32_t>();
	}

	operator uint64_t () const
	{
		return convert<uint64_t>();
	}

	operator int8_t () const
	{
		return convert<int8_t>();
	}

	operator int16_t () const
	{
		return convert<int16_t>();
	}

	operator int32_t () const
	{
		return convert<int32_t>();
	}

	operator int64_t () const
	{
		return convert<int64_t>();
	}

	operator float() const
	{
		return (float)convert<int64_t>();
	}

	operator double() const
	{
		return (double)convert<int64_t>();
	}

	operator long double() const
	{
		return (long double)convert<int64_t>();
	}

	explicit operator bool() const
	{
		for (int_fast32_t i = 0; i < len / 8; i++)
		{
			if (geta(i)) return true;
		}
		return false;
	}

	bool operator!() const
	{
		return !(bool)*this;
	}

	template<int l1, int l2> friend bool operator== (const vuint<l1> &lhs, const vuint<l2> &rhs);
	template<int l1, int l2> friend bool operator< (const vuint<l1> &lhs, const vuint<l2> &rhs);
	template<int len2> friend class vuint;
	template<int len2> friend vuint<len2> sqrt(vuint<len2> value);
	template<int len2> friend std::ostream& operator<<(std::ostream &os, const vuint<len2> &obj);
	template<int len2> friend std::istream& operator>>(std::istream &is, vuint<len2> &obj);

private:

	static inline bool isLittleEndian(void) // Compilers should deduce this at compile-time
	{
		static const union
		{
			uint16_t i;
			char c[2];
		} test = { 0x0102 };
		return test.c[1] == 1;
	}

	template<int p> static int_fast32_t addr()
	{
		return isLittleEndian() ? (len / 8 - p - 1) : p;
	}

	static inline int_fast32_t addra(int_fast32_t p) // Non-template version should still be resolved at compile-time
	{
		return isLittleEndian() ? (len / 8 - p - 1) : p;
	}

	template<int p> uint8_t get() const
	{
		return dat[addr<p>()];
	}

	template<int p> void set(uint8_t v)
	{
		dat[addr<p>()] = v;
	}

	inline void fill(uint8_t v)
	{
		memset(dat, v, len / 8);
	}

	inline void seta(int_fast32_t p, uint8_t v)
	{
		dat[addra(p)] = v;
	}

	inline uint8_t geta(int_fast32_t p) const
	{
		return dat[addra(p)];
	}

	template<typename T> void setval(T v)
	{
		int_fast32_t p = std::min((int_fast32_t)sizeof(T), (int_fast32_t)len / 8);

		for (int_fast32_t i = 0; i < p; i++) // Unroll at compile time?
		{
			seta(i, v & 0xFF);
			v >>= 8;
		}

		for (int_fast32_t i = sizeof(T); i < len / 8; i++)
		{
			seta(i, 0);
		}
	}

	template<int len2> void setval2(const vuint<len2> & v)
	{
		int_fast32_t p = std::min((int_fast32_t)len / 8, (int_fast32_t)len2 / 8);

		for (int_fast32_t i = 0; i < p; i++)
		{
			seta(i, v.geta(i));
		}

		for (int_fast32_t i = len2 / 8; i < len / 8; i++)
		{
			seta(i, 0);
		}
	}

	template<typename T> T convert() const
	{
		T ret = 0;
		int_fast32_t p = std::min((int_fast32_t)sizeof(T), (int_fast32_t)len / 8) - 1;

		for (int_fast32_t i = p; i >= 0; i--)
		{
			ret += geta(i);
			if (i != 0)
				ret <<= 8;
		}
		return ret;
	}

	bool getbit(int_fast32_t p) const
	{
		static uint8_t mask[] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };

		return (geta(p / 8) & mask[p % 8]) == mask[p % 8];
	}

	void setbit(int_fast32_t p, bool val)
	{
		static uint8_t mask[] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };

		if (val)
			seta(p / 8, geta(p / 8) | mask[p % 8]);
		else
			seta(p / 8, geta(p / 8) & ~mask[p % 8]);
	}

	uint8_t dat[len / 8];
};

template<int lf, int lr> bool operator== (const vuint<lf> &lhs, const vuint<lr> &rhs)
{
	int_fast32_t len = std::min(lf, lr);
	for (int_fast32_t i = 0; i < len / 8; i++)
	{
		if (lhs.geta(i) != rhs.geta(i)) return false;
	}
	for (int_fast32_t i = lr / 8; i < lf / 8; i++)
	{
		if (lhs.geta(i)) return false;
	}
	for (int_fast32_t i = lf / 8; i < lr / 8; i++)
	{
		if (rhs.geta(i)) return false;
	}
	return true;
}

template<int l1, int l2> bool operator!= (const vuint<l1> &lhs, const vuint<l2> &rhs)
{
	return !(lhs == rhs);
}

template<int lf, int lr> bool operator< (const vuint<lf> &lhs, const vuint<lr> &rhs)
{
	for (int_fast32_t i = lf / 8 - 1; i >= lr / 8; i--)
	{
		if (lhs.geta(i))
			return false;
	}
	for (int_fast32_t i = lr / 8 - 1; i >= lf / 8; i--)
	{
		if (rhs.geta(i))
			return true;
	}
	for (int_fast32_t i = std::min(lf, lr) / 8 - 1; i >= 0; i--)
	{
		uint8_t l = lhs.geta(i);
		uint8_t r = rhs.geta(i);
		if (l < r)
			return true;
		else if (l > r)
			return false;
	}
	return false;
}

template<int lf, int lr> bool operator<= (const vuint<lf> &lhs, const vuint<lr> &rhs)
{
	return !(lhs > rhs);
}

template<int lf, int lr> bool operator>(const vuint<lf> &lhs, const vuint<lr> &rhs)
{
	return rhs < lhs;
}

template<int lf, int lr> bool operator>= (const vuint<lf> &lhs, const vuint<lr> &rhs)
{
	return !(lhs < rhs);
}

template<int len> bool operator==(const vuint<len> &lhs, const uint8_t &rhs)
{
	return lhs == (vuint<8>)rhs;
}

template<int len> bool operator!=(const vuint<len> &lhs, const uint8_t &rhs)
{
	return !(lhs == rhs);
}

template<int len> bool operator<(const vuint<len> &lhs, const uint8_t &rhs)
{
	return lhs < (vuint<8>)rhs;
}

template<int len> bool operator<=(const vuint<len> &lhs, const uint8_t &rhs)
{
	return !(lhs > rhs);
}

template<int len> bool operator> (const vuint<len> &lhs, const uint8_t &rhs)
{
	return rhs < lhs;
}

template<int len> bool operator>= (const vuint<len> &lhs, const uint8_t &rhs)
{
	return !(lhs < rhs);
}

template<int len> bool operator==(const uint8_t &lhs, const vuint<len> &rhs)
{
	return (vuint<8>)lhs == rhs;
}

template<int len> bool operator!=(const uint8_t &lhs, const vuint<len> &rhs)
{
	return !(lhs == rhs);
}

template<int len> bool operator<(const uint8_t &lhs, const vuint<len> &rhs)
{
	return (vuint<8>)lhs < rhs;
}

template<int len> bool operator<=(const uint8_t &lhs, const vuint<len> &rhs)
{
	return !(lhs > rhs);
}

template<int len> bool operator>(const uint8_t &lhs, const vuint<len> &rhs)
{
	return rhs < lhs;
}

template<int len> bool operator>=(const uint8_t &lhs, const vuint<len> &rhs)
{
	return !(lhs < rhs);
}

template<int len> bool operator==(const vuint<len> &lhs, const uint16_t &rhs)
{
	return lhs == (vuint<16>)rhs;
}

template<int len> bool operator!=(const vuint<len> &lhs, const uint16_t &rhs)
{
	return !(lhs == rhs);
}

template<int len> bool operator<(const vuint<len> &lhs, const uint16_t &rhs)
{
	return lhs < (vuint<16>)rhs;
}

template<int len> bool operator<=(const vuint<len> &lhs, const uint16_t &rhs)
{
	return !(lhs > rhs);
}

template<int len> bool operator>(const vuint<len> &lhs, const uint16_t &rhs)
{
	return rhs < lhs;
}

template<int len> bool operator>= (const vuint<len> &lhs, const uint16_t &rhs)
{
	return !(lhs < rhs);
}

template<int len> bool operator==(const uint16_t &lhs, const vuint<len> &rhs)
{
	return (vuint<16>)lhs == rhs;
}

template<int len> bool operator!=(const uint16_t &lhs, const vuint<len> &rhs)
{
	return !(lhs == rhs);
}

template<int len> bool operator<(const uint16_t &lhs, const vuint<len> &rhs)
{
	return (vuint<16>)lhs < rhs;
}

template<int len> bool operator<=(const uint16_t &lhs, const vuint<len> &rhs)
{
	return !(lhs > rhs);
}

template<int len> bool operator>(const uint16_t &lhs, const vuint<len> &rhs)
{
	return rhs < lhs;
}

template<int len> bool operator>=(const uint16_t &lhs, const vuint<len> &rhs)
{
	return !(lhs < rhs);
}

template<int len> bool operator==(const vuint<len> &lhs, const uint32_t &rhs)
{
	return lhs == (vuint<32>)rhs;
}

template<int len> bool operator!=(const vuint<len> &lhs, const uint32_t &rhs)
{
	return !(lhs == rhs);
}

template<int len> bool operator<(const vuint<len> &lhs, const uint32_t &rhs)
{
	return lhs < (vuint<32>)rhs;
}

template<int len> bool operator<=(const vuint<len> &lhs, const uint32_t &rhs)
{
	return !(lhs > rhs);
}

template<int len> bool operator>(const vuint<len> &lhs, const uint32_t &rhs)
{
	return rhs < lhs;
}

template<int len> bool operator>= (const vuint<len> &lhs, const uint32_t &rhs)
{
	return !(lhs < rhs);
}

template<int len> bool operator==(const uint32_t &lhs, const vuint<len> &rhs)
{
	return (vuint<32>)lhs == rhs;
}

template<int len> bool operator!=(const uint32_t &lhs, const vuint<len> &rhs)
{
	return !(lhs == rhs);
}

template<int len> bool operator<(const uint32_t &lhs, const vuint<len> &rhs)
{
	return (vuint<32>)lhs < rhs;
}

template<int len> bool operator<=(const uint32_t &lhs, const vuint<len> &rhs)
{
	return !(lhs > rhs);
}

template<int len> bool operator>(const uint32_t &lhs, const vuint<len> &rhs)
{
	return rhs < lhs;
}

template<int len> bool operator>=(const uint32_t &lhs, const vuint<len> &rhs)
{
	return !(lhs < rhs);
}

template<int len> bool operator==(const vuint<len> &lhs, const uint64_t &rhs)
{
	return lhs == (vuint<64>)rhs;
}

template<int len> bool operator!=(const vuint<len> &lhs, const uint64_t &rhs)
{
	return !(lhs == rhs);
}

template<int len> bool operator<(const vuint<len> &lhs, const uint64_t &rhs)
{
	return lhs < (vuint<64>)rhs;
}

template<int len> bool operator<=(const vuint<len> &lhs, const uint64_t &rhs)
{
	return !(lhs > rhs);
}

template<int len> bool operator>(const vuint<len> &lhs, const uint64_t &rhs)
{
	return rhs < lhs;
}

template<int len> bool operator>= (const vuint<len> &lhs, const uint64_t &rhs)
{
	return !(lhs < rhs);
}

template<int len> bool operator==(const uint64_t &lhs, const vuint<len> &rhs)
{
	return (vuint<64>)lhs == rhs;
}

template<int len> bool operator!=(const uint64_t &lhs, const vuint<len> &rhs)
{
	return !(lhs == rhs);
}

template<int len> bool operator<(const uint64_t &lhs, const vuint<len> &rhs)
{
	return (vuint<64>)lhs < rhs;
}

template<int len> bool operator<=(const uint64_t &lhs, const vuint<len> &rhs)
{
	return !(lhs > rhs);
}

template<int len> bool operator>(const uint64_t &lhs, const vuint<len> &rhs)
{
	return rhs < lhs;
}

template<int len> bool operator>=(const uint64_t &lhs, const vuint<len> &rhs)
{
	return !(lhs < rhs);
}

template<int len> bool operator==(const vuint<len> &lhs, const int8_t &rhs)
{
	if (rhs < 0) return false;
	return lhs == (vuint<8>)rhs;
}

template<int len> bool operator!=(const vuint<len> &lhs, const int8_t &rhs)
{
	return !(lhs == rhs);
}

template<int len> bool operator<(const vuint<len> &lhs, const int8_t &rhs)
{
	if (rhs < 0) return false;
	return lhs < (vuint<8>)rhs;
}

template<int len> bool operator<=(const vuint<len> &lhs, const int8_t &rhs)
{
	return !(lhs > rhs);
}

template<int len> bool operator>(const vuint<len> &lhs, const int8_t &rhs)
{
	return rhs < lhs;
}

template<int len> bool operator>= (const vuint<len> &lhs, const int8_t &rhs)
{
	return !(lhs < rhs);
}

template<int len> bool operator==(const int8_t &lhs, const vuint<len> &rhs)
{
	if (lhs < 0) return false;
	return (vuint<8>)lhs == rhs;
}

template<int len> bool operator!=(const int8_t &lhs, const vuint<len> &rhs)
{
	return !(lhs == rhs);
}

template<int len> bool operator<(const int8_t &lhs, const vuint<len> &rhs)
{
	if (lhs < 0) return true;
	return (vuint<8>)lhs < rhs;
}

template<int len> bool operator<=(const int8_t &lhs, const vuint<len> &rhs)
{
	return !(lhs > rhs);
}

template<int len> bool operator>(const int8_t &lhs, const vuint<len> &rhs)
{
	return rhs < lhs;
}

template<int len> bool operator>=(const int8_t &lhs, const vuint<len> &rhs)
{
	return !(lhs < rhs);
}

template<int len> bool operator==(const vuint<len> &lhs, const int16_t &rhs)
{
	if (rhs < 0) return false;
	return lhs == (vuint<16>)rhs;
}

template<int len> bool operator!=(const vuint<len> &lhs, const int16_t &rhs)
{
	return !(lhs == rhs);
}

template<int len> bool operator<(const vuint<len> &lhs, const int16_t &rhs)
{
	if (rhs < 0) return false;
	return lhs < (vuint<16>)rhs;
}

template<int len> bool operator<=(const vuint<len> &lhs, const int16_t &rhs)
{
	return !(lhs > rhs);
}

template<int len> bool operator>(const vuint<len> &lhs, const int16_t &rhs)
{
	return rhs < lhs;
}

template<int len> bool operator>= (const vuint<len> &lhs, const int16_t &rhs)
{
	return !(lhs < rhs);
}

template<int len> bool operator==(const int16_t &lhs, const vuint<len> &rhs)
{
	if (lhs < 0) return false;
	return (vuint<16>)lhs == rhs;
}

template<int len> bool operator!=(const int16_t &lhs, const vuint<len> &rhs)
{
	return !(lhs == rhs);
}

template<int len> bool operator<(const int16_t &lhs, const vuint<len> &rhs)
{
	if (lhs < 0) return true;
	return (vuint<16>)lhs < rhs;
}

template<int len> bool operator<=(const int16_t &lhs, const vuint<len> &rhs)
{
	return !(lhs > rhs);
}

template<int len> bool operator>(const int16_t &lhs, const vuint<len> &rhs)
{
	return rhs < lhs;
}

template<int len> bool operator>=(const int16_t &lhs, const vuint<len> &rhs)
{
	return !(lhs < rhs);
}

template<int len> bool operator==(const vuint<len> &lhs, const int32_t &rhs)
{
	if (rhs < 0) return false;
	return lhs == (vuint<32>)rhs;
}

template<int len> bool operator!=(const vuint<len> &lhs, const int32_t &rhs)
{
	return !(lhs == rhs);
}

template<int len> bool operator<(const vuint<len> &lhs, const int32_t &rhs)
{
	if (rhs < 0) return false;
	return lhs < (vuint<32>)rhs;
}

template<int len> bool operator<=(const vuint<len> &lhs, const int32_t &rhs)
{
	return !(lhs > rhs);
}

template<int len> bool operator>(const vuint<len> &lhs, const int32_t &rhs)
{
	return rhs < lhs;
}

template<int len> bool operator>= (const vuint<len> &lhs, const int32_t &rhs)
{
	return !(lhs < rhs);
}

template<int len> bool operator==(const int32_t &lhs, const vuint<len> &rhs)
{
	if (lhs < 0) return false;
	return (vuint<32>)lhs == rhs;
}

template<int len> bool operator!=(const int32_t &lhs, const vuint<len> &rhs)
{
	return !(lhs == rhs);
}

template<int len> bool operator<(const int32_t &lhs, const vuint<len> &rhs)
{
	if (lhs < 0) return true;
	return (vuint<32>)lhs < rhs;
}

template<int len> bool operator<=(const int32_t &lhs, const vuint<len> &rhs)
{
	return !(lhs > rhs);
}

template<int len> bool operator>(const int32_t &lhs, const vuint<len> &rhs)
{
	return rhs < lhs;
}

template<int len> bool operator>=(const int32_t &lhs, const vuint<len> &rhs)
{
	return !(lhs < rhs);
}

template<int len> bool operator==(const vuint<len> &lhs, const int64_t &rhs)
{
	if (rhs < 0) return false;
	return lhs == (vuint<64>)rhs;
}

template<int len> bool operator!=(const vuint<len> &lhs, const int64_t &rhs)
{
	return !(lhs == rhs);
}


template<int len> bool operator<(const vuint<len> &lhs, const int64_t &rhs)
{
	if (rhs < 0) return false;
	return lhs < (vuint<64>)rhs;
}

template<int len> bool operator<=(const vuint<len> &lhs, const int64_t &rhs)
{
	return !(lhs > rhs);
}

template<int len> bool operator>(const vuint<len> &lhs, const int64_t &rhs)
{
	return rhs < lhs;
}

template<int len> bool operator>= (const vuint<len> &lhs, const int64_t &rhs)
{
	return !(lhs < rhs);
}

template<int len> bool operator==(const int64_t &lhs, const vuint<len> &rhs)
{
	if (lhs < 0) return false;
	return (vuint<64>)lhs == rhs;
}

template<int len> bool operator!=(const int64_t &lhs, const vuint<len> &rhs)
{
	return !(lhs == rhs);
}

template<int len> bool operator<(const int64_t &lhs, const vuint<len> &rhs)
{
	if (lhs < 0) return true;
	return (vuint<64>)lhs < rhs;
}

template<int len> bool operator<=(const int64_t &lhs, const vuint<len> &rhs)
{
	return !(lhs > rhs);
}

template<int len> bool operator>(const int64_t &lhs, const vuint<len> &rhs)
{
	return rhs < lhs;
}

template<int len> bool operator>=(const int64_t &lhs, const vuint<len> &rhs)
{
	return !(lhs < rhs);
}

template<int len> vuint<len> operator+(vuint<len> lhs, const uint8_t & rhs)
{
	lhs += rhs;
	return lhs;
}
template<int len> vuint<len> operator+(vuint<len> lhs, const uint16_t & rhs)
{
	lhs += rhs;
	return lhs;
}
template<int len> vuint<len> operator+(vuint<len> lhs, const uint32_t & rhs)
{
	lhs += rhs;
	return lhs;
}
template<int len> vuint<len> operator+(vuint<len> lhs, const uint64_t & rhs)
{
	lhs += rhs;
	return lhs;
}

template<int len> vuint<len> operator+(vuint<len> lhs, const int8_t & rhs)
{
	lhs += rhs;
	return lhs;
}
template<int len> vuint<len> operator+(vuint<len> lhs, const int16_t & rhs)
{
	lhs += rhs;
	return lhs;
}
template<int len> vuint<len> operator+(vuint<len> lhs, const int32_t & rhs)
{
	lhs += rhs;
	return lhs;
}
template<int len> vuint<len> operator+(vuint<len> lhs, const int64_t & rhs)
{
	lhs += rhs;
	return lhs;
}
template<int len> vuint<8> operator+(const uint8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret += rhs;
	return ret;
}
template<int len> vuint<16> operator+(const uint16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret += rhs;
	return ret;
}
template<int len> vuint<32> operator+(const uint32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret += rhs;
	return ret;
}
template<int len> vuint<64> operator+(const uint64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret += rhs;
	return ret;
}
template<int len> vuint<8> operator+(const int8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret += rhs;
	return ret;
}
template<int len> vuint<16> operator+(const int16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret += rhs;
	return ret;
}
template<int len> vuint<32> operator+(const int32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret += rhs;
	return ret;
}
template<int len> vuint<64> operator+(const int64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret += rhs;
	return ret;
}
template<int len, int len2> vuint<len> operator+(vuint<len> lhs, const vuint<len2> & rhs)
{
	lhs += rhs;
	return lhs;
}

template<int len> vuint<len> operator-(vuint<len> lhs, const uint8_t & rhs)
{
	lhs -= rhs;
	return lhs;
}
template<int len> vuint<len> operator-(vuint<len> lhs, const uint16_t & rhs)
{
	lhs -= rhs;
	return lhs;
}
template<int len> vuint<len> operator-(vuint<len> lhs, const uint32_t & rhs)
{
	lhs -= rhs;
	return lhs;
}
template<int len> vuint<len> operator-(vuint<len> lhs, const uint64_t & rhs)
{
	lhs -= rhs;
	return lhs;
}

template<int len> vuint<len> operator-(vuint<len> lhs, const int8_t & rhs)
{
	lhs -= rhs;
	return lhs;
}
template<int len> vuint<len> operator-(vuint<len> lhs, const int16_t & rhs)
{
	lhs -= rhs;
	return lhs;
}
template<int len> vuint<len> operator-(vuint<len> lhs, const int32_t & rhs)
{
	lhs -= rhs;
	return lhs;
}
template<int len> vuint<len> operator-(vuint<len> lhs, const int64_t & rhs)
{
	lhs -= rhs;
	return lhs;
}
template<int len> vuint<8> operator-(const uint8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret -= rhs;
	return ret;
}
template<int len> vuint<16> operator-(const uint16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret -= rhs;
	return ret;
}
template<int len> vuint<32> operator-(const uint32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret -= rhs;
	return ret;
}
template<int len> vuint<64> operator-(const uint64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret -= rhs;
	return ret;
}
template<int len> vuint<8> operator-(const int8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret -= rhs;
	return ret;
}
template<int len> vuint<16> operator-(const int16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret -= rhs;
	return ret;
}
template<int len> vuint<32> operator-(const int32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret -= rhs;
	return ret;
}
template<int len> vuint<64> operator-(const int64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret -= rhs;
	return ret;
}
template<int len, int len2> vuint<len> operator-(vuint<len> lhs, const vuint<len2> & rhs)
{
	lhs -= rhs;
	return lhs;
}


template<int len> vuint<len> operator*(vuint<len> lhs, const uint8_t & rhs)
{
	lhs *= rhs;
	return lhs;
}
template<int len> vuint<len> operator*(vuint<len> lhs, const uint16_t & rhs)
{
	lhs *= rhs;
	return lhs;
}
template<int len> vuint<len> operator*(vuint<len> lhs, const uint32_t & rhs)
{
	lhs *= rhs;
	return lhs;
}
template<int len> vuint<len> operator*(vuint<len> lhs, const uint64_t & rhs)
{
	lhs *= rhs;
	return lhs;
}

template<int len> vuint<len> operator*(vuint<len> lhs, const int8_t & rhs)
{
	lhs *= rhs;
	return lhs;
}
template<int len> vuint<len> operator*(vuint<len> lhs, const int16_t & rhs)
{
	lhs *= rhs;
	return lhs;
}
template<int len> vuint<len> operator*(vuint<len> lhs, const int32_t & rhs)
{
	lhs *= rhs;
	return lhs;
}
template<int len> vuint<len> operator*(vuint<len> lhs, const int64_t & rhs)
{
	lhs *= rhs;
	return lhs;
}
template<int len> vuint<8> operator*(const uint8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret *= rhs;
	return ret;
}
template<int len> vuint<16> operator*(const uint16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret *= rhs;
	return ret;
}
template<int len> vuint<32> operator*(const uint32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret *= rhs;
	return ret;
}
template<int len> vuint<64> operator*(const uint64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret *= rhs;
	return ret;
}
template<int len> vuint<8> operator*(const int8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret *= rhs;
	return ret;
}
template<int len> vuint<16> operator*(const int16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret *= rhs;
	return ret;
}
template<int len> vuint<32> operator*(const int32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret *= rhs;
	return ret;
}
template<int len> vuint<64> operator*(const int64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret *= rhs;
	return ret;
}
template<int len, int len2> vuint<len> operator*(vuint<len> lhs, const vuint<len2> & rhs)
{
	lhs *= rhs;
	return lhs;
}
template<int len> vuint<len> operator/(vuint<len> lhs, const uint8_t & rhs)
{
	lhs /= rhs;
	return lhs;
}
template<int len> vuint<len> operator/(vuint<len> lhs, const uint16_t & rhs)
{
	lhs /= rhs;
	return lhs;
}
template<int len> vuint<len> operator/(vuint<len> lhs, const uint32_t & rhs)
{
	lhs /= rhs;
	return lhs;
}
template<int len> vuint<len> operator/(vuint<len> lhs, const uint64_t & rhs)
{
	lhs /= rhs;
	return lhs;
}

template<int len> vuint<len> operator/(vuint<len> lhs, const int8_t & rhs)
{
	lhs /= rhs;
	return lhs;
}
template<int len> vuint<len> operator/(vuint<len> lhs, const int16_t & rhs)
{
	lhs /= rhs;
	return lhs;
}
template<int len> vuint<len> operator/(vuint<len> lhs, const int32_t & rhs)
{
	lhs /= rhs;
	return lhs;
}
template<int len> vuint<len> operator/(vuint<len> lhs, const int64_t & rhs)
{
	lhs /= rhs;
	return lhs;
}
template<int len> vuint<8> operator/(const uint8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret /= rhs;
	return ret;
}
template<int len> vuint<16> operator/(const uint16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret /= rhs;
	return ret;
}
template<int len> vuint<32> operator/(const uint32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret /= rhs;
	return ret;
}
template<int len> vuint<64> operator/(const uint64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret /= rhs;
	return ret;
}
template<int len> vuint<8> operator/(const int8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret /= rhs;
	return ret;
}
template<int len> vuint<16> operator/(const int16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret /= rhs;
	return ret;
}
template<int len> vuint<32> operator/(const int32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret /= rhs;
	return ret;
}
template<int len> vuint<64> operator/(const int64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret /= rhs;
	return ret;
}
template<int len, int len2> vuint<len> operator/(vuint<len> lhs, const vuint<len2> & rhs)
{
	lhs /= rhs;
	return lhs;
}
template<int len> vuint<len> operator%(vuint<len> lhs, const uint8_t & rhs)
{
	lhs %= rhs;
	return lhs;
}
template<int len> vuint<len> operator%(vuint<len> lhs, const uint16_t & rhs)
{
	lhs %= rhs;
	return lhs;
}
template<int len> vuint<len> operator%(vuint<len> lhs, const uint32_t & rhs)
{
	lhs %= rhs;
	return lhs;
}
template<int len> vuint<len> operator%(vuint<len> lhs, const uint64_t & rhs)
{
	lhs %= rhs;
	return lhs;
}

template<int len> vuint<len> operator%(vuint<len> lhs, const int8_t & rhs)
{
	lhs %= rhs;
	return lhs;
}
template<int len> vuint<len> operator%(vuint<len> lhs, const int16_t & rhs)
{
	lhs %= rhs;
	return lhs;
}
template<int len> vuint<len> operator%(vuint<len> lhs, const int32_t & rhs)
{
	lhs %= rhs;
	return lhs;
}
template<int len> vuint<len> operator%(vuint<len> lhs, const int64_t & rhs)
{
	lhs %= rhs;
	return lhs;
}
template<int len> vuint<8> operator%(const uint8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret %= rhs;
	return ret;
}
template<int len> vuint<16> operator%(const uint16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret %= rhs;
	return ret;
}
template<int len> vuint<32> operator%(const uint32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret %= rhs;
	return ret;
}
template<int len> vuint<64> operator%(const uint64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret %= rhs;
	return ret;
}
template<int len> vuint<8> operator%(const int8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret %= rhs;
	return ret;
}
template<int len> vuint<16> operator%(const int16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret %= rhs;
	return ret;
}
template<int len> vuint<32> operator%(const int32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret %= rhs;
	return ret;
}
template<int len> vuint<64> operator%(const int64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret %= rhs;
	return ret;
}
template<int len, int len2> vuint<len> operator%(vuint<len> lhs, const vuint<len2> & rhs)
{
	lhs %= rhs;
	return lhs;
}
template<int len> vuint<len> operator^(vuint<len> lhs, const uint8_t & rhs)
{
	lhs ^= rhs;
	return lhs;
}
template<int len> vuint<len> operator^(vuint<len> lhs, const uint16_t & rhs)
{
	lhs ^= rhs;
	return lhs;
}
template<int len> vuint<len> operator^(vuint<len> lhs, const uint32_t & rhs)
{
	lhs ^= rhs;
	return lhs;
}
template<int len> vuint<len> operator^(vuint<len> lhs, const uint64_t & rhs)
{
	lhs ^= rhs;
	return lhs;
}

template<int len> vuint<len> operator^(vuint<len> lhs, const int8_t & rhs)
{
	lhs ^= rhs;
	return lhs;
}
template<int len> vuint<len> operator^(vuint<len> lhs, const int16_t & rhs)
{
	lhs ^= rhs;
	return lhs;
}
template<int len> vuint<len> operator^(vuint<len> lhs, const int32_t & rhs)
{
	lhs ^= rhs;
	return lhs;
}
template<int len> vuint<len> operator^(vuint<len> lhs, const int64_t & rhs)
{
	lhs ^= rhs;
	return lhs;
}
template<int len> vuint<8> operator^(const uint8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret ^= rhs;
	return ret;
}
template<int len> vuint<16> operator^(const uint16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret ^= rhs;
	return ret;
}
template<int len> vuint<32> operator^(const uint32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret ^= rhs;
	return ret;
}
template<int len> vuint<64> operator^(const uint64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret ^= rhs;
	return ret;
}
template<int len> vuint<8> operator^(const int8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret ^= rhs;
	return ret;
}
template<int len> vuint<16> operator^(const int16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret ^= rhs;
	return ret;
}
template<int len> vuint<32> operator^(const int32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret ^= rhs;
	return ret;
}
template<int len> vuint<64> operator^(const int64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret ^= rhs;
	return ret;
}
template<int len, int len2> vuint<len> operator^(vuint<len> lhs, const vuint<len2> & rhs)
{
	lhs ^= rhs;
	return lhs;
}


template<int len> vuint<len> operator|(vuint<len> lhs, const uint8_t & rhs)
{
	lhs |= rhs;
	return lhs;
}
template<int len> vuint<len> operator|(vuint<len> lhs, const uint16_t & rhs)
{
	lhs |= rhs;
	return lhs;
}
template<int len> vuint<len> operator|(vuint<len> lhs, const uint32_t & rhs)
{
	lhs |= rhs;
	return lhs;
}
template<int len> vuint<len> operator|(vuint<len> lhs, const uint64_t & rhs)
{
	lhs |= rhs;
	return lhs;
}

template<int len> vuint<len> operator|(vuint<len> lhs, const int8_t & rhs)
{
	lhs |= rhs;
	return lhs;
}
template<int len> vuint<len> operator|(vuint<len> lhs, const int16_t & rhs)
{
	lhs |= rhs;
	return lhs;
}
template<int len> vuint<len> operator|(vuint<len> lhs, const int32_t & rhs)
{
	lhs |= rhs;
	return lhs;
}
template<int len> vuint<len> operator|(vuint<len> lhs, const int64_t & rhs)
{
	lhs |= rhs;
	return lhs;
}
template<int len> vuint<8> operator|(const uint8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret |= rhs;
	return ret;
}
template<int len> vuint<16> operator|(const uint16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret |= rhs;
	return ret;
}
template<int len> vuint<32> operator|(const uint32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret |= rhs;
	return ret;
}
template<int len> vuint<64> operator|(const uint64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret |= rhs;
	return ret;
}
template<int len> vuint<8> operator|(const int8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret |= rhs;
	return ret;
}
template<int len> vuint<16> operator|(const int16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret |= rhs;
	return ret;
}
template<int len> vuint<32> operator|(const int32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret |= rhs;
	return ret;
}
template<int len> vuint<64> operator|(const int64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret |= rhs;
	return ret;
}
template<int len, int len2> vuint<len> operator|(vuint<len> lhs, const vuint<len2> & rhs)
{
	lhs |= rhs;
	return lhs;
}

template<int len> vuint<len> operator&(vuint<len> lhs, const uint8_t & rhs)
{
	lhs &= rhs;
	return lhs;
}
template<int len> vuint<len> operator&(vuint<len> lhs, const uint16_t & rhs)
{
	lhs &= rhs;
	return lhs;
}
template<int len> vuint<len> operator&(vuint<len> lhs, const uint32_t & rhs)
{
	lhs &= rhs;
	return lhs;
}
template<int len> vuint<len> operator&(vuint<len> lhs, const uint64_t & rhs)
{
	lhs &= rhs;
	return lhs;
}

template<int len> vuint<len> operator&(vuint<len> lhs, const int8_t & rhs)
{
	lhs &= rhs;
	return lhs;
}
template<int len> vuint<len> operator&(vuint<len> lhs, const int16_t & rhs)
{
	lhs &= rhs;
	return lhs;
}
template<int len> vuint<len> operator&(vuint<len> lhs, const int32_t & rhs)
{
	lhs &= rhs;
	return lhs;
}
template<int len> vuint<len> operator&(vuint<len> lhs, const int64_t & rhs)
{
	lhs &= rhs;
	return lhs;
}
template<int len> vuint<8> operator&(const uint8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret &= rhs;
	return ret;
}
template<int len> vuint<16> operator&(const uint16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret &= rhs;
	return ret;
}
template<int len> vuint<32> operator&(const uint32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret &= rhs;
	return ret;
}
template<int len> vuint<64> operator&(const uint64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret &= rhs;
	return ret;
}
template<int len> vuint<8> operator&(const int8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret &= rhs;
	return ret;
}
template<int len> vuint<16> operator&(const int16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret &= rhs;
	return ret;
}
template<int len> vuint<32> operator&(const int32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret &= rhs;
	return ret;
}
template<int len> vuint<64> operator&(const int64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret &= rhs;
	return ret;
}
template<int len, int len2> vuint<len> operator&(vuint<len> lhs, const vuint<len2> & rhs)
{
	lhs &= rhs;
	return lhs;
}
template<int len> vuint<len> operator>>(vuint<len> lhs, const uint8_t & rhs)
{
	lhs >>= rhs;
	return lhs;
}
template<int len> vuint<len> operator>>(vuint<len> lhs, const uint16_t & rhs)
{
	lhs >>= rhs;
	return lhs;
}
template<int len> vuint<len> operator>>(vuint<len> lhs, const uint32_t & rhs)
{
	lhs >>= rhs;
	return lhs;
}
template<int len> vuint<len> operator>>(vuint<len> lhs, const uint64_t & rhs)
{
	lhs >>= rhs;
	return lhs;
}

template<int len> vuint<len> operator>>(vuint<len> lhs, const int8_t & rhs)
{
	lhs >>= rhs;
	return lhs;
}
template<int len> vuint<len> operator>>(vuint<len> lhs, const int16_t & rhs)
{
	lhs >>= rhs;
	return lhs;
}
template<int len> vuint<len> operator>>(vuint<len> lhs, const int32_t & rhs)
{
	lhs >>= rhs;
	return lhs;
}
template<int len> vuint<len> operator>>(vuint<len> lhs, const int64_t & rhs)
{
	lhs >>= rhs;
	return lhs;
}
template<int len> vuint<8> operator>>(const uint8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret >>= rhs;
	return ret;
}
template<int len> vuint<16> operator>>(const uint16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret >>= rhs;
	return ret;
}
template<int len> vuint<32> operator>>(const uint32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret >>= rhs;
	return ret;
}
template<int len> vuint<64> operator>>(const uint64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret >>= rhs;
	return ret;
}
template<int len> vuint<8> operator>>(const int8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret >>= rhs;
	return ret;
}
template<int len> vuint<16> operator>>(const int16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret >>= rhs;
	return ret;
}
template<int len> vuint<32> operator>>(const int32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret >>= rhs;
	return ret;
}
template<int len> vuint<64> operator>>(const int64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret >>= rhs;
	return ret;
}
template<int len, int len2> vuint<len> operator>>(vuint<len> lhs, const vuint<len2> & rhs)
{
	lhs >>= rhs;
	return lhs;
}
template<int len> vuint<len> operator<<(vuint<len> lhs, const uint8_t & rhs)
{
	lhs <<= rhs;
	return lhs;
}
template<int len> vuint<len> operator<<(vuint<len> lhs, const uint16_t & rhs)
{
	lhs <<= rhs;
	return lhs;
}
template<int len> vuint<len> operator<<(vuint<len> lhs, const uint32_t & rhs)
{
	lhs <<= rhs;
	return lhs;
}
template<int len> vuint<len> operator<<(vuint<len> lhs, const uint64_t & rhs)
{
	lhs <<= rhs;
	return lhs;
}

template<int len> vuint<len> operator<<(vuint<len> lhs, const int8_t & rhs)
{
	lhs <<= rhs;
	return lhs;
}
template<int len> vuint<len> operator<<(vuint<len> lhs, const int16_t & rhs)
{
	lhs <<= rhs;
	return lhs;
}
template<int len> vuint<len> operator<<(vuint<len> lhs, const int32_t & rhs)
{
	lhs <<= rhs;
	return lhs;
}
template<int len> vuint<len> operator<<(vuint<len> lhs, const int64_t & rhs)
{
	lhs <<= rhs;
	return lhs;
}
template<int len> vuint<8> operator<<(const uint8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret <<= rhs;
	return ret;
}
template<int len> vuint<16> operator<<(const uint16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret <<= rhs;
	return ret;
}
template<int len> vuint<32> operator<<(const uint32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret <<= rhs;
	return ret;
}
template<int len> vuint<64> operator<<(const uint64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret <<= rhs;
	return ret;
}
template<int len> vuint<8> operator<<(const int8_t & lhs, vuint<len> rhs)
{
	vuint<8> ret = lhs;
	ret <<= rhs;
	return ret;
}
template<int len> vuint<16> operator<<(const int16_t & lhs, vuint<len> rhs)
{
	vuint<16> ret = lhs;
	ret <<= rhs;
	return ret;
}
template<int len> vuint<32> operator<<(const int32_t & lhs, vuint<len> rhs)
{
	vuint<32> ret = lhs;
	ret <<= rhs;
	return ret;
}
template<int len> vuint<64> operator<<(const int64_t & lhs, vuint<len> rhs)
{
	vuint<64> ret = lhs;
	ret <<= rhs;
	return ret;
}
template<int len, int len2> vuint<len> operator<<(vuint<len> lhs, const vuint<len2> & rhs)
{
	lhs <<= rhs;
	return lhs;
}

template<int len> std::ostream& operator<<(std::ostream &os, const vuint<len> &obj)
{
	uint8_t buffer[len * 2];

	vuint<len> data = obj;
	int_fast32_t iter = 0;

	int_fast32_t base = 10;
	if ((os.flags() & std::ios_base::basefield) == std::ios_base::oct) base = 8;
	if ((os.flags() & std::ios_base::basefield) == std::ios_base::hex) base = 16;

	uint8_t firstHex = 'a';
	if ((os.flags() & std::ios_base::uppercase) == std::ios_base::uppercase)
		firstHex = 'A';

	while (data > 0)
	{
		uint8_t c = (data % base);
		if (c < 10)
			buffer[iter++] = '0' + c;
		else
			buffer[iter++] = firstHex + c - 10;
		data /= base;
	}

	int_fast32_t length = iter;

	if (length == 0) length = 1;

	if (base == 10 && (os.flags() & std::ios_base::showpos) == std::ios_base::showpos)
		length++;
	if (obj != 0 && (os.flags() & std::ios_base::showbase) == std::ios_base::showbase)
	{
		if (base == 8) length++;
		else if (base == 16) length += 2;
	}

	if ((os.flags() & std::ios_base::adjustfield) == std::ios_base::right)
	{
		for (int_fast32_t i = length; i < os.width(); i++)
			os.put(os.fill());
	}


	if (base == 10 && (os.flags() & std::ios_base::showpos) == std::ios_base::showpos)
		os.put('+');

	if (obj != 0 && (os.flags() & std::ios_base::showbase) == std::ios_base::showbase)
	{
		if (base == 16) { os.put('0'); os.put('x'); }
	}

	if ((os.flags() & std::ios_base::adjustfield) == std::ios_base::internal)
	{
		for (int_fast32_t i = length; i < os.width(); i++)
			os.put(os.fill());
	}

	if (obj != 0 && (os.flags() & std::ios_base::showbase) == std::ios_base::showbase)
	{
		if (base == 8) os.put('0');
	}

	if (iter == 0)
		os.put('0');

	while (iter > 0)
	{
		os.put(buffer[--iter]);
	}

	if ((os.flags() & std::ios_base::adjustfield) == std::ios_base::left)
	{
		for (int_fast32_t i = length; i < os.width(); i++)
			os.put(os.fill());
	}

	if ((os.flags() & std::ios_base::unitbuf) == std::ios_base::unitbuf)
		os.flush();

	return os;
}

template<int len> std::istream& operator>>(std::istream &is, vuint<len> &obj)
{
	uint8_t buffer[len * 2 + 2 + 1];

	is.getline((char*)buffer, sizeof(buffer));

	int_fast32_t iter = 0;
	int_fast32_t base = 10;

	if ((is.flags() & std::ios_base::basefield) == std::ios_base::oct) base = 8;
	if ((is.flags() & std::ios_base::basefield) == std::ios_base::hex) base = 16;

	obj = 0;
	bool start = true;

	while (buffer[iter])
	{
		if (buffer[iter] >= '0' && buffer[iter] <= '9')
		{
			obj *= base;
			obj += buffer[iter] - '0';

			if (buffer[iter] != '0')
				start = false;
		}
		else if (base == 16)
		{
			uint8_t c = tolower(buffer[iter]);
			if (c >= 'a' && c <= 'f')
			{
				obj *= base;
				obj += c - 'a';
				start = false;
			}
			else if (!start || c != 'x')
				break;
		}
		else
			break;
		iter++;
	}

	return is;
}

// Following is direct implementation of
// http://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Binary_numeral_system_.28base_2.29
//
template<int len> vuint<len> sqrt(vuint<len> value)
{
	vuint<len> ret;
	vuint<len> bit;

	bit.setbit(len - 2, true);
	while (bit > value)
		bit >>= 2;

	while (bit != 0)
	{
		if (value >= ret + bit)
		{
			value -= ret + bit;
			ret = (ret >> 1) + bit;
		}
		else
			ret >>= 1;
		bit >>= 2;
	}
	return ret;
}

typedef vuint<8> uint8;
typedef vuint<16> uint16;
typedef vuint<24> uint24;
typedef vuint<32> uint32;
typedef vuint<64> uint64;
typedef vuint<128> uint128;
typedef vuint<256> uint256;

#endif
