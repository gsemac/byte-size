#pragma once
#include "ByteSize.h"

class BitSize {

public:
	BitSize(double bytes, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);

	double Bits() const;
	double Bytes() const;

	double Kilobits() const;
	double Megabits() const;
	double Gigabits() const;
	double Terabits() const;
	double Petabits() const;

	std::string LargestUnitSymbol() const;
	double LargestUnitValue() const;

	void AddBits(double size);
	void AddBytes(double size);
	void AddKilobits(double size);
	void AddMegabits(double size);
	void AddGigabits(double size);
	void AddTerabits(double size);
	void AddPetabits(double size);

	std::string ToString(unsigned int precision = 1) const;

	static BitSize MinValue();
	static BitSize MaxValue();

	static BitSize Parse(const std::string& string);
	static BitSize Parse(const char* string);
	static bool TryParse(const std::string& string, BitSize& object);
	static bool TryParse(const char* string, BitSize& object);

	static BitSize FromBits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);
	static BitSize FromBytes(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);
	static BitSize FromKilobits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);
	static BitSize FromMegabits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);
	static BitSize FromGigabits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);
	static BitSize FromTerabits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);
	static BitSize FromPetabits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);

	static double BitsInByte(ByteUnit unit = ByteUnit::Binary);

	static double BytesInKilobit(ByteUnit unit = ByteUnit::Binary);
	static double BytesInMegabit(ByteUnit unit = ByteUnit::Binary);
	static double BytesInGigabit(ByteUnit unit = ByteUnit::Binary);
	static double BytesInTerabit(ByteUnit unit = ByteUnit::Binary);
	static double BytesInPetabit(ByteUnit unit = ByteUnit::Binary);

	static std::string BitSymbol(BytePrefix prefix = BytePrefix::IEC);
	static std::string ByteSymbol(BytePrefix prefix = BytePrefix::IEC);

	static std::string KilobitSymbol(BytePrefix prefix = BytePrefix::IEC);
	static std::string MegabitSymbol(BytePrefix prefix = BytePrefix::IEC);
	static std::string GigabitSymbol(BytePrefix prefix = BytePrefix::IEC);
	static std::string TerabitSymbol(BytePrefix prefix = BytePrefix::IEC);
	static std::string PetabitSymbol(BytePrefix prefix = BytePrefix::IEC);

	BitSize& operator+=(const BitSize& rhs);
	BitSize& operator-=(const BitSize& rhs);

	friend BitSize operator+(const BitSize& lhs, const BitSize& rhs);
	friend BitSize operator-(const BitSize& lhs, const BitSize& rhs);

private:
	ByteUnit _unit;
	BytePrefix _prefix;
	double _bytes;

};

bool operator==(const BitSize& lhs, const BitSize& rhs);
bool operator!=(const BitSize& lhs, const BitSize& rhs);
bool operator<(const BitSize& lhs, const BitSize& rhs);
bool operator<=(const BitSize& lhs, const BitSize& rhs);
bool operator>(const BitSize& lhs, const BitSize& rhs);
bool operator>=(const BitSize& lhs, const BitSize& rhs);
BitSize operator+(const BitSize& lhs, const BitSize& rhs);
BitSize operator-(const BitSize& lhs, const BitSize& rhs);