#ifndef QRSCANNER_H
#define QRSCANNER_H

#include <sys/types.h>
typedef unsigned char bit;
typedef unsigned char byte;
typedef struct scanner scanner_t;

#define P(I,J) (scanner->d[(I)*scanner->s + (J)])

struct scanner
{
	size_t s; // size
	int    v; // version
	bit*   d; // data
	int    m; // mask

	// block splitting
	const int* blocks; // block information
	int n_blocks;      // total number of blocks
	int cur_block;     // current block
	int cur_words;     // number of its data words
	int cur_word;      // current word

	// current bit
	size_t i;
	size_t j;

	// codeword buffer
	byte   buf;
	size_t buf_avail;
};

#endif
