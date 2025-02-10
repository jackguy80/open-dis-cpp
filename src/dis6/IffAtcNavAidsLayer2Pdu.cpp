#include "IffAtcNavAidsLayer2Pdu.h"

using namespace DIS;


IffAtcNavAidsLayer2Pdu::IffAtcNavAidsLayer2Pdu() : IffAtcNavAidsLayer1Pdu(),
   layerHeader(), 
   beamData(), 
   secondaryOperationalData(), 
   fundamentalIffParameters(0)
{
}

IffAtcNavAidsLayer2Pdu::~IffAtcNavAidsLayer2Pdu()
{
    fundamentalIffParameters.clear();
}

void IffAtcNavAidsLayer2Pdu::marshal(DataStream& dataStream) const
{
    IffAtcNavAidsLayer1Pdu::marshal(dataStream); // Marshal information in superclass first
    layerHeader.marshal(dataStream);
    beamData.marshal(dataStream);
    secondaryOperationalData.marshal(dataStream);

     for(size_t idx = 0; idx < fundamentalIffParameters.size(); idx++)
     {
        FundamentalParameterDataIff x = fundamentalIffParameters[idx];
        x.marshal(dataStream);
     }

}

void IffAtcNavAidsLayer2Pdu::unmarshal(DataStream& dataStream)
{
    IffAtcNavAidsLayer1Pdu::unmarshal(dataStream); // unmarshal information in superclass first
    layerHeader.unmarshal(dataStream);
    beamData.unmarshal(dataStream);
    secondaryOperationalData.unmarshal(dataStream);

     fundamentalIffParameters.clear();
     for(size_t idx = 0; idx < pad2; idx++)
     {
        FundamentalParameterDataIff x;
        x.unmarshal(dataStream);
        fundamentalIffParameters.push_back(x);
     }
}


bool IffAtcNavAidsLayer2Pdu::operator ==(const IffAtcNavAidsLayer2Pdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = IffAtcNavAidsLayer1Pdu::operator==(rhs);

     if( ! (layerHeader == rhs.layerHeader) ) ivarsEqual = false;
     if( ! (beamData == rhs.beamData) ) ivarsEqual = false;
     if( ! (secondaryOperationalData == rhs.secondaryOperationalData) ) ivarsEqual = false;

     for(size_t idx = 0; idx < fundamentalIffParameters.size(); idx++)
     {
        if( ! ( fundamentalIffParameters[idx] == rhs.fundamentalIffParameters[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int IffAtcNavAidsLayer2Pdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = IffAtcNavAidsLayer1Pdu::getMarshalledSize();
   marshalSize = marshalSize + layerHeader.getMarshalledSize();  // layerHeader
   marshalSize = marshalSize + beamData.getMarshalledSize();  // beamData
   marshalSize = marshalSize + secondaryOperationalData.getMarshalledSize();  // secondaryOperationalData

   for(int idx=0; idx < fundamentalIffParameters.size(); idx++)
   {
        FundamentalParameterDataIff listElement = fundamentalIffParameters[idx];
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
