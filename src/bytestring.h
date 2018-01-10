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

//typedef struct bytestring{
//	byte * data;
//	size_t length;
//} bytearray;
class bytestring{
	byte * data;
	size_t length;
public:

	bytestring(size_t length);
	bytestring(string str);
	bytestring(byte * data, size_t length);
	byte * get_data(void);
	size_t get_length(void);
	bytestring operator^ (bytestring a); // XOR
	bytestring operator+ (bytestring a); // STRING CONCAT
	ostream& operator<< (ostream& os);   // FOR PRINTING
	bytestring substring(size_t start, size_t length);
	string toString(void);
};

#endif /* BYTESTRING_H_ */
