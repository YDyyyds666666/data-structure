template<class T>
class Node
{
public:
	T data;
	Node<T>* next;
	// �޲ι��캯��
	Node() {}
	Node(T data, Node<T>* node = nullptr) {
		this->data = data;
		this->next = node;
	}
};
