/*
 * Block.cpp
 *
 *  Created on: Apr 9, 2018
 *      Author: le0nx
 */

#include "Block.h"
#include <iostream>
#include <time.h>
#include "crypto/sha256.h"


void Block::info() const {
	std::cout << "Timestamp: " << this->_timestamp << std::endl;
	std::cout << "Last Hash: " << this->_last_hash << std::endl;
	std::cout << "Hash     : " << this->_hash 	   << std::endl;
	std::cout << "Data     : " << this->_data	   << std::endl;

}

Block* Block::genesis() {
	time_t curr_time = time(&curr_time);
	const std::string prev_hash = "none";
	const std::string hash = "SS898--1-2asdf";
	const uint64_t data = 1;

	return new Block(curr_time,data,hash, prev_hash);
}

std::string Block::get_hash() const {
	return this->_hash;
}


Block* Block::mineBlock(const Block* lastBlock, uint64_t data) {
	time_t curr_time = time(&curr_time);
	const std::string prev_hash = lastBlock->get_hash();
	const std::string hash = Block::calcHash(curr_time, prev_hash, data);

	return new Block(curr_time,data,hash, prev_hash);
}