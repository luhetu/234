#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "langton.h"
#include "visualiser.h"

// Set the ants direction so that it turns left
void turn_left(struct ant *ant)
{

   ant->direction =2;


   // TODO
}

// Set the ants direction so that it turns right
void turn_right(struct ant *ant)
{
   ant->direction = 3;
}
// TODO

// Actually move the ant forward based on it's current direction
// Should only be called after turn_left or turn_right
void move_forward(struct ant *ant)
{
   switch (ant->direction)
   {
   case 1:
      ant->y -= 1;
      if (ant->y == -1)
      {
         ant->x = 99;
      }
      break;

   case 2:
      ant->x -= 1;
      if (ant->x == -1)
      {
         ant->x = 99;
      }
      break;

   case 3:
      ant->x += 1;
      if (ant->x == 100)
      {
         ant->x = 0;
      }
      break;

   case 0:
      ant->y += 1;
      if (ant->y == 100)
      {
         ant->y = 0;
      }
      break;
   }
   // TODO
}

// Do not modify
const char *direction_to_s(enum direction d)
{
   return UP == d ? "^" : DOWN == d ? "v"
                      : LEFT == d   ? "<"
                                    :
                                  /* else */ ">";
}

// Call turn_left, or turn_right depending on the color of the current square,
// or in other words: apply the rule:
// * When at a white square, turn 90° clockwise, flip the color of the square to black and then move forward one unit.
// * When at a black square, turn 90° counter-clockwise, flip the color of the square to white and then move forward one unit.
void apply_rule(enum colour *colour, struct ant *ant)
{
   // int m = 100;
   // int n = 100;
   // int a[m][n];
   switch (colour->&colour)
   {
   case 1:
      /* code */
      turn_left(ant);
      *colour = 0;
      move_forward(ant);
      break;
   
   case 0:
      turn_right(ant);
      *colour = 1;
      move_forward(ant);
      break;
   }
   // TODO
}
