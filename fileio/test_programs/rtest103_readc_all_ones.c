/*
 * rtest105_readc_all_ones - Check readc follows behavior when
 * reading the byte 0xff
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../io300.h"
#include "unit_tests.h"

char* expected_string = "\xff\xff\xff";

int main() {
    test_init();
    struct io300_file* f = create_file_from_string(TEST_FILE, expected_string);

    assert(CACHE_SIZE == 8);

    int expected_byte = 0xff; // expected value if reading 0xff from file
    int failed_read = -1;     // readc should return -1 on EOF
                              // (how is this different from returning 0xff???)

    assert(io300_readc(f) != failed_read);    // expected 0xff
    assert(io300_readc(f) == expected_byte);  // expected 0xff
    assert(io300_readc(f) == expected_byte);  // expected 0xff
    assert(io300_readc(f) == failed_read);    // EOF, expected -1

    io300_close(f);
}
