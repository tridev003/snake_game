#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int x,y,height=35,width=35,gameover=0;
int fruitX,fruitY,score,flag=0;
int tailX[100],tailY[100];
int countTail=0;

void setup()
{
	gameover=0;
	x=width/2;
	y=height/2;
	
	
	label1:
	fruitX=rand()%20;
	if(fruitX==0) 
		goto label1;
	
	
	label2:
	fruitY=rand()%20;
	if(fruitY==0)
		goto label2;
	
	}
	
	
int draw()
{
    int i,j,k;
	system("cls");
    for(i=0;i<width;i++)
    {
        for(j=0;j<height;j++)
        {
            if(i==0||j==0||i==height-1||j==width-1)
               {
                printf("*");
                }
        else
           {
		   int sml=1;
		   if(i==x && j==y)
           		printf("O");
           	else if(i==fruitX && j==fruitY)
           		printf("%c",sml);
           	else{
           		int ch=0;
           		for(k=0;k<countTail;k++)  //i,j
           		{
           			if(i==tailX[k] && j==tailY[k])
           			{
					   printf("o");
           			   ch=1;
					   }
				   }
				   if(ch==0)
				   	{
					   printf(" ");
        			
					}
           		
			   }
           	
           	

           }
        }
        printf("\n");


    }
    return 0;

}


void input()
{
	if(kbhit())
	{
		switch(getch())
		{case'a':
			flag=1;
			break;
		case 'd':
			flag=2;
			break;
		case 'w':
			flag=3;
			break;
		case 'z':
			flag=4;
			break;
		case 'x':
			gameover=1;
			break;
				
			
		}
	}
}


void logic()
{
	int i;
	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X,prev2Y;
	tailX[0]=x;
	tailY[0]=y;
	
	for(i=1;i<countTail;i++)
	{
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
		
		
	}
	
	

	switch(flag)
	{
		case 1:
			y--;
			break;
		case 2:
			y++;
			break;
		case 3:
			x--;
			break;
		case 4:
			x++;
			break;
		default:
			break;
			
}
	
if(x<0||x>width||y<0||y>height)
	gameover=1;
for(i=0;i<countTail;i++)
{
	if(x==tailX[i] && y==tailY[i])
		gameover=1;
}
if(x==fruitX && y==fruitY)
{
	label3:
	fruitX=rand()%20;
	if(fruitX==0)
		goto label3;
	
	
	label4:
	fruitY=rand()%20;
	if(fruitY==0)
		goto label4;
	
	score+=30;
    countTail++;
	
	
	
	
	}	
}
int main()
{	
int m,n;
char c;
	label5:
	setup();
	
	while(!gameover)
	{
	
	
    draw();
    input();
    logic();
    
  /*  for(m=0;m>=100000;m++)
    {for(n=0;n>=100000;n++)
    {
	}
	}*/
    
}

	printf("SCORE : %d",score);

	printf("\n PRESS Y TO CONTINUE : ");
	scanf("%c",&c);
	if(c=='Y' || c=='y')
		goto label5;
return 0;
}
