#pragma once

#include "EntityID.h"
#include "EventID.h"
#include "Vector3Float.h"
#include "Vector3Double.h"
#include "BurstDescriptor.h"
#include "Vector3Float.h"
#include "ArticulationParameter.h"
#include <vector>
#include "WarfareFamilyPdu.h"
#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
// Section 5.3.4.2. Information about stuff exploding. COMPLETE

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

#pragma warning(disable: 4251 ) // Disables warning for stl vector template DLL export in msvc

struct EXPORT_MACRO DetonationPdu : public WarfareFamilyPdu
{
  /** ID of muntion that was fired */
  EntityID munitionID;

  /** ID firing event */
  EventID eventID;

  /** ID firing event */
  Vector3Float velocity;

  /** where the detonation is, in world coordinates */
  Vector3Double locationInWorldCoordinates;

  /** Describes munition used */
  BurstDescriptor burstDescriptor;

  /** location of the detonation or impact in the target entity's coordinate system. This information should be used for damage assessment. */
  Vector3Float locationInEntityCoordinates;

  /** result of the explosion */
  unsigned char detonationResult;

  /** How many articulation parameters we have */
  unsigned char numberOfArticulationParameters;

  /** padding */
  short pad;

  std::vector<ArticulationParameter> articulationParameters;

    DetonationPdu();
    virtual ~DetonationPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


     virtual int getMarshalledSize() const;

     bool operator ==(const DetonationPdu& rhs) const;
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
