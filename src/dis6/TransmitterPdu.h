#pragma once

#include "EntityID.h"
#include "RadioEntityType.h"
#include "Vector3Double.h"
#include "Vector3Float.h"
#include "ModulationType.h"
#include "BeamAntennaPattern.h"
#include <vector>
#include "RadioCommunicationsFamilyPdu.h"
#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
// Section 5.3.8.1. Detailed information about a radio transmitter. This PDU requires manually         written code to complete, since the modulation parameters are of variable length. UNFINISHED

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

#pragma warning(disable: 4251 ) // Disables warning for stl vector template DLL export in msvc

struct EXPORT_MACRO TransmitterPdu : public RadioCommunicationsFamilyPdu
{
  /** ID of the entity that is the source of the communication, ie contains the radio */
  EntityID entityId;

  /** particular radio within an entity */
  unsigned short radioId;

  /** linear accelleration of entity */
  RadioEntityType radioEntityType;

  /** transmit state */
  unsigned char transmitState;

  /** input source */
  unsigned char inputSource;

  /** padding */
  unsigned short padding1;

  /** Location of antenna */
  Vector3Double antennaLocation;

  /** relative location of antenna, in entity coordinates */
  Vector3Float relativeAntennaLocation;

  /** antenna pattern type */
  unsigned short antennaPatternType;

  /** atenna pattern length */
  unsigned short antennaPatternCount;

  /** frequency */
  long frequency;

  /** transmit frequency Bandwidth */
  float transmitFrequencyBandwidth;

  /** transmission power */
  float power;

  /** modulation */
  ModulationType modulationType;

  /** crypto system enumeration */
  unsigned short cryptoSystem;

  /** crypto system key identifer */
  unsigned short cryptoKeyId;

  /** length of modulation parameters in octets */
  unsigned char modulationParameterCount;

  /** padding2 */
  unsigned short padding2;

  /** padding3 */
  unsigned char padding3;

  /** variable length list of modulation parameters */
  std::vector<unsigned short> modulationParametersList;

  /** variable length list of antenna pattern records */
  std::vector<BeamAntennaPattern> antennaPatternList;

    TransmitterPdu();
    virtual ~TransmitterPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


     virtual int getMarshalledSize() const;

     bool operator ==(const TransmitterPdu& rhs) const;
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
