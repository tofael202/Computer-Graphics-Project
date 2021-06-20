#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include <windows.h>
#include <GL/glut.h>
#include <time.h>
#include<conio.h>
#include<string.h>


struct SnakePart
{
    char direction[100];
    double x;
    double y;
    double r;
    double g;
    double b;
};

struct SnakePart snakeParts[1000];
int snakeLength = 150;

char currentDirection[100] = "right";
double inc = 0.7;

int food_x, food_y,food_x1,food_y1;
int isFoodEaten = 0;

int score = 0;
int isGameOver = 0;
int showMenu=1;
int menuValue=0;

void drawCircle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}
    }
    glEnd();
}

void keyboardListener(unsigned char key, int x,int y)
{
	switch(key){
        case '1':
            menuValue=1;
			break;
        case 's':
            showMenu=0;
            break;
        default:
			break;
	}
}

void specialKeyListener(int key, int x,int y)
{
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
		    if(strcmp(currentDirection, "left") == 0 || strcmp(currentDirection, "right") == 0 ){
                strcpy(currentDirection, "down");
		    }
			break;
		case GLUT_KEY_UP:		// up arrow key
		    if(strcmp(currentDirection, "left") == 0 || strcmp(currentDirection, "right") == 0 ){
                strcpy(currentDirection, "up");
		    }
			break;

		case GLUT_KEY_RIGHT:
		    if(strcmp(currentDirection, "up") == 0 || strcmp(currentDirection, "down") == 0 ){
                strcpy(currentDirection, "right");
		    }
			break;
		case GLUT_KEY_LEFT:
		    if(strcmp(currentDirection, "up") == 0 || strcmp(currentDirection, "down") == 0 ){
                strcpy(currentDirection, "left");
		    }
			break;

		case GLUT_KEY_PAGE_UP:
			break;
		case GLUT_KEY_PAGE_DOWN:
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			break;
		case GLUT_KEY_END:
			break;

		default:
			break;
	}
}

void mouseListener(int button, int state, int x, int y)
{
	switch(button){
		case GLUT_LEFT_BUTTON:
			break;
		case GLUT_RIGHT_BUTTON:
			break;
		case GLUT_MIDDLE_BUTTON:
			break;
		default:
			break;
	}
}

void drawBorder()
{
    glColor3f(1.0, 0, 0);
    glLineWidth(4.0);

    glBegin(GL_LINES);{
        glVertex3f(10,10,0);
        glVertex3f(590,10,0);

        glVertex3f(10,10,0);
        glVertex3f(10,590,0);

        glVertex3f(10,590,0);
        glVertex3f(590,590,0);

        glVertex3f(590,10,0);
        glVertex3f(590,590,0);
    }
    glEnd();
}
void drawLine()
{
    glColor3f(1.0, 0, 0);
    glLineWidth(4.0);

    glBegin(GL_LINES);{
        glVertex3f(200,300,0);
        glVertex3f(300,300,0);

        glVertex3f(300,300,0);
        glVertex3f(300,400,0);

        glVertex3f(300,400,0);
        glVertex3f(330,400,0);

        glVertex3f(330,400,0);
        glVertex3f(330,300,0);

        glVertex3f(330,300,0);
        glVertex3f(400,300,0);

        glVertex3f(400,300,0);
        glVertex3f(400,270,0);

        glVertex3f(400,270,0);
        glVertex3f(200,270,0);

        glVertex3f(200,270,0);
        glVertex3f(200,300,0);

    }
    glEnd();
}


void drawSnake()
{
    glPushMatrix();

    for(int i=0; i<snakeLength; i++)
    {
        glColor3f(snakeParts[i].r,snakeParts[i].g,snakeParts[i].b);
        glTranslatef(snakeParts[i].x,snakeParts[i].y,0);
        drawCircle(10,10);
        glTranslatef(-snakeParts[i].x,-snakeParts[i].y,0);
    }
    glPopMatrix();
}

