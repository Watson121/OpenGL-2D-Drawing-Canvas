#include "include\freeglut.h"	// OpenGL toolkit - in the local shared folder
#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <cstdlib>
#include <cstdio>

#define X_CENTRE 0.0      /* centre point of square */
#define Y_CENTRE 0.0
#define LENGTH   1.0      /* lengths of sides of square */
float lineX, lineY;	      //Initial Postion of the Line
using namespace std;

//ClASSES
class Triangle {

private:

	GLfloat x, y;
	GLfloat x1, x2, x3, y1, y2, y3;
	GLfloat length;

public:

	Triangle(GLfloat l, GLfloat xVal, GLfloat yVal) {
		
		x = xVal;
		y = yVal;
		length = l;
		
		x1 = x + length / 2; 
		y1 = y + length / 2;
		x2 = x + length / 2; 
		y2 = y - length / 2;
		x3 = x - length / 2; 
		y3 = y - length / 2;

		drawTriangle();
	}

	void drawTriangle() {
		glColor3f(0.9, 0, 0);
		glBegin(GL_TRIANGLES);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glVertex2f(x3, y3);
		glEnd();
	}
};

class Square {

private:

	GLfloat x, y;
	GLfloat x1, y1, x2, y2, x3, y3, x4, y4;
	GLfloat length;

public:

	Square(GLfloat l, GLfloat xVal, GLfloat yVal) {

		x = xVal;
		y = yVal;
		length = l;



		x1 = x - length / 2;
		y1 = y + length / 2;
		x2 = x + length / 2;
		y2 = y + length / 2;
		x3 = x + length / 2;
		y3 = y - length / 2;
		x4 = x - length / 2;
		y4 = y - length / 2;

		drawSquare();
	}

	void drawSquare() {
		glColor3f(0.9, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glVertex2f(x3, y3);
		glVertex2f(x4, y4);
		glEnd();
	}

	void animateSquare() {
		x = 0;
		y = y + 1;

		x1 = x - length / 2;
		y1 = y + length / 2;
		x2 = x + length / 2;
		y2 = y + length / 2;
		x3 = x + length / 2;
		y3 = y - length / 2;
		x4 = x - length / 2;
		y4 = y - length / 2;

		drawSquare();
	}


};

class Circle {

private:

	GLfloat x, y, radius;

public:
	Circle(GLfloat r, GLfloat xVal, GLfloat yVal) {

		x = xVal;
		y = yVal;
		radius = r;
		



		drawCircle();
	}

	void drawCircle() {
		glColor3f(0.9, 0, 0);

		glBegin(GL_POLYGON);
		GLfloat xc1, yc1;
		GLdouble PI = 3.14159;

		for (GLfloat i = 0; i < 360; i++)
		{
			xc1 = x + radius * cos(i * PI / 180);
			yc1 = y + radius * sin(i * PI / 180);
			glVertex2f(xc1, yc1);
		}
		
		glEnd();
	}

	void animateCircle(GLfloat xVal, GLfloat yVal) {
		x = xVal;
		y = yVal;
		drawCircle();
	}

};

class Point {
private:

	GLfloat x, y;

public:

	Point(GLfloat xVal = 0, GLfloat yVal = 0) {
		x = xVal;
		y = yVal;



		drawPoint();
	}

	void drawPoint() {
		glColor3f(0.0, 0.0, 0.0);
		glPointSize(8);

		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();

	}
};

class Line {

private:
	GLfloat x1, y1, x2, y2;

public:

	Line(GLfloat x1Val = 0, GLfloat y1Val = 0, GLfloat x2Val = 0, GLfloat y2Val = 0) {

		x1 = x1Val;
		y1 = y1Val;
		x2 = x2Val;
		y2 = y2Val;

		if (x1 < -8) {
			x1 = -8;
		}

		if (y1 > 8) {
			y1 = 8;
		}

		if (x2 < -8) {
			x2 = -8;
		}

		if (y2 > 8) {
			y2 = 8;
		}
	}
	void getPostions() {

		drawLine();

	}

