
/*
	Ahsanullah University Of Science & Technology
	
	Department Of Computer Science & Engineering
	"Copter Battle"
	Course No : CSE 1200 (Game Project)
	1st Year 2nd Semester
	Authors: 
	Shahnewaz Mahmud Ayon
	Samsul Islam 
	Md Jahidul Islam
*/

#include "iGraphics.h"
#include <iomanip>
#include <locale>
#include "bitmap_loader.h"
#include "Building_change.h"
#include "Enemy_Copter.h"
#include "Gamer_Copter.h"
#include "High_Score.h"
#include "Levels_EMH.h"
#include <stdlib.h>

#define Swidth 1360 //screen width
#define Slength 700 //screen height

void iDraw()
{
	iClear();
	if (gamestate == 0)
	{
		game_pause(1);
		iShowImage(0, 0, 1360, 700, starting);
	}
	if (gamestate == 1)
	{
		iShowImage(0, 0, 1360, 700, menu);

		drawTextBox();

		if(mode == 1)
		{
			iSetColor(0, 0, 0);
			iText(620, 290, str);
		}

		iText(10, 10, "Click to activate the box, enter to finish.");
	}

	if (gamestate == 2)
	{
		iShowImage(0, 0, 1360, 700, level);
	}
	if (gamestate == 3)
	{
		iShowImage(0, 0, 1360, 700, instruction);
	}
	if (gamestate == 4)
	{
		iShowImage(0, 0, 1360, 700, highscore);
		read();
		show(s);
	}
	if (gamestate == 5)
	{
		iShowImage(0, 0, 1360, 700, aboutus);
	}
	if (gamestate == 6)  //Easy level
	{
		game_resume(1);
		
		building_pass=9;  //Easy level speed
		bombspeed=9;
		enemyspeed=9;

		itoa(t,score,10);
		iShowImage(0, 0, 1360, 700, BG);
		iShowImage(w_building_x , w_building_y , 1125 , 350 , building1);
		iShowImage(w2_building_x , w2_building_y , 199 , 300 , building2);
		iShowImage(w3_building_x , w3_building_y , 138 , 320 , building3);
		iShowImage(w4_building_x , w4_building_y , 467 , 360 , building4);
		iShowImage(w5_building_x , w5_building_y , 200 , 280 , building5);
		iShowImage(w6_building_x , w6_building_y , 141 , 330 , building6);
		
		easybombMovement();	
		gbombmovement();
		easyenemyMovement();
		render();
		buildingcrasheasy();
		enemybombcrasheasy();
		enemycrasheasy();
		gamerbombhiteasy();
		screencrasheasy();
		iShowBMP2(flamex, flamey, "Image\\Blast.bmp",0);
		iSetColor(0, 0, 0);
		iText(600, 672, "Player:" , GLUT_BITMAP_TIMES_ROMAN_24);
		iText(680, 670, str2 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText(600, 630, "Score:", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(670, 630, score , GLUT_BITMAP_TIMES_ROMAN_24);

		iText(30, 672, "Player Life:" , GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255 , 0 , 0);
		iFilledRectangle(150 , 670, 200 , 20);
		iSetColor(0 , 255 , 0);
		iFilledRectangle(150 , 670, LIFE , 20);
	}
	if (gamestate == 7) //Medium level
	{
		game_resume(1);

		building_pass=13; //Medium level speed
		bombspeed=13;
		enemyspeed=13;

		itoa(t,score,10);
		iShowImage(0, 0, 1360, 700, BG);
		iShowImage(w_building_x , w_building_y , 1125 , 350 , building1);
		iShowImage(w2_building_x , w2_building_y , 199 , 300 , building2);
		iShowImage(w3_building_x , w3_building_y , 138 , 320 , building3);
		iShowImage(w4_building_x , w4_building_y , 467 , 360 , building4);
		iShowImage(w5_building_x , w5_building_y , 200 , 280 , building5);
		iShowImage(w6_building_x , w6_building_y , 141 , 330 , building6);
		
		mediumbombMovement();	
		gbombmovement();
		mediumenemyMovement();
		render();
		buildingcrashmedium();
		enemybombcrashmedium();
		enemycrashmedium();
		gamerbombhitmedium();
		screencrashmedium();
		iShowBMP2(flamex, flamey, "Image\\Blast.bmp",0);
		iSetColor(0, 0, 0);
		iText(600, 672, "Player:" , GLUT_BITMAP_TIMES_ROMAN_24);
		iText(680, 670, str2 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText(600, 630, "Score:", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(670, 630, score , GLUT_BITMAP_TIMES_ROMAN_24);

		iText(30, 672, "Player Life:" , GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255 , 0 , 0);
		iFilledRectangle(150 , 670, 200 , 20);
		iSetColor(0 , 255 , 0);
		iFilledRectangle(150 , 670, LIFE , 20);
	}
	if (gamestate == 8)
	{
		game_resume(1);
		building_pass=17;
		bombspeed=17;
		enemyspeed=17;


		itoa(t,score,10);
		iShowImage(0, 0, 1360, 700, BG);
		iShowImage(w_building_x , w_building_y , 1125 , 350 , building1);
		iShowImage(w2_building_x , w2_building_y , 199 , 300 , building2);
		iShowImage(w3_building_x , w3_building_y , 138 , 320 , building3);
		iShowImage(w4_building_x , w4_building_y , 467 , 360 , building4);
		iShowImage(w5_building_x , w5_building_y , 200 , 280 , building5);
		iShowImage(w6_building_x , w6_building_y , 141 , 330 , building6);
		
		hardbombMovement();	
		gbombmovement();
		hardenemyMovement();
		render();
		buildingcrashhard();
		enemybombcrashhard();
		enemycrashhard();
		gamerbombhithard();
		screencrashhard();
		iShowBMP2(flamex, flamey, "Image\\Blast.bmp",0);
		iSetColor(0, 0, 0);
		iText(600, 672, "Player:" , GLUT_BITMAP_TIMES_ROMAN_24);
		iText(680, 670, str2 , GLUT_BITMAP_TIMES_ROMAN_24);
		iText(600, 630, "Score:", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(670, 630, score , GLUT_BITMAP_TIMES_ROMAN_24);

		iText(30, 672, "Player Life:" , GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255 , 0 , 0);
		iFilledRectangle(150 , 670, 200 , 20);
		iSetColor(0 , 255 , 0);
		iFilledRectangle(150 , 670, LIFE , 20);
	}
	
	if (gamestate == 9) //Level Easy Game Over Page
	{
		leveleasygameoverpage(1);
	}
	if (gamestate == 10) //Level Medium Game Over Page
	{
		levelmediumgameoverpage(1);
	}
	if (gamestate == 11) //Level Hard Game Over Page
	{
		levelhardgameoverpage(1);
	}
	if (gamestate == 12) //Level Easy Game Pause Page
	{
		iShowImage(0, 0, 1360, 700, game_Pause);
	}
	if (gamestate == 13) //Level Medium Game Pause Page
	{
		iShowImage(0, 0, 1360, 700, game_Pause);
	}
	if (gamestate == 14) //Level Hard Game Pause Page
	{
		iShowImage(0, 0, 1360, 700, game_Pause);
	}
}

void iMouseMove(int mx, int my)
{

}


void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)    
	{
		if (gamestate == 1)
		{
			if (mx >= 20 && mx <= 395 && my >= 550 && my <= 650) //play button
			{
				gamestate = 2;
			}
			if (mx >= 20 && mx <= 395 && my >= 410 && my <= 500)  //Instruction Button
			{
				gamestate = 3;
			}
			if (mx >= 20 && mx <= 395 && my >= 280 && my <= 370)  //High Score Button
			{
				gamestate = 4;
			}
			if (mx >= 20 && mx <= 395 && my >= 150 && my <= 240)  //About us button
			{
				gamestate = 5;
			}
			if (mx >= 20 && mx <= 395 && my >= 30 && my <= 120)  //Exit Button
			{
				exit(0);
			}

			if(mx >= 610 && mx <= 860 && my >= 280 && my <= 310 && mode == 0)
			{
				mode = 1;
			}
		}
		if (gamestate == 2)
		{
			if (mx >= 10 && mx <= 270 && my >= 20 && my <= 100)  //Main Menu
			{
				gamestate = 1;
			}
			if (mx >= 480 && mx <= 850 && my >= 410 && my <= 500) //Easy
			{
				leveleasynewgame(1);
				gamestate = 6;
				music2(1);
				
			}
			if (mx >= 480 && mx <= 850 && my >= 280 && my <= 370) //Medium
			{
				levelmediumnewgame(1);
				gamestate = 7;
				music2(1);
			}
			if (mx >= 480 && mx <= 850 && my >= 145 && my <= 235)  // Hard
			{
				levelhardnewgame(1);
				gamestate = 8;
				music2(1);
			}
		}
		if (gamestate == 3)
		{
			if (mx >= 10 && mx <= 270 && my >= 20 && my <= 100)  //Main Menu
			{
				gamestate = 1;
			}
		}
		if (gamestate == 4)
		{
			if (mx >= 10 && mx <= 270 && my >= 20 && my <= 100) //Main menu
			{
				gamestate = 1;
			}
		}
		if (gamestate == 5)
		{
			if (mx >= 10 && mx <= 270 && my >= 20 && my <= 100)  //Main Menu
			{
				gamestate = 1;
			}
		}
		if (gamestate == 12)
		{
			if (mx >= 480 && mx <= 830 && my >= 445 && my <= 530)  //Back to Level Easy 
			{
				gamestate = 6;
				music2(1);
			}
			if (mx >= 480 && mx <= 830 && my >= 310 && my <= 395)  // Restart the game
			{
				leveleasynewgame(1);
				music2(1);
			}
			if (mx >= 480 && mx <= 830 && my >= 185 && my <= 270)  // Main Menu
			{
				gamestate = 1;
				music3(1);
			}
			if (mx >= 480 && mx <= 830 && my >= 55 && my <= 140)  // exit from game
			{
				exit(0);
			}
		}
		if (gamestate == 13)
		{
			if (mx >= 480 && mx <= 830 && my >= 445 && my <= 530)  //Back to Level Medium
			{
				gamestate = 7;
				music2(1);
			}
			if (mx >= 480 && mx <= 830 && my >= 310 && my <= 395)  // Restart the game
			{
				levelmediumnewgame(1);
				music2(1);
			}
			if (mx >= 480 && mx <= 830 && my >= 185 && my <= 275)  // Main Menu
			{
				gamestate = 1;
				music3(1);
			}
			if (mx >= 480 && mx <= 830 && my >= 55 && my <= 140)  // exit from game
			{
				exit(0);
			}
		}
		if (gamestate == 14)
		{
			if (mx >= 480 && mx <= 830 && my >= 445 && my <= 530)  //Back to Level Hard
			{
				gamestate = 8;
				music2(1);
			}
			if (mx >= 480 && mx <= 830 && my >= 310 && my <= 395)  // Restart the game
			{
				levelhardnewgame(1);
				music2(1);
			}
			if (mx >= 480 && mx <= 830 && my >= 185 && my <= 270)  // Main Menu
			{
				gamestate = 1;
				music3(1);
			}
			if (mx >= 480 && mx <= 830 && my >= 55 && my <= 140)  // exit from game
			{
				exit(0);
			}
		}
	}
}

void iKeyboard(unsigned char key)
{
	if (gamestate == 0)
	{
		if(key == '\r')
		{
			gamestate = 1;
		}
	}
	if (gamestate == 1)
	{
		if (mode == 1)
		{
			if (key != '\b')
			{
				str[len] = key;
				len++;
				str[len] = '\0';
			}
			else
			{
				if (len <= 0)
				{
					len = 0;
				}
				else
				{
					len--;
					str[len] = '\0';
				}
			}
			if(key == '\r')
			{
				mode = 0;
				strcpy(str2, str);
				for(int i = 0; i < len; i++)
					str[i] = 0;
				len = 0;
			}
		}
	}
	if (gamestate == 6 || gamestate == 7 || gamestate == 8)
	{
		if (key == 'f' || key == 'F')
		{
			gbomb[k].gbombshow=true;
			k++;

			if(k==100)
			{
				k=0;
			}
		}

		if (key == 'a' || key == 'A')
		{
			cop_x -= 10;
		}
		else if (key == 'd' || key == 'D')
		{
			cop_x += 10;
		}
		else if (key == 'w' || key == 'W')
		{
			cop_y +=10;
		}
		else if (key == 's' || key == 'S')
		{
			cop_y -= 10;
		}
		setgbomb(); //update gamer plane bomb co ordinate

	}
	if (gamestate == 6)
	{
		if (key == 27)  //Game pause
		{
			gamestate = 12;
			game_pause(1);
			music4(1);
		}
	}
	if (gamestate == 7)
	{
		if (key == 27)  //Game pause
		{
			gamestate = 13;
			game_pause(1);
			music4(1);
		}
	}
	if (gamestate == 8)
	{
		if (key == 27)  //Game pause
		{
			gamestate = 14;
			game_pause(1);
			music4(1);
		}
	}
	if (gamestate == 9)
	{
		if (key == 'p' || key == 'P')
		{
			leveleasynewgame(1);
			music5(1);
		}	
	}
	if (gamestate == 10)
	{
		if (key == 'p' || key == 'P')
		{
			levelmediumnewgame(1);
			music5(1);
		}	
	}
	if (gamestate == 11)
	{
		if (key == 'p' || key == 'P')
		{
			levelhardnewgame(1);
			music5(1);
		}	
	}
}

void iSpecialKeyboard(unsigned char key)
{
	if (gamestate == 0 || gamestate == 1 || gamestate == 2 || gamestate == 3 || gamestate == 4 || gamestate == 5 || gamestate == 12 || gamestate == 13 || gamestate == 14)
	{
		if (key == GLUT_KEY_F6)
		{
			music6(1);
		}
	}
	if (gamestate == 6 || gamestate == 7 || gamestate == 8) //Helicopter Control
	{  
		if(key == GLUT_KEY_UP)
		{
			cop_y += 20;
		}

		if (key == GLUT_KEY_DOWN)
		{
			cop_y -= 20;
		}

		if(key == GLUT_KEY_LEFT)
		{
			cop_x -= 10;
		}

		if (key == GLUT_KEY_RIGHT)
		{
			cop_x += 10;
		}
		setgbomb();
		if (key == GLUT_KEY_F6) //Music on off
		{  
			music(1);
		}
	}
	if (gamestate == 9 || gamestate == 10 || gamestate == 11)
	{
		if(key == GLUT_KEY_HOME)
		{	
			gamestate = 1;
			music7(1);
		}
	}
}


int main()
{
	iInitialize(Swidth, Slength, "Copter Battle");

	len = 0;
	mode = 0;
	str[0]= 0;

	setEnemyVariables();
	setgbomb();
	setBombVariables();

	photoload();
	
	iSetTimer();

	if(music3On)
	{
		PlaySound("Music\\Menu.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	iStart();
	return 0;
}
