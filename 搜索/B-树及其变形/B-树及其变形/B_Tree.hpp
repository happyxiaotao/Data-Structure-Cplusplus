#pragma once

#ifndef _B_TREE_
#define _B_TREE_

template <typename K�� size_t M>
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
	size_t _size; //��Ч�ڵ����
	K _key[M]; //�ؼ��ּ��� �����һ���ռ䣬������Ѳ���
	Node* _pSub[M+1];//���ӽڵ㼯�ϣ�ָ�����飩�����һ���ռ䣬������Ѳ���
};

template <typename K>
class B_Tree
{

};





#endif //_B_TREE_
