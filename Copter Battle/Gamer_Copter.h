//Copter Rendering Algorithm Start
int copterOne[3]; // array for gamer helicopter rendering
int index;
int c;// iset timer controller for helicopter fall
int copterfall; //Variable for falling helicopter
int cop_x = 20 , cop_y = 600 , dcopx = 150 , dcopy = 112; 
void render()   //Copter render function for idraw
{
	iShowImage(cop_x, cop_y, 200, 112 ,copterOne[index]);
}

void change()
{
	index++; 
	if(index==2)
	{
		index=0;
	}
}

void helicopter_fall() //helicopter falling function
{
	cop_y -=1;
}
//Copter Rendering Algorithm End
//Gamer Bombing Algorithm Start

int k=0; //variable for gamer bomb show after pressing f button
int Gamer_bomb; //iSetTimer controller for gamer bomb
int gBomb;
#define gbombnumber 100

struct gamerbomb
{
	int gbomb_x;
	int gbomb_y;
	bool gbombshow;

};

gamerbomb gbomb[gbombnumber];

void setgbomb()
{
	for (int i = k; i < gbombnumber ; i++)
	{
		gbomb[i].gbomb_x=cop_x + 85;
		gbomb[i].gbomb_y=cop_y + 10;
		gbomb[i].gbombshow=false;
	}
}

void gbombmovement()
{
	for (int i = 0; i < gbombnumber ; i++)
	{
		if(gbomb[i].gbombshow)
		iShowImage(gbomb[i].gbomb_x, gbomb[i].gbomb_y,50,15, gBomb);
	}
}

void gbombpositionchange()
{
	for (int i = 0; i < gbombnumber ; i++)
	{
		if (gbomb[i].gbombshow)
		{
			gbomb[i].gbomb_x += 12;
		}
	}

	for (int i = 0; i < gbombnumber ; i++)
	{
		if (gbomb[i].gbomb_x == 1700)
		{
			gbomb[i].gbomb_x = cop_x + 140;
		}
	}

}
//Gamer Bombing Algorithm End