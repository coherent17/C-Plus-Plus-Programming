#include <iostream>
#include <iomanip>


int main(){

    //std::setw() : Adjusts the field with for the item about to be printed. 
    //The setw() manipulator only affects the next value to be printed.
    
    std::cout << "Unformatted table : " << std::endl;
    std::cout << "Daniel" << " " << "Gray" << " 25" << std::endl;
    std::cout << "Stanley" <<" "  << "Woods" << " 33" << std::endl;
    std::cout << "Jordan" << " "  << "Parker" << " 45" << std::endl;
    std::cout << "Joe" << " " << "Ball" << " 21" << std::endl;
    std::cout << "Josh" << " " << "Carr" << " 27" << std::endl;
    std::cout << "Izaiah" << " " << "Robinson" << " 29" << std::endl;
    
    std::cout << std::endl;
    std::cout << "Formatted table : " << std::endl;
    
    std::cout << std::setw(10) <<  "Lastname"  << std::setw(10) << "Firstname" << std::setw(5) << "Age" << std::endl;
    std::cout << std::setw(10) << "Daniel"  << std::setw(10) << "Gray" << std::setw(5) << "25" << std::endl;
    std::cout << std::setw(10) << "Stanley" << std::setw(10)  << "Woods" << std::setw(5) <<  "33" << std::endl;
    std::cout << std::setw(10) <<  "Jordan" << std::setw(10)  << "Parker" << std::setw(5) << "45" << std::endl;
    std::cout << std::setw(10) <<  "Joe" << std::setw(10) << "Ball" << std::setw(5) << "21" << std::endl;
    std::cout << std::setw(10) << "Josh" << std::setw(10) << "Carr" << std::setw(5) <<"27" << std::endl;
    std::cout << std::setw(10) << "Izaiah" << std::setw(10) << "Robinson" << std::setw(5) << "29" << std::endl;
    
    //===================================================================
    std::cout << std::endl;

    //boolalpha and noboolapha : control bool output format : 1/0 or true/false
    
    bool condition {true};
    bool other_condition {false};
    
    std::cout << "condition : " << condition << std::endl;
    std::cout << "other_condition : " << other_condition << std::endl;
    
    std::cout << std::endl;
    std::cout << std::boolalpha;
    std::cout << "condition : " << condition << std::endl;
    std::cout << "other_condition : " << other_condition << std::endl;
    
    std::cout << std::endl;
    std::cout << std::noboolalpha;
    std::cout << "condition : " << condition << std::endl;
    std::cout << "other_condition : " << other_condition << std::endl;
    
    //===================================================================
    std::cout << std::endl;

    //showpos and noshowpos : show or hide the +  sign for positive numbers
    
    int pos_num {34};
    int neg_num {-45};
    
    std::cout << "pos_num : " << pos_num << std::endl;
    std::cout << "neg_num : " << neg_num << std::endl;
    
    std::cout << std::endl;
    std::cout << std::showpos;
    std::cout << "pos_num : " << pos_num << std::endl;
    std::cout << "neg_num : " << neg_num << std::endl; 

    std::cout << std::endl;
    std::cout << std::noshowpos;
    std::cout << "pos_num : " << pos_num << std::endl;
    std::cout << "neg_num : " << neg_num << std::endl;   


    //===================================================================
    std::cout << std::endl;


    //different number systems : std::dec, std::hex, std::oct
    
    int pos_int {717171};
    int neg_int {-47347};
    double double_var {498.32};
    
    std::cout << std::endl;
    std::cout << "default base format : " << std::endl;
    std::cout << "pos_int : " << pos_int << std::endl;
    std::cout << "neg_int : " << neg_int << std::endl;
    std::cout << "double_var : " << double_var << std::endl;
    
    std::cout << std::endl;
    std::cout << "pos_int in different bases : " << std::endl;
    std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;
    std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;
    std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;
    
    std::cout << std::endl;
    std::cout << "neg_int in different bases : " << std::endl;
    std::cout << "neg_int (dec) : " << std::dec << neg_int << std::endl;
    std::cout << "neg_int (hex) : " << std::hex << neg_int << std::endl;
    std::cout << "neg_int (oct) : " << std::oct << neg_int << std::endl;
    
    
    //===================================================================
    std::cout << std::endl;


    //uppercase and nouppercase

    pos_int = 717171;
    
    std::cout << "pos_int (nouppercase : default) : " << std::endl;
    std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;
    std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;
    std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;
    
    std::cout << std::endl;
    std::cout << "pos_int (uppercase) : " << std::endl;
    std::cout << std::uppercase;
    std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;
    std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;
    std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;
    
    
    //===================================================================
    std::cout << std::endl;


    //fixed and scientific : for floating point values
    
    double a{ 3.1415926535897932384626433832795 };
    double b{ 2006.0 };
    double c{ 1.34e-10 };
    
    std::cout << std::endl;
    std::cout << "double values (default : use scientific where necessary) : " << std::endl;
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;
    
    std::cout << std::endl;
    std::cout << "double values (fixed) : " << std::endl;
    std::cout << std::fixed;
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;
    
    std::cout << std::endl;
    std::cout << "double values (scientific) : " << std::endl;
    std::cout << std::scientific;
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;

    std::cout << std::endl;
    std::cout << "double values (back to defaults) : " << std::endl;
    std::cout.unsetf(std::ios::scientific | std::ios::fixed); // Hack
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;
    
    
    //===================================================================
    std::cout << std::endl;

    //setprecision() : the number of digits printed out for a floating point. Default is 6
    
    a = 3.1415926535897932384626433832795;
    
    std::cout << std::endl;
    std::cout << "a (default precision(6)) : " << a <<  std::endl;
    std::cout << std::setprecision(10);
    std::cout << "a (precision(10)) : " << a << std::endl;
    std::cout << std::setprecision(20);
    std::cout << "a (precision(20)) : " << a << std::endl;
    
    //If the precision is bigger than supported by the type, you'll just print garbage.
    
    //===================================================================
    std::cout << std::endl;


    //showpoint and noshowpoint : show trailing zeros if necessary
    //Force output of the decimal point
    
    double d {34.1};
    double e {101.99};
    double f {12.0};
    int    g {45};
    
    std::cout << std::endl;
    std::cout << "noshowpoint (default) : " << std::endl;
    std::cout << "d : " << d << std::endl;
    std::cout << "e : " << e << std::endl;
    std::cout << "f : " << f << std::endl; // 12
    std::cout << "g : " << g << std::endl;
    
    std::cout << std::endl;
    std::cout << "showpoint: " << std::endl;
    std::cout << std::showpoint;
    std::cout << "d : " << d << std::endl;
    std::cout << "e : " << e << std::endl;
    std::cout << "f : " << f << std::endl; // 12.0
    std::cout << "g : " << g << std::endl;

    return 0;
}