#include <QApplication>
#include <Simulator/simulator.h>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);
    QApplication app(argc, argv);
//    app.setPalette( Qt::darkGray );

#ifdef ANDROID
    app.setApplicationName(argv[0]);
    app.setStyle("macintosh");

    QString tmpString = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QFileInfo tmpFileInfo(QString("%1/%2").arg(tmpString).arg("ecg.hea"));
    QString tmpPath = tmpFileInfo.absoluteFilePath();

    if ( !tmpFileInfo.exists() )
    {
        bool copySuccess = QFile::copy( QString("assets:/ecg.hea"), tmpPath );
        if ( !copySuccess )
        {
            tmpPath.clear();
        }
    }
    tmpFileInfo.setFile(QString("%1/%2").arg(tmpString).arg("ecg.dat"));
    tmpPath = tmpFileInfo.absoluteFilePath();
    if ( !tmpFileInfo.exists() )
    {
        bool copySuccess = QFile::copy( QString("assets:/ecg.dat"), tmpPath );
        if ( !copySuccess )
        {
            tmpPath.clear();
        }
    }
#endif

    Simulator w;
    //w.resize(800,400);
    w.show();
    
    return app.exec();
}
