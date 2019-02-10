#include<bits/stdc++.h>
using namespace std;
const int MAX=1e3;
const double eps=1e-7;
struct Point{double x,y;};
struct Line
{
    Point st,en;
}Li[MAX];
double ax[10*MAX];
double cross(Point a,Point b){return (a.x*b.y-a.y*b.x);}        //叉积
Point Vector(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};} //向量a-b
double dot(Point a,Point b){return a.x*b.x+a.y*b.y;}            //点积
int segmentin(Point a1,Point a2,Point b1,Point b2)              //判断线段是否相交
{
	double c1=cross(Vector(a2,a1),Vector(b1,a1)),c2=cross(Vector(a2,a1),Vector(b2,a1));
	double c3=cross(Vector(b2,b1),Vector(a1,b1)),c4=cross(Vector(b2,b1),Vector(a2,b1));
	return (c1*c2<0||abs(c1*c2)<=eps)&&(c3*c4<=0||abs(c3*c4)<=eps);
	//如果等于0可能端点处有相交或线段重合
}
Point getaxi(Point a,Point b,Point c,Point d)                   //求线段ab与cd交点
{
    Point u=Vector(a,c);
    Point v=Vector(b,a);
    Point w=Vector(d,c);
    double t=cross(w,u)/cross(v,w);
    return (Point){a.x+v.x*t,a.y+v.y*t};
}
int main()
{
    int n,m=0,siz=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        double L,R,x,y;
        scanf("%lf%lf%lf%lf",&L,&R,&x,&y);
        Li[m++]=(Line){(Point){L,0},(Point){x,y}};
        Li[m++]=(Line){(Point){x,y},(Point){R,0}};
        ax[siz++]=L;
        ax[siz++]=R;
        ax[siz++]=x;
    }
    for(int i=0;i<m;i++)            //求出所有线段的交点
    {
        for(int j=i+1;j<m;j++)
        {
            if(segmentin(Li[i].st,Li[i].en,Li[j].st,Li[j].en)==0)continue;
            ax[siz++]=getaxi(Li[i].st,Li[i].en,Li[j].st,Li[j].en).x;
        }
    }
    sort(ax,ax+siz);
    siz=unique(ax,ax+siz)-ax;
    //for(int i=0;i<siz;i++)printf("x=%.2lf\n",ax[i]);
    double ans=0;
    for(int i=1;i<siz;i++)
    {
        Point p2=(Point){0,0};
        Point p1=(Point){0,0};
        for(int j=0;j<m;j++)//找出所有线段中与x=ax[i]和x=ax[i-1]相交所得到的最高的一条线段
        {
            if((ax[i]-Li[j].st.x>eps||abs(ax[i]-Li[j].st.x)<=eps)&&(Li[j].en.x-ax[i]>eps||abs(Li[j].en.x-ax[i])<=eps)&&(ax[i-1]-Li[j].st.x>eps||abs(ax[i-1]-Li[j].st.x)<=eps)&&(Li[j].en.x-ax[i-1]>eps||abs(Li[j].en.x-ax[i-1])<=eps))
            {
                Point now=getaxi(Li[j].st,Li[j].en,(Point){ax[i],0},(Point){ax[i],1000000});
                Point pre=getaxi(Li[j].st,Li[j].en,(Point){ax[i-1],0},(Point){ax[i-1],1000000});
                if((now.y-p2.y>eps||abs(now.y-p2.y)<=eps)&&(pre.y-p1.y>eps||abs(pre.y-p1.y)<=eps)){p2=now;p1=pre;}
            }
        }
        //printf("pre:x=%.2lf y=%.2lf now:x=%.2lf y=%.2lf\n",p1.x,p1.y,p2.x,p2.y);
        ans+=(p1.y+p2.y)*fabs(p1.x-p2.x)/2;
    }
    printf("%.2lf\n",ans);
    return 0;
}