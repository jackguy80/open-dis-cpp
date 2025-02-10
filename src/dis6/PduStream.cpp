#include "PduStream.h"

using namespace DIS;


PduStream::PduStream():
   startTime(0), 
   stopTime(0), 
   pduCount(0), 
   pdusInStream(0)
{
     // Initialize fixed length array
     for(int lengthshortDescription= 0; lengthshortDescription < 256; lengthshortDescription++)
     {
         shortDescription[lengthshortDescription] = 0;
     }

     // Initialize fixed length array
     for(int lengthlongDescription= 0; lengthlongDescription < 512; lengthlongDescription++)
     {
         longDescription[lengthlongDescription] = 0;
     }

     // Initialize fixed length array
     for(int lengthpersonRecording= 0; lengthpersonRecording < 128; lengthpersonRecording++)
     {
         personRecording[lengthpersonRecording] = 0;
     }

     // Initialize fixed length array
     for(int lengthauthorEmail= 0; lengthauthorEmail < 128; lengthauthorEmail++)
     {
         authorEmail[lengthauthorEmail] = 0;
     }

}

PduStream::~PduStream()
{
    pdusInStream.clear();
}

void PduStream::marshal(DataStream& dataStream) const
{

     for(size_t idx = 0; idx < 256; idx++)
     {
        dataStream << shortDescription[idx];
     }


     for(size_t idx = 0; idx < 512; idx++)
     {
        dataStream << longDescription[idx];
     }


     for(size_t idx = 0; idx < 128; idx++)
     {
        dataStream << personRecording[idx];
     }


     for(size_t idx = 0; idx < 128; idx++)
     {
        dataStream << authorEmail[idx];
     }

    dataStream << startTime;
    dataStream << stopTime;
    dataStream << ( unsigned int )pdusInStream.size();

     for(size_t idx = 0; idx < pdusInStream.size(); idx++)
     {
        Pdu x = pdusInStream[idx];
        x.marshal(dataStream);
     }

}

void PduStream::unmarshal(DataStream& dataStream)
{

     for(size_t idx = 0; idx < 256; idx++)
     {
        dataStream >> shortDescription[idx];
     }


     for(size_t idx = 0; idx < 512; idx++)
     {
        dataStream >> longDescription[idx];
     }


     for(size_t idx = 0; idx < 128; idx++)
     {
        dataStream >> personRecording[idx];
     }


     for(size_t idx = 0; idx < 128; idx++)
     {
        dataStream >> authorEmail[idx];
     }

    dataStream >> startTime;
    dataStream >> stopTime;
    dataStream >> pduCount;

     pdusInStream.clear();
     for(size_t idx = 0; idx < pduCount; idx++)
     {
        Pdu x;
        x.unmarshal(dataStream);
        pdusInStream.push_back(x);
     }
}


bool PduStream::operator ==(const PduStream& rhs) const
 {
     bool ivarsEqual = true;


     for(int idx = 0; idx < 256; idx++)
     {
          if(!(shortDescription[idx] == rhs.shortDescription[idx]) ) ivarsEqual = false;
     }


     for(int idx = 0; idx < 512; idx++)
     {
          if(!(longDescription[idx] == rhs.longDescription[idx]) ) ivarsEqual = false;
     }


     for(int idx = 0; idx < 128; idx++)
     {
          if(!(personRecording[idx] == rhs.personRecording[idx]) ) ivarsEqual = false;
     }


     for(int idx = 0; idx < 128; idx++)
     {
          if(!(authorEmail[idx] == rhs.authorEmail[idx]) ) ivarsEqual = false;
     }

     if( ! (startTime == rhs.startTime) ) ivarsEqual = false;
     if( ! (stopTime == rhs.stopTime) ) ivarsEqual = false;

     for(size_t idx = 0; idx < pdusInStream.size(); idx++)
     {
        if( ! ( pdusInStream[idx] == rhs.pdusInStream[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int PduStream::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 256 * 1;  // shortDescription
   marshalSize = marshalSize + 512 * 1;  // longDescription
   marshalSize = marshalSize + 128 * 1;  // personRecording
   marshalSize = marshalSize + 128 * 1;  // authorEmail
   marshalSize = marshalSize + 8;  // startTime
   marshalSize = marshalSize + 8;  // stopTime
   marshalSize = marshalSize + 4;  // pduCount

   for(int idx=0; idx < pdusInStream.size(); idx++)
   {
        Pdu listElement = pdusInStream[idx];
        marshalSize = marshalSize + listElement.getMarshalledSize();
    }

    return marshalSize;
}

// Copyright (c) 1995-2009 held by the author(s).  All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
//  are met:
// 
//  * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// * Neither the names of the Naval Postgraduate School (NPS)
//  Modeling Virtual Environments and Simulation (MOVES) Institute
// (http://www.nps.edu and http://www.MovesInstitute.org)
// nor the names of its contributors may be used to endorse or
//  promote products derived from this software without specific
// prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// AS IS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
