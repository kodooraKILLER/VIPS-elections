/*
VE17-P.CPP


	a collective effort by the COMPUTER SCIENCE STUDENTS of XII A.The
progaram was born on 15 april 2017 at the VIPS computer lab. The main aim
of this program is to conduct a fair & easy elections for the post of the
president of VIPS for the consequent academic year.The advantages of
this bold attempt over the BALLOT PAPER system are:

>>Reduced manpower
>>Effecient and Economic
>>Fair and unbiased
>>Instantaneous calculation and declaration of results

PROGRAMMED,DEVELOPED AND HOSTED BY:
					*K.Karthikeyan
					*S.Sai Kiran
					*R.Senthil Kumar
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<string.h>
#include<iomanip.h>
#define MAX 3
#define MAXVOTE 470
struct hhmmss
{
int hr,min,sec,millisec;
char ampm[2];
}current,target;


float f=0;
float per=0.0;
int DIVIDE=1;
float candidate[MAX]={0,0,0};
char hide[80];
char name[MAX][20];
char ch[MAXVOTE];
void logo();
void function();
void time();
void colour(int a);
void code();
void result();
void cheat();

void main()
{
target.ampm[0]=current.ampm[0]='a';
target.ampm[1]=current.ampm[1]='m';

cout.setf(ios::fixed);
textcolor(BLACK);
textbackground(WHITE);
 int c,d;

for(int ccv=0;ccv<MAXVOTE;ccv++)
ch[ccv]='\0';

char crash;  //the waste character
code();      //function to set password

clrscr();
cheat();     //function to randomise candidates' list
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t   Set time in 24 hr format [HH MM SS]: ";
cin>>current.hr>>current.min>>current.sec;
time();
clrscr();
superstart:
int FLAG=0;
clrscr();

//the most important loop
for(;f<MAXVOTE&&ch[f]!=''&&FLAG!=2;++f)
{
clrscr();


logo();      //the vips logo!!
int swag=0;
clrscr();
top:
servoboot:
 time();
 FLAG=0;
//the presenter
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\t\t\t";
randomize;
colour(random(4));
cprintf("VIPS PRESIDENTIAL ELECTIONS 2K17");
textcolor(BLACK);
textbackground(WHITE);
cout<<"\n\t\t PROGRESS: "<<f<<" out of "<<MAXVOTE<<" ["<<setprecision(1)<<f*100/MAXVOTE<<"%] votes recorded ";
cout<<"\n\t\t\tEXPECTED FINISH = "<<target.hr<<":"<<target.min<<":"<<target.sec<<" "<<target.ampm[0]<<target.ampm[1]<<"\n\t\t\t  cast your vote on the EVM";



if(swag==0)  //START signal
{
sound(600);
delay(200);
sound(400);
delay(200);
sound(800);
delay(200);
swag++;
}
nosound();
textbackground(WHITE);


 if(kbhit())
 {
 ch[f]=getch();

 cout<<"\n\n";
 textcolor(BLUE);
 if(ch[f]=='2'||ch[f]=='6'||ch[f]=='0'||ch[f]=='')
{//END signal
 cprintf("YOU have voted for ");
 sound(600);
 delay(200);
 sound(400);
 delay(200);
 sound(800);
 delay(200);
 nosound();
 current.sec+=10;
 target.sec+=10;
}
 }
 else
 {
 delay(100);
 current.millisec+=100;
 goto top;
 }

 switch(ch[f]) //the most crucial part of program
 {
  case '2':puts(name[0]);
	   candidate[0]++;
	   break;
  case '6':puts(name[1]);
	   candidate[1]++;
	   break;
  case '0':puts(name[2]);//cout<<"CAND:4";
	   candidate[2]++;
	   break;
  /*case '8':puts(name[3]);//cout<<"CAND:5";
	   candidate[3]++;
	   break;
  case '0':puts(name[4]);//cout<<"CAND:6";
	   candidate[4]++;
	   break;*/
  case '':FLAG=2;
	   f--;
	   cout<<"\n";
	   break;
  default :FLAG=1;
	   cout<<"\n";
	   break;

}

if(FLAG==1)//RETURNS TO TOP if voter doesnt press
{
goto servoboot;
}
randomize;
int xc=random(8);
for(int i=0;i<80;i++) //to display bar
{
colour(xc);
cprintf("%c",178);
delay(62.5);
textcolor(BLACK);
textbackground(WHITE);
}

 for(int xo=0;xo<100;xo++)   //to "crash" up useless variables
 if(kbhit())
 crash=getch();

for(xo=0;xo<100;xo++)
if(kbhit())
crash=getch();

}

