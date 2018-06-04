#include <stdio.h>
#include <iostream>
#include <memory>
#include <thread>

using namespace std;

class Thread 
{
public:
	Thread() 
	{
		cout << "Construct Thread" << endl;
		m_wait = true;
		m_term = false;
	}

	~Thread() 
	{
		cout << "Destruct Thread" << endl;
		if( m_thread.joinable() )
			m_thread.join();
	}

	void start()
	{
		cout << "Start" << endl;
		m_thread = thread( &Thread::run, this );
	}

	void run()
	{
		while( !m_term ) {
			wait();
			cout << "run" << endl;

			lock_guard<mutex> guard(m_lock);
			cout << "lock guard" << endl;
		}
	}

	void stop()
	{
		m_term = true;
	}

	void wait()
	{
		unique_lock<mutex> guard(m_lock);
		if( m_wait ) {
			m_cv.wait( guard);
		}
	}

	void notify()
	{
		unique_lock<mutex> guard(m_lock);
		m_wait = false;
		m_cv.notify_one();
	}

private:
	thread m_thread;
	mutex  m_lock;
	condition_variable m_cv;
	bool m_wait;
	bool m_term;
};


int main( int argc, char** argv )
{
	Thread t1;
	t1.start();

	for(int i=0; i<30000 ; i++ )
	{
		//cout << "loop" << endl;
	}
	t1.notify();
	t1.stop();
	getchar();

	return 0;
}
