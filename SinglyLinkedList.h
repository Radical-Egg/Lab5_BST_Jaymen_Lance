#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_
#include <iostream>
#include "LinkNode.h"


template<typename T>
class SinglyLinkedList
{
	protected:
		int count;
		LinkNode<T>* start;
		LinkNode<T>* end;

		/*
			template<typename T>
			LinkNode<T>* getNodeIndex(int index);

			Get the node at the specified index.

			Pre:	int index - The specified index.
			Post:	None.
			Return:	The node at the specified index.
					nullptr if the specified index is out of bounds.
		*/
		LinkNode<T>* getNodeIndex(int index);

	public:
		SinglyLinkedList();
		virtual ~SinglyLinkedList();

		/*
			template<typename T>
			void insert(const T data, int index);

			Inserts new data in the specified index

			Pre:	const T data - The new data
					int index - The specified index.
			Post:	The new data is inserted at the specified index.
					Previous data and all data above specified index is shifted up 1 index.
					If index == count, append the data
					If index is out of bound, do nothing.
			Return:	None.
		*/
		void insert(const T data, int index);

		/*
			template<typename T>
			void append(const T data);

			Inserts new data in the end of the list.

			Pre:	const T data - The new data
			Post:	The new data is inserted at the end of the list.
			Return:	None.
		*/
		void append(const T data);

		/*
			template<typename T>
			void prepend(const T data);

			Inserts new data in the beginning of the list.

			Pre:	const T data - The new data
			Post:	The new data is inserted at the beginning of the list.
			Return:	None.
		*/
		void prepend(const T data);

		/*
			template<typename T>
			void removeIndex(int index);

			Remove data in the specified index

			Pre:	int index - The index of the data to delete.
			Post:	The data in the specified index is deleted
					Data above the index is shifted down 1 index.
					If index is out of bounds, do nothing
			Return:	None.
		*/
		void removeIndex(int index);

		/*
			template<typename T>
			void removeData(const T data);

			Remove the first occurence of the specified data

			Pre:	const T data - The specified data to remove
			Post:	The first occurence of the specified data is removed.
					Data above the deleted data is shifted down 1 index.
			Return:	None.
		*/
		void removeData(const T data);

		/*
			template<typename T>
			void removeFirst();

			Remove the first data of the list.

			Pre:	None.
			Post:	The first data of the list is deleted.
					Data above the deleted data is shifted down 1 index.
			Return:	None.
		*/
		void removeFirst();

		/*
			template<typename T>
			void removeLast();

			Remove the last data of the list.

			Pre:	None.
			Post:	The last data of the list is deleted.
			Return:	None.
		*/
		void removeLast();

		/*
			template<typename T>
			void clearList();

			Clear the list.
			
			Pre:	None.
			Post:	All data in the list are deleted.
			Return:	None.
		*/
		void clearList();

		/*
			template<typename T>
			void printList();

			Print all data in the list

			Pre:	None.
			Post:	None.
			Return:	None.
		*/
		void printList();

		/*
			template<typename T>
			bool isListEmpty();

			Check if the list is empty.

			Pre:	None.
			Post:	None.
			Return:	True - List is empty
					False - List is not empty
		*/
		bool isListEmpty();

		/*
			template<typename T>
			T getStart();

			Get the data at the start of the list

			Pre:	None.
			Post:	None.
			Return:	The data at the start of the list.
		*/
		T getStart();

		/*
			template<typename T>
			T getEnd();

			Get the data at the end of the list

			Pre:	None.
			Post:	None.
			Return:	The data at the end of the list.
		*/
		T getEnd();

		/*
			template<typename T>
			T getData(int i);

			Get the data at the specified index.

			Pre:	None.
			Post:	None.
			Return:	The data at the specified index.
					Default constructed object if out of bounds.
		*/
		T getData(int i);

		/*
			template<typename T>
			int getIndex(const T data);

			Get the index of first occuring specified data.

			Pre:	None.
			Post:	None.
			Return:	The index of the first occuring specified data.
					-1 if the specified data is not found.
		*/
		int getIndex(const T data);

