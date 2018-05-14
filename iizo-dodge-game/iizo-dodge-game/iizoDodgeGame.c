/*
 ******************************************************
   Title         : iizo! DodgeGame (the dodge game)
   Making period : 2014.11.20 ~ 2014.12. 3
   Made By       : window9401@gmail.com + 1-J Class 2 Team
 ******************************************************
 */

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

// Moving Key
#define UP 72                        
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27

// MAP's scale and STAR's quanity
#define X 31
#define Y 31
#define MAX_STAR 56

// Time Function
time_t t1;
time_t t2;
time_t t3;

int		t;
int		x=15,y=15;
int		bgx=32;
int		bgy=17;
int		turn=0;
int		input;
void	inter_face(void);
void	remove_cursor(void);	// Cursor blinking remove
void	gotoxy(int , int );	// Cursor coordination setting
void	MM(void);				// Make Map
int		getkey();				// Key input
void	MI(int, int);			// Make Item
void	item();				// Item Make
void	move(int);				// Player moving
void	enemy();				// Enermy making
void	updatestar();			// Enermy(star) update real-time
void	start();				// Game's start
void	movestar();			// summoned star's managemanting
void	start_Menu();			// start menu
void	show_star();			// star's printing on console
void	SetColor();			// color setting
void	information();			// game's information

