
#ifndef _UNIONFINDSET_H_
#define _UNIONFINDSET_H_

#pragma once

#include <iostream>
#include <vector>
using namespace std;

template <typename K>
class UnionFindSet
{
public:
	//将并查集所在数组所有值初始化为-1
	UnionFindSet(int* array, size_t size)
		:_arr(array)
		, _ufs(size, -1)
	{}
	
	//将K类型的数，映射到一个数组下标表示的表中。
	size_t GetIndexOfKey(const K& key)
	{
		size_t index = 0;
		while (_arr[index] != key)
		{
			++index;
		}

		return index;
	}

	//查找所属关系圈
	size_t FindRoot(const K& key)
	{
		size_t root = GetIndexOfKey(key);
		while (_ufs[root] >= 0)
		{
			root = _ufs[root];
		}

		return root;
	}
	
	bool IsSame(const K& key1, const K& key2)
	{
		size_t root1 = FindRoot(key1);
		size_t root2 = FindRoot(key2);

		return root1 == root2;
	}

	//连接两个关系圈
	void link(const K& key1, const K& key2)
	{
		size_t root1 = FindRoot(key1);
		size_t root2 = FindRoot(key2);

		if (root1 != root2)
		{
			int size = _ufs[root2]; //获取root2的关系圈中人数（负数）
			_ufs[root2] = root1;//将root2的关系圈变为root1的关系圈
			_ufs[root1] += size; //将root2中的人数加到root1的关系圈中
		}
	}

	//找到关系圈内人的个数
	size_t Size(const K& key)
	{
		size_t root = FindRoot(key);
		return (-_ufs[root]);
	}

	//找到该大集合内关系圈的个数
	size_t Size()
	{
		size_t count = 0;
		for (size_t idx = 0; idx < _ufs.size(); ++idx)
		{
			if (_ufs[idx] < 0)
				++count;
		}
		return count;
	}


private:
	int* _arr;
	vector<int> _ufs;
};

#endif //_UNIONFINDSET_H_