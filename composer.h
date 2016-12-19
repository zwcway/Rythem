#ifndef COMPOSER_H
#define COMPOSER_H

#include <QtGui>
#include <QtNetwork>
#include "proxy/rypipedata.h"
#include <QtGlobal>
#if QT_VERSION >= 0x050000
# include <QtWidgets>
#endif

namespace Ui {
    class Composer;
}

class Composer : public QWidget
{
        Q_OBJECT

    public:
        explicit Composer(QWidget *parent = 0);
        ~Composer();
        void setupProxy(QString host,qint16 port);

    protected:
        void dragEnterEvent(QDragEnterEvent *event);
        void dropEvent(QDropEvent *event);

    private:
        Ui::Composer *ui;

        QNetworkAccessManager *manager;
        RyPipeData_ptr pipeData;

    private slots:
        void onFinished(QNetworkReply *);
        void onSendClicked();

};

#endif // COMPOSER_H
