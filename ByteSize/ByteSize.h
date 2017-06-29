#pragma once
#include <cstdint>
#include <string>

enum class ByteUnit : uint8_t {
	Decimal,
	Binary
};

enum class BytePrefix : uint8_t {
	Metric,
	IEC,
	JEDEC
};

class ByteSize {

public:
	ByteSize(uint64_t bytes, ByteUnit unit = ByteUnit::Binary, BytePrefix prefix = BytePrefix::IEC);

	uint64_t Bits() const;
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

	static uint64_t BitsInByte(ByteUnit unit = ByteUnit::Binary);

	static uint64_t BytesInKilobyte(ByteUnit unit = ByteUnit::Binary);
	static uint64_t BytesInMegabyte(ByteUnit unit = ByteUnit::Binary);
	static uint64_t BytesInGigabyte(ByteUnit unit = ByteUnit::Binary);
	static uint64_t BytesInTerabyte(ByteUnit unit = ByteUnit::Binary);
	static uint64_t BytesInPetabyte(ByteUnit unit = ByteUnit::Binary);

	static uint64_t BytesInKilobit(ByteUnit unit = ByteUnit::Binary);
	static uint64_t BytesInMegabit(ByteUnit unit = ByteUnit::Binary);
	static uint64_t BytesInGigabit(ByteUnit unit = ByteUnit::Binary);
	static uint64_t BytesInTerabit(ByteUnit unit = ByteUnit::Binary);
	static uint64_t BytesInPetabit(ByteUnit unit = ByteUnit::Binary);
	
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
	
private:
	ByteUnit _unit;
	BytePrefix _prefix;
	uint8_t _bits;
	uint64_t _bytes;

};