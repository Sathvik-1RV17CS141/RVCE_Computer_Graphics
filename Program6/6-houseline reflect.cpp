#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
GLfloat house[2][9]={{100.0,100.0,175.0,250.0,250.0,150.0,150.0,200.0,200.0},        {100.0,300.0,400.0,300.0,100.0,100.0,150.0,150.0,100.0}};
GLfloat theta,m,c;
GLfloat h=100.0;
GLfloat k=100.0;
void drawhouse()
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(house[0][0],house[1][0]);
    glVertex2f(house[0][1],house[1][1]);
    glVertex2f(house[0][3],house[1][3]);
    glVertex2f(house[0][4],house[1][4]);
    glEnd();
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(house[0][5],house[1][5]);
    glVertex2f(house[0][6],house[1][6]);
    glVertex2f(house[0][7],house[1][7]);
    glVertex2f(house[0][8],house[1][8]);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(house[0][1],house[1][1]);
    glVertex2f(house[0][2],house[1][2]);
    glVertex2f(house[0][3],house[1][3]);
    glEnd();
}
void display()
{
    int i;
	float sin1=sin(theta);
	float cos1=cos(theta);
	float x1=0;
	float x2=500;
	float y1=m*x1+c;
	float y2=m*x2+c;
	
    GLfloat m[16];
    for(i=0;i<15;i++)
        m[i]=0.0;
    m[0]=cos1*cos1-sin1*sin1;
    m[1]=2*sin1*cos1;
    m[4]=2*sin1*cos1;
    m[5]=sin1*sin1-cos1*cos1;
    m[12]=2*(-c)*cos1*sin1;
    m[13]=(-c)*(sin1*sin1-cos1*cos1)+c;
    m[10]=1;
    m[15]=1;
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    drawhouse();
    glPushMatrix();
    glMultMatrixf(m);
    drawhouse();
    glPopMatrix();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();

    glFlush();
	}
void myinit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-499.0,499.0,-499.0,499.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv)
{

    printf("enter the value of m(y=mx+c):");
    scanf("%f",&m);
	printf("Enter the value of c:");
	scanf("%f",&c);
    //theta=theta*3.141/180;
	theta=atan(m);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("reflected house");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}