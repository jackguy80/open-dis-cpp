#pragma once

#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
// The Angle Deception attribute record may be used to communicate discrete values that are associated with angle deception jamming that cannot be referenced to an emitter mode. The values provided in the record records (provided in the associated Electromagnetic Emission PDU). (The victim radar beams are those that are targeted by the jammer.) Section 6.2.21.2.2

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

struct EXPORT_MACRO AngleDeception
{
  /** record type */
  unsigned int recordType;

  /** the length of the record in octets. */
  unsigned short recordLength;

  /** padding */
  unsigned short padding;

  /** indicates the emitter system for which the angle deception values are applicable.  */
  unsigned char emitterNumber;

  /** indicates the jamming beam for which the angle deception values are applicable. */
  unsigned char beamNumber;

  /** This field shall be used to indicate if angle deception data have changed since issuance of the last Angle Deception attribute record for this beam, if the Angle Deception attribute record is part of a heartbeat update to meet periodic update requirements or if the angle deception data for the beam has ceased. */
  unsigned char stateIndicator;

  /** padding */
  unsigned char padding2;

  /** This field indicates the relative azimuth angle at which the deceptive radar returns are centered. This angle is measured in the X-Y plane of the victim radar's entity coordinate system (see 1.4.3). This angle is measured in radians from the victim radar entity's azimuth for the true jam- mer position to the center of the range of azimuths in which deceptive radar returns are perceived as shown in Figure 43. Positive and negative values indicate that the perceived positions of the jammer are right and left of the true position of the jammer, respectively. The range of permissible values is -PI to PI */
  float azimuthOffset;

  /** indicates the range of azimuths (in radians) through which the deceptive radar returns are perceived, centered on the azimuth offset as shown in Figure 43. The range of permissible values is 0 to 2PI radians */
  float azimuthWidth;

  /** This field indicates the rate (in radians per second) at which the Azimuth Offset value is changing. Positive and negative values indicate that the Azimuth Offset is moving to the right or left, respectively. */
  float azimuthPullRate;

  /** This field indicates the rate (in radians per second squared) at which the Azimuth Pull Rate value is changing. Azimuth Pull Acceleration is defined as positive to the right and negative to the left. */
  float azimuthPullAcceleration;

  /** This field indicates the relative elevation angle at which the deceptive radar returns begin. This angle is measured as an angle with respect to the X-Y plane of the victim radar's entity coordinate system (see 1.4.3). This angle is measured in radians from the victim radar entity's eleva- tion for the true jammer position to the center of the range of elevations in which deceptive radar returns are perceived as shown in Figure 44. Positive and negative values indicate that the perceived positions of the jammer are above and below the true position of the jammer, respectively. The range of permissible values is -PI/2 to PI/2 */
  float elevationOffset;

  /** This field indicates the range of elevations (in radians) through which the decep- tive radar returns are perceived, centered on the elevation offset as shown in Figure 44. The range of permissible values is 0 to PI radians */
  float elevationWidth;

  /** This field indicates the rate (in radians per second) at which the Elevation Off- set value is changing. Positive and negative values indicate that the Elevation Offset is moving up or down, respectively.  */
  float elevationPullRate;

  /** This field indicates the rate (in radians per second squared) at which the Elevation Pull Rate value is changing. Elevation Pull Acceleration is defined as positive to upward and negative downward.  */
  float elevationPullAcceleration;

  unsigned int padding3;

    AngleDeception();
    virtual ~AngleDeception();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


     virtual int getMarshalledSize() const;

     bool operator ==(const AngleDeception& rhs) const;
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
