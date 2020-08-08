// Design - Implement HashMap

Class MyHashMap
{
	vector<list<pair<int, int>>> hashTable;

public:
	MyHashMap(int _size)
	{
		hashTable = vector<pair<int, int>>(_size, 0);
	}

	void put(int key, int value)
	{
		int index = hash(key);
		for (auto it : hashTable[index])
		{
			if (it.first == key)
			{
				It.second = value;
				return;
			}
		}
		hashTable[index].push_back({key, value});
	}

	int get(int key)
	{
		int index = hash(key);
		if (hashTable[index].size() == 0)
			return -1;
		for (auto it : hashTable[index])
		{
			if (it.first == key)
			{
				return it.second;
			}
		}
		return -1;
	}

	void remove(int key, int value)
	{
		int index = hash(key);
		if (hashTable[index].size() == 0)
			return;
		hashTable[index].remove_if([key](auto n) { return n.first == key; });
	}

	int hash(int key)
	{
		return key % capacity;
	}
};
