/// USING Google Test framework

#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include "vuint.hpp"

TEST(Comparision, UnsignedForEquality)
{
	EXPECT_EQ(0u, uint8(0u)); EXPECT_LE(0u, uint8(0u)); EXPECT_GE(0u, uint8(0u));
	EXPECT_EQ(32u, uint8(32u)); EXPECT_LE(32u, uint8(32u)); EXPECT_GE(32u, uint8(32u));

	EXPECT_EQ(0u, uint16(0u)); EXPECT_LE(0u, uint16(0u)); EXPECT_GE(0u, uint16(0u));
	EXPECT_EQ(32u, uint16(32u)); EXPECT_LE(32u, uint16(32u)); EXPECT_GE(32u, uint16(32u));
	EXPECT_EQ(1024u, uint16(1024u)); EXPECT_LE(1024u, uint16(1024u)); EXPECT_GE(1024u, uint16(1024u));

	EXPECT_EQ(0u, uint24(0u)); EXPECT_LE(0u, uint24(0u)); EXPECT_GE(0u, uint24(0u));
	EXPECT_EQ(32u, uint24(32u)); EXPECT_LE(32u, uint24(32u)); EXPECT_GE(32u, uint24(32u));
	EXPECT_EQ(1024u, uint24(1024u)); EXPECT_LE(1024u, uint24(1024u)); EXPECT_GE(1024u, uint24(1024u));
	EXPECT_EQ(100000u, uint24(100000u)); EXPECT_LE(100000u, uint24(100000u)); EXPECT_GE(100000u, uint24(100000u));

	EXPECT_EQ(0u, uint32(0u)); EXPECT_LE(0u, uint32(0u)); EXPECT_GE(0u, uint32(0u));
	EXPECT_EQ(32u, uint32(32u)); EXPECT_LE(32u, uint32(32u)); EXPECT_GE(32u, uint32(32u));
	EXPECT_EQ(1024u, uint32(1024u)); EXPECT_LE(1024u, uint32(1024u)); EXPECT_GE(1024u, uint32(1024u));
	EXPECT_EQ(100000u, uint32(100000u)); EXPECT_LE(100000u, uint32(100000u)); EXPECT_GE(100000u, uint32(100000u));
	EXPECT_EQ(2000000000u, uint32(2000000000u)); EXPECT_LE(2000000000u, uint32(2000000000u)); EXPECT_GE(2000000000u, uint32(2000000000u));

	EXPECT_EQ(0u, uint64(0u)); EXPECT_LE(0u, uint64(0u)); EXPECT_GE(0u, uint64(0u));
	EXPECT_EQ(32u, uint64(32u)); EXPECT_LE(32u, uint64(32u)); EXPECT_GE(32u, uint64(32u));
	EXPECT_EQ(1024u, uint64(1024u)); EXPECT_LE(1024u, uint64(1024u)); EXPECT_GE(1024u, uint64(1024u));
	EXPECT_EQ(100000u, uint64(100000u)); EXPECT_LE(100000u, uint64(100000u)); EXPECT_GE(100000u, uint64(100000u));
	EXPECT_EQ(2000000000u, uint64(2000000000u)); EXPECT_LE(2000000000u, uint64(2000000000u)); EXPECT_GE(2000000000u, uint64(2000000000u));
	EXPECT_EQ(2000000000000ull, uint64(2000000000000ull)); EXPECT_LE(2000000000000ull, uint64(2000000000000ull)); EXPECT_GE(2000000000000ull, uint64(2000000000000ull));
}

TEST(Comparision, UnsignedForInEquality)
{
	EXPECT_NE(1u, uint8(0u));
	EXPECT_NE(0u, uint8(1u));
	EXPECT_NE(1u, uint8(2u));
	EXPECT_NE(512u, uint8(0u));
	EXPECT_NE(512u, uint8(16u));

	EXPECT_NE(1u, uint16(0u));
	EXPECT_NE(0u, uint16(1u));
	EXPECT_NE(1u, uint16(2u));
	EXPECT_NE(512u, uint16(0u));
	EXPECT_NE(512u, uint16(16u));
	EXPECT_NE(100000u, uint16(1024u));

	EXPECT_NE(1u, uint24(0u));
	EXPECT_NE(0u, uint24(1u));
	EXPECT_NE(1u, uint24(2u));
	EXPECT_NE(512u, uint24(0u));
	EXPECT_NE(512u, uint24(16u));
	EXPECT_NE(100000u, uint24(1024u));
	EXPECT_NE(2000000000u, uint24(2048u));

	EXPECT_NE(1u, uint32(0u));
	EXPECT_NE(0u, uint32(1u));
	EXPECT_NE(1u, uint32(2u));
	EXPECT_NE(512u, uint32(0u));
	EXPECT_NE(512u, uint32(16u));
	EXPECT_NE(100000u, uint32(1024u));
	EXPECT_NE(2000000000000ull, uint32(2000000000u));
}

TEST(Comparision, Negative)
{
	EXPECT_FALSE(uint8(255) == -1);
	EXPECT_FALSE(-1 == uint8(255));
	EXPECT_FALSE(uint8(-1) == -1);
	EXPECT_FALSE(-1 == uint8(-1));

	EXPECT_FALSE(uint16(0xFFFF) == -1);
	EXPECT_FALSE(-1 == uint16(0xFFFF));
	EXPECT_FALSE(uint16(-1) == -1);
	EXPECT_FALSE(-1 == uint16(-1));

	EXPECT_FALSE(uint24(0xFFFFFF) == -1);
	EXPECT_FALSE(-1 == uint24(0xFFFFFF));
	EXPECT_FALSE(uint24(-1) == -1);
	EXPECT_FALSE(-1 == uint24(-1));
}

TEST(Comparision, Unsigned)
{
	EXPECT_LT(1u, uint8(2));  EXPECT_LE(1u, uint8(2));
	EXPECT_LT(1u, uint8(16)); EXPECT_LE(1u, uint8(16));
	EXPECT_LT(1u, uint8(255)); EXPECT_LE(1u, uint8(255));
	EXPECT_LT(1u, uint16(0xFFFFu)); EXPECT_LE(1u, uint16(0xFFFFu));
	EXPECT_LT(0x2266u, uint16(0x5522u)); EXPECT_LE(1u, uint16(0x5522u));
	EXPECT_LT(0x123455u, uint24(0x123456u)); EXPECT_LE(1u, uint24(0x123456u));
	EXPECT_LT(0xFEFFFFFFu, uint32(0xFF000000u)); EXPECT_LE(1u, uint32(0xFF000000u));

	EXPECT_GT(255u, uint8(0x7Fu)); EXPECT_GE(255u, uint8(0x7Fu));
	EXPECT_GT(1u, uint8(0u)); EXPECT_GE(1u, uint8(0u));
	EXPECT_GT(0xFF00u, uint8(5u)); EXPECT_GE(0xFF00u, uint8(5u));
	EXPECT_GT(0x0100u, uint16(0x00FFu)); EXPECT_GE(0x0100u, uint16(0x00FFu));
	EXPECT_GT(0x3313u, uint16(0x1234u)); EXPECT_GE(0x3313u, uint16(0x1234u));
	EXPECT_GT(0x01000000u, uint16(0xFFFFu)); EXPECT_GE(0x01000000u, uint16(0xFFFFu));
	EXPECT_GT(0x7F0000u, uint24(0x123456u)); EXPECT_GE(0x7F0000u, uint24(0x123456u));
	EXPECT_GT(0xFF000000u, uint32(0xFEFFFFFFu)); EXPECT_GE(0xFF000000u, uint32(0xFEFFFFFFu));
}

TEST(Comparision, Negative2)
{
	EXPECT_LT(-1, uint8(2));  EXPECT_LE(-1, uint8(2));
	EXPECT_LT(-5, uint8(16)); EXPECT_LE(-5, uint8(16));
	EXPECT_LT(-127, uint8(255)); EXPECT_LE(-127, uint8(255));
	EXPECT_LT(-10000, uint8(255)); EXPECT_LE(-10000, uint8(255));
	EXPECT_LT(-1, uint16(0xFFFFu)); EXPECT_LE(-1, uint8(0xFFFFu));
	EXPECT_LT(-1000, uint16(0x5522u)); EXPECT_LE(-1000, uint8(0x5522u));
	EXPECT_LT(-500, uint24(0x123456u)); EXPECT_LE(-500, uint8(0x123456u));
	EXPECT_LT(-1, uint32(0xFF000000u)); EXPECT_LE(-1, uint8(0xFF000000u));

	EXPECT_GT(uint8(0x7Fu), -255); EXPECT_GE(uint8(0x7Fu), -255);
	EXPECT_GT(uint8(0u), -1); EXPECT_GE(uint8(0u), -1);
	EXPECT_GT(uint8(5u), -1000); EXPECT_GE(uint8(5u), -1000);
	EXPECT_GT(uint16(0x00FFu), -1); EXPECT_GE(uint16(0x00FFu), -1);
	EXPECT_GT(uint16(0x1234u), -5000); EXPECT_GE(uint16(0x1234u), -5000);
	EXPECT_GT(uint16(0xFFFFu), -6464); EXPECT_GE(uint16(0xFFFFu), -6464);
	EXPECT_GT(uint24(0x123456u), -1); EXPECT_GE(uint24(0x123456u), -1);
	EXPECT_GT(uint32(0xFF000000u), -1); EXPECT_GE(uint32(0xFF000000u), -1);
}

TEST(Comparision, ComparisionOperator)
{
	EXPECT_FALSE(uint8(255) == -1);
	EXPECT_FALSE(-1 == uint8(255));
	EXPECT_FALSE(uint8(-1) == -1);
	EXPECT_FALSE(-1 == uint8(-1));

	EXPECT_FALSE(uint16(0xFFFF) == -1);
	EXPECT_FALSE(-1 == uint16(0xFFFF));
	EXPECT_FALSE(uint16(-1) == -1);
	EXPECT_FALSE(-1 == uint16(-1));

	EXPECT_FALSE(uint24(0xFFFFFF) == -1);
	EXPECT_FALSE(-1 == uint24(0xFFFFFF));
	EXPECT_FALSE(uint24(-1) == -1);
	EXPECT_FALSE(-1 == uint24(-1));
}

TEST(Assigment, Basic)
{
	uint8 x8;
	uint16 x16;
	uint24 x24;

	x8 = 255; EXPECT_EQ(255, x8);
	x8 = 128; EXPECT_EQ(128, x8);
	x8 = 0; EXPECT_EQ(0, x8);

	x16 = 0xFEFEu;  EXPECT_EQ(0xFEFEu, x16);
	x16 = 128;  EXPECT_EQ(128, x16);
	x16 = 1;  EXPECT_EQ(1, x16);

	x24 = 0xFEABu;  EXPECT_EQ(0xFEABu, x24);
	x24 = 0x123456u;  EXPECT_EQ(0x123456u, x24);
	x24 = 128;  EXPECT_EQ(128, x24);
	x24 = 1;  EXPECT_EQ(1, x24);
}

TEST(Assigment, Float)
{
	uint8 x8;
	uint16 x16;
	uint24 x24;

	x8 = (uint8)255.0f; EXPECT_EQ(255, x8);
	x8 = (uint8)128.0f; EXPECT_EQ(128, x8);
	x8 = (uint8)0.0f; EXPECT_EQ(0, x8);

	x16 = (uint16)2048.0;  EXPECT_EQ(2048, x16);
	x16 = (uint16)128.0;  EXPECT_EQ(128, x16);
	x16 = (uint16)1.0;  EXPECT_EQ(1, x16);

	x24 = (uint24)100000.0f;  EXPECT_EQ(100000, x24);
	x24 = (uint24)161616.0;  EXPECT_EQ(161616, x24);
	x24 = (uint24)128.0;  EXPECT_EQ(128, x24);
	x24 = (uint24)1.0;  EXPECT_EQ(1, x24);
}

