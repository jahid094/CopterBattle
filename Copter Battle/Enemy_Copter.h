//Enemy Copter Algorithm Start
#define COPTERNUMBER 3 // number of enemy helicopter
int mediumenemyhelicopterfall;
int easyenemyhelicopterfall; // isetTimer controller
int hardenemyhelicopterfall;
int enemycopterOne[3];//enemy copter rendering
int enemyPosition;  //iSetTimer controller

struct enemycopter
{
	int copter_x;
	int copter_y;
	int copterIndex;
	bool copterShow;
};
enemycopter enemy[COPTERNUMBER];

void setEnemyVariables()
{
	for (int i = 0; i < COPTERNUMBER ; i++)
	{
		enemy[i].copter_x = 1360 + rand() % 300;
		enemy[i].copter_y = 350 + rand() % 250;
		enemy[i].copterShow = true;
	}
}

void easyenemyMovement()
{
	for (int i = 0; i < COPTERNUMBER - 2; i++)
	{
		if (enemy[i].copterShow)
		{
			iShowImage(enemy[i].copter_x, enemy[i].copter_y,200,112, enemycopterOne[enemy[i].copterIndex]);
		}
	}
}


void mediumenemyMovement()
{
	for (int i = 0; i < COPTERNUMBER - 1; i++)
	{
		if (enemy[i].copterShow)
		{
			iShowImage(enemy[i].copter_x, enemy[i].copter_y,200,112, enemycopterOne[enemy[i].copterIndex]);
		}
	}
}

void hardenemyMovement()
{
	for (int i = 0; i < COPTERNUMBER; i++)
	{
		if (enemy[i].copterShow)
		{
			iShowImage(enemy[i].copter_x, enemy[i].copter_y,200,112, enemycopterOne[enemy[i].copterIndex]);
		}
	}
}

int enemyspeed;

void enemypositionchange()
{
	for (int i = 0; i < COPTERNUMBER; i++)
	{
		enemy[i].copter_x -= enemyspeed;

		if (enemy[i].copter_x <=-100)
		{
			enemy[i].copter_x = 1360 + rand()%300;
		}
		
		enemy[i].copterIndex++;
		if (enemy[i].copterIndex == 2)
		{
			enemy[i].copterIndex = 0;
			
		}
	}
}
//Enemy Copter Algorithm End
//Enemy Bombing Algorithm Start

int enemybombpause;
int enemybombpic;
struct enemybomb
{
	int enemybomb_x;
	int enemybomb_y;
	bool enemybombShow;
};

enemybomb bomb[COPTERNUMBER];

void setBombVariables()
{
	for (int i = 0; i < COPTERNUMBER; i++)
	{
		bomb[i].enemybomb_x = enemy[i].copter_x + 50;
		bomb[i].enemybomb_y =  enemy[i].copter_y + 20;
		bomb[i].enemybombShow = true;
	}
}

void easybombMovement()
{
	for (int i = 0; i < COPTERNUMBER - 2; i++)
	{
		if (bomb[i].enemybombShow)
		{
			iShowImage(bomb[i].enemybomb_x, bomb[i].enemybomb_y , 50 , 15 , enemybombpic);
		}
	}
}

void mediumbombMovement()
{
	for (int i = 0; i < COPTERNUMBER - 1; i++)
	{
		if (bomb[i].enemybombShow)
		{
			iShowImage(bomb[i].enemybomb_x, bomb[i].enemybomb_y , 50 , 15 , enemybombpic);
		}
	}
}

void hardbombMovement()
{
	for (int i = 0; i < COPTERNUMBER; i++)
	{
		if (bomb[i].enemybombShow)
		{
			iShowImage(bomb[i].enemybomb_x, bomb[i].enemybomb_y , 50 , 15 , enemybombpic);
		}
	}
}

int bombspeed;

void bombpositionchange()
{
	for (int i = 0; i < COPTERNUMBER; i++)
	{
		bomb[i].enemybomb_x -=  bombspeed;
		if (bomb[i].enemybomb_x <=- 100)
		{
			bomb[i].enemybomb_x = enemy[i].copter_x + 50;
			bomb[i].enemybomb_y = enemy[i].copter_y + 20;
			bomb[i].enemybombShow=true;
		}
	}		
}
//Enemy Bombing Algorithm End