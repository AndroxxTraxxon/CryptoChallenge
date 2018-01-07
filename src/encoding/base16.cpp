/*
 * base16.cpp
 *
 *  Created on: Jan 6, 2018
 *      Author: david
 */
#include "base16.h"

string hex_encode(bytestring bytes){
	size_t out_len = (bytes.length * 2);
	string output (out_len, (char) 0);
	for(size_t i = 0, out_index = 0; i < bytes.length && out_index < out_len ; i++, out_index += 2){
		output[out_index]     = (bytes.data[i] >> 4) & 0x0F;
		output[out_index + 1] =  bytes.data[i]       & 0x0F;
	}
	for(size_t i = 0; i < out_len; i++){
		if(output[i] < 10){
			output[i] += 48;
		}else if (output[i] < 16){
			output[i] += (65 - 10);
		}else{
			output[i] = '?';
		}
	}
	output[out_len] = 0;
	return output;
}

bytestring hex_decode(string base16){
	size_t out_len = base16.length() / 2 + (base16.length() % 2);
	bytestring output = make_bytestring(out_len);
	for(size_t i = 0; 2 * i < base16.length(); i++){
			if (base16.length() - 2*i < 2){
				output.data[i] = hex_char_to_bin(base16[2*i]);
			}else{
				output.data[i] = hex_pair_to_byte(base16[2*i], base16[2*i+1]);
			}
		}
	return output;
}

byte hex_char_to_bin(char input){
	input = toupper(input);
	if (input >= '0' && input <= '9'){
		return (byte) input - '0';
	}else if (input >= 'A' && input <= 'F'){
		return (byte) input -'A' + 10;
	}
	cout << (int)input << endl;
	throw runtime_error("hex_char_to_bin only accepts characters in the range '0' thru '9', 'a' thru'f', and 'A' thru 'F'");
	return (byte) -1;
}

byte hex_pair_to_byte(char a, char b){
	byte ba = hex_char_to_bin(a);
	return ((ba << 4) + hex_char_to_bin(b));
}
