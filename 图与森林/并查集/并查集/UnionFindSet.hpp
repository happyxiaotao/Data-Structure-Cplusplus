
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
	//�����鼯������������ֵ��ʼ��Ϊ-1
	UnionFindSet(int* array, size_t size)
		:_arr(array)
		, _ufs(size, -1)
	{}
	
	//��K���͵�����ӳ�䵽һ�������±��ʾ�ı��С�
	size_t GetIndexOfKey(const K& key)
	{
		size_t index = 0;
		while (_arr[index] != key)
		{
			++index;
		}

		return index;
	}

	//����������ϵȦ
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

	//����������ϵȦ
	void link(const K& key1, const K& key2)
	{
		size_t root1 = FindRoot(key1);
		size_t root2 = FindRoot(key2);

		if (root1 != root2)
		{
			int size = _ufs[root2]; //��ȡroot2�Ĺ�ϵȦ��������������
			_ufs[root2] = root1;//��root2�Ĺ�ϵȦ��Ϊroot1�Ĺ�ϵȦ
			_ufs[root1] += size; //��root2�е������ӵ�root1�Ĺ�ϵȦ��
		}
	}

	//�ҵ���ϵȦ���˵ĸ���
	size_t Size(const K& key)
	{
		size_t root = FindRoot(key);
		return (-_ufs[root]);
	}

	//�ҵ��ô󼯺��ڹ�ϵȦ�ĸ���
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