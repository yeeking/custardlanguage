/**
 * This class represents the curses interface. The interface has 4 panels:
 * 1. Machine panel: shows which steo in the program is being executed
 * 2. Data panel: shows the data held in the machine
 * 3. Editor panel: allows the user to edit the program
 * 4. Library panel: shows context sensitive information, e.g. a list of possible completions for the editor
 * The Interpreter listens to the editor panel for edits. It then sends command objects to the CustardMachine which updates data and commands on the running protram. 
 * The RunningProgram displayed in the Machine windows is provided by the CustardMachine, helped by the sequencer. (The CustardMachine constists of a sequence of commands plus some data). 
 * The Interpreter provides the info avout the Library. 
*/

#include <panel.h>


int startx = 0;
int starty = 0;

void print_menu(WINDOW *menu_win, int highlight);


char *choices[] = { 
			"Choice 1",
			"Choice 2",
			"Choice 3",
			"Choice 4",
			"Exit",
		  };
int n_choices = sizeof(choices) / sizeof(char *);

int main()
{	
  WINDOW *my_wins[4];
	PANEL  *my_panels[4];
	int n_panels = 4;
	int lines = 10, cols = 40, y = 2, x = 4, i;
	WINDOW *menu_win;
	int highlight = 1;
	int choice = 0;
	int c;

	initscr();
	cbreak();
	noecho();

	/* Create windows for the panels */
	
	my_wins[0] = newwin(lines, cols, y, x);
	my_wins[1] = newwin(lines, cols, y, x + cols);
	my_wins[2] = newwin(lines, cols, y + lines, x);
	my_wins[3] = newwin(lines, cols, y + lines, x + cols);
	/* 
	 * Create borders around the windows so that you can see the effect
	 * of panels
	 */
	for(i = 0; i < n_panels; ++i)
		box(my_wins[i], 0, 0);

	/* Attach a panel to each window */ 	/* Order is bottom up */
	my_panels[0] = new_panel(my_wins[0]); 	/* Push 0, order: stdscr-0 */
	my_panels[1] = new_panel(my_wins[1]); 	/* Push 1, order: stdscr-0-1 */
	my_panels[2] = new_panel(my_wins[2]); 	/* Push 2, order: stdscr-0-1-2 */
	my_panels[3] = new_panel(my_wins[3]); 	/* Push 2, order: stdscr-0-1-2 */

	/* Update the stacking order. 2nd panel will be on top */
	update_panels();

	/* Show it on the screen */
	doupdate();
	
	keypad(my_wins[0], TRUE);
	//refresh();
	//for (i=0; i<n_panels;++i){
	mvwprintw(my_wins[0], 0, 1, "DATA");
	print_menu(my_wins[0], 0);	  
	mvwprintw(my_wins[1], 0, 1, "PROGRAM");
	print_menu(my_wins[1], 0);	  
	mvwprintw(my_wins[2], 0, 1, "EDITOR");
	print_menu(my_wins[2], 0);	  
	mvwprintw(my_wins[3], 0, 1, "HELP");
	print_menu(my_wins[3], 0);	  
	//wrefresh(my_wins[i]);

	//}
	

	getch();
	endwin();



}

void print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, i;	

	x = 2;
	y = 2;
	// i think box draws a blank box
	//box(menu_win, 0, 0);
	for(i = 0; i < n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE); 
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}
