#ifndef BSTNODE_H

template<typename T>
class BSTNode
{
	public:
		T data;
		BSTNode<T>* left;
		BSTNode<T>* right;
		BSTNode(T d);
		BSTNode();
		~BSTNode();
};

template<typename T>
BSTNode<T>::BSTNode(T d)
{
	data = d;
	left = nullptr;
	right = nullptr;
}

template<typename T>
BSTNode<T>::BSTNode()
{
	left = nullptr;
	right = nullptr;
}

template<typename T>
BSTNode<T>::~BSTNode()
{
}

#endif // !BSTNODE_H

