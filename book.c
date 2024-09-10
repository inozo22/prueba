#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//define the s_book structure
typedef struct s_book
{
	char	*title;
	char	*author;
	int		year;
	struct s_book	*next;
} t_book;

t_book	*head = NULL;


void	add_book(char* title, char* author, int year)
{

}

bool	search_book(char* title)
{
	//return true when finds the book
}

void	remove_book(char* title)
{
	//search book, when find the book, delete it

}

void	list_books(void)
{
	if (head == NULL)
	{
		printf("There is no data.\n");
		return ;
	}
	t_book	*current = head;
	while (current != NULL)
	{
		printf("title: %s author: %s published year: %d\n", current->title, current->author, current->year);
		current = current->next;
	}
}



int	main(int ac, char **av)
{
	(void)ac, av;
	printf("test without any data\n");
	list_books();



	return 0;
}
