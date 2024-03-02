#include <limits>
#include <iostream>
#include "../headers/boundingBox.h"
#include "../headers/writer.h"

// Calculate bounding box of the object
void Feature ::BoundingBox::calculateBoundingBox(Geometry::Point3D& minVertex, Geometry::Point3D& maxVertex, Geometry::Triangulation& triangulation)
{
  minVertex = {std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), std::numeric_limits<float>::max()};
  maxVertex = {std::numeric_limits<float>::min(), std::numeric_limits<float>::min(), std::numeric_limits<float>::min()};

  for (const auto &vertex : triangulation.uniquePoints())
  {
    minVertex.setX(std::min(minVertex.x(), vertex.x()));
    minVertex.setY(std::min(minVertex.y(), vertex.y()));
    minVertex.setZ(std::min(minVertex.z(), vertex.z()));

    maxVertex.setX(std::max(maxVertex.x(), vertex.x()));
    maxVertex.setY(std::max(maxVertex.y(), vertex.y()));
    maxVertex.setZ(std::max(maxVertex.z(), vertex.z()));
  }
}

// Calculate the center of the bounding box
Geometry::Point3D Feature ::BoundingBox::calculateBoundingBoxCenter(const Geometry::Point3D& minVertex, const Geometry::Point3D& maxVertex)
{
  Geometry::Point3D center;
  center.setX((minVertex.x() + maxVertex.x()) / 2);
  center.setY((minVertex.y() + maxVertex.y()) / 2);
  center.setZ((minVertex.z() + maxVertex.z()) / 2);
  return center;
}