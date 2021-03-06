//#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include "visualiser.h"

#define cell_at(y,x) cells[(y)*max_x + (x)] // Modify for correct boundary behaviour
#define cell_under_ant cell_at(ant->y, ant->x)
cell *cells;





void start_visualisation(struct ant* ant) {
  setlocale(LC_ALL, "");
   initscr();
   curs_set(FALSE);
   max_x = getmaxx(stdscr);
   max_y = getmaxy(stdscr);
   cells = calloc(max_y*max_x, sizeof(cell));
   ant->x = max_x/2;
   ant->y = max_y/2;
   ant->direction = RIGHT;
}

void visualise_and_advance(struct ant* ant) {
      int x,y=0;
      /* Draw cells and ant */
      for ( y=0; y<max_y; y++)
      {
         for ( x=0; x<max_x; x++)
         {
            mvprintw(y,x,
               ant_is_at(y,x)
                 ? direction_to_s(ant->direction)
                 : cell_at(y,x)
                    ? "█"
                    : " "
            );
         }
      }
      refresh();
      
      /* Advance to next step */
      apply_rule(&cell_under_ant, ant);
      move_forward(ant);
}

// Check if the user has input "q" to quit
bool not_quit() {
   return 'q' != getch();
}

void end_visualisation() {
   free(cells);
   endwin();
}

