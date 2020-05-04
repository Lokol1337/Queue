#pragma once

// ����� �������� �� �������
using ValueType = double;

class LinkedList2

{

	// ����� ���� ������
	// �� ����� ����, ����� ��������� ����� ������,
	// ����� ����������� � ������������� ������, ������ �������
	// ���� � ������ � ���� �, � ������ �����, �������� ������ LinkedList
	// (������ �� �����, ����� �� ����� � �.�.)
	struct Node {
		Node(const ValueType& value, Node* next = nullptr, Node* last = nullptr); //+
		~Node(); //+

		void insertNext(const ValueType& value); //+
		void removeNext(); //+

		ValueType value;
		Node* next;
		Node* last;

	};

public:

	////

	LinkedList2(); //+
	LinkedList2(const LinkedList2& copyList);//+
	LinkedList2& operator=(const LinkedList2& copyList);//+

	LinkedList2(LinkedList2&& moveList) noexcept;//+
	LinkedList2& operator=(LinkedList2&& moveList) noexcept;//+

	~LinkedList2(); //+

	////

	// ������ � �������� �������� �� �������
	ValueType& operator[](const size_t pos) const; //+

	// ������ � ���� �� �������
	LinkedList2::Node* getNode(const size_t pos) const; //+

	// ������� �������� �� �������, ������� ����, ���� ��������� (�(n)), ����� ��������� (O(1))
	void insert(const size_t pos, const ValueType& value); //+

	// ������� �������� ����� ����, (O(1))
	//static
	void insertAfterNode(Node* node, const ValueType& value); //+

	// ������� � ����� (�(n))
	void enqueueBack(const ValueType& value); //+

	// ������� � ������ (�(1))
	void pushFront(const ValueType& value);  //+

	// ��������
	void remove(const size_t pos);//+
	void removeNextNode(Node* node);
	void removeFront();
	void removeBack();

	// �����, �(n)
	long long int findIndex(const ValueType& value) const;
	Node* findNode(const ValueType& value) const;//+

	// �������� ������
	void reverse();						// ��������� �������� ������       +
	LinkedList2 reverse() const;			// �������� ������ ������ (��� ����������� ��������)
	LinkedList2 getReverseList() const;	// ����� ������������� ������ ���� ��� ���������� ����� ����������� ������

	size_t size() const;//+
private:
	Node* _head;
	Node* _tail;
	size_t	_size;

	void forceNodeDelete(Node* node); //+



};
