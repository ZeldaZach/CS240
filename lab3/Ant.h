#ifndef ANT_H
#define ANT_H

class Ant
{
	private:
		int id;
		int x;
		int y;
		int experience;
	
	public:
		Ant(int);
		Ant* fight(Ant *);
		void move();
		int getID() { return id; }
		int getX() { return x; }
		int getY() { return y; }
		int getExperience() { return experience; }
};

#endif