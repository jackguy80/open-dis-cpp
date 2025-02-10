#include "EventID.h"

using namespace DIS;


EventID::EventID():
   site(0), 
   application(0), 
   eventNumber(0)
{
}

EventID::~EventID()
{
}

void EventID::marshal(DataStream& dataStream) const
{
    dataStream << site;
    dataStream << application;
    dataStream << eventNumber;
}

void EventID::unmarshal(DataStream& dataStream)
{
    dataStream >> site;
    dataStream >> application;
    dataStream >> eventNumber;
}


bool EventID::operator ==(const EventID& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (site == rhs.site) ) ivarsEqual = false;
     if( ! (application == rhs.application) ) ivarsEqual = false;
     if( ! (eventNumber == rhs.eventNumber) ) ivarsEqual = false;

    return ivarsEqual;
 }

int EventID::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 2;  // site
   marshalSize = marshalSize + 2;  // application
   marshalSize = marshalSize + 2;  // eventNumber
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
