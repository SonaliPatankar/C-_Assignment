#pragma once
#include <vector>
#include "Point3D.h"
#include "Triangle.h"
#include "Triangulation.h"

namespace Feature
{
    class BoundingBox
    {
    public:
        void calculateBoundingBox(Geometry::Point3D& minVertex, Geometry::Point3D& maxVertex, Geometry::Triangulation& triangulation);
        Geometry::Point3D calculateBoundingBoxCenter(const Geometry::Point3D& minVertex, const Geometry::Point3D& maxVertex);
    };
}