/*M///////////////////////////////////////////////////////////////////////////
// Copyright (c) 2014, sheng
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright notice,
//       this list of conditions and the following disclaimer in the documentation
//       and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//M*/


#include "logging.h"
#include "opencv2/opencv.hpp"


/**
 * @brief Test_Loggng The unit test for the logging class.
 *
 * @author sheng
 * @date   2014-08-21
 * @version 0.1
 *
 * @history
 *     <author>       <date>         <version>        <description>
 *      sheng       2014-08-21          0.1         build the function
 *
 */
void Test_Loggng()
{
    Logging Logger;

    // test int
    int i = 2;
    Logger << i << '\n';

    // test char
    char a = 'a';
    Logger << a << '\n';

    // test long
    long lv = 1234567890;
    Logger << lv << '\n';

    // test char array
    char* b = "adede";
    Logger << b << '\n';

    // test string
    std::string strv = "string";
    Logger << strv << '\n';

    //test cv::Mat
    cv::Mat Image(2,2, CV_8UC1, cv::Scalar(10));
    Logger << Image << '\n';



    // prefix
    std::string FileName = "Hello";
    Logging LoggerInName(FileName);
    LoggerInName << i << "\n";
    LoggerInName << a << "\n";
    LoggerInName << b << "\n";
    LoggerInName << strv << "\n";
    LoggerInName << Image << "\n";

}