TEST(Assigment, InBetween)
{
	uint8 x8;
	uint16 x16;
	uint24 x24;
	uint32 x32;

	const uint8 a = 0x12u;
	const uint16 b = 0x1234u;
	const uint32 c = 0x123456u;
	const uint32 d = 0x12345678u;

	x8 = a; EXPECT_EQ(0x12u, x8);

	x16 = a; EXPECT_EQ(0x12u, x16);
	x16 = b; EXPECT_EQ(0x1234u, x16);

	x24 = a; EXPECT_EQ(0x12u, x24);
	x24 = b; EXPECT_EQ(0x1234u, x24);
	x24 = c; EXPECT_EQ(0x123456u, x24);

	x32 = a; EXPECT_EQ(0x12u, x32);
	x32 = b; EXPECT_EQ(0x1234u, x32);
	x32 = c; EXPECT_EQ(0x123456u, x32);
	x32 = d; EXPECT_EQ(0x12345678u, x32);
}

TEST(Incrementation, PreIncrementation)
{
	uint8 x8;
	uint16 x16;
	uint24 x24;

	x8 = 0u; EXPECT_EQ(1u, ++x8);
	x8 = 63u; EXPECT_EQ(64u, ++x8);
	x8 = 127u; EXPECT_EQ(128u, ++x8);
	x8 = 255u; EXPECT_EQ(0u, ++x8);

	x16 = 0u; EXPECT_EQ(1u, ++x16);
	x16 = 63u; EXPECT_EQ(64u, ++x16);
	x16 = 127u; EXPECT_EQ(128u, ++x16);
	x16 = 255u; EXPECT_EQ(256u, ++x16);
	x16 = 1000u; EXPECT_EQ(1001u, ++x16);
	x16 = 0xFEFF; EXPECT_EQ(0xFF00, ++x16);
	x16 = 0xFFFF; EXPECT_EQ(0u, ++x16);

	x24 = 0u; EXPECT_EQ(1u, ++x24);
	x24 = 63u; EXPECT_EQ(64u, ++x24);
	x24 = 127u; EXPECT_EQ(128u, ++x24);
	x24 = 255u; EXPECT_EQ(256u, ++x24);
	x24 = 1000u; EXPECT_EQ(1001u, ++x24);
	x24 = 0xFEFF; EXPECT_EQ(0xFF00, ++x24);
	x24 = 0xFFFF; EXPECT_EQ(0x10000u, ++x24);
}

TEST(Incrementation, PostIncrementation)
{
	uint8 x8;
	uint16 x16;
	uint24 x24;

	x8 = 0u; EXPECT_EQ(0u, x8++); EXPECT_EQ(1u, x8);
	x8 = 63u; EXPECT_EQ(63, x8++); EXPECT_EQ(64u, x8);
	x8 = 127u; EXPECT_EQ(127u, x8++); EXPECT_EQ(128u, x8);
	x8 = 255u; EXPECT_EQ(255u, x8++); EXPECT_EQ(0u, x8);

	x16 = 0u; EXPECT_EQ(0u, x16++); EXPECT_EQ(1u, x16);
	x16 = 63u; EXPECT_EQ(63u, x16++); EXPECT_EQ(64u, x16);
	x16 = 127u; EXPECT_EQ(127u, x16++); EXPECT_EQ(128u, x16);
	x16 = 255u; EXPECT_EQ(255u, x16++); EXPECT_EQ(256u, x16);
	x16 = 1000u; EXPECT_EQ(1000u, x16++); EXPECT_EQ(1001u, x16);
	x16 = 0xFEFF; EXPECT_EQ(0xFEFF, x16++); EXPECT_EQ(0xFF00, x16);
	x16 = 0xFFFF; EXPECT_EQ(0xFFFF, x16++); EXPECT_EQ(0u, x16);

	x24 = 0u; EXPECT_EQ(0u, x24++); EXPECT_EQ(1u, x24);
	x24 = 63u; EXPECT_EQ(63u, x24++); EXPECT_EQ(64u, x24);
	x24 = 127u; EXPECT_EQ(127u, x24++); EXPECT_EQ(128u, x24);
	x24 = 255u; EXPECT_EQ(255u, x24++); EXPECT_EQ(256u, x24);
	x24 = 1000u; EXPECT_EQ(1000u, x24++); EXPECT_EQ(1001u, x24);
	x24 = 0xFEFF; EXPECT_EQ(0xFEFF, x24++); EXPECT_EQ(0xFF00, x24);
	x24 = 0xFFFF; EXPECT_EQ(0xFFFF, x24++); EXPECT_EQ(0x10000u, x24);
}

TEST(Incrementation, PreDecrementation)
{
	uint8 x8;
	uint16 x16;
	uint24 x24;

	x8 = 0u; EXPECT_EQ(255u, --x8);
	x8 = 64u; EXPECT_EQ(63u, --x8);
	x8 = 128u; EXPECT_EQ(127u, --x8);
	x8 = 255u; EXPECT_EQ(254u, --x8);

	x16 = 0u; EXPECT_EQ(0xFFFF, --x16);
	x16 = 64u; EXPECT_EQ(63u, --x16);
	x16 = 128u; EXPECT_EQ(127u, --x16);
	x16 = 255u; EXPECT_EQ(254u, --x16);
	x16 = 256u; EXPECT_EQ(255u, --x16);
	x16 = 1001u; EXPECT_EQ(1000u, --x16);
	x16 = 0x1234; EXPECT_EQ(0x1233, --x16);
	x16 = 0xFFFF; EXPECT_EQ(0xFFFE, --x16);

	x24 = 0u; EXPECT_EQ(0xFFFFFF, --x24);
	x24 = 64u; EXPECT_EQ(63u, --x24);
	x24 = 128u; EXPECT_EQ(127u, --x24);
	x24 = 256u; EXPECT_EQ(255u, --x24);
	x24 = 1000u; EXPECT_EQ(999u, --x24);
	x24 = 0xFFFF; EXPECT_EQ(0xFFFE, --x24);
	x24 = 0x10000u; EXPECT_EQ(0xFFFFu, --x24);
	x24 = 0xFFFFFF; EXPECT_EQ(0xFFFFFE, --x24);
}

TEST(Incrementation, PostDecrementation)
{
	uint8 x8;
	uint16 x16;
	uint24 x24;

	x8 = 0u; EXPECT_EQ(0u, x8--); EXPECT_EQ(255u, x8);
	x8 = 64u; EXPECT_EQ(64u, x8--); EXPECT_EQ(63u, x8);
	x8 = 128u; EXPECT_EQ(128u, x8--); EXPECT_EQ(127u, x8);
	x8 = 255u; EXPECT_EQ(255u, x8--); EXPECT_EQ(254u, x8);

	x16 = 0u; EXPECT_EQ(0u, x16--); EXPECT_EQ(0xFFFF, x16);
	x16 = 64u; EXPECT_EQ(64u, x16--); EXPECT_EQ(63u, x16);
	x16 = 128u; EXPECT_EQ(128u, x16--); EXPECT_EQ(127u, x16);
	x16 = 255u; EXPECT_EQ(255u, x16--); EXPECT_EQ(254u, x16);
	x16 = 256u; EXPECT_EQ(256u, x16--); EXPECT_EQ(255u, x16);
	x16 = 1001u; EXPECT_EQ(1001u, x16--); EXPECT_EQ(1000u, x16);
	x16 = 0x1234; EXPECT_EQ(0x1234, x16--); EXPECT_EQ(0x1233, x16);
	x16 = 0xFFFF; EXPECT_EQ(0xFFFF, x16--); EXPECT_EQ(0xFFFE, x16);

	x24 = 0u; EXPECT_EQ(0u, x24--); EXPECT_EQ(0xFFFFFF, x24);
	x24 = 64u; EXPECT_EQ(64u, x24--); EXPECT_EQ(63u, x24);
	x24 = 128u; EXPECT_EQ(128u, x24--); EXPECT_EQ(127u, x24);
	x24 = 256u; EXPECT_EQ(256u, x24--); EXPECT_EQ(255u, x24);
	x24 = 1000u; EXPECT_EQ(1000u, x24--); EXPECT_EQ(999u, x24);
	x24 = 0xFFFF; EXPECT_EQ(0xFFFF, x24--); EXPECT_EQ(0xFFFE, x24);
	x24 = 0x10000u; EXPECT_EQ(0x10000u, x24--); EXPECT_EQ(0xFFFF, x24);
	x24 = 0xFFFFFF; EXPECT_EQ(0xFFFFFF, x24--); EXPECT_EQ(0xFFFFFE, x24);
}

TEST(Conversion, Signed)
{
	int8_t x8;
	int16_t x16;
	int32_t x32;

	const uint8 a = 0x12u;
	const uint16 b = 0x1234u;
	const uint24 c = 0x123456u;
	const uint32 d = 0x12345678u;

	x8 = (int8_t)a; EXPECT_EQ(0x12u, x8);

	x16 = (int16_t)a; EXPECT_EQ(0x12u, x16);
	x16 = (int16_t)b; EXPECT_EQ(0x1234u, x16);

	x32 = (int32_t)a; EXPECT_EQ(0x12u, x32);
	x32 = (int32_t)b; EXPECT_EQ(0x1234u, x32);
	x32 = (int32_t)c; EXPECT_EQ(0x123456u, x32);
	x32 = (int32_t)d; EXPECT_EQ(0x12345678u, x32);
}

TEST(Conversion, Unsigned)
{
	uint8_t x8;
	uint16_t x16;
	uint32_t x32;

	const uint8 a = 0x12u;
	const uint16 b = 0x1234u;
	const uint24 c = 0x123456u;
	const uint32 d = 0x12345678u;

	x8 = (uint8_t)a; EXPECT_EQ(0x12u, x8);

	x16 = (uint16_t)a; EXPECT_EQ(0x12u, x16);
	x16 = (uint16_t)b; EXPECT_EQ(0x1234u, x16);

	x32 = (uint32_t)a; EXPECT_EQ(0x12u, x32);
	x32 = (uint32_t)b; EXPECT_EQ(0x1234u, x32);
	x32 = (uint32_t)c; EXPECT_EQ(0x123456u, x32);
	x32 = (uint32_t)d; EXPECT_EQ(0x12345678u, x32);
}

TEST(Conversion, Boolean)
{
	EXPECT_TRUE(uint8(1u));
	EXPECT_TRUE(uint8(16u));
	EXPECT_TRUE(uint16(1u));
	EXPECT_TRUE(uint16(0xFF00));
	EXPECT_TRUE(uint24(0x00FF00));
	EXPECT_TRUE(uint24(0x010000));
	EXPECT_TRUE(uint32(0x01000000));
	EXPECT_TRUE(uint32(0x00010000));

	EXPECT_FALSE(uint8(0));
	EXPECT_FALSE(uint16(0));
	EXPECT_FALSE(uint24(0));
	EXPECT_FALSE(uint32(0));
	EXPECT_FALSE(uint64(0));
}

TEST(Conversion, BooleanNegative)
{
	EXPECT_FALSE(!uint8(1u));
	EXPECT_FALSE(!uint8(16u));
	EXPECT_FALSE(!uint16(1u));
	EXPECT_FALSE(!uint16(0xFF00));
	EXPECT_FALSE(!uint24(0x00FF00));
	EXPECT_FALSE(!uint24(0x010000));
	EXPECT_FALSE(!uint32(0x01000000));
	EXPECT_FALSE(!uint32(0x00010000));

	EXPECT_TRUE(!uint8(0));
	EXPECT_TRUE(!uint16(0));
	EXPECT_TRUE(!uint24(0));
	EXPECT_TRUE(!uint32(0));
	EXPECT_TRUE(!uint64(0));
}

