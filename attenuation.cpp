#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>


/*
  Energy        μ/ρ        μen/ρ 
   (MeV)      (cm2/g)     (cm2/g)
*/

//initiate this as a class

class Attenuation
{
	using Map = std::map<double, double>;
	Map attenuation;

public:
	Attenuation(std::string material)
	{
		std::string line, s;
		std::ifstream attenuation_file("./mass_attenuation/"+material);

		std::string energy, mass_att, lin_att;
		
		while(attenuation_file >> energy >> mass_att >> lin_att)
		{
			try
			{
				attenuation[std::stod(energy)] = std::stod(lin_att);
			}
			catch(...) {}
		}

		attenuation_file.close();

	}

	~Attenuation() {}

	double get_attenuation(double energy)		// material
	{
		double previous = -1;
		Map::iterator it;
		for(it = attenuation.begin(); it != attenuation.end(); it++)
		{
			if (energy == it->first)
			{
				return it->second;
			}
			else if (energy > it->first)
			{
				previous = it->first;
			}
			else
			{
				// interpolate
				return interpolate(energy, it->first, it->second, previous, attenuation[previous]);
			}
		}

		return 0;
	}

private:
	double interpolate(double x, double x2, double y2, double x1, double y1)
	{

		double slope = (y2-y1)/(x2-x1);
		double val = y1 + slope * (x-x1);
		return val;
	}
};

int main()
{
	Attenuation att1("water");
	std::cout << att1.get_attenuation(3.5);

	return 0;
}
