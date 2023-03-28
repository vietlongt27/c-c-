#include <stdio.h>
#include <math.h>

using namespace std;
// tao class diem voi toa do (x,y)
class Point{

    private: 
        int coordinateX;
        int coordinateY;
    public:
        Point() {}
    
        int getX() {
            return coordinateX;
        }
        int getY() {
            return coordinateY;
        }
        void setX(int x) {
            coordinateX = x;
        }
        void setY(int y) {
            coordinateY = y;
        }
        void inputPoint() {
            printf("X = ");
            scanf("%d", &coordinateX);
            printf("Y = ");
            scanf("%d", &coordinateY);
        }
};

// tao class khong gian 2d ke thua class diem
class twoDSpace: public Point{

    public:
        double distance2Point(Point, Point);
        double areaOfTriangle(Point, Point, Point);
        

};
// tinh khoang cach giua 2 diem 
double twoDSpace::distance2Point(Point firstPoint, Point secondPoint)
{
    double result = 0;
    // can((x2-x1)2 + ( y2-y1)2)
    result = sqrt(pow((firstPoint.getX() - secondPoint.getX()), 2) + pow((firstPoint.getY() - secondPoint.getY()), 2) );
    return result;
};
// tinh dien tich tam giac
double twoDSpace::areaOfTriangle(Point firstPoint, Point secondPoint, Point thirdPoint){
    double result = 0;
    // tinh do dai 3 canh cua tam giac
    double firstSide = distance2Point(firstPoint, secondPoint);     
    double secondSide = distance2Point(secondPoint, thirdPoint);
    double thirSide = distance2Point(firstPoint, thirdPoint);
    //tinh nua chu vi
    double halfCircumference = (firstSide + secondSide + thirSide) / 2;
    // tinh dien tich tam giac theo ct tong quat
    result = sqrt((halfCircumference*(halfCircumference - firstSide)*(halfCircumference-secondSide)*(halfCircumference-thirSide)));
    return result;

};
// tao menu
void menu() {
    int choice;
    do {
        printf("**********MENU***********\n");
        printf("1. Calculate distance of two points\n");
        printf("2. Calculate area of triangle\n");
        printf("3. Exit the program\n");
        printf("Please enter a number: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // khoi tao 2 diem A va B
                Point A;
                A.inputPoint();

                Point B;
                B.inputPoint();
                
                double distance = twoDSpace().distance2Point(A, B);
                printf("Distance between the two points: %.2lf\n", distance);
                break;
            }
            case 2: {
                // khoi tao 3 diem A, B, C
                Point A;
                A.inputPoint();

                Point B;
                B.inputPoint();

                Point C;
                C.inputPoint();

                double area = twoDSpace().areaOfTriangle(A, B, C);
                printf("Area of triangle: %.2lf\n", area);
                break;
            }
            // thoat khoi chuong trinh khi = 3
            case 3: {
                printf("Exiting the program...\n");
                break;
            }
            // nhap lai
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    } while (choice != 3);
}



int main(int argc, char const *argv[])
{
    menu();
    

    return 0;
}

