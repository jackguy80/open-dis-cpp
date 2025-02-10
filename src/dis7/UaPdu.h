#pragma once

#include "EntityID.h"
#include "EventIdentifier.h"
#include "Vector3Float.h"
#include "Vector3Float.h"
#include "Vector3Float.h"
#include "DistributedEmissionsFamilyPdu.h"
#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
//  Information about underwater acoustic emmissions. This requires manual cleanup.  The beam data records should ALL be a the finish, rather than attached to each emitter system. Section 7.6.4. UNFINISHED

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

struct EXPORT_MACRO UaPdu : public DistributedEmissionsFamilyPdu
{
  /** ID of the entity that is the source of the emission */
  EntityID emittingEntityID;

  /** ID of event */
  EventIdentifier eventID;

  /** This field shall be used to indicate whether the data in the UA PDU represent a state update or data that have changed since issuance of the last UA PDU */
  char stateChangeIndicator;

  /** padding */
  char pad;

  /** This field indicates which database record (or file) shall be used in the definition of passive signature (unintentional) emissions of the entity. The indicated database record (or  file) shall define all noise generated as a function of propulsion plant configurations and associated  auxiliaries. */
  unsigned short passiveParameterIndex;

  /** This field shall specify the entity propulsion plant configuration. This field is used to determine the passive signature characteristics of an entity. */
  unsigned char propulsionPlantConfiguration;

  /**  This field shall represent the number of shafts on a platform */
  unsigned char numberOfShafts;

  /** This field shall indicate the number of APAs described in the current UA PDU */
  unsigned char numberOfAPAs;

  /** This field shall specify the number of UA emitter systems being described in the current UA PDU */
  unsigned char numberOfUAEmitterSystems;

  /** shaft RPM values. THIS IS WRONG. It has the wrong class in the list. */
  Vector3Float shaftRPMs;

  /** apaData. THIS IS WRONG. It has the worng class in the list. */
  Vector3Float apaData;

  /** THIS IS WRONG. It has the wrong class in the list. */
  Vector3Float emitterSystems;

    UaPdu();
    virtual ~UaPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


     virtual int getMarshalledSize() const;

     bool operator ==(const UaPdu& rhs) const;
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
