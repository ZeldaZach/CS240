#include "Hash.h"
#include <iostream>

Hash::Hash(unsigned int size) : maxSize(size), curSize(0)
{
	dict.reserve(size);
	for (int i = 0; i < maxSize; i++)
		dict.push_back(std::make_pair("",""));
}

bool Hash::insert(String key, String value)
{
	if (curSize == maxSize)
		return false;

	int dictAddressToInsertTo = hasher(key);

	while (dict.at(dictAddressToInsertTo).first != "")
	{
		dictAddressToInsertTo++;
		dictAddressToInsertTo %= maxSize; // Wrap around
	}

	dict.at(dictAddressToInsertTo) = std::make_pair(key, value);
	curSize++;
	return true;
}

bool Hash::remove(String key)
{
	for (int i = 0; i < size(); i++)
	{
		if (dict.at(i).first == key)
		{
			dict.at(i) = std::make_pair("", "");
			return true;
		}
	}

	return false;
}

String Hash::find(String key)
{
	for (auto i : dict)
		if (i.first == key)
			return i.second;

	return "";
}

bool Hash::empty()
{
	for (int i = 0; i < size(); i++)
		if (dict.at(i).first != "")
			return false;

	return true;
}

int Hash::size()
{
	return maxSize;
}

void Hash::printHash()
{
	for (int i = 0; i < size(); i++)
		std::cout << "[" << i << "]" << "\tKEY:" << dict.at(i).first << "\tVALUE:" << dict.at(i).second << std::endl;
}

int Hash::hasher(String key)
{
	/*
	 * For each letter, get ascii value then add a
	 * set of primes to it and * it w/ prime
	 * number. Do this for all symbols.
	 * Finally, mod it with the # of possible
	 * indexes we have to put it with.
	 */
	int result = 0;
	int length = key.length();

	for (int i = 0; i < length; i++)
	{
		int ascii = static_cast<int>(key.at(i));
		result += (11*ascii + 17*length + 31*i) * 193;
	}

	result %= maxSize;

	return result;
}
