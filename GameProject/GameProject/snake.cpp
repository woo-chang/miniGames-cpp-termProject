#include "snake.h"

// 생성자  
Snake::Snake()
{
	Initialize();
}
// 뱀 머리 위치 반환  
const Position Snake::head() const
{
	return body_.front();
}
// 뱀 꼬리 위치 반환  
const Position Snake::tail() const
{
	return body_.back();
}
// 뱀 전체 list 반환  
list<Position>& Snake::body()
{
	return body_;
}
 
//뱀 정보 초기화  
void Snake::Initialize()
{
	body_.clear();
	
	Position pos[2] = {{31,14},{31,15}};
	body_.push_front(pos[0]);
	body_.push_back(pos[1]);
	
	direction = UP;
}

//뱀이 움직이는 방향 설정  
void Snake::SetDirection(Key key)
{
	if (direction == UP && key == DOWN) return;
	if (direction == DOWN && key == UP) return;
	if (direction == LEFT && key == RIGHT) return;
	if (direction == RIGHT && key == LEFT) return;
	
	direction = key;
}

// 머리를 몸통으로 바꾼다. 
void Snake::Move()
{
	move_xy_draw(head().X, head().Y, 'o');
	
	switch(direction)
	{
		case UP: move_up(); break;
		case DOWN: move_down(); break;
		case LEFT: move_left(); break;
		case RIGHT: move_right(); break;
	}
}



void Snake::move_up()
{
	Position new_head = {head().X, head().Y-1};
	body_.push_front(new_head);
}

void Snake::move_down()
{
	Position new_head = {head().X, head().Y+1};
	body_.push_front(new_head);
}

void Snake::move_left()
{
	Position new_head = {head().X-1, head().Y};
	body_.push_front(new_head);
}

void Snake::move_right()
{
	Position new_head = {head().X+1, head().Y};
	body_.push_front(new_head);
}

bool Snake::is_bitten()
{
	list<Position>::const_iterator iter = body_.begin();
	while (++iter != body_.end())
		if ((iter->X == head().X) && (iter->Y == head().Y))
			return true;
	
	return false;
}





