int BG,copter,enemycopter1; // image load variables for background and helicopter
int building1 , building2 , building3, building4,building5,building6; // image load variables for building
int LIFE=200; //Variable for Gamer Copter Life
char score[20]; //Strings for score
int gamestate=0; //Variable of GameState
int game_Pause; //Image Load Variable for Game Pause Page
int buildingchange; // Variable for Moving Buuilding
bool musicOn = false;  //helicopter music
bool music2On = false; //blast music
bool music3On = true; //menu music
int flamex= 1300,flamey=1300; //flame blast image 
int enemyheli_x,enemyheli_y,cshow=0; //enemy helicopter show after crashing in gameover page
int starting , menu , level , instruction , aboutus, highscore; // image load variables for main menu page
int len,mode; //Strings for keyboard input
//Keyboard Input Function Start
void drawTextBox()
{
	iSetColor(235,218,76);
	iFilledRectangle(610, 280, 250, 30);
}
//Keyboard Input Function End
//Photo Load Function Start
void photoload()
{
	BG = iLoadImage("Image\\BG.jpg");
	copter= iLoadImage("Image\\copter.png");
	enemycopter1 = iLoadImage("Image\\enemycopter.png");

	starting = iLoadImage("Image\\Main Menu\\Starting page.jpg");
	menu = iLoadImage("Image\\Main Menu\\Menu.jpg");
	level = iLoadImage("Image\\Main Menu\\Level.jpg");
	instruction = iLoadImage("Image\\Main Menu\\Instructions.jpg");
	highscore = iLoadImage("Image\\Main Menu\\HighScore.jpg");
	aboutus = iLoadImage("Image\\Main Menu\\Aboutus.png");
	game_Pause=iLoadImage("Image\\Game pause.jpg");

	building1 = iLoadImage("Image\\Building\\building1.png");
	building2 = iLoadImage("Image\\Building\\building2.png");
	building3 = iLoadImage("Image\\Building\\building3.png");
	building4 = iLoadImage("Image\\Building\\building4.png");
	building5 = iLoadImage("Image\\Building\\building5.png");
	building6 = iLoadImage("Image\\Building\\building6.png");

	copterOne[0]= iLoadImage("Image\\Copter\\Copter1.png");
	copterOne[1]= iLoadImage("Image\\Copter\\Copter2.png");
	copterOne[2]= iLoadImage("Image\\Copter\\Copter3.png");

	enemycopterOne[0]=iLoadImage("Image\\Enemy\\eCopter1.png");
	enemycopterOne[1]=iLoadImage("Image\\Enemy\\eCopter2.png");
	enemycopterOne[2]=iLoadImage("Image\\Enemy\\eCopter3.png");

	gBomb= iLoadImage("Image\\BombPicture\\Bomb.png");
	
	enemybombpic = iLoadImage("Image\\BombPicture\\enemyBomb.png");
}
//Photo Load Function End
//ISetTimer Function Start
void iSetTimer()
{
	enemybombpause = iSetTimer(5, bombpositionchange);

	buildingchange = iSetTimer (30, building_change);
	easyenemyhelicopterfall=iSetTimer(100,easyenemyMovement);
	mediumenemyhelicopterfall=iSetTimer(100,mediumenemyMovement);
	hardenemyhelicopterfall=iSetTimer(100,hardenemyMovement);

	copterfall=iSetTimer(50,helicopter_fall);
	
	enemyPosition=iSetTimer(30, enemypositionchange);
	c= iSetTimer(75, change);
	Gamer_bomb=iSetTimer(5, gbombpositionchange);
}
//ISetTimer Function End
//Music On Off Function Start
void music(int n)  
{
	if (musicOn)
	{
		musicOn = false;
		PlaySound(0, 0, 0);
	}
	else
	{
		musicOn = true;
		PlaySound("Music\\Heli.wav", NULL, SND_LOOP | SND_ASYNC);
	}
}
void music2(int n)
{
	if (music3On)
	{
		musicOn = true;
		PlaySound("Music\\Heli.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	if (music3On == false)
	{
		musicOn = false;
		PlaySound(0, 0, 0);
	}
}
void music3(int n)
{
	if (musicOn)
	{
		PlaySound("Music\\Menu.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	else
	{
		PlaySound(0, 0, 0);
	}
}
void music4(int n)
{
	if (musicOn)
	{
		music3On = true;
		PlaySound("Music\\Menu.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	if (musicOn == false)
	{
		music3On = false;
		PlaySound(0, 0, 0);
	}
}
void music5(int n)
{
	if (musicOn)
	{
		PlaySound("Music\\Heli.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	else
	{
		PlaySound(0, 0, 0);
	}
}
void music6(int n)
{
	if (music3On)
	{
		music3On = false;
		PlaySound(0, 0, 0);
	}
	else
	{
		music3On = true;
		PlaySound("Music\\Menu.wav", NULL, SND_LOOP | SND_ASYNC);
	}
}
void music7(int n)
{
	if (music2On)
	{
		music3On = true;
		PlaySound("Music\\Menu.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	if (music2On == false)
	{
		music3On = false;
		PlaySound(0, 0, 0);
	}
}
//Music On Off Function End
//Game Pause and Resume Function Start
void game_pause(int n)
{
	iPauseTimer(buildingchange);
	iPauseTimer(enemyPosition); //enemy helciopter moving stop
	iPauseTimer(enemybombpause);
	iPauseTimer(easyenemyhelicopterfall);
	iPauseTimer(mediumenemyhelicopterfall);
	iPauseTimer(hardenemyhelicopterfall);
	iPauseTimer(copterfall); 
	iPauseTimer(c);
}
void game_resume(int n)
{
	iResumeTimer(buildingchange);
	iResumeTimer(enemyPosition); 
	iResumeTimer(enemybombpause);
	iResumeTimer(easyenemyhelicopterfall);
	iResumeTimer(mediumenemyhelicopterfall);
	iResumeTimer(hardenemyhelicopterfall);
	iResumeTimer(copterfall); 
	iResumeTimer(c);
}
//Game Pause and Resume Function End
//Blast Sound Play And Going To Gameover State Function Start
void leveleasygame_oversound(int n)  
{
	if(gamestate == 15)
	{
		if (musicOn)
		{
			music2On = true;
			PlaySound("Music\\Bomb.wav", NULL, SND_ASYNC);
		}
		if (musicOn == false)
		{
			music2On = false;
			PlaySound(0, 0, 0);
		}
		gamestate = 9;
	}
}

void levelmediumgame_oversound(int n)  
{
	if(gamestate == 16)
	{
		if (musicOn)
		{
			music2On = true;
			PlaySound("Music\\Bomb.wav", NULL, SND_ASYNC);
		}
		if (musicOn == false)
		{
			music2On = false;
			PlaySound(0, 0, 0);
		}
		gamestate = 10;
	}
}

void levelhardgame_oversound(int n)  
{
	if(gamestate == 17)
	{
		if (musicOn)
		{
			music2On = true;
			PlaySound("Music\\Bomb.wav", NULL, SND_ASYNC);
		}
		if (musicOn == false)
		{
			music2On = false;
			PlaySound(0, 0, 0);
		}
		gamestate = 11;
	}
}
//Blast Sound Play And Going To Gameover State Function Start

//Crash Algorithm For Level Easy Start
void buildingcrasheasy()
{
	if(((cop_x+dcopx >= w_building_x && cop_x <= w_building_x+dbuildx) && (cop_y + dcopy >= w_building_y && cop_y <= w_building_y + dbuildy))  || ((cop_x+dcopx >= w2_building_x && cop_x <= w2_building_x+d2buildx) && (cop_y + dcopy >= w2_building_y && cop_y <= w2_building_y + d2buildy))  ||  ((cop_x+dcopx >= w3_building_x && cop_x <= w3_building_x+d3buildx) && (cop_y + dcopy >= w3_building_y && cop_y <= w3_building_y + d3buildy))  || ((cop_x+dcopx >= w4_building_x && cop_x <= w4_building_x+d4buildx) && (cop_y + dcopy >= w4_building_y && cop_y <= w4_building_y + d4buildy)) || ((cop_x+dcopx >= w5_building_x && cop_x <= w5_building_x+d5buildx) && (cop_y + dcopy >= w5_building_y && cop_y <= w5_building_y + d5buildy)) || ((cop_x+dcopx >= w6_building_x && cop_x <= w6_building_x+d6buildx) && (cop_y + dcopy >= w6_building_y && cop_y <= w6_building_y + d6buildy)) )
	{
		game_pause(1);
		flamex=cop_x+60;
		flamey=cop_y;

		gamestate = 15;
		leveleasygame_oversound(1);
		store_score();
	}
}
void enemycrasheasy()
{
	for (int i = 0; i < 1; i++)
	{
		if (enemy[i].copterShow)
		{
			if((cop_x+dcopx-30 >= enemy[i].copter_x  && cop_x-20 <= enemy[i].copter_x+150) && (cop_y + dcopy-30 >= enemy[i].copter_y && cop_y <=enemy[i].copter_y + 80))
			{
				enemyheli_x = enemy[i].copter_x;
				enemyheli_y = enemy[i].copter_y;
				cshow=1;
				iShowBMP2(cop_x+100, cop_y+20, "Image\\Blast.bmp",0);
				LIFE -= 100;
				enemy[i].copterShow=false;
				enemy[i].copter_x = 1360 + rand() % 300;
				enemy[i].copter_y = 350 + rand() % 250;
				enemy[i].copterShow = true;
				
				
				if (LIFE <= 20)
				{
					enemy[i].copterShow=true;
			
					game_pause(1);
					flamex=cop_x+60;
					flamey=cop_y;

					gamestate = 15;
					leveleasygame_oversound(1);
					store_score();
				}
			}
		}
	}
}
void gamerbombhiteasy()
{
	for (int i = 0; i < gbombnumber ; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if(gbomb[i].gbombshow)
			{
				if((gbomb[i].gbomb_x+50 >= enemy[j].copter_x  && gbomb[i].gbomb_x <= enemy[j].copter_x+150) && (gbomb[i].gbomb_y + 15 >= enemy[j].copter_y && gbomb[i].gbomb_y <=enemy[j].copter_y + 80))
				{
					iShowBMP2(enemy[j].copter_x,enemy[j].copter_y , "Image\\Blast.bmp",0);
					enemy[j].copterShow = false;
					enemy[j].copter_x = 1360 + rand() % 300;
					enemy[j].copter_y = 350 + rand() % 250;
					enemy[j].copterShow = true;

					gbomb[i].gbombshow=false;
					gbomb[i].gbomb_x=cop_x+140;


					t=t+10;;
				}
			}
		}
	}
}
void enemybombcrasheasy()
{
	for (int i = 0; i < 1; i++)
	{
		if(bomb[i].enemybombShow)
		{
			if((cop_x+dcopx-40 >= bomb[i].enemybomb_x && cop_x-40 <= bomb[i].enemybomb_x + 50) && (cop_y + dcopy-30 >= bomb[i].enemybomb_y && cop_y +30<= bomb[i].enemybomb_y + 15))		
			{
				iShowBMP2(cop_x+100, cop_y+20, "Image\\Blast.bmp",0);
				LIFE-=20;
				bomb[i].enemybombShow=false;

				if(LIFE<=20)
				{
					game_pause(1);
					flamex=cop_x+60;
					flamey=cop_y;

					gamestate = 15;
					leveleasygame_oversound(1);
					store_score();
				}
			}
		}
	}
}
void screencrasheasy()
{
	if((cop_x == -200  || cop_x + dcopx == 1360) || (cop_y == 700 || cop_y + dcopy == 0))
	{
		game_pause(1);
		flamex=cop_x+60;
		flamey=cop_y;
		gamestate = 15;
		leveleasygame_oversound(1);
		store_score();
	}
}
//Crash Algorithm For Level Easy End
//New Game Function Start To Start a New Game For Level Easy
void leveleasynewgame(int n)
{
	cop_x = 20; cop_y = 600; dcopx=150; dcopy=112;

	LIFE=200;
	cshow=0;

	setEnemyVariables();
	setBombVariables();
	setgbomb();

	w_building_x = 100; w_building_y = 0; 
	w2_building_x = 900; w2_building_y = 0; 
	w3_building_x = 1200; w3_building_y = 0; 
	w4_building_x = 1600; w4_building_y = 0; 
	w5_building_x = 1900; w5_building_y = 0; 
	w6_building_x = 2300; w6_building_y = 0; 

	flamex = 1300;
	flamey = 1300;
		
	t=0;	

	gamestate = 6;

	game_resume(1);
}
//New Game Function End To Start a New Game For Level Easy
//Crash Algorithm For Level Medium Start
void buildingcrashmedium()
{
	if(((cop_x+dcopx >= w_building_x && cop_x <= w_building_x+dbuildx) && (cop_y + dcopy >= w_building_y && cop_y <= w_building_y + dbuildy))  || ((cop_x+dcopx >= w2_building_x && cop_x <= w2_building_x+d2buildx) && (cop_y + dcopy >= w2_building_y && cop_y <= w2_building_y + d2buildy))  ||  ((cop_x+dcopx >= w3_building_x && cop_x <= w3_building_x+d3buildx) && (cop_y + dcopy >= w3_building_y && cop_y <= w3_building_y + d3buildy))  || ((cop_x+dcopx >= w4_building_x && cop_x <= w4_building_x+d4buildx) && (cop_y + dcopy >= w4_building_y && cop_y <= w4_building_y + d4buildy)) || ((cop_x+dcopx >= w5_building_x && cop_x <= w5_building_x+d5buildx) && (cop_y + dcopy >= w5_building_y && cop_y <= w5_building_y + d5buildy)) || ((cop_x+dcopx >= w6_building_x && cop_x <= w6_building_x+d6buildx) && (cop_y + dcopy >= w6_building_y && cop_y <= w6_building_y + d6buildy)) )
	{
		game_pause(1);
		flamex=cop_x+60;
		flamey=cop_y;

		gamestate = 16;
		levelmediumgame_oversound(1);
		store_score();
	}
}
void enemycrashmedium()
{
	for (int i = 0; i < 2; i++)
	{
		if (enemy[i].copterShow)
		{
			if((cop_x+dcopx-30 >= enemy[i].copter_x  && cop_x-20 <= enemy[i].copter_x+150) && (cop_y + dcopy-30 >= enemy[i].copter_y && cop_y <=enemy[i].copter_y + 80))
			{
				enemyheli_x = enemy[i].copter_x;
				enemyheli_y = enemy[i].copter_y;
				cshow=1;
				iShowBMP2(cop_x+100, cop_y+20, "Image\\Blast.bmp",0);
				LIFE -= 100;
				enemy[i].copterShow=false;
				enemy[i].copter_x = 1360 + rand() % 300;
				enemy[i].copter_y = 350 + rand() % 250;
				enemy[i].copterShow = true;

				if (LIFE <= 20)
				{
					game_pause(1);
					flamex=cop_x+60;
					flamey=cop_y;

					gamestate = 16;
					levelmediumgame_oversound(1);
					store_score();
				}
			}
		}
	}
}
void enemybombcrashmedium()
{
	for (int i = 0; i < 2; i++)
	{
		if(bomb[i].enemybombShow)
		{
			if((cop_x+dcopx-40 >= bomb[i].enemybomb_x && cop_x-40 <= bomb[i].enemybomb_x + 50) && (cop_y + dcopy-30 >= bomb[i].enemybomb_y && cop_y +30<= bomb[i].enemybomb_y + 15))		
			{
				iShowBMP2(cop_x+100, cop_y+20, "Image\\Blast.bmp",0);
				LIFE-=20;
				bomb[i].enemybombShow=false;

				if(LIFE<=20)
				{
					game_pause(1);
					flamex=cop_x+60;
					flamey=cop_y;

					gamestate = 16;
					levelmediumgame_oversound(1);
					store_score();
				}
			}
		}
	}
}
void gamerbombhitmedium()
{
	for (int i = 0; i < gbombnumber ; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if(gbomb[i].gbombshow)
			{
				if((gbomb[i].gbomb_x+50 >= enemy[j].copter_x  && gbomb[i].gbomb_x <= enemy[j].copter_x+150) && (gbomb[i].gbomb_y + 15 >= enemy[j].copter_y && gbomb[i].gbomb_y <=enemy[j].copter_y + 80))
				{
					iShowBMP2(enemy[j].copter_x,enemy[j].copter_y , "Image\\Blast.bmp",0);
					enemy[j].copterShow = false;
					enemy[j].copter_x = 1360 + rand() % 300;
					enemy[j].copter_y = 350 + rand() % 250;
					enemy[j].copterShow = true;

					gbomb[i].gbombshow=false;
					gbomb[i].gbomb_x=cop_x+140;


					t = t + 10;
				}
			}
		}
	}
}
void screencrashmedium()
{
	if((cop_x == -200  || cop_x + dcopx == 1360) || (cop_y == 700 || cop_y + dcopy == 0))
	{	
		game_pause(1);
		flamex=cop_x+60;
		flamey=cop_y;
		gamestate = 16;
		levelmediumgame_oversound(1);
		store_score();
	}
}
//Crash Algorithm For Level Medium End
//New Game Function Start To Start a New Game For Level Medium
void levelmediumnewgame(int n)
{
	cop_x = 20; cop_y = 600; dcopx=150; dcopy=112;

	LIFE=200;
	cshow=0;

	setEnemyVariables();
	setBombVariables();
	setgbomb();

	w_building_x = 100; w_building_y = 0; 
	w2_building_x = 900; w2_building_y = 0; 
	w3_building_x = 1200; w3_building_y = 0; 
	w4_building_x = 1600; w4_building_y = 0; 
	w5_building_x = 1900; w5_building_y = 0; 
	w6_building_x = 2300; w6_building_y = 0; 

	flamex = 1300;
	flamey = 1300;
		
	t=0;	

	gamestate = 7;

	game_resume(1);
}
//New Game Function End To Start a New Game For Level Medium
//Crash Algorithm For Level Hard Start
void buildingcrashhard()
{
	if(((cop_x+dcopx >= w_building_x && cop_x <= w_building_x+dbuildx) && (cop_y + dcopy >= w_building_y && cop_y <= w_building_y + dbuildy))  || ((cop_x+dcopx >= w2_building_x && cop_x <= w2_building_x+d2buildx) && (cop_y + dcopy >= w2_building_y && cop_y <= w2_building_y + d2buildy))  ||  ((cop_x+dcopx >= w3_building_x && cop_x <= w3_building_x+d3buildx) && (cop_y + dcopy >= w3_building_y && cop_y <= w3_building_y + d3buildy))  || ((cop_x+dcopx >= w4_building_x && cop_x <= w4_building_x+d4buildx) && (cop_y + dcopy >= w4_building_y && cop_y <= w4_building_y + d4buildy)) || ((cop_x+dcopx >= w5_building_x && cop_x <= w5_building_x+d5buildx) && (cop_y + dcopy >= w5_building_y && cop_y <= w5_building_y + d5buildy)) || ((cop_x+dcopx >= w6_building_x && cop_x <= w6_building_x+d6buildx) && (cop_y + dcopy >= w6_building_y && cop_y <= w6_building_y + d6buildy)) )
	{
		game_pause(1);
		flamex=cop_x+60;
		flamey=cop_y;

		gamestate = 17;
		levelhardgame_oversound(1);
		store_score();
	}
}
void enemycrashhard()
{
	for (int i = 0; i < COPTERNUMBER; i++)
	{
		if (enemy[i].copterShow)
		{
			if((cop_x+dcopx-30 >= enemy[i].copter_x  && cop_x-20 <= enemy[i].copter_x+150) && (cop_y + dcopy-30 >= enemy[i].copter_y && cop_y <=enemy[i].copter_y + 80))
			{
				enemyheli_x = enemy[i].copter_x;
				enemyheli_y = enemy[i].copter_y;
				cshow=1;
				iShowBMP2(cop_x+100, cop_y+20, "Image\\Blast.bmp",0);
				LIFE -= 100;
				enemy[i].copterShow=false;
				enemy[i].copter_x = 1360 + rand() % 300;
				enemy[i].copter_y = 350 + rand() % 250;
				enemy[i].copterShow = true;
				

				if (LIFE <= 20)
				{
					game_pause(1);
					flamex=cop_x+60;
					flamey=cop_y;

					gamestate = 17;
					levelhardgame_oversound(1);
					store_score();
				}

			}
		}
	}
}
void enemybombcrashhard()
{
	for (int i = 0; i < COPTERNUMBER; i++)
	{
		if(bomb[i].enemybombShow)
		{
			if((cop_x+dcopx-40 >= bomb[i].enemybomb_x && cop_x-40 <= bomb[i].enemybomb_x + 50) && (cop_y + dcopy-30 >= bomb[i].enemybomb_y && cop_y +30<= bomb[i].enemybomb_y + 15))		
			{
				iShowBMP2(cop_x+100, cop_y+20, "Image\\Blast.bmp",0);
				LIFE-=20;
				bomb[i].enemybombShow=false;

				if(LIFE<=20)
				{
					game_pause(1);
					flamex=cop_x+60;
					flamey=cop_y;

					gamestate = 17;
					levelhardgame_oversound(1);
					store_score();
				}
			}
		}
	}
}
void gamerbombhithard()
{
	for (int i = 0; i < gbombnumber ; i++)
	{
		for (int j = 0; j < COPTERNUMBER; j++)
		{
			if(gbomb[i].gbombshow)
			{
				if((gbomb[i].gbomb_x+50 >= enemy[j].copter_x  && gbomb[i].gbomb_x <= enemy[j].copter_x+150) && (gbomb[i].gbomb_y + 15 >= enemy[j].copter_y && gbomb[i].gbomb_y <=enemy[j].copter_y + 80))
				{
					iShowBMP2(enemy[j].copter_x,enemy[j].copter_y , "Image\\Blast.bmp",0);
					enemy[j].copterShow = false;
					enemy[j].copter_x = 1360 + rand() % 300;
					enemy[j].copter_y = 350 + rand() % 250;
					enemy[j].copterShow = true;

					gbomb[i].gbombshow=false;
					gbomb[i].gbomb_x=cop_x+140;


					t = t + 10;
				}
			}
		}
	}
}
void screencrashhard()
{
	if((cop_x == -200  || cop_x + dcopx == 1360) || (cop_y == 700 || cop_y + dcopy == 0))
	{
		game_pause(1);
		flamex=cop_x+60;
		flamey=cop_y;
		gamestate = 17;
		levelhardgame_oversound(1);
		store_score();
	}
}
//Crash Algorithm For Level Hard End
//New Game Function Start To Start a New Game For Level Hard
void levelhardnewgame(int n)
{
	cop_x = 20; cop_y = 600; dcopx=150; dcopy=112;

	LIFE=200;
	cshow=0;

	setEnemyVariables();
	setBombVariables();
	setgbomb();

	w_building_x = 100; w_building_y = 0; 
	w2_building_x = 900; w2_building_y = 0; 
	w3_building_x = 1200; w3_building_y = 0; 
	w4_building_x = 1600; w4_building_y = 0; 
	w5_building_x = 1900; w5_building_y = 0; 
	w6_building_x = 2300; w6_building_y = 0; 

	flamex = 1300;
	flamey = 1300;
		
	t=0;	

	gamestate = 8;

	game_resume(1);
}
//New Game Function End To Start a New Game For Level Hard
//Gameover Page Function Start
void leveleasygameoverpage(int n) 
{
	iShowImage(0, 0, 1360, 700, BG);
	iShowImage(w_building_x , w_building_y , 1125 , 350 , building1);
	iShowImage(w2_building_x , w2_building_y , 199 , 300 , building2);
	iShowImage(w3_building_x , w3_building_y , 138 , 320 , building3);
	iShowImage(w4_building_x , w4_building_y , 467 , 360 , building4);
	iShowImage(w5_building_x , w5_building_y , 200 , 280 , building5);
	iShowImage(w6_building_x , w6_building_y , 141 , 330 , building6);

	game_pause(1);

	for (int i = 0; i < 1; i++)
	{
		if (enemy[i].copterShow)
		{
			iShowImage(enemy[i].copter_x, enemy[i].copter_y,200,112, enemycopter1);
		}
	}
	for (int i = 0; i < 1 ; i++)
	{
		if (bomb[i].enemybombShow)
		{
			iShowImage(bomb[i].enemybomb_x, bomb[i].enemybomb_y , 50 , 15 , enemybombpic);
		}
	}

	if(cshow==1 && LIFE<=20 )
	{
		iShowImage(enemyheli_x, enemyheli_y,200,112, enemycopter1);
	}

	iShowImage(cop_x, cop_y, 200, 112, copter);
	iShowBMP2(flamex, flamey, "Image\\Blast.bmp",0);
	iSetColor(0, 0, 0);
	iText(600, 672, "Player:" , GLUT_BITMAP_TIMES_ROMAN_24);
	iText(680, 670, str2 , GLUT_BITMAP_TIMES_ROMAN_24);
	iText(600, 630, "Score:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(670, 630, score , GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(500, 250, "Image\\gameover.bmp",0);
	iText(30, 672, "Player Life:" , GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255 , 0 , 0);
	iFilledRectangle(150 , 670, 200 , 20);
}
void levelmediumgameoverpage(int n) 
{
	iShowImage(0, 0, 1360, 700, BG);
	iShowImage(w_building_x , w_building_y , 1125 , 350 , building1);
	iShowImage(w2_building_x , w2_building_y , 199 , 300 , building2);
	iShowImage(w3_building_x , w3_building_y , 138 , 320 , building3);
	iShowImage(w4_building_x , w4_building_y , 467 , 360 , building4);
	iShowImage(w5_building_x , w5_building_y , 200 , 280 , building5);
	iShowImage(w6_building_x , w6_building_y , 141 , 330 , building6);

	game_pause(1);

	for (int i = 0; i < 2; i++)
	{
		if (enemy[i].copterShow)
		{
			iShowImage(enemy[i].copter_x, enemy[i].copter_y,200,112, enemycopter1);
		}
	}
	for (int i = 0; i < 2 ; i++)
	{
		if (bomb[i].enemybombShow)
		{
			iShowImage(bomb[i].enemybomb_x, bomb[i].enemybomb_y , 50 , 15 , enemybombpic);
		}
	}

	if(cshow==1 && LIFE<=20)
	{
		iShowImage(enemyheli_x, enemyheli_y,200,112, enemycopter1);
	}
	iShowImage(cop_x, cop_y, 200, 112, copter);
	iShowBMP2(flamex, flamey, "Image\\Blast.bmp",0);
	iSetColor(0, 0, 0);
	iText(600, 672, "Player:" , GLUT_BITMAP_TIMES_ROMAN_24);
	iText(680, 670, str2 , GLUT_BITMAP_TIMES_ROMAN_24);
	iText(600, 630, "Score:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(670, 630, score , GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(500, 250, "Image\\gameover.bmp",0);
	iText(30, 672, "Player Life:" , GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255 , 0 , 0);
	iFilledRectangle(150 , 670, 200 , 20);
}
void levelhardgameoverpage(int n) 
{
	iShowImage(0, 0, 1360, 700, BG);
	iShowImage(w_building_x , w_building_y , 1125 , 350 , building1);
	iShowImage(w2_building_x , w2_building_y , 199 , 300 , building2);
	iShowImage(w3_building_x , w3_building_y , 138 , 320 , building3);
	iShowImage(w4_building_x , w4_building_y , 467 , 360 , building4);
	iShowImage(w5_building_x , w5_building_y , 200 , 280 , building5);
	iShowImage(w6_building_x , w6_building_y , 141 , 330 , building6);

	game_pause(1);

	for (int i = 0; i < COPTERNUMBER; i++)
	{
		if (enemy[i].copterShow)
		{
			iShowImage(enemy[i].copter_x, enemy[i].copter_y,200,112, enemycopter1);
		}
	}
	for (int i = 0; i < COPTERNUMBER ; i++)
	{
		if (bomb[i].enemybombShow)
		{
			iShowImage(bomb[i].enemybomb_x, bomb[i].enemybomb_y , 50 , 15 , enemybombpic);
		}
	}

	if(cshow==1 && LIFE<=20)
	{
		iShowImage(enemyheli_x, enemyheli_y,200,112, enemycopter1);
	}

	
	iShowImage(cop_x, cop_y, 200, 112, copter);
	iShowBMP2(flamex, flamey, "Image\\Blast.bmp",0);
	iSetColor(0, 0, 0);
	iText(600, 672, "Player:" , GLUT_BITMAP_TIMES_ROMAN_24);
	iText(680, 670, str2 , GLUT_BITMAP_TIMES_ROMAN_24);
	iText(600, 630, "Score:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(670, 630, score , GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(500, 250, "Image\\gameover.bmp",0);
	iText(30, 672, "Player Life:" , GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255 , 0 , 0);
	iFilledRectangle(150 , 670, 200 , 20);
}
//Gameover Page Function End