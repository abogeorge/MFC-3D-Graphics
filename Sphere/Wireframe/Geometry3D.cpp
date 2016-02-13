#include "stdafx.h"
#include "Geometry3D.h"


Geometry3D::Geometry3D(int height, int width, double zp)
{
	this->l = width;
	this->h = height;
	this->zp = zp;

	_prevMousePoint = Point2D(0, 0);
}

Point2D Geometry3D::PerspectiveProjection(Point3D A)
{
	Point2D p2d;

	double c = zp / (A.z - zp);
	p2d.x = l + c * A.x;
	p2d.y = h - c * A.y;

	return p2d;
}

void Geometry3D::AddPoint3D(Point3D p)
{
	_3DPoints.push_back(p);
}

void Geometry3D::AddUnion(Union u)
{
	_unions.push_back(u);
}

void Geometry3D::SetPrevMousePoint(Point2D newMousePoint)
{
	_prevMousePoint = newMousePoint;
}

Point2D Geometry3D::GetPrevMousePoint()
{
	return _prevMousePoint;
}

void Geometry3D::Draw(CPaintDC *dc)
{
	ApplyPerspectiveProjection();

	for (int i = 0; i<(int)_unions.size(); i++)
	{
		dc->MoveTo( _2DPoints[_unions[i].i1].x, _2DPoints[_unions[i].i1].y);
		dc->LineTo( _2DPoints[_unions[i].i2].x, _2DPoints[_unions[i].i2].y);
	}
}

void Geometry3D::ApplyPerspectiveProjection()
{
	_2DPoints.resize(_3DPoints.size());

	for (int i = 0; i<(int)_3DPoints.size(); i++)
		_2DPoints[i] = PerspectiveProjection(_3DPoints[i]);
}

void Geometry3D::Rotate(double &x, double &y, double xc, double yc, double cosu, double sinu)
{
	double x0 = x;
	x = (x - xc)*cosu - (y - yc)*sinu + xc;
	y = (x0 - xc)*sinu + (y - yc)*cosu + yc;
}

void Geometry3D::CalculateUVector(int m, float a, float b)
{
	m_m = m;
	u_Vector.push_back(a);
	for (int i = 1; i <= m_m; i++)
	{
		double diff = b - a;
		double delta = diff / m_m;
		u_Vector.push_back(u_Vector[i-1] + delta);
	}
}

void Geometry3D::CalculateVVector(int n, float c, float d)
{
	m_n = n;
	v_Vector.push_back(c);
	for (int i = 1; i <= m_n; i++)
	{
		double diff = d - c;
		double delta = diff / m_n;
		v_Vector.push_back(v_Vector[i - 1] + delta);
	}
}


void Geometry3D::ApplyAllFuncs(int A,int B, int C)
{
	for (int i = 0; i < m_m;i++)
	{
		for (int j = 0;j < m_n; j++)
		{
			Point3D temp;
			temp.x = A*cos(u_Vector[i]) * sin(v_Vector[j]);
			temp.y = A*cos(u_Vector[i]) * cos(v_Vector[j]);
			temp.z = A*sin(u_Vector[i]) + B;

			_3DPoints.push_back(temp);
		}
	}

	for (int i = 0; i < m_m-1;i++)
	{
		for (int j = 0; j < m_n-1; j++)
		{
			int a = (m_n + 1)*i + j;
			int b = (m_n + 1)*i + j + 1;
			int c = (m_n + 1)*(i + 1) + j;
			_unions.push_back(Union ((m_n)*i+j, (m_n)*i+j+1));
			_unions.push_back(Union ((m_n)*i+j, (m_n)*(i+1)+j));
		}
	} 
}

void Geometry3D::Ffunc(float u)
{
	
}

void Geometry3D::Gfunc(float u)
{
}

void Geometry3D::Hfunc(float u)
{
}

void Geometry3D::RotateOnOY(double u)
{
	if (!_3DPoints.size())
		return;

	double cosu = cos(u), sinu = sin(u);

	double zg = 0, xg = 0;

	for (int i = 0; i<(int)_3DPoints.size(); i++)
	{
		zg += _3DPoints[i].z;
		xg += _3DPoints[i].x;
	}

	zg /= _3DPoints.size();
	xg /= _3DPoints.size();

	for (int i = 0; i<(int)_3DPoints.size(); i++)
		Rotate(_3DPoints[i].z, _3DPoints[i].x, zg, xg, cosu, sinu);
}

void Geometry3D::RotateOnOZ(double u)
{
	if (!_3DPoints.size())
		return;

	double cosu = cos(u), sinu = sin(u);

	double xg = 0, yg = 0;

	for (int i = 0; i<(int)_3DPoints.size(); i++)
	{
		xg += _3DPoints[i].x;
		yg += _3DPoints[i].y;
	}

	xg /= _3DPoints.size();
	yg /= _3DPoints.size();

	for (int i = 0; i<(int)_3DPoints.size(); i++)
		Rotate(_3DPoints[i].x, _3DPoints[i].y, xg, yg, cosu, sinu);
}

void Geometry3D::RotateOnOX(double u)
{
	if (!_3DPoints.size())
		return;

	double cosu = cos(u), sinu = sin(u);

	double yg = 0, zg = 0;

	for (int i = 0; i<(int)_3DPoints.size(); i++)
	{
		yg += _3DPoints[i].y;
		zg += _3DPoints[i].z;
	}

	yg /= _3DPoints.size();
	zg /= _3DPoints.size();

	for (int i = 0; i<(int)_3DPoints.size(); i++)
		Rotate(_3DPoints[i].y, _3DPoints[i].z, yg, zg, cosu, sinu);
}

void Geometry3D::TranslateOnOx(double dx)
{
	if (!_3DPoints.size())
		return;
	for (int i = 0; i<(int)_3DPoints.size(); i++)
	{
		_3DPoints[i].x+=dx;
	}
}

void Geometry3D::TranslateOnOz(double zx)
{
	if (!_3DPoints.size())
		return;

	for (int i = 0; i<(int)_3DPoints.size(); i++)
	{
		_3DPoints[i].z += zx;
	}
}




