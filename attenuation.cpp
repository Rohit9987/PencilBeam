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

int main()
{
	std::string line, s;
	std::ifstream attenuation_file("./mass_attenuation/water");

/*
	while(getline(attenuation_file, line))
	{
		std::cout << line << "\n";
	}

*/

	//std::map<std::string, std::string> attenuation;
	std::map<double, double> attenuation;
	std::string energy, mass_att, lin_att;

	while(attenuation_file >> energy >> mass_att >> lin_att)
	{
		try
		{

		attenuation[std::stod(energy)] = std::stod(lin_att);
		}
		catch(...)
		{}
	}

	attenuation_file.close();


	for(auto s: attenuation)
	{
		std::cout << s.first << ": " << s.second << '\n';
	}
}
	
