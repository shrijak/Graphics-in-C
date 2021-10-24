#include<graphics.h>
#include<stdio.h>
#include<math.h>
#define pi 3.141592
#define sx 0.2
#define sy 0.2

int xt=4,yt=9,shx=0,shy=0,m,c;
float angle=75;
void matrix(float *,float *,int);
enum transformation { TRANSLATE=0, SCALE=1,  ROTATE=2,  REFLECT=3, SHEAR=4};

int main() {
    float x[140],y[140];
    int i,j,k,r=191,xt1,yt1;
    x[0]=325,y[0]=240;
    k=1;
    for(i=90;i<=450;i+=60){
      x[k]=325 + 70*cos(i*(pi/180));
      y[k]=240 + 70*sin(i*(pi/180));
      x[k+1]=325 + 70*cos((i+60)*(pi/180));
      y[k+1]=240 + 70*sin((i+60)*(pi/180));
      k+=2;
	}
    for(i=0;i<360;i+=60){
      for(j=90;j<=450;j+=60){
      x[k]= 325 +  120*cos(i*(pi/180)) + 70*cos(j*(pi/180));
      y[k]= 240 +  120*sin(i*(pi/180)) + 70*sin(j*(pi/180));
      x[k+1]= 325 +  120*cos(i*(pi/180)) + 70*cos((j+60)*(pi/180));
      y[k+1]= 240 +  120*sin(i*(pi/180)) + 70*sin((j+60)*(pi/180));
      k+=2;
      }
	}
	 for(i=49;i<=409;i+=60){
      x[k]=325 + 183*cos(i*(pi/180));
      y[k]=240 + 183*sin(i*(pi/180));
      x[k+1]=325 + 191*cos((i-2)*(pi/180));
      y[k+1]=240 + 191*sin((i-2)*(pi/180));
      x[k+2]=325 + 183*cos((i+22)*(pi/180));
      y[k+2]=240 + 183*sin((i+22)*(pi/180));
      x[k+3]=325 + 191*cos((i+24)*(pi/180));
      y[k+3]=240 + 191*sin((i+24)*(pi/180));
      k+=4;
	}
	for(i=40;i<=400;i+=60){
            x[k]= 325 + 180*cos(i*(pi/180));
            y[k]= 240 + 180*sin(i*(pi/180));
            k++;
            }

    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, " ");
setfillstyle(SOLID_FILL,WHITE);
    floodfill(70,70,BLUE);

    for(i=0;i<=k;i++)
        {
            matrix(&x[i],&y[i],SCALE);
        }
    setcolor(BLUE);
    line(0,240,639,240);
    setcolor(BLACK);
    while(!kbhit()){
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(70,70,BLUE);
    setfillstyle(SOLID_FILL,BLACK);
    line(0,53,639,53);
    for(i=0;i<=k;i++)
        {
        matrix(&x[i],&y[i],TRANSLATE);
        }
        xt1=xt;yt1=yt;
    for(i=1;i<=k;i++)
    {
            xt=-x[0];yt=-y[0];
            matrix(&x[i],&y[i],TRANSLATE);
            matrix(&x[i],&y[i],ROTATE);
            xt=x[0];yt=y[0];
            matrix(&x[i],&y[i],TRANSLATE);

    }
    xt=xt1;yt=yt1;
    circle(x[0],y[0],r*sx);
    for(i=1;i<127;i+=2)
        {
            line(x[i],y[i],x[i+1],y[i+1]);
        }
	floodfill(x[0],y[0],BLACK);
	for(i=127;i<k;i++)
        {
            floodfill(x[i],y[i],BLACK);
        }
        delay(40);
        if(x[0]>600){xt=-4;angle=-75;}
        if(x[0]<39){xt=+4;angle=75;}
        if(y[0]>200){yt=-9;}
        if(y[0]<100){yt=+9;}
    }
    getch();
    closegraph();
    return 0;
}

void matrix(float *x,float *y,int transformation){
    int i,j,k;
    float sum,a[3][3],ang=(angle*pi)/180;
    float b[3][1]={*x,*y,1};
    float d[3][1];

    if(transformation==0){a[0][0]=1;a[0][1]=0;a[0][2]=xt;
                          a[1][0]=0;a[1][1]=1;a[1][2]=yt;
                          a[2][0]=0;a[2][1]=0;a[2][2]=1;}
    else if(transformation==1){a[0][0]=sx;a[0][1]=0;a[0][2]=0;
                               a[1][0]=0;a[1][1]=sy;a[1][2]=0;
                               a[2][0]=0;a[2][1]=0;a[2][2]=1;}
    else if(transformation==2){a[0][0]=cos(ang);a[0][1]=-sin(ang);a[0][2]=0;
                               a[1][0]=sin(ang);a[1][1]=cos(ang);a[1][2]=0;
                               a[2][0]=0;a[2][1]=0;a[2][2]=1;}
    else if(transformation==3){a[0][0]=(1 - m*m)/(1 + m*m);a[0][1]=(2*m)/(1 + m*m);a[0][2]=(- 2*c*m)/(1 + m*m);
                               a[1][0]=(2*m)/(1 + m*m);a[1][1]=(m*m - 1)/(1 + m*m);a[1][2]=(2*c)/(1 + m*m);
                               a[2][0]=0;a[2][1]=0;a[2][2]=1;}
    else if(transformation==4){a[0][0]=1;a[0][1]=shx;a[0][2]=0;
                          a[1][0]=shy;a[1][1]=1;a[1][2]=0;
                          a[2][0]=0;a[2][1]=0;a[2][2]=1;}
for(i=0;i<3;i++)
{
for(j=0;j<1;j++)
{
sum=0;
for(k=0;k<3;k++)
{
sum+=a[i][k]*b[k][j];
}
d[i][j] = sum;
}
}
*x=d[0][0];
*y=d[1][0];
}




