#pragma once
#include <cstdint>
#include <string>

enum class ByteUnit : uint8_t {
	// One kilobyte is equal to 1000 bytes.
	Decimal,
	// One kilobyte is equal to 1024 bytes.
	Binary
};

enum class BytePrefix : uint8_t {
	Metric,
	IEC,
	JEDEC
};

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

	double Kilobits() const;
	double Megabits() const;
	double Gigabits() const;
	double Terabits() const;
	double Petabits() const;

	std::string LargestByteUnitSymbol() const;
	double LargestByteUnitValue() const;
	std::string LargestBitUnitSymbol() const;
	double LargestBitUnitValue() const;

	std::string ToString(unsigned int precision = 1) const;
	
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
	static ByteSize FromKilobits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);
	static ByteSize FromMegabits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);
	static ByteSize FromGigabits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);
	static ByteSize FromTerabits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);
	static ByteSize FromPetabits(double size, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);

	static double BitsInByte(ByteUnit unit = ByteUnit::Binary);

	static double BytesInKilobyte(ByteUnit unit = ByteUnit::Binary);
	static double BytesInMegabyte(ByteUnit unit = ByteUnit::Binary);
	static double BytesInGigabyte(ByteUnit unit = ByteUnit::Binary);
	static double BytesInTerabyte(ByteUnit unit = ByteUnit::Binary);
	static double BytesInPetabyte(ByteUnit unit = ByteUnit::Binary);

	static double BytesInKilobit(ByteUnit unit = ByteUnit::Binary);
	static double BytesInMegabit(ByteUnit unit = ByteUnit::Binary);
	static double BytesInGigabit(ByteUnit unit = ByteUnit::Binary);
	static double BytesInTerabit(ByteUnit unit = ByteUnit::Binary);
	static double BytesInPetabit(ByteUnit unit = ByteUnit::Binary);
	
	static std::string BitSymbol(BytePrefix prefix = BytePrefix::IEC);
	static std::string ByteSymbol(BytePrefix prefix = BytePrefix::IEC);
	
	static std::string KilobyteSymbol(BytePrefix prefix = BytePrefix::IEC);
	static std::string MegabyteSymbol(BytePrefix prefix = BytePrefix::IEC);
	static std::string GigabyteSymbol(BytePrefix prefix = BytePrefix::IEC);
	static std::string TerabyteSymbol(BytePrefix prefix = BytePrefix::IEC);
	static std::string PetabyteSymbol(BytePrefix prefix = BytePrefix::IEC);

	static std::string KilobitSymbol(BytePrefix prefix = BytePrefix::IEC);
	static std::string MegabitSymbol(BytePrefix prefix = BytePrefix::IEC);
	static std::string GigabitSymbol(BytePrefix prefix = BytePrefix::IEC);
	static std::string TerabitSymbol(BytePrefix prefix = BytePrefix::IEC);
	static std::string PetabitSymbol(BytePrefix prefix = BytePrefix::IEC);
	
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