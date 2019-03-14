#include "gl.h"
#include <iostream>
#include <GL/glut.h>
#include <math.h>

void drawLine(float x1, float y1, float x2, float y2, float border){


    glLineWidth(border);
    glBegin(GL_LINE);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);

    glEnd();

}


void drawCircleBorder(float radius, float h, float k, float border, float n_points){


    glLineWidth(border);
    glBegin(GL_LINE);

    for( float angle = 0; angle <= 360; angle+=(360/n_points) ){

        glVertex2f((radius * cos(M_PI * (angle, 180))) + h,(radius * sin(M_PI*(angle / 360)))+k);

    }

    glEnd();

}


void drawCircleSolid(float radius, float h, float k, float n_points){

    glBegin(GL_POLYGON);

    for( float angle = 0; angle <= 360; angle+=(360/n_points) ){

        glVertex2f((radius * cos(M_PI * (angle, 180))) + h,(radius * sin(M_PI*(angle / 360)))+k);

    }

    glEnd();

}


void drawRectangleBorder(float x, float y, float height, float width, float border){


    glLineWidth(border);
    glBegin(GL_LINE_LOOP);

    glVertex2f(x, y);
    glVertex2f(x, y+height);
    glVertex2f(x+width, y+height);
    glVertex2f(x+width, y);

    glEnd();

}


void drawRectangleSolid(float x, float y, float height, float width){

    glBegin(GL_QUADS);

    glVertex2f(x, y);
    glVertex2f(x, y+height);
    glVertex2f(x+width, y+height);
    glVertex2f(x+width, y);

    glEnd();

}

void drawCircleSegmentLine(float radius, float h, float k, float degree_segment, float start_degree, float n_points, float border){

    glLineWidth(border);
    glBegin(GL_LINE);

    for( float angle = start_degree; angle <= degree_segment; angle+=(degree_segment/n_points) ){

        glVertex2f((radius * cos(M_PI * (angle, 180))) + h,(radius * sin(M_PI*(angle / 360)))+k);

    }

    glEnd();

}


void drawCircleSegmentSolid(float radius, float h, float k, float degree_segment, float start_degree, float n_points){

    glBegin(GL_POLYGON);

    glVertex2f(h,k);
    for( float angle = start_degree; angle <= degree_segment; angle+=(degree_segment/n_points) ){

        glVertex2f((radius * cos(M_PI * (angle, 180))) + h,(radius * sin(M_PI*(angle / 360)))+k);

    }

    glEnd();

}