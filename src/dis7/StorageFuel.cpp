#include "StorageFuel.h"

using namespace DIS;


StorageFuel::StorageFuel():
   fuelQuantity(0), 
   fuelMeasurementUnits(0), 
   fuelType(0), 
   fuelLocation(0), 
   padding(0)
{
}

StorageFuel::~StorageFuel()
{
}

void StorageFuel::marshal(DataStream& dataStream) const
{
    dataStream << fuelQuantity;
    dataStream << fuelMeasurementUnits;
    dataStream << fuelType;
    dataStream << fuelLocation;
    dataStream << padding;
}

void StorageFuel::unmarshal(DataStream& dataStream)
{
    dataStream >> fuelQuantity;
    dataStream >> fuelMeasurementUnits;
    dataStream >> fuelType;
    dataStream >> fuelLocation;
    dataStream >> padding;
}


bool StorageFuel::operator ==(const StorageFuel& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (fuelQuantity == rhs.fuelQuantity) ) ivarsEqual = false;
     if( ! (fuelMeasurementUnits == rhs.fuelMeasurementUnits) ) ivarsEqual = false;
     if( ! (fuelType == rhs.fuelType) ) ivarsEqual = false;
     if( ! (fuelLocation == rhs.fuelLocation) ) ivarsEqual = false;
     if( ! (padding == rhs.padding) ) ivarsEqual = false;

    return ivarsEqual;
 }

int StorageFuel::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 4;  // fuelQuantity
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
