#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int height=20,width=20,gameOver;
int score,x,y,fruitX,fruitY,flag=0;
void setup()//this will contain inital values
{
	gameOver=0;//when game will be over then it will be=1
	x=width/2;//these are x and y axis which will intialise the head of snake to the middle
	y=height/2;
	
	label1:
	fruitX=rand()%20;//initial position of fruit which will be a random value less then width of the boundry
	if(fruitX==0)
	{
		goto label1;
	}
	 
	 label2:
	 	fruitY=rand()%20;
	 	if(fruitY==0)
	 	{
	 		goto label2;
		}
	 score=0;
}
void draw()
{
	int i,j;
	system("cls");
	for(i=0;i<width;i++)
	{
		for(j=0;j<height;j++)
		{
			if(i==0||i==height-1||j==width-1||j==0)
			{
			   printf("*");	
			}
			else//blank area ka liya code
			{
				if(i==x&& j==y)
				   printf("O");//snake
				else if(i==fruitX &&j==fruitY)
				   printf("F");//fruit
				else
				  printf(" ");
			}
			
		}
		printf("\n");
	}
}
 void input()
 {
 	if(kbhit())//if some input then it returns a positive number else return -ve number
 	{
 		switch(getch())
 		{
 	      case 'a'://if user press a then snake left
		   flag=1; 	
		   break;
		   case 's'://if user press s then snake right
		   	flag=2;
		   	break;
		   	case 'w'://if user press w snake up;
		   	flag=3;
		   	break;
		   	case 'z'://user press z then snake down
		   	flag=4;
		   	break;
		   	case 'x'://if user press x then gameover
		   	gameOver=1;
		   	break;
		   		
		   		
	    }    
	 }
 }
 void makeLogic()
 {
 	switch(flag)
 	{
 		case 1:
 			y--;//move left
 			break;
 		case 2:
		    y++;//right
		    break;
		case 3:
		    x--;//up
			break;
		case 4:
		    x++;//down
		    
			break;	 
		default:
		    break;		
	}
	if(x<0||x>width||y<0||y>width)//boundry condition
	{
		gameOver=1;
	}
 }
int main()
{
	int m,n;
	setup();//this will intialise the values

	while(!gameOver)
	{
	
	   draw();//boundry of the snake in which it will move	   
	   input();//used to input value by user
	   makeLogic();//logic for movement of snake
	   for(m=0;m<1000;m++)//to make the speed slow
	   {
	   	for(n=0;n<1000;n++){
		   }
	   }
    }
		return (0);
}