TEST(BitOperations, Basic)
{
	uint32 a = 0x12345678u;
	uint32 b = 0x00120034u;
	uint16 c = 0x1234u;
	uint8 d = 0x12u;

	EXPECT_EQ(0x12345678u ^ 0x00120034u, a ^ b);
	EXPECT_EQ(0x12345678u ^ 0x1234u, a ^ c);
	EXPECT_EQ(0x12345678u ^ 0x12u, a ^ d);
	EXPECT_EQ(0x00120034u ^ 0x1234u, b ^ c);
	EXPECT_EQ(0x00120034u ^ 0x12u, b ^ d);
	EXPECT_EQ(0x1234u ^ 0x12u, c ^ d);

	EXPECT_EQ(0x12345678u | 0x00120034u, a | b);
	EXPECT_EQ(0x12345678u | 0x1234u, a | c);
	EXPECT_EQ(0x12345678u | 0x12u, a | d);
	EXPECT_EQ(0x00120034u | 0x1234u, b | c);
	EXPECT_EQ(0x00120034u | 0x12u, b | d);
	EXPECT_EQ(0x1234u | 0x12u, c | d);

	EXPECT_EQ(0x12345678u & 0x00120034u, a & b);
	EXPECT_EQ(0x12345678u & 0x1234u, a & c);
	EXPECT_EQ(0x12345678u & 0x12u, a & d);
	EXPECT_EQ(0x00120034u & 0x1234u, b & c);
	EXPECT_EQ(0x00120034u & 0x12u, b & d);
	EXPECT_EQ(0x1234u & 0x12u, c & d);
}

TEST(BitOperations, Complement)
{
	uint32 a = 0x12345678u;
	uint32 b = 0x00001234u;
	uint32 c = 0x00120034u;

	EXPECT_EQ(~0x12345678u, ~a);
	EXPECT_EQ(~0x00001234u, ~b);
	EXPECT_EQ(~0x00120034u, ~c);
}

TEST(BitOperations, BitShift)
{
	EXPECT_EQ(1 << 3, uint8(1) << 3);
	EXPECT_EQ(3 << 3, uint8(3) << 3);
	EXPECT_EQ(255 << 3, uint16(255) << 3);
	EXPECT_EQ(512 << 3, uint16(512) << 3);
	EXPECT_EQ(0x0123 << 3, uint16(0x0123) << 3);
	EXPECT_EQ(0xFFFF << 4, uint24(0xFFFF) << 4);
	EXPECT_EQ(0x0100 << 4, uint32(0x0100) << 4);
	EXPECT_EQ(0x00010001 << 5, uint32(0x00010001) << 5);
	EXPECT_EQ(0x00010100 << 5, uint32(0x00010100) << 5);

	EXPECT_EQ(16 >> 2, uint8(16) >> 2);
	EXPECT_EQ(254 >> 3, uint8(254) >> 3);
	EXPECT_EQ(0x1234 >> 2, uint16(0x1234) >> 2);
	EXPECT_EQ(0x7FFF >> 7, uint16(0x7FFF) >> 7);
	EXPECT_EQ(0xFE00FE >> 5, uint32(0xFE00FE) >> 5);

	EXPECT_EQ(1 << 3, 1 << uint8(3));
	EXPECT_EQ(3 << 3, 3 << uint16(3));
	EXPECT_EQ(255 << 3, 255 << uint8(3));
	EXPECT_EQ(512 << 3, 512 << uint16(3));
	EXPECT_EQ(0x0123 << 3, 0x0123 << uint8(3));
	EXPECT_EQ(0xFFFF << 4, 0xFFFF << uint16(4));
	EXPECT_EQ(0x0100 << 4, 0x0100 << uint32(4));
	EXPECT_EQ(0x00010001 << 5, 0x00010001 << uint8(5));
	EXPECT_EQ(0x00010100 << 5, 0x00010100 << uint16(5));

	EXPECT_EQ(16 >> 2, 16 >> uint8(2));
	EXPECT_EQ(254 >> 3, 254 >> uint16(3));
	EXPECT_EQ(0x1234 >> 2, 0x1234 >> uint8(2));
	EXPECT_EQ(0x7FFF >> 7, 0x7FFF >> uint16(7));
	EXPECT_EQ(0xFE00FE >> 5, 0xFE00FE >> uint8(5));
	EXPECT_EQ(0xFE00FE >> 5, 0xFE00FE >> uint16(5));
	EXPECT_EQ(0xFE00FE >> 5, 0xFE00FE >> uint32(5));
}

TEST(BitOperations, BitShiftInsane)
{
	EXPECT_EQ(0, 1 << uint32(0xFFFF));
	EXPECT_EQ(0, uint32(1) << 0xFFFF);

	EXPECT_EQ(0, 1 >> uint32(0xFFFF));
	EXPECT_EQ(0, uint32(1) >>0xFFFF);
}
TEST(Arithmetic, Addition)
{
	EXPECT_EQ(1 + 1, uint8(1) + 1);
	EXPECT_EQ(1 + 1, 1 + uint8(1));
	EXPECT_EQ(1 + 1, uint8(1) + uint8(1));

	EXPECT_EQ(255 + 255, uint16(255) + 255);
	EXPECT_EQ(255 + 255, 255 + uint16(255));
	EXPECT_EQ(255 + 255, uint16(255) + uint8(255));

	EXPECT_EQ(0xFEFE + 0x0100, uint32(0xFEFE) + 0x0100);
	EXPECT_EQ(0x56007800 + 0x120034, 0x56007800 + uint32(0x120034));
	EXPECT_EQ(0x56007800 + 0x120034, uint32(0x56007800) + uint32(0x120034));
	EXPECT_EQ(0x12345678 + 0x23456789, uint32(0x12345678) + 0x23456789);
}
TEST(Arithmetic, Substraction)
{
	EXPECT_EQ(1 - 1, uint8(1) - 1);
	EXPECT_EQ(1 - 1, 1 - uint8(1));
	EXPECT_EQ(1 - 1, uint8(1) - uint8(1));

	EXPECT_EQ(128 - 64, uint16(128) - 64);
	EXPECT_EQ(0x0100 - 0xFF, uint16(0x0100) - 0xFF);
	EXPECT_EQ(0x0105 - 0xFF, uint16(0x0105) - 0xFF);
	EXPECT_EQ(0x01000000 - 0x01, uint32(0x01000000) - 0x01);
	EXPECT_EQ(0x01001001 - 0xFFFF, uint32(0x01001001) - 0xFFFF);
	EXPECT_EQ(0x12345678 - 0xFFFF, uint32(0x12345678) - 0xFFFF);
	EXPECT_EQ(0x12345678 - 0x876543, 0x12345678 - uint32(0x876543));
}
TEST(Arithmetic, Multiplication)
{
	EXPECT_EQ(0 * 0, uint8(0) * 0);
	EXPECT_EQ(0 * 1, uint8(0) * 1);
	EXPECT_EQ(1 * 1, uint8(1) * 1);
	EXPECT_EQ(2 * 5, uint8(2) * 5);
	EXPECT_EQ(255 * 255, uint16(255) * 255);
	EXPECT_EQ(16 * 512, uint16(16) * 512);
	EXPECT_EQ(512 * 16, uint16(512) * 16);

	EXPECT_EQ(100000 * 1234, uint32(100000) * uint16(1234));
	EXPECT_EQ(1234 * 5678, uint32(1234) * uint16(5678));
	EXPECT_EQ(0x01000200 * 0x12, uint32(0x01000200) * uint16(0x12));
	EXPECT_EQ(0x100000 * 1234, uint32(0x100000) * uint16(1234));
	EXPECT_EQ(0x12345678 * 3, uint32(0x12345678) * uint8(3));
}
TEST(Arithmetic, Division)
{
	EXPECT_EQ(0 / 1, uint8(0) / 1);
	EXPECT_EQ(4 / 3, uint8(4) / 3);
	EXPECT_EQ(4 / 2, uint8(4) / 2);
	EXPECT_EQ(57 / 1, uint8(57) / 1);
	EXPECT_EQ(57 / 17, uint16(57) / uint8(17));
	EXPECT_EQ(57 / 17, uint16(57) / 17);
	EXPECT_EQ(57 / 17, 57 / uint8(17));
	EXPECT_EQ(0x1000 / 2, uint16(0x1000) / 2);
	EXPECT_EQ(0x010000 / 3, uint32(0x010000) / 3);
	EXPECT_EQ(0x123456 / 17, uint32(0x123456) / 17);
	EXPECT_EQ(0x12345678 / 0x123, uint32(0x12345678) / 0x123);
	EXPECT_EQ(0xababab / 0x87, uint32(0xababab) / 0x87);
	EXPECT_EQ(0x1234 / 0x2000, uint32(0x1234) / 0x2000);
}
TEST(Arithmetic, Modulo)
{
	EXPECT_EQ(0 % 1, uint8(0) % 1);
	EXPECT_EQ(4 % 3, uint8(4) % 3);
	EXPECT_EQ(4 % 2, uint8(4) % 2);
	EXPECT_EQ(57 % 1, uint8(57) % 1);
	EXPECT_EQ(57 % 17, uint16(57) % uint8(17));
	EXPECT_EQ(57 % 17, uint16(57) % 17);
	EXPECT_EQ(57 % 17, 57 % uint8(17));
	EXPECT_EQ(0x1000 % 2, uint16(0x1000) % 2);
	EXPECT_EQ(0x010000 % 3, uint32(0x010000) % 3);
	EXPECT_EQ(0x123456 % 17, uint32(0x123456) % 17);
	EXPECT_EQ(0x12345678 % 0x123, uint32(0x12345678) % 0x123);
	EXPECT_EQ(0xababab % 0x87, uint32(0xababab) % 0x87);
	EXPECT_EQ(0x1234 % 0x2000, uint32(0x1234) % 0x2000);
}
TEST(Arithmetic, Sqrt)
{
	EXPECT_EQ(4, sqrt(uint8(16)));
	EXPECT_EQ(4, sqrt(uint8(18)));
	EXPECT_EQ(9, sqrt(uint16(9 * 9)));
	EXPECT_EQ(13, sqrt(uint32(13 * 13)));
	EXPECT_EQ(15, sqrt(uint32(15 * 15)));
	EXPECT_EQ(123, sqrt(uint64(123ull * 123ull)));
}

#define STREAM_TEST(type, mod, x) {std::stringstream buff1, buff2; buff1 << mod << type(x); buff2 << mod << x; EXPECT_EQ(buff2.str(), buff1.str()); }

TEST(Stream, Bases)
{
	STREAM_TEST(uint8, std::dec, 0x00);
	STREAM_TEST(uint8, std::hex, 0x00);
	STREAM_TEST(uint8, std::oct, 0x00);

	STREAM_TEST(uint8, std::dec, 0x01);
	STREAM_TEST(uint8, std::hex, 0x01);
	STREAM_TEST(uint8, std::oct, 0x01);
	
	STREAM_TEST(uint8, std::dec, 0x12);
	STREAM_TEST(uint8, std::hex, 0x12);
	STREAM_TEST(uint8, std::oct, 0x12);

	STREAM_TEST(uint8, std::dec, 0x99);
	STREAM_TEST(uint8, std::hex, 0x99);
	STREAM_TEST(uint8, std::oct, 0x99);

	STREAM_TEST(uint16, std::dec, 0x001b);
	STREAM_TEST(uint16, std::hex, 0x001b);
	STREAM_TEST(uint16, std::oct, 0x001b);

	STREAM_TEST(uint16, std::dec, 0x0100);
	STREAM_TEST(uint16, std::hex, 0x0100);
	STREAM_TEST(uint16, std::oct, 0x0100);

	STREAM_TEST(uint16, std::dec, 0xab12);
	STREAM_TEST(uint16, std::hex, 0xab12);
	STREAM_TEST(uint16, std::oct, 0xab12);

	STREAM_TEST(uint32, std::dec, 0x00ab1200);
	STREAM_TEST(uint32, std::hex, 0x00ab1200);
	STREAM_TEST(uint32, std::oct, 0x00ab1200);

	STREAM_TEST(uint32, std::dec, 0x0ab12000);
	STREAM_TEST(uint32, std::hex, 0x0ab12000);
	STREAM_TEST(uint32, std::oct, 0x0ab12000);

	STREAM_TEST(uint32, std::dec, 0x01000200);
	STREAM_TEST(uint32, std::hex, 0x01000200);
	STREAM_TEST(uint32, std::oct, 0x01000200);

	STREAM_TEST(uint32, std::dec, 0x00001100);
	STREAM_TEST(uint32, std::hex, 0x00001100);
	STREAM_TEST(uint32, std::oct, 0x00001100);

	STREAM_TEST(uint32, std::dec, 1000);
	STREAM_TEST(uint32, std::hex, 1000);
	STREAM_TEST(uint32, std::oct, 1000);

	STREAM_TEST(uint32, std::dec, 01000);
	STREAM_TEST(uint32, std::hex, 01000);
	STREAM_TEST(uint32, std::oct, 01000);
}

