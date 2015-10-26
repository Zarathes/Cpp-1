#ifndef __client__
#define __client__

class State;

class Client{
	private:
		class State *current;
	public:
		Client();

		void goNext();
		void setState(State *newState);
	
		virtual ~Client();
};

#endif