//password check block
clrscr();
int flag=0;
char sen[80];
cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tEnter password : ";
for(int cx=0;cx<80;cx++)
{
tp:
if(kbhit()) //for giving sounds while keypress
{
sen[cx]=getch();

	if(sen[cx]==13)
	{
	sen[cx]='\0';
	goto endst;
	}

	else if(sen[cx]==8)
	{
	sen[cx]='\0';
	cout<<char(8)<<" "<<char(8);
	cx-=2;
	sound(300);
	delay(100);
	nosound();
	}
else
{
cout<<"*";
sound(600);
delay(100);
nosound();
}
}
else goto tp;
}
endst:
for(cx=cx+1;cx<80;cx++)
sen[cx]='\0';
//cin.getline(sen,80);

d=strlen(hide);
c=strlen(sen);
if(c!=d)
{
flag=1;
}

//checking if passwords match
for(int sai=0,sai2=0;(sen[sai]!='\0'&& hide[sai2]!='\0'&& flag!=1);sai++,sai2++)
{
 if(sen[sai]!=hide[sai2])
 {
 flag=1;
 break;
 }
}

if (flag==0)//if passwords match,show result
result();
else        //or else,redirect
{
cout<<"\n\n\t\tWrong password,re-routing back to main page!";
sound(1000);
delay(200);
sound(3000);
delay(200);
sound(500);
delay(200);
nosound();
sleep(2.5);
ch[f]='\0';
goto superstart;
}
getch();
}
/////////////////////////////////////////////////////////////////////////////
//functions

void colour(int a)
{
switch(a)
{
case 0:textcolor(LIGHTGREEN);
       textbackground(BLACK);
       break;
case 1:textcolor(YELLOW);
       textbackground(BLACK);
       break;
case 5:textcolor(BLUE);
       textbackground(BLACK);
       break;
case 4:textcolor(RED);
       textbackground(YELLOW);
       break;
case 6:textcolor(MAGENTA);
       textbackground(WHITE);
       break;
case 3:textcolor(WHITE);
       textbackground(BLACK);
       break;
case 2:textcolor(LIGHTCYAN);
       textbackground(BLACK);
       break;
case 7:textcolor(BROWN);
       textbackground(YELLOW);
       break;
default:textcolor(WHITE);
       textbackground(BLACK);
       break;
}
}

void result()
{

textbackground(WHITE);
textcolor(BLACK);
clrscr();
cout<<"\n\t\t   VIDHYASAGAR INTERNATIONAL PUBLIC SCHOOL\n\t\t     PRESIDENTIAL ELECTIONS 2K17 RESULTS\n";
int max=0;
int win=0;
cout<<" \t\t       Attendance: "<<f<<" out of "<<MAXVOTE<<" ["<<setprecision(1)<<f*100/MAXVOTE<<"%]\n";
for(int i=0;i<MAX;i++)
{

if(max<candidate[i])
{
max=candidate[i];
win=i;                                                  //to show winner
}

if(max<40)
DIVIDE=1;
else if(max<80)
DIVIDE=2;
else if(max<120)
DIVIDE=3;
else if(max<160)
DIVIDE=4;
else if(max<200)
DIVIDE=5;
else if(max<240)
DIVIDE=6;
else if(max<280)
DIVIDE=7;

cout<<"\n\n ";
for(int len=0;name[i][len]!='\0';len++)
cout<<name[i][len];                			//name of candidate
for(;len<=15;len++)
cout<<" ";
cout<<": ";


	for(int x=candidate[i]/DIVIDE;x>=0;x--)
	{
	colour(i);
	cprintf("%c",178);                       //graphical representation
	}

cout<<candidate[i];
;
cout<<" ["<<setprecision(1)<<(candidate[i]/f)*100<<"%]";
}

cout<<"\n\n";


int tie=0;
int seed=0;

for(i=0;i<MAX;i++)
{

	if(i==win)
	;
	else
	{
		if(candidate[i]==candidate[win])
		{
		tie++;
		seed=1;
		}
		if(candidate[i]!=candidate[win])
		{
		seed=0;
		}


		if(tie==1&&seed==1)
		{
		cout<<" There's a tie between ";
		}


		if(tie>=1&&seed==1)
		{
		for(int xx=0;name[i][xx]!='\0';xx++)
		{
		cout<<name[i][xx];
		}
		cout<<", ";
		}

	}
}


if(tie==0)
{
cout<<"\n\t\t     THE Next president of VIPS is ";
}
puts(name[win]);
cout<<char(8);

sound(600);
delay(200);
sound(700);
delay(200);
sound(900);
delay(200);
sound(1100);
delay(400);
nosound();

}