TEST(Stream, BasesUppercase)
{
	STREAM_TEST(uint8, std::uppercase << std::dec, 0x00);
	STREAM_TEST(uint8, std::uppercase << std::hex, 0x00);
	STREAM_TEST(uint8, std::uppercase << std::oct, 0x00);

	STREAM_TEST(uint8, std::uppercase << std::dec, 0x01);
	STREAM_TEST(uint8, std::uppercase << std::hex, 0x01);
	STREAM_TEST(uint8, std::uppercase << std::oct, 0x01);

	STREAM_TEST(uint8, std::uppercase << std::dec, 0x12);
	STREAM_TEST(uint8, std::uppercase << std::hex, 0x12);
	STREAM_TEST(uint8, std::uppercase << std::oct, 0x12);

	STREAM_TEST(uint8, std::uppercase << std::dec, 0x99);
	STREAM_TEST(uint8, std::uppercase << std::hex, 0x99);
	STREAM_TEST(uint8, std::uppercase << std::oct, 0x99);

	STREAM_TEST(uint16, std::uppercase << std::dec, 0x001b);
	STREAM_TEST(uint16, std::uppercase << std::hex, 0x001b);
	STREAM_TEST(uint16, std::uppercase << std::oct, 0x001b);

	STREAM_TEST(uint16, std::uppercase << std::dec, 0x0100);
	STREAM_TEST(uint16, std::uppercase << std::hex, 0x0100);
	STREAM_TEST(uint16, std::uppercase << std::oct, 0x0100);

	STREAM_TEST(uint16, std::uppercase << std::dec, 0xab12);
	STREAM_TEST(uint16, std::uppercase << std::hex, 0xab12);
	STREAM_TEST(uint16, std::uppercase << std::oct, 0xab12);

	STREAM_TEST(uint32, std::uppercase << std::dec, 0x00ab1200);
	STREAM_TEST(uint32, std::uppercase << std::hex, 0x00ab1200);
	STREAM_TEST(uint32, std::uppercase << std::oct, 0x00ab1200);

	STREAM_TEST(uint32, std::uppercase << std::dec, 0x0ab12000);
	STREAM_TEST(uint32, std::uppercase << std::hex, 0x0ab12000);
	STREAM_TEST(uint32, std::uppercase << std::oct, 0x0ab12000);

	STREAM_TEST(uint32, std::uppercase << std::dec, 0x01000200);
	STREAM_TEST(uint32, std::uppercase << std::hex, 0x01000200);
	STREAM_TEST(uint32, std::uppercase << std::oct, 0x01000200);

	STREAM_TEST(uint32, std::uppercase << std::dec, 0x00001100);
	STREAM_TEST(uint32, std::uppercase << std::hex, 0x00001100);
	STREAM_TEST(uint32, std::uppercase << std::oct, 0x00001100);

	STREAM_TEST(uint32, std::uppercase << std::dec, 1000);
	STREAM_TEST(uint32, std::uppercase << std::hex, 1000);
	STREAM_TEST(uint32, std::uppercase << std::oct, 1000);

	STREAM_TEST(uint32, std::uppercase << std::dec, 01000);
	STREAM_TEST(uint32, std::uppercase << std::hex, 01000);
	STREAM_TEST(uint32, std::uppercase << std::oct, 01000);
}

TEST(Stream, PositiveAndBase)
{
	STREAM_TEST(uint8, std::showbase << std::showpos << std::dec, 0x00);
	STREAM_TEST(uint8, std::showbase << std::showpos << std::hex, 0x00);
	STREAM_TEST(uint8, std::showbase << std::showpos << std::oct, 0x00);

	STREAM_TEST(uint8, std::showbase << std::showpos << std::dec, 0x01);
	STREAM_TEST(uint8, std::showbase << std::showpos << std::hex, 0x01);
	STREAM_TEST(uint8, std::showbase << std::showpos << std::oct, 0x01);

	STREAM_TEST(uint8, std::showbase << std::showpos << std::dec, 0x12);
	STREAM_TEST(uint8, std::showbase << std::showpos << std::hex, 0x12);
	STREAM_TEST(uint8, std::showbase << std::showpos << std::oct, 0x12);

	STREAM_TEST(uint8, std::showbase << std::showpos << std::dec, 0x99);
	STREAM_TEST(uint8, std::showbase << std::showpos << std::hex, 0x99);
	STREAM_TEST(uint8, std::showbase << std::showpos << std::oct, 0x99);

	STREAM_TEST(uint16, std::showbase << std::showpos << std::dec, 0x001b);
	STREAM_TEST(uint16, std::showbase << std::showpos << std::hex, 0x001b);
	STREAM_TEST(uint16, std::showbase << std::showpos << std::oct, 0x001b);

	STREAM_TEST(uint16, std::showbase << std::showpos << std::dec, 0x0100);
	STREAM_TEST(uint16, std::showbase << std::showpos << std::hex, 0x0100);
	STREAM_TEST(uint16, std::showbase << std::showpos << std::oct, 0x0100);

	STREAM_TEST(uint16, std::showbase << std::showpos << std::dec, 0xab12);
	STREAM_TEST(uint16, std::showbase << std::showpos << std::hex, 0xab12);
	STREAM_TEST(uint16, std::showbase << std::showpos << std::oct, 0xab12);

	STREAM_TEST(uint32, std::showbase << std::showpos << std::dec, 0x00ab1200);
	STREAM_TEST(uint32, std::showbase << std::showpos << std::hex, 0x00ab1200);
	STREAM_TEST(uint32, std::showbase << std::showpos << std::oct, 0x00ab1200);

	STREAM_TEST(uint32, std::showbase << std::showpos << std::dec, 0x0ab12000);
	STREAM_TEST(uint32, std::showbase << std::showpos << std::hex, 0x0ab12000);
	STREAM_TEST(uint32, std::showbase << std::showpos << std::oct, 0x0ab12000);

	STREAM_TEST(uint32, std::showbase << std::showpos << std::dec, 0x01000200);
	STREAM_TEST(uint32, std::showbase << std::showpos << std::hex, 0x01000200);
	STREAM_TEST(uint32, std::showbase << std::showpos << std::oct, 0x01000200);

	STREAM_TEST(uint32, std::showbase << std::showpos << std::dec, 0x00001100);
	STREAM_TEST(uint32, std::showbase << std::showpos << std::hex, 0x00001100);
	STREAM_TEST(uint32, std::showbase << std::showpos << std::oct, 0x00001100);

	STREAM_TEST(uint32, std::showbase << std::showpos << std::dec, 1000);
	STREAM_TEST(uint32, std::showbase << std::showpos << std::hex, 1000);
	STREAM_TEST(uint32, std::showbase << std::showpos << std::oct, 1000);

	STREAM_TEST(uint32, std::showbase << std::showpos << std::dec, 01000);
	STREAM_TEST(uint32, std::showbase << std::showpos << std::hex, 01000);
	STREAM_TEST(uint32, std::showbase << std::showpos << std::oct, 01000);
}

#define STREAM_TEST_WIDTH(type, mod, x, len) {std::stringstream buff1, buff2; buff1.width(len); buff2.width(len); buff1 << mod << type(x); buff2 << mod << x; EXPECT_EQ(buff2.str(), buff1.str()); }


TEST(StreamAlign, Internal)
{
	STREAM_TEST_WIDTH(uint8, std::internal << std::dec, 0x00, 16);
	STREAM_TEST_WIDTH(uint8, std::internal << std::hex, 0x00, 16);
	STREAM_TEST_WIDTH(uint8, std::internal << std::oct, 0x00, 16);

	STREAM_TEST_WIDTH(uint8, std::internal << std::dec, 0x01, 16);
	STREAM_TEST_WIDTH(uint8, std::internal << std::hex, 0x01, 16);
	STREAM_TEST_WIDTH(uint8, std::internal << std::oct, 0x01, 16);

	STREAM_TEST_WIDTH(uint8, std::internal << std::dec, 0x12, 16);
	STREAM_TEST_WIDTH(uint8, std::internal << std::hex, 0x12, 16);
	STREAM_TEST_WIDTH(uint8, std::internal << std::oct, 0x12, 16);

	STREAM_TEST_WIDTH(uint8, std::internal << std::dec, 0x99, 16);
	STREAM_TEST_WIDTH(uint8, std::internal << std::hex, 0x99, 16);
	STREAM_TEST_WIDTH(uint8, std::internal << std::oct, 0x99, 16);

	STREAM_TEST_WIDTH(uint16, std::internal << std::dec, 0x001b, 16);
	STREAM_TEST_WIDTH(uint16, std::internal << std::hex, 0x001b, 16);
	STREAM_TEST_WIDTH(uint16, std::internal << std::oct, 0x001b, 16);

	STREAM_TEST_WIDTH(uint16, std::internal << std::dec, 0x0100, 16);
	STREAM_TEST_WIDTH(uint16, std::internal << std::hex, 0x0100, 16);
	STREAM_TEST_WIDTH(uint16, std::internal << std::oct, 0x0100, 16);

	STREAM_TEST_WIDTH(uint16, std::internal << std::dec, 0xab12, 16);
	STREAM_TEST_WIDTH(uint16, std::internal << std::hex, 0xab12, 16);
	STREAM_TEST_WIDTH(uint16, std::internal << std::oct, 0xab12, 16);

	STREAM_TEST_WIDTH(uint32, std::internal << std::dec, 0x00ab1200, 16);
	STREAM_TEST_WIDTH(uint32, std::internal << std::hex, 0x00ab1200, 16);
	STREAM_TEST_WIDTH(uint32, std::internal << std::oct, 0x00ab1200, 16);

	STREAM_TEST_WIDTH(uint32, std::internal << std::dec, 0x0ab12000, 16);
	STREAM_TEST_WIDTH(uint32, std::internal << std::hex, 0x0ab12000, 16);
	STREAM_TEST_WIDTH(uint32, std::internal << std::oct, 0x0ab12000, 16);

	STREAM_TEST_WIDTH(uint32, std::internal << std::dec, 0x01000200, 16);
	STREAM_TEST_WIDTH(uint32, std::internal << std::hex, 0x01000200, 16);
	STREAM_TEST_WIDTH(uint32, std::internal << std::oct, 0x01000200, 16);

	STREAM_TEST_WIDTH(uint32, std::internal << std::dec, 0x00001100, 16);
	STREAM_TEST_WIDTH(uint32, std::internal << std::hex, 0x00001100, 16);
	STREAM_TEST_WIDTH(uint32, std::internal << std::oct, 0x00001100, 16);

	STREAM_TEST_WIDTH(uint32, std::internal << std::dec, 1000, 16);
	STREAM_TEST_WIDTH(uint32, std::internal << std::hex, 1000, 16);
	STREAM_TEST_WIDTH(uint32, std::internal << std::oct, 1000, 16);

	STREAM_TEST_WIDTH(uint32, std::internal << std::dec, 01000, 16);
	STREAM_TEST_WIDTH(uint32, std::internal << std::hex, 01000, 16);
	STREAM_TEST_WIDTH(uint32, std::internal << std::oct, 01000, 16);
}

