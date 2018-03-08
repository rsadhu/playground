// CppExtended.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<thread>
#include<mutex>
#include<deque>
#include<future>

std::mutex mu;
std::deque<int> deq = { -1 };
std::condition_variable cond;
bool bool_val = false;



void readerThread()
{
	while (!bool_val || !deq.empty())
	{
		std::unique_lock<std::mutex> locker(mu);
		cond.wait(locker, []()
		{
			return !deq.empty();
		});
		std::cout << "  " << deq.front();
		deq.pop_front();
	}
}


void writerThread()
{	
	int d = 1;

	while (d != 0)
	{
		std::unique_lock<std::mutex> locker(mu);
		std::cin >> d;
		deq.push_back(d);
		cond.notify_all();
		locker.unlock();
	}
	bool_val = true;
}


template<typename T>
constexpr T sqfun(const T &p)
{
	return p * p;
}




class XYZ
{

public: 
	void displayABC();	
};



class ABC
{
	friend class XYZ;
	friend void dostFunction();
public:
	ABC()
	{
		std::cout << " ABC::ABC\n";
	}

	~ABC()
	{
		std::cout << " ABC::~ABC\n";
	}

	void display() { std::cout << " \nABC:: display :: " << data; }
private:
	int data = 0;
};


void XYZ::displayABC()
{
	{
		ABC abc;
		abc.data = 10001;
		abc.display();
	}
}

void dostFunction()
{
	ABC abc;
	abc.data = 100;
	abc.display();
}


template<typename T, typename U=char>
class MultiDataTypeClass
{	
public:
	MultiDataTypeClass() = default;

	MultiDataTypeClass(T data, U data1) :m_Data(data), m_CharData(data1)
	{

	}

protected:
	void display() { std::cout << "MultiDataTypeClass:: display :: " << m_Data << " " << m_CharData; }
private:
	T m_Data;
	U m_CharData;
};

//template<typename T,typename U>
class DataType : public MultiDataTypeClass<int,char>
{
public:
	DataType() = default;
	DataType(int d,char c) :MultiDataTypeClass(d,c) {}
	void printAll()
	{
		display();
	}
};

int  test(int n)
{
	if(n > 1)
	{
		n=n*test(--n);
	}
	return n;
}

void reverseString(char *str)
{
	if (*str != '\0')
	{
		str++;
		reverseString(str);
	}

	std::cout << *str;
}

int sq(std::future<int> f)
{
	return f * f;
}


int main()
{
	std::thread reader(readerThread), writer(writerThread);
	reader.join();
	writer.join();


	constexpr int  res = sqfun<int>(9);
	
	std::cout << " \n Square of :: " << 9 <<"   "<< res;	

	constexpr double res1 = sqfun<double>(9.1);

	std::cout << "  \nSquare of :: " << 9.1 << "   " << res1;

	dostFunction();

	XYZ xvz;
	xvz.displayABC();

	DataType dt ('a'-'0', 'a');
	dt.printAll();



	//auto f = std::function(test);
	//std::bind(f);

	std::cout<<test(9);

	//reverseString(const_cast<char *>("hello"));


	//char16_t *utf16Char= "çesme";// = new char16_t[10];
	//strcpy("çesme", utf16Char);
	//memset(utf16Char, "jkjdks", 10);
	
//	std::wcout << utf16Char;




	std::promise<int> par;
	std::future<int> v = par.get_future();
	std::future<int> ret = std::async(std::launch::async,sq,std::ref(v));

	par.set_value(10);
	std::cout << ret.get();
	
    return 0;
}

