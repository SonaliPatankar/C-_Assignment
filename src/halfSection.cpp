#include <limits>
#include <iostream>
#include "../headers/halfSection.h"
#include "../headers/writer.h"

// Cut the object into two pieces based on the center point
void Feature ::HalfSection ::cutObject(const Geometry::Point3D& center, Geometry::Triangulation& triangulation)
{
  Geometry::Writer writer;
  string filePath1 = "output/halfsection1.txt";
  string filePath2 = "output/halfsection2.txt";

  string plane;
  std::cout << "Please, enter the plane for Halfsection - XY, YZ or XZ " << "\n";
  std::cin>>plane;

  std::vector<Geometry::Triangle> halfSectionTriangles1;
  std::vector<Geometry::Triangle> halfSectionTriangles2;
  vector<Geometry::Point3D> &points = triangulation.uniquePoints();
  Geometry::Point3D p11(0, 0, 0);
  Geometry::Point3D p12(0, 0, 0);
  Geometry::Point3D p13(0, 0, 0);

  Geometry::Point3D p21(0, 0, 0);
  Geometry::Point3D p22(0, 0, 0);
  Geometry::Point3D p23(0, 0, 0);
  int index1;
  int index2;
  int index3;
  int index4;
  int index5;
  int index6;
  for (const auto &triangle : triangulation.triangles())
  {
    double offset = 0.05;
    
    if(((plane.compare("YZ")) == 0) || ((plane.compare("yz")) == 0))
    {
      if(points[triangle.v1()].x() >= center.x())    //for YZ plane
      {
        index1 = triangulation.uniquePoints().size();
        p11.setX(center.x()-offset);
        p11.setY(points[triangle.v1()].y());
        p11.setZ(points[triangle.v1()].z());
        triangulation.uniquePoints().push_back(p11);

        index2 = triangulation.uniquePoints().size();
        p21.setX(points[triangle.v1()].x()+offset);
        p21.setY(points[triangle.v1()].y());
        p21.setZ(points[triangle.v1()].z());
        triangulation.uniquePoints().push_back(p21);

      }
      else
      {
        index1 = triangulation.uniquePoints().size();
        p11.setX(points[triangle.v1()].x()-offset);
        p11.setY(points[triangle.v1()].y());
        p11.setZ(points[triangle.v1()].z());
        triangulation.uniquePoints().push_back(p11);

        index2 = triangulation.uniquePoints().size();
        p21.setX(center.x()+offset);
        p21.setY(points[triangle.v1()].y());
        p21.setZ(points[triangle.v1()].z());
        triangulation.uniquePoints().push_back(p21);
      }
     
      if(points[triangle.v2()].x() >= center.x())
      {
        index3 = triangulation.uniquePoints().size();
        p12.setX(center.x()-offset);
        p12.setY(points[triangle.v2()].y());
        p12.setZ(points[triangle.v2()].z());
        triangulation.uniquePoints().push_back(p12);

        index4 = triangulation.uniquePoints().size();
        p22.setX(points[triangle.v2()].x()+offset);
        p22.setY(points[triangle.v2()].y());
        p22.setZ(points[triangle.v2()].z());
        triangulation.uniquePoints().push_back(p22);
      }
      else
      {
        index3 = triangulation.uniquePoints().size();
        p12.setX(points[triangle.v2()].x()-offset);
        p12.setY(points[triangle.v2()].y());
        p12.setZ(points[triangle.v2()].z());
        triangulation.uniquePoints().push_back(p12);

        index4 = triangulation.uniquePoints().size();
        p22.setX(center.x()+offset);
        p22.setY(points[triangle.v2()].y());
        p22.setZ(points[triangle.v2()].z());
        triangulation.uniquePoints().push_back(p22);
      }
 
      if(points[triangle.v3()].x() >= center.x())
      {
        index5 = triangulation.uniquePoints().size();
        p13.setX(center.x()-offset);
        p13.setY(points[triangle.v3()].y());
        p13.setZ(points[triangle.v3()].z());
        triangulation.uniquePoints().push_back(p13);

        index6 = triangulation.uniquePoints().size();
        p23.setX(points[triangle.v3()].x()+offset);
        p23.setY(points[triangle.v3()].y());
        p23.setZ(points[triangle.v3()].z());
        triangulation.uniquePoints().push_back(p23);
      }
      else
      {
        index5 = triangulation.uniquePoints().size();
        p13.setX(points[triangle.v3()].x()-offset);
        p13.setY(points[triangle.v3()].y());
        p13.setZ(points[triangle.v3()].z());
        triangulation.uniquePoints().push_back(p13);

        index6 = triangulation.uniquePoints().size();
        p23.setX(center.x()+offset);
        p23.setY(points[triangle.v3()].y());
        p23.setZ(points[triangle.v3()].z());
        triangulation.uniquePoints().push_back(p23);
      }
    }
    else if((plane.compare("XZ") == 0) || (plane.compare("xz") == 0))           //for XZ plane
    {
      if(points[triangle.v1()].y() >= center.y())
      {
        index1 = triangulation.uniquePoints().size();
        p11.setY(center.y()-offset);
        p11.setX(points[triangle.v1()].x());
        p11.setZ(points[triangle.v1()].z());
        triangulation.uniquePoints().push_back(p11);

        index2 = triangulation.uniquePoints().size();
        p21.setY(points[triangle.v1()].y()+offset);
        p21.setX(points[triangle.v1()].x());
        p21.setZ(points[triangle.v1()].z());
        triangulation.uniquePoints().push_back(p21);
      }
      else
      {
        index1 = triangulation.uniquePoints().size();
        p11.setY(points[triangle.v1()].y()-offset);
        p11.setX(points[triangle.v1()].x());
        p11.setZ(points[triangle.v1()].z());
        triangulation.uniquePoints().push_back(p11);

        index2 = triangulation.uniquePoints().size();
        p21.setY(center.y()+offset);
        p21.setX(points[triangle.v1()].x());
        p21.setZ(points[triangle.v1()].z());
        triangulation.uniquePoints().push_back(p21);
      }
     
      if(points[triangle.v2()].y() >= center.y())
      {
        index3 = triangulation.uniquePoints().size();
        p12.setY(center.y()-offset);
        p12.setX(points[triangle.v2()].x());
        p12.setZ(points[triangle.v2()].z());
        triangulation.uniquePoints().push_back(p12);

        index4 = triangulation.uniquePoints().size();
        p22.setY(points[triangle.v2()].y()+offset);
        p22.setX(points[triangle.v2()].x());
        p22.setZ(points[triangle.v2()].z());
        triangulation.uniquePoints().push_back(p12);
      }
      else
      {
        index3 = triangulation.uniquePoints().size();
        p12.setY(points[triangle.v2()].y()-offset);
        p12.setX(points[triangle.v2()].x());
        p12.setZ(points[triangle.v2()].z());
        triangulation.uniquePoints().push_back(p12);

        index4 = triangulation.uniquePoints().size();
        p22.setY(center.y()+offset);
        p22.setX(points[triangle.v2()].x());
        p22.setZ(points[triangle.v2()].z());
        triangulation.uniquePoints().push_back(p22);
      }
 
      if(points[triangle.v3()].y() >= center.y())
      {
        index5 = triangulation.uniquePoints().size();
        p13.setY(center.y()-offset);
        p13.setX(points[triangle.v3()].x());
        p13.setZ(points[triangle.v3()].z());
        triangulation.uniquePoints().push_back(p13);

        index6 = triangulation.uniquePoints().size();
        p23.setY(points[triangle.v3()].y()+offset);
        p23.setX(points[triangle.v3()].x());
        p23.setZ(points[triangle.v3()].z());
        triangulation.uniquePoints().push_back(p23);
      }
      else
      {
        index5 = triangulation.uniquePoints().size();
        p13.setY(points[triangle.v3()].y()-offset);
        p13.setX(points[triangle.v3()].x());
        p13.setZ(points[triangle.v3()].z());
        triangulation.uniquePoints().push_back(p13);

        index6 = triangulation.uniquePoints().size();
        p23.setY(center.y()+offset);
        p23.setX(points[triangle.v3()].x());
        p23.setZ(points[triangle.v3()].z());
        triangulation.uniquePoints().push_back(p23);
      }
    }
    else if((plane.compare("XY") == 0) || (plane.compare("xy") == 0))             //for XZ plane
    {
      if(points[triangle.v1()].z() >= center.z())
      {
        index1 = triangulation.uniquePoints().size();
        p11.setZ(center.z()-offset);
        p11.setY(points[triangle.v1()].y());
        p11.setX(points[triangle.v1()].x());
        triangulation.uniquePoints().push_back(p11);

        index2 = triangulation.uniquePoints().size();
        p21.setZ(points[triangle.v1()].z()+offset);
        p21.setY(points[triangle.v1()].y());
        p21.setX(points[triangle.v1()].x());
        triangulation.uniquePoints().push_back(p21);
      }
      else
      {
        index1 = triangulation.uniquePoints().size();
        p11.setZ(points[triangle.v1()].z()-offset);
        p11.setY(points[triangle.v1()].y());
        p11.setX(points[triangle.v1()].x());
        triangulation.uniquePoints().push_back(p11);
        
        index2 = triangulation.uniquePoints().size();
        p21.setZ(center.z()+offset);
        p21.setY(points[triangle.v1()].y());
        p21.setX(points[triangle.v1()].x());
        triangulation.uniquePoints().push_back(p21);
      }
     
      if(points[triangle.v2()].z() >= center.z())
      {
        index3 = triangulation.uniquePoints().size();
        p12.setZ(center.z()-offset);
        p12.setY(points[triangle.v2()].y());
        p12.setX(points[triangle.v2()].x());
        triangulation.uniquePoints().push_back(p12);

        index4 = triangulation.uniquePoints().size();
        p22.setZ(points[triangle.v2()].z()+offset);
        p22.setY(points[triangle.v2()].y());
        p22.setX(points[triangle.v2()].x());
        triangulation.uniquePoints().push_back(p22);
      }
      else
      {
        index5 = triangulation.uniquePoints().size();
        p12.setZ(points[triangle.v2()].z()-offset);
        p12.setY(points[triangle.v2()].y());
        p12.setX(points[triangle.v2()].x());
        triangulation.uniquePoints().push_back(p12);

        index6 = triangulation.uniquePoints().size();
        p22.setZ(center.z()+offset);
        p22.setY(points[triangle.v2()].y());
        p22.setX(points[triangle.v2()].x());
        triangulation.uniquePoints().push_back(p22);
      }
 
      if(points[triangle.v3()].z() >= center.z())
      {
        index5 = triangulation.uniquePoints().size();
        p13.setZ(center.z()-offset);
        p13.setY(points[triangle.v3()].y());
        p13.setX(points[triangle.v3()].x());
        triangulation.uniquePoints().push_back(p13);

        index6 = triangulation.uniquePoints().size();
        p23.setZ(points[triangle.v3()].z()+offset);
        p23.setY(points[triangle.v3()].y());
        p23.setX(points[triangle.v3()].x());
        triangulation.uniquePoints().push_back(p23);
      }
      else
      {
        index5 = triangulation.uniquePoints().size();
        p13.setZ(points[triangle.v3()].z()-offset);
        p13.setY(points[triangle.v3()].y());
        p13.setX(points[triangle.v3()].x());
        triangulation.uniquePoints().push_back(p13);

        index6 = triangulation.uniquePoints().size();
        p23.setZ(center.z()+offset);
        p23.setY(points[triangle.v3()].y());
        p23.setX(points[triangle.v3()].x());
        triangulation.uniquePoints().push_back(p23);
      }
    }

    Geometry::Triangle triangle1(index1, index3, index5);
    halfSectionTriangles1.push_back(triangle1);

    Geometry::Triangle triangle2(index2, index4, index6);
    halfSectionTriangles2.push_back(triangle2);
  }

  writer.write(filePath1, halfSectionTriangles1, triangulation.uniquePoints());
  writer.write(filePath2, halfSectionTriangles2, triangulation.uniquePoints());
}