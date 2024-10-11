template <typename t>

struct  Node {
	t data;
    Node<t> *next;
};

template <typename t>

class Queue{

	public:
		Queue();
		Queue(const Queue&);
		~Queue();

		void enqueue(t);
		void dequeue();

		Queue& operator=(const Queue&);

	private:
		Node<t> *head, *tail;
};
