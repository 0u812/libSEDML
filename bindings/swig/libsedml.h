/**
 * \file    libsedml.h
 * \brief   Language-independent SWIG includes for wrapping libsedml
 * \author  Ben Bornstein
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libsedml.  Please visit http://sed-ml.org for more
 * information about sedml, and the latest version of libsedml.
 *
 * Copyright (C) 2009-2013 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sed-ml.org/software/libsedml/license.html
 * ---------------------------------------------------------------------- -->*/

#include <sedml/common/libsedml-version.h>
#include <sedml/common/operationReturnValues.h>

#include <sedml/SedTypes.h>

#include "ListWrapper.h"

#include <sbml/SBase.h>
#include <sbml/Model.h>
#include <sbml/SBMLTransforms.h>
#include <sbml/SBMLNamespaces.h>
#include <sbml/annotation/CVTerm.h>
#include <sbml/annotation/Date.h>

#include <sbml/math/MathML.h>
#include <sbml/math/ASTNode.h>
#include <sbml/math/FormulaParser.h>
#include <sbml/math/FormulaFormatter.h>
#include <sbml/math/L3Parser.h>
#include <sbml/math/L3ParserSettings.h>

#include <sbml/xml/XMLAttributes.h>
#include <sbml/xml/XMLConstructorException.h>
#include <sbml/xml/XMLNamespaces.h>
#include <sbml/xml/XMLToken.h>
#include <sbml/xml/XMLNode.h>
#include <sbml/xml/XMLTriple.h>
#include <sbml/xml/XMLOutputStream.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/xml/XMLError.h>
#include <sbml/xml/XMLErrorLog.h>

#include <numl/common/extern.h>
#include <numl/common/libnuml-namespace.h>
#include <numl/common/libnuml-version.h>
#include <numl/common/operationReturnValues.h>

#include <numl/NUMLNamespaces.h>
#include <numl/NUMLReader.h>
#include <numl/NUMLWriter.h>
#include <numl/NUMLTypeCodes.h>
#include <numl/NMBase.h>
#include <numl/NUMLDocument.h>
#include <numl/ResultComponent.h>

#include <numl/Dimension.h>
#include <numl/DimensionDescription.h>

#include <numl/CompositeValue.h>
#include <numl/Tuple.h>
#include <numl/AtomicValue.h>

#include <numl/CompositeDescription.h>
#include <numl/TupleDescription.h>
#include <numl/AtomicDescription.h>

