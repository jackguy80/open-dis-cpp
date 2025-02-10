#pragma once

#include "EntityID.h"
#include "EntityID.h"
#include "IntercomCommunicationsParameters.h"
#include <vector>
#include "RadioCommunicationsFamilyPdu.h"
#include "utils/DataStream.h"
#include "dis6/msLibMacro.h"


namespace DIS
{
// Section 5.3.8.5. Detailed inofrmation about the state of an intercom device and the actions it is requestion         of another intercom device, or the response to a requested action. Required manual intervention to fix the intercom parameters,        which can be of varialbe length. UNFINSISHED

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

#pragma warning(disable: 4251 ) // Disables warning for stl vector template DLL export in msvc

struct EXPORT_MACRO IntercomControlPdu : public RadioCommunicationsFamilyPdu
{
  /** control type */
  unsigned char controlType;

  /** control type */
  unsigned char communicationsChannelType;

  /** Source entity ID */
  EntityID sourceEntityID;

  /** The specific intercom device being simulated within an entity. */
  unsigned char sourceCommunicationsDeviceID;

  /** Line number to which the intercom control refers */
  unsigned char sourceLineID;

  /** priority of this message relative to transmissons from other intercom devices */
  unsigned char transmitPriority;

  /** current transmit state of the line */
  unsigned char transmitLineState;

  /** detailed type requested. */
  unsigned char command;

  /** eid of the entity that has created this intercom channel. */
  EntityID masterEntityID;

  /** specific intercom device that has created this intercom channel */
  unsigned short masterCommunicationsDeviceID;

  /** number of intercom parameters */
  unsigned int intercomParametersLength;

  /** Must be  */
  std::vector<IntercomCommunicationsParameters> intercomParameters;

    IntercomControlPdu();
    virtual ~IntercomControlPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);


     virtual int getMarshalledSize() const;

     bool operator ==(const IntercomControlPdu& rhs) const;
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
