# include <stdio.h>
# include <stdlib.h>

void init (int*** game)
{
  	int i = 0;
  	*game = malloc(3*sizeof(int*));
  	while (i < 3)
	{
		(*game)[i] = malloc(3*sizeof(int));
		i++;
	}
	i = 0;
	int j = 0;
	while (i < 3)
	{
		while (j < 3)
		{
			(*game)[i][j] = 1;
			j++;
		}
	j = 0;
	i++;
	}

}
void display (int **game)
{
	system("clear");
	int i = 0;
	int j=  0;
	while (i < 3)
	{
		while (j < 3)
		{
			(game[i][j] !=1 )? (game[i][j] == 3) ? printf("o"): printf("x") : printf(" ");;
				printf("|");
			j++;
		}
	printf("\n");
	j = 0;
	i++;
	}
}

void play (int **game, int played, int i)
{
	game[(played-1)/3][(played-1)%3] = ( i % 2 == 0) ? 3 : 2 ;
}
int dejavu (int** game, int played)
{
	return (game[(played-1)/3][(played-1)%3] != 1) ? 1 : 0;
}

void freegame(int **game)
{
int i = 0;
int j = 0;

	while ( i < 3)
	{
		free(game[i]);
	i++;
	}
	free(game);
}
int won (int **game)
{
	int i = 0;
	for (i = 0 ;  i < 3; i++)
	{
	 if (game[i][0] == game[i][1] && game[i][1] == game[i][2] && game[i][0] != 1) 
	{
		return 1;
	}	
	}
	for ( i =0;i < 3; i ++)
        {
        if (game[0][i] == game[1][i] && game [1][i] == game[2][i] && game[0][i] != 1)
	{
		return 1;
	}
        }
	if (game[0][0] == game[1][1] && game[1][1]  == game[2][2] && game[1][1] != 1)
	{
		return 1;
	}

	if (game[0][2] == game[1][1] && game[1][1] == game[2][0]&& game[1][1] != 1)
	{
		return 1;
	}
	return 0;

}
int main (int argc, char** argv)
{
	int **game = NULL;
	init (&game);
	int played = 0;
	int i = 0;
	display(game);
	int winner = 0;
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
		if (i > 4)
		{
			if (won(game)  == 1)
			{
				winner = i%2;
				i = 9;
			}
		}
	
	display(game);
	}
	
	winner++;
	if (won(game) == 1)
	{
		printf("player %d won\n", winner);
	}
	freegame(game);


	return 0;
}
