#include "glibrary.h"
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <tuple>



void drawLine2d(float x1, float y1, float x2, float y2, float border){


    glLineWidth(border);
    glBegin(GL_LINES);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);

    glEnd();

}


void drawCircleBorder2d(float radius, float h, float k, float border, float n_points){

    glLineWidth(border);
    glBegin(GL_LINE_LOOP);


    for( float angle = 0; angle <= 360; angle+=(360/n_points) ){


        glVertex2f((radius * cos(angle * (M_PI/ 180))) + h,(radius * sin(angle * (M_PI/ 180)))+k);

    }

    glEnd();

}


void drawCircleSolid2d(float radius, float h, float k, float n_points){

    glBegin(GL_POLYGON);

    for( float angle = 0; angle <= 360; angle+=(360/n_points) ){

        glVertex2f((radius * cos(angle * (M_PI/ 180))) + h,(radius * sin(angle * (M_PI/ 180)))+k);

    }

    glEnd();

}


void drawRectangleBorder2d(float x, float y, float height, float width, float border){


    glLineWidth(border);
    glBegin(GL_LINE_LOOP);

    glVertex2f(x, y);
    glVertex2f(x, y+height);
    glVertex2f(x+width, y+height);
    glVertex2f(x+width, y);

    glEnd();

}


void drawRectangleSolid2d(float x, float y, float height, float width){

    glBegin(GL_QUADS);

    glVertex2f(x, y);
    glVertex2f(x, y+height);
    glVertex2f(x+width, y+height);
    glVertex2f(x+width, y);

    glEnd();

}

void drawCircleSegmentLine2d(float radius, float h, float k, float degree_segment, float start_degree, float n_points,
                             float border){

    glLineWidth(border);
    glBegin(GL_LINE_STRIP);

    for( float angle = start_degree; angle <= degree_segment+start_degree; angle+=(degree_segment/n_points) ){

        glVertex2f((radius * cos(angle * (M_PI/ 180))) + h,(radius * sin(angle * (M_PI/ 180)))+k);

    }

    glEnd();

}


void drawCircleSegmentSolid2d(float radius, float h, float k, float degree_segment, float start_degree, float n_points){

    glBegin(GL_POLYGON);

    glVertex2f(h,k);
    for( float angle = start_degree; angle <= degree_segment+start_degree; angle+=(degree_segment/n_points) ){

        glVertex2f((radius * cos(angle * (M_PI/ 180))) + h,(radius * sin(angle * (M_PI/ 180)))+k);

    }

    glEnd();

}

void drawTriangleBorder2d(float x, float y, float base, float height, float border) {

    glLineWidth(border);

    glBegin(GL_LINE_LOOP);

    glVertex2f(x, y);
    glVertex2f(x+base, y);
    glVertex2f((x+base)/2, y+height);

    glEnd();

}

void drawTriangleSolid2d(float x, float y, float base, float height) {

    glBegin(GL_TRIANGLES);

    glVertex2f(x, y);
    glVertex2f(x+base, y);
    glVertex2f((x+base)/2, y+height);

    glEnd();

}

void drawLineAngle2d(float x, float y, float large, float angle, float border) {

    glLineWidth(border);
    glBegin(GL_LINES);

    glVertex2f(x, y);
    glVertex2f( (large * cos( angle * (M_PI / 180) ))+x,  (large * sin( angle * (M_PI / 180) ))+y);

    glEnd();

}

void drawRectangleBorderAngle2d(float x, float y, float height, float width, float angle, float border) {


    glLineWidth(border);
    glBegin(GL_LINE_LOOP);

    glVertex2f(x, y);//OK


    float tmp_x = (height * cos( (angle + 90) * (M_PI / 180) ))+x;
    float tmp_y = (height * sin( (angle + 90) * (M_PI / 180) ))+y;

    glVertex2f( tmp_x,  tmp_y); //OK

    glVertex2f( (width * cos( angle  * (M_PI / 180) ))+tmp_x,  (width * sin( angle * (M_PI / 180) ))+tmp_y);

    glVertex2f( (width * cos( angle * (M_PI / 180) ))+x,  (width * sin( angle * (M_PI / 180) ))+y);

    glEnd();


}

void drawRectangleSolidAngle2d(float x, float y, float height, float width, float angle) {

    glBegin(GL_QUADS);

    glVertex2f(x, y);//OK


    float tmp_x = (height * cos( (angle + 90) * (M_PI / 180) ))+x;
    float tmp_y = (height * sin( (angle + 90) * (M_PI / 180) ))+y;

    glVertex2f( tmp_x,  tmp_y); //OK

    glVertex2f( (width * cos( angle  * (M_PI / 180) ))+tmp_x,  (width * sin( angle * (M_PI / 180) ))+tmp_y);

    glVertex2f( (width * cos( angle * (M_PI / 180) ))+x,  (width * sin( angle * (M_PI / 180) ))+y);

    glEnd();
}

void drawPlane2d(float height, float width, float border) {

    glBegin(GL_LINES);

    glLineWidth(border);

    glVertex2f(0, -1*height);
    glVertex2f(0, height);
    glVertex2f(-1*width, 0);
    glVertex2f(width, 0);

    glEnd();

}

void drawLineStripVerical2d(float x1, float y1, float length, float border) {

    glLineWidth(border);
    glBegin(GL_LINES);

    glVertex2f(x1, y1);

    for( float y = y1; y<= length; y+=0.1 ){

        glVertex2f(x1, y);

    }

    glEnd();

}

void drawLineStripHorizontal2d(float x1, float y1, float length, float border) {

    glLineWidth(border);
    glBegin(GL_LINES);

    glVertex2f(x1, y1);

    for( float x = x1; x<= length; x+=0.1 ){

        glVertex2f(x, y1);

    }

    glEnd();

}
