#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//define the s_book structure
typedef struct s_book
{
	char	title[100];
	char	author[100];
	int		year;
	struct s_book	*next;
} t_book;

t_book	*head = NULL;


void	add_book(char* title, char* author, int year)
{
	t_book	*new = (t_book *)malloc(sizeof(t_book));

	if (!new)
	{
		printf("Failed memory allocation\n");
		return ;//memory allocation error
	}
//Create the new book
	strcpy(new->title, title);
	strcpy(new->author, author);
	new->year = year;
	new->next = NULL;
//Add in the structuire list
	if (head == NULL || strcmp(head->title, title) > 0)
	{
		// printf("LINE: %d: title: %s, head_title: %s\n", __LINE__, title, head->title);
		new->next = head;
		head = new;
		return ;
	}
	t_book	*current = head;
	while(current->next != NULL && strcmp(current->title, title) < 0)
	{
		current = current->next;
	}
	// printf("LINE: %d: title: %s, curr_title: %s\n", __LINE__, title, current->title);
	new->next = current->next;
	current->next = new;
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
	add_book("TEST1", "test_author1", 1999);
	add_book("AIYEO", "test_author2", 1999);
	add_book("WHERE ARE YOU", "test_author3", 1920);

	printf("test after add_book\n");
	list_books();


	return 0;
}
