#include <QRegExp>
#include <QDebug>

int main( int /*argc*/, char* /*argv*/[] ) {

    QStringList qStringList = { "PRA QT SERVE", "3", "Edition 3º", "123", " My 1 Test 2 Ok 3" };

    {
        QRegExp regex( "\\d*" );

        qDebug() << "";
        qDebug() << "EXACT MATCH";
        qDebug() << "";

        for ( const QString& regexInString : qStringList ) {
            qDebug() << regexInString << regex.exactMatch( regexInString );
        }
    }

    {
        QRegExp regex( "\\d" );

        qDebug() << "";
        qDebug() << "CAP";
        qDebug() << "";

        for ( const QString& regexInString : qStringList ) {
            regex.indexIn( regexInString );
            qDebug() << regexInString << regex.cap( 0 );
        }
    }

    {
        qDebug() << "";
        qDebug() << "CAPTURED TEXTS";
        qDebug() << "";

        QRegExp regex( "(\\d+)" );
        QString string = "Offsets: 12 14 99 231 7";
        QStringList result = {};

        int pos = 0;

        while ( ( pos = regex.indexIn( string, pos ) ) != -1 ) {
            result.append( regex.cap( 1 ) );
            pos += regex.matchedLength();
        }

        qDebug() << string << result;
    }

    {
        QRegExp regex( "pra qt serve", Qt::CaseInsensitive );

        qDebug() << "";
        qDebug() << "CASE INSENSITVE";
        qDebug() << "";

        for ( const QString& regexInString : { "PRA QT SERVE", "pra qt serve", "Pra Qt Serve", "PrA qT sErVe" } ) {
            qDebug() << regexInString << regex.exactMatch( regexInString );
        }
    }

    {
        QRegExp regex( "pra qt serve", Qt::CaseInsensitive );

        qDebug() << "";
        qDebug() << "PATTERN";
        qDebug() << "";

        qDebug() << regex.pattern();
    }

}