TEST(StreamAlign, Left)
{
	STREAM_TEST_WIDTH(uint8, std::left << std::dec, 0x00, 16);
	STREAM_TEST_WIDTH(uint8, std::left << std::hex, 0x00, 16);
	STREAM_TEST_WIDTH(uint8, std::left << std::oct, 0x00, 16);

	STREAM_TEST_WIDTH(uint8, std::left << std::dec, 0x01, 16);
	STREAM_TEST_WIDTH(uint8, std::left << std::hex, 0x01, 16);
	STREAM_TEST_WIDTH(uint8, std::left << std::oct, 0x01, 16);

	STREAM_TEST_WIDTH(uint8, std::left << std::dec, 0x12, 16);
	STREAM_TEST_WIDTH(uint8, std::left << std::hex, 0x12, 16);
	STREAM_TEST_WIDTH(uint8, std::left << std::oct, 0x12, 16);

	STREAM_TEST_WIDTH(uint8, std::left << std::dec, 0x99, 16);
	STREAM_TEST_WIDTH(uint8, std::left << std::hex, 0x99, 16);
	STREAM_TEST_WIDTH(uint8, std::left << std::oct, 0x99, 16);

	STREAM_TEST_WIDTH(uint16, std::left << std::dec, 0x001b, 16);
	STREAM_TEST_WIDTH(uint16, std::left << std::hex, 0x001b, 16);
	STREAM_TEST_WIDTH(uint16, std::left << std::oct, 0x001b, 16);

	STREAM_TEST_WIDTH(uint16, std::left << std::dec, 0x0100, 16);
	STREAM_TEST_WIDTH(uint16, std::left << std::hex, 0x0100, 16);
	STREAM_TEST_WIDTH(uint16, std::left << std::oct, 0x0100, 16);

	STREAM_TEST_WIDTH(uint16, std::left << std::dec, 0xab12, 16);
	STREAM_TEST_WIDTH(uint16, std::left << std::hex, 0xab12, 16);
	STREAM_TEST_WIDTH(uint16, std::left << std::oct, 0xab12, 16);

	STREAM_TEST_WIDTH(uint32, std::left << std::dec, 0x00ab1200, 16);
	STREAM_TEST_WIDTH(uint32, std::left << std::hex, 0x00ab1200, 16);
	STREAM_TEST_WIDTH(uint32, std::left << std::oct, 0x00ab1200, 16);

	STREAM_TEST_WIDTH(uint32, std::left << std::dec, 0x0ab12000, 16);
	STREAM_TEST_WIDTH(uint32, std::left << std::hex, 0x0ab12000, 16);
	STREAM_TEST_WIDTH(uint32, std::left << std::oct, 0x0ab12000, 16);

	STREAM_TEST_WIDTH(uint32, std::left << std::dec, 0x01000200, 16);
	STREAM_TEST_WIDTH(uint32, std::left << std::hex, 0x01000200, 16);
	STREAM_TEST_WIDTH(uint32, std::left << std::oct, 0x01000200, 16);

	STREAM_TEST_WIDTH(uint32, std::left << std::dec, 0x00001100, 16);
	STREAM_TEST_WIDTH(uint32, std::left << std::hex, 0x00001100, 16);
	STREAM_TEST_WIDTH(uint32, std::left << std::oct, 0x00001100, 16);

	STREAM_TEST_WIDTH(uint32, std::left << std::dec, 1000, 16);
	STREAM_TEST_WIDTH(uint32, std::left << std::hex, 1000, 16);
	STREAM_TEST_WIDTH(uint32, std::left << std::oct, 1000, 16);

	STREAM_TEST_WIDTH(uint32, std::left << std::dec, 01000, 16);
	STREAM_TEST_WIDTH(uint32, std::left << std::hex, 01000, 16);
	STREAM_TEST_WIDTH(uint32, std::left << std::oct, 01000, 16);
}

TEST(StreamAlign, Right)
{
	STREAM_TEST_WIDTH(uint8, std::right << std::dec, 0x00, 16);
	STREAM_TEST_WIDTH(uint8, std::right << std::hex, 0x00, 16);
	STREAM_TEST_WIDTH(uint8, std::right << std::oct, 0x00, 16);

	STREAM_TEST_WIDTH(uint8, std::right << std::dec, 0x01, 16);
	STREAM_TEST_WIDTH(uint8, std::right << std::hex, 0x01, 16);
	STREAM_TEST_WIDTH(uint8, std::right << std::oct, 0x01, 16);

	STREAM_TEST_WIDTH(uint8, std::right << std::dec, 0x12, 16);
	STREAM_TEST_WIDTH(uint8, std::right << std::hex, 0x12, 16);
	STREAM_TEST_WIDTH(uint8, std::right << std::oct, 0x12, 16);

	STREAM_TEST_WIDTH(uint8, std::right << std::dec, 0x99, 16);
	STREAM_TEST_WIDTH(uint8, std::right << std::hex, 0x99, 16);
	STREAM_TEST_WIDTH(uint8, std::right << std::oct, 0x99, 16);

	STREAM_TEST_WIDTH(uint16, std::right << std::dec, 0x001b, 16);
	STREAM_TEST_WIDTH(uint16, std::right << std::hex, 0x001b, 16);
	STREAM_TEST_WIDTH(uint16, std::right << std::oct, 0x001b, 16);

	STREAM_TEST_WIDTH(uint16, std::right << std::dec, 0x0100, 16);
	STREAM_TEST_WIDTH(uint16, std::right << std::hex, 0x0100, 16);
	STREAM_TEST_WIDTH(uint16, std::right << std::oct, 0x0100, 16);

	STREAM_TEST_WIDTH(uint16, std::right << std::dec, 0xab12, 16);
	STREAM_TEST_WIDTH(uint16, std::right << std::hex, 0xab12, 16);
	STREAM_TEST_WIDTH(uint16, std::right << std::oct, 0xab12, 16);

	STREAM_TEST_WIDTH(uint32, std::right << std::dec, 0x00ab1200, 16);
	STREAM_TEST_WIDTH(uint32, std::right << std::hex, 0x00ab1200, 16);
	STREAM_TEST_WIDTH(uint32, std::right << std::oct, 0x00ab1200, 16);

	STREAM_TEST_WIDTH(uint32, std::right << std::dec, 0x0ab12000, 16);
	STREAM_TEST_WIDTH(uint32, std::right << std::hex, 0x0ab12000, 16);
	STREAM_TEST_WIDTH(uint32, std::right << std::oct, 0x0ab12000, 16);

	STREAM_TEST_WIDTH(uint32, std::right << std::dec, 0x01000200, 16);
	STREAM_TEST_WIDTH(uint32, std::right << std::hex, 0x01000200, 16);
	STREAM_TEST_WIDTH(uint32, std::right << std::oct, 0x01000200, 16);

	STREAM_TEST_WIDTH(uint32, std::right << std::dec, 0x00001100, 16);
	STREAM_TEST_WIDTH(uint32, std::right << std::hex, 0x00001100, 16);
	STREAM_TEST_WIDTH(uint32, std::right << std::oct, 0x00001100, 16);

	STREAM_TEST_WIDTH(uint32, std::right << std::dec, 1000, 16);
	STREAM_TEST_WIDTH(uint32, std::right << std::hex, 1000, 16);
	STREAM_TEST_WIDTH(uint32, std::right << std::oct, 1000, 16);

	STREAM_TEST_WIDTH(uint32, std::right << std::dec, 01000, 16);
	STREAM_TEST_WIDTH(uint32, std::right << std::hex, 01000, 16);
	STREAM_TEST_WIDTH(uint32, std::right << std::oct, 01000, 16);
}

TEST(StreamAlign, InternalWithBase)
{
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::dec, 0x00, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::hex, 0x00, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::oct, 0x00, 16);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::dec, 0x01, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::hex, 0x01, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::oct, 0x01, 16);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::dec, 0x12, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::hex, 0x12, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::oct, 0x12, 16);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::dec, 0x99, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::hex, 0x99, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::oct, 0x99, 16);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::dec, 0x001b, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::hex, 0x001b, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::oct, 0x001b, 16);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::dec, 0x0100, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::hex, 0x0100, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::oct, 0x0100, 16);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::dec, 0xab12, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::hex, 0xab12, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::oct, 0xab12, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::dec, 0x00ab1200, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::hex, 0x00ab1200, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::oct, 0x00ab1200, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::dec, 0x0ab12000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::hex, 0x0ab12000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::oct, 0x0ab12000, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::dec, 0x01000200, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::hex, 0x01000200, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::oct, 0x01000200, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::dec, 0x00001100, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::hex, 0x00001100, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::oct, 0x00001100, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::dec, 1000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::hex, 1000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::oct, 1000, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::dec, 01000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::hex, 01000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::oct, 01000, 16);
}


TEST(StreamAlign, LeftWithBase)
{
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::dec, 0x00, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::hex, 0x00, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::oct, 0x00, 16);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::dec, 0x01, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::hex, 0x01, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::oct, 0x01, 16);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::dec, 0x12, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::hex, 0x12, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::oct, 0x12, 16);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::dec, 0x99, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::hex, 0x99, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::oct, 0x99, 16);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::dec, 0x001b, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::hex, 0x001b, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::oct, 0x001b, 16);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::dec, 0x0100, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::hex, 0x0100, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::oct, 0x0100, 16);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::dec, 0xab12, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::hex, 0xab12, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::oct, 0xab12, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::dec, 0x00ab1200, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::hex, 0x00ab1200, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::oct, 0x00ab1200, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::dec, 0x0ab12000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::hex, 0x0ab12000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::oct, 0x0ab12000, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::dec, 0x01000200, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::hex, 0x01000200, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::oct, 0x01000200, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::dec, 0x00001100, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::hex, 0x00001100, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::oct, 0x00001100, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::dec, 1000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::hex, 1000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::oct, 1000, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::dec, 01000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::hex, 01000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::oct, 01000, 16);
}
TEST(StreamAlign, RightWithBase)
{
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::dec, 0x00, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::hex, 0x00, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::oct, 0x00, 16);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::dec, 0x01, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::hex, 0x01, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::oct, 0x01, 16);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::dec, 0x12, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::hex, 0x12, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::oct, 0x12, 16);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::dec, 0x99, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::hex, 0x99, 16);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::oct, 0x99, 16);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::dec, 0x001b, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::hex, 0x001b, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::oct, 0x001b, 16);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::dec, 0x0100, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::hex, 0x0100, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::oct, 0x0100, 16);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::dec, 0xab12, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::hex, 0xab12, 16);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::oct, 0xab12, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::dec, 0x00ab1200, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::hex, 0x00ab1200, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::oct, 0x00ab1200, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::dec, 0x0ab12000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::hex, 0x0ab12000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::oct, 0x0ab12000, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::dec, 0x01000200, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::hex, 0x01000200, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::oct, 0x01000200, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::dec, 0x00001100, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::hex, 0x00001100, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::oct, 0x00001100, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::dec, 1000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::hex, 1000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::oct, 1000, 16);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::dec, 01000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::hex, 01000, 16);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::oct, 01000, 16);
}

