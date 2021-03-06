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


#ifndef LOGGING_H
#define LOGGING_H

#include <iostream>
#include <fstream>
#include <string>



class Logging
{
    public:
        Logging();
        Logging(const std::string& FileName);
        ~Logging();

        template <class T> Logging &operator <<(const T &Input);


    private:
        std::fstream* ActualFile;
        std::string GetCurrentDate();
};



/**
 * @brief Logging::operator <<  The template output operator which is used to
 *        output the Input to the file.
 * @param Input The variable which should be saved in the log file.
 *
 * @author sheng
 * @date   2014-08-22
 * @version 0.1
 *
 * @history
 *     <author>       <date>         <version>        <description>
 *      sheng       2014-08-22          0.1         build the function
 *
 */
template <class T> Logging& Logging::operator <<(const T& Input)
{
    if (ActualFile)
    {
        // write the Input to the log file.
        (*ActualFile) << Input;
    }

    return *this;
}

#endif // LOGGING_H


