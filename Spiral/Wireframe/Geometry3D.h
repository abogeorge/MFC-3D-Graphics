#include "vector"

using namespace std;


struct Point2D
{
	double x, y;
	Point2D()
	{

	}

	Point2D(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};


struct Point3D
{
	double x, y, z;
	Point3D(){}
	Point3D(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

struct Union
{
	int i1, i2;
	Union(int i1, int i2)
	{
		this->i1 = i1;
		this->i2 = i2;
	}
};

class Geometry3D
{
private:
	double zp;
	int l, h;
	Point2D _prevMousePoint;
	vector<Point3D> _3DPoints;
	vector<Union> _unions;
	vector<Point2D> _2DPoints;
	vector<float> u_Vector;
	Point2D PerspectiveProjection(Point3D p3D);
public:
	Geometry3D(int l, int h, double zp = -1000.f);
	void AddPoint3D(Point3D p3D);
	void AddUnion(Union newUnion);
	void ApplyPerspectiveProjection();
	void Draw(CPaintDC *dc);
	void RotateOnOY(double u);
	void RotateOnOZ(double u);
	void RotateOnOX(double u);
	void TranslateOnOx(double dx);
	void TranslateOnOz(double zx);
	void SetPrevMousePoint(Point2D newPoint);
	Point2D GetPrevMousePoint();
	void Rotate(double &x, double &y, double xc, double yc, double cosu, double sinu);

	void CalculateUVector(int n, int a, int b);
	void ApplyAllFuncs(int A, int B, int C);
	void Ffunc(float u);
	void Gfunc(float u);
	void Hfunc(float u);

	Point3D curvePoint;
	float u;
	int n;
	int m_n;


};
