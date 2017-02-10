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
		const static int Y_MAX = 25;
		const static int X_MAX = 25;
};

#endif