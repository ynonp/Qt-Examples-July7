
#include <QApplication>
#include <QtGui>
#include <QDebug>

class MainWindow : public QMainWindow
{
  public:
    MainWindow();

  protected:
    bool eventFilter(QObject *obj, QEvent *ev);

  private:
    QTextEdit *textEdit;
    QLabel    *bpCounter;
    int        count;
};

MainWindow::MainWindow()
{
  count = 0;
  bpCounter = new QLabel(QString("Backspace Count: %1").arg(count));
  textEdit = new QTextEdit;
  setCentralWidget(textEdit);

  statusBar()->addWidget(bpCounter);
  textEdit->installEventFilter(this);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
  if (obj == textEdit) {
    if (event->type() == QEvent::KeyPress) {
      QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
      if ( keyEvent->key() == Qt::Key_Backspace ) {
        bpCounter->setText(QString("Backspace Count: %1").arg(count++));
      }
    }

    // pass the event to the widget
    return false;
  }
  else {
    // pass the event on to the parent class
    return QMainWindow::eventFilter(obj, event);
  }
}

int main(int argc, char **argv)
{
  QApplication app(argc, argv);

  MainWindow mw;
  mw.show();

  app.exec();
}

