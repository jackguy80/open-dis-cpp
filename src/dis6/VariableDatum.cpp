#include "VariableDatum.h"

using namespace DIS;


VariableDatum::VariableDatum():
   variableDatumID(0), 
   variableDatumLength(0), 
   variableData(0)
{
}

VariableDatum::~VariableDatum()
{
    variableData.clear();
}

void VariableDatum::marshal(DataStream& dataStream) const
{
    dataStream << variableDatumID;
    dataStream << ( unsigned int )variableData.size();

     for(size_t idx = 0; idx < variableData.size(); idx++)
     {
        OneByteChunk x = variableData[idx];
        x.marshal(dataStream);
     }

}

void VariableDatum::unmarshal(DataStream& dataStream)
{
    dataStream >> variableDatumID;
    dataStream >> variableDatumLength;

     variableData.clear();
     for(size_t idx = 0; idx < variableDatumLength; idx++)
     {
        OneByteChunk x;
        x.unmarshal(dataStream);
        variableData.push_back(x);
     }
}


bool VariableDatum::operator ==(const VariableDatum& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (variableDatumID == rhs.variableDatumID) ) ivarsEqual = false;

     for(size_t idx = 0; idx < variableData.size(); idx++)
     {
        if( ! ( variableData[idx] == rhs.variableData[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int VariableDatum::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // variableDatumID
   marshalSize = marshalSize + 4;  // variableDatumLength

   for(int idx=0; idx < variableData.size(); idx++)
   {
        OneByteChunk listElement = variableData[idx];
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