		/*
			template<typename T>
			int getCount();

			Get the size of the list

			Pre:	None.
			Post:	None.
			Return:	The size of the list.
		*/
		int getCount();
};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	start = nullptr;
	end = nullptr;
	count = 0;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	clearList();
}

template<typename T>
LinkNode<T>* SinglyLinkedList<T>::getNodeIndex(int index)
{
	if (index < 0 || index >= count)
	{
		return nullptr;
	}

	LinkNode<T>* node = start;

	for (int i = 0; i < index; i++)
	{
		node = node->next;
	}

	return node;
}

// Insert has appending behavior when index == length
template<typename T>
void SinglyLinkedList<T>::insert(const T data, int index)
{
	if (index < 0 || index > count)
	{
		return;
	}

	LinkNode<T>* newNode = new LinkNode<T>();
	newNode->data = data;

	LinkNode<T>* curNode = getNodeIndex(index);
	LinkNode<T>* prevNode = getNodeIndex(index - 1);

	if (prevNode == nullptr)
	{
		start = newNode;
	}
	else
	{
		prevNode->next = newNode;
	}

	newNode->next = curNode;
	count++;
}

template<typename T>
void SinglyLinkedList<T>::append(const T data)
{
	insert(data, count);
}

template<typename T>
void SinglyLinkedList<T>::prepend(const T data)
{
	insert(data, 0);
}

template<typename T>
void SinglyLinkedList<T>::removeIndex(int index)
{
	if (index < 0 || index >= count)
	{
		return;
	}

	LinkNode<T>* node = getNodeIndex(index);
	LinkNode<T>* prevNode = getNodeIndex(index - 1);
	
	if (prevNode == nullptr)
	{
		start = node->next;
	}
	else
	{
		prevNode->next = node->next;
	}

	if (node->next == nullptr)
	{
		end = prevNode;
	}
	else
	{
		node->next = nullptr;
	}
	
	delete node;
	count--;
}

template<typename T>
void SinglyLinkedList<T>::removeData(const T data)
{
	removeIndex(getIndex(data));
}

template<typename T>
void SinglyLinkedList<T>::removeFirst()
{
	removeIndex(0);
}

template<typename T>
void SinglyLinkedList<T>::removeLast()
{
	removeIndex(count-1);
}

template<typename T>
void SinglyLinkedList<T>::clearList()
{
	LinkNode<T>* node = start;
	while (node != nullptr)
	{
		LinkNode<T>* nextNode = node->next;

		delete node;

		node = nextNode;
	}

	start = nullptr;
	end = nullptr;
	count = 0;
}

template<typename T>
bool SinglyLinkedList<T>::isListEmpty()
{
	return count <= 0;
}

template<typename T>
void SinglyLinkedList<T>::printList()
{
	LinkNode<T>* node = start;
	std::cout << "[ ";

	while (node != nullptr)
	{
		LinkNode<T>* nextNode = node->next;

		std::cout << node->data << " " << std::endl;

		node = nextNode;
	}

	std::cout << "]" << std::endl;
}

// removed 'std::cout << node->data;'
template<typename T>
T SinglyLinkedList<T>::getData(int i)
{
	LinkNode<T>* node = start;
	while (node != nullptr && i > 0)
	{
		node = node->next;
		i--;
	}

	if (node == nullptr)
	{
		return T();
	}

	return node->data;
}

template<typename T>
T SinglyLinkedList<T>::getStart()
{
	return getData(0);
}

template<typename T>
T SinglyLinkedList<T>::getEnd()
{
	return getData(count - 1);
}

template<typename T>
int SinglyLinkedList<T>::getIndex(const T data)
{
	int i = 0;
	LinkNode<T>* node = start;
	while (node != nullptr && node->data != data)
	{
		node = node->next;
		i++;
	}

	if (node == nullptr)
	{
		return -1;
	}

	return i;
}

template<typename T>
int SinglyLinkedList<T>::getCount()
{
	return count;
}

#endif
