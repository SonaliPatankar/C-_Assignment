# Half section View - 
This project provides functionalities for triangulation, geometry processing, and file handling.

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

## Usage
Triangulation and Geometry Processing: Utilize the provided components for tasks such as optimization, file conversion, and geometry processing.
Reading Files: Use the appropriate reader components like stlReader.h to read input files.
Writing Files: Utilize writer.h to write processed data to output files.
Bounding Box and Half Section Operations: Explore functionalities provided by boundingBox.h and halfSection.h for specific tasks related to geometry processing.
