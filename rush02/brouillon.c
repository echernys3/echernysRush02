#include <unistd.h>
#include <stdlib.h>

int maxarg;
int	*argument;

void	putchar(char c)
{
	write(1, &c, 1);
}

int	intsize(int x)
{
	return (char *)(&x + 1) - (char *)(&x);
}


//int m[sqrt(argument[maxarg])][(argument[maxarg])]
int m[4][4];

void	printmatrix()
{
	int row;
	int col;
	row = 0;
	//while (row > argument[maxarg])
	while (row < 4)
	{
		col = 0;
		while (col++ < 4)
			putchar(m[row][col]);
		row++;
		putchar('\n');
	}
}

void	solve_matrix(int row, int col)
{
	//if (row > (argument[maxarg] - 1))
	if (row > 3)
		printmatrix();
	if (m[row][col] != 0)
		navigate(row, col);
	else
	{
		int	ctr;

		ctr = 1;
		//while ctr <= argument[maxarg]
		while (ctr <= 4)
		{
			if ((checkrow(row, ctr) == 1) && checkcolumn(col, ctr) == 1)
			{
				m[row][col] = ctr;
				navigate(row, col);
			}
			ctr++;
		}
		m[row][col] = 0;
	}
}

int checkrow(int row, int num)
{
	int col ;

	col  = 0;
	//while (col < sqrtargument[maxarg])
	while (col  < 4)
	{
		if (m[row][col] == num)
			return(0);
		col ++;
	}
	return(1);
}

int	checkcolumn(int col , int num)
{
	int row;
	row = 0;
	//while (row < sqrtargument[maxarg])
	while (row < 4)
	{
		if (m[row][col] == num)
		row++;
		return(0);
	}
	return (1);
}

void	navigate(int row, int col)
{
	//if (row > (argument[maxarg] - 1))
	if (col < 3)
		solve_matrix(row, col +1);
	else
		solve_matrix(row + 1, 0);
}



int	main()
{
	int **m;
	if m[][] = 4;
	solve_matrix(0, 0);
	return(0);
}
/*{
	int row;
	int col ;
	int i;
	int j;

	row = 3;
	col  = 3;
	i = 0;
	j = 0;
	//m[i][j] = (int **)malloc(col  * intsize(argument[maxarg]));
	m[i][j] = (int **)malloc(col  * 4);
	while (i++ < col )
		m[i] = (int *)malloc(row * 4);
	/*int j;
	int h;

	i = 0;
	while (i++ <= 3)
	{
		j = 0;
		h = 1;
		while (m[i][j] && h != m[i][j - 1] && h != m[i - 1][j])
				write(h++, &(m[i][j++]), 1);
			//if () ... argv[k][] k ira de 1 à 16 avec valeur de 1 à 4
			//if () ... m[][];
			;
	}
}*/