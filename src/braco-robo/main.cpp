/**
**/

#include <GL/glut.h>
#include <math.h>

#define SCREEN_X 800
#define SCREEN_Y 800

class Cubo {
public:

	double x, y, z;
	double angulo;
	double corR, corG, corB;

	void updateLeft(void) {
		this->angulo -= 10;
		//this->y += 1.0f;
	}
	
	void updateRight(void) {
		this->angulo += 10;
		//this->y += 1.0f;
	}

	void display(void) {
		//desenha o cubo
		glColor3f(this->corR, this->corG, this->corB);
		glTranslatef(this->x, this->y, 0.0f);
		glRotatef(this->angulo, 0.0f, 0.0f, 1.0f);
		glutWireCube(7);
	}
};

Cubo cubos[4];

////////////////////////////////////////////////////////////////////////////////////////
void display(void)
{
	Sleep(10);
	
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100, 100, 100, -100, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 2,  //from. Posicao onde a camera esta posicionada
		0, 0, 0,  //to. Posicao absoluta onde a camera esta vendo
		0, 1, 0); //up. Vetor Up.

	glLineWidth(1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 550.0f, 0.0f);
	glVertex3f(0.0f, -550.0f, 0.0f);
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(550.0f, 0.0f, 0.0f);
	glVertex3f(-550.0f, 0.0f, 0.0f);
	glEnd();

	for (int i = 0; i <= 3; i++) {
		cubos[i].display();
	}


	glutSwapBuffers();
}

void keyboard(unsigned char a, int x, int y)
{
	if (a == '') {
		cubos[1].x += 5;
	}
	else if (a == 'q') {
		if (cubos[1].angulo >= -25) {
			cubos[1].updateLeft();
			cubos[2].updateLeft();
			cubos[3].updateLeft();
		}
	}
	else if (a == 'a') {
		if (cubos[1].angulo <= 25) {
			cubos[1].updateRight();
			cubos[2].updateRight();
			cubos[3].updateRight();
		}
	}

	else if (a == 'w') {
		if (cubos[2].angulo >= -30) {
			cubos[2].updateLeft();
			cubos[3].updateLeft();
		}
	}
	else if (a == 's') {
		if (cubos[2].angulo <= 30) {
			cubos[2].updateRight();
			cubos[3].updateRight();
		}
	}


	else if (a == 'e') {
		if (cubos[3].angulo >= -40) {
			cubos[3].updateLeft();
		}
	}
	else if (a == 'd') {
		if (cubos[3].angulo <= 40) {
			cubos[3].updateRight();
		}
	}

	// Request display update
	glutPostRedisplay();
}


////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int  argc = 0;
	glutInit(&argc, NULL);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(SCREEN_X, SCREEN_Y);
	glutInitWindowPosition(250, 10);
	/* create window */
	glutCreateWindow("Braço Robô");

	
	
	cubos[0].x = 0.0f;
	cubos[0].y = -10.0f;
	cubos[0].angulo = 0.0f;
	cubos[0].corR = 0.0f; cubos[0].corG = 0.0f; cubos[0].corB = 0.0f;

	cubos[1].x = 0.0f;
	cubos[1].y = -7.0f;
	cubos[1].angulo = 0.0f;
	cubos[1].corR = 1.0f; cubos[1].corG = 0.0f; cubos[1].corB = 0.0f;

	cubos[2].x = 0.0f;
	cubos[2].y = -7.0f;
	cubos[2].angulo = 0.0f;
	cubos[2].corR = 0.0f; cubos[2].corG = 1.0f; cubos[2].corB = 0.0f;

	cubos[3].x = 0.0f;
	cubos[3].y = -7.0f;
	cubos[3].angulo = 0.0f;
	cubos[3].corR = 0.0f; cubos[3].corG = 0.0f; cubos[3].corB = 1.0f;

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}
