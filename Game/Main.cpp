#include "helper.h"
#include "Dynamic.h"
#include<iostream>


int main() 
{
	std::cout << nc::sqr(5) << std::endl;
	nc::point p1{ 10,10 };
	nc::point p2{ 10,10 };
	nc::point p3{ 10,10 };
	std::cout << p3.x << "" << p3.y << std::endl;

	system("pause");
}