void drawFood()
{
    if(isFoodEaten == 1)
    {
        food_x = (rand() % 500)+50;
        food_y = (rand() % 500)+50;
        isFoodEaten = 0;
    }

    glPushMatrix();
    glColor3f(0,1,1);
    glTranslatef(food_x,food_y,0);
    drawCircle(10,10);
    glPopMatrix();
}
void random_generator(){
    int n=0,m=0;
    n = (rand() % 500)+50;
    m=  (rand() % 500)+50;
     if(n <=300 && n >=200 )
               {
                    if( m <= 300 && m >= 299)
                      return random_generator();
                }
                if(n <=300 &&n >=298 )
                {
                    if( m <= 400 && m >= 300)
                      return random_generator();
                }
                if(n <=330 && n >=300 )
                {
                    if( m <= 400 && m >= 400)
                      return random_generator();
                }
                if(n <=330 && n >=300 )
                {
                    if( m <= 400 && m >= 398)
                      return random_generator();
                }
                if(n <=331 && n >=300 )
                {
                    if( m <= 400 && m >= 300)
                      return random_generator();
                }
                if(n <=400 && n >=300 )
                {
                    if( m <= 301 && m >= 300)
                      return random_generator();
                }
                if(n<=401 && n >=400 )
                {
                    if( m <= 300 && m >= 270)
                      return random_generator();
                }
                if(n <=400 && n >=200 )
                {
                    if( m <= 271 && m >= 270)
                      return random_generator();
                }
                if(n <=201 && n >=200 )
                {
                    if( m <= 300 && m >= 270)
                      return random_generator();
                }
              else
              {
                  food_x1=n;
                  food_y1=m;
              }
}
void drawFood1()
{   random_generator();
    if(isFoodEaten == 1)
    {
        food_x=food_x1 ;
        food_y = food_y1;

        isFoodEaten = 0;
    }

    glPushMatrix();
    glColor3f(0,1,1);
    glTranslatef(food_x,food_y,0);
    drawCircle(10,10);
    glPopMatrix();
}






void checkFoodEaten()
{
    if(((snakeParts[0].x-10 >= food_x-10 && snakeParts[0].x-10 <= food_x+10) || (snakeParts[0].x+10 >= food_x-10 && snakeParts[0].x+10 <= food_x+10))
       && ((snakeParts[0].y-10 >= food_y-10 && snakeParts[0].y-10 <= food_y+10) || (snakeParts[0].y+10 >= food_y-10 && snakeParts[0].y+10 <= food_y+10)))
    {
        isFoodEaten = 1;
        score =  score + 1;
        snakeLength = snakeLength + 1;

        if(strcmp(currentDirection, "up") == 0 && strcmp(currentDirection, "down") == 0 && strcmp(currentDirection, "left") == 0 ){
                strcpy(snakeParts[snakeLength-1].direction, "right");
		    }
		if(strcmp(currentDirection, "up") == 0 && strcmp(currentDirection, "down") == 0 && strcmp(currentDirection, "right") == 0){
                strcpy(snakeParts[snakeLength-1].direction, "left");
		    }
		if(strcmp(currentDirection, "left") == 0 && strcmp(currentDirection, "right") == 0 && strcmp(currentDirection, "up") == 0 ){
                strcpy(snakeParts[snakeLength-1].direction, "down");
		    }
		 if(strcmp(currentDirection, "left") == 0 && strcmp(currentDirection, "right") == 0 && strcmp(currentDirection, "down") == 0 ){
                strcpy(snakeParts[snakeLength-1].direction, "up");
		    }
        snakeParts[snakeLength-1].x = snakeParts[snakeLength-2].x ;
        snakeParts[snakeLength-1].y = snakeParts[snakeLength-2].y;
        snakeParts[snakeLength-1].r = 0;
        snakeParts[snakeLength-1].g = 0;
        snakeParts[snakeLength-1].b = 1;
    }
}

