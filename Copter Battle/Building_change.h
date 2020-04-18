// building co ordinates

int w_building_x = 100, w_building_y =0,    dbuildx=1125,  dbuildy=320;
int w2_building_x = 900, w2_building_y =0,  d2buildx=199, d2buildy=275;
int w3_building_x = 1200, w3_building_y =0, d3buildx=138, d3buildy=275;
int w4_building_x = 1600, w4_building_y =0, d4buildx=467, d4buildy=330;
int w5_building_x = 1900, w5_building_y =0, d5buildx=200, d5buildy=240;
int w6_building_x = 2300, w6_building_y =0, d6buildx=141, d6buildy=270;


int building_pass; //buiding movement speed


void building_change()
{
	w_building_x -=building_pass;
	w2_building_x -=building_pass;
	w3_building_x -=building_pass;
	w4_building_x -=building_pass;
	w5_building_x -=building_pass;
	w6_building_x -=building_pass;
	
	
	if (w_building_x < -1450)
	{
		w_building_x = 1400;
	}
	if ( w2_building_x < -150)
	{
		 w2_building_x = 1600;
	}
	if (w3_building_x < -250)
	{
		w3_building_x = 1500;
	}
	if (w4_building_x < -700)
	{
		w4_building_x = 1700;
	}
	if (w5_building_x < -300)
	{
		w5_building_x = 1900;
	}
	if (w6_building_x < -350)
	{
		w6_building_x = 2100;
	}
}