void code()
{
clrscr();
char hide1[80];
int flag =0,c,d;
t:
cout<<"\n";
cout<<"Enter password\n";
for(int cx=0;cx<80;cx++)
{
tp:
if(kbhit())
{
hide[cx]=getch();

	if(hide[cx]==13)
	{
	hide[cx]='\0';
	sound(900);
	delay(100);
	nosound();
	goto endst;
	}

	else if(hide[cx]==8)
	{
	hide[cx]='\0';
	cout<<char(8)<<" "<<char(8);
	cx-=2;
	sound(300);
	delay(100);
	nosound();
	}

else
{
cout<<"*";
sound(600);
delay(100);
nosound();
}
}
else goto tp;
}
endst:
for(cx=cx+1;cx<80;cx++)
hide[cx]='\0';
				//			   cin.getline(hide,80);

cout<<"\n";
cout<<"Confirm password\n";
for(cx=0;cx<80;cx++)
{
tp2:
if(kbhit())
{
hide1[cx]=getch();
	if(hide1[cx]==13)
	{
	hide1[cx]='\0';
	sound(900);
	delay(100);
	nosound();
	goto endst2;
	}

	else if(hide1[cx]==8)
	{
	hide1[cx]='\0';
	cout<<char(8)<<" "<<char(8);
	cx-=2;
	sound(300);
	delay(100);
	nosound();
	}

else
{
cout<<"*";
sound(600);
delay(100);
nosound();
}
}
else goto tp2;
}
endst2:
for(cx=cx+1;cx<80;cx++)
hide1[cx]='\0';
//cin.getline(hide1,80);

c=strlen(hide);

d=strlen(hide1);
if(c!=d)
{
flag=1;
}


for(int i=0,j=0;hide[i]!='\0'&& hide[j]!='\0'&& flag!=1;i++,j++)
{

if( hide[i]!=hide1[j])
{
flag=1;
}
}

if(flag==1)
{
cout<<"\npasswords mismatch! pleasy try again! \n";
flag=0;
goto t;
}

else
{
cout<<"\nPassword has been successfully saved!\n";
}

getch();
}
void time()
{

target.sec=current.sec+(MAXVOTE-f)*10;
target.min=current.min;
target.hr=current.hr;
if(current.millisec>1000)
{
current.sec++;
current.millisec=current.millisec-1000;
}
if(current.sec>59)
{
current.min++;
current.sec=current.sec-60;
}
if(current.min>59)
{
current.hr++;
current.min=current.min-60;
}
if(current.hr>=12)
{
if(current.hr>12)
current.hr=current.hr-12;
current.ampm[0]='p';
}
if(target.millisec>=1000)
{
target.sec+=int(target.sec/1000);
target.millisec=(target.millisec%1000);
}
if(target.sec>=60)
{
target.min+=int(target.sec/60);
target.sec=(target.sec%60);
}
if(target.min>=60)

{
target.hr+=int(target.min/60);
target.min=(target.min%60);
}
if(target.hr>=12)
{
if(target.hr>12)
target.hr=target.hr-12;
target.ampm[0]='p';
}
}
void logo()
{
int gd=DETECT,gm;

initgraph(&gd,&gm,"C://TC//BGI");
detectgraph(&gd,&gm);
int rhy,rhx,i;

setbkcolor(WHITE);
setcolor(12);

//the letter vvvvvvvvvvvvvvvvvvvvv/////////////////////////////////////////////
setlinestyle(SOLID_LINE,1,3);
//center line left
line(270,110,270,170);

//center line right
line(270,110,270,170);

//left diagonal
line(270,170,245,60);

//line joining diagonal and center line
line(245,60,270,110);

//diagonal right
line(270,170,294,60);

//line joining the diagional right and center line right
line(294,60,270,110);



//the letter IIII //////////////////////////////////////////////////////////////////////////
//top of i
setcolor(43);
line( 290,130,310,130);

//diagonal of i
line(290,130,300,135);

//exdended part if i
line(300,135,310,135);


//joining part
line(310,135,310,130);

//straight line of i left
line(302,135,302,165);

//straight line of i right
line(304,135,304,165);

//down

line( 290,165,310,165);

//diagonal of i
line(290,165,300,170);

//exdended part if i
line(300,170,310,170);

//joining part
line(310,170,310,165);

////////the letter ppppppppppppppppppppppppppppp///////////////////////////

setcolor(22);
// starting line
line( 320,130,340,130);
//double line
line(320,133,340,133);

//joining::::
line(320,133,320,130);

//straight line
line(323,130,323,170);

//double
line(325,130,325,170);

//diagonal first/

line(340,130,325,150);
//diagonal second

line(340,133,325,153);

//line joining last
line(323,170,325,170);


//the letter sssssssssssssssssssssssss/////////////////////////////////////

setcolor(29);
//diagonal right
line(345,150,360,130);
//double
line(348,150,363,130);

//join::
line(360,130,363,130);

//straight
line(345,150,365,150);

// downwards
line(365,150,365,170);

//straight line down
line(365,170,340,170);

//double
line(365,167,345,167);

//diagonal
line(345,167,340,170);


/////////////////////////////////////////over/////////////////////////////////vipsssssssss.........
setcolor(18);
//////////////////start of the word eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeellllllllllllllllllllllllllllllllllllllllleeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeecccccccccccccccccccccccccccccccccctttttttttttttttttttttttttttttttttiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiooooooooooooooooooooooooooooooooooonnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn

//the starting letter eeeeeeee

line(252,200,285,200);
//double
line(252,203,285,203);
//downward straight line
line(255,200,255,260);
//double
line(252,200,252,263);
//join::::
line(285,200,285,203);

//center line eeeee
line(255,228,275,228);
//double
line(255,232,275,232);
//join::;
line(275,228,275,232);

//last lineeeee of eeeeee
line(255,260,285,260);
//last line double
line(252,263,285,263);
//join:::
line(285,260,285,263);



////the letter lllllllllllllllllllllllllllllll////////////////////////
setcolor(67);
//downwards straight
line(297,232,297,263);
//double
line(300,235,300,260);
//join::
line(297,232,300,235);
//down straight
line(297,263,317,263);
//down double
line(300,260,317,260);
//join::::
line(317,263,317,260);

//eeee
setcolor(17);
// the straight line
line(325,263,325,232);
//double
line(328,263,328,232);
//right line
line(325,232,345,232);
//double right
line(325,234,345,234);
//join::::
line(345,232,345,234);
//center line
line(325,247,340,247);
//double
line(325,249,340,249);
//join::::
line(340,247,340,249);
//downward
line(325,263,345,263);
//double
line(325,261,345,261);
//join
line(345,263,345,261);



///////////////////////////////the      cccccccccccccccccccccc

setcolor(92);
//startline top of ccc
line(355,232,375,232);
//double
line(355,235,377,235);
//join
line(375,232,377,235);

//straight line
line(355,232,355,263);
//double
line(357,232,357,263);
//end line
line(355,263,373,263);
//double
line(355,261,375,261);
//join::
line(373,263,375,261);



////////////////////the letter ttttttttttttttttttttt

setcolor(105);
//start line of ttt top
line(387,232,415,232);
//double
line(383,234,415,234);
//join::
line(387,232,383,234);
//straightline
line(400,232,400,263);
//double
line(402,232,402,263);
//join:::
line(400,263,402,263);
//join toppp
line(415,232,415,234);



//the letter IIII //////////////////////////////////////////////////////////////////////////
//top of i
setcolor(55);
line(425,232,445,232);
//double
line(425,234,445,234);
//join:::
line(445,232,445,234);
/////join front
line(425,232,425,234);
//
//stright line
line(433,232,433,263);
//double
line(435,232,435,263);
//straight
line(425,263,445,263);
//double
line(425,261,445,261);
//join left
line(425,263,425,261);
//join rght
line(445,263,445,261);
//


//////////////////////the leeeeeeetttttttteeeeerrrrrrr oooooooooooo
setcolor(6);
circle(470,247,17);
circle(470,247,15);

//////the letterrrrrrrrrrrrrrrrrrrr       nnnnnnnnnnnn
//straight line
setcolor(43);
line(495,263,495,232);
//double
line(497,263,497,238);
//line
line(495,232,498,232);
//right
line(516,258,516,210);
//left
line(518,263,518,210);
//join?::
line(518,263,515,263);
//diagonal
line(498,232,516,258);
//right
line(497,238,515,263);
//join::
line(518,210,516,210);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//tingering     startsssssss
setcolor(9);
circle(100,100,30);
circle(200,200,10);
circle(300,300,15);
circle(400,400,20);
circle(350,350,40);
circle(400,400,20);
circle(500,100,20);
circle(550,150,30);
circle(90,500,20);
circle(100,300,20);
circle(80,200,20);
circle(240,320,30);











sound(1000);
delay(200);
sound(800);
delay(200);
sound(600);
delay(200);
cleardevice();
closegraph();


}
void cheat()
{
randomize();
char dummy[MAX][20]={ "SARJUES AMAL","PRADEEP","NIVEDA"};
int flag[MAX],mainflag[MAX];
for(int i=0;i<MAX;i++)
{
flag[i]=mainflag[i]=0;
}
int x,y;

for(int p=0;p<MAX;p++)
{


do
{
x=random(MAX);
y=random(MAX);
}
while(mainflag[x]!=0||flag[y]!=0);
strcpy(name[x],dummy[y]);
mainflag[x]=flag[y]=1;

}

clrscr();
cout<<"\n\n\n\t\t    VIDHAYASAGAR INTERNATIONAL PUBLIC SCHOOL";
cout<<"\n\t\t           PRESIDENTIAL ELECTIONS 2K17\n\nList of candidates: \n\n";

for(int hj=0;hj<MAX;hj++)
{
cout<<hj+1<<" . ";
puts(name[hj]);
}

getch();
}
