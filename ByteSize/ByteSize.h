#pragma once
#include <cstdint>
#include <string>

class ByteSize {

public:
	ByteSize(uint64_t bytes);

	uint64_t Bits() const;
	double Bytes() const;
	double Kilobytes() const;
	double Megabytes() const;
	double Gigabytes() const;
	double Terabytes() const;
	double Petabytes() const;

	static uint64_t BitsInByte();
	static uint64_t BytesInKilobyte();
	static uint64_t BytesInMegabyte();
	static uint64_t BytesInGigabyte();
	static uint64_t BytesInTerabyte();
	static uint64_t BytesInPetabyte();

	static std::string BitSymbol();
	static std::string ByteSymbol();
	static std::string KilobyteSymbol();
	static std::string MegabyteSymbol();
	static std::string GigabyteSymbol();
	static std::string TerabyteSymbol();
	static std::string PetabyteSymbol();

private:
	uint64_t _bytes;

};