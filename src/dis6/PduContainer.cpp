#include "PduContainer.h"

using namespace DIS;


PduContainer::PduContainer():
   numberOfPdus(0), 
   pdus(0)
{
}

PduContainer::~PduContainer()
{
    pdus.clear();
}

void PduContainer::marshal(DataStream& dataStream) const
{
    dataStream << ( int )pdus.size();

     for(size_t idx = 0; idx < pdus.size(); idx++)
     {
        Pdu x = pdus[idx];
        x.marshal(dataStream);
     }

}

void PduContainer::unmarshal(DataStream& dataStream)
{
    dataStream >> numberOfPdus;

     pdus.clear();
     for(size_t idx = 0; idx < numberOfPdus; idx++)
     {
        Pdu x;
        x.unmarshal(dataStream);
        pdus.push_back(x);
     }
}


bool PduContainer::operator ==(const PduContainer& rhs) const
 {
     bool ivarsEqual = true;


     for(size_t idx = 0; idx < pdus.size(); idx++)
     {
        if( ! ( pdus[idx] == rhs.pdus[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int PduContainer::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // numberOfPdus

   for(int idx=0; idx < pdus.size(); idx++)
   {
        Pdu listElement = pdus[idx];
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
