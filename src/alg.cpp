using namespace std;

template <typename T>
class TPQueue
{
private:
	T* A; 
	int* P; 
	int count; 
public:
	TPQueue() { count = 0; }

	QueueP(const TPQueue& _Q)
	{
		try {
			A = new T[_Q.count];
			P = new int[_Q.count];
		}
		catch (bad_alloc e)
		{
			cout << e.what() << endl;
			count = 0;
			return;
		}

		count = _Q.count;

		for (int i = 0; i < count; i++)
			A[i] = _Q.A[i];

		for (int i = 0; i < count; i++)
			P[i] = _Q.P[i];
	}

	~TPQueue()
	{
		if (count > 0)
		{
			delete[] A;
			delete[] P;
		}
	}

	TPQueue operator=(const TPQueue& _Q);

	void Push(T item, int priority);
	T Pop();
	void Clear()
	{
		if (count > 0)
		{
			delete[] A;
			delete[] P;
			count = 0;
		}
	}

	int Count()
	{
		return count;
	}

	void Print(const char* objName);
};

struct SYM
{
	char ch;
	int prior;
};
