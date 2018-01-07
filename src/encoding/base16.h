/*
 * base16.h
 *
 *  Created on: Jan 6, 2018
 *      Author: david
 */

#ifndef BASE16_H_
#define BASE16_H_

#include "encoding.h"
#include <stdexcept>
#include <string>

string hex_encode(bytestring bytes);
bytestring hex_decode(string base16);
byte hex_pair_to_byte(char a, char b);
byte hex_char_to_bin(char input);

#endif /* BASE16_H_ */
