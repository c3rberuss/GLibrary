#ifndef GLIBRARY_LIBRARY_H
#define GLIBRARY_LIBRARY_H

void drawLine(float x1, float y1, float x2, float y2, float border);
void drawCircleBorder(float radius, float h, float k, float border, float n_points);
void drawCircleSolid(float radius, float h, float k, float n_points);
void drawRectangleBorder(float x, float y, float height, float width, float border);
void drawRectangleSolid(float x, float y, float height, float width);
void drawCircleSegmentLine(float radius, float x, float y, float degree_segment, float start_degree, float n_points);
void drawCircleSegmentSolid(float radius, float h, float k, float degree_segment, float start_degree, float n_points);

#endif