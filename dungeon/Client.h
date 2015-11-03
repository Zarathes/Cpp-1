#ifndef __client__
#define __client__

class State;

class Client{
	protected:
		class State *currentState;
	public:
		Client();

		void goNext();
		void setState(State *newState);
		State* getState();
	
		virtual ~Client();
};

#endif

