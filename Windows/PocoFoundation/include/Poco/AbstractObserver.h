//
// AbstractObserver.h
//
// $Id: //poco/1.4/Foundation/include/Poco/AbstractObserver.h#2 $
//
// Library: Foundation
// Package: Notifications
// Module:  NotificationCenter
//
// Definition of the AbstractObserver class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Foundation_AbstractObserver_INCLUDED
#define Foundation_AbstractObserver_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/Notification.h"


namespace Poco {


class Foundation_API AbstractObserver
	/// The base class for all instantiations of
	/// the Observer and NObserver template classes.
{
public:
	AbstractObserver();
	AbstractObserver(const AbstractObserver& observer);
	virtual ~AbstractObserver();
	
	AbstractObserver& operator = (const AbstractObserver& observer);

	virtual void notify(Notification* pNf) const = 0;
	virtual bool equals(const AbstractObserver& observer) const = 0;
	virtual bool accepts(Notification* pNf) const = 0;
	virtual AbstractObserver* clone() const = 0;
	virtual void disable() = 0;
};


} // namespace Poco


#endif // Foundation_AbstractObserver_INCLUDED
