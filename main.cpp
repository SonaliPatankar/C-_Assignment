#include <iostream>
#include <vector>
#include "./headers/point3d.h"
#include "./headers/triangulation.h"
#include "./headers/stlreader.h"
#include "./headers/writer.h"
#include "./headers/halfsection.h"
#include "./headers/boundingBox.h"

int main()
{
    try
    {
        string filepath = "D:/sonali_workspace/C++/TRANSLATOR/READ STL/resources/cube.stl";
        Geometry::Triangulation triangulation;
        Geometry::STLReader stlReader;
        Feature::HalfSection halfsection;
        Feature::BoundingBox boundingBox;
        Geometry::Point3D  minVertex;
        Geometry::Point3D maxVertex;
        stlReader.readSTL(filepath, triangulation);
        boundingBox.calculateBoundingBox (minVertex, maxVertex,triangulation);
        Geometry::Point3D center = boundingBox.calculateBoundingBoxCenter(minVertex, maxVertex);
        halfsection.cutObject(center, triangulation);
        
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}