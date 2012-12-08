/* Copyright (c) 2010-2012, AOYAMA Kazuharu
 * All rights reserved.
 *
 * This software may be used and distributed according to the terms of
 * the New BSD License, which is incorporated herein by reference.
 */

#include <QThread>
#include "TLog"

/*!
  \class TLog
  \brief The TLog class contains log messages for web application.
*/

TLog::TLog(int pri, const QByteArray &msg)
    : timestamp(QDateTime::currentDateTime()),
      priority(pri),
      pid(QCoreApplication::applicationPid()),
      threadId((qulonglong)QThread::currentThreadId()),
      message(msg)
{ }


QDataStream &operator<<(QDataStream &out, const TLog &log)
{
    out << log.timestamp << log.priority << log.pid << log.threadId << log.message;
    return out;
}


QDataStream &operator>>(QDataStream &in, TLog &log)
{
    in >> log.timestamp >> log.priority >> log.pid >> log.threadId >> log.message;
    return in;
}