	void drawLine() {
		glColor3f(0.0, 0.0, 0.0);
		glLineWidth(8);

		glBegin(GL_LINES);

		glVertex2f(x1, y1);
		glVertex2f(x2, y2);

		glEnd();
	}


};

class SquareLine {

private:

	GLfloat x, y;
	GLfloat x1, y1, x2, y2, x3, y3, x4, y4;
	GLfloat length;

public:

	SquareLine(GLfloat l, GLfloat xVal, GLfloat yVal) {

		x = xVal;
		y = yVal;
	    length = l;


		x1 = x - length / 2;
		y1 = y + length / 2;
		x2 = x + length / 2;
		y2 = y + length / 2;
		x3 = x + length / 2;
		y3 = y - length / 2;
		x4 = x - length / 2;
		y4 = y - length / 2;

		drawSquare();

	}

	void drawSquare() {

		glColor3f(0, 0, 0);
		glLineWidth(3);
		glBegin(GL_LINE_LOOP);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glVertex2f(x3, y3);
		glVertex2f(x4, y4);
		glEnd();
	}

};

class LineTriangle {

private:

	GLfloat x, y;
	GLfloat x1, x2, x3, y1, y2, y3;
	GLfloat length;

public:

	LineTriangle(GLfloat l, GLfloat xVal, GLfloat yVal) {

		x = xVal;
		y = yVal;
		length = l;


		x1 = x + length / 2;
		y1 = y + length / 2;
		x2 = x + length / 2;
		y2 = y - length / 2;
		x3 = x - length / 2;
		y3 = y - length / 2;

		drawTriangle();

	}

	void drawTriangle() {
		glColor3f(0, 0, 0);
		glLineWidth(3);
		glBegin(GL_LINE_LOOP);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glVertex2f(x3, y3);
		glEnd();
	}
};

//GLOBAL VARIABLES
GLfloat red = 1, green = 1, blue = 1;
GLfloat x1Val = 0, y1Val = 0, x2Val = 0, y2Val = 0;
GLfloat mouseX, mouseY;
GLdouble PI = 3.14159;
GLfloat angle;
int numberOfClicks = 1;	//Tracks how many times the mouse has been clicked

bool gridActive = true;
bool rightButtonClicked, leftButtonClicked;
bool canDraw = false;
bool playAnimation = false;

GLfloat angle1 = 0.0;   //rotation angle for helix
GLfloat R = 3;  // Radius of helix
GLfloat t;

//Booleans to check if the objects will move up or not
bool moveUp, moveDown, moveLeft, moveRight;

char state;

//Positions of Objects on the Grid
std::vector< float > trianglePos; //Postions of Triangles
std::vector< float > squarePos;	//Postions of Squares
std::vector< float > circlePos;	//Postions of Circles
std::vector< float > pointsPos; //Postions of Points
std::vector< float > linePos; //Postions of Lines
std::vector< float > squareLinePos; //Postions of Square Lines
std::vector< float > triangleLinePos; //Postions of Triangle Lines
std::vector< float > animateCirclePos; //Postions of Circle Animations


//FOR ANIMATION
std::vector< Square > squaresArray;
std::vector< float > squaresArrayPos;

//DECLEARING THE FUNCTIONS
//Drawing the Menu and setting up the controls
void drawMenu();
void drawButton(GLfloat length, GLfloat x, GLfloat y, char typeOfButton);
void drawActiveButton(GLfloat length, GLfloat x, GLfloat y);
void drawGrid();
void userControls(unsigned char key, int x, int y);

//Interaction with Mouse
bool drawInvisbleBox(GLfloat length, GLfloat x, GLfloat y);
bool withinGridCheck();

void drawing();
void mouseClick();

//Shape Positions

void drawLines(GLfloat length, GLfloat x, GLfloat y);
void drawText(string Text, float x, float y, GLfloat r, GLfloat g, GLfloat b);
//void spinSquare(bool xaxis, bool yaxis, bool zaxis, GLfloat rotation, GLfloat length, GLfloat xpos, GLfloat ypos, bool multiplyMatrix);
//void spinTriangle(bool xaxis, bool yaxis, bool zaxis, GLfloat rotation, GLfloat length, GLfloat xpos, GLfloat ypos, bool multiplyMatrix);

void animation();

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
}

