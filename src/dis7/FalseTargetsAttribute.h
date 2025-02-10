#pragma once

#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
// The False Targets attribute record shall be used to communicate discrete values that are associated with false targets jamming that cannot be referenced to an emitter mode. The values provided in the False Targets attri- bute record shall be considered valid only for the victim radar beams listed in the jamming beam's Track/Jam Data records (provided in the associated Electromagnetic Emission PDU). Section 6.2.21.3

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

struct EXPORT_MACRO FalseTargetsAttribute
{
  /** record type */
  unsigned int recordType;

  /** the length of the record in octets. */
  unsigned short recordLength;

  /** padding */
  unsigned short padding;

  /** This field indicates the emitter system generating the false targets. */
  unsigned char emitterNumber;

  /** This field indicates the jamming beam generating the false targets.  */
  unsigned char beamNumber;

  /** This field shall be used to indicate if false target data have changed since issuance of the last False Targets attribute record for this beam, if the False Targets attribute record is part of a heartbeat update to meet periodic update requirements or if false target data for the beam has ceased. */
  unsigned char stateIndicator;

  /** padding */
  unsigned char padding2;

  /** This field indicates the jamming beam generating the false targets.  */
  unsigned short falseTargetCount;

  /** This field shall specify the speed (in meters per second) at which false targets move toward the victim radar. Negative values shall indicate a velocity away from the victim radar.  */
  float walkSpeed;

  /** This field shall specify the rate (in meters per second squared) at which false tar- gets accelerate toward the victim radar. Negative values shall indicate an acceleration direction away from the victim radar.  */
  float walkAcceleration;

  /** This field shall specify the distance (in meters) that a false target is to walk before it pauses in range.  */
  float maximumWalkDistance;

  /** This field shall specify the time (in seconds) that a false target is to be held at the Maxi- mum Walk Distance before it resets to its initial position.  */
  float keepTime;

  /** TThis field shall specify the distance between false targets in meters. Positive values for this field shall indicate that second and subsequent false targets are initially placed at increasing ranges from the victim radar.  */
  float echoSpacing;

    FalseTargetsAttribute();
    virtual ~FalseTargetsAttribute();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


     virtual int getMarshalledSize() const;

     bool operator ==(const FalseTargetsAttribute& rhs) const;
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
