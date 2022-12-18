#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';
int heuristic[50][6],count=0,u=0;
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main()
{
   char winner = ' ';
   char response = ' ';

   do
   {
      winner = ' ';
      response = ' ';
      resetBoard();

      while(winner == ' ' && checkFreeSpaces() != 0)
      {
         printBoard();

         playerMove();
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }

         computerMove();
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }
      }

      printBoard();
      printWinner(winner);

      printf("\nWould you like to play again? (Y/N): ");
      //scanf("%c");
      scanf(" %c", &response);
      response = toupper(response);
   } while (response == 'Y');

   printf("Thanks for playing!");

   return 0;
}

void resetBoard()
{
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         board[i][j] = ' ';
      }
   }
}
void printBoard()
{
   printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
   printf("\n");
}
int checkFreeSpaces()
{
   int freeSpaces = 9;

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(board[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}
void playerMove()
{
   int x;
   int y;

   do
   {
      printf("Enter row #(1-3): ");
      scanf("%d", &x);
      x--;
      printf("Enter column #(1-3): ");
      scanf("%d", &y);
      y--;

      if(board[x][y] != ' ')
      {
         printf("Invalid move!\n");
      }
      else
      {
         board[x][y] = PLAYER;
         break;
      }
   } while (board[x][y] != ' ');

}
void computerMove()
{
   //creates a seed based on current time
   /*srand(time(0));
   int x;
   int y;*/

   if(checkFreeSpaces() > 0)
   {
      /*do
      {
         x = rand() % 3;
         y = rand() % 3;
      } while (board[x][y] != ' ');

      board[x][y] = COMPUTER;
   }*/int u=0,i,j;
         //  int n2[3][3]={0,0,0,0,0,0,0,0,0};
         i=0;
         j=1;
           if(board[i][j]!=PLAYER&&board[i][j]==' ')
           {
               board[i][j]=COMPUTER;

               if(i==0&&j==1)
               {
                    //n2[0][1]++;
                   if(board[i+1][j]!=PLAYER&&board[i+2][j]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i][j-1]!=PLAYER&&board[i][j+1]!=PLAYER)
                   {
                       count++;
                   }
                    if(board[i+1][j]==PLAYER&&board[i+2][j]==PLAYER||board[i][j-1]==PLAYER&&board[i][j+1]==PLAYER)
                   {
                       heuristic[u][5]=1;
                   }
                   else
                   {
                       heuristic[u][5]=0;
                   }
                   }
                   heuristic[u][0]=i;
                   heuristic[u][1]=j;
                   int c=0,k=0;
                    int l[3][3]={};
                           if(board[c][k]==COMPUTER)
                           {
                                l[0][0]++;
                                   if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                   {
                                       count++;
                                   }
                           }
                                 /*  c=0;
                                   c=1;
                                   if(board[c][k]==COMPUTER&&n2[0][1]==0)
                                   {
                                       l[0][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                           count++;
                                       }
                                   }*/
                                   c=0;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][2]++;
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                               count++;

                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c+2][k-2]!=PLAYER)
                                       {
                                           count++;
                                       }
                                   }

                                   c=1;
                                   k=0;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               count++;

                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                                count++;
                                           }
                                       }
                                   }
                                   c=1;
                                   k=1;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k+1]!=PLAYER&&board[c-1][k-1]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c-1][k+1]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                  c=1;
                                  k=2;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][2]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                               if(l[1][0]!=0||l[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=0;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               count++;
                                       }
                                       if(board[c-1][k+1]!=PLAYER&&board[c-2][k+2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                           if(l[1][0]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[2][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }
                                   c=2;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][2]++;
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                               if(l[1][2]!=0||l[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c-1][k-1]!=PLAYER&&board[c-2][k-2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                        if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                           if(l[2][1]!=0||l[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   heuristic[u][2]=count;
                                   count=0;
                                   int countx=0,s[3][3]={};
                                   c=0;
                                   k=0;
                                    if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                               countx++;
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k+1]!=COMPUTER&&board[c+2][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][1]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k-1]!=COMPUTER&&board[c+2][k-2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][1]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[1][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c+1][k-1]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k-1]!=COMPUTER&&board[c+1][k+1]!=COMPUTER)
                                       {
                                           if(s[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=1;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[1][0]!=0||s[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c-2][k+2]!=COMPUTER)
                                       {
                                           if(s[1][1]!=0||s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][1]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][2]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][2]!=0||s[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0||s[2][1]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   heuristic[u][3]=countx;
                                   heuristic[u][4]=(heuristic[u][3]-heuristic[u][2]);
                                   u++;
                                   board[i][j]=' ';

           }
           i=0;
           j=0;
           int l[3][3]={};
           if(board[i][j]!=PLAYER&&board[i][j]==' ')
           {
               board[i][j]=COMPUTER;

               if(i==0&&j==0)
               {
                    //n2[0][1]++;
                     l[0][0]++;
                   if(board[i+1][j]!=PLAYER&&board[i+2][j]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i][j+1]!=PLAYER&&board[i][j+2]!=PLAYER)
                   {
                       count++;
                   }
                    if(board[i+1][j+1]!=PLAYER&&board[i+2][j+2]!=PLAYER)
                   {
                       count++;
                   }
                    if((board[i+1][j]==PLAYER&&board[i+2][j]==PLAYER)||(board[i][j+1]==PLAYER&&board[i][j+2]==PLAYER)||(board[i+1][j+1]==PLAYER&&board[i+2][j+2]==PLAYER))
                   {
                       heuristic[u][5]=1;
                   }
                  else
                   {
                       heuristic[u][5]=0;
                   }

                   }
                   heuristic[u][0]=i;
                   heuristic[u][1]=j;
                   int c=0,k=0;

                           /*if(board[c][k]==COMPUTER)
                           {
                                l[0][0]++;
                                   if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                   {
                                       count++;
                                   }
                           }*/
                                  c=0;
                                   c=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                           count++;
                                       }
                                   }
                                   c=0;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][2]++;
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                               count++;

                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c+2][k-2]!=PLAYER)
                                       {
                                           count++;
                                       }
                                       if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }

                                   c=1;
                                   k=0;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               count++;

                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                                count++;
                                           }
                                       }
                                   }
                                   c=1;
                                   k=1;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k+1]!=PLAYER&&board[c-1][k-1]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c-1][k+1]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                               if(l[0][1]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }

                                       }
                                   }
                                  c=1;
                                  k=2;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][2]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                               if(l[1][0]!=0||l[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=0;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               count++;
                                       }
                                       if(board[c-1][k+1]!=PLAYER&&board[c-2][k+2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                           if(l[1][0]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[2][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }
                                   c=2;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][2]++;
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                               if(l[1][2]!=0||l[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c-1][k-1]!=PLAYER&&board[c-2][k-2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                        if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                           if(l[2][1]!=0||l[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   heuristic[u][2]=count;
                                   count=0;
                                   int countx=0,s[3][3]={};
                                   c=0;
                                   k=0;
                                    if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                               countx++;
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k+1]!=COMPUTER&&board[c+2][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][1]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k-1]!=COMPUTER&&board[c+2][k-2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][1]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[1][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c+1][k-1]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k-1]!=COMPUTER&&board[c+1][k+1]!=COMPUTER)
                                       {
                                           if(s[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=1;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[1][0]!=0||s[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c-2][k+2]!=COMPUTER)
                                       {
                                           if(s[1][1]!=0||s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][1]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][2]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][2]!=0||s[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0||s[2][1]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   heuristic[u][3]=countx;
                                   heuristic[u][4]=(heuristic[u][3]-heuristic[u][2]);
                                   u++;
                                   board[i][j]=' ';

           }
           i=0;
           j=2;
           if(board[i][j]!=PLAYER&&board[i][j]==' ')
           {
               board[i][j]=COMPUTER;
                int l[3][3]={};
               if(i==0&&j==2)
               {
                    //n2[0][1]++;
                    l[0][2]++;
                   if(board[i+1][j]!=PLAYER&&board[i+2][j]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i][j-1]!=PLAYER&&board[i][j-2]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i+1][j-1]!=PLAYER&&board[i+2][j-2]!=PLAYER)
                   {
                       count++;
                   }
                   if((board[i+1][j]==PLAYER && board[i+2][j]==PLAYER)||(board[i][j-1]==PLAYER && board[i][j-2]==PLAYER)||(board[i+1][j-1]==PLAYER && board[i+2][j-2]==PLAYER))
                   {
                       heuristic[u][5]=1;
                   }
                   else
                   {
                       heuristic[u][5]=0;
                   }
                   }
                   heuristic[u][0]=i;
                   heuristic[u][1]=j;
                   int c=0,k=0;

                           if(board[c][k]==COMPUTER)
                           {
                                l[0][0]++;
                                   if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                   {
                                       if(l[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                   }
                           }
                                  c=0;
                                   c=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[0][0]!=0||l[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                           count++;
                                       }
                                   }
                                   /*c=0;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][2]++;
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                               count++;

                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c+2][k-2]!=PLAYER)
                                       {
                                           count++;
                                       }
                                   }*/

                                   c=1;
                                   k=0;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               count++;

                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                                count++;
                                           }
                                       }
                                   }
                                   c=1;
                                   k=1;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k+1]!=PLAYER&&board[c-1][k-1]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c-1][k+1]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                  c=1;
                                  k=2;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][2]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                               if(l[1][0]!=0||l[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=0;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               count++;
                                       }
                                       if(board[c-1][k+1]!=PLAYER&&board[c-2][k+2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                           if(l[1][0]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[2][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }
                                   c=2;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][2]++;
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                               if(l[1][2]!=0||l[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c-1][k-1]!=PLAYER&&board[c-2][k-2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                        if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                           if(l[2][1]!=0||l[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   heuristic[u][2]=count;
                                   count=0;
                                   int countx=0,s[3][3]={};
                                   c=0;
                                   k=0;
                                    if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                               countx++;
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k+1]!=COMPUTER&&board[c+2][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][1]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k-1]!=COMPUTER&&board[c+2][k-2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][1]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[1][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c+1][k-1]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k-1]!=COMPUTER&&board[c+1][k+1]!=COMPUTER)
                                       {
                                           if(s[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=1;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[1][0]!=0||s[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c-2][k+2]!=COMPUTER)
                                       {
                                           if(s[1][1]!=0||s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][1]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][2]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][2]!=0||s[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0||s[2][1]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   heuristic[u][3]=countx;
                                   heuristic[u][4]=heuristic[u][3]-heuristic[u][2];
                                   u++;
                                   board[i][j]=' ';

           }
           i=1;
           j=0;
           count=0;
           if(board[i][j]!=PLAYER&&board[i][j]==' ')
           {
               board[i][j]=COMPUTER;
                int l[3][3]={};
                count=0;
               if(i==1&&j==0)
               {
                    //n2[0][1]++;
                    l[1][0]++;
                   if(board[i-1][j]!=PLAYER&&board[i+1][j]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i][j+1]!=PLAYER&&board[i][j+2]!=PLAYER)
                   {
                       count++;
                   }
                   if(((board[i-1][j]==PLAYER)&&(board[i+1][j]==PLAYER))||((board[i][j+1]==PLAYER)&&(board[i][j+2]==PLAYER)))
                   {
                       heuristic[u][5]=1;
                   }
                   else
                   {
                       heuristic[u][5]=0;
                   }

                   }
                   heuristic[u][0]=i;
                   heuristic[u][1]=j;
                   int c=0,k=0;

                           if(board[c][k]==COMPUTER)
                           {
                                l[0][0]++;
                                   if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                   {
                                       if(l[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                   }
                                   if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                   {
                                       count++;
                                   }
                                   if(board[c+1][k+1]!=PLAYER&&board[c+2][k+2]!=PLAYER)
                                   {
                                       count++;
                                   }
                           }
                                  c=0;
                                   k=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                           count++;
                                       }
                                   }
                                   c=0;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][2]++;
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                               count++;

                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c+2][k-2]!=PLAYER)
                                       {
                                           count++;
                                       }
                                       if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                           if(l[0][0]!=0||l[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }

                                  /* c=1;
                                   k=0;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               count++;

                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                                count++;
                                           }
                                       }
                                   }*/
                                   c=1;
                                   k=1;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k+1]!=PLAYER&&board[c-1][k-1]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c-1][k+1]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                           if(l[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }
                                  c=1;
                                  k=2;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][2]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                               if(l[1][0]!=0||l[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=0;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               count++;
                                       }
                                       if(board[c-1][k+1]!=PLAYER&&board[c-2][k+2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                           if(l[1][0]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[2][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                              if(l[1][1]!=0||l[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }

                                   }
                                   c=2;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][2]++;
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                               if(l[1][2]!=0||l[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c-1][k-1]!=PLAYER&&board[c-2][k-2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                        if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                           if(l[2][1]!=0||l[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   heuristic[u][2]=count;
                                   count=0;
                                   int countx=0,s[3][3]={};
                                   c=0;
                                   k=0;
                                    if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                               countx++;
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k+1]!=COMPUTER&&board[c+2][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][1]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k-1]!=COMPUTER&&board[c+2][k-2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][1]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[1][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c+1][k-1]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k-1]!=COMPUTER&&board[c+1][k+1]!=COMPUTER)
                                       {
                                           if(s[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=1;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[1][0]!=0||s[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c-2][k+2]!=COMPUTER)
                                       {
                                           if(s[1][1]!=0||s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][1]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][2]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][2]!=0||s[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0||s[2][1]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   heuristic[u][3]=countx;
                                   heuristic[u][4]=heuristic[u][3]-heuristic[u][2];
                                   u++;
                                   board[i][j]=' ';

           }
           i=1;
           j=1;
           count=0;
           if(board[i][j]!=PLAYER&&board[i][j]==' ')
           {
               board[i][j]=COMPUTER;
                int l[3][3]={};
                count=0;
               if(i==1&&j==1)
               {
                    //n2[0][1]++;
                    l[1][1]++;
                   if(board[i][j-1]!=PLAYER&&board[i][j+1]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i-1][j]!=PLAYER&&board[i+1][j]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i-1][j-1]!=PLAYER&&board[i+1][j+1]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i-1][j+1]!=PLAYER&&board[i+1][j-1]!=PLAYER)
                   {
                       count++;
                   }

                   if(board[i][j-1]==PLAYER&&board[i][j+1]==PLAYER)
                   {
                       heuristic[u][5]=1;
                   }
                   else
                   {
                       heuristic[u][5]=0;
                   }
                   if(board[i-1][j]==PLAYER&&board[i+1][j]==PLAYER)
                   {
                       heuristic[u][5]=1;
                   }
                   else
                   {
                       heuristic[u][5]=0;
                   }
                   if(board[i-1][j-1]==PLAYER&&board[i+1][j+1]==PLAYER)
                   {
                       heuristic[u][5]=1;
                   }
                   else
                   {
                       heuristic[u][5]=0;
                   }
                   if(board[i-1][j+1]==PLAYER&&board[i+1][j-1]==PLAYER)
                   {
                       heuristic[u][5]=1;
                   }
                   else
                   {
                       heuristic[u][5]=0;
                   }
                   }
                   heuristic[u][0]=i;
                   heuristic[u][1]=j;
                   int c=0,k=0;

                           if(board[c][k]==COMPUTER)
                           {
                                l[0][0]++;
                                   if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                   {
                                       if(l[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                   }
                                   if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                   {
                                       count++;
                                   }
                                   if(board[c+1][k+1]!=PLAYER&&board[c+2][k+2]!=PLAYER)
                                   {
                                       if(l[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                   }
                           }
                                  c=0;
                                   k=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                           if(l[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }
                                   c=0;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][2]++;
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                               count++;

                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c+2][k-2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                           if(l[0][0]!=0||l[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }

                                   c=1;
                                   k=0;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               if(l[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                                count++;
                                           }
                                       }
                                   }
                                   /*c=1;
                                   k=1;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k+1]!=PLAYER&&board[c-1][k-1]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c-1][k+1]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                           if(l[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }*/
                                  c=1;
                                  k=2;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][2]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                               if(l[1][0]!=0||l[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=0;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               count++;
                                       }
                                       if(board[c-1][k+1]!=PLAYER&&board[c-2][k+2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                           if(l[1][0]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[2][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                              if(l[1][1]!=0||l[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }

                                   }
                                   c=2;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][2]++;
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                               if(l[1][2]!=0||l[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c-1][k-1]!=PLAYER&&board[c-2][k-2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                        if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                           if(l[2][1]!=0||l[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   heuristic[u][2]=count;
                                   count=0;
                                   int countx=0,s[3][3]={};
                                   c=0;
                                   k=0;
                                    if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                               countx++;
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k+1]!=COMPUTER&&board[c+2][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][1]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k-1]!=COMPUTER&&board[c+2][k-2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][1]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[1][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c+1][k-1]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k-1]!=COMPUTER&&board[c+1][k+1]!=COMPUTER)
                                       {
                                           if(s[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=1;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[1][0]!=0||s[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c-2][k+2]!=COMPUTER)
                                       {
                                           if(s[1][1]!=0||s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][1]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][2]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][2]!=0||s[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0||s[2][1]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   heuristic[u][3]=countx;
                                   heuristic[u][4]=heuristic[u][3]-heuristic[u][2];
                                   u++;
                                   board[i][j]=' ';

           }
           i=1;
           j=2;
           count=0;
           if(board[i][j]!=PLAYER&&board[i][j]==' ')
           {
               board[i][j]=COMPUTER;
                int l[3][3]={};
                count=0;
               if(i==1&&j==2)
               {
                    //n2[0][1]++;
                    l[1][2]++;
                   if(board[i-1][j]!=PLAYER&&board[i+1][j]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i][j-1]!=PLAYER&&board[i][j-2]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i-1][j]==PLAYER&&board[i+1][j]==PLAYER||board[i][j-1]==PLAYER&&board[i][j-2]==PLAYER)
                   {
                       heuristic[u][5]=1;
                   }
                   else
                   {
                       heuristic[u][5]=0;
                   }
                   }
                   heuristic[u][0]=i;
                   heuristic[u][1]=j;
                   int c=0,k=0;

                           if(board[c][k]==COMPUTER)
                           {
                                l[0][0]++;
                                   if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                   {
                                                   count++;
                                   }
                                   if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                   {
                                       count++;
                                   }
                                   if(board[c+1][k+1]!=PLAYER&&board[c+2][k+2]!=PLAYER)
                                   {
                                       count++;
                                   }
                           }
                                  c=0;
                                   k=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                           count++;
                                       }
                                   }
                                   c=0;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][2]++;
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                                if(l[1][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c+2][k-2]!=PLAYER)
                                       {
                                           count++;
                                       }
                                       if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                           if(l[0][0]!=0||l[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }

                                   c=1;
                                   k=0;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               if(l[1][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                                count++;
                                           }

                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                                count++;
                                           }
                                       }
                                   }
                                   c=1;
                                   k=1;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[1][0]!=0||l[1][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k+1]!=PLAYER&&board[c-1][k-1]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c-1][k+1]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c+1][k]!=PLAYER&&board[c-1][k]!=PLAYER)
                                       {
                                           if(l[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }
                                  /*c=1;
                                  k=2;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][2]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                               if(l[1][0]!=0||l[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }*/
                                   c=2;
                                   k=0;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               count++;
                                       }
                                       if(board[c-1][k+1]!=PLAYER&&board[c-2][k+2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                           if(l[1][0]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[2][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                              if(l[1][1]!=0||l[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }

                                   }
                                   c=2;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][2]++;
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                               if(l[1][2]!=0||l[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c-1][k-1]!=PLAYER&&board[c-2][k-2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                        if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                           if(l[2][1]!=0||l[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   heuristic[u][2]=count;
                                   count=0;
                                   int countx=0,s[3][3]={};
                                   c=0;
                                   k=0;
                                    if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                               countx++;
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k+1]!=COMPUTER&&board[c+2][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][1]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k-1]!=COMPUTER&&board[c+2][k-2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][1]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[1][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c+1][k-1]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k-1]!=COMPUTER&&board[c+1][k+1]!=COMPUTER)
                                       {
                                           if(s[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=1;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[1][0]!=0||s[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c-2][k+2]!=COMPUTER)
                                       {
                                           if(s[1][1]!=0||s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][1]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][2]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][2]!=0||s[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0||s[2][1]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k-1]!=COMPUTER&&board[c-2][k-2]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0||s[2][1]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   heuristic[u][3]=countx;
                                   heuristic[u][4]=heuristic[u][3]-heuristic[u][2];
                                   u++;
                                   board[i][j]=' ';

           }
           i=2;
           j=0;
           count=0;
           if(board[i][j]!=PLAYER&&board[i][j]==' ')
           {
               board[i][j]=COMPUTER;
                int l[3][3]={};
                count=0;
               if(i==2&&j==0)
               {
                    //n2[0][1]++;
                    l[2][0]++;
                   if(board[i-1][j]!=PLAYER&&board[i-2][j]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i][j+1]!=PLAYER&&board[i][j+2]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i+1][j+1]!=PLAYER&&board[i+2][j+2]!=PLAYER)
                   {
                       count++;
                   }
                    if(board[i-1][j]==PLAYER&&board[i-2][j]==PLAYER||board[i][j+1]==PLAYER&&board[i][j+2]==PLAYER||board[i+1][j+1]==PLAYER&&board[i+2][j+2]==PLAYER)
                   {
                       heuristic[u][5]=1;
                   }
                   else
                   {
                       heuristic[u][5]=0;
                   }
                   }
                   heuristic[u][0]=i;
                   heuristic[u][1]=j;
                   int c=0,k=0;

                           if(board[c][k]==COMPUTER)
                           {
                                l[0][0]++;
                                   if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                   {
                                       if(l[2][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                   }
                                   if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                   {
                                       count++;
                                   }
                                   if(board[c+1][k+1]!=PLAYER&&board[c+2][k+2]!=PLAYER)
                                   {
                                       count++;
                                   }
                           }
                                  c=0;
                                   k=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                           count++;
                                       }
                                   }
                                   c=0;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][2]++;
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                               count++;

                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c+2][k-2]!=PLAYER)
                                       {
                                           if(l[2][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                           if(l[0][0]!=0||l[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }

                                   c=1;
                                   k=0;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               count++;

                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][0]!=0||l[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                                count++;
                                           }
                                       }
                                   }
                                   c=1;
                                   k=1;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k+1]!=PLAYER&&board[c-1][k-1]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c-1][k+1]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }
                                  c=1;
                                  k=2;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][2]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                               if(l[1][0]!=0||l[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                  /* c=2;
                                   k=0;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               count++;
                                       }
                                       if(board[c-1][k+1]!=PLAYER&&board[c-2][k+2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                           if(l[1][0]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }*/
                                   c=2;
                                   k=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[2][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                              if(l[1][1]!=0||l[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }

                                   }
                                   c=2;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][2]++;
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                               if(l[1][2]!=0||l[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c-1][k-1]!=PLAYER&&board[c-2][k-2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                        if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                           if(l[2][1]!=0||l[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   heuristic[u][2]=count;
                                   count=0;
                                   int countx=0,s[3][3]={};
                                   c=0;
                                   k=0;
                                    if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                               countx++;
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k+1]!=COMPUTER&&board[c+2][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][1]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k-1]!=COMPUTER&&board[c+2][k-2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][1]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[1][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c+1][k-1]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k-1]!=COMPUTER&&board[c+1][k+1]!=COMPUTER)
                                       {
                                           if(s[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=1;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[1][0]!=0||s[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c-2][k+2]!=COMPUTER)
                                       {
                                           if(s[1][1]!=0||s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][1]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][2]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][2]!=0||s[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0||s[2][1]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k-1]!=COMPUTER&&board[c-2][k-2]!=COMPUTER)
                                       {
                                           if(s[1][1]!=0||s[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   heuristic[u][3]=countx;
                                   heuristic[u][4]=heuristic[u][3]-heuristic[u][2];
                                   u++;
                                   board[i][j]=' ';

           }
            i=2;
            j=1;
            if(board[i][j]!=PLAYER&&board[i][j]==' ')
           {
               board[i][j]=COMPUTER;
                 int l[3][3]={};
                 count=0;
               if(i==2&&j==1)
               {
                    //n2[0][1]++;
                    l[2][1]++;
                   if(board[i-1][j]!=PLAYER&&board[i-2][j]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i][j-1]!=PLAYER&&board[i][j+1]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i-1][j]==PLAYER&&board[i-2][j]==PLAYER||board[i][j-1]==PLAYER&&board[i][j+1]==PLAYER)
                   {
                       heuristic[u][5]=1;
                   }
                   else
                   {
                       heuristic[u][5]=0;
                   }
                   }
                   heuristic[u][0]=i;
                   heuristic[u][1]=j;
                   int c=0,k=0;

                           if(board[c][k]==COMPUTER)
                           {
                                l[0][0]++;
                                   if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                   {
                                       count++;
                                   }
                                   if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                   {
                                       count++;
                                   }
                                   if(board[c+1][k+1]!=PLAYER&&board[c+2][k+2]!=PLAYER)
                                   {
                                       count++;
                                   }
                           }
                                  c=0;
                                   k=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                           if(l[2][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }
                                   c=0;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][2]++;
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                               count++;

                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c+2][k-2]!=PLAYER)
                                       {
                                           count++;
                                       }
                                       if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                               if(l[0][1]!=0||l[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }

                                   c=1;
                                   k=0;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               count++;

                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                                count++;
                                           }
                                       }
                                   }
                                   c=1;
                                   k=1;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k+1]!=PLAYER&&board[c-1][k-1]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c-1][k+1]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                  c=1;
                                  k=2;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][2]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                               if(l[1][0]!=0||l[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=0;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               if(l[2][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c-1][k+1]!=PLAYER&&board[c-2][k+2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                           if(l[1][0]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                 /*  c=2;
                                   k=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[2][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }*/
                                   c=2;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][2]++;
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                               if(l[1][2]!=0||l[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c-1][k-1]!=PLAYER&&board[c-2][k-2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                        if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                           if(l[2][1]!=0||l[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   heuristic[u][2]=count;
                                   count=0;
                                   int countx=0,s[3][3]={};
                                   c=0;
                                   k=0;
                                    if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                               countx++;
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k+1]!=COMPUTER&&board[c+2][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][1]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k-1]!=COMPUTER&&board[c+2][k-2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][1]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[1][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c+1][k-1]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k-1]!=COMPUTER&&board[c+1][k+1]!=COMPUTER)
                                       {
                                           if(s[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=1;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[1][0]!=0||s[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c-2][k+2]!=COMPUTER)
                                       {
                                           if(s[1][1]!=0||s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][1]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][2]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][2]!=0||s[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0||s[2][1]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                        if(board[c-1][k-1]!=COMPUTER&&board[c-2][k-2]!=COMPUTER)
                                       {
                                           if(s[1][1]!=0||s[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   heuristic[u][3]=countx;
                                   heuristic[u][4]=heuristic[u][3]-heuristic[u][2];
                                   u++;
                                   board[i][j]=' ';

           }
           i=2;
            j=2;
            if(board[i][j]!=PLAYER&&board[i][j]==' ')
           {
               board[i][j]=COMPUTER;
                 int l[3][3]={};
                 count=0;
               if(i==2&&j==2)
               {
                    //n2[0][1]++;
                    l[2][2]++;
                   if(board[i-1][j]!=PLAYER&&board[i-2][j]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i][j-1]!=PLAYER&&board[i][j-2]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i-1][j-1]!=PLAYER&&board[i-2][j-2]!=PLAYER)
                   {
                       count++;
                   }
                   if(board[i-1][j]==PLAYER&&board[i-2][j]==PLAYER||board[i][j-1]==PLAYER&&board[i][j-2]==PLAYER||board[i-1][j-1]==PLAYER&&board[i-2][j-2]==PLAYER)
                   {
                       heuristic[u][5]=1;
                   }
                   else
                   {
                       heuristic[u][5]=0;
                   }
                   }
                   heuristic[u][0]=i;
                   heuristic[u][1]=j;
                   int c=0,k=0;

                           if(board[c][k]==COMPUTER)
                           {
                                l[0][0]++;
                                   if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                   {
                                       count++;
                                   }
                                   if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                   {
                                       count++;
                                   }
                                   if(board[c+1][k+1]!=PLAYER&&board[c+2][k+2]!=PLAYER)
                                   {
                                       if(l[2][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                   }
                           }
                                  c=0;
                                   k=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                                   count++;
                                       }
                                   }
                                   c=0;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[0][2]++;
                                       if(board[c+1][k]!=PLAYER&&board[c+2][k]!=PLAYER)
                                       {
                                               if(l[2][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c+2][k-2]!=PLAYER)
                                       {
                                           count++;
                                       }
                                       if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                               if(l[0][1]!=0||l[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }

                                   c=1;
                                   k=0;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               count++;

                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c+1][k]!=PLAYER)
                                       {
                                           if(l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                                count++;
                                           }
                                       }
                                   }
                                   c=1;
                                   k=1;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c+1][k+1]!=PLAYER&&board[c-1][k-1]!=PLAYER)
                                       {
                                           if(l[0][0]!=0||l[2][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c+1][k-1]!=PLAYER&&board[c-1][k+1]!=PLAYER)
                                       {
                                           if(l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                           if(l[1][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                  c=1;
                                  k=2;
                                    if(board[c][k]==COMPUTER)
                                   {
                                       l[1][2]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                               if(l[1][0]!=0||l[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c+1][k]!=PLAYER&&board[c-1][k]!=PLAYER)
                                       {
                                           if(l[0][2]!=0||l[2][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=0;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][0]++;
                                       if(board[c][k+1]!=PLAYER&&board[c][k+2]!=PLAYER)
                                       {
                                               if(l[2][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c-1][k+1]!=PLAYER&&board[c-2][k+2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                           if(l[1][0]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }
                                 c=2;
                                   k=1;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][1]++;
                                       if(board[c][k-1]!=PLAYER&&board[c][k+1]!=PLAYER)
                                       {
                                               if(l[2][0]!=0||l[2][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                               if(l[0][1]!=0||l[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }
                                       }
                                   }
                                   /*c=2;
                                   k=2;
                                   if(board[c][k]==COMPUTER)
                                   {
                                       l[2][2]++;
                                       if(board[c-1][k]!=PLAYER&&board[c-2][k]!=PLAYER)
                                       {
                                               if(l[1][2]!=0||l[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   count++;
                                               }

                                       }
                                       if(board[c-1][k-1]!=PLAYER&&board[c-2][k-2]!=PLAYER)
                                       {
                                           if(l[1][1]!=0||l[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                        if(board[c][k-1]!=PLAYER&&board[c][k-2]!=PLAYER)
                                       {
                                           if(l[2][1]!=0||l[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               count++;
                                           }
                                       }
                                   }*/
                                   heuristic[u][2]=count;
                                   count=0;
                                   int countx=0,s[3][3]={};
                                   c=0;
                                   k=0;
                                    if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                               countx++;
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k+1]!=COMPUTER&&board[c+2][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][1]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=0;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c+1][k-1]!=COMPUTER&&board[c+2][k-2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c+1][k]!=COMPUTER&&board[c+2][k]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                   }
                                   c=1;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][1]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                               if(s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[1][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c+1][k-1]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                       if(board[c-1][k-1]!=COMPUTER&&board[c+1][k+1]!=COMPUTER)
                                       {
                                           if(s[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=1;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[1][2]++;
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                               if(s[1][0]!=0||s[1][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c-1][k]!=COMPUTER&&board[c+1][k]!=COMPUTER)
                                       {
                                           if(s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=0;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[0][0]!=0||s[1][0]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k+1]!=COMPUTER&&board[c][k+2]!=COMPUTER)
                                       {
                                           countx++;
                                       }
                                       if(board[c-1][k+1]!=COMPUTER&&board[c-2][k+2]!=COMPUTER)
                                       {
                                           if(s[1][1]!=0||s[0][2]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=1;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[0][0]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][1]!=0||s[0][1]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k+1]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   c=2;
                                   k=2;
                                   if(board[c][k]==PLAYER)
                                   {
                                       s[2][2]++;
                                       if(board[c-1][k]!=COMPUTER&&board[c-2][k]!=COMPUTER)
                                       {
                                               if(s[1][2]!=0||s[0][2]!=0)
                                               {

                                               }
                                               else
                                               {
                                                   countx++;
                                               }
                                       }
                                       if(board[c][k-1]!=COMPUTER&&board[c][k-2]!=COMPUTER)
                                       {
                                           if(s[2][0]!=0||s[2][1]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                        if(board[c-1][k-1]!=COMPUTER&&board[c-2][k-2]!=COMPUTER)
                                       {
                                           if(s[1][1]!=0||s[0][0]!=0)
                                           {

                                           }
                                           else
                                           {
                                               countx++;
                                           }
                                       }
                                   }
                                   heuristic[u][3]=countx;
                                   heuristic[u][4]=heuristic[u][3]-heuristic[u][2];
                                   u++;
                                   board[i][j]=' ';

           }
           printf("i\tj\tO\tH\t H-O\tWin\n");
           int local_min=heuristic[0][4],minrep=0;
           for(int we=0;we<u;we++)
           {
               if(local_min>heuristic[we][4])
               {
                   local_min=heuristic[we][4];
                   minrep=we;

               }
               printf("%d\t%d\t%d\t%d\t%d\t%d\n",heuristic[we][0],heuristic[we][1],heuristic[we][2],heuristic[we][3],heuristic[we][4],heuristic[we][5]);
           }
           for(int ant=0;ant<u;ant++)
           {
               if(heuristic[ant][5]==1)
                   {
                       local_min=heuristic[ant][4];
                   minrep=ant;
                   break;
                   }
           }
           int trex,trex2;
           trex=heuristic[minrep][0];
           trex2=heuristic[minrep][1];
           board[trex][trex2]=COMPUTER;
          /* printf("i\tj\tO\tH\t H-O\n");
           printf("%d\t%d\t%d\t%d\t%d\n",heuristic[0][0],heuristic[0][1],heuristic[0][2],heuristic[0][3],heuristic[0][4]);
            printf("%d\t%d\t%d\t%d\t%d\n",heuristic[1][0],heuristic[1][1],heuristic[1][2],heuristic[1][3],heuristic[1][4]);
            printf("%d\t%d\t%d\t%d\t%d\n",heuristic[2][0],heuristic[2][1],heuristic[2][2],heuristic[2][3],heuristic[2][4]);
            printf("%d\t%d\t%d\t%d\t%d\n",heuristic[3][0],heuristic[3][1],heuristic[3][2],heuristic[3][3],heuristic[3][4]);
            printf("%d\t%d\t%d\t%d\t%d\n",heuristic[4][0],heuristic[4][1],heuristic[4][2],heuristic[4][3],heuristic[4][4]);
            printf("%d\t%d\t%d\t%d\t%d\n",heuristic[5][0],heuristic[5][1],heuristic[5][2],heuristic[5][3],heuristic[5][4]);
            printf("%d\t%d\t%d\t%d\t%d\n",heuristic[6][0],heuristic[6][1],heuristic[6][2],heuristic[6][3],heuristic[6][4]);
             printf("%d\t%d\t%d\t%d\t%d\n",heuristic[7][0],heuristic[7][1],heuristic[7][2],heuristic[7][3],heuristic[7][4]);
              printf("%d\t%d\t%d\t%d\t%d\n",heuristic[8][0],heuristic[8][1],heuristic[8][2],heuristic[8][3],heuristic[8][4]);*/
              u=0;
              //heuristic[50][5]={0};
}
   else
   {
      printWinner(' ');
   }
}
char checkWinner()
{
   //check rows
   for(int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }
   //check columns
   for(int i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }
   //check diagonals
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }

   return ' ';
}
void printWinner(char winner)
{
   if(winner == PLAYER)
   {
      printf("YOU WIN!");
   }
   else if(winner == COMPUTER)
   {
      printf("YOU LOSE!");
   }
   else{
      printf("IT'S A TIE!");
   }
}
