#include "stdafx.h"
#include "3D.h"

Grafica3D::Grafica3D(int l, int h, double zp)
{
	this->l = l;
	this->h = h;
	this->zp = zp;
}

Punct2D Grafica3D::Pp(Punct3D A)
{
	Punct2D p2d;

	double c = zp / (A.z - zp);
	p2d.x = l + c * A.x;
	p2d.y = h - c * A.y;

	return p2d;
}

void Grafica3D::AdaugaPunct3D(Punct3D p)
{
	v3d.push_back(p);
}

void Grafica3D::AdaugaUnire(Unire u)
{
	unire.push_back(u);
}

void Grafica3D::Desenare(CPaintDC *dc)
{
	Proiectie();

	for (int i = 0; i<(int)unire.size(); i++)
	{
		dc->MoveTo(v2d[unire[i].i1].x, v2d[unire[i].i1].y);
		dc->LineTo(v2d[unire[i].i2].x, v2d[unire[i].i2].y);
	}
}

void Grafica3D::Proiectie()
{
	v2d.resize(v3d.size());

	for (int i = 0; i<(int)v3d.size(); i++)
		v2d[i] = Pp(v3d[i]);
}

void Rotatie(double &x, double &y, double xc, double yc, double cosu, double sinu)
{
	double x0 = x;
	x = (x - xc)*cosu - (y - yc)*sinu + xc;
	y = (x0 - xc)*sinu + (y - yc)*cosu + yc;
}

void Grafica3D::RotatieOY(double u)
{
	if (!v3d.size())
		return;

	double cosu = cos(u), sinu = sin(u);

	double zg = 0, xg = 0;

	for (int i = 0; i<(int)v3d.size(); i++)
	{
		zg += v3d[i].z;
		xg += v3d[i].x;
	}

	zg /= v3d.size();
	xg /= v3d.size();

	for (int i = 0; i<(int)v3d.size(); i++)
		Rotatie(v3d[i].z, v3d[i].x, zg, xg, cosu, sinu);
}
void Grafica3D::RotatieOZ(double u)
{
	if (!v3d.size())
		return;

	double cosu = cos(u), sinu = sin(u);

	double xg = 0, yg = 0;

	for (int i = 0; i<(int)v3d.size(); i++)
	{
		xg += v3d[i].x;
		yg += v3d[i].y;
	}

	xg /= v3d.size();
	yg /= v3d.size();

	for (int i = 0; i<(int)v3d.size(); i++)
		Rotatie(v3d[i].x, v3d[i].y, xg, yg, cosu, sinu);
}
void Grafica3D::RotatieOX(double u)
{
	if (!v3d.size())
		return;

	double cosu = cos(u), sinu = sin(u);

	double yg = 0, zg = 0;

	for (int i = 0; i<(int)v3d.size(); i++)
	{
		yg += v3d[i].y;
		zg += v3d[i].z;
	}

	yg /= v3d.size();
	zg /= v3d.size();

	for (int i = 0; i<(int)v3d.size(); i++)
		Rotatie(v3d[i].y, v3d[i].z, yg, zg, cosu, sinu);
}
Punct3D Grafica3D::translatie(Punct3D punct, double dx, double dy, double dz)
{
	double matrice[4][4] = { { 1, 0, 0, dx }, { 0, 1, 0, dy }, { 0, 0, 1, dz }, { 0, 0, 0, 1 } };
	double matricePunct[4][1] = { { punct.getX() }, { punct.getY() }, { punct.getZ() }, { 1 } };

	double rezultat[4][1];

	for (int i = 0; i < 4; i++)
	{
		rezultat[i][0] = 0;
		for (int k = 0; k < 4; k++)
		{
			rezultat[i][0] = rezultat[i][0] + matrice[i][k] * matricePunct[k][0];
		}

	}
	Punct3D punctDupaTranslatie = Punct3D(rezultat[0][0], rezultat[1][0], rezultat[2][0]);
	return punctDupaTranslatie;
}

void Grafica3D::translatiePeX(double dx)
{
	for (int i = 0; i < v3d.size(); i++)
	{
		v3d[i] = translatie(v3d[i], dx, 0, 0);
	}
	
}
void Grafica3D::translatiePeY(double dy)
{
	for (int i = 0; i < v3d.size(); i++)
	{
		v3d[i] = translatie(v3d[i], 0, dy, 0);
	}
	
}

void Grafica3D::translatiePeZ(double dz)
{
	for (int i = 0; i < v3d.size(); i++)
	{
		v3d[i] = translatie(v3d[i], 0, 0, dz);
	}
	
}

