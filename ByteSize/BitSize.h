#pragma once
#include "ByteSizeCommon.h"
#include <string>

namespace hvn3 {

	class BitSize {

	public:
		BitSize(double bytes, BytePrefix prefix = BytePrefix::Binary, ByteUnit unit = ByteUnit::IEC);

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

		std::string ToString(unsigned int precision = 2) const;

		static BitSize MinValue();
		static BitSize MaxValue();

		static BitSize Parse(const std::string& string);
		static BitSize Parse(const char* string);
		static bool TryParse(const std::string& string, BitSize& object);
		static bool TryParse(const char* string, BitSize& object);

		static BitSize FromBits(double size, BytePrefix prefix = BytePrefix::Binary, ByteUnit unit = ByteUnit::IEC);
		static BitSize FromBytes(double size, BytePrefix prefix = BytePrefix::Binary, ByteUnit unit = ByteUnit::IEC);
		static BitSize FromKilobits(double size, BytePrefix prefix = BytePrefix::Binary, ByteUnit unit = ByteUnit::IEC);
		static BitSize FromMegabits(double size, BytePrefix prefix = BytePrefix::Binary, ByteUnit unit = ByteUnit::IEC);
		static BitSize FromGigabits(double size, BytePrefix prefix = BytePrefix::Binary, ByteUnit unit = ByteUnit::IEC);
		static BitSize FromTerabits(double size, BytePrefix prefix = BytePrefix::Binary, ByteUnit unit = ByteUnit::IEC);
		static BitSize FromPetabits(double size, BytePrefix prefix = BytePrefix::Binary, ByteUnit unit = ByteUnit::IEC);

		static double BitsInByte(BytePrefix prefix = BytePrefix::Binary);

		static double BytesInKilobit(BytePrefix prefix = BytePrefix::Binary);
		static double BytesInMegabit(BytePrefix prefix = BytePrefix::Binary);
		static double BytesInGigabit(BytePrefix prefix = BytePrefix::Binary);
		static double BytesInTerabit(BytePrefix prefix = BytePrefix::Binary);
		static double BytesInPetabit(BytePrefix prefix = BytePrefix::Binary);

		static std::string BitSymbol(ByteUnit unit = ByteUnit::IEC);
		static std::string ByteSymbol(ByteUnit unit = ByteUnit::IEC);

		static std::string KilobitSymbol(ByteUnit unit = ByteUnit::IEC);
		static std::string MegabitSymbol(ByteUnit unit = ByteUnit::IEC);
		static std::string GigabitSymbol(ByteUnit unit = ByteUnit::IEC);
		static std::string TerabitSymbol(ByteUnit unit = ByteUnit::IEC);
		static std::string PetabitSymbol(ByteUnit unit = ByteUnit::IEC);

		BitSize& operator+=(const BitSize& rhs);
		BitSize& operator-=(const BitSize& rhs);

		friend BitSize operator+(const BitSize& lhs, const BitSize& rhs);
		friend BitSize operator-(const BitSize& lhs, const BitSize& rhs);

	private:
		BytePrefix _prefix;
		ByteUnit _unit;
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
	std::ostream& operator<<(std::ostream& lhs, const BitSize& rhs);

}