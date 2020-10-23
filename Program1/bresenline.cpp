#include<stdio.h>
#include<gl/glut.h>

int x1,y1,x2,y2;
int first = 0;
int draw = 0;

void display(int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();	
}

void draw_line()
{
	int dx,dy,i,e;
	int incx,incy,inc1,inc2;
	int x,y;
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	dx=x2-x1;
	dy=y2-y1;
	if(dx<0)
	{
		dx=-dx;
	}

	if(dy<0)
	{
		dy=-dy;
	}
	
	incx=1;
	if(x2<x1)
		incx=-1;
	
	incy=1;
	if(y2<y1)
		incy=-1;
	
	x = x1;
	y = y1;
	if(dx>dy)
	{
		display(x,y);
		e=2*dy-dx;
		inc1=2*(dy-dx);
		inc2=2*dy;
		for(i=0;i<dx;i++)
		{
			if(e>=0)
			{
				y+=incy;
				e+=inc1;
			}
			else
			{
				e+=inc2;
			}
			x+=incx;
			display(x,y);
		}
	}
	else
	{
		display(x,y);
		e=2*dx-dy;
		inc1=2*(dx-dy);
		inc2=2*dx;
		for(i=0;i<dy;i++)
		{
			if(e>=0)
			{
				x+=incx;
				e+=inc1;
			}
			else
			{
				e+=inc2;
			}
			y+=incy;
			display(x,y);
		}
	}
	glFlush();
}

void init()
{
	glClearColor(1,1,1,1);
	glColor3f(1.0,0.0,0.0);
	glPointSize(3.0);
	gluOrtho2D(10,500,10,500);
}

int main(int argc, char *argv[])
{
	printf("Bresenham's line drawing\nEnter the co-ordinated of first point: ");
	scanf("%d %d", &x1, &y1);
	printf("Enter the co-ordinates of second point: ");
	scanf("%d %d", &x2, &y2);
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(5,5);
	glutCreateWindow("CSE");
	
	init();
	glutDisplayFunc(draw_line);
	glutMainLoop();  
	
	return 1;
}