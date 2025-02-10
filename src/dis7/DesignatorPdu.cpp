#include "DesignatorPdu.h"

using namespace DIS;


DesignatorPdu::DesignatorPdu() : DistributedEmissionsFamilyPdu(),
   designatingEntityID(), 
   codeName(0), 
   designatedEntityID(), 
   designatorCode(0), 
   designatorPower(0.0), 
   designatorWavelength(0.0), 
   designatorSpotWrtDesignated(), 
   designatorSpotLocation(), 
   deadReckoningAlgorithm(0), 
   padding1(0), 
   padding2(0), 
   entityLinearAcceleration()
{
    pduType = 24;
}

DesignatorPdu::~DesignatorPdu()
{
}

void DesignatorPdu::marshal(DataStream& dataStream) const
{
    DistributedEmissionsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    designatingEntityID.marshal(dataStream);
    dataStream << codeName;
    designatedEntityID.marshal(dataStream);
    dataStream << designatorCode;
    dataStream << designatorPower;
    dataStream << designatorWavelength;
    designatorSpotWrtDesignated.marshal(dataStream);
    designatorSpotLocation.marshal(dataStream);
    dataStream << deadReckoningAlgorithm;
    dataStream << padding1;
    dataStream << padding2;
    entityLinearAcceleration.marshal(dataStream);
}

void DesignatorPdu::unmarshal(DataStream& dataStream)
{
    DistributedEmissionsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    designatingEntityID.unmarshal(dataStream);
    dataStream >> codeName;
    designatedEntityID.unmarshal(dataStream);
    dataStream >> designatorCode;
    dataStream >> designatorPower;
    dataStream >> designatorWavelength;
    designatorSpotWrtDesignated.unmarshal(dataStream);
    designatorSpotLocation.unmarshal(dataStream);
    dataStream >> deadReckoningAlgorithm;
    dataStream >> padding1;
    dataStream >> padding2;
    entityLinearAcceleration.unmarshal(dataStream);
}


bool DesignatorPdu::operator ==(const DesignatorPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = DistributedEmissionsFamilyPdu::operator==(rhs);

     if( ! (designatingEntityID == rhs.designatingEntityID) ) ivarsEqual = false;
     if( ! (codeName == rhs.codeName) ) ivarsEqual = false;
     if( ! (designatedEntityID == rhs.designatedEntityID) ) ivarsEqual = false;
     if( ! (designatorCode == rhs.designatorCode) ) ivarsEqual = false;
     if( ! (designatorPower == rhs.designatorPower) ) ivarsEqual = false;
     if( ! (designatorWavelength == rhs.designatorWavelength) ) ivarsEqual = false;
     if( ! (designatorSpotWrtDesignated == rhs.designatorSpotWrtDesignated) ) ivarsEqual = false;
     if( ! (designatorSpotLocation == rhs.designatorSpotLocation) ) ivarsEqual = false;
     if( ! (deadReckoningAlgorithm == rhs.deadReckoningAlgorithm) ) ivarsEqual = false;
     if( ! (padding1 == rhs.padding1) ) ivarsEqual = false;
     if( ! (padding2 == rhs.padding2) ) ivarsEqual = false;
     if( ! (entityLinearAcceleration == rhs.entityLinearAcceleration) ) ivarsEqual = false;

    return ivarsEqual;
 }

int DesignatorPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = DistributedEmissionsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + designatingEntityID.getMarshalledSize();  // designatingEntityID
   marshalSize = marshalSize + 2;  // codeName
   marshalSize = marshalSize + designatedEntityID.getMarshalledSize();  // designatedEntityID
   marshalSize = marshalSize + 2;  // designatorCode
   marshalSize = marshalSize + 4;  // designatorPower
   marshalSize = marshalSize + 4;  // designatorWavelength
   marshalSize = marshalSize + designatorSpotWrtDesignated.getMarshalledSize();  // designatorSpotWrtDesignated
   marshalSize = marshalSize + designatorSpotLocation.getMarshalledSize();  // designatorSpotLocation
   marshalSize = marshalSize + 1;  // deadReckoningAlgorithm
   marshalSize = marshalSize + 2;  // padding1
   marshalSize = marshalSize + 1;  // padding2
   marshalSize = marshalSize + entityLinearAcceleration.getMarshalledSize();  // entityLinearAcceleration
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
