/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com - Copyright (C) 2011 Fabian Gerold
*
* This library is open source and may be redistributed and/or modified under  
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
* (at your option) any later version.  The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
* OpenSceneGraph Public License for more details.
*/

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPException.h"
#include "include/IfcFlowDirectionEnum.h"

// TYPE IfcFlowDirectionEnum = ENUMERATION OF	(SOURCE	,SINK	,SOURCEANDSINK	,NOTDEFINED);
IfcFlowDirectionEnum::IfcFlowDirectionEnum() {}
IfcFlowDirectionEnum::~IfcFlowDirectionEnum() {}
shared_ptr<IfcPPObject> IfcFlowDirectionEnum::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcFlowDirectionEnum> copy_self( new IfcFlowDirectionEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcFlowDirectionEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCFLOWDIRECTIONENUM("; }
	if( m_enum == ENUM_SOURCE )
	{
		stream << ".SOURCE.";
	}
	else if( m_enum == ENUM_SINK )
	{
		stream << ".SINK.";
	}
	else if( m_enum == ENUM_SOURCEANDSINK )
	{
		stream << ".SOURCEANDSINK.";
	}
	else if( m_enum == ENUM_NOTDEFINED )
	{
		stream << ".NOTDEFINED.";
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IfcFlowDirectionEnum> IfcFlowDirectionEnum::createObjectFromSTEP( const std::wstring& arg )
{
	// read TYPE
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcFlowDirectionEnum>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcFlowDirectionEnum>(); }
	shared_ptr<IfcFlowDirectionEnum> type_object( new IfcFlowDirectionEnum() );
	if( boost::iequals( arg, L".SOURCE." ) )
	{
		type_object->m_enum = IfcFlowDirectionEnum::ENUM_SOURCE;
	}
	else if( boost::iequals( arg, L".SINK." ) )
	{
		type_object->m_enum = IfcFlowDirectionEnum::ENUM_SINK;
	}
	else if( boost::iequals( arg, L".SOURCEANDSINK." ) )
	{
		type_object->m_enum = IfcFlowDirectionEnum::ENUM_SOURCEANDSINK;
	}
	else if( boost::iequals( arg, L".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcFlowDirectionEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
