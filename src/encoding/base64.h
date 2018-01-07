/*
 * base64.h
 *
 *  Created on: Jan 6, 2018
 *      Author: david
 */

#ifndef BASE64_H_
#define BASE64_H_

#include "encoding.h"

string base64_encode(bytestring bytes);
bytestring base64_decode(string base64);

#endif /* BASE64_H_ */
