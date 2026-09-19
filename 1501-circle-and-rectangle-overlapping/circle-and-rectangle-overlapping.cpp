class Solution {
public:
    bool checkOverlap(int radius, int xcenter, int ycenter, int x1, int y1, int x2, int y2) {
        int cx; int cy;
        if(xcenter<x1){
            cx=x1;
        }
        else if(xcenter>x2){
            cx=x2;
        }
        else if(x1<=xcenter && xcenter<=x2){
            cx=xcenter;
        }

        if(ycenter<y1){
            cy=y1;
        }
        else if(ycenter>y2){
            cy=y2;
        }
        else if(y1<=ycenter && ycenter<=y2){
            cy=ycenter;
        }

        long long r2=radius*radius;
        int x= abs(cx-xcenter);
        int y= abs(cy-ycenter);
        long long dis= x*x + y*y;
        if(dis<=r2) return true;
        else return false;

    }
};