#ifndef BST_H
#define BST_H
#include "BSTNode.h"
#include "queue.h"
#include <iostream>

template<typename T>
class BST
{
	private:
		/*
			template<typename T>
			void clearNodesRecur(BSTNode<T>*& nodeStart);

			Clears a tree of nodes, with the specified node as the root.

			Pre:	BSTNode<T>*& nodeStart - The specified root node.
			Post:	All subnodes under the specified node root are deleted.
			Return:	None.
		*/
		void clearNodesRecur(BSTNode<T>*& nodeStart);

		/*
			template<typename T>
			void printNodesDepthFirstRecur(BSTNode<T>*& nodeStart, int order);

			Prints the the tree with a specified root node, in a specified order.

			Pre:	BSTNode<T>*& nodeStart - The specified root node.
					int order - The specified depth first order.
								1 : Pre-order
								2 : In-order
								3 : Post-order
			Post:	None.
			Return:	None.
		*/
		void printNodesDepthFirstRecur(BSTNode<T>*& nodeStart, int order);

		/*
			template<typename T>
			bool insertFromNodeRecur(BSTNode<T>*& nodeStart, T data);

			Insert a new data from the tree with specified root node.

			Pre:	BSTNode<T>*& nodeStart - The specified root node.
					T data - The new data
			Post:	Data is inserted into the tree.
			Return:	True - Operation is successful.
					False - Operation is not successful (Data already exists).
		*/
		bool insertFromNodeRecur(BSTNode<T>*& nodeStart, T data);

		/*
			template<typename T>
			BSTNode<T>*& getMinNode(BSTNode<T>*& nodeStart);

			Gets the node that contains the smallest data from the
			tree with the specifed root node.

			Pre:	BSTNode<T>*& nodeStart - The specified root node.
			Return:	The reference node that contains the smallest data.
		*/
		BSTNode<T>*& getMinNode(BSTNode<T>*& nodeStart);

		/*
			template<typename T>
			BSTNode<T>*& getMaxNode(BSTNode<T>*& nodeStart);

			Gets the node that contains the biggest data from the
			tree with the specifed root node.

			Pre:	BSTNode<T>*& nodeStart - The specified root node.
			Return:	The reference node that contains the biggest data.
		*/
		BSTNode<T>*& getMaxNode(BSTNode<T>*& nodeStart);

		/*
			template<typename T>
			BSTNode<T>*& getMaxNode(BSTNode<T>*& nodeStart);

			Gets the node that contains the specified data from the
			tree with the specifed root node.

			Pre:	BSTNode<T>*& nodeStart - The specified root node.
					T data - The specified data.
			Return:	The reference node that contains the specified data.
		*/
		BSTNode<T>*& getNode(BSTNode<T>*& nodeStart, T data);

	protected:
		BSTNode<T>* start;
		int count;

	public:
		BST(T headData);
		BST();
		~BST();

		/*
			template<typename T>
			void clearTree();

			Clears the tree of data.

			Pre:	None.
			Post:	The tree is cleared of data.
			Return:	None.
		*/
		void clearTree();

		/*
			template<typename T>
			void printDataInOrder();

			Print all data in depth-first in-order.

			Pre:	None.
			Post:	None.
			Return:	None.
		*/
		void printDataInOrder();

		/*
			template<typename T>
			void printDataPreOrder();

			Print all data in depth-first pre-order.

			Pre:	None.
			Post:	None.
			Return:	None.
		*/
		void printDataPreOrder();

		/*
			template<typename T>
			void printDataPostOrder();

			Print all data in depth-first post-order.

			Pre:	None.
			Post:	None.
			Return:	None.
		*/
		void printDataPostOrder();

		/*
			template<typename T>
			void printDataPostOrder();

			Print all data in breadth-first order.

			Pre:	None.
			Post:	None.
			Return:	None.
		*/
		void printDataBreadthFirst();

		/*
			template<typename T>
			bool contains(T d);

			Check if specified data is in the tree.

			Pre:	T data - The specified data.
			Post:	None.
			Return:	True - The specified data is in the tree.
					False - The specified data is not in the tree.
		*/
		bool contains(T d);

		/*
			template<typename T>
			bool remove(const T data);

			Removes the specified data from the tree.

			Pre:	T data - The specified data.
			Post:	None.
			Return:	True - Operation is successful.
					False - Operation is not successful (Data is not in tree).
		*/
		bool remove(const T data);

		/*
			template<typename T>
			bool insert(const T data);

			Inserts the specified data to the tree.

			Pre:	T data - The specified data.
			Post:	None.
			Return:	True - Operation is successful.
					False - Operation is not successful (Data is already in the tree).
		*/
		bool insert(const T data);

		/*
			template<typename T>
			int getCount();

			Get the amount of data stored in the tree.

			Pre:	None
			Post:	None.
			Return:	The amount of data stored in the tree.
		*/
		int getCount();

		/*
			template<typename T>
			T getMin();

			Get the smallest data in the tree.

			Pre:	None
			Post:	None.
			Return:	The smallest data in the tree.
		*/
		T getMin();

		/*
			template<typename T>
			T getMin();

			Get the biggest data in the tree.

			Pre:	None
			Post:	None.
			Return:	The biggest data in the tree.
		*/
		T getMax();
};

template<typename T>
BST<T>::BST(T startData)
{
	start = new BSTNode<T>(startData);
	count = 0;
}

template<typename T>
BST<T>::BST()
{
	start = nullptr;
	count = 0;
}

template<typename T>
BST<T>::~BST()
{
	clearTree();
}

