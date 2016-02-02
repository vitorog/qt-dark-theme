#include "mainwindow.h"
#include <QApplication>

#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    
    a.setStyle("plastique");
    QFile styleSheet("dark-theme.qss");
    if(!styleSheet.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Failed to read stylesheet file.";
    }else{
        QTextStream in(&styleSheet);
        QString css;
        while(!in.atEnd()){
            css.append(in.readLine());
        }
        a.setStyleSheet(css);
    }

    MainWindow w;
    w.show();

    return a.exec();
}
