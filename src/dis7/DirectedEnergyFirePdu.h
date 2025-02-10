#pragma once

#include "EntityType.h"
#include "ClockTime.h"
#include "Vector3Float.h"
#include "StandardVariableSpecification.h"
#include "WarfareFamilyPdu.h"
#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
// Firing of a directed energy weapon shall be communicated by issuing a Directed Energy Fire PDU Section 7.3.4  COMPLETE

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

struct EXPORT_MACRO DirectedEnergyFirePdu : public WarfareFamilyPdu
{
  /** Field shall identify the munition type enumeration for the DE weapon beam, Section 7.3.4  */
  EntityType munitionType;

  /** Field shall indicate the simulation time at start of the shot, Section 7.3.4  */
  ClockTime shotStartTime;

  /** Field shall indicate the current cumulative duration of the shot, Section 7.3.4  */
  float commulativeShotTime;

  /** Field shall identify the location of the DE weapon aperture/emitter, Section 7.3.4  */
  Vector3Float ApertureEmitterLocation;

  /** Field shall identify the beam diameter at the aperture/emitter, Section 7.3.4  */
  float apertureDiameter;

  /** Field shall identify the emissions wavelength in units of meters, Section 7.3.4  */
  float wavelength;

  /** Field shall identify the current peak irradiance of emissions in units of Watts per square meter, Section 7.3.4  */
  float peakIrradiance;

  /** field shall identify the current pulse repetition frequency in units of cycles per second (Hertz), Section 7.3.4  */
  float pulseRepetitionFrequency;

  /** field shall identify the pulse width emissions in units of seconds, Section 7.3.4 */
  int pulseWidth;

  /** 16bit Boolean field shall contain various flags to indicate status information needed to process a DE, Section 7.3.4  */
  int flags;

  /** Field shall identify the pulse shape and shall be represented as an 8-bit enumeration, Section 7.3.4  */
  char pulseShape;

  /** padding, Section 7.3.4  */
  unsigned char padding1;

  /** padding, Section 7.3.4  */
  unsigned int padding2;

  /** padding, Section 7.3.4  */
  unsigned short padding3;

  /** Field shall specify the number of DE records, Section 7.3.4  */
  unsigned short numberOfDERecords;

  /** Fields shall contain one or more DE records, records shall conform to the variable record format (Section6.2.82), Section 7.3.4 */
  StandardVariableSpecification dERecords;

    DirectedEnergyFirePdu();
    virtual ~DirectedEnergyFirePdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


     virtual int getMarshalledSize() const;

     bool operator ==(const DirectedEnergyFirePdu& rhs) const;
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
