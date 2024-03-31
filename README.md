# Half section View - 
HalfDection View is a C++ project designed to read any .stl file and create a half section view. Data is stored in form of triangulation

## File Structure
point3D.h: Defines a class for a 3D point with x, y, and z coordinates.

triangle.h: Represents a 3D triangle using three indices.

triangulation.h: Manages a collection of triangles forming a 3D mesh.

boundingBox.h: Implements functionality for bounding box calculations.

halfSection.h: Handles operations related to half sections of 3D objects.

stlReader.h: Reads .stl files and populates a triangulation object.

writer.h: Manages writing data to files.

## Directories
inputfiles: Stores input files like .stl and .obj files.
outputfiles: Stores output files such as .txt, .obj, and .stl files.
