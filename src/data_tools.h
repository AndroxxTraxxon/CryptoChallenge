/*
 * hex_to_base64.h
 *
 *  Created on: Jan 5, 2018
 *      Author: david
 */

#ifndef DATA_TOOLS_H_
#define DATA_TOOLS_H_



using namespace std;

#include <stdlib.h>
#include <cstring>
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "bytestring.h"
#include "encoding/base64.h"
#include "encoding/base16.h"

#ifndef BYTE_DEFINITION_OVERRIDE
#define BYTE_DEFINITION_OVERRIDE
typedef unsigned char byte;
#endif /* BYTE_DEFINITION_OVERRIDE */

bytestring bytestr_xor(bytestring a, bytestring b);
bytestring repeat_key_xor(bytestring message, string key);
string repeat_string(string seed, size_t length);
size_t hamming_distance(bytestring a, bytestring b);


#endif /* DATA_TOOLS_H_ */