void checkBoundaryCrossed()
{
    if(snakeParts[0].x-10 <= 10 || snakeParts[0].x+10 >= 590 || snakeParts[0].y-10 <= 10 || snakeParts[0].y+10 >= 590)
    {
        isGameOver = 1;
    }
}
void checkBoundaryCrossed1()
{
    if(snakeParts[0].x-10 <=300 && snakeParts[0].x-10 >=200 )
    {
        if( snakeParts[0].y-10 <= 300 && snakeParts[0].y-10 >= 299)
          isGameOver =1;
    }
    if(snakeParts[0].x+10 <=300 && snakeParts[0].x+10 >=298 )
    {
        if( snakeParts[0].y+10 <= 400 && snakeParts[0].y+10 >= 300)
          isGameOver =1;
    }
    if(snakeParts[0].x <=330 && snakeParts[0].x >=300 )
    {
        if( snakeParts[0].y-10 <= 400 && snakeParts[0].y-10 >= 400)
          isGameOver =1;
    }
    if(snakeParts[0].x <=330 && snakeParts[0].x >=300 )
    {
        if( snakeParts[0].y-10 <= 400 && snakeParts[0].y-10 >= 398)
          isGameOver =1;
    }
    if(snakeParts[0].x-10 <=331 && snakeParts[0].x-10 >=300 )
    {
        if( snakeParts[0].y-10 <= 400 && snakeParts[0].y-10 >= 300)
          isGameOver =1;
    }

    if(snakeParts[0].x-10 <=400 && snakeParts[0].x-10 >=300 )
    {
        if( snakeParts[0].y-10 <= 301 && snakeParts[0].y-10 >= 300)
          isGameOver =1;
    }
    if(snakeParts[0].x-10 <=401 && snakeParts[0].x-10 >=400 )
    {
        if( snakeParts[0].y-10 <= 300 && snakeParts[0].y-10 >= 270)
          isGameOver =1;
    }
    if(snakeParts[0].x+10 <=400 && snakeParts[0].x+10 >=200 )
    {
        if( snakeParts[0].y +10 <= 271 && snakeParts[0].y+10 >= 270)
          isGameOver =1;
    }
    if(snakeParts[0].x+10 <=201 && snakeParts[0].x+10 >=200 )
    {
        if( snakeParts[0].y +10 <= 300 && snakeParts[0].y+10 >= 270)
          isGameOver =1;
    }
}

void checkBoundaryCrossed2()
{
    if(snakeParts[0].x-10 <= 0)
    {
       //snakeParts[0].x = snakeParts[0].x+ 600 ;
       //drawSnake();

    }
    else if(snakeParts[0].x+10 >= 600)
    {
       snakeParts[0].x = snakeParts[0].x- 600 ;
       //drawSnake();
    }
    else if(snakeParts[0].y-10 <= 0)
    {
       snakeParts[0].y = snakeParts[0].y+ 600 ;
       //drawSnake();
    }
    else if(snakeParts[0].y+10 >= 600)
    {
       snakeParts[0].y = snakeParts[0].y- 600 ;
       //drawSnake();
    }
}

void checkBitten()
{
    for(int i=100; i<snakeLength; i++)
    {
        if((snakeParts[0].x >= snakeParts[i].x-10 && snakeParts[0].x <= snakeParts[i].x+10)
           && (snakeParts[0].y >= snakeParts[i].y-10 && snakeParts[0].y <= snakeParts[i].y+10))
        {
            isGameOver = 1;
            break;
        }
    }
}

void displayScore()
{
    char buf[1024];
    snprintf(buf, 1024, "Game Over. Your Score: %d", score);

    int msgboxID = MessageBox(NULL,buf, "Game Over", NULL);

    if(msgboxID == IDOK)
    {
        exit(0);
    }
}
void bitmap_output(int x, int y, char *string, void *font)
{
  int len, i;

  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}

