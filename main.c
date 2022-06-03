#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
int kesh=1,s=0,m=0,temporary=1;//kesh =1 as false ,m=1 as row of stored elements for player 2,s=1 for player 1
int store1=1,store2=12; //this variables represent column of removed pieces
int ArrKing[4]={8,7,1,7};//this array store kings positions
int ArrKesh[4];//in this array we store position of kech enemy and king place
char undoArr[100][5];//this array i used to store data input
int undocount=-1;//this count i use to change Array rows in undoArr
int placeOutPiece1[16][2];//thid function to store places of removed pieces by player 1
int placeOutPiece2[16][2];//thid function to store places of removed pieces by player 2
int checkKeshPice(char a[][14],char inputArr[],int x)//here we do not need to check horse or pawns as the way from that is to move king or kill en
{ char E1[3]={'r','q','b'},E2[3]={'R','Q','B'};
    //check for player 2
    if(x%2==0){
     for(int i=0;i<2;i++)
    {if(a[ArrKesh[0]][ArrKesh[1]]==E1[i])
    { // i check first if king is in row and rook is on right side and then if rook is on left
        if((ArrKesh[0]==57-inputArr[3]&&((inputArr[2]-62)>ArrKesh[3]&&(inputArr[2]-62)<ArrKesh[1]))||
           (ArrKesh[0]==57-inputArr[3]&&((inputArr[2]-62)<ArrKesh[3]&&(inputArr[2]-62)>ArrKesh[1])))
        {

            return 0;
        }
     // i check if king in column and rook is above and then if rook is down
        else if((ArrKesh[1]==inputArr[2]-62&&((57-inputArr[3])>ArrKesh[0]&&(57-inputArr[3])<ArrKesh[2]))||
                (ArrKesh[1]==inputArr[2]-62&&((57-inputArr[3])<ArrKesh[0]&&(57-inputArr[3])>ArrKesh[2])))
        {

            return 0;
        }
    }}
   for(int i=1;i<3;i++){
    if(a[ArrKesh[0]][ArrKesh[1]]==E1[i])
    {// i check first if king is in right diagonal or in left and bishop is on left diagonal
        if((((abs((57-inputArr[3])-ArrKesh[2])==abs((inputArr[2]-62)-ArrKesh[3]))&&(57-inputArr[3])>ArrKesh[0]&&(57-inputArr[3])<ArrKesh[2])
           &&(ArrKesh[1]>(inputArr[2]-62)&&(inputArr[2]-62)>ArrKesh[3]))||(((abs((57-inputArr[3])-ArrKesh[2])==abs((inputArr[2]-62)-ArrKesh[3]))&&(57-inputArr[3])>ArrKesh[0]&&(57-inputArr[3])<ArrKesh[2])
           &&(ArrKesh[1]<(inputArr[2]-62)&&(inputArr[2]-62)<ArrKesh[3]))||
           (((abs((57-inputArr[3])-ArrKesh[2])==abs((inputArr[2]-62)-ArrKesh[3]))&&(57-inputArr[3])<ArrKesh[0]&&(57-inputArr[3])>ArrKesh[2])
           &&(ArrKesh[1]<(inputArr[2]-62)&&(inputArr[2]-62)<ArrKesh[3]))||(((abs((57-inputArr[3])-ArrKesh[2])==abs((inputArr[2]-62)-ArrKesh[3]))&&(57-inputArr[3])<ArrKesh[0]&&(57-inputArr[3])>ArrKesh[2])
           &&(ArrKesh[1]>(inputArr[2]-62)&&(inputArr[2]-62)>ArrKesh[3])))
        {
            return 0;
        }
    }}
    }
    if(x%2!=0){
     for(int i=0;i<2;i++)
    {if(a[ArrKesh[0]][ArrKesh[1]]==E2[i])
    { // i check first if king is in row and rook is on right side and then if rook is on left
        if((ArrKesh[0]==57-inputArr[3]&&((inputArr[2]-62)>ArrKesh[3]&&(inputArr[2]-62)<ArrKesh[1]))||
           (ArrKesh[0]==57-inputArr[3]&&((inputArr[2]-62)<ArrKesh[3]&&(inputArr[2]-62)>ArrKesh[1])))
        {
            return 0;
        }
     // i check if king in column and rook is above and then if rook is down
        else if((ArrKesh[1]==inputArr[2]-62&&((57-inputArr[3])>ArrKesh[0]&&(57-inputArr[3])<ArrKesh[2]))||
                (ArrKesh[1]==inputArr[2]-62&&((57-inputArr[3])<ArrKesh[0]&&(57-inputArr[3])>ArrKesh[2])))
        {
            return 0;
        }
    }}
   for(int i=1;i<3;i++)
    {if(a[ArrKesh[0]][ArrKesh[1]]==E2[i])
    {// i check first if king is in right diagonal or in left and bishop is on left diagonal
       if((((abs((57-inputArr[3])-ArrKesh[2])==abs((inputArr[2]-62)-ArrKesh[3]))&&(57-inputArr[3])>ArrKesh[0]&&(57-inputArr[3])<ArrKesh[2])
           &&(ArrKesh[1]>(inputArr[2]-62)&&(inputArr[2]-62)>ArrKesh[3]))||(((abs((57-inputArr[3])-ArrKesh[2])==abs((inputArr[2]-62)-ArrKesh[3]))&&(57-inputArr[3])>ArrKesh[0]&&(57-inputArr[3])<ArrKesh[2])
           &&(ArrKesh[1]<(inputArr[2]-62)&&(inputArr[2]-62)<ArrKesh[3]))||
           (((abs((57-inputArr[3])-ArrKesh[2])==abs((inputArr[2]-62)-ArrKesh[3]))&&(57-inputArr[3])<ArrKesh[0]&&(57-inputArr[3])>ArrKesh[2])
           &&(ArrKesh[1]<(inputArr[2]-62)&&(inputArr[2]-62)<ArrKesh[3]))||(((abs((57-inputArr[3])-ArrKesh[2])==abs((inputArr[2]-62)-ArrKesh[3]))&&(57-inputArr[3])<ArrKesh[0]&&(57-inputArr[3])>ArrKesh[2])
           &&(ArrKesh[1]>(inputArr[2]-62)&&(inputArr[2]-62)>ArrKesh[3])))
        {
            return 0;

        }
    }
    }

}
return 1;
}
int checkKesh(char a[][14],char inputArr[],int x)
{  char kingsymplol,E1[3]={'R','Q','B'},E2[3]={'r','q','b'},tempoARR[3],tempHourse;
    if(x%2!=0)
    {
        tempHourse='n';
        kingsymplol='K';
        for(int i=0;i<3;i++)
        {
            tempoARR[i]=E2[i];
        }
    }
    else if(x%2==0)
    { tempHourse='N';
        kingsymplol='k';
        for(int i=0;i<3;i++)
        {
            tempoARR[i]=E1[i];
        }
    }
    for(int j=0;j<2;j++) //in this i check for both rooks and king
     {//check for right rooks
     if(a[57-inputArr[3]][inputArr[2]-62]==tempoARR[j])
     {for(int i=1;i<=(10-(inputArr[2]-62));i++)//here we limit right moves
      {
          if(a[57-inputArr[3]][inputArr[2]-62+i]==kingsymplol)
          {
              ArrKesh[2]=57-inputArr[3];// here i store the king place which is in check
              ArrKesh[3]=inputArr[2]-62+i;
              return 0;
          }
          else if(a[57-inputArr[3]][inputArr[2]-62+i]!=' ')
          {
              break;
          }
      }
      //check for left rooks
     for(int i=1;i<=(inputArr[2]-62-3);i++)//i made it 2 to neglect previos king//////////
      {
          if(a[57-inputArr[3]][inputArr[2]-62-i]==kingsymplol)
          {
               ArrKesh[2]=57-inputArr[3];// here i store the king place which is in check
              ArrKesh[3]=inputArr[2]-62-i;
              return 0;
          }
          else if(a[57-inputArr[3]][inputArr[2]-62-i]!=' ')
          {
              break;
          }
      }
      //check for top rooks
     for(int i=1;i<=(57-inputArr[3]-1);i++)
      {
          if(a[57-inputArr[3]-i][inputArr[2]-62]==kingsymplol)
          {
              ArrKesh[2]=57-inputArr[3]-i;// here i store the king place which is in check
              ArrKesh[3]=inputArr[2]-62;
               return 0;
          }
          else if(a[57-inputArr[3]-i][inputArr[2]-62]!=' ')
          {
              break;
          }
      }
      //check for down rook
     for(int i=1;i<=(8-(57-inputArr[3]));i++)
      {
          if(a[57-inputArr[3]+i][inputArr[2]-62]==kingsymplol)
          {
              ArrKesh[2]=57-inputArr[3]+i;// here i store the king place which is in check
              ArrKesh[3]=inputArr[2]-62;
              return 0;
          }
          else if(a[57-inputArr[3]+i][inputArr[2]-62+i]!=' ')
          {
              break;
          }
      }}}
           //check for both queen and bishops
     for(int j=1;j<3;j++)
     {
          //check for right top bishops
         if(a[57-inputArr[3]][inputArr[2]-62]==tempoARR[j]){
         for(int i=1;i<=(57-inputArr[3]-1);i++)//i limit the i so that i do not reach to first raw
      {
          if(a[57-inputArr[3]-i][inputArr[2]-62+i]==kingsymplol)//////////////////
          {
              return 0;
          }
          else if(a[57-inputArr[3]-i][inputArr[2]-62+i]!=' ')
          {
              break;
          }
      }
      //check for left top king
     for(int i=1;i<=(57-inputArr[3]-1);i++)//i limit the i so that i do not reach to first raw
      {   //printf("%c",a[57-inputArr[3]-i][inputArr[2]-62-i]);
          if(a[57-inputArr[3]-i][inputArr[2]-62-i]==kingsymplol)
          {
              return 0;
          }
          else if(a[57-inputArr[3]-i][inputArr[2]-62-i]!=' ')//here i add king because i want to miss previous king
          {
              break;
          }
      }
      //check for right down bishops
     for(int i=1;i<=(8-(57-inputArr[3]));i++)
      {
          if(a[57-inputArr[3]+i][inputArr[2]-62+i]==kingsymplol)
          {
              return 0;
          }
          else if(a[57-inputArr[3]+i][inputArr[2]-62+i]!=' ')
          {
              break;
          }
      }
      //check for left down bishops
     for(int i=1;i<=(8-(57-inputArr[3]));i++)
      {
          if(a[57-inputArr[3]+i][inputArr[2]-62-i]==kingsymplol)
          {
              return 0;//as kesh occur
          }
          else if(a[57-inputArr[3]+i][inputArr[2]-62-i]!=' ')
          {
              break;
          }
      }}}
      // i check about hourse
      if(a[57-inputArr[3]][inputArr[2]-62]==tempHourse)
      {if(a[57-inputArr[3]+2][inputArr[2]-62+1]==kingsymplol||a[57-inputArr[3]+2][inputArr[2]-62-1]==kingsymplol||a[57-inputArr[3]-2][inputArr[2]-62-1]==kingsymplol
        ||a[57-inputArr[3]-2][inputArr[2]-62+1]==kingsymplol||a[57-inputArr[3]+1][inputArr[2]-62+2]==kingsymplol||a[57-inputArr[3]+1][inputArr[2]-62-2]==kingsymplol
        ||a[57-inputArr[3]-1][inputArr[2]-62-2]==kingsymplol||a[57-inputArr[3]-1][inputArr[2]-62+2]==kingsymplol)
     {
         return 0;
     }}
      return 1;////as kesh do not occur
}
void printArr(char a[][14])
{   char sign1='-',sign2='.',temp1;
    for(int i=0;i<10;i++)
{
    for(int j=0;j<14;j++)
    {
       if((i>0&&i<9)&&(j>2&&j<11)) //we limit this period to be in interval of playing
       {  if(j%2!=0)          //here if column is odd for first row we print - after swap
           {printf("%C",sign2);
           printf("%C ",a[i][j]);}
           else{
            printf("%C",sign1);
           printf("%C ",a[i][j]);
           }
       }
       else{
        printf(" %C ",a[i][j]);}
    }
    temp1=sign1;
    sign1=sign2;
    sign2=temp1;
    printf("\n");
}
}
void makeArr(char a[][14])
{

    int num;

    //printf("%c",a[0][0]);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<14;j++)
        {
            if((i>2&&i<7)&&(j>2&&j<11))//we fill roes of A B C and so on.
            {
                a[i][j]=' ';
                a[0][j]=62+j; //first character represents 62+3=65 ->'A'
                a[9][j]=62+j;// the same put in buttom.
            }

               if(j>2&&j<11)//>2 because first 2 columns are free to store removed piece and third is for num 1,2,..,8
            {
                a[1][3]='R';a[1][10]='R';a[1][9]='N';a[1][4]='N';
                a[1][5]='B';a[1][8]='B';a[1][6]='Q';a[1][7]='K';
                a[8][3]='r';a[8][10]='r';a[8][9]='n';a[8][4]='n';
                a[8][5]='b';a[8][8]='b';a[8][6]='q';a[8][7]='k';
                a[2][j]='P';
                a[7][j]='p';
            }
            //here we fill numbers we start from i==1.
            else if((j==2||j==11)&&(i!=0&&i!=9))
            {  num=57-i;
                a[i][2]=num;
                a[i][11]=num;
            }
            else{a[i][j]=' ';}
        }}
    printArr(a);
}
// this function check if next move is correct for knights
int checkKnights(char a[][14],char inputArr[],int x)
{
    if(kesh==1){
      char ArrE1[5]={'p','r','b','n','q'},ArrE2[5]={'P','R','N','Q','B'};
     char rOOt,TEMPARR[5];//this array i use to make use of x%2==0 and x%2!=0
      int tempVAR,columN ;
         if(x%2!=0)
        {rOOt='n';
         tempVAR=s;
         for(int i=0;i<5;i++)
         {
            TEMPARR[i]=ArrE1[i];
         }
         columN=store1;//this when i use to store delete element
        }
        else if(x%2==0)
        {
         rOOt='N';
         tempVAR=m;
         for(int i=0;i<5;i++)
         {
            TEMPARR[i]=ArrE2[i];
         }
          columN=store2; //this when i use to store delete element
        }
        //check that next move is not on my piece
         for(int i=0;i<5;i++)
            {
                if(a[57-inputArr[3]][(inputArr[2]-62)]==TEMPARR[i])
                 {
                     return 1;
                 }
            }
     //here i check that the next nove is valid for hourse
        if(((inputArr[2]==inputArr[0]-1)&&inputArr[3]==inputArr[1]-2)||((inputArr[2]==inputArr[0]-2)&&inputArr[3]==inputArr[1]-1)||
           ((inputArr[2]==inputArr[0]-2)&&inputArr[3]==inputArr[1]+1)||((inputArr[2]==inputArr[0]-1)&&inputArr[3]==inputArr[1]+2)||
           ((inputArr[2]==inputArr[0]+1)&&inputArr[3]==inputArr[1]-2)||((inputArr[2]==inputArr[0]+2)&&inputArr[3]==inputArr[1]-1)
           ||((inputArr[2]==inputArr[0]+1)&&inputArr[3]==inputArr[1]+2)||((inputArr[2]==inputArr[0]+2)&&inputArr[3]==inputArr[1]+1))
        {

            if(a[57-inputArr[3]][(inputArr[2]-62)]==' '&&a[57-inputArr[1]][(inputArr[0]-62)]==rOOt)
            {
               if(temporary==1){
             a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
             a[57-inputArr[1]][(inputArr[0]-62)]=' ';
             kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;
             }}
             return 0;
            }
            else if(a[57-inputArr[3]][(inputArr[2]-62)]!=' '&&a[57-inputArr[1]][(inputArr[0]-62)]==rOOt)
            {
                if(temporary==1){
             tempVAR++;
             if(x%2!=0){s++;}
             else if(x%2==0){m++;}
             a[tempVAR][columN]= a[57-inputArr[3]][(inputArr[2]-62)];
             if(x%2!=0)
              {placeOutPiece1[s][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece1[s][1]=inputArr[2]-62;
              }
              else if(x%2==0)
              {
                 placeOutPiece2[m][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece2[m][1]=inputArr[2]-62;
              }
             a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
             a[57-inputArr[1]][(inputArr[0]-62)]=' ';
             kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;
             }}
            return 0;
            }
        }
    }
else if(kesh==0)
{  temporary=0;
    int t;
    kesh=1;
    t=checkKnights(a,inputArr,x);
    kesh=0;
    if(t==0)
    {
        if(57-inputArr[3]==ArrKesh[0]&&inputArr[2]-62==ArrKesh[1])
        {
            kesh=1;
            temporary=1;
            checkKnights(a,inputArr,x);
            return 0;
        }
        else if(checkKeshPice(a,inputArr,x)==0)
        {
            kesh=1;
            temporary=1;
            checkKnights(a,inputArr,x);
            return 0;
        }
    }
}
return 1;
}
//this function check for move of rooks and return 0 if ok move.
int checkRooks(char a[][14],char inputArr[],int x)
{ if(kesh==1){
     char ArrE1[5]={'p','r','b','n','q'},ArrE2[5]={'P','R','N','Q','B'};
    //check that we move in the same row or the same column
    if(inputArr[0]==inputArr[2]||inputArr[1]==inputArr[3])
    {  char rOOt,TEMPARR[5];
      int tempVAR,columN ;
         if(x%2!=0)
        {rOOt='r';
         tempVAR=s;
         for(int i=0;i<5;i++)
         {
            TEMPARR[i]=ArrE1[i];
         }
         columN=store1;//this when i use to store delete element
        }
        else if(x%2==0)
        {
         rOOt='R';
         tempVAR=m;
         for(int i=0;i<5;i++)
         {
            TEMPARR[i]=ArrE2[i];
         }
          columN=store2; //this when i use to store delete element
        }
        if(a[57-inputArr[1]][(inputArr[0]-62)]==rOOt)
        {  //check next move is not my piece
            for(int i=0;i<5;i++)
            {
                if(a[57-inputArr[3]][(inputArr[2]-62)]==TEMPARR[i])
                 {
                     return 1;

                 }
            }
        //check if we move in column direction
          if(inputArr[0]==inputArr[2]){
           //check next move up is not exceed any piece.
           for(int i=57-inputArr[1]-1;i>57-inputArr[3];i--)
           {
               if(a[i][inputArr[0]-62]!=' ')
               {
                   return 1;
               }

           }
         //check next move down is not exceed any piece.
         for(int i=57-inputArr[1]+1;i<57-inputArr[3];i++)
           {
               if(a[i][inputArr[0]-62]!=' ')
               {
                   return 1;
               }

           }
         if(a[57-inputArr[3]][(inputArr[2]-62)]==' ')
         {  if(temporary==1){
             a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
             a[57-inputArr[1]][(inputArr[0]-62)]=' ';
             kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;
             }}
             return 0;
         }
         else if(a[57-inputArr[3]][(inputArr[2]-62)]!=' ')
         {  if(temporary==1){
             tempVAR++;/////////////////////
             if(x%2!=0){s++;}
             else if(x%2==0){m++;}
             a[tempVAR][columN]= a[57-inputArr[3]][(inputArr[2]-62)];
             if(x%2!=0)
              {placeOutPiece1[s][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece1[s][1]=inputArr[2]-62;
              }
              else if(x%2==0)
              {
                 placeOutPiece2[m][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece2[m][1]=inputArr[2]-62;
              }
             a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
             a[57-inputArr[1]][(inputArr[0]-62)]=' ';
             kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;
             }}
             return 0;
         }
        }
        // if we move in row direction
        if(inputArr[1]==inputArr[3])
        {
            //check next move right is not exceed any piece.
           for(int i=inputArr[0]-62+1;i<inputArr[2]-62;i++)
           {
               if(a[57-inputArr[1]][i]!=' ')
               {
                   return 1;
               }

           }
           //check next move left is not exceed any piece.
           for(int i=inputArr[0]-62-1;i>inputArr[2]-62;i--)
           {
               if(a[57-inputArr[1]][i]!=' ')
               {
                   return 1;

               }
           }
           //if next step is empty
           if(a[57-inputArr[3]][(inputArr[2]-62)]==' ')
         {  if(temporary==1){
             a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
             a[57-inputArr[1]][(inputArr[0]-62)]=' ';
             kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;
             }}
        return 0;
         }
         else if(a[57-inputArr[3]][(inputArr[2]-62)]!=' ')
         { if(temporary==1){
             tempVAR++;/////////////////////
             if(x%2!=0){s++;}
             else if(x%2==0){m++;}
             a[tempVAR][columN]= a[57-inputArr[3]][(inputArr[2]-62)];
             if(x%2!=0)
              {placeOutPiece1[s][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece1[s][1]=inputArr[2]-62;
              }
              else if(x%2==0)
              {
                 placeOutPiece2[m][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece2[m][1]=inputArr[2]-62;
              }
             a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
             a[57-inputArr[1]][(inputArr[0]-62)]=' ';
             kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;
             }}
             return 0;
         }

        }
        }
    }}
  else if(kesh==0)
{
     temporary=0;
    int t;
    kesh=1;
    t=checkRooks(a,inputArr,x);
    printArr(a);
    kesh=0;
    if(t==0)
    {
        if(57-inputArr[3]==ArrKesh[0]&&inputArr[2]-62==ArrKesh[1])
        {
            kesh=1;
            temporary=1;
            checkRooks(a,inputArr,x);
            return 0;
        }
        else if(checkKeshPice(a,inputArr,x)==0)
        {
            kesh=1;
            temporary=1;
            checkRooks(a,inputArr,x);
            return 0;
        }
    }
}
   return 1;
}
//this function check for bishops move
int checkBishops(char a[][14],char inputArr[],int x )
{ if(kesh==1){
  char ArrE1[5]={'p','r','b','n','q'},ArrE2[5]={'P','R','N','Q','B'};
  char rOOt,TEMPARR[5];
      int tempVAR,columN ;
         if(x%2!=0)
        {rOOt='b';
         tempVAR=s;
         for(int i=0;i<5;i++)
         {
            TEMPARR[i]=ArrE1[i];
         }
         columN=store1;//this when i use to store delete element
        }
        else if(x%2==0)
        {
         rOOt='B';
         tempVAR=m;
         for(int i=0;i<5;i++)
         {
            TEMPARR[i]=ArrE2[i];
         }
          columN=store2; //this when i use to store delete element
        }
 //check if next step is on diagonal way
 if(abs(inputArr[0]-inputArr[2])==abs(inputArr[1]-inputArr[3]))
 {

     int i;//this variable i use in my for loops later
 if(a[57-inputArr[1]][(inputArr[0]-62)]==rOOt)
{
     //check that the place i go to is not contain my piece.
     for(int i=0;i<5;i++)
     {
         if(a[57-inputArr[3]][(inputArr[2]-62)]==TEMPARR[i])
         {
             return 1;//as false
         }
     }
//check if second move is up the recent one
 if(57-inputArr[3]<57-inputArr[1])
 {
    //check if move is right.
    if(inputArr[2]-62>inputArr[0]-62)
     {  //check next step is exceed piece
         i=57-inputArr[1]-1;
         for(int j=(inputArr[0]-62+1);j<(inputArr[2]-62)&&j<=10;j++)//10 final column in actual space
     {
         if(a[i][j]!=' ')
         {
             return 1;
         }
         i--;
     }
     if(a[57-inputArr[3]][(inputArr[2]-62)]==' ')
     {  if(temporary==1){
         a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
         a[57-inputArr[1]][(inputArr[0]-62)]=' ';
          kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;}}
         return 0;

     }
     //check next step is not empty
     else if(a[57-inputArr[3]][(inputArr[2]-62)]!=' ')
     {   if(temporary==1){
         tempVAR++;
        if(x%2!=0){s++;}
        else if(x%2==0){m++;}
         a[tempVAR][columN]= a[57-inputArr[3]][(inputArr[2]-62)];
         if(x%2!=0)
              {placeOutPiece1[s][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece1[s][1]=inputArr[2]-62;
              }
              else if(x%2==0)
              {
                 placeOutPiece2[m][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece2[m][1]=inputArr[2]-62;
              }
         a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
         a[57-inputArr[1]][(inputArr[0]-62)]=' ';
         kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;}}
         return 0;
     }
     }
    //check if move is left.
    if(inputArr[2]-62<inputArr[0]-62)
    {
         //check next step is exceed piece
         i=57-inputArr[1]-1;
         for(int j=(inputArr[0]-62-1);j<(inputArr[2]-62)&&j<=3;j--)
     {
         if(a[i][j]!=' ')
         {
             return 1;
         }
         i--;
     }
     //if place i go is empty
     if(a[57-inputArr[3]][(inputArr[2]-62)]==' ')
     {  if(temporary==1){
         a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
         a[57-inputArr[1]][(inputArr[0]-62)]=' ';
         kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;}}
         return 0;

     }
     //check next step is not empty
     else if(a[57-inputArr[3]][(inputArr[2]-62)]!=' ')
     {    if(temporary==1){
         tempVAR++;
         if(x%2!=0){s++;}
         else if(x%2==0){m++;}
         a[tempVAR][columN]= a[57-inputArr[3]][(inputArr[2]-62)];
         if(x%2!=0)
              {placeOutPiece1[s][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece1[s][1]=inputArr[2]-62;
              }
              else if(x%2==0)
              {
                 placeOutPiece2[m][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece2[m][1]=inputArr[2]-62;
              }
         a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
         a[57-inputArr[1]][(inputArr[0]-62)]=' ';
         kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;}}
         return 0;

     }
    }

 }
//check if second move is down the recent one
 else if(57-inputArr[3]>57-inputArr[1])
 {
       //check if move is right.
    if(inputArr[2]-62>inputArr[0]-62)
     {  //check next step is exceed piece
         i=57-inputArr[1]+1;
         for(int j=(inputArr[0]-62+1);j<(inputArr[2]-62)&&j<=10;j++)//10 final column in actual space
     {
         if(a[i][j]!=' ')
         {
             return 1;
         }
         i++;
     }
     if(a[57-inputArr[3]][(inputArr[2]-62)]==' ')
     {  if(temporary==1){
         a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
         a[57-inputArr[1]][(inputArr[0]-62)]=' ';
         kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;}}
         return 0;
     }
     //check next step is not empty
     else if(a[57-inputArr[3]][(inputArr[2]-62)]!=' ')
     {   if(temporary==1){
         tempVAR ++;
        if(x%2!=0){s++;}
        else if(x%2==0){m++;}
         a[tempVAR][columN]= a[57-inputArr[3]][(inputArr[2]-62)];
         if(x%2!=0)
              {placeOutPiece1[s][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece1[s][1]=inputArr[2]-62;
              }
              else if(x%2==0)
              {
                 placeOutPiece2[m][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece2[m][1]=inputArr[2]-62;
              }
         a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
         a[57-inputArr[1]][(inputArr[0]-62)]=' ';
         kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;}}
        return 0;
     }

     }
    //check if move is left.
    if(inputArr[2]-62<inputArr[0]-62)
    {
         //check next step is exceed piece
         i=57-inputArr[1]+1;
         for(int j=(inputArr[0]-62-1);j<(inputArr[2]-62)&&j<=3;j--)
     {
         if(a[i][j]!=' ')
         {
             return 1;
         }
         i++;
     }
     //if place i go is empty
     if(a[57-inputArr[3]][(inputArr[2]-62)]==' ')
     {   if(temporary==1){
         a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
         a[57-inputArr[1]][(inputArr[0]-62)]=' ';
         kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;}}
         return 0;
     }
     //check next step is not empty
     else if(a[57-inputArr[3]][(inputArr[2]-62)]!=' ')
     {   if(temporary==1){
          tempVAR++;
         if(x%2!=0){s++;}
         else if(x%2==0){m++;}
         a[tempVAR][columN]= a[57-inputArr[3]][(inputArr[2]-62)];
         if(x%2!=0)
              {placeOutPiece1[s][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece1[s][1]=inputArr[2]-62;
              }
              else if(x%2==0)
              {
                 placeOutPiece2[m][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece2[m][1]=inputArr[2]-62;
              }
         a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
         a[57-inputArr[1]][(inputArr[0]-62)]=' ';
         kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;}}
         return 0;
     }
    }
 }
}
 }
}
else if(kesh==0)
{  temporary=0;
    int t;
    kesh=1;
    t=checkBishops(a,inputArr,x);
    printArr(a);
    kesh=0;
    if(t==0)
    {
        if(57-inputArr[3]==ArrKesh[0]&&inputArr[2]-62==ArrKesh[1])
        {
            kesh=1;
            temporary=1;
            checkBishops(a,inputArr,x);
            return 0;
        }
        else if(checkKeshPice(a,inputArr,x)==0)
        {
            kesh=1;
            temporary=1;
            checkBishops(a,inputArr,x);
            return 0;
        }
    }
}
 return 1;
}
//this function check for move of queen and return 0 if ok move.
int checkQueen(char a[][14],char inputArr[],int x)
{
  if(kesh==1)
  {
    char ArrE1[5]={'p','r','b','n','q'},ArrE2[5]={'P','R','N','Q','B'};
    //check if we move in diadonal way or orthogonal
   if((inputArr[0]==inputArr[2]||inputArr[1]==inputArr[3]||(abs(inputArr[0]-inputArr[2])==abs(inputArr[1]-inputArr[3]))))
   {   //if we will act as bishops.
       if((abs(inputArr[0]-inputArr[2])==abs(inputArr[1]-inputArr[3])))
       {
  char rOOt,TEMPARR[5];
      int tempVAR,columN ;
         if(x%2!=0)
        {
            rOOt='q';
         tempVAR=s;
         for(int i=0;i<5;i++)
         {
            TEMPARR[i]=ArrE1[i];
         }
         columN=store1;//this when i use to store delete element
        }
        else if(x%2==0)
        {
         rOOt='Q';
         tempVAR=m;
         for(int i=0;i<5;i++)
         {
            TEMPARR[i]=ArrE2[i];
         }
          columN=store2; //this when i use to store delete element
        }
 //check if next step is on diagonal way
 if(abs(inputArr[0]-inputArr[2])==abs(inputArr[1]-inputArr[3]))
 {
     int i;//this variable i use in my for loops later
 if(a[57-inputArr[1]][(inputArr[0]-62)]==rOOt)
{
     //check that the place i go to is not contain my piece.
     for(int i=0;i<5;i++)
     {
         if(a[57-inputArr[3]][(inputArr[2]-62)]==TEMPARR[i])
         {
             return 1;//as false
         }
     }
//check if second move is up the recent one
 if(57-inputArr[3]<57-inputArr[1])
 {
    //check if move is right.
    if(inputArr[2]-62>inputArr[0]-62)
     {  //check next step is exceed piece
         i=57-inputArr[1]-1;
         for(int j=(inputArr[0]-62+1);j<(inputArr[2]-62)&&j<=10;j++)//10 final column in actual space
     {
         if(a[i][j]!=' ')
         {
             return 1;
         }
         i--;
     }
     if(a[57-inputArr[3]][(inputArr[2]-62)]==' ')
     {   if(temporary==1){
         a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
         a[57-inputArr[1]][(inputArr[0]-62)]=' ';
          kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;}}
         return 0;

     }
     //check next step is not empty
     else if(a[57-inputArr[3]][(inputArr[2]-62)]!=' ')
     {   if(temporary==1){
         tempVAR++;
        if(x%2!=0){s++;}
        else if(x%2==0){m++;}
         a[tempVAR][columN]= a[57-inputArr[3]][(inputArr[2]-62)];
         if(x%2!=0)
              {placeOutPiece1[s][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece1[s][1]=inputArr[2]-62;
              }
              else if(x%2==0)
              {
                 placeOutPiece2[m][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece2[m][1]=inputArr[2]-62;
              }
         a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
         a[57-inputArr[1]][(inputArr[0]-62)]=' ';
         kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;}}
         return 0;
     }
     }
    //check if move is left.
    if(inputArr[2]-62<inputArr[0]-62)
    {
         //check next step is exceed piece
         i=57-inputArr[1]-1;
         for(int j=(inputArr[0]-62-1);j<(inputArr[2]-62)&&j<=3;j--)
     {
         if(a[i][j]!=' ')
         {
             return 1;
         }
         i--;
     }
     //if place i go is empty
     if(a[57-inputArr[3]][(inputArr[2]-62)]==' ')
     {  if(temporary==1){
         a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
         a[57-inputArr[1]][(inputArr[0]-62)]=' ';
         kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;}}
         return 0;

     }
     //check next step is not empty
     else if(a[57-inputArr[3]][(inputArr[2]-62)]!=' ')
     {   if(temporary==1){
          tempVAR++;
         if(x%2!=0){s++;}
         else if(x%2==0){m++;}
         a[tempVAR][columN]= a[57-inputArr[3]][(inputArr[2]-62)];
         if(x%2!=0)
              {placeOutPiece1[s][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece1[s][1]=inputArr[2]-62;
              }
              else if(x%2==0)
              {
                 placeOutPiece2[m][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece2[m][1]=inputArr[2]-62;
              }
         a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
         a[57-inputArr[1]][(inputArr[0]-62)]=' ';
         kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;}}
         return 0;

     }
    }

 }
//check if second move is down the recent one
 else if(57-inputArr[3]>57-inputArr[1])
 {
       //check if move is right.
    if(inputArr[2]-62>inputArr[0]-62)
     {  //check next step is exceed piece
         i=57-inputArr[1]+1;
         for(int j=(inputArr[0]-62+1);j<(inputArr[2]-62)&&j<=10;j++)//10 final column in actual space
     {
         if(a[i][j]!=' ')
         {
             return 1;
         }
         i++;
     }
     if(a[57-inputArr[3]][(inputArr[2]-62)]==' ')
     {   if(temporary==1){
         a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
         a[57-inputArr[1]][(inputArr[0]-62)]=' ';
         kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;}}
         return 0;
     }
     //check next step is not empty
     else if(a[57-inputArr[3]][(inputArr[2]-62)]!=' ')
     {  if(temporary==1){
          tempVAR ++;
        if(x%2!=0){s++;}
        else if(x%2==0){m++;}
         a[tempVAR][columN]= a[57-inputArr[3]][(inputArr[2]-62)];
         if(x%2!=0)
              {placeOutPiece1[s][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece1[s][1]=inputArr[2]-62;
              }
              else if(x%2==0)
              {
                 placeOutPiece2[m][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece2[m][1]=inputArr[2]-62;
              }
         a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
         a[57-inputArr[1]][(inputArr[0]-62)]=' ';
         kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;}}
        return 0;
     }

     }
    //check if move is left.
    if(inputArr[2]-62<inputArr[0]-62)
    {
         //check next step is exceed piece
         i=57-inputArr[1]+1;
         for(int j=(inputArr[0]-62-1);j<(inputArr[2]-62)&&j<=3;j--)
     {
         if(a[i][j]!=' ')
         {
             return 1;
         }
         i++;
     }
     //if place i go is empty
     if(a[57-inputArr[3]][(inputArr[2]-62)]==' ')
     {   if(temporary==1){
         a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
         a[57-inputArr[1]][(inputArr[0]-62)]=' ';
         kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;}}
         return 0;
     }
     //check next step is not empty
     else if(a[57-inputArr[3]][(inputArr[2]-62)]!=' ')
     {    if(temporary==1){
         tempVAR++;
         if(x%2!=0){s++;}
         else if(x%2==0){m++;}
         a[tempVAR][columN]= a[57-inputArr[3]][(inputArr[2]-62)];
         if(x%2!=0)
              {placeOutPiece1[s][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece1[s][1]=inputArr[2]-62;
              }
              else if(x%2==0)
              {
                 placeOutPiece2[m][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece2[m][1]=inputArr[2]-62;
              }
         a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
         a[57-inputArr[1]][(inputArr[0]-62)]=' ';
         kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;}}
         return 0;
     }
    }
 }
}
 }
         }
         //if we act as rook
    else if(inputArr[0]==inputArr[2]||inputArr[1]==inputArr[3])
    {

       //check that we move in the same row or the same column
    if(inputArr[0]==inputArr[2]||inputArr[1]==inputArr[3])
    {  char rOOt,TEMPARR[5];
      int tempVAR,columN ;
         if(x%2!=0)
        {rOOt='q';
         tempVAR=s;
         for(int i=0;i<5;i++)
         {
            TEMPARR[i]=ArrE1[i];
         }
         columN=store1;//this when i use to store delete element
        }
        else if(x%2==0)
        {
         rOOt='Q';
         tempVAR=m;
         for(int i=0;i<5;i++)
         {
            TEMPARR[i]=ArrE2[i];
         }
          columN=store2; //this when i use to store delete element
        }
        if(a[57-inputArr[1]][(inputArr[0]-62)]==rOOt)
        {  //check next move is not my piece
            for(int i=0;i<5;i++)
            {
                if(a[57-inputArr[3]][(inputArr[2]-62)]==TEMPARR[i])
                 {
                     return 1;

                 }
            }
        //check if we move in column direction
          if(inputArr[0]==inputArr[2]){
           //check next move up is not exceed any piece.
           for(int i=57-inputArr[1]-1;i>57-inputArr[3];i--)
           {
               if(a[i][inputArr[0]-62]!=' ')
               {
                   return 1;
               }

           }
         //check next move down is not exceed any piece.
         for(int i=57-inputArr[1]+1;i<57-inputArr[3];i++)
           {
               if(a[i][inputArr[0]-62]!=' ')
               {
                   return 1;
               }

           }
         if(a[57-inputArr[3]][(inputArr[2]-62)]==' ')
         {   if(temporary==1){
             a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
             a[57-inputArr[1]][(inputArr[0]-62)]=' ';
             kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;
             }}
             return 0;
         }
         else if(a[57-inputArr[3]][(inputArr[2]-62)]!=' ')
         { if(temporary==1){
             tempVAR++;/////////////////////
             if(x%2!=0){s++;}
             else if(x%2==0){m++;}
             a[tempVAR][columN]= a[57-inputArr[3]][(inputArr[2]-62)];
             if(x%2!=0)
              {placeOutPiece1[s][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece1[s][1]=inputArr[2]-62;
              }
              else if(x%2==0)
              {
                 placeOutPiece2[m][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece2[m][1]=inputArr[2]-62;
              }
             a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
             a[57-inputArr[1]][(inputArr[0]-62)]=' ';
             kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;
             }}
             return 0;
         }
        }
        // if we move in row direction
        if(inputArr[1]==inputArr[3])
        {
            //check next move right is not exceed any piece.
           for(int i=inputArr[0]-62+1;i<inputArr[2]-62;i++)
           {
               if(a[57-inputArr[1]][i]!=' ')
               {
                   return 1;
               }

           }
           //check next move left is not exceed any piece.
           for(int i=inputArr[0]-62-1;i>inputArr[2]-62;i--)
           {
               if(a[57-inputArr[1]][i]!=' ')
               {
                   return 1;

               }
           }
           //if next step is empty
           if(a[57-inputArr[3]][(inputArr[2]-62)]==' ')
         {   if(temporary==1){
             a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
             a[57-inputArr[1]][(inputArr[0]-62)]=' ';
             kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;
             }}
        return 0;
         }
         else if(a[57-inputArr[3]][(inputArr[2]-62)]!=' ')
         { if(temporary==1){
             tempVAR++;/////////////////////
             if(x%2!=0){s++;}
             else if(x%2==0){m++;}
             a[tempVAR][columN]= a[57-inputArr[3]][(inputArr[2]-62)];
             if(x%2!=0)
              {placeOutPiece1[s][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece1[s][1]=inputArr[2]-62;
              }
              else if(x%2==0)
              {
                 placeOutPiece2[m][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece2[m][1]=inputArr[2]-62;
              }
             a[57-inputArr[3]][(inputArr[2]-62)]=a[57-inputArr[1]][(inputArr[0]-62)];
             a[57-inputArr[1]][(inputArr[0]-62)]=' ';
             kesh=checkKesh(a,inputArr,x);////////////////
             if(kesh==0)
             {
              ArrKesh[0]=57-inputArr[3];// here i store the rook place which is in check
              ArrKesh[1]=inputArr[2]-62;
             }}
             return 0;
         }

        }
        }
    }
    }

   }
}
else if(kesh==0)
{  temporary=0;
    int t;
    kesh=1;
    t=checkQueen(a,inputArr,x);
    printArr(a);
    kesh=0;
    if(t==0)
    {
        if(57-inputArr[3]==ArrKesh[0]&&inputArr[2]-62==ArrKesh[1])
        {
            kesh=1;
            temporary=1;
            checkQueen(a,inputArr,x);
            return 0;
        }
        else if(checkKeshPice(a,inputArr,x)==0)
        {
            kesh=1;
            temporary=1;
            checkQueen(a,inputArr,x);
            return 0;
        }
    }
}
return 1;
}

//this function check for kings move.it take array of elements and user array and x indicates who played play now
int checkKing(char a[][14],char inputArr[],int x )
{
    //declaring two arrays of elements of player 1 and 2
  char ArrE1[5]={'p','r','b','n','q'},ArrE2[5]={'P','R','N','Q','B'},arrE3[3]={'R','Q','B'},arrE4[3]={'r','q','b'};
  //check input data is correct motion like E8E7
  if(((inputArr[1]=='1'&&a[57-inputArr[1]][inputArr[0]-62]=='k'&&(x%2!=0))&&(inputArr[2]>inputArr[0]-2&&inputArr[2]<inputArr[0]+2)&&(inputArr[3]>'0'&&inputArr[3]<inputArr[1]+2))
     ||((inputArr[1]>'1'&&(x%2!=0))&&a[57-inputArr[1]][inputArr[0]-62]=='k'&&(inputArr[2]>inputArr[0]-2&&inputArr[2]<inputArr[0]+2)&&(inputArr[3]>inputArr[1]-2&&inputArr[3]<inputArr[1]+2))
     ||(((inputArr[1]=='8'&&(x%2==0))&&a[57-inputArr[1]][inputArr[0]-62]=='K'&&((inputArr[2]>(inputArr[0]-2))&&(inputArr[2]<(inputArr[0]+2)))&&(inputArr[3]<'9'&&inputArr[3]>inputArr[1]-2)))//first motion of row of kink
     ||(((inputArr[1]<'8'&&(x%2==0))&&inputArr[3]!='0'&&a[57-inputArr[1]][inputArr[0]-62]=='K'&&(inputArr[2]>inputArr[0]-2&&inputArr[2]<inputArr[0]+2)&&(inputArr[3]>inputArr[1]-2&&inputArr[3]<inputArr[1]+2)))){


    if(x%2!=0)//first player
   {
     //check safe for enemies pawns
     if(a[57-inputArr[3]-1][inputArr[2]-62+1]=='P'||a[57-inputArr[3]-1][inputArr[2]-62-1]=='P'||a[57-inputArr[3]+1][inputArr[2]-62+1]=='P'
        ||a[57-inputArr[3]+1][inputArr[2]-62-1]=='P')
     {
         return 1;
     }
    for(int j=0;j<2;j++) //in this i check for both rooks and king
     {//check for right rooks
     for(int i=1;i<=(10-(inputArr[2]-62));i++)//here we limit right moves
      {
          if(a[57-inputArr[3]][inputArr[2]-62+i]==arrE3[j])
          {
              return 1;
          }
          else if(a[57-inputArr[3]][inputArr[2]-62+i]!=' '&&a[57-inputArr[3]][inputArr[2]-62+i]!='k')
          {
              break;
          }
      }
      //check for left rooks
     for(int i=1;i<=(inputArr[2]-62-3);i++)//i made it 2 to neglect previos king//////////
      {
          if(a[57-inputArr[3]][inputArr[2]-62-i]==arrE3[j])
          {
              return 1;
          }
          else if(a[57-inputArr[3]][inputArr[2]-62-i]!=' '&&a[57-inputArr[3]][inputArr[2]-62-i]!='k')
          {
              break;
          }
      }
      //check for top rooks
     for(int i=1;i<=(57-inputArr[3]-1);i++)
      {
          if(a[57-inputArr[3]-i][inputArr[2]-62]==arrE3[j])
          {
             return 1;
          }
          else if(a[57-inputArr[3]-i][inputArr[2]-62]!=' '&&a[57-inputArr[3]-i][inputArr[2]-62]!='k')
          {
              break;
          }
      }
      //check for down rook
     for(int i=1;i<=(8-(57-inputArr[3]));i++)
      {
          if(a[57-inputArr[3]+i][inputArr[2]-62]==arrE3[j])
          {
              return 1;
          }
          else if(a[57-inputArr[3]+i][inputArr[2]-62+i]!=' '&&a[57-inputArr[3]+i][inputArr[2]-62+i]!='k')
          {
              break;
          }
      }}
     //check for both queen and bishops
     for(int j=1;j<3;j++)
     {  //check for right top bishops
         for(int i=1;i<=(57-inputArr[3]-1);i++)//i limit the i so that i do not reach to first raw
      {
          if(a[57-inputArr[3]-i][inputArr[2]-62+i]==arrE3[j])//////////////////
          {
              return 1;
          }
          else if(a[57-inputArr[3]-i][inputArr[2]-62+i]!=' '&&a[57-inputArr[3]-i][inputArr[2]-62+i]!='k')//here i add king because i want to miss previous king
          {
              break;
          }
      }
      //check for left top bishops
     for(int i=1;i<=(57-inputArr[3]-1);i++)//i limit the i so that i do not reach to first raw
      {   //printf("%c",a[57-inputArr[3]-i][inputArr[2]-62-i]);
          if(a[57-inputArr[3]-i][inputArr[2]-62-i]==arrE3[j])
          {
              return 1;
          }
          else if(a[57-inputArr[3]-i][inputArr[2]-62-i]!=' '&&a[57-inputArr[3]-i][inputArr[2]-62-i]!='k')//here i add king because i want to miss previous king
          {
              break;
          }
      }
      //check for right down bishops
     for(int i=1;i<=(8-(57-inputArr[3]));i++)
      {
          if(a[57-inputArr[3]+i][inputArr[2]-62+i]==arrE3[j])
          {
              return 1;
          }
          else if(a[57-inputArr[3]+i][inputArr[2]-62+i]!=' '&&a[57-inputArr[3]+i][inputArr[2]-62+i]!='k')
          {
              break;
          }
      }
      //check for left down bishops
     for(int i=1;i<=(8-(57-inputArr[3]));i++)
      {
          if(a[57-inputArr[3]+i][inputArr[2]-62-i]==arrE3[j])
          {
              return 1;
          }
          else if(a[57-inputArr[3]+i][inputArr[2]-62-i]!=' '&&a[57-inputArr[3]+i][inputArr[2]-62-i]!='k')
          {
              break;
          }
      }}
     //check for hourse
     if(a[57-inputArr[3]+2][inputArr[2]-62+1]=='N'||a[57-inputArr[3]+2][inputArr[2]-62-1]=='N'||a[57-inputArr[3]-2][inputArr[2]-62-1]=='N'
        ||a[57-inputArr[3]-2][inputArr[2]-62+1]=='N'||a[57-inputArr[3]+1][inputArr[2]-62+2]=='N'||a[57-inputArr[3]+1][inputArr[2]-62-2]=='N'
        ||a[57-inputArr[3]-1][inputArr[2]-62-2]=='N'||a[57-inputArr[3]-1][inputArr[2]-62+2]=='N')
     {
         return 1;
     }
       for(int i=0;i<5;i++)  //check next step is not on my piece
       {
           if(ArrE1[i]==a[57-inputArr[3]][inputArr[2]-62])
           {
              return 1;
           }
       }
    if(a[57-inputArr[3]][inputArr[2]-62]==' ') //check if next step is empty
   {   if(temporary==1){
       a[57-inputArr[3]][inputArr[2]-62]=a[57-inputArr[1]][inputArr[0]-62];
       a[57-inputArr[1]][inputArr[0]-62]=' ';
        ArrKing[0]=57-inputArr[3];
        ArrKing[1]=inputArr[2]-62;
       }
       kesh=1;
       return 0;
   }
   else if(a[57-inputArr[3]][inputArr[2]-62]!=' ')//check if next step have element from another player
   {
      if(temporary==1){ s++;
        a[s][store1]= a[57-inputArr[3]][inputArr[2]-62];
              placeOutPiece1[s][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece1[s][1]=inputArr[2]-62;

        a[57-inputArr[3]][inputArr[2]-62]=a[57-inputArr[1]][inputArr[0]-62];
        a[57-inputArr[1]][inputArr[0]-62]=' ';
        ArrKing[0]=57-inputArr[3];
        ArrKing[1]=inputArr[2]-62;
        }
        kesh=1;
        return 0;
   }
   }
    if(x%2==0)//first player
   {

     //check safe for enemies pawns
     if(a[57-inputArr[3]-1][inputArr[2]-62+1]=='p'||a[57-inputArr[3]-1][inputArr[2]-62-1]=='p'||a[57-inputArr[3]+1][inputArr[2]-62+1]=='p'
        ||a[57-inputArr[3]+1][inputArr[2]-62-1]=='p')
     {
         return 1;
     }
       for(int j=0;j<2;j++) //in this i check for both rooks and king
     {//check for right rooks
     for(int i=1;i<=(10-(inputArr[2]-62));i++)//here we limit right moves
      {
          if(a[57-inputArr[3]][inputArr[2]-62+i]==arrE4[j])
          {
              return 1;
          }
          else if(a[57-inputArr[3]][inputArr[2]-62+i]!=' '&&a[57-inputArr[3]][inputArr[2]-62+i]!='K')
          {
              break;
          }
      }
      //check for left rooks
     for(int i=1;i<=(inputArr[2]-62-3);i++)//i made it 2 to neglect previos king//////////
      {
          if(a[57-inputArr[3]][inputArr[2]-62-i]==arrE4[j])
          {
              return 1;
          }
          else if(a[57-inputArr[3]][inputArr[2]-62-i]!=' '&&a[57-inputArr[3]][inputArr[2]-62-i]!='K')
          {
              break;
          }
      }
      //check for top rooks
     for(int i=1;i<=(57-inputArr[3]-1);i++)
      {
          if(a[57-inputArr[3]-i][inputArr[2]-62]==arrE4[j])
          {
             return 1;
          }
          else if(a[57-inputArr[3]-i][inputArr[2]-62]!=' '&&a[57-inputArr[3]-i][inputArr[2]-62]!='K')
          {
              break;
          }
      }
      //check for down rook
     for(int i=1;i<=(8-(57-inputArr[3]));i++)
      {
          if(a[57-inputArr[3]+i][inputArr[2]-62]==arrE4[j])
          {
              return 1;
          }
          else if(a[57-inputArr[3]+i][inputArr[2]-62+i]!=' '&&a[57-inputArr[3]+i][inputArr[2]-62+i]!='K')
          {
              break;
          }
      }}
     //check for both queen and bishops
     for(int j=1;j<3;j++)
     {  //check for right top bishops
         for(int i=1;i<=(57-inputArr[3]-1);i++)
      {
          if(a[57-inputArr[3]-i][inputArr[2]-62+i]==arrE4[j])
          {
              return 1;
          }
          else if(a[57-inputArr[3]-i][inputArr[2]-62+i]!=' '&&a[57-inputArr[3]-i][inputArr[2]-62+i]!='K')
          {
              break;
          }
      }
      //check for left top bishops
     for(int i=1;i<=(57-inputArr[3]-1);i++)
      {
          if(a[57-inputArr[3]-i][inputArr[2]-62-i]==arrE4[j])
          {
              return 1;
          }
          else if(a[57-inputArr[3]-i][inputArr[2]-62-i]!=' '&&a[57-inputArr[3]-i][inputArr[2]-62-i]!='K')
          {
              break;
          }
      }
      //check for right down bishops
     for(int i=1;i<=(8-(57-inputArr[3]));i++)
      {
          if(a[57-inputArr[3]+i][inputArr[2]-62+i]==arrE4[j])
          {
              return 1;
          }
          else if(a[57-inputArr[3]+i][inputArr[2]-62+i]!=' '&&a[57-inputArr[3]+i][inputArr[2]-62+i]!='K')
          {
              break;
          }
      }
      //check for left down bishops
     for(int i=1;i<=(8-(57-inputArr[3]));i++)
      {
          if(a[57-inputArr[3]+i][inputArr[2]-62-i]==arrE4[j])
          {
              return 1;
          }
          else if(a[57-inputArr[3]+i][inputArr[2]-62-i]!=' '&&a[57-inputArr[3]+i][inputArr[2]-62-i]!='K')
          {
              break;
          }
      }}
     //check for horse we check all places of hourses
     if(a[57-inputArr[3]+2][inputArr[2]-62+1]=='n'||a[57-inputArr[3]+2][inputArr[2]-62-1]=='n'||a[57-inputArr[3]-2][inputArr[2]-62-1]=='n'
        ||a[57-inputArr[3]-2][inputArr[2]-62+1]=='n'||a[57-inputArr[3]+1][inputArr[2]-62+2]=='n'||a[57-inputArr[3]+1][inputArr[2]-62-2]=='n'
        ||a[57-inputArr[3]-1][inputArr[2]-62-2]=='n'||a[57-inputArr[3]-1][inputArr[2]-62+2]=='n')
     {
         return 1;
     }

       for(int i=0;i<5;i++)  //check next step is not on my piece
       {
           if(ArrE2[i]==a[57-inputArr[3]][inputArr[2]-62])
           {
               return 1;
           }
       }
        //check next step in not empty and has another player piece

    if(a[57-inputArr[3]][inputArr[2]-62]==' ') //check if next step is empty
   {  if(temporary==1){
       a[57-inputArr[3]][inputArr[2]-62]=a[57-inputArr[1]][inputArr[0]-62];
       a[57-inputArr[1]][inputArr[0]-62]=' ';
        ArrKing[2]=57-inputArr[3];
        ArrKing[3]=inputArr[2]-62;
       }
       kesh=1;
      return 0;
   }
   //check next step in not empty and has another player piece
   else if(a[57-inputArr[3]][inputArr[2]-62]!=' ')
   {   if(temporary==1){
         m++;
        a[m][store2]= a[57-inputArr[3]][inputArr[2]-62];

                 placeOutPiece2[m][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece2[m][1]=inputArr[2]-62;
        a[57-inputArr[3]][inputArr[2]-62]=a[57-inputArr[1]][inputArr[0]-62];
        a[57-inputArr[1]][inputArr[0]-62]=' ';
        ArrKing[2]=57-inputArr[3];
        ArrKing[3]=inputArr[2]-62;
        }
        kesh=1;
        return 0;
   }
   }
     }
     return 1;
}

//this function check for pawns move take array of elements and user array and x indicates who played play now
int checkPawns(char a[][14],char inputArr[],int x)
{
//this wrong and we want to replace it
 if(kesh==1){
/*here i turned indexes like A2 to index like a[7][3] and A3 like a[6][3]
three indicates column 3 in array that represents A i do tha by subtracta[57-'3']['A'-62]*/
//this function check if we move pawns from player 1 forward with 2 squares
    if(x%2!=0&&(inputArr[0]==inputArr[2])&&inputArr[1]=='2'&&(inputArr[1]==inputArr[3]-2)&&(a[57-inputArr[3]][inputArr[2]-62]=' ')&&inputArr[4]=='\n')
    {
          a[57-inputArr[3]][inputArr[2]-62]=a[57-inputArr[1]][inputArr[0]-62];
          a[57-inputArr[1]][inputArr[0]-62]=' ';
        return 0;
    }
//this function check if we move pawns from player 2 forward with 2 squares
    else if(x%2==0&&inputArr[1]=='7'&&(inputArr[0]==inputArr[2])&&(inputArr[3]==inputArr[1]-2)&&(a[57-inputArr[3]][inputArr[2]-62]==' ')&&inputArr[4]=='\n')
    {
        a[57-inputArr[3]][inputArr[2]-62]=a[57-inputArr[1]][inputArr[0]-62];
        a[57-inputArr[1]][inputArr[0]-62]=' ';
        return 0;
    }
//this function when we move forward at square 8 with player 1 highest rank
    else if(x%2!=0&&(inputArr[0]==inputArr[2])&&(inputArr[1]==inputArr[3]-1)&&(a[57-inputArr[3]][inputArr[2]-62]==' ')&&inputArr[4]!='\n')

    {
        a[57-inputArr[3]][inputArr[2]-62]=inputArr[4];
        a[57-inputArr[1]][inputArr[0]-62]=' ';
        return 0;
    }
//this function when we move forward at square 2 highest rank
      else if(x%2==0&&(inputArr[0]==inputArr[2])&&(inputArr[3]==inputArr[1]-1)&&(a[57-inputArr[3]][inputArr[2]-62]==' ')&&inputArr[4]!='\n')

    {
        a[57-inputArr[3]][inputArr[2]-62]=inputArr[4];
        a[57-inputArr[1]][inputArr[0]-62]=' ';
        return 0;
    }

//this function check if we move pawns from player 1 forward with 1 squares

    else if(x%2!=0&&(inputArr[1]!='7')&&(inputArr[0]==inputArr[2])&&(inputArr[1]==inputArr[3]-1)&&(a[57-inputArr[3]][inputArr[2]-62]==' ')&&inputArr[4]=='\n')
    {
        a[57-inputArr[3]][inputArr[2]-62]=a[57-inputArr[1]][inputArr[0]-62];
        a[57-inputArr[1]][inputArr[0]-62]=' ';
        if((a[57-inputArr[3]-1][inputArr[2]-62+1]=='K'))//check if kesh for king
        {
            kesh=0;
            ArrKesh[0]=57-inputArr[3];//////////////////
            ArrKesh[1]=inputArr[2]-62;
            ArrKesh[2]=57-inputArr[3]-1; //
            ArrKesh[3]=inputArr[2]-62+1;

        }
        else if((a[57-inputArr[3]-1][inputArr[2]-62-1]=='K'))
        {
            kesh=0;
            ArrKesh[0]=57-inputArr[3];//i store the places of king and check piece
            ArrKesh[1]=inputArr[2]-62;
            ArrKesh[2]=57-inputArr[3]-1; //
            ArrKesh[3]=inputArr[2]-62-1;
        }
        return 0;
    }
//this function check if we move pawns from player 2 forward with 1 squares
    else if(x%2==0&&(inputArr[1]!='2')&&(inputArr[0]==inputArr[2])&&(inputArr[3]==inputArr[1]-1)&&(a[57-inputArr[3]][inputArr[2]-62]==' ')&&inputArr[4]=='\n')
    {
        a[57-inputArr[3]][inputArr[2]-62]=a[57-inputArr[1]][inputArr[0]-62];
        a[57-inputArr[1]][inputArr[0]-62]=' ';
        if((a[57-inputArr[3]+1][inputArr[2]-62+1]=='k'))//check if kesh for king with player 1
        {
            kesh=0;
            ArrKesh[0]=57-inputArr[3];//////////////////
            ArrKesh[1]=inputArr[2]-62;
            ArrKesh[2]=57-inputArr[3]+1; //
            ArrKesh[3]=inputArr[2]-62+1;
        }
        else if((a[57-inputArr[3]+1][inputArr[2]-62-1]=='k'))
        {
             kesh=0;
            ArrKesh[0]=57-inputArr[3];//////////////////
            ArrKesh[1]=inputArr[2]-62;
            ArrKesh[2]=57-inputArr[3]+1; //
            ArrKesh[3]=inputArr[2]-62-1;
        }
        return 0;
    }

//this function check for diagonal move of player 1
    else if(x%2!=0&&(inputArr[1]==inputArr[3]-1)&&isupper(a[57-inputArr[3]][inputArr[2]-62])&&abs(inputArr[0]-inputArr[2])==1)
    {
        s++;//global variable
         a[s][store1]=a[57-inputArr[3]][inputArr[2]-62];
              placeOutPiece1[s][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece1[s][1]=inputArr[2]-62;

        a[57-inputArr[3]][inputArr[2]-62]=a[57-inputArr[1]][inputArr[0]-62];
        a[57-inputArr[1]][inputArr[0]-62]=' ';
         if((a[57-inputArr[3]-1][inputArr[2]-62+1]=='K'))//check if kesh for king
        {
            kesh=0;
            ArrKesh[0]=57-inputArr[3];//////////////////
            ArrKesh[1]=inputArr[2]-62;
            ArrKesh[2]=57-inputArr[3]-1; //
            ArrKesh[3]=inputArr[2]-62+1;

        }
        else if((a[57-inputArr[3]-1][inputArr[2]-62-1]=='K'))
        {
             kesh=0;
            ArrKesh[0]=57-inputArr[3];//////////////////
            ArrKesh[1]=inputArr[2]-62;
            ArrKesh[2]=57-inputArr[3]-1; //
            ArrKesh[3]=inputArr[2]-62-1;
        }
        return 0;
    }
//this function check for diagonal move of player 2
    else if(x%2==0&&(inputArr[3]==inputArr[1]-1)&&islower(a[57-inputArr[3]][inputArr[2]-62])&&abs(inputArr[0]-inputArr[2])==1)
    {    m++;//global variable
         a[m][store2]=a[57-inputArr[3]][inputArr[2]-62]; //add piece taken by player 2 in empty places in array
                 placeOutPiece2[m][0]=57-inputArr[3];//here i store place of removed piece
               placeOutPiece2[m][1]=inputArr[2]-62;

        a[57-inputArr[3]][inputArr[2]-62]=a[57-inputArr[1]][inputArr[0]-62];
        a[57-inputArr[1]][inputArr[0]-62]=' ';
        if((a[57-inputArr[3]+1][inputArr[2]-62+1]=='k'))//check if kesh for king with player 1
        {
            kesh=0;
            ArrKesh[0]=57-inputArr[3];
            ArrKesh[1]=inputArr[2]-62;
            ArrKesh[2]=57-inputArr[3]+1; //
            ArrKesh[3]=inputArr[2]-62+1;
        }
        else if((a[57-inputArr[3]+1][inputArr[2]-62-1]=='k'))
        {
            kesh=0;
            ArrKesh[0]=57-inputArr[3];//////////////////
            ArrKesh[1]=inputArr[2]-62;
            ArrKesh[2]=57-inputArr[3]+1; //
            ArrKesh[3]=inputArr[2]-62-1;
        }
        return 0;
    }
 }
 else if(kesh==0)
 {
     int t;
     kesh=1;
     t=checkPawns( a,inputArr,x);
     kesh=0;
     if(t==0)
     {
         if(57-inputArr[3]==ArrKesh[0]&&inputArr[2]-62==ArrKesh[1])//check if next move kill kesh enemy
         {
             kesh=1;
             return 0;
         }
        else if(checkKeshPice(a,inputArr,x)==0)
        {
            kesh=1;
            return 0;
        }
     }
 }
    return 1;
}



//this function check if input is valid in Array
int checkinArr(char a[][14],char inputArr[],int x)//since x shows us who player played 1 or 2
{ int check=1;
    if(x%2!=0)//in this case player 1 played has bottom pieces
     {
         switch(a[57-inputArr[1]][inputArr[0]-62])//i compare first user input character like A2 is pawns
         {
         case 'p':
             check=checkPawns(a,inputArr,x);//if first 2 characters in user input are represents pawns
             break;
         case 'r':
             check=checkRooks(a,inputArr,x);//if first 2 characters in user input are represents rooks
             break;
         case 'n':
             check=checkKnights(a,inputArr,x);//if first 2 characters in user input are represents knight
             break;
         case 'b':
             check=checkBishops(a,inputArr,x);//if first 2 characters in user input are represents bishop
             break;
         case 'k':
             check=checkKing(a,inputArr,x);//if first 2 characters in user input are represents king
             break;
         case 'q':
             check=checkQueen(a,inputArr,x);//if first 2 characters in user input are represents queen
             break;
         }
     }
     else //if player 2 played who has top pieces
     {
        switch(a[57-inputArr[1]][inputArr[0]-62])
         {
         case 'P':
             check=checkPawns(a,inputArr,x);//if first 2 characters in user input are represents pawns
             break;
         case 'R':
             check=checkRooks(a,inputArr,x);//if first 2 characters in user input are represents rooks
             break;
         case 'N':
             check=checkKnights(a,inputArr,x);//if first 2 characters in user input are represents knight
             break;
         case 'B':
             check=checkBishops(a,inputArr,x);//if first 2 characters in user input are represents bishop
             break;
         case 'K':
             check=checkKing(a,inputArr,x);//if first 2 characters in user input are represents king
             break;
         case 'Q':
             check=checkQueen(a,inputArr,x);//if first 2 characters in user input are represents queen
             break;
         }
     }
     return check;
}
//this function check if the write input is valid according to writing for example aabb is wrong writing
int checkWrite(char inputArr[],char a[][14],int x)
{  int check=1;//as false number
    if((inputArr[1]>48&&inputArr[1]<57)&&(inputArr[3]>48&&inputArr[3]<57)&&(inputArr[0]>64&&inputArr[0]<73)&&(inputArr[2]>64&&inputArr[2]<73))
       {
           if(x%2!=0&&((inputArr[4]=='b'||inputArr[4]=='n'||inputArr[4]=='q'||inputArr[4]=='r')&&inputArr[3]=='8'&&
          a[57-inputArr[1]][inputArr[0]-62]=='p'))
           {check=0;}   //as true number.
           else if(x%2==0&&((inputArr[4]=='B'||inputArr[4]=='N'||inputArr[4]=='Q'||inputArr[4]=='R')&&inputArr[3]=='1'&&
          a[57-inputArr[1]][inputArr[0]-62]=='P'))
           {
               check=0;
           }
           if(inputArr[4]=='\n')
           {
               check=0;
           }

       }
    return check;
}

//this function check for check mate when kesh
int checkInKeshCase(char a[][14],char inputArr[],int x)
{ int terminal=0,count=0,TempARR[2];
  temporary=0;//this i used to not change in the array
  inputArr[5]='\0';
  if(kesh==0)
  {
      if(x%2!=0){
    TempARR[0]=ArrKing[0];//as row
    TempARR[1]=ArrKing[1]; //as column
    //printf("%d %d",TempARR[0],TempARR[1]);
    }
    else{
    TempARR[0]=ArrKing[2];//as row
    TempARR[1]=ArrKing[3]; //as column
    }

  }
  else if(kesh!=0&&x%2!=0)
  {
    TempARR[0]=ArrKing[0];//as row
    TempARR[1]=ArrKing[1]; //as column
  }
  else if(kesh!=0&&x%2==0)
  {
    TempARR[0]=ArrKing[2];//as row
    TempARR[1]=ArrKing[3]; //as column
  }
    while(terminal<8)
    { if(terminal==0)
       {
           inputArr[0]='A'+(TempARR[1]-3); //here i convert row and column like 8,7 to '1','E'
           inputArr[1]='1'+(8-TempARR[0]);
           inputArr[2]='A'+(TempARR[1]-3);
           inputArr[3]='1'+(8-TempARR[0])+1;
       }
       if(terminal==1)
       {
            inputArr[0]='A'+(TempARR[1]-3); //here i convert row and column like 8,7 to '1','E'
           inputArr[1]='1'+(8-TempARR[0]);
           inputArr[2]='A'+(TempARR[1]-3);
           inputArr[3]='1'+(8-TempARR[0])-1;
       }
       if(terminal==2)
       {
           inputArr[0]='A'+(TempARR[1]-3); //here i convert row and column like 8,7 to '1','E'
           inputArr[1]='1'+(8-TempARR[0]);
           inputArr[2]='A'+(TempARR[1]-3)-1;
           inputArr[3]='1'+(8-TempARR[0]);
       }
       if(terminal==3)
       {
             inputArr[0]='A'+(TempARR[1]-3); //here i convert row and column like 8,7 to '1','E'
           inputArr[1]='1'+(8-TempARR[0]);
           inputArr[2]='A'+(TempARR[1]-3)+1;
           inputArr[3]='1'+(8-TempARR[0]);
       }
       if(terminal==4)
       {
           inputArr[0]='A'+(TempARR[1]-3); //here i convert row and column like 8,7 to '1','E'
           inputArr[1]='1'+(8-TempARR[0]);
           inputArr[2]='A'+(TempARR[1]-3)+1;
           inputArr[3]='1'+(8-TempARR[0])+1;

       }
       if(terminal==5)
       {
            inputArr[0]='A'+(TempARR[1]-3); //here i convert row and column like 8,7 to '1','E'
           inputArr[1]='1'+(8-TempARR[0]);
           inputArr[2]='A'+(TempARR[1]-3)+1;
           inputArr[3]='1'+(8-TempARR[0])-1;
       }
       if(terminal==6)
       {
                 inputArr[0]='A'+(TempARR[1]-3); //here i convert row and column like 8,7 to '1','E'
           inputArr[1]='1'+(8-TempARR[0]);
           inputArr[2]='A'+(TempARR[1]-3)-1;
           inputArr[3]='1'+(8-TempARR[0])+1;
       }
       if(terminal==7)
       {
             inputArr[0]='A'+(TempARR[1]-3); //here i convert row and column like 8,7 to '1','E'
           inputArr[1]='1'+(8-TempARR[0]);
           inputArr[2]='A'+(TempARR[1]-3)-1;
           inputArr[3]='1'+(8-TempARR[0])-1;
       }
        if(checkKing(a,inputArr,x)==1)
        {
            count++;
        }
        terminal++;
    }
    if(count==8)
    {
        temporary=1;
        return 0;
    }
temporary=1;
 return 1;
}
int checkStalemate(int x,char a[][14])
{
    int count=0;
    if(x%2!=0)//in this function i check if there is empty way arount king and there is only king and pawns in play
    {
        if(a[ArrKing[0]+1][ArrKing[1]]==' '||a[ArrKing[0]+1][ArrKing[1]+1]==' '||a[ArrKing[0]+1][ArrKing[1]-1]==' '||
           a[ArrKing[0]][ArrKing[1]+1]==' '||a[ArrKing[0]+1][ArrKing[1]-1]==' '||a[ArrKing[0]-1][ArrKing[1]]==' '||
           a[ArrKing[0]-1][ArrKing[1]+1]==' '||a[ArrKing[0]-1][ArrKing[1]-1]==' ')
        { for(int i=1;i<9;i++)
          {
            for(int j=12;j<14;j++)
            {
                if(a[i][j]!='q'||a[i][j]!='b'||a[i][j]!='n'||a[i][j]!='r')
                {
                    count++;
                }
            }
          }
          if(count==4)
            {return 0;}
        }
    }
    else if(x%2==0)
    {
       if(a[ArrKing[2]+1][ArrKing[3]]==' '||a[ArrKing[2]+1][ArrKing[3]+1]==' '||a[ArrKing[2]+1][ArrKing[3]-1]==' '||
           a[ArrKing[2]][ArrKing[3]+1]==' '||a[ArrKing[2]+1][ArrKing[3]-1]==' '||a[ArrKing[2]-1][ArrKing[3]]==' '||
           a[ArrKing[2]-1][ArrKing[3]+1]==' '||a[ArrKing[2]-1][ArrKing[3]-1]==' ')
        {
             for(int i=1;i<9;i++)
          {
            for(int j=0;j<2;j++)
            {
                if(a[i][j]=='Q'||a[i][j]=='B'||a[i][j]=='N'||a[i][j]=='R')
                {
                    count++;
                }
            }
          }
          if(count==4)
            {return 0;}
        }
    }
  return 1;
}
void getArr(char inputArr[])
{

    char x;
    int z=0;
    while((x=getchar())!='\n')
    {
        if(z<5)
        {
            inputArr[z]=x;
            z++;
        }
    }
    if(z==5)
    {inputArr[z]='\0';}
    else{inputArr[z]='\n';}
}

int readArr(char inputArr[],char a[][14],int x)
{   int w=1,y=1,T=1;//t for return player

   while(w==1||y==1){
   if(T>=2)
    {
       // printf("%d",T);
        printf("wrong Enter again:");}
     //printf("%c",inputArr[0]);
      getArr(inputArr);
     // printf("%c",inputArr[0]);
    w=checkWrite(inputArr,a,x);
    if(w==0)//as true
    {
        y=checkinArr(a,inputArr,x);}
    T++;
   }
        undocount++;
    for(int i=0;i<5;i++)
        {
           undoArr[undocount][i]=inputArr[i];
         }
   return 0;
    //if the input is valid in chess i change the array to the new one
}
void makeUndo(int x,char undo[],char inputArr[],char a[][14])
{
    char TempArr;
    if(x%2!=0)
    {TempArr='p';}
    else if(x%2==0)
    {
        TempArr='P';
    }
    if(undo[0]=='Y'||undo[0]=='y'&&undo[1]=='\n'&&undocount>-1)//here i make limit to undo when user input y or capital Y and undocount to undo till the first player
    {

        if(undoArr[undocount][4]=='\n')
          {//printf("%c",undoArr[undocount][3]);
             for(int j=0;j<4;j++)
            {
                inputArr[j]=undoArr[undocount][j];
                   }
        a[57-inputArr[1]][inputArr[0]-62]=a[57-inputArr[3]][inputArr[2]-62];
        a[57-inputArr[3]][inputArr[2]-62]=' ';//العنصر اللي رايحلو فاضي ولا لا
        undocount--;
           }
           else{
             for(int j=0;j<4;j++)
            {
                inputArr[j]=undoArr[undocount][j];
                   }
            a[57-inputArr[1]][inputArr[0]-62]=TempArr;
            a[57-inputArr[3]][inputArr[2]-62]=' ';
            undocount--;
           }
          // printf("%d",(57-inputArr[3]));
          // printf("%d",placeOutPiece2[m][0]);
          // printf("%d",(inputArr[2]-62));
          // printf("%d",placeOutPiece2[m][1]);
         // printf("%d",x);
           if(x%2!=0)
           {
               if((57-inputArr[3])==placeOutPiece1[s][0]&&(inputArr[2]-62)==placeOutPiece1[s][1])
               {
                   a[57-inputArr[3]][inputArr[2]-62]=a[s][store1];
                    a[s][store1]=' ';
                   s--;
               }
           }
           else if(x%2==0)
           {
               if((57-inputArr[3])==placeOutPiece2[m][0]&&(inputArr[2]-62)==placeOutPiece2[m][1])
               {
                   a[57-inputArr[3]][inputArr[2]-62]=a[m][store2];
                   a[m][store2]=' ';
                   m--;
               }
           }
      printArr(a);
       if(kesh==0)
         {
             kesh=1;
         }
      if(undocount!=-1)
     {
         x--; // i make this decrease as when i go twice player undo change
      printf("do you want Undo:");
      fgets(undo,10,stdin);
      makeUndo(x,undo,inputArr,a);}
    }
    else if(undo[1]!='\n'||(undo[0]!='n'&&undo[0]!='N')){
      printf("please Enter valid char:");
      fgets(undo,10,stdin);
      makeUndo(x,undo,inputArr,a);

    }
}

int main(void)
  { char a[10][14],undo[10];
    makeArr(a);
    int x=1,check=0;
  /*FILE*f1,*f2;
    f1=fopen("file1.txt","r");
    f2=fopen("file2,txt","r");
    if(f1==NULL||f1==NULL)
    {
        printf("file not found");
        exit(1);
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<14;j++)
        {
          fscanf(f1,"%c",&a[i][j]);
        }
    }
    fscanf(f2,"%d",&x);
    fcloseall();*/
    while(check==0)
   {
    char inputArr[5];
    if(x%2!=0)
    {
          if(s>7)//i make this to move the column of storing removed pieces
      {
        store1=0;
        s=0;
      }
         if(kesh==0)
       {
           if(checkInKeshCase(a,inputArr,x)==0)
           {
               printf("checkmate player2 win");
               break;
           }
           else{printf("check\n");}
       }
         if(kesh!=0&&(checkStalemate(x,a)==0)&&checkInKeshCase(a,inputArr,x)==0)
       {
           printf("stalemate draw");
           break;
       }
        printf("Player1:");
        check=readArr(inputArr,a,x);
        //system("cls");
        printArr(a);
        //if(x==1)
        undo[0]='y';
       // printf("%c",undo[0]);
        while(undo[0]=='Y'||undo[0]=='y')
        {
            printf("do you want Undo:");
        fgets(undo,10,stdin);
        makeUndo(x,undo,inputArr,a);
        //printf("%c",undo[0]);
        if(undo[0]=='y'||undo[0]=='Y')
       {
        printf("Player1:");
        check=readArr(inputArr,a,x);
         printArr(a);
        }}
    }
    else{
         if(m>7)//i make this to move the column of storing removed pieces
      {
        store2=13;
        m=0;
      }
            if(kesh==0)
         {
           if(checkInKeshCase(a,inputArr,x)==0)
           {
               printf("checkmate player1 win");
               break;
           }
           else{printf("check\n");}
         }
        if(kesh!=0&&(checkStalemate(x,a)==0)&&checkInKeshCase(a,inputArr,x)==0)
         {
           printf("stalemate draw");
           break;
         }
        printf("player2:");
        check=readArr(inputArr,a,x);
        //system("cls");
        printArr(a);
        printf("do you want Undo:");
        fgets(undo,10,stdin);
       // printf("%c",undo);
        makeUndo(x,undo,inputArr,a);
        //system("cls");
          while(undo[0]=='Y'||undo[0]=='y')
        {
            printf("do you want Undo:");
        fgets(undo,10,stdin);
        makeUndo(x,undo,inputArr,a);
        //printf("%c",undo[0]);
        if(undo[0]=='y'||undo[0]=='Y')
       {
        printf("Player2:");
        check=readArr(inputArr,a,x);
         printArr(a);
        }}
      }
       x++;
   /* f1=fopen("file1.txt","w");
    f2=fopen("file2.txt","w");
   if(f1==NULL||f2==NULL)
    {
        printf("file not found");
        exit(1);
    }
        for(int i=0;i<10;i++)
    {
        for(int j=0;j<14;j++)
        {
          fprintf(f1,"%c",a[i][j]);
        }
    }
    fprintf(f2,"%d",x);
    fcloseall();*/

   }
 return 0;
}
