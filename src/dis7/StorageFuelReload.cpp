#include "StorageFuelReload.h"

using namespace DIS;


StorageFuelReload::StorageFuelReload():
   standardQuantity(0), 
   maximumQuantity(0), 
   standardQuantityReloadTime(0), 
   maximumQuantityReloadTime(0), 
   fuelMeasurementUnits(0), 
   fuelType(0), 
   fuelLocation(0), 
   padding(0)
{
}

StorageFuelReload::~StorageFuelReload()
{
}

void StorageFuelReload::marshal(DataStream& dataStream) const
{
    dataStream << standardQuantity;
    dataStream << maximumQuantity;
    dataStream << standardQuantityReloadTime;
    dataStream << maximumQuantityReloadTime;
    dataStream << fuelMeasurementUnits;
    dataStream << fuelType;
    dataStream << fuelLocation;
    dataStream << padding;
}

void StorageFuelReload::unmarshal(DataStream& dataStream)
{
    dataStream >> standardQuantity;
    dataStream >> maximumQuantity;
    dataStream >> standardQuantityReloadTime;
    dataStream >> maximumQuantityReloadTime;
    dataStream >> fuelMeasurementUnits;
    dataStream >> fuelType;
    dataStream >> fuelLocation;
    dataStream >> padding;
}


bool StorageFuelReload::operator ==(const StorageFuelReload& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (standardQuantity == rhs.standardQuantity) ) ivarsEqual = false;
     if( ! (maximumQuantity == rhs.maximumQuantity) ) ivarsEqual = false;
     if( ! (standardQuantityReloadTime == rhs.standardQuantityReloadTime) ) ivarsEqual = false;
     if( ! (maximumQuantityReloadTime == rhs.maximumQuantityReloadTime) ) ivarsEqual = false;
     if( ! (fuelMeasurementUnits == rhs.fuelMeasurementUnits) ) ivarsEqual = false;
     if( ! (fuelType == rhs.fuelType) ) ivarsEqual = false;
     if( ! (fuelLocation == rhs.fuelLocation) ) ivarsEqual = false;
     if( ! (padding == rhs.padding) ) ivarsEqual = false;

    return ivarsEqual;
 }

int StorageFuelReload::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // standardQuantity
   marshalSize = marshalSize + 4;  // maximumQuantity
   marshalSize = marshalSize + 1;  // standardQuantityReloadTime
   marshalSize = marshalSize + 1;  // maximumQuantityReloadTime
   marshalSize = marshalSize + 1;  // fuelMeasurementUnits
   marshalSize = marshalSize + 1;  // fuelType
   marshalSize = marshalSize + 1;  // fuelLocation
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
