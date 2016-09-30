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
			(*game)[i][j] = 0;
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
			(game[i][j] !=0 )? (game[i][j] == 3) ? printf("o"): printf("x") : printf(" ");;
			(j == 2) ? : printf("|");
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
	return (game[(played-1)/3][(played-1)%3] !=0) ? 1 : 0;
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
int main (int argc, char** argv)
{
	int **game = NULL;
	init (&game);
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
	
	printf("%d", played);
	}
	freegame(game);

//penser a ajouter un free reimplementer le jeu ajouter la verification de solution

	return 0;
}
