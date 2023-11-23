/*


terma = phi * invsq * exp(-ud) * Energy * (u/p)


integrate this over the energy fluence



linear stopping power ratios

nist x ray mass attenuation coefficients
https://www.nist.gov/pml/x-ray-mass-attenuation-coefficients



*/


#define SSD 100.0

class TERMA
{
public:
	TERMA(double phi, double distance): _phi{phi}, _distance{distance}
	{
		std::cout << invsq(200);	

	}
private:
	double _phi, _distance;
	
	double invsq(distance)
	{
		return distance * distance / (SSD * SSD);
	}

};


int main()
{
	double phi = 1.0;

	double distance = 100;

	
	return 0;

}




	


