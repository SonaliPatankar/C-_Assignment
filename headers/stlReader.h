#pragma once

#include <string>
#include "Triangulation.h"

namespace IOOperation
{
    class STLReader
    {
    public:
        // Function to read data from an STL file and populate a Triangulation object
        void readSTL(std::string& filePath, Geometry::Triangulation& triangulation);
    };
}