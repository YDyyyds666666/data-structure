template<class T>
class Node
{
public:
	T data;
	Node<T>* next;
	// 无参构造函数
	Node() {}
	Node(T data, Node<T>* node = nullptr) {
		this->data = data;
		this->next = node;
	}
};
