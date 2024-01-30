#include<bits/stdc++.h>
using namespace std;
//defining section OK
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)


//deg to rad and vice versa convert OK

double DEG_to_RAD(double d)
{
    return (d*PI)/180.0;
}

doulbe RAD_to_DEG(double r)
{
    return (r*180)/PI;
}



//struct of point
//point_i kaj korinai oita dia
struct point
{
    double x,y;
    point()
    {
        x=y=0.0;
    }
    point(double _x,double _y) : x(_x),y(_y) {}

    bool operator < (point other) const
    {
        if(fabs(other.x - x) > EPS) return x<other.x;
        else return y<other.y;
    }

    bool operator == (point other) const
    {
        return (fabs(other.x-x)<EPS && fabs(other.y-y)<EPS);
    }

};






//dist function
double dist(point p1,point p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}


//rotate function
point rotate(point p,double theta)
{
    double rad = DEG_to_RAD(theta);
    return point(p.x*cos(rad)-p.y*sin(rad),
                 p.x*sin(rad)+p.y*cos(rad));
}



//struct of line
struct line
{
    double a,b,c;
};

//pointtoline
void pointsToLine(point p1,point p2,line &l)
{
    if(fabs(p1.x-p2.x)<EPS)
    {
        l.a=1.0;
        l.b=0;
        l.c=-(p1.x);
    }
    else
    {
        l.a= (p1.y-p2.y)/(p1.x-p2.x);
        l.b= 1;
        l.c= -(double)(l.a*p1.x) - p1.y;
    }


}

//pointtolinev2 (apatoto lagbena)


//parallel check
bool areParallel(line l1,line l2)
{
    return (fabs(l1.a-l2.a)<EPS)&& (fabs(l1.b-l2.b)<EPS);
}

//same check
bool areSame(line l1,line l2)
{
    return (areParallel(l1,l2)) && (fabs(l1.c-l2.c)<EPS);
}


//intersect check & points
bool areIntersect(line l1,line l2,point &p)
{
    if(areParallel(l1,l2)) return false;

    p.x= (l2.b*l1.c - l1.b * l2.c )/(l2.a*l1.b - l1.a*l2.b);
//(b2c1-b1c2/a2b1-a1b2)
    if(l1.b>EPS) p.y= -(l1.a*p.x + l1.c);
    else         p.y= -(l2.a*p.x + l2.c);

}


//struct vec,function toVec,scale,translate
struct vec
{
    double x,y;
    vec(double _x,double _y) : x(_x),y(_y) {}
};

vec toVec(point a, point b)
{
    return vec(b.x-a.x,b.y-a.y);
}

vec scale(vec v,double s)
{
    return vec(v.x*s, v.y*s);
}

point translate(point p,vec v)
{
    return point(p.x+v.x, p.y+v.y);
}


//pointslope2line
void pointSlopeToLine(point p1,double m, line &l)
{
    l.a= -m;
    l.b= 1;
    l.c= -((l.a*p.x)+(l.b*p.y));
}

//closest point to a line
void closestPoint(line l,point p,point &ans)
{
    if(fabs(l.a)<EPS)
    {
        ans.x = p.x;
        ans.y = -(l.c);
        return;
    }

    if(fabs(l.b)<EPS)
    {
        ans.x = -(l.c);
        ans.y = p.y;
        return;
    }

    line perpendicular;
    pointSlopeToLine(p,1/l.a,perpendicular);
    areIntersect(line,perpendicular,ans);

}


//finding the reflection point about an line of a point
void reflectionPoint(line l,point p,point &ans)
{
    point b;
    closestPoint(l,p,b);
    vec v=toVec(p,b);
    ans= translate(translate(p,v),v);
}


//dot,norm_sq
double dot(vec a,vec b)
{
    return (a.x*b.x + a.y *b.y);
}
double norm_sq(vec v)
{
    return v.x*v.x + v.y*v.y;
}

//dist from a point to a point defined by two points distToline
double distToLine(point p,point a,point b, point &c)
{
    vec ap= toVec(a,p), ab= toVec(a,b);
    double u= dot(ap,ab)/norm_sq(ab);
    c=translate(a,scale(ab,u));
    return dist(p,c);
}



double distToLineSegment(point p,point a, point b,point &c)
{
    vec ap=toVec(a,p), ab= toVec(a,b);
    double u= dot(ap,ab)/norm_sq(ab);

    if(u<0.0)
    {
        c= point(a.x,a.y);
        return dist(p,a);
    }
    if(u>1.0)
    {
        c= point(b.x,b.y);
        return dist(p,b);
    }
    return distToLine(p,a,b,c);

}


//angle

double angle(point a,point o,point b)
{
vec oa=toVec(o,a),ob=toVec(o,b);
return acos(dot(oa,ob)/sqrt(norm_sq(oa) * norm_sq(ob));
}

//cross product (vec a ,vec b)

double cross(vec a,vec b)
{
return a.x*b.y - a.y*b.x;

}

//ccw,checking the cross product
//collinear check
//driver function to check.with manual input


bool ccw(point p,point q,point r )
{
return cross(toVec(p,q),toVec(p,r))>0 ;

}


bool collinear(point p,point q, point r)
{
return fabs(cross(toVec(p,q),toVec(p,r)))<EPS; ;

}





int main()
{

}
