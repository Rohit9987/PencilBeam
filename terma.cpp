/*


terma = phi * invsq * exp(-ud) * Energy * (u/p)


integrate this over the energy fluence



linear stopping power ratios

nist x ray mass attenuation coefficients
https://www.nist.gov/pml/x-ray-mass-attenuation-coefficients



*/

#include <iostream>
#include <math.h>

#define iso 100.0

class TERMA
{
public:
	TERMA(double phi, double distance, double SSD): _phi{phi}, _distance{distance}, _ssd{SSD}
	{
		std::cout << invsq();	

	}
private:
	double _phi, _distance, _ssd, _d, _u;
	
	double invsq()
	{
		return (iso * iso)/(_distance * _distance);
	}

	double exponential()
	{
		return exp(-(_u*_d));
	}

};


int main()
{
	double phi = 1.0;

	double distance = 100;
	
	TERMA terma1(1, 120, 95);

	
	return 0;

}




	


