class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {

        int sx;
        int sy;
        if(xCenter<x1){
            sx = x1;
        }else if(xCenter>x2){
            sx =x2;
        }else{
            sx = xCenter;
        }
        if(yCenter<y1){
            sy = y1;
        }else if(yCenter>y2){
            sy =y2;
        }else{
            sy = yCenter;
        }

        int dx = sx -xCenter;
        int dy = sy- yCenter;
        return dx*dx+dy*dy<=radius*radius;

    }
};