/* display callback function
called whenever contents of window need to be re-displayed */
//this is the all important drawing method - all drawing code goes in here
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);   /* clear window */

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (playAnimation == true) {
		animation();
	}

	drawText("2D Drawing Canvas - Adam Tedder", -1, -9, 0.0, 0.0, 0.0);

	drawMenu();

	drawButton(2, -7, 9, 'a');
	drawButton(2, -5, 9, 'b');
	drawButton(2, -3, 9, 'c');
	drawButton(2, -9, 7, 'd');
	drawButton(2, -9, 5, 'e');
	drawButton(2, -9, 3, 'f');
	drawButton(2, -9, 1, 'g');

	if (gridActive == true) {
		drawGrid(); 
	}

	drawing();
	glutSwapBuffers();

	glFlush();     /* execute drawing commands in buffer */
}

/* graphics initialisation */
void init(void)
{
	glClearColor(1, 1, 1, 0.0);   /* window will be cleared to black */
}

void drawText(string Text, float x, float y, GLfloat r, GLfloat g, GLfloat b) {

	/*This function draws text that displays on the canvas*/

	glColor3f(r, g, b);

	glRasterPos2f(x, y);

	for (int c = 0; c<Text.size(); c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, Text[c]);
	}
	
}

void drawMenu() {

	glColor3f(0, 0.6, 0.6);

	//Top

	glBegin(GL_POLYGON);
	glVertex2f(-8, 10);
	glVertex2f(10, 10);
	glVertex2f(10, 8);
	glVertex2f(-8, 8);
	glEnd();

	glColor3f(0, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-8, 10);
	glVertex2f(10, 10);
	glVertex2f(10, 8);
	glVertex2f(-8, 8);
	glEnd();

	//Side

	glColor3f(0, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(-10, 8);
	glVertex2f(-8, 8);
	glVertex2f(-8, -10);
	glVertex2f(-10, -10);
	glEnd();

	glColor3f(0, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-10, 8);
	glVertex2f(-8, 8);
	glVertex2f(-8, -10);
	glVertex2f(-10, -10);
	glEnd();

}

void drawGrid() {

	GLfloat x1, y1, x2, y2, x3, y3, x4, y4;
	GLfloat x, y, lengthOfCube;
	int height = 1, length = 1;

	x = -7;
	y = 7;
	lengthOfCube = 2;

	for (height; height <= 9; height++) {
		for (length; length <= 9; length++) {

			x1 = x - lengthOfCube / 2;
			y1 = y + lengthOfCube / 2;
			x2 = x + lengthOfCube / 2;
			y2 = y + lengthOfCube / 2;
			x3 = x + lengthOfCube / 2;
			y3 = y - lengthOfCube / 2;
			x4 = x - lengthOfCube / 2;
			y4 = y - lengthOfCube / 2;

			glColor3f(0.8, 0.8, 0.8);
			glLineWidth(0.01f);

		
			glEnable(GL_LINE_STIPPLE);
			glLineStipple(1, 0x9999);
			glBegin(GL_LINE_LOOP);
		
			glVertex2f(x1, y1);
			glVertex2f(x2, y2);
			glVertex2f(x3, y3);
			glVertex2f(x4, y4);

			glEnd();
			glDisable(GL_LINE_STIPPLE);
			

			x = x + 2;
		}
		length = 1;
		x = -7;
		y = y - 2;
	}

}

void drawButton(GLfloat length, GLfloat x, GLfloat y, char typeOfButton) {

	/*This function creates the button. It also draws the shape that the button 
	draws within the button, this is done by using the parameter 'typeOfButton' 
	and depending on the value of this parameter a different shape will be drawn in
	the button. */


	GLfloat x1, y1, x2, y2, x3, y3, x4, y4;
	x1 = x - length / 2;
	y1 = y + length / 2;
	x2 = x + length / 2;
	y2 = y + length / 2;
	x3 = x + length / 2;
	y3 = y - length / 2;
	x4 = x - length / 2;
	y4 = y - length / 2;

	glColor3f(0, 0.9, 1);

	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	glColor3f(0, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();

	

	if (typeOfButton == 'a') {
		if (state == 'a') {
			drawActiveButton(2, -7, 9);
		}
		Triangle *triangle = new Triangle(1, x, y);
	}

	if (typeOfButton == 'b') {
		if (state == 'b') {
			drawActiveButton(2, -5, 9);
		}
		Square *square = new Square(1, x, y);
	}

	if (typeOfButton == 'c') {
		if (state == 'c') {
			drawActiveButton(2, -3, 9);
		}
		Circle *circle = new Circle(0.5, x, y);
	}

	if (typeOfButton == 'd') {
		if (state == 'd') {
			drawActiveButton(2, -9, 7);
		}
		Point *points = new Point(x, y);
	}

	if (typeOfButton == 'e') {
		if (state == 'e') {
			drawActiveButton(2, -9, 5);
		}
		drawLines(1, x, y);
	}

	if (typeOfButton == 'f') {
		if (state == 'f') {
			drawActiveButton(2, -9, 3);
		}
		SquareLine *squareLine = new SquareLine(1, x, y);
	}

	if (typeOfButton == 'g') {
		if (state == 'g') {
			drawActiveButton(2, -9, 1);
		}
		LineTriangle *lineTriangle = new LineTriangle(1, x, y);
	}
	
	glFlush();

}

void drawActiveButton(GLfloat length, GLfloat x, GLfloat y) {

	GLfloat x1, y1, x2, y2, x3, y3, x4, y4;
	x1 = x - length / 2;
	y1 = y + length / 2;
	x2 = x + length / 2;
	y2 = y + length / 2;
	x3 = x + length / 2;
	y3 = y - length / 2;
	x4 = x - length / 2;
	y4 = y - length / 2;

	glColor3f(1, 1, 0);

	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();


}

void drawLines(GLfloat length, GLfloat x, GLfloat y) {

	//This function draws Lines

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(8);
	
	glBegin(GL_LINES);

	glVertex2f(x + length / 3, y + length / 3);
	glVertex2f(x - length / 3, y - length / 3);

	glEnd();
}

void animation() {

	GLfloat x, y;

	x = -10;
	y = -12;

	for (int i = 0; i < 100; i++) {
		animateCirclePos.push_back(x);
		animateCirclePos.push_back(y);

		x++;
		
	}


	Circle *cirle = new Circle(1, -10, animateCirclePos[5]);
	Circle *cirle1 = new Circle(0.9, -8, animateCirclePos[7]);
	Circle *cirle2 = new Circle(0.4, -6, animateCirclePos[9]);
	Circle *cirle3 = new Circle(0.5, 0, animateCirclePos[11]);
	Circle *cirle4 = new Circle(2, 2, animateCirclePos[13]);
	Circle *cirle5 = new Circle(0.3, 3, animateCirclePos[15]);
	Circle *cirle6 = new Circle(0.8, 4, animateCirclePos[17]);

	if (playAnimation == true) {
		animateCirclePos[5] = animateCirclePos[5] + 0.06;
		animateCirclePos[7] = animateCirclePos[7] + 0.03;
		animateCirclePos[9] = animateCirclePos[9] + 0.02;
		animateCirclePos[11] = animateCirclePos[11] + 0.01;
		animateCirclePos[13] = animateCirclePos[13] + 0.04;
		animateCirclePos[15] = animateCirclePos[15] + 0.08;
		animateCirclePos[17] = animateCirclePos[17] + 0.1;
	}

	if (animateCirclePos[5] > 12) {
		animateCirclePos[5] = -12;
	}

	if (animateCirclePos[7] > 12) {
		animateCirclePos[7] = -12;
	}

	if (animateCirclePos[9] > 12) {
		animateCirclePos[9] = -12;
	}

	if (animateCirclePos[11] > 12) {
		animateCirclePos[11] = -12;
	}

	if (animateCirclePos[13] > 12) {
		animateCirclePos[13] = -12;
	}

	if (animateCirclePos[15] > 12) {
		animateCirclePos[15] = -12;
	}

	if (animateCirclePos[17] > 12) {
		animateCirclePos[17] = -12;
	}
}



bool drawInvisbleBox(GLfloat length, GLfloat x, GLfloat y) {

	/*Creates an invisble box which checks after the mouse has been clicked, 
	that checks if the mouse is within one of the invisble boxes. If the mouse 
	is within the invisble box, then this function will return as true and if not 
	the function will return as false*/

	GLfloat x1, y1, x2, y2;
	x1 = x - length / 2;
	y1 = y + length / 2;
	x2 = x + length / 2;
	y2 = y - length / 2;


	if (mouseX > x1 && mouseX < x2 && mouseY < y1 && mouseY > y2) {
		return true;
	}
	else {
		return false;
	}
}

void TimerFunction(int value)
{
	glClear(GL_COLOR_BUFFER_BIT);
	angle = angle + 1.0;
	if (angle > 360)angle = 0;

	angle1 += 5.0;
	if (angle1 > 360.0) angle -= 360.0;

	if (playAnimation == true) {
		glutPostRedisplay();
	}
	glutTimerFunc(5, TimerFunction, 0);
	
}

//User functions
void userControls(unsigned char key, int x, int y) {

	/*This functions is the keyboard function, it get what key is being pressed 
	and what the current position of the key being pressed. Also, depending on 
	the key being pressed the program will act acorrdingly*/

	//PRESSING THESE KEYS WILL REMOVE SHAPES FROM THE CANVAS
	if (key == 'l') {
		linePos.clear();
		std::cout << "Cleared Lines \n";	//Clears Lines
	}
	else if (key == 't') {
		trianglePos.clear();
		std::cout << "Cleared Triagnles \n"; //Clears Triangles
	}
	else if (key == 'p') {
		pointsPos.clear();
		std::cout << "Cleared Points \n"; //Clears Points
	}
	else if (key == 'c') {
		circlePos.clear();
		std::cout << "Cleared Circles \n"; // Clears Circles
	}
	else if (key == 'r') {
		squarePos.clear();
		std::cout << "Cleared Squares \n"; // Clears Squares
	}
	else if (key == 27) {
		exit(0);
	}
	else if (key == 32) {
		trianglePos.clear();
		squarePos.clear();
		circlePos.clear();
		pointsPos.clear();
		linePos.clear();
		squareLinePos.clear();
		triangleLinePos.clear();

		std::cout << "Cleared Canvas \n";	//Clears Everything
	}
	
	if (playAnimation == false) {

		if (key == 'w') {	//Moves objects up
			moveUp = true;
			moveDown = false;
			moveLeft = false;
			moveRight = false;

		}
		else if (key == 's') { //Moves objects down
			moveUp = false;
			moveDown = true;
			moveLeft = false;
			moveRight = false;
		}
		else if (key == 'a') { //Moves objects left
			moveUp = false;
			moveDown = false;
			moveLeft = true;
			moveRight = false;
		}
		else if (key == 'd') { //Moves objects right
			moveUp = false;
			moveDown = false;
			moveLeft = false;
			moveRight = true;
		}
		else {					//Sets movement to false, so they don't move on their own.
			std::cout << key;
			moveUp = false;
			moveDown = false;
			moveLeft = false;
			moveRight = false;
		}
	}

	glutPostRedisplay();

}

void myMouse(int button, int state, int x, int y)
{
	/*This is the mouse function. It gets what button is currently being pressed, what the currenty postion of the mouse is
	and if the mouse button is being pressed down or released*/


	float X = x;
	float Y = y;

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		mouseX = float((X / 400 - 1) * 10);
		mouseY = float((-(Y / 400 - 1)) * 10);

		moveUp = false;
		moveDown = false;
		moveLeft = false;
		moveRight = false;

		mouseClick();

		canDraw = withinGridCheck();
	}
	
	glutPostRedisplay();
}

void mouseClick() {

	/*This function calls the 'drawInvisbleBox' function, which is drawn on the same place as the buttons.
	This is done to check if the mouse click is within these invisble boxes. If it comes back true, then
	the corrisponding state will be set, which will allow the user to draw the Polygon, Line or Point they
	want to draw.*/

	if (drawInvisbleBox(2, -7, 9)) {
		state = 'a';
	}
	else if (drawInvisbleBox(2, -5, 9)) {
		state = 'b';
	}
	else if (drawInvisbleBox(2, -3, 9)) {
		state = 'c';
	}
	else if (drawInvisbleBox(2, -9, 7)) {
		state = 'd';
	}
	else if (drawInvisbleBox(2, -9, 5)) {
		state = 'e';
	}
	else if (drawInvisbleBox(2, -9, 3)) {
		state = 'f';
	}
	else if (drawInvisbleBox(2, -9, 1)) {
		state = 'g';
	}

	

}

void drawing() {

	/*Draws the objects on to the canvas, by using the vector postions*/

	//Draws the Triangles
	for (GLfloat i = 0; i < trianglePos.size(); i += 2)
	{
		Triangle *triange = new Triangle(2, trianglePos[i], trianglePos[i + 1]);

		if (state == 'a') {
			if (moveUp == true) {
				trianglePos[i + 1]++;
			}
			else if (moveDown == true) {
				trianglePos[i + 1]--;
			}
			else if (moveLeft == true) {
				trianglePos[i]--; 
			}
			else if (moveRight == true) {
				trianglePos[i]++;
			}
		}

		if (trianglePos[i] < -7) {
			trianglePos[i] = -7;
		}

		if (trianglePos[i + 1] > 7) {
			trianglePos[i + 1] = 7;
		}

	}   
	//Draws the Sqaures
	for (GLfloat i = 0; i < squarePos.size(); i += 2)
	{
		Square *square = new Square(2, squarePos[i], squarePos[i + 1]);

		if (state == 'b') {
			if (moveUp == true) {
				squarePos[i + 1]++;
			}
			else if (moveDown == true) {
				squarePos[i + 1]--;
			}
			else if (moveLeft == true) {
				squarePos[i]--;
			}
			else if (moveRight == true) {
				squarePos[i]++;
			}
		}

		if (squarePos[i] < -7) {
			squarePos[i] = -7;
		}

		if (squarePos[i + 1] > 7) {
			squarePos[i + 1] = 7;
		}

	}	 //Draws the Squares
	//Draws the Circles
	for (GLfloat i = 0; i < circlePos.size(); i += 2)
	{
		Circle *cirle = new Circle(1, circlePos[i], circlePos[i + 1]);

		if (state == 'c') {
			if (moveUp == true) {
				circlePos[i + 1]++;
			}
			else if (moveDown == true) {
				circlePos[i + 1]--;
			}
			else if (moveLeft == true) {
				circlePos[i]--;
			}
			else if (moveRight == true) {
				circlePos[i]++;
			}
		}

		if (circlePos[i] < -7) {
			circlePos[i] = -7;
		}

		if (circlePos[i + 1] > 7) {
			circlePos[i + 1] = 7;
		}
	}	 
	//Draws the Points
	for (GLfloat i = 0; i < pointsPos.size(); i += 2)
	{
		Point *points = new Point(pointsPos[i], pointsPos[i + 1]);

		if (state == 'd') {
			if (moveUp == true) {
				pointsPos[i + 1]++;
			}
			else if (moveDown == true) {
				pointsPos[i + 1]--;
			}
			else if (moveLeft == true) {
				pointsPos[i]--;
			}
			else if (moveRight == true) {
				pointsPos[i]++;
			}
		}

		if (pointsPos[i] < -8) {
			pointsPos[i] = -8;
		}

		if (pointsPos[i + 1] > 8) {
			pointsPos[i + 1] = 8;
		}

	}
	//Draws the Lines
	for (GLfloat i = 0; i < linePos.size(); i += 4)
	{
		Line *line = new Line(linePos[i], linePos[i + 1], linePos[i + 2], linePos[i + 3]);
		line->drawLine();

		if (state == 'e') {
			if (moveUp == true) {
				linePos[i + 1]++;
				linePos[i + 3]++;
			}
			else if (moveDown == true) {
				linePos[i + 1]--;
				linePos[i + 3]--;
			}
			else if (moveLeft == true) {
				linePos[i]--;
				linePos[i + 2]--;
			}
			else if (moveRight == true) {
				linePos[i]++;
				linePos[i + 2]++;
			}
		}
	}
	//Draws the Square Lines
	for (GLfloat i = 0; i < squareLinePos.size(); i += 2)
	{
		SquareLine *lineSquare = new SquareLine(2, squareLinePos[i], squareLinePos[i + 1]);

		if (state == 'f') {
			if (moveUp == true) {
				squareLinePos[i + 1]++;
			}
			else if (moveDown == true) {
				squareLinePos[i + 1]--;
			}
			else if (moveLeft == true) {
				squareLinePos[i]--;
			}
			else if (moveRight == true) {
				squareLinePos[i]++;
			}
		}

		if (squareLinePos[i] < -7) {
			squareLinePos[i] = -7;
		}

		if (squareLinePos[i + 1] > 7) {
			squareLinePos[i + 1] = 7;
		}
	}
	//Draws the Triangle Lines
	for (GLfloat i = 0; i < triangleLinePos.size(); i += 2)
	{
		LineTriangle *lineTriangele = new LineTriangle(2, triangleLinePos[i], triangleLinePos[i + 1]);

		if (state == 'g') {
			if (moveUp == true) {
				triangleLinePos[i + 1]++;
			}
			else if (moveDown == true) {
				triangleLinePos[i + 1]--;
			}
			else if (moveLeft == true) {
				triangleLinePos[i]--;
			}
			else if (moveRight == true) {
				triangleLinePos[i]++;
			}
		}

		if (triangleLinePos[i] < -7) {
			triangleLinePos[i] = -7;
		}

		if (triangleLinePos[i + 1] > 7) {
			triangleLinePos[i + 1] = 7;
		}
	}
}

bool withinGridCheck() {

	//This function checks if the mouse click is within the grid area, and not within the menus

	GLfloat x1 = -8, x2 = 10, y1 = 8, y2 = -10;

	if (mouseX > x1 && mouseX < x2 && mouseY < y1 && mouseY > y2) {

		if (state == 'a') {
			trianglePos.push_back(mouseX);
			trianglePos.push_back(mouseY);
		}
		else if(state == 'b'){
			squarePos.push_back(mouseX);
			squarePos.push_back(mouseY);
		}
		else if (state == 'c') {
			circlePos.push_back(mouseX);
			circlePos.push_back(mouseY);
		}
		else if (state == 'd') {
			pointsPos.push_back(mouseX);
			pointsPos.push_back(mouseY);
		}
		else if (state == 'e') {
			if (numberOfClicks == 1) {
				lineX = mouseX;
				lineY = mouseY;
			}
			else if (numberOfClicks == 2) {
				linePos.push_back(lineX);
				linePos.push_back(lineY);
				linePos.push_back(mouseX);
				linePos.push_back(mouseY);
				numberOfClicks = 0;
			}
			numberOfClicks++;
		}
		else if (state == 'f') {
			squareLinePos.push_back(mouseX);
			squareLinePos.push_back(mouseY);
		}
		else if (state == 'g') {
			triangleLinePos.push_back(mouseX);
			triangleLinePos.push_back(mouseY);
		}

		return true;
	}
	else {
		return false;
	}
}

void dropDownMenu(GLint id) {

	/*This function creates and controls the drop down menu.*/

	if (id == 1) {
		gridActive = true;
		playAnimation = false;
	}

	else if (id == 2) {
		gridActive = false;
		playAnimation = false;
	}
	
	else if (id == 3) {
		playAnimation = true;
		gridActive = false;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("2D Drawing Canvas");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(userControls);
	glutMouseFunc(myMouse);

	glutCreateMenu(dropDownMenu);
	glutAddMenuEntry("GRID ON", 1);
	glutAddMenuEntry("GRID OFF", 2);
	glutAddMenuEntry("ANIMATION", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	cout << "How to Draw: Controls and Interaction \n";
	cout << "\n";
	cout << "1> Left click on a box on the left or upper menu to select a primative or filled shape. \n";
	cout << "\n";
	cout << "2> Right click for menu optoins.\n";
	cout << "\n";
	cout << "3> Click once to draw a point and twice to draw a line";
	cout << "\n";

	while (playAnimation) {
		glutPostRedisplay();
	}

	glutTimerFunc(5, TimerFunction, 0);
	glutMainLoop();
	return 0;
}



