// ///////////////////////////// MIT License //////////////////////////////////// //
//                                                                                //
// Copyright (c) 2013 David Zsolt Manrique                                        //
//                    david.zsolt.manrique@gmail.com                              //
//                                                                                //
// Permission is hereby granted, free of charge, to any person obtaining a copy   //
// of this software and associated documentation files (the "Software"), to deal  //
// in the Software without restriction, including without limitation the rights   //
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      //
// copies of the Software, and to permit persons to whom the Software is          //
// furnished to do so, subject to the following conditions:                       //
//                                                                                //
// The above copyright notice and this permission notice shall be included in     //
// all copies or substantial portions of the Software.                            //
//                                                                                //
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     //
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       //
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    //
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         //
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  //
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN      //
// THE SOFTWARE.                                                                  //
//                                                                                //
// ////////////////////////////////////////////////////////////////////////////// //


#include "cmdl.h"

using namespace cmdl;

int main(int argc, char **argv) {

    //arguments arg(argc, argv);

    arguments arg("program -mvad 1.1 -vad -2.2 -vai -1 -vas str -mvad 2.2 -t1 3.3 -t3 4.4 4 str -mt3 5.5 5 str1 -mvad 3.3 -mt3 6.6 6 str2 1 a b c d e f g h i 2");


    switcharg<false> help(arg, "-h", "--help", "print help message");

    //{
        vararg<double> vararg_double(arg, "-vad", "--va-double", "help message for vararg-double", 0.0);
    //}
    vararg<int> vararg_int(arg, "-vai", "--va-int", "help message for vararg-int", 0);
    vararg<std::string> vararg_string(arg, "-vas", "--va-string", "help message for vararg-string", "string");

    multivararg<double> multivararg_double(arg, "-mvad", "--mva-double", "help message for multivararg-double", 0.0);
    multivararg<int> multivararg_int(arg, "-mvai", "--mva-int", "help message for multivararg-int", 0);
    multivararg<std::string> multivararg_string(arg, "-mvas", "--mva-string", "help message for multivararg-string", "string");

    tuplevararg<double> tuplevararg1(arg, "-t1", "--tuple3", "help message for double-int-string", 0.0);
    tuplevararg<double, int, std::string> tuplevararg3(arg, "-t3", "--tuple3", "help message for double-int-string", 0.0, 0, "string");
    tuplevararg<double, int, std::string, double, int, std::string> tuplevararg6(arg, "-t6", "--tuple6", "help message for double-int-string-double-int-string", 0.0, 0, "string", 1.1, 1, "string");

    muplevararg<double> muplevararg1(arg, "-mt1", "--muple3", "help message for double-int-string", 0.0);
    muplevararg<double, int, std::string> muplevararg3(arg, "-mt3", "--muple3", "help message for double-int-string", 0.0, 0, "string");
    muplevararg<double, int, std::string, double, int, std::string> muplevararg6(arg, "-mt6", "--muple6", "help message for double-int-string-double-int-string", 0.0, 0, "string", 1.1, 1, "string");

    posarg<int> pos1(arg, "this pos1 int", 1);
    multiposarg<std::string> pos2(arg, "this is pos2 maximum 9 strings", "", 9);
    posarg<int> pos3(arg, "this pos3 int", 1);
    multiposarg<std::string> pos4(arg, "this is pos4 maximum 4 strings", "", 4);
    multiposarg<std::string> pos5(arg, "this is pos5 arbritrary strings", "");


    //interpret<int,int,int>(1,2,3,"")

    //interpret(1,2,3,"x,x:x");

    //interpret(1,2,3,"x,x:x");
    //interpret<int,int,int>    
    if (*help) {
        arg.print_help(std::cout);
        std::cout << "examples:" << std::endl;
        std::cout << arg.name() << " -h" << std::endl;
        std::cout << std::endl;
        std::cout << "Copyright (c) 2012 David Zsolt Manrique (david.zsolt.manrique@gmail.com)" << std::endl;
        std::cout << "Version 0.99b" << std::endl;
        exit(EXIT_SUCCESS);
    }

    std::cout << arg.cmdline() << std::endl;
    std::cout << arg.cmdline() << std::endl;

    arg.print();
    std::cout << arg.cmdline() << std::endl;
    std::cout << arg.cmdline() << std::endl;

    std::cout << help.val() << std::endl;
    //std::cout << vararg_double.val() << std::endl;
    //std::cout << *vararg_double << std::endl;
    std::cout << vararg_int.val() << std::endl;
    std::cout << vararg_string.val() << std::endl;
//    for (auto x : multivararg_double.val()) std::cout << x << std::endl;
//    for (auto x : multivararg_int.val()) std::cout << x << std::endl;
//    for (auto x : multivararg_string.val()) std::cout << x << std::endl;

    std::cout << pos1.val() << std::endl;
//    for (auto x : pos2.val()) std::cout << x << std::endl;
    std::cout << pos3.val() << std::endl;
//    for (auto x : pos4.val()) std::cout << x << std::endl;
//    for (auto x : pos5.val()) std::cout << x << std::endl;

    arg.print_all();

}

