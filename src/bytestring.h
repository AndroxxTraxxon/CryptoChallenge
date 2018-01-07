/*
 * bytearray.h
 *
 *  Created on: Jan 6, 2018
 *      Author: david
 */

#ifndef BYTESTRING_H_
#define BYTESTRING_H_

#ifndef BYTE_DEFINITION_OVERRIDE
#define BYTE_DEFINITION_OVERRIDE
typedef unsigned char byte;
#endif /* BYTE_DEFINITION_OVERRIDE */

#include <cstring>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

typedef struct bytestring{
	byte * data;
	size_t length;
} bytearray;

bytestring operator+ (bytestring a, bytestring b);
bytestring operator^ (bytestring a, bytestring b);
ostream& operator<< (ostream& os, bytestring b);
bytestring make_bytestring(size_t l);
bytestring make_bytestring(string str);
bytestring sub_bytestring(bytestring b, size_t start, size_t len);

#endif /* BYTESTRING_H_ */
