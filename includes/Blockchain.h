/*
 * Blockchain.h
 *
 *  Created on: Apr 10, 2018
 *      Author: le0nx
 */

#ifndef INCLUDES_BLOCKCHAIN_H_
#define INCLUDES_BLOCKCHAIN_H_

#include "Block.h"
#include <vector>
#include <memory>

class BlockChain {
public:
	BlockChain();

	void addBlock(const std::vector<std::string>& data);

	bool isValidChain(const std::vector <Block*> &chain);

	void replaceChain(const std::vector <Block*> &chain);

	std::vector <Block*> get_chain() const;

	std::string toJSON();
private:
	std::vector <Block*> _blockchain;
};



#endif /* INCLUDES_BLOCKCHAIN_H_ */
