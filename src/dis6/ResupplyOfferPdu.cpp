#include "ResupplyOfferPdu.h"

using namespace DIS;


ResupplyOfferPdu::ResupplyOfferPdu() : LogisticsFamilyPdu(),
   receivingEntityID(), 
   supplyingEntityID(), 
   numberOfSupplyTypes(0), 
   padding1(0), 
   padding2(0), 
   supplies(0)
{
    pduType = 6;
}

ResupplyOfferPdu::~ResupplyOfferPdu()
{
    supplies.clear();
}

void ResupplyOfferPdu::marshal(DataStream& dataStream) const
{
    LogisticsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    receivingEntityID.marshal(dataStream);
    supplyingEntityID.marshal(dataStream);
    dataStream << ( unsigned char )supplies.size();
    dataStream << padding1;
    dataStream << padding2;

     for(size_t idx = 0; idx < supplies.size(); idx++)
     {
        SupplyQuantity x = supplies[idx];
        x.marshal(dataStream);
     }

}

void ResupplyOfferPdu::unmarshal(DataStream& dataStream)
{
    LogisticsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    receivingEntityID.unmarshal(dataStream);
    supplyingEntityID.unmarshal(dataStream);
    dataStream >> numberOfSupplyTypes;
    dataStream >> padding1;
    dataStream >> padding2;

     supplies.clear();
     for(size_t idx = 0; idx < numberOfSupplyTypes; idx++)
     {
        SupplyQuantity x;
        x.unmarshal(dataStream);
        supplies.push_back(x);
     }
}


bool ResupplyOfferPdu::operator ==(const ResupplyOfferPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = LogisticsFamilyPdu::operator==(rhs);

     if( ! (receivingEntityID == rhs.receivingEntityID) ) ivarsEqual = false;
     if( ! (supplyingEntityID == rhs.supplyingEntityID) ) ivarsEqual = false;
     if( ! (padding1 == rhs.padding1) ) ivarsEqual = false;
     if( ! (padding2 == rhs.padding2) ) ivarsEqual = false;

     for(size_t idx = 0; idx < supplies.size(); idx++)
     {
        if( ! ( supplies[idx] == rhs.supplies[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int ResupplyOfferPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = LogisticsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + receivingEntityID.getMarshalledSize();  // receivingEntityID
   marshalSize = marshalSize + supplyingEntityID.getMarshalledSize();  // supplyingEntityID
   marshalSize = marshalSize + 1;  // numberOfSupplyTypes
   marshalSize = marshalSize + 2;  // padding1
   marshalSize = marshalSize + 1;  // padding2

   for(int idx=0; idx < supplies.size(); idx++)
   {
        SupplyQuantity listElement = supplies[idx];
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
