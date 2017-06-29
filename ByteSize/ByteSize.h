#pragma once
#include "ByteSizeCommon.h"
#include <string>

namespace hvn3 {

	class ByteSize {

	public:
		ByteSize(double bytes, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);

		double Bits() const;
		double Bytes() const;

		double Kilobytes() const;
		double Megabytes() const;
		double Gigabytes() const;
		double Terabytes() const;
		double Petabytes() const;

		std::string LargestUnitSymbol() const;
		double LargestUnitValue() const;

		void AddBits(double size);
		void AddBytes(double size);
		void AddKilobytes(double size);
		void AddMegabytes(double size);
		void AddGigabytes(double size);
		void AddTerabytes(double size);
		void AddPetabytes(double size);

		std::string ToString(unsigned int precision = 3) const;

		static ByteSize MinValue();
		static ByteSize MaxValue();

		static ByteSize Parse(const std::string& string);
		static ByteSize Parse(const char* string);
		static bool TryParse(const std::string& string, ByteSize& object);
		static bool TryParse(const char* string, ByteSize& object);

		static ByteSize FromBits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);
		static ByteSize FromBytes(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);
		static ByteSize FromKilobytes(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);
		static ByteSize FromMegabytes(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);
		static ByteSize FromGigabytes(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);
		static ByteSize FromTerabytes(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);
		static ByteSize FromPetabytes(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);

		static double BitsInByte(ByteUnit unit = ByteUnit::Binary);
		static double BytesInKilobyte(ByteUnit unit = ByteUnit::Binary);
		static double BytesInMegabyte(ByteUnit unit = ByteUnit::Binary);
		static double BytesInGigabyte(ByteUnit unit = ByteUnit::Binary);
		static double BytesInTerabyte(ByteUnit unit = ByteUnit::Binary);
		static double BytesInPetabyte(ByteUnit unit = ByteUnit::Binary);

		static std::string BitSymbol(BytePrefix prefix = BytePrefix::IEC);
		static std::string ByteSymbol(BytePrefix prefix = BytePrefix::IEC);
		static std::string KilobyteSymbol(BytePrefix prefix = BytePrefix::IEC);
		static std::string MegabyteSymbol(BytePrefix prefix = BytePrefix::IEC);
		static std::string GigabyteSymbol(BytePrefix prefix = BytePrefix::IEC);
		static std::string TerabyteSymbol(BytePrefix prefix = BytePrefix::IEC);
		static std::string PetabyteSymbol(BytePrefix prefix = BytePrefix::IEC);

		ByteSize& operator+=(const ByteSize& rhs);
		ByteSize& operator-=(const ByteSize& rhs);

		friend ByteSize operator+(const ByteSize& lhs, const ByteSize& rhs);
		friend ByteSize operator-(const ByteSize& lhs, const ByteSize& rhs);

	private:
		ByteUnit _unit;
		BytePrefix _prefix;
		double _bytes;

	};

	bool operator==(const ByteSize& lhs, const ByteSize& rhs);
	bool operator!=(const ByteSize& lhs, const ByteSize& rhs);
	bool operator<(const ByteSize& lhs, const ByteSize& rhs);
	bool operator<=(const ByteSize& lhs, const ByteSize& rhs);
	bool operator>(const ByteSize& lhs, const ByteSize& rhs);
	bool operator>=(const ByteSize& lhs, const ByteSize& rhs);
	ByteSize operator+(const ByteSize& lhs, const ByteSize& rhs);
	ByteSize operator-(const ByteSize& lhs, const ByteSize& rhs);

}