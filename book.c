#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//define the s_book structure
typedef struct s_book
{
	char	title[100];
	char	author[100];
	int		year;
	struct s_book	*next;
} t_book;

t_book	*head = NULL;

char	*to_uppercase(char *str)
{
	char *ret = str;
	char ch;

	for (int i = 0; ret[i]; i++)
	{
		putchar(toupper(ret[i]));
	}
	return ret;
}


void	add_book(char* title, char* author, int year)
{
	t_book	*new = (t_book *)malloc(sizeof(t_book));
	char	*tmp_title;
	
	tmp_title = to_uppercase(title);

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

void	search_book(char* title)
{
	t_book	*current = head;
	while (current != NULL)
	{
		if (strcmp(title, current->title) == 0)
		{
			printf("Search book success!\n");
			printf("title: %s author: %s published year: %d\n", current->title, current->author, current->year);
			return ;
		}
		current = current->next;
	}
	printf("Search book failed, there is no book named as %s\n", title);
}

void	remove_book(char* title)
{
	if (head == NULL)
	{
		printf("There is no data to delete.\n");
		return ;
	}
	t_book *tmp = head;
	if (strcmp(head->title, title) == 0)
	{
		head = head->next;
		free (tmp);
		printf("The book: %s deleted succussesfully!\n", title);
		return ;
	}
	t_book *pre = NULL;
	while (tmp != NULL && strcmp(tmp->title, title) != 0)
	{
		pre = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		printf("There is no book to delete.\n");
		return ;
	}
	pre->next = tmp->next;
	free (tmp);
	printf("The book: %s deleted succussesfully!\n", title);
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
	add_book("test1", "test_author1", 1999);
	add_book("AIYEO", "test_author2", 1999);
	add_book("WHERE ARE YOU", "test_author3", 1920);

	printf("test after add_book\n");
	list_books();

	search_book("TEST1");
	remove_book("TEST1");
	list_books();



	return 0;
}
