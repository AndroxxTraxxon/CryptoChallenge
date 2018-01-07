/*
 * base64.cpp
 *
 *  Created on: Jan 6, 2018
 *      Author: david
 */

#include "base64.h"

string base64_encode(bytestring base64){
	size_t out_len = ((base64.length * 4)/3) + ((base64.length * 4) % 3);
	string output (out_len, (char) 0);
	size_t out_index = 0;

	for(size_t i = 0; i < base64.length; i++){
		switch(i % 3){
		case 0:
			output[out_index]  = (base64.data[i] >> 2) & 0x3F;
			out_index++;
			output[out_index]  = (base64.data[i] << 4) & 0x30;
			break;
		case 1:
			output[out_index] |= (base64.data[i] >> 4) & 0x0F;
			out_index++;
			output[out_index]  = (base64.data[i] << 2) & 0x3C;
			break;
		case 2:
			output[out_index] |= (base64.data[i] >> 6) & 0x03;
			out_index++;
			output[out_index]  = (base64.data[i] >> 0) & 0x3F;
			out_index++;
			break;
		}
	}
	for(size_t i = 0; i < out_len; i ++){
		if(output[i] < 26){
			output[i] += 'A';
		}else if(output[i] < 52){
			output[i] += 'a' - 26;
		}else if(output[i] < 62){
			output[i] += '0' - 52;
		}else if(output[i] == 62){
			output[i] = '+';
		}else if(output[i] == 63){
			output[i] = '/';
		}
	}
	while(output[output.length()-1] == 'A'){
		output[output.length()-1] = 0;
	}
	return output;
}
bytestring base64_decode(string base64){
	size_t out_len = (((base64.length() * 3) + 1)/4);
	// checking if there is a padded byte at the end of the string
	if((base64[base64.length() - 1] & 0x3F) == 0){
		out_len = out_len - 1;
	}
	bytestring input = make_bytestring(base64.length());
	bytestring output = make_bytestring(out_len);
	size_t out_index = 0;
	for(size_t i = 0; i < base64.length(); i++){
		if(base64[i]>= 'A' && base64[i] < ('A' + 26)){
			input.data[i] = (base64[i] -'A');
		}else if(base64[i]>= 'a' && base64[i] < ('a' + 26)){
			input.data[i] = (base64[i] - 'a') + 26;
		}else if(base64[i]>= '0' && base64[i] < ('0' + 10)){
			input.data[i] = (base64[i] - '0') + (26 * 2);
		}else if(base64[i]== '+'){
			input.data[i] = 62;
		}else if(base64[i] == '/'){
			input.data[i] =  63;
		}else{
			input.data[i] = 0;
		}
	}
	for(size_t i = 0; i < input.length; i++){
		switch(i % 4){
		case 0:
			output.data[out_index]  = (input.data[i] << 2) & 0xFC;
			break;
		case 1:
			output.data[out_index] |= (input.data[i] >> 4) & 0x03;
			out_index++;
			output.data[out_index]  = (input.data[i] << 4) & 0xF0;
			break;
		case 2:
			output.data[out_index] |= (input.data[i] >> 2) & 0x0F;
			out_index++;
			output.data[out_index]  = (input.data[i] << 6) & 0xC0;
			break;
		case 3:
			output.data[out_index] |= (input.data[i] >> 0) & 0x3F;
			out_index++;
			break;
		}
	}
	return output;
}

