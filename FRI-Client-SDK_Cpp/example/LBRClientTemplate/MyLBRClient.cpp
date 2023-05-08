/**

The following license terms and conditions apply, unless a redistribution
agreement or other license is obtained by KUKA Deutschland GmbH, Augsburg, Germany.

SCOPE

The software �KUKA Sunrise.FRI Client SDK� is targeted to work in
conjunction with the �KUKA Sunrise.FRI� toolkit.
In the following, the term �software� refers to all material directly
belonging to the provided SDK �Software development kit�, particularly source
code, libraries, binaries, manuals and technical documentation.

COPYRIGHT

All Rights Reserved
Copyright (C)  2014-2022 
KUKA Deutschland GmbH
Augsburg, Germany

LICENSE 

Redistribution and use of the software in source and binary forms, with or
without modification, are permitted provided that the following conditions are
met:
a) The software is used in conjunction with KUKA products only. 
b) Redistributions of source code must retain the above copyright notice, this
list of conditions and the disclaimer.
c) Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the disclaimer in the documentation and/or other
materials provided with the distribution. Altered source code of the
redistribution must be made available upon request with the distribution.
d) Modification and contributions to the original software provided by KUKA
must be clearly marked and the authorship must be stated.
e) Neither the name of KUKA nor the trademarks owned by KUKA may be used to
endorse or promote products derived from this software without specific prior
written permission.

DISCLAIMER OF WARRANTY

The Software is provided "AS IS" and "WITH ALL FAULTS," without warranty of
any kind, including without limitation the warranties of merchantability,
fitness for a particular purpose and non-infringement. 
KUKA makes no warranty that the Software is free of defects or is suitable for
any particular purpose. In no event shall KUKA be responsible for loss or
damages arising from the installation or use of the Software, including but
not limited to any indirect, punitive, special, incidental or consequential
damages of any character including, without limitation, damages for loss of
goodwill, work stoppage, computer failure or malfunction, or any and all other
commercial damages or losses. 
The entire risk to the quality and performance of the Software is not borne by
KUKA. Should the Software prove defective, KUKA is not liable for the entire
cost of any service and repair.



\file
\version {2.5}
*/
#include <cstdio>
#include "MyLBRClient.h"

using namespace KUKA::FRI;
//******************************************************************************
MyLBRClient::MyLBRClient()
{
}

//******************************************************************************
MyLBRClient::~MyLBRClient()
{
}
      
//******************************************************************************
void MyLBRClient::onStateChange(ESessionState oldState, ESessionState newState)
{
   LBRClient::onStateChange(oldState, newState);
   // react on state change events
   switch (newState)
   {
      case MONITORING_WAIT:
      {
         break;
      }       
      case MONITORING_READY:
      {
         break;
      }
      case COMMANDING_WAIT:
      {
         break;
      }   
      case COMMANDING_ACTIVE:
      {
         break;
      }   
      default:
      {
         break;
      }
   }
}

//******************************************************************************
void MyLBRClient::monitor()
{
   LBRClient::monitor();
   
   /***************************************************************************/
   /*                                                                         */
   /*   Place user Client Code here                                           */
   /*                                                                         */
   /***************************************************************************/
   
}

//******************************************************************************
void MyLBRClient::waitForCommand()
{
   // In waitForCommand(), the joint values have to be mirrored. Which is done, 
   // by calling the base method.
   LBRClient::waitForCommand();
   
   /***************************************************************************/
   /*                                                                         */
   /*   Place user Client Code here                                           */
   /*                                                                         */
   /***************************************************************************/   
   
}

//******************************************************************************
void MyLBRClient::command()
{
   /***************************************************************************/
   /*                                                                         */
   /*   Place user Client Code here                                           */
   /*                                                                         */
   /***************************************************************************/   
   
   // In command(), the joint angle values have to be set. 
   //robotCommand().setJointPosition( newJointValues );
}
