#pragma once

#ifndef _B_TREE_
#define _B_TREE_

template <typename K， size_t M>
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

template <typename K>
class B_Tree
{

};





#endif //_B_TREE_
