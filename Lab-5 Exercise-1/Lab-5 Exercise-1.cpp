#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
};

class DList {
private:
	Node* head;

public:
	DList()
	{
		head = new Node;
		head = NULL;
	}

	bool is_empty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Insert_Begin(int Value)
	{
		Node* temp = new Node;
		temp->data = Value;
		temp->next = NULL;
		temp->prev = NULL;

		if (is_empty())
		{
			head = temp;
		}
		else
		{
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	}

	void Insert_End(int Value)
	{
		Node* temp = new Node;
		temp->data = Value;
		temp->next = NULL;
		temp->prev = NULL;

		if (is_empty())
		{
			head = temp;
		}
		else
		{
			Node* current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = temp;
			temp->prev = current;
		}

	}

	void Insert_After(int OldV, int NewV)
	{
		Node* temp = new Node;
		temp->data = NewV;
		temp->next = NULL;
		temp->prev = NULL;

		Node* p = head;
		while (p->data != OldV)
		{
			p = p->next;
		}
		temp->next = p->next;
		p->next->prev = temp;
		temp->prev = p;
		p->next = temp;

		if (p == NULL)
		{
			cout << "Node not found!" << endl;
		}
	}

	void Delete_Begin()
	{
		Node* temp = head;

		if (is_empty())
		{
			cout << "List is empty!" << endl;
		}

		head = head->next;
		delete temp;
	}

	void Delete_End()
	{
		Node* p = head->next;
		Node* q = head;

		if (is_empty())
		{
			cout << "List is empty!" << endl;
		}

		while (p->next != NULL)
		{
			q = p;
			p = p->next;
		}

		q->next = NULL;
		delete p;
	}

	void Delete_Node(int Value)
	{
		Node* temp = head;

		if (is_empty())
		{
			cout << "List is empty!" << endl;
		}

		if (head->data == Value)
		{
			head = head->next;
			head = temp;
		}
		else
		{
			Node* p = head->next;
			Node* q = head;
			while (p->data != Value)
			{
				q = p;
				p = p->next;
			}
			q->next = p->next;
			delete p;
		}
	}

	void Display()
	{
		if (is_empty())
		{
			cout << "List is empty!" << endl;
		}

		Node* current = head;
		cout << "List is:  " << endl;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
};

int main()
{
	DList li;
	li.Insert_Begin(10);
	li.Insert_Begin(20);
	li.Insert_Begin(30);
	li.Insert_End(40);
	li.Insert_End(50);
	li.Insert_After(30, 60);
	li.Display();
	li.Delete_Begin();
	li.Display();
	li.Delete_End();
	li.Display();
	li.Delete_Node(20);
	li.Display();
}