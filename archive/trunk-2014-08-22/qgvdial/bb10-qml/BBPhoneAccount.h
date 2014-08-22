/*
qgvdial is a cross platform Google Voice Dialer
Copyright (C) 2009-2014  Yuvraaj Kelkar

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

Contact: yuvraaj@gmail.com
*/

#ifndef BBPHONEACCOUNT_H_
#define BBPHONEACCOUNT_H_

#include "global.h"
#include "IPhoneAccount.h"

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
#include <bb/system/phone/Phone>
#endif

class BBPhoneAccount: public IPhoneAccount
{
    Q_OBJECT

private:
    BBPhoneAccount(QObject *parent = 0);

public:
    ~BBPhoneAccount();

    QString id ();
    QString name ();

    bool initiateCall(AsyncTaskToken *task);

    QString getNumber();

private:
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
    bb::system::phone::Phone m_phone;
#endif

    friend class BB10PhoneFactory;
};

#endif /* BBPHONEACCOUNT_H_ */
