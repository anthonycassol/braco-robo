/**
**/

#include <GL/glut.h>
#include <math.h>

#define SCREEN_X 800
#define SCREEN_Y 800


//Criação da classe Cubo
class Cubo {
public:
	
	double x, y, z; //coordenadas
	double angulo = 0.0f; //angulo
	double scale = 1.0f; //escala do cubo
	double corR, corG, corB;  //cores
	int rY; //flag para verificar se faz rotação eixo Y 
	float rYvalue;  //valor rotacao eixo y

	//rotaciona eixo z para esquerda
	void updateLeft(void) {
		this->angulo -= 10;	
	}
	
	//rotaciona eixo z para direita
	void updateRight(void) {
		this->angulo += 10;
	}

	//rotaciona eixo Y esquerda
	void rotateLeftY(void) {
		this->rY = 1;
		this->rYvalue += 3.0;
	}

	//rotaciona eixo Y direita
	void rotateRightY(void) {
		this->rY = 1;
		this->rYvalue -= 3.0;
	}

	//desenha o cubo
	void display(void) {
		glColor3f(this->corR, this->corG, this->corB);
		glRotatef(this->angulo, 0.0f, 0.0f, 1.0f);
		glTranslatef(this->x, this->y, 0.0f);
		glScalef(1.0f, this->scale, 1.0f);

		//verifica se deve fazer a rotação no eixo Y
		if (this->rY = 1) {
			glRotatef(this->rYvalue, 0.0f, 1.0f, 0.0f);
			this->rY = 0;
		}

		glutWireCube(7);
	}
};

//instancia 4 cubos
Cubo cubos[4];

//display geral
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

	//linha eixo y
	glLineWidth(1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, 550.0f, 0.0f);
	glVertex3f(0.0f, -550.0f, 0.0f);
	glEnd();

	//linha eixo x
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(550.0f, 0.0f, 0.0f);
	glVertex3f(-550.0f, 0.0f, 0.0f);
	glEnd();

	//desenha os cubos
	glPushMatrix();
	for (int i = 0; i <= 3; i++) {
		cubos[i].display();
	}

	glColor3f(0.4f, 0.0f, 1.0f);
	glRotatef(-20.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, -6.0f, 0.0f);
	glScalef(0.4f, 1.0f, 1.0f);
	glutWireCube(4.0f);

	glColor3f(0.4f, 0.0f, 1.0f);
	glRotatef(20.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glScalef(0.4f, 1.0f, 1.0f);
	glutWireCube(4.0f);
	
	glPopMatrix();

	glutSwapBuffers();
}

//Função para verificar caracter do teclado
void keyboard(unsigned char a, int x, int y)
{
	
	//ira verificar qual caractere e o que fazer. Note que movimentos no eixo z tem angulos limitados

	if (a == 'q') {
		if (cubos[1].angulo >= -25) {
			cubos[1].updateLeft();
		}
	}
	else if (a == 'a') {
		if (cubos[1].angulo <= 25) {
			cubos[1].updateRight();
		}
	}

	else if (a == 'w') {
		if (cubos[2].angulo >= -30) {
			cubos[2].updateLeft();
		}
	}
	else if (a == 's') {
		if (cubos[2].angulo <= 30) {
			cubos[2].updateRight();
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

	//aqui movimenta todos os cubos no eixo x
	else if (a == 'z') {
		cubos[0].x -= 1.0f;
	}
	else if (a == 'x') {
		cubos[0].x += 1.0f;		
	}

	// Request display update
	glutPostRedisplay();
}


//verificacao se apertar setas
void especial(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		break;
	case GLUT_KEY_DOWN:
		break;
	case GLUT_KEY_LEFT:
		cubos[0].rotateLeftY();
		break;
	case GLUT_KEY_RIGHT:
		cubos[0].rotateRightY();
		break;
	}

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

	
	//inicia cubo 0
	cubos[0].x = 0.0f;
	cubos[0].y = -10.0f;
	cubos[0].corR = 0.0f; cubos[0].corG = 0.0f; cubos[0].corB = 0.0f;

	//inicia cubo 1
	cubos[1].x = 0.0f;
	cubos[1].y = -9.0f;
	cubos[1].corR = 1.0f; cubos[1].corG = 0.0f; cubos[1].corB = 0.0f;

	//inicia cubo 2
	cubos[2].x = 0.0f;
	cubos[2].y = -9.0f;
	cubos[2].corR = 0.0f; cubos[2].corG = 1.0f; cubos[2].corB = 0.0f;

	//inicia cubo 3
	cubos[3].x = 0.0f;
	cubos[3].y = -11.0f;
	//o cubo 3 te escala maior no Y
	cubos[3].scale = 1.5f;
	cubos[3].corR = 0.0f; cubos[3].corG = 0.0f; cubos[3].corB = 1.0f;

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(especial);

	glutMainLoop();
	return 0;
}
