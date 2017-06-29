# byte-size
A class for easily displaying byte quantities in different formats

`ByteSize` (and the accompanying class, `BitSize`) were inpsired by Omar's [ByteSize](https://github.com/omar/ByteSize) class for C#.

Use the `ByteSize` class to represent amounts in bytes, kilobytes, megabytes, gigabytes, and so on (up to petabytes):

```cpp
ByteSize bs(1024);
std::cout << bs.Bits(); // outputs 8192
std::cout << bs.Bytes(); // outputs 1024
std::cout << bs.Kilobytes(); // outputs 1
std::cout << bs; // outputs 1.00 KiB
```

By default, the binary prefix is used (`1 kilobyte` = `1024 bytes`). The decimal prefix can be used by providing it in the constructor:

```cpp
ByteSize bs(1024, BytePrefix::Decimal); // 1 kilobyte  = 1000 bytes
std::cout << bs; // outputs 1.02 kB
```

The `BitSize` class works similarly, but is used to represent amounts in kilobits, megabits, gigabits, and so on (up to petabits):

```cpp
BitSize bs_binary(1024);
BitSize bs_decimal(1024, BytePrefix::Decimal);
std::cout << bs_binary; // outputs 8.00 Kibit
std::cout << bs_decimal; // outputs 8.19 kbit
```

You can also create an instance of either class from a `string`, and the correct prefix will be deduced:

```cpp
ByteSize bs = ByteSize::Parse("1kB");
std::cout << bs.ToString(1); // outputs 1.0 kB
```

Various methods exist to create an instance of either class from a given unit:

```cpp
ByteSize bs = ByteSize::FromMegabytes(0.5);
std::cout << bs; // outputs 512 KiB
```

#### License

Released under [MIT License](https://github.com/gsemac/byte-size/blob/master/LICENSE).