void front()
{
	glColor3f(0.0,0.0,1.0);
	bitmap_output(200,400, "WELCOME! to Our Game",GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(200, 300, "For Start Press S",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.0,1.0,0.0);
	bitmap_output(200, 200, "Press Esc For Exit.......",GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.0,1.0,0.0);
	bitmap_output(200, 150, "Thank You.......",GLUT_BITMAP_HELVETICA_18);

}

void display(){
    //clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/********************
	/ set-up camera here
	********************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//gluLookAt(0,0,0,	0,0,-1,	0,1,0);

	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);

	/****************************
	/ Add your objects from here
	****************************/
    //startMenu();
    //if(showMenu==0)
       //{front();}

	if(menuValue==0)
    {
                if (score<8){
            drawBorder();
            drawSnake();
            drawFood();
            checkFoodEaten();
            checkBoundaryCrossed();
            checkBitten();
            }
                if (score>=20){
                            //drawBorder();
                              if(snakeParts[0].x >= 590)
                            {
                               //snakeParts[0].x = snakeParts[0].x- 600 ;
                               glTranslatef(-590,0,0);
                               drawSnake();
                               glTranslatef(590,0,0);
                               drawFood();
                               checkFoodEaten();
                            //checkBoundaryCrossed2();
                               checkBitten();
                            }
                             else if(snakeParts[0].x-10 <= 0)
                            {
                               //snakeParts[0].x = snakeParts[0].x+ 600 ;
                               glTranslatef(600,0,0);
                               drawSnake();
                               glTranslatef(-600,0,0);
                               drawFood();
                               checkFoodEaten();
                            //checkBoundaryCrossed2();
                              checkBitten();


                            }

                             else if(snakeParts[0].y-10 <= 0)
                            {
                               //snakeParts[0].y = snakeParts[0].y+ 600 ;
                               glTranslatef(0,600,0);
                               drawSnake();
                               glTranslatef(0,-600,0);
                            }
                            else if(snakeParts[0].y+10 >= 600)
                            {
                               //snakeParts[0].y = snakeParts[0].y- 600 ;
                               glTranslatef(0,-600,0);
                               drawSnake();
                               glTranslatef(0,600,0);
                            }
                           else
                            drawSnake();
                            drawFood();
                            checkFoodEaten();
                            //checkBoundaryCrossed2();
                            checkBitten();
                }


                if(score>=8){
                drawLine();
                drawBorder();   //lavel 3 for plus sign

                drawSnake();
                drawFood1();
                checkFoodEaten();
                checkBitten();
                checkBoundaryCrossed();
                checkBoundaryCrossed1();

                }

    if(isGameOver == 1)
    {
        displayScore();
	}



    }

    else
        front();

	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void animate(){
    for(int i=0; i<snakeLength; i++)
    {
        if(strcmp(snakeParts[i].direction, "right") == 0){
            snakeParts[i].x = snakeParts[i].x + inc;
        }
        else if(strcmp(snakeParts[i].direction, "left") == 0){
            snakeParts[i].x = snakeParts[i].x - inc;
        }
        else if(strcmp(snakeParts[i].direction, "up") == 0){
            snakeParts[i].y = snakeParts[i].y + inc;
        }
        else if(strcmp(snakeParts[i].direction, "down") == 0){
            snakeParts[i].y = snakeParts[i].y - inc;
        }
    }

    strcpy(snakeParts[0].direction, currentDirection);
    for(int i=snakeLength-1; i>0; i--)
    {
        strcpy(snakeParts[i].direction, snakeParts[i-1].direction);
    }

	//codes for any changes in Models, Camera
	glutPostRedisplay();
}

void init(){
	//codes for initialization

	for(int i=0; i<snakeLength; i++)
    {
        strcpy(snakeParts[i].direction, currentDirection);
        snakeParts[i].x = 100-i*inc;
        snakeParts[i].y = 100;

        if(i==0)
        {
            snakeParts[i].r = 0;
            snakeParts[i].g = 1;
            snakeParts[i].b = 0;
        }
        else
        {
            snakeParts[i].r = 1;
            snakeParts[i].g = 0;
            snakeParts[i].b = 1;
        }
    }

    srand(time(0));
    food_x = (rand()%500)+50;
    food_y = (rand()%500)+50;

	//clear the screen
	glClearColor(0,0,0,0);

	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	gluOrtho2D(0, 600, 0, 600);
}
void reshape(int width,int height)
{
	/* Set viewport to new width,height of window */
	glViewport(0,0,(GLsizei)width,(GLsizei)height);

	/* Change matrix to projection */
	glMatrixMode(GL_PROJECTION);
	/* Reset matrix to identity matrix */
	glLoadIdentity();
	/* Set 2D Plane vertices */
	gluOrtho2D(0, 600, 0, 600);
	/* Switch back to modelview matrix */
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("Snake Game");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);
	//glutReshapeFunc(reshape); 	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	glutMouseFunc(mouseListener);


	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
