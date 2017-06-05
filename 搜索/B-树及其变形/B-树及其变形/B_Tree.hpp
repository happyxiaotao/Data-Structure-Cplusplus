#pragma once

#include <iostream>
using namespace std;

#ifndef _B_TREE_
#define _B_TREE_

template <typename K, size_t M>
struct B_TreeNode
{
	typedef B_TreeNode<K, M> Node;

	B_TreeNode()
		:_pParent(nullptr)
		, size_t _size(0)
	{
		for (size_t i = 0; i < M + 1; ++i)
			_pSub[i] = nullptr;
	}

	Node* _pParent;
	size_t _size; //有效节点个数
	K _key[M]; //关键字集合 ，多个一个空间，方便分裂操作
	Node* _pSub[M+1];//孩子节点集合（指针数组），多给一个空间，方便分裂操作
};

template <typename K, size_t M>
class B_Tree
{
	typedef B_TreeNode<K, M> Node;

public:
	B_Tree()
		: _pRoot(nullptr)
	{}

	bool Insert(const K& key)
	{
		//B树为空时
		if (nullptr == _pRoot)
		{
			_pRoot = new Node;
			_pRoot->_key = key;
			_pRoot->_size = 1;

			return true;
		}
			
		//B树不为空

	}

	bool Find(const K& key)
	{
		pair<Node*, int> address = _find(key);
		
		return (-1 == address.second) ? true; false;
	}
private:
	//返回-1存在
	pair<Node*, int> _find(const K& key);
	
private:
	Node* _pRoot;
};

template <typename K, size_t M>
pair<B_TreeNode<K, size_t M>*, int> B_Tree<K, M>::_find(const K& key)
{
	if ()
}





#endif //_B_TREE_
