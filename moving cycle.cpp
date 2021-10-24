#include<graphics.h>
#include<stdio.h>
#include<math.h>
#define pi 3.14159265


float xt=4,yt=9,angle=10,sx=1,sy=0.8,m,c,shx=0,shy=0;
void matrix(float *,float *,int);
enum transformation { TRANSLATE=0, SCALE=1,  ROTATE=2,  REFLECT=3, SHEAR=4};

int main() {
    float x[90],y[90],r[90],xt1,yt1;
    int i,k;

    //circle
    x[0]=325;y[0]=240;r[0]=5;x[1]=325;y[1]=240;r[1]=10;
    x[2]=325-70;y[2]=240;r[2]=40;x[3]=325-70;y[3]=240;r[3]=35;
    x[4]=325-70;y[4]=240;r[4]=10;x[5]=325-70;y[5]=240;r[5]=3;
    x[6]=325+70;y[6]=240;r[6]=40;x[7]=325+70;y[7]=240;r[7]=35;
    x[8]=325+70;y[8]=240;r[8]=10;x[9]=325+70;y[9]=240;r[9]=3;

   //floodfill
    x[10]=325;y[10]=240-7;
    x[11]=325-70;y[11]=240-37;x[12]=325-70;y[12]=240-5;
    x[13]=325+70;y[13]=240-37;x[14]=325+70;y[14]=240-5;

    //line
    x[15]=325-65;y[15]=240+3;x[16]=325-5;y[16]=240+3;x[17]=325-65;y[17]=240-3;x[18]=325-5;y[18]=240-3;
    x[19]=325+5;y[19]=240+8;x[20]=325+38;y[20]=240+60;x[21]=325+7;y[21]=240+1;x[22]=325+45;y[22]=240+60;
    x[23]=325+70-5;y[23]=240+7;x[24]=325+45;y[24]=240+60;x[25]=325+70+2;y[25]=240+5;x[26]=325+43;y[26]=240+92;
    x[27]=325-70+5;y[27]=240+8;x[28]=325-70+41;y[28]=240+67;x[29]=325-70+7;y[29]=240+1;x[30]=325-70+45;y[30]=240+60;
    x[31]=325-5;y[31]=240+7;x[32]=325-70+45;y[32]=240+60;x[33]=325+2;y[33]=240+5;x[34]=325-70+53;y[34]=240+60;
    x[35]=325-70+53;y[35]=240+60;x[36]=325+38;y[36]=240+60;x[37]=325-70+50;y[37]=240+67;x[38]=325+41;y[38]=240+67;
    x[39]=325-70+50;y[39]=240+67;x[40]=325-70+41;y[40]=240+87;x[41]=325-70+32;y[41]=240+87;x[42]=325-70+41;y[42]=240+65;
    x[43]=325-70+32;y[43]=240+87;x[44]=325-70+32-15;y[44]=240+87;x[45]=325-70+41;y[45]=240+87;x[46]=325-70+41+15;y[46]=240+87;
    x[47]=325-70+41+15;y[47]=240+97;x[48]=325-70+32-15;y[48]=240+97;x[49]=325-70+41+15;y[49]=240+97;x[50]=325-70+41+15;y[50]=240+86;
    x[51]=325-70+32-15;y[51]=240+97;x[52]=325-70+32-15;y[52]=240+86;
    x[53]=325+32;y[53]=240+100;x[54]=325+41;y[54]=240+67;x[55]=325+32;y[55]=240+100;x[56]=325+70;y[56]=240+100;
    x[57]=325+43;y[57]=240+92;x[58]=325+60;y[58]=240+92;x[59]=325+60;y[59]=240+92;x[60]=325+60;y[60]=240+92-10;
    x[61]=325+70;y[61]=240+92-10;x[62]=325+70;y[62]=240+100;x[63]=325+60;y[63]=240+92-10;x[64]=325+70;y[64]=240+92-10;

    //rotating line
    k=65;
    for(i=-3;i<=0;i++){
    x[k]=325+70+25+i;y[k]=240-15-i;x[k+1]=325+70+15+i;y[k+1]=240-25-i;x[k+2]=325-70-25-i;y[k+2]=240+15+i;x[k+3]=325-70-15-i;y[k+3]=240+25+i;
    k+=4;
    }

    //floodfill
    x[81]=325-50;y[81]=240;
    x[82]=325-15;y[82]=240;x[83]=325+70-3;y[83]=240+12;
    x[84]=325-70+8;y[84]=240+10;x[85]=325;y[85]=240+65;


    for(i=0;i<=85;i++)
        {
            xt=-325;yt=-240;
            matrix(&x[i],&y[i],TRANSLATE);
            m=0;c=0;
            matrix(&x[i],&y[i],REFLECT);
            matrix(&x[i],&y[i],SCALE);
            xt=325;yt=240;
            matrix(&x[i],&y[i],TRANSLATE);
            xt=-200;yt=-100;
            matrix(&x[i],&y[i],TRANSLATE);
        }

    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, " ");
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(50,50,WHITE);
    setfillstyle(SOLID_FILL,BLACK);
    setcolor(BLACK);
    xt=7;yt=0;
    while(!kbhit())
    {
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(50,50,RED);
        setfillstyle(SOLID_FILL,BLACK);

            if(x[7]<50) {
                    angle=10;
                    for(i=0;i<=85;i++){
                    xt=-100;yt=0;
                    matrix(&x[i],&y[i],TRANSLATE);
                    //matrix(&x[i],&y[i],ROTATE);
                    m=200;c=0;
                    matrix(&x[i],&y[i],REFLECT);
                    xt=100;yt=0;
                    matrix(&x[i],&y[i],TRANSLATE);
                    }
                    xt=7;yt=0;
            }
            if(x[7]>550){
                    angle=-10;
                    for(i=0;i<=85;i++){
                    xt=-500;yt=0;
                    matrix(&x[i],&y[i],TRANSLATE);
                    //matrix(&x[i],&y[i],ROTATE);
                    m=200;c=0;
                    matrix(&x[i],&y[i],REFLECT);
                    xt=500;yt=0;
                    matrix(&x[i],&y[i],TRANSLATE);
                    }
                    xt=-7;yt=0;
            }
        for(i=0;i<=85;i++)
        {
            matrix(&x[i],&y[i],TRANSLATE);
        }
        xt1=xt;yt1=yt;
        for(i=65;i<=80;i+=4)
        {
            xt=-x[7];yt=-y[7];
            matrix(&x[i],&y[i],TRANSLATE);
            matrix(&x[i],&y[i],ROTATE);
            matrix(&x[i+1],&y[i+1],TRANSLATE);
            matrix(&x[i+1],&y[i+1],ROTATE);
            xt=x[7];yt=y[7];
            matrix(&x[i],&y[i],TRANSLATE);
            matrix(&x[i+1],&y[i+1],TRANSLATE);
            xt=-x[3];yt=-y[3];
            matrix(&x[i+2],&y[i+2],TRANSLATE);
            matrix(&x[i+2],&y[i+2],ROTATE);
            matrix(&x[i+3],&y[i+3],TRANSLATE);
            matrix(&x[i+3],&y[i+3],ROTATE);
            xt=x[3];yt=y[3];
            matrix(&x[i+2],&y[i+2],TRANSLATE);
            matrix(&x[i+3],&y[i+3],TRANSLATE);
        }
        xt=xt1;yt=yt1;
    for(i=0;i<=9;i++)
        {
            circle(x[i],y[i],r[i]*sx);
        }
	//for(i=10;i<=14;i++)
      //  {
        //    floodfill(x[i],y[i],BLACK);
        //}
    for(i=15;i<=80;i+=2)
        {
            line(x[i],y[i],x[i+1],y[i+1]);
        }
    //for(i=81;i<=85;i++)
      //  {
        //    floodfill(x[i],y[i],BLACK);
        //}
        delay(50);

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




