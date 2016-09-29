# include <stdio.h>

void init (char* game)
{
  int i = 0;
        while (i < 17)
        {
                game[i] = ' ';
                if ((i % 2) != 0 && i != 5 && i !=5)
                {
                        game[i] = 'I';
                }
                if ( i == 5 || i == 11)
                {
                        game[i] = '\n';
                }
                i++;
        }
        game[17] = '\0';

}
void display (char* str)
{
	system("clear");
	printf("%s \n", str);
}

void play (char *str, int played, int i)
{
	switch (played)
	{
	case 1 : str[0] = (i % 2 == 0) ? 'x' : 'o' ;
		break;
	case 2 : str[2] = (i % 2 == 0) ? 'x' : 'o' ;
                break;
	case 3 : str[4] = (i % 2 == 0) ? 'x' : 'o' ;
                break;
	case 4 : str[6] = (i % 2 == 0) ? 'x' : 'o' ;
                break;
	case 5 : str[8] = (i % 2 == 0) ? 'x' : 'o' ;
                break;
	case 6 : str[10] = (i % 2 == 0) ? 'x' : 'o' ;
                break;
	case 7 : str[12] = (i % 2 == 0) ? 'x' : 'o' ;
                break;
	case 8 : str[14] = (i % 2 == 0) ? 'x' : 'o' ;
                break;
	case 9 : str[16] = (i % 2 == 0) ? 'x' : 'o' ;
                break;
	}

}
int dejavu (char* str, int played)
{
int i = 0;
switch (played)
        {
        case 1 : i = (str[0] == ' ') ?  0 : 1 ;
                break;
        case 2 : i = (str[2] == ' ') ? 0 : 1 ;
                break;
        case 3 : i = (str[4] == ' ') ? 0 : 1 ;
                break;
        case 4 : i = (str[6] == ' ') ? 0 : 1 ;
                break;
        case 5 : i = (str[8] == ' ') ? 0 : 1 ;
                break;
        case 6 : i = (str[10] == ' ')  ? 0 : 1 ;
                break; 
        case 7 : i = (str[12] == ' ') ? 0 : 1 ;
                break; 
        case 8 : i = (str[14] == ' ') ? 0 : 1 ;
                break; 
        case 9 : i = (str[16] == ' ') ? 0 : 1 ;
                break; 
        }
	return i;

}

int main (int argc, char** argv)
{
	char game[18];
	init (game);
	int played = 0;
	int i = 0;
	display(game);
	while (i < 9)
	{
	printf("quelle case jouer?");
	scanf("%d", &played);
	if (played > 0 && played < 10)
	{
		if(dejavu(game, played) == 0)
		{
			play(game, played, i);
			i++;
		}
	}
	display(game);
	//printf("%d", played);
	}


	return 0;
}
