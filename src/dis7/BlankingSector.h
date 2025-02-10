#pragma once

#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
// The Blanking Sector attribute record may be used to convey persistent areas within a scan volume where emitter power for a specific active emitter beam is reduced to an insignificant value. Section 6.2.21.2

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

struct EXPORT_MACRO BlankingSector
{
  /** record type */
  int recordType;

  /** the length of the Blanking Sector attribute record in octets. */
  unsigned short recordLength;

  /** Pading */
  unsigned short padding;

  /** indicates the emitter system for which the blanking sector values are applicable */
  unsigned char emitterNumber;

  /** indicates the beam for which the blanking sector values are applicable. */
  unsigned char beamNumber;

  /** indicate if blanking sector data have changed since issuance of the last Blanking Sector attribute record for this beam, if the Blanking Sector attribute record beam has ceased */
  unsigned char stateIndicator;

  /** Padding */
  unsigned char padding2;

  /** This field is provided to indicate the left-most azimuth (clockwise in radians) for which emitted power is reduced. This angle is measured in the X-Y plane of the radar's entity coor- dinate system (see 1.4.3). The range of permissible values is 0 to 2PI, with zero pointing in the X- direction.  */
  float leftAzimuth;

  /** Indicate the right-most azimuth (clockwise in radians) for which emitted power is reduced. This angle is measured in the X-Y plane of the radar's entity coordinate system (see 1.4.3). The range of permissible values is 0 to 2PI , with zero pointing in the X- direction. */
  float rightAzimuth;

  /** This field is provided to indicate the lowest elevation (in radians) for which emit- ted power is reduced. This angle is measured positive upward with respect to the X-Y plane of the radar's entity coordinate system (see 1.4.3). The range of permissible values is -PI/2 to PI/2 */
  float lowerElevation;

  /** This field is provided to indicate the highest elevation (in radians) for which emitted power is reduced. This angle is measured positive upward with respect to the X-Y plane of the radar's entitycoordinatesystem(see1.4.3). The range of permissible values is -PI/2 to PI/2 */
  float upperElevation;

  /** This field shall specify the residual effective radiated power in the blanking sector in dBm.  */
  float residualPower;

  /** Padding, 32 bits */
  int padding3;

  /** Padding, 32 bits */
  int padding4;

    BlankingSector();
    virtual ~BlankingSector();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


     virtual int getMarshalledSize() const;

     bool operator ==(const BlankingSector& rhs) const;
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
