#pragma once
#include "Geom.h"
#include "Disc.h"
#include "Chwytak.h"

class Kolo : public Geom
{
public:
	float R, H;

	Kolo(float r, float h) : R(r), H(h)
	{
		int steps = 15;
		float f = 2 * M_PI / steps;
		float r2 = r * 0.7;

		auto s1 = new Shape(TriangleStrip, ColorF(0.2, 0.2, 0.2));
		for (int i = 0; i <= steps; i++)
		{
			s1->AddPoint(Vec3(-h / 2, r * cos(i * f), r * sin(i * f)), 
				Vec3::Normalized(Vec3(0, cos(i * f), sin(i * f))));
			s1->AddPoint(Vec3(-h / 2, r * cos((i + 1) * f), r * sin((i + 1) * f)),
				Vec3::Normalized(Vec3(0, cos((i + 1) * f), sin((i + 1) * f))));

			s1->AddPoint(Vec3(h / 2, r * cos(i * f), r * sin(i * f)),
				Vec3::Normalized(Vec3(0, cos(i * f), sin(i * f))));

			s1->AddPoint(Vec3(h / 2, r * cos((i + 1) * f), r * sin((i + 1) * f)), 
				Vec3::Normalized(Vec3(0, cos((i + 1) * f), sin((i + 1) * f))));

			s1->AddPoint(Vec3(h / 2, r2 * cos(i * f), r2 * sin(i * f)),
				Vec3::Normalized(Vec3(0, cos(i * f), sin(i * f))));
			s1->AddPoint(Vec3(h / 2, r2 * cos((i + 1) * f), r2 * sin((i + 1) * f)), 
				Vec3::Normalized(Vec3(0, cos((i + 1) * f), sin((i + 1) * f))));

			s1->AddPoint(Vec3(-h / 2, r2 * cos(i * f), r2 * sin(i * f)), 
				Vec3::Normalized(Vec3(0, cos(i * f), sin(i * f))));
			s1->AddPoint(Vec3(-h / 2, r2 * cos((i + 1) * f), r2 * sin((i + 1) * f)),
				Vec3::Normalized(Vec3(0, cos((i + 1) * f), sin((i + 1) * f))));
		}

		this->Shapes.push_back((new Disc(GRAY))
			->WithPosition(Vec3(h/3, 0, 0))
			->WithScale(r2)
			->WithRotation(Quat::FromAngleAxis(Deg2Rad(90), Vec3::Forward())));
		this->Shapes.push_back((new Disc(GRAY))
			->WithPosition(Vec3(-h / 3, 0, 0))
			->WithScale(r2)
			->WithRotation(Quat::FromAngleAxis(Deg2Rad(90), Vec3::Forward())));
		this->Shapes.push_back(s1);
	}
};
