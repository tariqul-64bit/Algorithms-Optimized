#include<bits/stdc++.h>
using namespace std;

struct point
{
    int x,y;
point(double _x,double _y) : x(_x),y(_y) {}

};


struct vec
{
    double x,y;
    vec(double _x,double _y) : x(_x),y(_y) {}
};

vec toVec(point a, point b)
{
    return vec(b.x-a.x,b.y-a.y);
}


double cross(vec a,vec b)
{
    return a.x*b.y - a.y*b.x;

}


bool ccw(point p,point q,point r )
{
    return cross(toVec(p,q),toVec(p,r)) >0 ;

}


int main()
{

    vector<point> P;
    double coor[100];


    while(1)
    {   P.clear();
        for(int i=0;i<8;i++)   cin>>coor[i];
        for(int i=0;i<8;)  {P.push_back(point(coor[i],coor[i+1])); i=i+2;}


        for(int i=0;i<4;i++) cout<<P[i].x<<" "<<P[i].y<<endl;

        //cout << ccw(P[1],P[2],P[3]) << ccw(P[1],P[2],P[4]) << ccw(P[3],P[4],P[1])<<ccw(P[3],P[4],P[2])<<endl;;

        if( (ccw(P[0],P[1],P[2]) !=  ccw(P[0],P[1],P[3])) && (ccw(P[2],P[3],P[0]) !=  ccw(P[2],P[3],P[1])) )cout<<"INTERSECTED\n";
            else cout<<"NOT INTERSECTED"<<endl;


    }




}
