#ifndef ANT_H
#define ANT_H

class Ant
{
	private:
		int id;
		int x;
		int y;

	public:
		Ant(int);
		Ant(const Ant&);
		int fight();
		int move();
		int getID() { return id; }
		int getX() { return x; }
		int getY() { return y; }
		bool inRange();
		const static int Y_MAX = 5; // Grid maximum Y and -Y
		const static int X_MAX = 5; // Grid maximum X and -X
		const static float ODDS_OF_WINNING_FIGHT = 0.55; // Odds of winning a fight (1.00 = 100%)
		enum Action { JUST_MOVED, FIGHT_WIN, FIGHT_LOSE, FOUND_FOOD }; // Specify the action taken by the ant on move()
};

#endif