template<typename T>
void BST<T>::clearNodesRecur(BSTNode<T>*& nodeStart)
{
	if (nodeStart == nullptr)
	{
		return;
	}

	if (nodeStart->left != nullptr)
	{
		clearNodesRecur(nodeStart->left);
		delete nodeStart->left;
	}
	
	if (nodeStart->right != nullptr)
	{
		clearNodesRecur(nodeStart->right);
		delete nodeStart->right;
	}
}


/*
	Order:
	<= 1: Pre-order
	== 2: In-order
	>= 3: Post-order
*/
template<typename T>
void BST<T>::printNodesDepthFirstRecur(BSTNode<T>*& nodeStart, int order)
{
	if (nodeStart == nullptr)
	{
		return;
	}

	if (order <= 1)
	{
		std::cout << nodeStart->data << " ";
	}

	if (nodeStart->left != nullptr)
	{
		printNodesDepthFirstRecur(nodeStart->left, order);
	}

	if (order == 2)
	{
		std::cout << nodeStart->data << " ";
	}

	if (nodeStart->right != nullptr)
	{
		printNodesDepthFirstRecur(nodeStart->right, order);
	}

	if (order == 3)
	{
		std::cout << nodeStart->data << " ";
	}
}

template<typename T>
bool BST<T>::insertFromNodeRecur(BSTNode<T>*& nodeStart, T data)
{
	if (nodeStart == nullptr)
	{
		nodeStart = new BSTNode<T>(data);
		count++;
		return true;
	}
	else if (data > nodeStart->data)
	{
		if (nodeStart->right == nullptr)
		{
			nodeStart->right = new BSTNode<T>(data);
			count++;
			return true;
		}
		else
		{
			insertFromNodeRecur(nodeStart->right, data);
		}
	}
	else if (data < nodeStart->data)
	{
		if (nodeStart->left == nullptr)
		{
			nodeStart->left = new BSTNode<T>(data);
			count++;
			return true;
		}
		else
		{
			insertFromNodeRecur(nodeStart->left, data);
		}
	}
	return false;
}

template<typename T>
BSTNode<T>*& BST<T>::getMinNode(BSTNode<T>*& nodeStart)
{
	if (nodeStart == nullptr || nodeStart->left == nullptr)
	{
		return nodeStart;
	}
	return getMinNode(nodeStart->left);
}

template<typename T>
BSTNode<T>*& BST<T>::getMaxNode(BSTNode<T>*& nodeStart)
{
	if (nodeStart == nullptr || nodeStart->right == nullptr)
	{
		return nodeStart;
	}
	return getMaxNode(nodeStart->right);
}

template<typename T>
BSTNode<T>*& BST<T>::getNode(BSTNode<T>*& nodeStart, T data)
{
	if (nodeStart == nullptr || nodeStart->data == data)
	{
		return nodeStart;
	}

	else if (data > nodeStart->data)
	{
		return getNode(nodeStart->right, data);
	}
	else
	{
		return getNode(nodeStart->left, data);
	}
}

template<typename T>
void BST<T>::clearTree()
{
	clearNodesRecur(start);
	delete start;
	start = nullptr;
	count = 0;
}

template<typename T>
void BST<T>::printDataInOrder()
{
	std::cout << "[ ";
	printNodesDepthFirstRecur(start, 2);
	std::cout << "]" << std::endl;
}

template<typename T>
void BST<T>::printDataPreOrder()
{
	std::cout << "[ ";
	printNodesDepthFirstRecur(start, 1);
	std::cout << "]" << std::endl;
}

template<typename T>
void BST<T>::printDataPostOrder()
{
	std::cout << "[ ";
	printNodesDepthFirstRecur(start, 3);
	std::cout << "]" << std::endl;
}

template<typename T>
void BST<T>::printDataBreadthFirst()
{
	if (start != nullptr)
	{
		Queue<BSTNode<T>*>* q = new Queue<BSTNode<T>*>();
		q->enQueue(start);

		std::cout << "[ ";
		while (!q->isListEmpty())
		{
			BSTNode<T>* curNode = q->deQueue();
			T curData = curNode->data;
			std::cout << curData << " ";

			if (curNode->left != nullptr)
			{
				q->enQueue(curNode->left);
			}
			if (curNode->right != nullptr)
			{
				q->enQueue(curNode->right);
			}
		}
		std::cout << "]" << std::endl;

		delete q;
	}
}

template<typename T>
bool BST<T>::contains(T data)
{
	return getNode(start, data) != nullptr;
}

template<typename T>
bool BST<T>::remove(T data)
{
	BSTNode<T>*& targetNode = getNode(start, data);
	if (targetNode != nullptr)
	{
		if (targetNode->left != nullptr && targetNode->right != nullptr)
		{
			BSTNode<T>*& successorNode = getMinNode(targetNode->right);
			targetNode->data = successorNode->data;
			successorNode = nullptr;
			return true;
		}
		else if (targetNode->left == nullptr && targetNode->right == nullptr)
		{
			targetNode = nullptr;
			return true;
		}
		else if(targetNode->left != nullptr)
		{
			targetNode = targetNode->left;
			return true;
		}
		else
		{
			targetNode = targetNode->right;
			return true;
		}
	}
	return false;
}

template<typename T>
int BST<T>::getCount()
{
	return count;
}

template<typename T>
T BST<T>::getMin()
{
	BSTNode<T>*& minNode = getMinNode(start);
	if (minNode != nullptr)
	{
		return minNode->data;
	}
	return T();
}

template<typename T>
T BST<T>::getMax()
{
	BSTNode<T>*& maxNode = getMaxNode(start);
	if (maxNode != nullptr)
	{
		return maxNode->data;
	}
	return T();
}

template<typename T>
bool BST<T>::insert(const T data)
{
	return insertFromNodeRecur(start, data);
}

#endif