TEST(StreamAlign, InternalShort)
{
	STREAM_TEST_WIDTH(uint8, std::internal << std::dec, 0x00, 2);
	STREAM_TEST_WIDTH(uint8, std::internal << std::hex, 0x00, 2);
	STREAM_TEST_WIDTH(uint8, std::internal << std::oct, 0x00, 2);

	STREAM_TEST_WIDTH(uint8, std::internal << std::dec, 0x01, 2);
	STREAM_TEST_WIDTH(uint8, std::internal << std::hex, 0x01, 2);
	STREAM_TEST_WIDTH(uint8, std::internal << std::oct, 0x01, 2);

	STREAM_TEST_WIDTH(uint8, std::internal << std::dec, 0x12, 2);
	STREAM_TEST_WIDTH(uint8, std::internal << std::hex, 0x12, 2);
	STREAM_TEST_WIDTH(uint8, std::internal << std::oct, 0x12, 2);

	STREAM_TEST_WIDTH(uint8, std::internal << std::dec, 0x99, 2);
	STREAM_TEST_WIDTH(uint8, std::internal << std::hex, 0x99, 2);
	STREAM_TEST_WIDTH(uint8, std::internal << std::oct, 0x99, 2);

	STREAM_TEST_WIDTH(uint16, std::internal << std::dec, 0x001b, 2);
	STREAM_TEST_WIDTH(uint16, std::internal << std::hex, 0x001b, 2);
	STREAM_TEST_WIDTH(uint16, std::internal << std::oct, 0x001b, 2);

	STREAM_TEST_WIDTH(uint16, std::internal << std::dec, 0x0100, 2);
	STREAM_TEST_WIDTH(uint16, std::internal << std::hex, 0x0100, 2);
	STREAM_TEST_WIDTH(uint16, std::internal << std::oct, 0x0100, 2);

	STREAM_TEST_WIDTH(uint16, std::internal << std::dec, 0xab12, 2);
	STREAM_TEST_WIDTH(uint16, std::internal << std::hex, 0xab12, 2);
	STREAM_TEST_WIDTH(uint16, std::internal << std::oct, 0xab12, 2);

	STREAM_TEST_WIDTH(uint32, std::internal << std::dec, 0x00ab1200, 2);
	STREAM_TEST_WIDTH(uint32, std::internal << std::hex, 0x00ab1200, 2);
	STREAM_TEST_WIDTH(uint32, std::internal << std::oct, 0x00ab1200, 2);

	STREAM_TEST_WIDTH(uint32, std::internal << std::dec, 0x0ab12000, 2);
	STREAM_TEST_WIDTH(uint32, std::internal << std::hex, 0x0ab12000, 2);
	STREAM_TEST_WIDTH(uint32, std::internal << std::oct, 0x0ab12000, 2);

	STREAM_TEST_WIDTH(uint32, std::internal << std::dec, 0x01000200, 2);
	STREAM_TEST_WIDTH(uint32, std::internal << std::hex, 0x01000200, 2);
	STREAM_TEST_WIDTH(uint32, std::internal << std::oct, 0x01000200, 2);

	STREAM_TEST_WIDTH(uint32, std::internal << std::dec, 0x00001100, 2);
	STREAM_TEST_WIDTH(uint32, std::internal << std::hex, 0x00001100, 2);
	STREAM_TEST_WIDTH(uint32, std::internal << std::oct, 0x00001100, 2);

	STREAM_TEST_WIDTH(uint32, std::internal << std::dec, 1000, 2);
	STREAM_TEST_WIDTH(uint32, std::internal << std::hex, 1000, 2);
	STREAM_TEST_WIDTH(uint32, std::internal << std::oct, 1000, 2);

	STREAM_TEST_WIDTH(uint32, std::internal << std::dec, 01000, 2);
	STREAM_TEST_WIDTH(uint32, std::internal << std::hex, 01000, 2);
	STREAM_TEST_WIDTH(uint32, std::internal << std::oct, 01000, 2);
}

TEST(StreamAlign, LeftShort)
{
	STREAM_TEST_WIDTH(uint8, std::left << std::dec, 0x00, 2);
	STREAM_TEST_WIDTH(uint8, std::left << std::hex, 0x00, 2);
	STREAM_TEST_WIDTH(uint8, std::left << std::oct, 0x00, 2);

	STREAM_TEST_WIDTH(uint8, std::left << std::dec, 0x01, 2);
	STREAM_TEST_WIDTH(uint8, std::left << std::hex, 0x01, 2);
	STREAM_TEST_WIDTH(uint8, std::left << std::oct, 0x01, 2);

	STREAM_TEST_WIDTH(uint8, std::left << std::dec, 0x12, 2);
	STREAM_TEST_WIDTH(uint8, std::left << std::hex, 0x12, 2);
	STREAM_TEST_WIDTH(uint8, std::left << std::oct, 0x12, 2);

	STREAM_TEST_WIDTH(uint8, std::left << std::dec, 0x99, 2);
	STREAM_TEST_WIDTH(uint8, std::left << std::hex, 0x99, 2);
	STREAM_TEST_WIDTH(uint8, std::left << std::oct, 0x99, 2);

	STREAM_TEST_WIDTH(uint16, std::left << std::dec, 0x001b, 2);
	STREAM_TEST_WIDTH(uint16, std::left << std::hex, 0x001b, 2);
	STREAM_TEST_WIDTH(uint16, std::left << std::oct, 0x001b, 2);

	STREAM_TEST_WIDTH(uint16, std::left << std::dec, 0x0100, 2);
	STREAM_TEST_WIDTH(uint16, std::left << std::hex, 0x0100, 2);
	STREAM_TEST_WIDTH(uint16, std::left << std::oct, 0x0100, 2);

	STREAM_TEST_WIDTH(uint16, std::left << std::dec, 0xab12, 2);
	STREAM_TEST_WIDTH(uint16, std::left << std::hex, 0xab12, 2);
	STREAM_TEST_WIDTH(uint16, std::left << std::oct, 0xab12, 2);

	STREAM_TEST_WIDTH(uint32, std::left << std::dec, 0x00ab1200, 2);
	STREAM_TEST_WIDTH(uint32, std::left << std::hex, 0x00ab1200, 2);
	STREAM_TEST_WIDTH(uint32, std::left << std::oct, 0x00ab1200, 2);

	STREAM_TEST_WIDTH(uint32, std::left << std::dec, 0x0ab12000, 2);
	STREAM_TEST_WIDTH(uint32, std::left << std::hex, 0x0ab12000, 2);
	STREAM_TEST_WIDTH(uint32, std::left << std::oct, 0x0ab12000, 2);

	STREAM_TEST_WIDTH(uint32, std::left << std::dec, 0x01000200, 2);
	STREAM_TEST_WIDTH(uint32, std::left << std::hex, 0x01000200, 2);
	STREAM_TEST_WIDTH(uint32, std::left << std::oct, 0x01000200, 2);

	STREAM_TEST_WIDTH(uint32, std::left << std::dec, 0x00001100, 2);
	STREAM_TEST_WIDTH(uint32, std::left << std::hex, 0x00001100, 2);
	STREAM_TEST_WIDTH(uint32, std::left << std::oct, 0x00001100, 2);

	STREAM_TEST_WIDTH(uint32, std::left << std::dec, 1000, 2);
	STREAM_TEST_WIDTH(uint32, std::left << std::hex, 1000, 2);
	STREAM_TEST_WIDTH(uint32, std::left << std::oct, 1000, 2);

	STREAM_TEST_WIDTH(uint32, std::left << std::dec, 01000, 2);
	STREAM_TEST_WIDTH(uint32, std::left << std::hex, 01000, 2);
	STREAM_TEST_WIDTH(uint32, std::left << std::oct, 01000, 2);
}

TEST(StreamAlign, RightShort)
{
	STREAM_TEST_WIDTH(uint8, std::right << std::dec, 0x00, 2);
	STREAM_TEST_WIDTH(uint8, std::right << std::hex, 0x00, 2);
	STREAM_TEST_WIDTH(uint8, std::right << std::oct, 0x00, 2);

	STREAM_TEST_WIDTH(uint8, std::right << std::dec, 0x01, 2);
	STREAM_TEST_WIDTH(uint8, std::right << std::hex, 0x01, 2);
	STREAM_TEST_WIDTH(uint8, std::right << std::oct, 0x01, 2);

	STREAM_TEST_WIDTH(uint8, std::right << std::dec, 0x12, 2);
	STREAM_TEST_WIDTH(uint8, std::right << std::hex, 0x12, 2);
	STREAM_TEST_WIDTH(uint8, std::right << std::oct, 0x12, 2);

	STREAM_TEST_WIDTH(uint8, std::right << std::dec, 0x99, 2);
	STREAM_TEST_WIDTH(uint8, std::right << std::hex, 0x99, 2);
	STREAM_TEST_WIDTH(uint8, std::right << std::oct, 0x99, 2);

	STREAM_TEST_WIDTH(uint16, std::right << std::dec, 0x001b, 2);
	STREAM_TEST_WIDTH(uint16, std::right << std::hex, 0x001b, 2);
	STREAM_TEST_WIDTH(uint16, std::right << std::oct, 0x001b, 2);

	STREAM_TEST_WIDTH(uint16, std::right << std::dec, 0x0100, 2);
	STREAM_TEST_WIDTH(uint16, std::right << std::hex, 0x0100, 2);
	STREAM_TEST_WIDTH(uint16, std::right << std::oct, 0x0100, 2);

	STREAM_TEST_WIDTH(uint16, std::right << std::dec, 0xab12, 2);
	STREAM_TEST_WIDTH(uint16, std::right << std::hex, 0xab12, 2);
	STREAM_TEST_WIDTH(uint16, std::right << std::oct, 0xab12, 2);

	STREAM_TEST_WIDTH(uint32, std::right << std::dec, 0x00ab1200, 2);
	STREAM_TEST_WIDTH(uint32, std::right << std::hex, 0x00ab1200, 2);
	STREAM_TEST_WIDTH(uint32, std::right << std::oct, 0x00ab1200, 2);

	STREAM_TEST_WIDTH(uint32, std::right << std::dec, 0x0ab12000, 2);
	STREAM_TEST_WIDTH(uint32, std::right << std::hex, 0x0ab12000, 2);
	STREAM_TEST_WIDTH(uint32, std::right << std::oct, 0x0ab12000, 2);

	STREAM_TEST_WIDTH(uint32, std::right << std::dec, 0x01000200, 2);
	STREAM_TEST_WIDTH(uint32, std::right << std::hex, 0x01000200, 2);
	STREAM_TEST_WIDTH(uint32, std::right << std::oct, 0x01000200, 2);

	STREAM_TEST_WIDTH(uint32, std::right << std::dec, 0x00001100, 2);
	STREAM_TEST_WIDTH(uint32, std::right << std::hex, 0x00001100, 2);
	STREAM_TEST_WIDTH(uint32, std::right << std::oct, 0x00001100, 2);

	STREAM_TEST_WIDTH(uint32, std::right << std::dec, 1000, 2);
	STREAM_TEST_WIDTH(uint32, std::right << std::hex, 1000, 2);
	STREAM_TEST_WIDTH(uint32, std::right << std::oct, 1000, 2);

	STREAM_TEST_WIDTH(uint32, std::right << std::dec, 01000, 2);
	STREAM_TEST_WIDTH(uint32, std::right << std::hex, 01000, 2);
	STREAM_TEST_WIDTH(uint32, std::right << std::oct, 01000, 2);
}

TEST(StreamAlign, InternalWithBaseShort)
{
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::dec, 0x00, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::hex, 0x00, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::oct, 0x00, 2);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::dec, 0x01, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::hex, 0x01, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::oct, 0x01, 2);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::dec, 0x12, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::hex, 0x12, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::oct, 0x12, 2);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::dec, 0x99, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::hex, 0x99, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::internal << std::oct, 0x99, 2);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::dec, 0x001b, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::hex, 0x001b, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::oct, 0x001b, 2);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::dec, 0x0100, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::hex, 0x0100, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::oct, 0x0100, 2);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::dec, 0xab12, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::hex, 0xab12, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::internal << std::oct, 0xab12, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::dec, 0x00ab1200, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::hex, 0x00ab1200, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::oct, 0x00ab1200, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::dec, 0x0ab12000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::hex, 0x0ab12000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::oct, 0x0ab12000, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::dec, 0x01000200, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::hex, 0x01000200, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::oct, 0x01000200, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::dec, 0x00001100, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::hex, 0x00001100, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::oct, 0x00001100, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::dec, 1000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::hex, 1000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::oct, 1000, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::dec, 01000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::hex, 01000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::internal << std::oct, 01000, 2);
}


