/*
 * hex_to_base64.cpp
 *
 *  Created on: Jan 5, 2018
 *      Author: david
 */

#include "data_tools.h"

bytestring repeat_key_xor(bytestring message, string key){
	bytestring temp = make_bytestring(repeat_string(key, message.length));
	return message ^ temp;
}

string repeat_string(string seed, size_t length){
	string output = "";
	size_t seed_len = seed.length();
	for(size_t i = 0; i < length; i++){
		output += seed[i%seed_len];
	}
	return output;
}

size_t hamming_distance(bytestring a, bytestring b){
	size_t output = 0;
	bytestring temp = a ^ b;
	for(size_t i = 0; i < temp.length; i++){
		for(size_t j = 0; j < 8; j++){
			output += (temp.data[i] >> j) & 0x01;
		}
	}
	return output;
}

bytestring crack_repeat_xor(bytestring str){
	bytestring output;
	size_t min_keySize = 2;
	double min_score = 8;
	for(size_t keySize = 2; keySize <= 40; keySize ++){
		bytestring temp_a = sub_bytestring(str, 0, keySize);
		bytestring temp_b = sub_bytestring(str, keySize, keySize);

		double norm_dist = hamming_distance(temp_a, temp_b)/(double)keySize;
		if(norm_dist < min_score){
			min_score = norm_dist;
			min_keySize = keySize;
		}
	}
	cout << min_keySize << endl;

	return output;
}


