#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include "global.h"
#include <openssl/aes.h>
#include <openssl/evp.h>
#include "GVWebPage.h"
#include "NotifyGVContactsTable.h"
#include "NotifyGVInbox.h"

class MainWindow : public QObject
{
    Q_OBJECT

public:
    MainWindow(QObject *parent = 0);
    void log (const QString &strText, int level = 10);

private slots:
    void doWork ();
    void setStatus(const QString &strText, int timeout  = 3000);
    void loginCompleted (bool bOk, const QVariantList &varList);
    void logoutCompleted (bool bOk, const QVariantList &);
    void getContactsDone (bool bChanges, bool bOK);
    void inboxChanged ();

private:
    void initLogging ();
    void doLogin ();
    void doLogout ();
    void startTimer ();

    QString baseDir();
    bool checkParams ();
    bool cipher(const QByteArray &byIn, QByteArray &byOut, bool bEncrypt);

private:
    //! Logfile
    QFile           fLogfile;

    // Settings parsed from the ini file
    QString strUser;
    QString strPass;
    QString strMqServer;
    int mqPort;
    QString strMqTopic;

    // Needed by GV webpage
    QString strSelfNumber;

    //! GV Contacts object
    GVContactsTable oContacts;
    //! GV Inbox object
    GVInbox         oInbox;

    QTimer          mainTimer;
};

#endif //_MAINWINDOW_H_