TEST(StreamAlign, LeftWithBaseShort)
{
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::dec, 0x00, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::hex, 0x00, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::oct, 0x00, 2);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::dec, 0x01, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::hex, 0x01, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::oct, 0x01, 2);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::dec, 0x12, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::hex, 0x12, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::oct, 0x12, 2);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::dec, 0x99, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::hex, 0x99, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::left << std::oct, 0x99, 2);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::dec, 0x001b, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::hex, 0x001b, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::oct, 0x001b, 2);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::dec, 0x0100, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::hex, 0x0100, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::oct, 0x0100, 2);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::dec, 0xab12, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::hex, 0xab12, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::left << std::oct, 0xab12, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::dec, 0x00ab1200, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::hex, 0x00ab1200, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::oct, 0x00ab1200, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::dec, 0x0ab12000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::hex, 0x0ab12000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::oct, 0x0ab12000, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::dec, 0x01000200, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::hex, 0x01000200, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::oct, 0x01000200, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::dec, 0x00001100, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::hex, 0x00001100, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::oct, 0x00001100, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::dec, 1000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::hex, 1000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::oct, 1000, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::dec, 01000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::hex, 01000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::left << std::oct, 01000, 2);
}

TEST(StreamAlign, RightWithBaseShort)
{
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::dec, 0x00, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::hex, 0x00, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::oct, 0x00, 2);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::dec, 0x01, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::hex, 0x01, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::oct, 0x01, 2);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::dec, 0x12, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::hex, 0x12, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::oct, 0x12, 2);

	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::dec, 0x99, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::hex, 0x99, 2);
	STREAM_TEST_WIDTH(uint8, std::showbase << std::showpos << std::right << std::oct, 0x99, 2);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::dec, 0x001b, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::hex, 0x001b, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::oct, 0x001b, 2);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::dec, 0x0100, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::hex, 0x0100, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::oct, 0x0100, 2);

	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::dec, 0xab12, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::hex, 0xab12, 2);
	STREAM_TEST_WIDTH(uint16, std::showbase << std::showpos << std::right << std::oct, 0xab12, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::dec, 0x00ab1200, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::hex, 0x00ab1200, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::oct, 0x00ab1200, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::dec, 0x0ab12000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::hex, 0x0ab12000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::oct, 0x0ab12000, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::dec, 0x01000200, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::hex, 0x01000200, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::oct, 0x01000200, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::dec, 0x00001100, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::hex, 0x00001100, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::oct, 0x00001100, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::dec, 1000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::hex, 1000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::oct, 1000, 2);

	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::dec, 01000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::hex, 01000, 2);
	STREAM_TEST_WIDTH(uint32, std::showbase << std::showpos << std::right << std::oct, 01000, 2);
}

#define STREAM_TEST_WIDTH_FILL(type, mod, x, len, c) {std::stringstream buff1, buff2; buff1.width(len); buff2.width(len); buff1.fill(c); buff2.fill(c); buff1 << mod << type(x); buff2 << mod << x; EXPECT_EQ(buff2.str(), buff1.str()); }


TEST(StreamAlign, InternalFill)
{
	STREAM_TEST_WIDTH_FILL(uint8, std::internal << std::dec, 0x00, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::internal << std::hex, 0x00, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::internal << std::oct, 0x00, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::internal << std::dec, 0x01, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::internal << std::hex, 0x01, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::internal << std::oct, 0x01, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::internal << std::dec, 0x12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::internal << std::hex, 0x12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::internal << std::oct, 0x12, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::internal << std::dec, 0x99, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::internal << std::hex, 0x99, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::internal << std::oct, 0x99, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::internal << std::dec, 0x001b, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::internal << std::hex, 0x001b, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::internal << std::oct, 0x001b, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::internal << std::dec, 0x0100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::internal << std::hex, 0x0100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::internal << std::oct, 0x0100, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::internal << std::dec, 0xab12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::internal << std::hex, 0xab12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::internal << std::oct, 0xab12, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::dec, 0x00ab1200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::hex, 0x00ab1200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::oct, 0x00ab1200, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::dec, 0x0ab12000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::hex, 0x0ab12000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::oct, 0x0ab12000, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::dec, 0x01000200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::hex, 0x01000200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::oct, 0x01000200, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::dec, 0x00001100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::hex, 0x00001100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::oct, 0x00001100, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::dec, 1000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::hex, 1000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::oct, 1000, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::dec, 01000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::hex, 01000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::internal << std::oct, 01000, 16, '?');
}

TEST(StreamAlign, LeftFill)
{
	STREAM_TEST_WIDTH_FILL(uint8, std::left << std::dec, 0x00, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::left << std::hex, 0x00, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::left << std::oct, 0x00, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::left << std::dec, 0x01, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::left << std::hex, 0x01, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::left << std::oct, 0x01, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::left << std::dec, 0x12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::left << std::hex, 0x12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::left << std::oct, 0x12, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::left << std::dec, 0x99, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::left << std::hex, 0x99, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::left << std::oct, 0x99, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::left << std::dec, 0x001b, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::left << std::hex, 0x001b, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::left << std::oct, 0x001b, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::left << std::dec, 0x0100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::left << std::hex, 0x0100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::left << std::oct, 0x0100, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::left << std::dec, 0xab12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::left << std::hex, 0xab12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::left << std::oct, 0xab12, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::dec, 0x00ab1200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::hex, 0x00ab1200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::oct, 0x00ab1200, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::dec, 0x0ab12000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::hex, 0x0ab12000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::oct, 0x0ab12000, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::dec, 0x01000200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::hex, 0x01000200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::oct, 0x01000200, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::dec, 0x00001100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::hex, 0x00001100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::oct, 0x00001100, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::dec, 1000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::hex, 1000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::oct, 1000, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::dec, 01000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::hex, 01000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::left << std::oct, 01000, 16, '?');
}

TEST(StreamAlign, RightFill)
{
	STREAM_TEST_WIDTH_FILL(uint8, std::right << std::dec, 0x00, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::right << std::hex, 0x00, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::right << std::oct, 0x00, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::right << std::dec, 0x01, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::right << std::hex, 0x01, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::right << std::oct, 0x01, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::right << std::dec, 0x12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::right << std::hex, 0x12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::right << std::oct, 0x12, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::right << std::dec, 0x99, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::right << std::hex, 0x99, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::right << std::oct, 0x99, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::right << std::dec, 0x001b, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::right << std::hex, 0x001b, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::right << std::oct, 0x001b, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::right << std::dec, 0x0100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::right << std::hex, 0x0100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::right << std::oct, 0x0100, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::right << std::dec, 0xab12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::right << std::hex, 0xab12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::right << std::oct, 0xab12, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::dec, 0x00ab1200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::hex, 0x00ab1200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::oct, 0x00ab1200, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::dec, 0x0ab12000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::hex, 0x0ab12000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::oct, 0x0ab12000, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::dec, 0x01000200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::hex, 0x01000200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::oct, 0x01000200, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::dec, 0x00001100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::hex, 0x00001100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::oct, 0x00001100, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::dec, 1000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::hex, 1000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::oct, 1000, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::dec, 01000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::hex, 01000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::right << std::oct, 01000, 16, '?');
}

TEST(StreamAlign, InternalWithBaseFill)
{
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::internal << std::dec, 0x00, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::internal << std::hex, 0x00, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::internal << std::oct, 0x00, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::internal << std::dec, 0x01, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::internal << std::hex, 0x01, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::internal << std::oct, 0x01, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::internal << std::dec, 0x12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::internal << std::hex, 0x12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::internal << std::oct, 0x12, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::internal << std::dec, 0x99, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::internal << std::hex, 0x99, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::internal << std::oct, 0x99, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::internal << std::dec, 0x001b, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::internal << std::hex, 0x001b, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::internal << std::oct, 0x001b, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::internal << std::dec, 0x0100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::internal << std::hex, 0x0100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::internal << std::oct, 0x0100, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::internal << std::dec, 0xab12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::internal << std::hex, 0xab12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::internal << std::oct, 0xab12, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::dec, 0x00ab1200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::hex, 0x00ab1200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::oct, 0x00ab1200, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::dec, 0x0ab12000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::hex, 0x0ab12000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::oct, 0x0ab12000, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::dec, 0x01000200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::hex, 0x01000200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::oct, 0x01000200, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::dec, 0x00001100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::hex, 0x00001100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::oct, 0x00001100, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::dec, 1000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::hex, 1000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::oct, 1000, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::dec, 01000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::hex, 01000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::internal << std::oct, 01000, 16, '?');
}


TEST(StreamAlign, LeftWithBaseFill)
{
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::left << std::dec, 0x00, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::left << std::hex, 0x00, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::left << std::oct, 0x00, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::left << std::dec, 0x01, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::left << std::hex, 0x01, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::left << std::oct, 0x01, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::left << std::dec, 0x12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::left << std::hex, 0x12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::left << std::oct, 0x12, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::left << std::dec, 0x99, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::left << std::hex, 0x99, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::left << std::oct, 0x99, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::left << std::dec, 0x001b, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::left << std::hex, 0x001b, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::left << std::oct, 0x001b, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::left << std::dec, 0x0100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::left << std::hex, 0x0100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::left << std::oct, 0x0100, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::left << std::dec, 0xab12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::left << std::hex, 0xab12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::left << std::oct, 0xab12, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::dec, 0x00ab1200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::hex, 0x00ab1200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::oct, 0x00ab1200, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::dec, 0x0ab12000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::hex, 0x0ab12000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::oct, 0x0ab12000, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::dec, 0x01000200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::hex, 0x01000200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::oct, 0x01000200, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::dec, 0x00001100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::hex, 0x00001100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::oct, 0x00001100, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::dec, 1000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::hex, 1000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::oct, 1000, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::dec, 01000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::hex, 01000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::left << std::oct, 01000, 16, '?');
}
TEST(StreamAlign, RightWithBaseFill)
{
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::right << std::dec, 0x00, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::right << std::hex, 0x00, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::right << std::oct, 0x00, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::right << std::dec, 0x01, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::right << std::hex, 0x01, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::right << std::oct, 0x01, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::right << std::dec, 0x12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::right << std::hex, 0x12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::right << std::oct, 0x12, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::right << std::dec, 0x99, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::right << std::hex, 0x99, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint8, std::showbase << std::showpos << std::right << std::oct, 0x99, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::right << std::dec, 0x001b, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::right << std::hex, 0x001b, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::right << std::oct, 0x001b, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::right << std::dec, 0x0100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::right << std::hex, 0x0100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::right << std::oct, 0x0100, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::right << std::dec, 0xab12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::right << std::hex, 0xab12, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint16, std::showbase << std::showpos << std::right << std::oct, 0xab12, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::dec, 0x00ab1200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::hex, 0x00ab1200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::oct, 0x00ab1200, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::dec, 0x0ab12000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::hex, 0x0ab12000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::oct, 0x0ab12000, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::dec, 0x01000200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::hex, 0x01000200, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::oct, 0x01000200, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::dec, 0x00001100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::hex, 0x00001100, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::oct, 0x00001100, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::dec, 1000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::hex, 1000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::oct, 1000, 16, '?');

	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::dec, 01000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::hex, 01000, 16, '?');
	STREAM_TEST_WIDTH_FILL(uint32, std::showbase << std::showpos << std::right << std::oct, 01000, 16, '?');
}

#define STREAM_TEST_READ(type, x) { std::stringstream buff1(#x), buff2(#x); type v1; int v2; buff1 >> v1; buff2 >> v2; EXPECT_EQ(v2, v1); }

