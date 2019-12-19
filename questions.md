# Questions

## What's `stdint.h`?

Header file which shall declare sets of integer types having specified widths, and shall define corresponding sets of macros. It shall also define macros that specify limits of integer types corresponding to types defined in other standard headers.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

uint8_t is an unsigned int of 8 bits, uint32_t is an unsigned long long, int32_t is a signed long long, and a uint16_t is an unsigned 16 bit int. They are all cross platform implementations of a standard data type.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

Byte: 1
DWORD: 4
LONG: 4
WORD: 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

Bitmap with "BM" or hex 0x4D42

## What's the difference between `bfSize` and `biSize`?

bfSize gives the entire file size in bytes, biSize gives BITMAPINFOHEADER size in bytes

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in `copy.c`?

If it cannot open the file - the file may be corrupted/ could not be found/ not enough memory

## Why is the third argument to `fread` always `1` in our code?

The third argument determines the number of elements fread will read. So this argument is always 1 because we are always reading one file.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

1

## What does `fseek` do?

moves file cursor ( file position indicator)

## What is `SEEK_CUR`?

SEEK_CUR is an option used in fseek to set the offset relative to the current pointer position.
