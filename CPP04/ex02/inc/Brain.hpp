#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain 
{
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();

		void setIdea(int i, const std::string &newIdea);
		std::string getIdea(int i) const;
};
#endif