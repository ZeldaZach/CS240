#include "DogShelter.h"
#include <fstream>

DogShelter::DogShelter(int max)
{
	this->max_dogs = max;
}

bool DogShelter::addDog(Dog d)
{
	// If shelter full, return
	if (this->current_dog_count == this->max_dogs)
		return false;
	
	// Set the dog's shelter ID
	d.setID(this->next_dog_id);
	this->next_dog_id++;
	
	// Make a new array to hold all the dogs
	Dog **tmp = new Dog*[this->current_dog_count + 1];
	
	// Copy old array -> new array
	for (int i = 0; i < current_dog_count; i++)
		tmp[i] = this->dogs_in_shelter[i];

	// Add new dog to array
	tmp[this->current_dog_count] = &d;
	
	// Delete old array & set pointer to new array
	delete[] this->dogs_in_shelter;
	this->dogs_in_shelter = tmp;
	
	return true;
}

bool DogShelter::adopt(int id)
{
	bool dog_found = false;
	int index_of_dog;
	
	// Find the dog in the shelter, if not found return (lower in file)
	for (int i = 0; i < this->current_dog_count; i++)
	{
		if (this->dogs_in_shelter->getID() == id)
		{
			dog_found = true;
			index_of_dog = i;
			break;
		}
	}
	
	if (dog_found)
	{
		fstream fptr;
		fptr.open("adopted.log", ios::app);
		
		if (! fptr.fail() )
		{
			fptr << "Dog ID: " << id
				<< " Dog Breed: " << this->dog_in_shelter[index_of_dog].getBreed();
		
			fptr.close();
		}
		else
		{
			std::cerr << "File failed to open" << std::endl;
			return false;
		}
		
		// Make a new array to hold all the remaining dogs
		Dog **tmp = new Dog*[this->current_dog_count - 1];
	
		// Copy old array -> new array
		for (int i = 0, j = 0; i < current_dog_count; i++)
		{
			if (i == index_of_dog)
				continue;
			
			tmp[j] = this->dogs_in_shelter[i];
			j++;
		}
	
		// Delete old array & set pointer to new array
		delete[] this->dogs_in_shelter;
		this->dogs_in_shelter = tmp;
	
		return true;
	}
	
	return false;
}
