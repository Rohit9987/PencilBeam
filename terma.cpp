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

constexpr double operator "" _MeV(long double const amount)
{
	return amount;
}

class TERMA
{
public:
	TERMA(double phi, double distance, double SSD): _phi{phi}, _distance{distance}, _ssd{SSD}
	{
		std::cout << calculateDose() << '\n'; 

	}
private:
	double _phi, _distance, _ssd, _d, _u, p = 1.00;
	double energy = 1.25_MeV;
	
	double invsq()
	{
		return (iso * iso)/(_distance * _distance);
	}

	double exponential()
	{
		return exp(-(_u*_d));
	}

	double attenuation()
	{
		// get the attenuation u/p from the attenuation file


		return 1;
	}

	double calculateDose()
	{
		std::cout << "phi: " <<_phi << '\n'
				  << "invsq : " << invsq() << '\n'
				  << "energy : " << energy << '\n'
			//	  << exponential << '\n'
				  << "u/p : " << _u/p << '\n';
		return _phi * invsq() * energy * exponential() * _u/p;
	}

};


int main()
{
	double phi = 1.0;

	double distance = 100;
	
	TERMA terma1(1, 120, 95);

	
	return 0;

}
