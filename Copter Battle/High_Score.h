//High Score Algorithm Start 
int t = 0; //timer variable for score
char str[100], str2[100];
 
void store_score()  //store score after game over
{
	FILE *fp=fopen("Score.txt","a");
    if(fp!=NULL)
    {
		fprintf(fp,"%s   %d\n",str2,t);
	}
	fclose(fp);
}

struct score_high
{
    char name[100];
    int n;
};

struct score_high s[1000];

void bubblesort(struct score_high s[], int l)  //shorting  scores... parameters are structures and total lines in the file
{
    int i, j;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < l; j++)
        {
            if (s[j].n < s[j + 1].n)
            {
                struct score_high p = s[j];
                s[j] = s[j + 1];
                s[j + 1] = p;
            }
        }
    }

}

void read()
{
    FILE *fp = fopen("Score.txt", "r");
    if (fp != NULL)
    {
        int i = 0;
        char x[100];
        int y;
        while (fscanf(fp, "%s %d", &x, &y)!=EOF)
        {
            strcpy(s[i].name, x);
            s[i].n = y;
            i++;
        }
        bubblesort(s, i);
    }
    else
    {
        printf("Error\n");
    }
    fclose(fp);
}

void show(struct score_high s[])
{
	char Highscore[20];
    int i,w;
    for (i = 0,w=0; i < 3; i++,w=w+70)
    {
		itoa(s[i].n,Highscore,10);
		iSetColor(0, 0, 0);
        iText(670, 420-w, Highscore , GLUT_BITMAP_TIMES_ROMAN_24);
		iText(600, 420-w, s[i].name , GLUT_BITMAP_TIMES_ROMAN_24);
    }
}
