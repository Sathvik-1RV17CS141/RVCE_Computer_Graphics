#include<stdio.h>
#include<gl/glut.h>

int xc,yc,r;
void draw_circle(int xc,int yc, int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(xc+x,yc+y);
		glVertex2i(xc-x,yc+y);
		glVertex2i(xc+x,yc-y);
		glVertex2i(xc-x,yc-y);

		glVertex2i(xc+y,yc+x);
		glVertex2i(xc-y,yc+x);	
		glVertex2i(xc+y,yc-x);
		glVertex2i(xc-y,yc-x);
	glEnd();
}

void circlebres()
{
	glClear(GL_COLOR_BUFFER_BIT);
	int x=0,y=r;
	int d=3-2*r;
	while(x<=y)
	{
		draw_circle(xc,yc,x,y);
		x++;
		if(d<0)
			d=d+4*x+6;
		else
		{
			y--;
			d=d+4*(x-y)+10;
		}
		draw_circle(xc,yc,x,y);
	}
	glFlush();
}

void init()
{
	glClearColor(1,1,1,1);
	glColor3f(1.0,0.0,0.0);
	glPointSize(3.0);
	gluOrtho2D(0,300,0,300);
}

int main(int argc, char *argv[])
{
	printf(" Bresenham’s circle drawing\n");
	printf("Enter the co-ordinates of the center of circle:");
	scanf("%d %d", &xc, &yc);
	printf("Enter radius of the circle");
	scanf("%d", &r);
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(5,5);
	glutCreateWindow("Program2");
	glutDisplayFunc(circlebres);
	
	init();
	glutMainLoop();  
	return 1;
} 

