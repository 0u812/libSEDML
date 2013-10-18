/**
 * @file:   SedRepeatedTask.cpp
 * @brief:  Implementation of the SedRepeatedTask class
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


#include <sedml/SedRepeatedTask.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedRepeatedTask with the given level, version, and package version.
 */
SedRepeatedTask::SedRepeatedTask (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mRange ("")
	, mResetModel (false)
	, mIsSetResetModel (false)
	, mRange (level, version)
	, mTaskChange (level, version)
	, mSubTask (level, version)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new SedRepeatedTask with the given SedNamespaces object.
 */
SedRepeatedTask::SedRepeatedTask (SedNamespaces* sedns)
	: SedBase(sedns)
	, mRange ("")
	, mResetModel (false)
	, mIsSetResetModel (false)
	, mRange (sedns)
	, mTaskChange (sedns)
	, mSubTask (sedns)

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for SedRepeatedTask.
 */
SedRepeatedTask::SedRepeatedTask (const SedRepeatedTask& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mRange  = orig.mRange;
		mResetModel  = orig.mResetModel;
		mIsSetResetModel  = orig.mIsSetResetModel;
		mRange  = orig.mRange;
		mTaskChange  = orig.mTaskChange;
		mSubTask  = orig.mSubTask;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for SedRepeatedTask.
 */
SedRepeatedTask&
SedRepeatedTask::operator=(const SedRepeatedTask& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mRange  = rhs.mRange;
		mResetModel  = rhs.mResetModel;
		mIsSetResetModel  = rhs.mIsSetResetModel;
		mRange  = rhs.mRange;
		mTaskChange  = rhs.mTaskChange;
		mSubTask  = rhs.mSubTask;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for SedRepeatedTask.
 */
SedRepeatedTask*
SedRepeatedTask::clone () const
{
	return new SedRepeatedTask(*this);
}


/*
 * Destructor for SedRepeatedTask.
 */
SedRepeatedTask::~SedRepeatedTask ()
{
}


/*
 * Returns the value of the "range" attribute of this SedRepeatedTask.
 */
const std::string&
SedRepeatedTask::getRange() const
{
	return mRange;
}


/*
 * Returns the value of the "resetModel" attribute of this SedRepeatedTask.
 */
const bool
SedRepeatedTask::getResetModel() const
{
	return mResetModel;
}


/*
 * Returns true/false if range is set.
 */
bool
SedRepeatedTask::isSetRange() const
{
	return (mRange.empty() == false);
}


/*
 * Returns true/false if resetModel is set.
 */
bool
SedRepeatedTask::isSetResetModel() const
{
	return mIsSetResetModel;
}


/*
 * Sets range and returns value indicating success.
 */
int
SedRepeatedTask::setRange(const std::string& range)
{
	if (&(range) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else if (!(SyntaxChecker::isValidInternalSId(range)))
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mRange = range;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Sets resetModel and returns value indicating success.
 */
int
SedRepeatedTask::setResetModel(bool resetModel)
{
	mResetModel = resetModel;
	mIsSetResetModel = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets range and returns value indicating success.
 */
int
SedRepeatedTask::unsetRange()
{
	mRange.erase();

	if (mRange.empty() == true)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		return LIBSEDML_OPERATION_FAILED;
	}
}


/*
 * Unsets resetModel and returns value indicating success.
 */
int
SedRepeatedTask::unsetResetModel()
{
	mResetModel = false;
	mIsSetResetModel = false;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the  "SedListOfRanges" in this SedRepeatedTask object.
 */
const SedListOfRanges*
SedRepeatedTask::getListOfRanges() const
{
	return &mRange;
}


/*
 * Removes the nth Range from the SedListOfRanges.
 */
SedRange*
SedRepeatedTask::removeRange(unsigned int n)
{
	return mRange.remove(n);
}


/*
 * Removes the a Range with given id from the SedListOfRanges.
 */
SedRange*
SedRepeatedTask::removeRange(const std::string& sid)
{
	return mRange.remove(sid);
}


/*
 * Return the nth Range in the SedListOfRanges within this SedRepeatedTask.
 */
SedRange*
SedRepeatedTask::getRange(unsigned int n)
{
	return mRange.get(n);
}


/*
 * Return the nth Range in the SedListOfRanges within this SedRepeatedTask.
 */
const SedRange*
SedRepeatedTask::getRange(unsigned int n) const
{
	return mRange.get(n);
}


/*
 * Return a Range from the SedListOfRanges by id.
 */
SedRange*
SedRepeatedTask::getRange(const std::string& sid)
{
	return mRange.get(sid);
}


/*
 * Return a Range from the SedListOfRanges by id.
 */
const SedRange*
SedRepeatedTask::getRange(const std::string& sid) const
{
	return mRange.get(sid);
}


/**
 * Adds a copy the given "SedRange" to this SedRepeatedTask.
 *
 * @param sr; the SedRange object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedRepeatedTask::addRange(const SedRange* sr)
{
	if(sr == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mRange.append(sr);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedRange objects in this SedRepeatedTask.
 *
 * @return the number of SedRange objects in this SedRepeatedTask
 */
unsigned int 
SedRepeatedTask::getNumRanges() const
{
	return mRange.size();
}

/**
 * Creates a new SedUniformRange object, adds it to this SedRepeatedTasks
 * SedRepeatedTask and returns the SedUniformRange object created. 
 *
 * @return a new SedUniformRange object instance
 *
 * @see addUniformRange(const SedRange* sr)
 */
SedUniformRange* 
SedRepeatedTask::createUniformRange()
{
	SedUniformRange *temp = new SedUniformRange();
	if (temp != NULL) mRange.appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedVectorRange object, adds it to this SedRepeatedTasks
 * SedRepeatedTask and returns the SedVectorRange object created. 
 *
 * @return a new SedVectorRange object instance
 *
 * @see addVectorRange(const SedRange* sr)
 */
SedVectorRange* 
SedRepeatedTask::createVectorRange()
{
	SedVectorRange *temp = new SedVectorRange();
	if (temp != NULL) mRange.appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedFunctionalRange object, adds it to this SedRepeatedTasks
 * SedRepeatedTask and returns the SedFunctionalRange object created. 
 *
 * @return a new SedFunctionalRange object instance
 *
 * @see addFunctionalRange(const SedRange* sr)
 */
SedFunctionalRange* 
SedRepeatedTask::createFunctionalRange()
{
	SedFunctionalRange *temp = new SedFunctionalRange();
	if (temp != NULL) mRange.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfTaskChanges" in this SedRepeatedTask object.
 */
const SedListOfTaskChanges*
SedRepeatedTask::getListOfTaskChanges() const
{
	return &mTaskChange;
}


/*
 * Removes the nth TaskChange from the SedListOfTaskChanges.
 */
SedSetValue*
SedRepeatedTask::removeTaskChange(unsigned int n)
{
	return mTaskChange.remove(n);
}


/*
 * Removes the a TaskChange with given id from the SedListOfTaskChanges.
 */
SedSetValue*
SedRepeatedTask::removeTaskChange(const std::string& sid)
{
	return mTaskChange.remove(sid);
}


/*
 * Return the nth TaskChange in the SedListOfTaskChanges within this SedRepeatedTask.
 */
SedSetValue*
SedRepeatedTask::getTaskChange(unsigned int n)
{
	return mTaskChange.get(n);
}


/*
 * Return the nth TaskChange in the SedListOfTaskChanges within this SedRepeatedTask.
 */
const SedSetValue*
SedRepeatedTask::getTaskChange(unsigned int n) const
{
	return mTaskChange.get(n);
}


/*
 * Return a TaskChange from the SedListOfTaskChanges by id.
 */
SedSetValue*
SedRepeatedTask::getTaskChange(const std::string& sid)
{
	return mTaskChange.get(sid);
}


/*
 * Return a TaskChange from the SedListOfTaskChanges by id.
 */
const SedSetValue*
SedRepeatedTask::getTaskChange(const std::string& sid) const
{
	return mTaskChange.get(sid);
}


/**
 * Adds a copy the given "SedSetValue" to this SedRepeatedTask.
 *
 * @param ssv; the SedSetValue object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedRepeatedTask::addTaskChange(const SedSetValue* ssv)
{
	if(ssv == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mTaskChange.append(ssv);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedSetValue objects in this SedRepeatedTask.
 *
 * @return the number of SedSetValue objects in this SedRepeatedTask
 */
unsigned int 
SedRepeatedTask::getNumTaskChanges() const
{
	return mTaskChange.size();
}

/**
 * Creates a new SedSetValue object, adds it to this SedRepeatedTasks
 * SedRepeatedTask and returns the SedSetValue object created. 
 *
 * @return a new SedSetValue object instance
 *
 * @see addSedSetValue(const SedSetValue* ssv)
 */
SedSetValue* 
SedRepeatedTask::createTaskChange()
{
	SedSetValue *temp = new SedSetValue();
	if (temp != NULL) mTaskChange.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfSubTasks" in this SedRepeatedTask object.
 */
const SedListOfSubTasks*
SedRepeatedTask::getListOfSubTasks() const
{
	return &mSubTask;
}


/*
 * Removes the nth SubTask from the SedListOfSubTasks.
 */
SedSubTask*
SedRepeatedTask::removeSubTask(unsigned int n)
{
	return mSubTask.remove(n);
}


/*
 * Removes the a SubTask with given id from the SedListOfSubTasks.
 */
SedSubTask*
SedRepeatedTask::removeSubTask(const std::string& sid)
{
	return mSubTask.remove(sid);
}


/*
 * Return the nth SubTask in the SedListOfSubTasks within this SedRepeatedTask.
 */
SedSubTask*
SedRepeatedTask::getSubTask(unsigned int n)
{
	return mSubTask.get(n);
}


/*
 * Return the nth SubTask in the SedListOfSubTasks within this SedRepeatedTask.
 */
const SedSubTask*
SedRepeatedTask::getSubTask(unsigned int n) const
{
	return mSubTask.get(n);
}


/*
 * Return a SubTask from the SedListOfSubTasks by id.
 */
SedSubTask*
SedRepeatedTask::getSubTask(const std::string& sid)
{
	return mSubTask.get(sid);
}


/*
 * Return a SubTask from the SedListOfSubTasks by id.
 */
const SedSubTask*
SedRepeatedTask::getSubTask(const std::string& sid) const
{
	return mSubTask.get(sid);
}


/**
 * Adds a copy the given "SedSubTask" to this SedRepeatedTask.
 *
 * @param sst; the SedSubTask object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedRepeatedTask::addSubTask(const SedSubTask* sst)
{
	if(sst == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mSubTask.append(sst);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedSubTask objects in this SedRepeatedTask.
 *
 * @return the number of SedSubTask objects in this SedRepeatedTask
 */
unsigned int 
SedRepeatedTask::getNumSubTasks() const
{
	return mSubTask.size();
}

/**
 * Creates a new SedSubTask object, adds it to this SedRepeatedTasks
 * SedRepeatedTask and returns the SedSubTask object created. 
 *
 * @return a new SedSubTask object instance
 *
 * @see addSedSubTask(const SedSubTask* sst)
 */
SedSubTask* 
SedRepeatedTask::createSubTask()
{
	SedSubTask *temp = new SedSubTask();
	if (temp != NULL) mSubTask.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
SedRepeatedTask::getElementName () const
{
	static const string name = "repeatedTask";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedRepeatedTask::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	if (name == "listOfRanges")
	{
		object = &mRange;
	}

	if (name == "listOfTaskChanges")
	{
		object = &mTaskChange;
	}

	if (name == "listOfSubTasks")
	{
		object = &mSubTask;
	}

	connectToChild();

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedRepeatedTask::connectToChild ()
{
	SedBase::connectToChild();

	mRange.connectToParent(this);
	mTaskChange.connectToParent(this);
	mSubTask.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedRepeatedTask::getTypeCode () const
{
	return SEDML_TASK_REPEATEDTASK;
}


/*
 * check if all the required attributes are set
 */
bool
SedRepeatedTask::hasRequiredAttributes () const
{
	bool allPresent = true;

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
SedRepeatedTask::hasRequiredElements () const
{
	bool allPresent = true;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
SedRepeatedTask::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
	if (getNumRanges() > 0)
	{
		mRange.write(stream);
	}
	if (getNumTaskChanges() > 0)
	{
		mTaskChange.write(stream);
	}
	if (getNumSubTasks() > 0)
	{
		mSubTask.write(stream);
	}
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedRepeatedTask::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedRepeatedTask::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
	mRange.setSedDocument(d);
	mTaskChange.setSedDocument(d);
	mSubTask.setSedDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedRepeatedTask::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("range");
	attributes.add("resetModel");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedRepeatedTask::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedBase::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

	//
	// range SIdRef   ( use = "optional" )
	//
	assigned = attributes.readInto("range", mRange, getErrorLog(), false);

	if (assigned == true)
	{
		// check string is not empty and correct syntax

		if (mRange.empty() == true)
		{
			logEmptyString(mRange, getLevel(), getVersion(), "<SedRepeatedTask>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mRange) == false)
		{
			logError(SedInvalidIdSyntax);
		}
	}

	//
	// resetModel bool   ( use = "optional" )
	//
	mIsSetResetModel = attributes.readInto("resetModel", mResetModel, getErrorLog(), false);

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedRepeatedTask::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetRange() == true)
		stream.writeAttribute("range", getPrefix(), mRange);

	if (isSetResetModel() == true)
		stream.writeAttribute("resetModel", getPrefix(), mResetModel);

}


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedRepeatedTask_t *
SedRepeatedTask_create(unsigned int level, unsigned int version)
{
	return new SedRepeatedTask(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedRepeatedTask_free(SedRepeatedTask_t * srt)
{
	if (srt != NULL)
		delete srt;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedRepeatedTask_t *
SedRepeatedTask_clone(SedRepeatedTask_t * srt)
{
	if (srt != NULL)
	{
		return static_cast<SedRepeatedTask_t*>(srt->clone());
	}
	else
	{
		return NULL;
	}
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedRepeatedTask_getRange(SedRepeatedTask_t * srt)
{
	if (srt == NULL)
		return NULL;

	return srt->getRange().empty() ? NULL : safe_strdup(srt->getRange().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_getResetModel(SedRepeatedTask_t * srt)
{
	return (srt != NULL) ? static_cast<int>(srt->getResetModel()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_isSetRange(SedRepeatedTask_t * srt)
{
	return (srt != NULL) ? static_cast<int>(srt->isSetRange()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_isSetResetModel(SedRepeatedTask_t * srt)
{
	return (srt != NULL) ? static_cast<int>(srt->isSetResetModel()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_setRange(SedRepeatedTask_t * srt, const char * range)
{
	return (srt != NULL) ? srt->setRange(range) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_setResetModel(SedRepeatedTask_t * srt, int resetModel)
{
	return (srt != NULL) ? srt->setResetModel(resetModel) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_unsetRange(SedRepeatedTask_t * srt)
{
	return (srt != NULL) ? srt->unsetRange() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_unsetResetModel(SedRepeatedTask_t * srt)
{
	return (srt != NULL) ? srt->unsetResetModel() : LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedRepeatedTask_addRange(SedRepeatedTask_t * srt, SedRange_t * sr)
{
	return  (srt != NULL) ? srt->addRange(sr) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedUniformRange_t *
SedRepeatedTask_createUniformRange(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->createUniformRange() : NULL;
}

LIBSEDML_EXTERN
SedVectorRange_t *
SedRepeatedTask_createVectorRange(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->createVectorRange() : NULL;
}

LIBSEDML_EXTERN
SedFunctionalRange_t *
SedRepeatedTask_createFunctionalRange(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->createFunctionalRange() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedRepeatedTask_getSedListOfRanges(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? (SedListOf_t *)srt->getListOfRanges() : NULL;
}

LIBSEDML_EXTERN
SedRange_t *
SedRepeatedTask_getRange(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->getRange(n) : NULL;
}

LIBSEDML_EXTERN
SedRange_t *
SedRepeatedTask_getRangeById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->getRange(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumRanges(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->getNumRanges() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedRange_t *
SedRepeatedTask_removeRange(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->removeRange(n) : NULL;
}

LIBSEDML_EXTERN
SedRange_t *
SedRepeatedTask_removeRangeById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->removeRange(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedRepeatedTask_addTaskChange(SedRepeatedTask_t * srt, SedSetValue_t * ssv)
{
	return  (srt != NULL) ? srt->addTaskChange(ssv) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_createTaskChange(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->createTaskChange() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedRepeatedTask_getSedListOfTaskChanges(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? (SedListOf_t *)srt->getListOfTaskChanges() : NULL;
}

LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_getTaskChange(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->getTaskChange(n) : NULL;
}

LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_getTaskChangeById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->getTaskChange(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumTaskChanges(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->getNumTaskChanges() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_removeTaskChange(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->removeTaskChange(n) : NULL;
}

LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_removeTaskChangeById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->removeTaskChange(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedRepeatedTask_addSubTask(SedRepeatedTask_t * srt, SedSubTask_t * sst)
{
	return  (srt != NULL) ? srt->addSubTask(sst) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_createSubTask(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->createSubTask() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedRepeatedTask_getSedListOfSubTasks(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? (SedListOf_t *)srt->getListOfSubTasks() : NULL;
}

LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_getSubTask(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->getSubTask(n) : NULL;
}

LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_getSubTaskById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->getSubTask(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumSubTasks(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->getNumSubTasks() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_removeSubTask(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->removeSubTask(n) : NULL;
}

LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_removeSubTaskById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->removeSubTask(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_hasRequiredAttributes(SedRepeatedTask_t * srt)
{
	return (srt != NULL) ? static_cast<int>(srt->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_hasRequiredElements(SedRepeatedTask_t * srt)
{
	return (srt != NULL) ? static_cast<int>(srt->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


