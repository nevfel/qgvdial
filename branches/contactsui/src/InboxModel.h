#ifndef __INBOXMODEL_H__
#define __INBOXMODEL_H__

#include "global.h"
#include <QtSql>

class InboxModel : public QSqlQueryModel
{
public:
    enum InboxFieldRoles {
        IN_TypeRole = Qt::UserRole + 1,
        IN_TimeRole,
        IN_NameRole,
        IN_NumberRole,
        IN_Link,
        IN_TimeDetail,
    };

    InboxModel (QObject * parent = 0);
    QVariant data (const QModelIndex   &index,
                         int            role = Qt::DisplayRole) const;

public:
    static QString type_to_string (GVH_Event_Type Type);
    static GVH_Event_Type string_to_type (const QString &strType);
};

#endif //__INBOXMODEL_H__
