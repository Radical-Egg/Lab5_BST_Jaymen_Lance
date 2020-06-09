#ifndef LINKNODE_H_
#define LINKNODE_H_

template<typename T>
class LinkNode
{
	public:
		T data;
		LinkNode<T>* next;
		LinkNode();
		LinkNode(T);
		~LinkNode();
};

template<typename T>
LinkNode<T>::LinkNode()
{
	data = T();
	next = nullptr;
}
template <typename T>
LinkNode<T>::LinkNode(T d)
{
	data = d;
	next = NULL;
}
template <typename T>
LinkNode<T>::~LinkNode()
{
	
}


#endif