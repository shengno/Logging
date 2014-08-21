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
#include "CurrentTime.h"

/**
 * @brief Logging::Logging The default constructor
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
Logging::Logging() : ActualFile(NULL)
{
    // get the current date
    std::string FileName = GetCurrentDate();

    // construct a fstream
    ActualFile = new std::fstream;

    // open the output file
    ActualFile->open(FileName.c_str(), std::ios_base::out);
}






/**
 * @brief Logging::Logging The overload constructor
 * @param FileName The prefix of the actural file name
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
Logging::Logging(const std::string &FileName) : ActualFile(NULL)
{
    // consturct a fstream
    ActualFile = new std::fstream;

    // Acturall file name
    std::string ActuralFileName = FileName + GetCurrentDate();

    // open the output file
    ActualFile->open(ActuralFileName.c_str(), std::ios_base::out);
}





/**
 * @brief Logging::~Logging The destructor
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
Logging::~Logging()
{
    if (ActualFile)
    {
        // closed the file
        ActualFile->close();

        // release the memory
        delete ActualFile;
    }
}






/**
 * @brief Logging::GetCurrentDate Get a string which represent the local current
 *        time.
 * @return The local current time in the type of string.
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
std::string Logging::GetCurrentDate()
{
    // get the current date in string
    std::string Result = GetCurrentTime();

    return Result;
}




/**
 * @brief Logging::operator <<  Overload operator
 * @param Input The Input which would the be saved in the logging file.
 * @return The Logging objcet.
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
template <class T>
Logging &Logging::operator <<(const T & Input)
{
    // save the input when the actual file is existed.
    if (ActualFile)
    {
        ActualFile << Input;
    }

    return *this;
}
