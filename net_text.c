#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include "game_io.h"
#include <stdbool.h>

void grid_display(game g);

int main(int argc, char const *argv[]) {

   int *x=(int*)malloc(sizeof(*x));
   int *y=(int*)malloc(sizeof(*y));
   piece *p=(piece*)malloc(25*sizeof(*p));
   direction *d=(direction*)malloc(25*sizeof(*d));
   game jeu=malloc(sizeof(jeu));
   if (p==NULL || d==NULL || jeu==NULL || x==NULL || y==NULL)
   {
     printf("echec alloc\n");
     return EXIT_FAILURE;
   }
   p[0]=0;p[1]=3;p[2]=0;p[3]=0;p[4]=0;p[5]=0;p[6]=3;p[7]=3;p[8]=2;
   p[9]=1;p[10]=0;p[11]=0;p[12]=3;p[13]=0;p[14]=1;p[15]=3;p[16]=3;
   p[17]=3;p[18]=3;p[19]=3;p[20]=2;p[21]=0;p[22]=0;p[23]=2;p[24]=0;

   d[0]=E;d[1]=W;d[2]=S;d[3]=E;d[4]=S;d[5]=S;d[6]=S;d[7]=N;d[8]=W;
   d[9]=N;d[10]=E;d[11]=N;d[12]=W;d[13]=W;d[14]=W;d[15]=S;d[16]=W;
   d[17]=N;d[18]=E;d[19]=E;d[20]=W;d[21]=N;d[22]=W;d[23]=N;d[24]=S;
   jeu=new_game(p,d);
   while(!is_game_over(jeu))
   {
    grid_display(jeu);
    printf("\n\tx=       0 1 2 3 4\n");
    printf("\n\tEntez les coordonnes de X et Y : ");
    scanf("%d %d",x,y);
    if (*x>=0 && *x<game_width(jeu) && *y>=0 && *y<game_height(jeu))
      rotate_piece_one(jeu,*x,*y);
   }
   grid_display(jeu);
   printf("\n\tx=       0 1 2 3 4\n\n\t\a\a\aFIN DU JEU :) :')\n");
   free(p);free(d);free(jeu);free(x);free(y);
  return EXIT_SUCCESS;
}
void grid_display(game g)
{
  for (int i=game_height(g)-1; i >=0; i--)
  {
    printf("\n\ty= %d |   ",i);
      for (int j = 0; j < game_width(g); j++)
      {
          switch (get_piece(g,j,i))
          {
            case 0 :
                      switch(get_current_dir(g,j,i))
                      {
                        case N :  printf("^ ");break;
                        case E :  printf("> ");break;
                        case S :  printf("v ");break;
                        case W :  printf("< ");break;
                      }
                      break;//OBLIGATOIRE
            case 1 :
                      switch(get_current_dir(g,j,i))
                      {
                        case N :  printf("| ");break;
                        case E :  printf("- ");break;
                        case S :  printf("| ");break;
                        case W :  printf("- ");break;
                      }
                      break;
            case 2 :
                      switch(get_current_dir(g,j,i))
                      {
                        case N :  printf("└ ");break;
                        case E :  printf("┌ ");break;
                        case S :  printf("┐ ");break;
                        case W :  printf("┘ ");break;
                      }
                      break;
            case 3 :
                      switch(get_current_dir(g,j,i))
                      {
                        case N :  printf("┴ ");break;
                        case E :  printf("├ ");break;
                        case S :  printf("┬ ");break;
                        case W :  printf("┤ ");break;
                      }
                      break;
            case -1 : printf(" ");
          }
      }
      printf("  |  ");
  }
printf("\n" );
}
