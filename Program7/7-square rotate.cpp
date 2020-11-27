#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>


#define degtorad 180.0/3.14159

static GLfloat spin=0.0;
GLfloat x,y;
int singleb,doubleb;

void myinit()
{
	glClearColor(01,01,001,01);
	glColor3f(01,0,0);
	gluOrtho2D(-2,2,-2,2);

}
void spindisplay()
{
	spin=spin+0.00025;
	if(spin>360) spin-=360;
	x=cos(degtorad*spin);
	y=sin(degtorad*spin);
	
	glutSetWindow(singleb);
	glutPostRedisplay(); 
	glutSetWindow(doubleb);
	glutPostRedisplay();
	
}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		glutIdleFunc(spindisplay);
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
		glutIdleFunc(NULL);
}


void myreshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		gluOrtho2D(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w);
	else 
		gluOrtho2D(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void square()
{    
	glBegin(GL_QUADS);
	glColor3f(01,0,0);
	glVertex2f(x,y);
	glColor3f(0,01,0);
	glVertex2f(-y,x);
	glColor3f(0,0,01);
    glVertex2f(-x,-y);
	glColor3f(01,0,01);
	glVertex2f(y,-x);
	glEnd();

}
void display()
{   
	glClear(GL_COLOR_BUFFER_BIT);
	square();
	glFlush();
}

void displayd()
{   
    glClear(GL_COLOR_BUFFER_BIT);
	square();
	glutSwapBuffers();
}

int main(int argc,char **argv)
{
	
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	singleb=glutCreateWindow("single buffer");
	myinit();
    glutDisplayFunc(display);
	glutReshapeFunc(myreshape);
	glutIdleFunc(spindisplay);
	glutMouseFunc(mouse);
	
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,00);
	doubleb=glutCreateWindow("double buffer");
	myinit();
	glutDisplayFunc(displayd);
	glutReshapeFunc(myreshape);
	glutIdleFunc(spindisplay);
	glutMouseFunc(mouse);
	
	glutMainLoop();
}