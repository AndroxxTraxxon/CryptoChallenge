/*
 * bytearray.cpp
 *
 *  Created on: Jan 6, 2018
 *      Author: david
 */

#include "bytestring.h"

bytestring operator^ (bytestring a, bytestring b){
	bytestring output = make_bytestring((a.length < b.length)?a.length:b.length);
	for(size_t i = 0; i < output.length; i++){
		output.data[i] = a.data[i] ^ b.data[i];
	}
	return output;
}

bytestring operator+ (bytestring a, bytestring b){
	bytestring output = make_bytestring(a.length + b.length);
	memcpy((void *)output.data, (void *) a.data, a.length);
	memcpy((void *)(&output.data[a.length]),(void *)b.data, b.length);
	return output;
}

bytestring make_bytestring(size_t l){
	bytestring output;
	output.length = l;
	output.data = (byte *) calloc(output.length, sizeof(byte));
	return output;
}

bytestring make_bytestring(string str){
	bytestring output = make_bytestring(str.length());
	memcpy((void *)output.data, (void *) str.data(), output.length);
	return output;
}

bytestring sub_bytestring(bytestring b, size_t start, size_t len){
	bytestring output = make_bytestring(len);
	memcpy((void *)output.data, (void *) (b.data + start), output.length);
	return output;
}

string bytearray_to_string(bytestring b){
	string str ((char *)b.data);
	return str;
}

ostream& operator<< (ostream& os, bytestring b){
	for(size_t i = 0; i < b.length; i++){
		if(b.data[i] > 31 && b.data[i] != 127 &&
				b.data[i] != 255 && b.data[i] != '&'){
			os << ((char) (b.data[i]));
		}else{
			os << "&#" <<(unsigned short) b.data[i] <<";";
		}
	}
	return os << endl;
}
