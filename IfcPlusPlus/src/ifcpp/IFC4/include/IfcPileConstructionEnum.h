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

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPObject.h"
#include "ifcpp/model/IfcPPGlobal.h"

// TYPE IfcPileConstructionEnum = ENUMERATION OF	(CAST_IN_PLACE	,COMPOSITE	,PRECAST_CONCRETE	,PREFAB_STEEL	,USERDEFINED	,NOTDEFINED);
class IFCPP_EXPORT IfcPileConstructionEnum : virtual public IfcPPObject
{
public:
	enum IfcPileConstructionEnumEnum
	{
		ENUM_CAST_IN_PLACE,
		ENUM_COMPOSITE,
		ENUM_PRECAST_CONCRETE,
		ENUM_PREFAB_STEEL,
		ENUM_USERDEFINED,
		ENUM_NOTDEFINED
	};

	IfcPileConstructionEnum();
	IfcPileConstructionEnum( IfcPileConstructionEnumEnum e ) { m_enum = e; }
	~IfcPileConstructionEnum();
	virtual const char* className() const { return "IfcPileConstructionEnum"; }
	virtual shared_ptr<IfcPPObject> getDeepCopy( IfcPPCopyOptions& options );
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
	static shared_ptr<IfcPileConstructionEnum> createObjectFromSTEP( const std::wstring& arg );
	IfcPileConstructionEnumEnum m_enum;
};

