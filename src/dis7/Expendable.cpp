#include "Expendable.h"

using namespace DIS;


Expendable::Expendable():
   expendable(), 
   station(0), 
   quantity(0), 
   expendableStatus(0), 
   padding(0)
{
}

Expendable::~Expendable()
{
}

void Expendable::marshal(DataStream& dataStream) const
{
    expendable.marshal(dataStream);
    dataStream << station;
    dataStream << quantity;
    dataStream << expendableStatus;
    dataStream << padding;
}

void Expendable::unmarshal(DataStream& dataStream)
{
    expendable.unmarshal(dataStream);
    dataStream >> station;
    dataStream >> quantity;
    dataStream >> expendableStatus;
    dataStream >> padding;
}


bool Expendable::operator ==(const Expendable& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (expendable == rhs.expendable) ) ivarsEqual = false;
     if( ! (station == rhs.station) ) ivarsEqual = false;
     if( ! (quantity == rhs.quantity) ) ivarsEqual = false;
     if( ! (expendableStatus == rhs.expendableStatus) ) ivarsEqual = false;
     if( ! (padding == rhs.padding) ) ivarsEqual = false;

    return ivarsEqual;
 }

int Expendable::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + expendable.getMarshalledSize();  // expendable
   marshalSize = marshalSize + 4;  // station
   marshalSize = marshalSize + 2;  // quantity
   marshalSize = marshalSize + 1;  // expendableStatus
   marshalSize = marshalSize + 1;  // padding
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
