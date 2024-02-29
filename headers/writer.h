// STLWriter.h
#pragma once
#include <string>
#include "Triangulation.h"

namespace IOOperation
{
    class Writer
    {
    public:
        // Function to write geometry data to an STL file
        void write(std::string& filePath, std::vector<Geometry::Triangle> trinagles,std::vector<Geometry::Point3D> &points);
    };
}