#ifndef __SNAKE__
#define __SNAKE__

#include "board.h"
#include <list>
using namespace std;

class Snake
{
	private:
		int direction;
		list<Position> body_;
		
	public:
		Snake();
		
		void Initialize();
		void SetDirection(Key key);
		void Move();
		bool is_bitten();
		
		list<Position>& body();

		const Position head() const;
		const Position tail() const;
		
		void move_up();
		void move_down();
		void move_right();
		void move_left();
		const int get_direction() const;

};

#endif

