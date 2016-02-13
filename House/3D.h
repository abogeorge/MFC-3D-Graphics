#include "vector"

using namespace std;

struct Punct3D
{
	double x, y, z;
	Punct3D(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	double Punct3D::getX()
	{
		return x;
	}
	double Punct3D::getY()
	{
		return y;
	}
	double Punct3D::getZ()
	{
		return z;
	}
};

struct Unire
{
	int i1, i2;
	Unire(int i1, int i2)
	{
		this->i1 = i1;
		this->i2 = i2;
	}
};

struct Punct2D
{
	int x, y;
};

class Grafica3D
{
	double zp;
	int l, h;
	vector<Punct3D> v3d;
	vector<Unire> unire;
	vector<Punct2D> v2d;
	Punct2D Pp(Punct3D);
public:
	Grafica3D(int l, int h, double zp = 1000.);
	void AdaugaPunct3D(Punct3D);
	void Grafica3D::AdaugaUnire(Unire);
	void Proiectie();
	void Desenare(CPaintDC *dc);
	Punct3D translatie(Punct3D punct, double, double, double);
	void translatiePeX(double);
	void translatiePeY(double);
	void translatiePeZ(double);
	void RotatieOY(double u);
	void RotatieOZ(double u);
	void RotatieOX(double u);
};
