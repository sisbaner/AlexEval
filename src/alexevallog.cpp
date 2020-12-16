#include "alexevallog.h"
#ifdef QT_DEBUG
    #include <QDebug>
#endif
AlexEvalLog* AlexEvalLog::instance=NULL;

AlexEvalLog::AlexEvalLog()
{
//    ts.setString(&buffer,QIODevice::ReadWrite);
    if (!instance) instance=this;
}

void AlexEvalLog::error(const QString &message)
{
#ifdef QT_DEBUG
    qDebug()<<message;
#endif
    if (instance) instance->intLogError(message);
}

void AlexEvalLog::warning(const QString &message)
{
#ifdef QT_DEBUG
    qDebug()<<message;
#endif
    if (instance) instance->intLogWarning(message);
}

void AlexEvalLog::text(const QString &message)
{
#ifdef QT_DEBUG
    qDebug()<<message;
#endif
    if (instance) instance->intLogText(message);
}


AlexEvalLogStream::AlexEvalLogStream(AlexEvalLog *instance)
{
    this->instance=instance;
}

AlexEvalLogStream::~AlexEvalLogStream()
{
    instance->text(buffer);
}


