#include "DirectedEnergyDamage.h"

using namespace DIS;


DirectedEnergyDamage::DirectedEnergyDamage():
   recordType(4500), 
   recordLength(40), 
   padding(0), 
   damageLocation(), 
   damageDiameter(0.0), 
   temperature(-273.15), 
   componentIdentification(0), 
   componentDamageStatus(0), 
   componentVisualDamageStatus(0), 
   componentVisualSmokeColor(0), 
   fireEventID(), 
   padding2(0)
{
}

DirectedEnergyDamage::~DirectedEnergyDamage()
{
}

void DirectedEnergyDamage::marshal(DataStream& dataStream) const
{
    dataStream << recordType;
    dataStream << recordLength;
    dataStream << padding;
    damageLocation.marshal(dataStream);
    dataStream << damageDiameter;
    dataStream << temperature;
    dataStream << componentIdentification;
    dataStream << componentDamageStatus;
    dataStream << componentVisualDamageStatus;
    dataStream << componentVisualSmokeColor;
    fireEventID.marshal(dataStream);
    dataStream << padding2;
}

void DirectedEnergyDamage::unmarshal(DataStream& dataStream)
{
    dataStream >> recordType;
    dataStream >> recordLength;
    dataStream >> padding;
    damageLocation.unmarshal(dataStream);
    dataStream >> damageDiameter;
    dataStream >> temperature;
    dataStream >> componentIdentification;
    dataStream >> componentDamageStatus;
    dataStream >> componentVisualDamageStatus;
    dataStream >> componentVisualSmokeColor;
    fireEventID.unmarshal(dataStream);
    dataStream >> padding2;
}


bool DirectedEnergyDamage::operator ==(const DirectedEnergyDamage& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (recordType == rhs.recordType) ) ivarsEqual = false;
     if( ! (recordLength == rhs.recordLength) ) ivarsEqual = false;
     if( ! (padding == rhs.padding) ) ivarsEqual = false;
     if( ! (damageLocation == rhs.damageLocation) ) ivarsEqual = false;
     if( ! (damageDiameter == rhs.damageDiameter) ) ivarsEqual = false;
     if( ! (temperature == rhs.temperature) ) ivarsEqual = false;
     if( ! (componentIdentification == rhs.componentIdentification) ) ivarsEqual = false;
     if( ! (componentDamageStatus == rhs.componentDamageStatus) ) ivarsEqual = false;
     if( ! (componentVisualDamageStatus == rhs.componentVisualDamageStatus) ) ivarsEqual = false;
     if( ! (componentVisualSmokeColor == rhs.componentVisualSmokeColor) ) ivarsEqual = false;
     if( ! (fireEventID == rhs.fireEventID) ) ivarsEqual = false;
     if( ! (padding2 == rhs.padding2) ) ivarsEqual = false;

    return ivarsEqual;
 }

int DirectedEnergyDamage::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // recordType
   marshalSize = marshalSize + 2;  // recordLength
   marshalSize = marshalSize + 2;  // padding
   marshalSize = marshalSize + damageLocation.getMarshalledSize();  // damageLocation
   marshalSize = marshalSize + 4;  // damageDiameter
   marshalSize = marshalSize + 4;  // temperature
   marshalSize = marshalSize + 1;  // componentIdentification
   marshalSize = marshalSize + 1;  // componentDamageStatus
   marshalSize = marshalSize + 1;  // componentVisualDamageStatus
   marshalSize = marshalSize + 1;  // componentVisualSmokeColor
   marshalSize = marshalSize + fireEventID.getMarshalledSize();  // fireEventID
   marshalSize = marshalSize + 2;  // padding2
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
