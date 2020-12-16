#ifndef ALEXEVALLOG_H
#define ALEXEVALLOG_H
#include <QString>
#include <QTextStream>

class AlexEvalLogStream;

class AlexEvalLog
{

    public:
        AlexEvalLog();
//        AlexEvalLogStream stream(AlexEvalLog *inst = instance);
        inline static AlexEvalLog* getInstance()  { return instance; }
        static void error(const QString& message);
        static void warning(const QString& message);
        static void text(const QString& message);

    protected:
        static AlexEvalLog* instance;

        virtual void intLogError(const QString& message)=0;
        virtual void intLogWarning(const QString& message)=0;
        virtual void intLogText(const QString& message)=0;
};



class AlexEvalLogStream
{
    QString buffer;
    QTextStream ts;
    AlexEvalLog *instance;
public:
    AlexEvalLogStream(AlexEvalLog *instance);
    ~AlexEvalLogStream();

    inline AlexEvalLogStream &maybeSpace() { ts << ' '; return *this; }
//    inline AlexEvalLogStream &maybeSpace() { ts << ' '; buffer.clear(); return *this; }
    inline AlexEvalLogStream &operator<<(QChar t) { ts << '\'' << t << '\''; return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(QBool t) { ts << (bool(t != 0) ? "true" : "false"); return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(bool t) { ts << (t ? "true" : "false"); return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(char t) { ts << t; return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(signed short t) { ts << t; return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(unsigned short t) { ts << t; return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(signed int t) { ts << t; return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(unsigned int t) { ts << t; return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(signed long t) { ts << t; return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(unsigned long t) { ts << t; return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(qint64 t)
        { ts << QString::number(t); return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(quint64 t)
        { ts << QString::number(t); return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(float t) { ts << t; return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(double t) { ts << t; return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(const char* t) { ts << QString::fromAscii(t); return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(const QString & t) { ts << '\"' << t  << '\"'; return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(const QStringRef & t) { return operator<<(t.toString()); }
    inline AlexEvalLogStream &operator<<(const QLatin1String &t) { ts << '\"'  << t.latin1() << '\"'; return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(const QByteArray & t) { ts  << '\"' << t << '\"'; return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(const void * t) { ts << t; return maybeSpace(); }
    inline AlexEvalLogStream &operator<<(QTextStreamFunction f) { ts << f; return *this;}
};

#endif // ALEXEVALLOG_H



