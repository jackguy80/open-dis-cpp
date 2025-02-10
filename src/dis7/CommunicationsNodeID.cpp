#include "CommunicationsNodeID.h"

using namespace DIS;


CommunicationsNodeID::CommunicationsNodeID():
   entityID(), 
   elementID(0)
{
}

CommunicationsNodeID::~CommunicationsNodeID()
{
}

void CommunicationsNodeID::marshal(DataStream& dataStream) const
{
    entityID.marshal(dataStream);
    dataStream << elementID;
}

void CommunicationsNodeID::unmarshal(DataStream& dataStream)
{
    entityID.unmarshal(dataStream);
    dataStream >> elementID;
}


bool CommunicationsNodeID::operator ==(const CommunicationsNodeID& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (entityID == rhs.entityID) ) ivarsEqual = false;
     if( ! (elementID == rhs.elementID) ) ivarsEqual = false;

    return ivarsEqual;
 }

int CommunicationsNodeID::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + entityID.getMarshalledSize();  // entityID
   marshalSize = marshalSize + 2;  // elementID
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
