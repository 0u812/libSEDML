/**
 * @file:   SedReport.cpp
 * @brief:  Implementation of the SedReport class
 * @author: Frank T. Bergmann
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SEDML, and the latest version of libSEDML.
 *
 * Copyright (c) 2013, Frank T. Bergmann  
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met: 
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ------------------------------------------------------------------------ -->
 */


#include <sedml/SedReport.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedReport with the given level, version, and package version.
 */
SedReport::SedReport (unsigned int level, unsigned int version)
	: SedOutput(level, version)
	, mDataSet (level, version)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new SedReport with the given SedNamespaces object.
 */
SedReport::SedReport (SedNamespaces* sedns)
	: SedOutput(sedns)
	, mDataSet (sedns)

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for SedReport.
 */
SedReport::SedReport (const SedReport& orig)
	: SedOutput(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mDataSet  = orig.mDataSet;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for SedReport.
 */
SedReport&
SedReport::operator=(const SedReport& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedOutput::operator=(rhs);
		mDataSet  = rhs.mDataSet;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for SedReport.
 */
SedReport*
SedReport::clone () const
{
	return new SedReport(*this);
}


/*
 * Destructor for SedReport.
 */
SedReport::~SedReport ()
{
}


/*
 * Returns the  "SedListOfSedDataSets" in this SedReport object.
 */
const SedListOfSedDataSets*
SedReport::getListOfSedDataSets() const
{
	return &mDataSet;
}


/*
 * Removes the nth SedDataSet from the SedListOfSedDataSets.
 */
SedDataSet*
SedReport::removeSedDataSet(unsigned int n)
{
	return mDataSet.remove(n);
}


/*
 * Removes the a SedDataSet with given id from the SedListOfSedDataSets.
 */
SedDataSet*
SedReport::removeSedDataSet(const std::string& sid)
{
	return mDataSet.remove(sid);
}


/*
 * Return the nth SedDataSet in the SedListOfSedDataSets within this SedReport.
 */
SedDataSet*
SedReport::getSedDataSet(unsigned int n)
{
	return mDataSet.get(n);
}


/*
 * Return the nth SedDataSet in the SedListOfSedDataSets within this SedReport.
 */
const SedDataSet*
SedReport::getSedDataSet(unsigned int n) const
{
	return mDataSet.get(n);
}


/*
 * Return a SedDataSet from the SedListOfSedDataSets by id.
 */
SedDataSet*
SedReport::getSedDataSet(const std::string& sid)
{
	return mDataSet.get(sid);
}


/*
 * Return a SedDataSet from the SedListOfSedDataSets by id.
 */
const SedDataSet*
SedReport::getSedDataSet(const std::string& sid) const
{
	return mDataSet.get(sid);
}


/**
 * Adds a copy the given "SedDataSet" to this SedReport.
 *
 * @param sds; the SedDataSet object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedReport::addSedDataSet(const SedDataSet* sds)
{
	if(sds == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mDataSet.append(sds);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedDataSet objects in this SedReport.
 *
 * @return the number of SedDataSet objects in this SedReport
 */
unsigned int 
SedReport::getNumSedDataSets() const
{
	return mDataSet.size();
}

/**
 * Creates a new SedDataSet object, adds it to this SedReports
 * SedReport and returns the SedDataSet object created. 
 *
 * @return a new SedDataSet object instance
 *
 * @see addSedDataSet(const SedDataSet* sds)
 */
SedDataSet* 
SedReport::createSedDataSet()
{
	SedDataSet *temp = new SedDataSet();
	if (temp != NULL) mDataSet.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
SedReport::getElementName () const
{
	static const string name = "report";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedReport::createObject(XMLInputStream& stream)
{
	SedBase* object = SedOutput::createObject(stream);

	const string& name   = stream.peek().getName();

	SedOutput::connectToChild();

	if (name == "listOfDataSets")
	{
		object = &mDataSet;
	}

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedReport::connectToChild ()
{
	SedOutput::connectToChild();

	mDataSet.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedReport::getTypeCode () const
{
	return SEDML_OUTPUT_REPORT;
}


/*
 * check if all the required attributes are set
 */
bool
SedReport::hasRequiredAttributes () const
{
	bool allPresent = SedOutput::hasRequiredAttributes();

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
SedReport::hasRequiredElements () const
{
	bool allPresent = SedOutput::hasRequiredElements();

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
SedReport::writeElements (XMLOutputStream& stream) const
{
	SedOutput::writeElements(stream);
	if (getNumSedDataSets() > 0)
	{
		mDataSet.write(stream);
	}
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedReport::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedReport::setSedDocument (SedDocument* d)
{
	SedOutput::setSedDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedReport::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedOutput::addExpectedAttributes(attributes);

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedReport::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedOutput::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedReport::writeAttributes (XMLOutputStream& stream) const
{
	SedOutput::writeAttributes(stream);

}


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedReport_t *
SedReport_create(unsigned int level, unsigned int version)
{
	return new SedReport(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedReport_free(SedReport_t * sr)
{
	if (sr != NULL)
		delete sr;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedReport_t *
SedReport_clone(SedReport_t * sr)
{
	if (sr != NULL)
	{
		return static_cast<SedReport_t*>(sr->clone());
	}
	else
	{
		return NULL;
	}
}


LIBSEDML_EXTERN
int
SedReport_addSedDataSet(SedReport_t * sr, SedDataSet_t * sds)
{
	return  (sr != NULL) ? sr->addSedDataSet(sds) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedDataSet_t *
SedReport_createSedDataSet(SedReport_t * sr)
{
	return  (sr != NULL) ? sr->createSedDataSet() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedReport_getSedListOfSedDataSets(SedReport_t * sr)
{
	return  (sr != NULL) ? (SedListOf_t *)sr->getListOfSedDataSets() : NULL;
}

LIBSEDML_EXTERN
SedDataSet_t *
SedReport_getSedDataSet(SedReport_t * sr, unsigned int n)
{
	return  (sr != NULL) ? sr->getSedDataSet(n) : NULL;
}

LIBSEDML_EXTERN
SedDataSet_t *
SedReport_getSedDataSetById(SedReport_t * sr, const char * sid)
{
	return  (sr != NULL) ? sr->getSedDataSet(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedReport_getNumSedDataSets(SedReport_t * sr)
{
	return  (sr != NULL) ? sr->getNumSedDataSets() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedDataSet_t *
SedReport_removeSedDataSet(SedReport_t * sr, unsigned int n)
{
	return  (sr != NULL) ? sr->removeSedDataSet(n) : NULL;
}

LIBSEDML_EXTERN
SedDataSet_t *
SedReport_removeSedDataSetById(SedReport_t * sr, const char * sid)
{
	return  (sr != NULL) ? sr->removeSedDataSet(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedReport_hasRequiredAttributes(SedReport_t * sr)
{
	return (sr != NULL) ? static_cast<int>(sr->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedReport_hasRequiredElements(SedReport_t * sr)
{
	return (sr != NULL) ? static_cast<int>(sr->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END

