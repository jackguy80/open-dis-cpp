#pragma once

#include "SimulationAddress.h"
#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
// The unique designation of each aggrgate in an exercise is specified by an aggregate identifier record. The aggregate ID is not an entity and shall not be treated as such. Section 6.2.3.

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

struct EXPORT_MACRO AggregateIdentifier
{
  /** Simulation address, ie site and application, the first two fields of the entity ID */
  SimulationAddress simulationAddress;

  /** the aggregate ID, an object identifier */
  unsigned short aggregateID;

    AggregateIdentifier();
    virtual ~AggregateIdentifier();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


     virtual int getMarshalledSize() const;

     bool operator ==(const AggregateIdentifier& rhs) const;
};
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