//Map
int block[Y][X] = {
      {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
      {4,5,9,5,9,5,9,5,9,5,9,5,9,5,9,5,9,5,9,5,9,5,9,5,9,5,9,5,9,5,4},
      {4,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,4},
      {4,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,4},
      {4,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,4},
      {4,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,4},
      {4,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,4},
      {4,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,4},
      {4,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,4},
      {4,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,4},
      {4,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,4},
      {4,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,4},
      {4,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,4},
      {4,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,4},
      {4,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,4},
      {4,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,4},
      {4,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,4},
      {4,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,4},
      {4,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,4},
      {4,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,4},
      {4,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,4},
      {4,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,4},
      {4,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,4},
      {4,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,4},
      {4,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,4},
      {4,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,4},
      {4,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,4},
      {4,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,4},
      {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,4},
      {4,5,9,5,9,5,9,5,9,5,9,5,9,5,9,5,9,5,9,5,9,5,9,5,9,5,9,5,9,5,4},
      {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4}
   };

//int star[2][50] = { {1},{1}};

int		star[MAX_STAR][2]={{0,0}};	//
int		tc;							//
int		turn_check=5;				//
int		flow;						// �ݺ��� ���� ���� �� ������ ��
int		value;						// �ݺ��� ���� ���� �� ��� ������ �������� �� rand�� �̿��Ұ��� �Ѥ�
int		starY, starX;				// ���Ե��� ��ǥ��... �����ؾߤŴ� ��


int main(void){
   int k;
   start();

   time(&t1);   // start time check
   remove_cursor();
   srand((unsigned)time(NULL));
   system("mode con lines=40 cols=100"); // �ܼ� ũ�⸦ ����
   MM();

   while(1){
      
	Sleep(10);   // �Ź� ���Ϲ��� �ݺ���ų�� ���ߵ� ���� ������ �����Լ�
	if(_kbhit()){
		k=_getch();
		move(k);
      }
    enemy();
    turn++;
	time(&t2);      // �� �ؿ��� ���� �ð� üũ
    t=t2-t1;      // ���� �ð� - ���۽ð� = ���� ��� �ð�
    inter_face();
    gotoxy(77,7);   // Ŀ�� �̵�(���� ����)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);      //������
    printf("%d�� %d��",t/60,t%60);   //���      
	if(t%1==0)   // ������ ���� ���� (���� ����)
      item();
    if(turn%turn_check==0)
	{
      updatestar();
	  movestar();
	}
	tc=t2-t3;
    if(tc==5)
		turn_check=5;

   } // end of while


}// end of main

void item(){
   int i,j,k;
   srand((unsigned)time(NULL));
   i= rand()%27+2;
   j= rand()%27+2;
   k= rand()%3;
   switch(k){
      case 0:
         block[i][j]=6;
         gotoxy(i*2+2,j+2);
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
         printf("��");
         break;
      
	  case 1:
         block[i][j]=7;
         gotoxy(i*2+2,j+2);
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
         printf("��");
         break;
      case 2:
         block[i][j]=8;
         gotoxy(i*2+2, j+2);
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
         printf("��");
         break; 
   } // end of switch
}; // making item



void remove_cursor(void)
{
   CONSOLE_CURSOR_INFO curInfo;
   GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
   curInfo.bVisible=0;
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
};// Ŀ�� ��¦�̴°� ����ִ� �Լ�

void MM(void){
   int x, y;
   for(y=0; y<32; y++){
      for(x=0; x<31; x++){
         if(block[y][x]==4){
            gotoxy(x*2+2, y+2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
            printf("��");
         }
      }
   }
};// ��� ����� �ִ� �Լ�

void gotoxy(int x, int y){
   COORD Pos = {x-1, y-1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
};// Ŀ�� �ű�� �Լ�

void move(int k){

   switch(k){
      case LEFT: if(x-1==1) break;
            else { 
            if(block[y][x-1]!=0){
               turn_check=20;
               gotoxy(40,38);
               printf("%d",turn_check);
               time(&t3);
            }
            bgx -= 2; x -= 1; 
            gotoxy(bgx+2,bgy); 
            printf("��"); 
            break;
            }

      case RIGHT: if(x+1==X-2) break;
            else {
            if(block[y][x+1]!=0){
            turn_check=20;
            gotoxy(40,38);
            printf("%d",turn_check);
            time(&t3);
            }
            bgx += 2; x += 1; 
            gotoxy(bgx-2, bgy); 
            printf("��"); 
            break;
            }

      case UP: if(y-1==1) break;
            else { 
            if(block[y-2][x]!=0){
               turn_check=20;
               gotoxy(40,38);
               printf("%d",turn_check);
               time(&t3);
             }
            bgy -= 1; y -= 1;  
            gotoxy(bgx, bgy+1); 
            printf("��"); 
            break;
            }

      case DOWN: if(y+1==Y-2) break;
            else {
            if(block[y][x]!=0){
            turn_check=20;
            gotoxy(40,38);
            printf("%d",turn_check);
            time(&t3);
            }
            bgy += 1; y += 1; 
            gotoxy(bgx, bgy-1); 
            printf("��"); 
            break;
            }
      case ESC: 
      default: break;
   }
   gotoxy(bgx,bgy);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
   printf("��");
   
};// �÷��̾� �̵� �Լ�
void enemy(){
   int x,y;
   for(y=1;y<32;y++){
      for(x=1;x<32;x++){ // �̰� ���� 32�� �ʿ��ֳ�? 31�̸� ���� �ʳ�? 
         switch(block[y][x]){
            case 5:
             gotoxy(x*2+2,y+2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
             printf("��");
             break;
            }
      }
   }
}// ���� ������ �Լ�

 
  void inter_face(void){
	  gotoxy(75,3);
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
      printf("���� �Ԥ���");
      gotoxy(70,5);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	  printf("���������ð���������");
      gotoxy(70,6);
      printf("��                ��");
      gotoxy(70,7);
      printf("��                ��");
      gotoxy(70,8);
      printf("��                ��");
      gotoxy(70,9);
      printf("��������������������");
      gotoxy(71,11);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
      printf("��");
      gotoxy(77,11);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
      printf("��");
      gotoxy(83,11);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
      printf("��");
      gotoxy(65,13);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	  printf("źȯ �ӵ��� ������ �մϴ�.(Ȯ��)");
      gotoxy(70,19);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
      printf("�� : ĳ���Ͱ� �·� �̵�");
      gotoxy(70,21);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
      printf("�� : ĳ���Ͱ� ��� �̵�");
      gotoxy(70,23);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
      printf("�� : ĳ���Ͱ� ���� �̵�");
      gotoxy(70,25);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
      printf("�� : ĳ���Ͱ� �������̵�");  
}; // �������̽� ���� �Լ�

  void updatestar()
  {
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

     for(flow=0; flow<MAX_STAR; flow++)
     {
        if(star[flow][0]==0 && star[flow][1]==0)
        {  
           if(flow==0)
              starY=2, 
              starX=2;

           else if(flow>=1 && flow<=13) // 1~13
              starY=2, 
              starX=flow*2+1;
           else if(flow==14) // 14�϶�
              starY=2, 
              starX=flow*2;
           else if( (flow>=15 && flow<=39) && flow%2==1) // 15~39 �� Ȧ��
              starY=flow-12,
              starX=2;
           else if( (flow>=16 && flow<=40) && flow%2==0) // 16~40 �� ¦��
              starY=flow-13,
              starX=28;
           else if(flow==41) // 41 ��
              starY=28,
              starX=2;
           else if(flow>=42 && flow<=54) // 42~54
              starY=28,
              starX=(flow-40)+(flow-40-1);
           else if(flow==55) // 55 ��
              starY=28, starX=28;

              star[flow][0]=starY; // ��� ������ ����;;;
			  star[flow][1]=starX; // �׷��� ���⵵ ����

              gotoxy(star[flow][1]*2+2,star[flow][0]+2);
              printf("��");
        }
     }
  }

void movestar()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

	for(flow=0; flow<MAX_STAR; flow++)
    {
		value=rand()%7;

        switch(value)
        {
        case 0: // ��

           if( (star[flow][1]-1)>1 && (star[flow][0]-1)>1 )
           {   
				if(block[star[flow][0]-1][star[flow][1]-1]==6 || block[star[flow][0]-1][star[flow][1]-1]==7) break;
				gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
				printf("  ");
				star[flow][0]-=1, star[flow][1]-=1;
				gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
				printf("��");
           }
           else
           {
              gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
              printf("  ");
              star[flow][0]=0;
              star[flow][1]=0;
           }
           if(star[flow][0]==y && star[flow][1]==x)
		   exit(1);
           break;

        case 1: // ��

           if(star[flow][0]-1>1)
           {
               gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
              printf("  ");
              star[flow][0]-=1;
              gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
              printf("��");
           }
           else
           {
              gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
              printf("  ");
              star[flow][0]=0;
              star[flow][1]=0;
           }
           if(star[flow][0]==y && star[flow][1]==x)
		   exit(1);
           break;

        case 2: // ��

           if( (star[flow][1]+1)!=X-2 && (star[flow][0]-1)>1 )
           {
           if(block[star[flow][0]+1][star[flow][1]-1]==6 || block[star[flow][0]+1][star[flow][1]-1]==7)
           break;
               gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
                printf("  ");
                              
               star[flow][0]-=1, star[flow][1]+=1;

               gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
                printf("��");
           }
           else
           {
              gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
              printf("  ");
              star[flow][0]=0;
              star[flow][1]=0;
           }
           if(star[flow][0]==y && star[flow][1]==x)
            exit(1);
           break;

        case 3: // ��

           if(star[flow][1]-1>1)
           {
           if(block[star[flow][0]][star[flow][1]-1]==6 || block[star[flow][0]][star[flow][1]-1]==7)
           break;

              gotoxy( (star[flow][1])*2+2, star[flow][0]+2 );
              printf("  ");
                            star[flow][1]-=1;
              gotoxy( (star[flow][1])*2+2, star[flow][0]+2 );
              printf("��");
           }
           else
           {
              gotoxy( (star[flow][1]+1)*2+2, star[flow][0]+2);
              printf("  ");
              star[flow][0]=0;
              star[flow][1]=0;
           }
		   if(star[flow][0]==y && star[flow][1]==x)
           exit(1);
           break;
          
		case 4: // ��

           if(star[flow][1]+1!=X-2)
           {
           if(block[star[flow][0]][star[flow][1]+1]==6 || block[star[flow][0]][star[flow][1]+1]==7)
           break;
              gotoxy( (star[flow][1])*2+2, star[flow][0]+2 );
              printf("  ");
                            star[flow][1]+=1;
              gotoxy( (star[flow][1])*2+2, star[flow][0]+2 );
              printf("��");
           }
           else
           {
              gotoxy( (star[flow][1]-1)*2+2, star[flow][0]+2);
              printf("  ");
              star[flow][0]=0;
              star[flow][1]=0;
           }
		   if(star[flow][0]==y && star[flow][1]==x)
		   exit(1);
           break;
         
		 case 5: // ��

           if( (star[flow][1]-1)>1 && (star[flow][0]+1)!=Y-2 )
           {
           if(block[star[flow][0]+1][star[flow][1]-1]==6 || block[star[flow][0]+1][star[flow][1]+1]==7)
           break;
               gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
                printf("  ");
                              
               star[flow][0]+=1, star[flow][1]-=1;

               gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
                printf("��");
           }
           else
           {
              gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
              printf("  ");
              star[flow][0]=0;
              star[flow][1]=0;
           }
           if(star[flow][0]==y && star[flow][1]==x)
		   exit(1);
           break;

        case 6: // ��

           if(star[flow][0]+1!=Y-2)
           {
           if(block[star[flow][0]+1][star[flow][1]]==6 || block[star[flow][0]+1][star[flow][1]]==7)
           break;
               gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
                printf("  ");
                              
               star[flow][0]+=1;

               gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
                printf("��");
           }
           else
           {
              gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
              printf("  ");
              star[flow][0]=0;
              star[flow][1]=0;
           }
           if(star[flow][0]==y && star[flow][1]==x)
		   exit(1);
           break;

         case 7: // ��

           if( (star[flow][1]+1)!=X-2 && (star[flow][0]+1)!=Y-2 )
           {
           if(block[star[flow][0]+1][star[flow][1]+1]==6 || block[star[flow][0]+1][star[flow][1]+1]==7)
           break;
               gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
                printf("  ");
                              
               star[flow][0]+=1, star[flow][1]+=1;

               gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
                printf("��");
           }
           else
           {
              gotoxy((star[flow][1])*2+2,(star[flow][0])+2);
              printf("  ");
              star[flow][0]=0;
              star[flow][1]=0;
           }
           if(star[flow][0]==y && star[flow][1]==x)
	       exit(1);
           break;
         } // end of switch
    } // end of for
} // end of function

// game's way
void information(void)
{
	int button; // for "switch" construction
	
	SetColor(15);
	gotoxy(20, 4);  puts("�̢̢̢̢̢̢̢̢̢̢�");
	gotoxy(20, 5);  puts("�� ��    ��     ��  ��");
	gotoxy(20, 6);  puts("��     ��  ��    �� ��");
	gotoxy(20, 7);  puts("�� ��               ��");
	gotoxy(20, 8);  puts("��        ��    ��  ��");
	gotoxy(20, 9);  puts("��  ��       ��     ��");
	gotoxy(20, 10); puts("��     ��       ��  ��");
	gotoxy(20, 11); puts("��  ��          ��  ��");
	gotoxy(20, 12); puts("�̢̢̢̢̢̢̢̢̢̢�");

	SetColor(15);
	gotoxy(18, 15);
	printf("�� ���� �̵��Ͽ� �ٰ����� ǥ��(��)�� ���ϴ� �����Դϴ�. \n\n");

	SetColor(8); 
	gotoxy(55, 4);   
	puts("��    = ��"); // wall
	SetColor(12); 
	gotoxy(55, 6);
	puts("�÷��̾� = ��"); // player
	SetColor(14);
	gotoxy(55, 8); 
	puts("������   = �� ��"); // item(star to slow by probability)
	SetColor(5);
	gotoxy(55, 10); 
	puts("ǥ�� = ��"); // enermy(star)

	SetColor(15);
	gotoxy(37,17);
	puts("����������������");
	gotoxy(37,18);
	puts("�� [1]�ڷΰ��⦢");
	gotoxy(37,19);
	puts("����������������");
	button=_getch();
	// if input value '1', break
	switch(button)
	{
	case '1':
	{
	system("cls");
	start_Menu();
	break;
	}
	default:
	{
	information();
	break;
	}
 }
}

// consol's text color setting
void SetColor(int color)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

// game's main scenes
void start_Menu(void)
{
   int i; // for "for" construction
   
   char arr[7][17]=
   {
      "����������������",
      "��1. ���� �����",
      "��2. ���� ���ۦ�",
      "��3. ���� ���ᦢ",
      "����������������"
   };

   SetColor(13);
   gotoxy(28, 2);  puts("�ܦ���������������������");
   gotoxy(28, 3);  puts("�����������ɫë����ѫভ");
   gotoxy(28, 4);  puts("�ܦ���������������������");

   SetColor(15);
   gotoxy(32, 7);

   for(i=0; i<=6; i++)
   {
      gotoxy(32, 7+i);
      printf("%s", arr[i]);
   }

   SetColor(14);
   gotoxy(31, 14);
   
   gotoxy(31, 16); puts("�̢̢̢̢̢̢̢̢̢�");
   gotoxy(31, 17); puts("��                ��");
   gotoxy(31, 18); puts("��   1-J    2��   ��");
   gotoxy(31, 19); puts("��                ��");
   gotoxy(31, 20); puts("�̢̢̢̢̢̢̢̢̢�");
}

// for "start_Menu" function
void start()
{
	remove_cursor();
	start_Menu();

   do{
      input = _getch();

      if(input=='1') // "information" Function call
      {
         system("cls"); // main scene removing
         information();
      }

      else if(input=='2') // Game start
      {
         system("cls");
         break;
      }

      else if(input=='3') // Game end
         exit(1);
      
      else
         continue;
   } while(1);
}