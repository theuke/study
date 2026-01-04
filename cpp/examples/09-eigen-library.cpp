#include "../CppLibs/Eigen/eigen-3.3.7/Eigen/Dense"
#include <iostream>

#define print(s) std::cout << s << std::endl //I know, I know. But it's one line and won't break anything.

// I thought about using lambdas for print to be nice but it's no bueno, and I'm not using namespace std and I'm not using << explicitly. It's so ugly. now I'm an outlaw using preprocessor commands on a whim. if you don't like it you're going to need to pry my print() function from my cold, dead hands.//auto print = [](std::string s){std::cout << s << std::endl;}; //I know 4 ways to do this now - typedef, define, using, and lambdas. no preprocessor stuff outside of ifndef. I wanted to template the lambda because I want to be able to print anything - but of course the lambda works using function pointers, and templates make multiple functions based on the use case and thus there are multiple function pointers - so of course it doesn't work... But templated lambdas will be introduced in C++20! Excited for this - should be out this month I think - but for now, I'm breaking the law and abusing the preprocessor.

int main()
{

    Eigen::MatrixXf A = (Eigen::MatrixXf::Constant(3,3,1.2))*50;
    Eigen::Matrix3f B;
    B <<    3, 1, 1,
            0, 4, 1,
            0, 0, 5;
    Eigen::Matrix3f C = Eigen::MatrixXf::Random(3,3);
    Eigen::Matrix3f D = Eigen::Matrix3f::Constant(1);
    C = C + D;

    Eigen::VectorXf v(3) ;
    v << 1, 2, 3;

    print("A = ");
    print(A);

    print("v = ");
    print(v);

    print("||v|| = ");
    print(v.transpose()*v);

    print("v*v' = ");
    print(v*v.transpose());

    print("A*v = ");
    print(A*v);

    print("B = ");
    print(B);

    print("B*v = ");
    print(A*v);

    print("A*B = ");
    print(A*B);

    print("C = ");
    print(C);

    print("C*v = ");
    print(C*v);

    print("C*B = ");
    print(C*B);

    print("D = ");
    print(D);

    print("D*v = ");
    print(D*v);

    print("D*B = ");
    print(D*B);

}