TEST(StreamRead, Basic)
{
	STREAM_TEST_READ(uint8, 0);
	STREAM_TEST_READ(uint8, 1);
	STREAM_TEST_READ(uint8, 2);
	STREAM_TEST_READ(uint8, 4);
	STREAM_TEST_READ(uint8, 32);
	STREAM_TEST_READ(uint8, 50);

	STREAM_TEST_READ(uint8, 0x00);
	STREAM_TEST_READ(uint8, 0x01);
	STREAM_TEST_READ(uint8, 0x01);
	STREAM_TEST_READ(uint8, 0x12);
	STREAM_TEST_READ(uint8, 0x10);

	STREAM_TEST_READ(uint8, 00);
	STREAM_TEST_READ(uint8, 01);
	STREAM_TEST_READ(uint8, 02);
	STREAM_TEST_READ(uint8, 04);
	STREAM_TEST_READ(uint8, 032);
	STREAM_TEST_READ(uint8, 050);

	STREAM_TEST_READ(uint32, 0);
	STREAM_TEST_READ(uint32, 1);
	STREAM_TEST_READ(uint32, 2);
	STREAM_TEST_READ(uint32, 4);
	STREAM_TEST_READ(uint32, 32);
	STREAM_TEST_READ(uint32, 50);
	STREAM_TEST_READ(uint32, 8080);
	STREAM_TEST_READ(uint32, 60000);
	STREAM_TEST_READ(uint32, 1000000000);

	STREAM_TEST_READ(uint32, 0x00);
	STREAM_TEST_READ(uint32, 0x01);
	STREAM_TEST_READ(uint32, 0x01);
	STREAM_TEST_READ(uint32, 0x12);
	STREAM_TEST_READ(uint32, 0x10);
	STREAM_TEST_READ(uint32, 0x8080);
	STREAM_TEST_READ(uint32, 0x60000);
	STREAM_TEST_READ(uint32, 0x1000000000);

	STREAM_TEST_READ(uint32, 00);
	STREAM_TEST_READ(uint32, 01);
	STREAM_TEST_READ(uint32, 02);
	STREAM_TEST_READ(uint32, 04);
	STREAM_TEST_READ(uint32, 032);
	STREAM_TEST_READ(uint32, 050);
	STREAM_TEST_READ(uint32, 08080);
	STREAM_TEST_READ(uint32, 060000);
	STREAM_TEST_READ(uint32, 01000000000);
}

#define STREAM_TEST_READ_MOD(type, mod, x) { std::stringstream buff1(#x), buff2(#x); type v1; int v2; buff1 >> mod >> v1; buff2 >> mod >> v2; EXPECT_EQ(v2, v1); }

TEST(StreamRead, ModDec)
{
	STREAM_TEST_READ_MOD(uint8, std::dec, 0);
	STREAM_TEST_READ_MOD(uint8, std::dec, 1);
	STREAM_TEST_READ_MOD(uint8, std::dec, 2);
	STREAM_TEST_READ_MOD(uint8, std::dec, 4);
	STREAM_TEST_READ_MOD(uint8, std::dec, 32);
	STREAM_TEST_READ_MOD(uint8, std::dec, 50);

	STREAM_TEST_READ_MOD(uint8, std::dec, 0x00);
	STREAM_TEST_READ_MOD(uint8, std::dec, 0x01);
	STREAM_TEST_READ_MOD(uint8, std::dec, 0x01);
	STREAM_TEST_READ_MOD(uint8, std::dec, 0x12);
	STREAM_TEST_READ_MOD(uint8, std::dec, 0x10);

	STREAM_TEST_READ_MOD(uint8, std::dec, 00);
	STREAM_TEST_READ_MOD(uint8, std::dec, 01);
	STREAM_TEST_READ_MOD(uint8, std::dec, 02);
	STREAM_TEST_READ_MOD(uint8, std::dec, 04);
	STREAM_TEST_READ_MOD(uint8, std::dec, 032);
	STREAM_TEST_READ_MOD(uint8, std::dec, 050);

	STREAM_TEST_READ_MOD(uint32, std::dec, 0);
	STREAM_TEST_READ_MOD(uint32, std::dec, 1);
	STREAM_TEST_READ_MOD(uint32, std::dec, 2);
	STREAM_TEST_READ_MOD(uint32, std::dec, 4);
	STREAM_TEST_READ_MOD(uint32, std::dec, 32);
	STREAM_TEST_READ_MOD(uint32, std::dec, 50);
	STREAM_TEST_READ_MOD(uint32, std::dec, 8080);
	STREAM_TEST_READ_MOD(uint32, std::dec, 60000);
	STREAM_TEST_READ_MOD(uint32, std::dec, 1000000000);

	STREAM_TEST_READ_MOD(uint32, std::dec, 0x00);
	STREAM_TEST_READ_MOD(uint32, std::dec, 0x01);
	STREAM_TEST_READ_MOD(uint32, std::dec, 0x01);
	STREAM_TEST_READ_MOD(uint32, std::dec, 0x12);
	STREAM_TEST_READ_MOD(uint32, std::dec, 0x10);
	STREAM_TEST_READ_MOD(uint32, std::dec, 0x8080);
	STREAM_TEST_READ_MOD(uint32, std::dec, 0x60000);
	STREAM_TEST_READ_MOD(uint32, std::dec, 0x1000000000);

	STREAM_TEST_READ_MOD(uint32, std::dec, 00);
	STREAM_TEST_READ_MOD(uint32, std::dec, 01);
	STREAM_TEST_READ_MOD(uint32, std::dec, 02);
	STREAM_TEST_READ_MOD(uint32, std::dec, 04);
	STREAM_TEST_READ_MOD(uint32, std::dec, 032);
	STREAM_TEST_READ_MOD(uint32, std::dec, 050);
	STREAM_TEST_READ_MOD(uint32, std::dec, 08080);
	STREAM_TEST_READ_MOD(uint32, std::dec, 060000);
	STREAM_TEST_READ_MOD(uint32, std::dec, 01000000000);
}
TEST(StreamRead, ModOct)
{
	STREAM_TEST_READ_MOD(uint8, std::oct, 0);
	STREAM_TEST_READ_MOD(uint8, std::oct, 1);
	STREAM_TEST_READ_MOD(uint8, std::oct, 2);
	STREAM_TEST_READ_MOD(uint8, std::oct, 4);
	STREAM_TEST_READ_MOD(uint8, std::oct, 32);
	STREAM_TEST_READ_MOD(uint8, std::oct, 50);

	STREAM_TEST_READ_MOD(uint8, std::oct, 0x00);
	STREAM_TEST_READ_MOD(uint8, std::oct, 0x01);
	STREAM_TEST_READ_MOD(uint8, std::oct, 0x01);
	STREAM_TEST_READ_MOD(uint8, std::oct, 0x12);
	STREAM_TEST_READ_MOD(uint8, std::oct, 0x10);

	STREAM_TEST_READ_MOD(uint8, std::oct, 00);
	STREAM_TEST_READ_MOD(uint8, std::oct, 01);
	STREAM_TEST_READ_MOD(uint8, std::oct, 02);
	STREAM_TEST_READ_MOD(uint8, std::oct, 04);
	STREAM_TEST_READ_MOD(uint8, std::oct, 032);
	STREAM_TEST_READ_MOD(uint8, std::oct, 050);

	STREAM_TEST_READ_MOD(uint32, std::oct, 0);
	STREAM_TEST_READ_MOD(uint32, std::oct, 1);
	STREAM_TEST_READ_MOD(uint32, std::oct, 2);
	STREAM_TEST_READ_MOD(uint32, std::oct, 4);
	STREAM_TEST_READ_MOD(uint32, std::oct, 32);
	STREAM_TEST_READ_MOD(uint32, std::oct, 50);
	STREAM_TEST_READ_MOD(uint32, std::oct, 7070);
	STREAM_TEST_READ_MOD(uint32, std::oct, 60000);
	STREAM_TEST_READ_MOD(uint32, std::oct, 100000000);

	STREAM_TEST_READ_MOD(uint32, std::oct, 0x00);
	STREAM_TEST_READ_MOD(uint32, std::oct, 0x01);
	STREAM_TEST_READ_MOD(uint32, std::oct, 0x01);
	STREAM_TEST_READ_MOD(uint32, std::oct, 0x12);
	STREAM_TEST_READ_MOD(uint32, std::oct, 0x10);
	STREAM_TEST_READ_MOD(uint32, std::oct, 0x7070);
	STREAM_TEST_READ_MOD(uint32, std::oct, 0x60000);
	STREAM_TEST_READ_MOD(uint32, std::oct, 0x100000000);

	STREAM_TEST_READ_MOD(uint32, std::oct, 00);
	STREAM_TEST_READ_MOD(uint32, std::oct, 01);
	STREAM_TEST_READ_MOD(uint32, std::oct, 02);
	STREAM_TEST_READ_MOD(uint32, std::oct, 04);
	STREAM_TEST_READ_MOD(uint32, std::oct, 032);
	STREAM_TEST_READ_MOD(uint32, std::oct, 050);
	STREAM_TEST_READ_MOD(uint32, std::oct, 07070);
	STREAM_TEST_READ_MOD(uint32, std::oct, 060000);
	STREAM_TEST_READ_MOD(uint32, std::oct, 0100000000);
}
TEST(StreamRead, ModHex)
{
	STREAM_TEST_READ_MOD(uint8, std::hex, 0);
	STREAM_TEST_READ_MOD(uint8, std::hex, 1);
	STREAM_TEST_READ_MOD(uint8, std::hex, 2);
	STREAM_TEST_READ_MOD(uint8, std::hex, 4);
	STREAM_TEST_READ_MOD(uint8, std::hex, 32);
	STREAM_TEST_READ_MOD(uint8, std::hex, 50);

	STREAM_TEST_READ_MOD(uint8, std::hex, 0x00);
	STREAM_TEST_READ_MOD(uint8, std::hex, 0x01);
	STREAM_TEST_READ_MOD(uint8, std::hex, 0x01);
	STREAM_TEST_READ_MOD(uint8, std::hex, 0x12);
	STREAM_TEST_READ_MOD(uint8, std::hex, 0x10);

	STREAM_TEST_READ_MOD(uint8, std::hex, 00);
	STREAM_TEST_READ_MOD(uint8, std::hex, 01);
	STREAM_TEST_READ_MOD(uint8, std::hex, 02);
	STREAM_TEST_READ_MOD(uint8, std::hex, 04);
	STREAM_TEST_READ_MOD(uint8, std::hex, 032);
	STREAM_TEST_READ_MOD(uint8, std::hex, 050);

	STREAM_TEST_READ_MOD(uint32, std::hex, 0);
	STREAM_TEST_READ_MOD(uint32, std::hex, 1);
	STREAM_TEST_READ_MOD(uint32, std::hex, 2);
	STREAM_TEST_READ_MOD(uint32, std::hex, 4);
	STREAM_TEST_READ_MOD(uint32, std::hex, 32);
	STREAM_TEST_READ_MOD(uint32, std::hex, 50);
	STREAM_TEST_READ_MOD(uint32, std::hex, 8080);
	STREAM_TEST_READ_MOD(uint32, std::hex, 60000);
	STREAM_TEST_READ_MOD(uint32, std::hex, 100000);

	STREAM_TEST_READ_MOD(uint32, std::hex, 0x00);
	STREAM_TEST_READ_MOD(uint32, std::hex, 0x01);
	STREAM_TEST_READ_MOD(uint32, std::hex, 0x01);
	STREAM_TEST_READ_MOD(uint32, std::hex, 0x12);
	STREAM_TEST_READ_MOD(uint32, std::hex, 0x10);
	STREAM_TEST_READ_MOD(uint32, std::hex, 0x8080);
	STREAM_TEST_READ_MOD(uint32, std::hex, 0x60000);
	STREAM_TEST_READ_MOD(uint32, std::hex, 0x100000);

	STREAM_TEST_READ_MOD(uint32, std::hex, 00);
	STREAM_TEST_READ_MOD(uint32, std::hex, 01);
	STREAM_TEST_READ_MOD(uint32, std::hex, 02);
	STREAM_TEST_READ_MOD(uint32, std::hex, 04);
	STREAM_TEST_READ_MOD(uint32, std::hex, 032);
	STREAM_TEST_READ_MOD(uint32, std::hex, 050);
	STREAM_TEST_READ_MOD(uint32, std::hex, 08080);
	STREAM_TEST_READ_MOD(uint32, std::hex, 060000);
	STREAM_TEST_READ_MOD(uint32, std::hex, 0100000);
}