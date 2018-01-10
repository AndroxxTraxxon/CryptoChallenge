/*
 * bytearray.cpp
 *
 *  Created on: Jan 6, 2018
 *      Author: david
 */

#include "bytestring.h"

bytestring bytestring::operator^ (bytestring a){
	bytestring output = bytestring((a.length < length)?a.length:length);
	for(size_t i = 0; i < output.length; i++){
		output.data[i] = a.data[i] ^ data[i];
	}
	return output;
}

bytestring bytestring::operator+ (bytestring a){
	bytestring output = bytestring(a.length + length);
	memcpy((void *)output.data, (void *) data, length);
	memcpy((void *)(&output.data[a.length]),(void *)a.data, a.length);
	return output;
}

size_t bytestring::get_length(void){
	return length;
}

byte* bytestring::get_data(void){
	return data;
}

bytestring::bytestring(byte * dat, size_t len){
	length = len;
	data = dat;
}

bytestring::bytestring(size_t length){
	this->length = length;
	data = (byte *) calloc(length, sizeof(byte));
}

bytestring::bytestring(string str){
	length = str.length();
	data = (byte *) calloc(length, sizeof(byte));
	memcpy((void *)data, (void *) str.data(), length);
}

bytestring bytestring::substring(size_t start, size_t len){
	len = (len < length - start)?len:length - start;
	bytestring output = bytestring(len);
	memcpy((void *)output.data, (void *) (data + start), output.length);
	return output;
}

string bytestring::toString(){
	string str ((char *)data);
	return str;
}

ostream& bytestring::operator<< (ostream& os){
	for(size_t i = 0; i < length; i++){
		if(data[i] > 31 && data[i] != 127 &&
				data[i] != 255 && data[i] != '&'){
			os << ((char) (data[i]));
		}else{
			os << "&#" <<(unsigned short) data[i] <<";";
		}
	}
	return os << endl;
}
