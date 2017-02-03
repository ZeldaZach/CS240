#ifndef DOGSHELTER_H
#define DOGSHELTER_H

class DogShelter
{
	private:
		int max_dogs;
		int current_dog_count;
		int next_dog_id;
		Dog** dogs_in_shelter;

	public:
		DogShelter(int);
		bool addDog(Dog d);
		bool adopt(int id);
};

#endif
