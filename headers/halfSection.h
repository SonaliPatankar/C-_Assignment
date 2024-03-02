#pragma once
#include <vector>
#include "Point3D.h"
#include "Triangle.h"
#include "Triangulation.h"

using namespace std;

namespace Feature
{
    class HalfSection
    {
    public:
        void cutObject(const Geometry::Point3D& center, Geometry::Triangulation& triangulation);
    };
}