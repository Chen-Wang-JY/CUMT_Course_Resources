#ifndef CHILDWINDOW_H
#define CHILDWINDOW_H

#include <QTextEdit>
#include <QPrinter>
#include <QFile>
#include <QFileInfo>
#include <QCloseEvent>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextDocumentWriter>
#include <QTextCodec>
#include <QtDebug>
#include <QMessageBox>

class ChildWindow : public QTextEdit
{
    Q_OBJECT
public:
    ChildWindow();
    ~ChildWindow();
    void newFile(); //新建
    //当前文件是否被保存到磁盘上的标志
    bool isUntitled;
    //保存当前文件路径
    QString curFile;


    //提取文件名
    QString userFriendlyCurrentFile();
    //返回当前路径
    QString currentFile(){return curFile;}
    bool loadFile(const QString& fileName);
    bool save();
    bool saveAnother();


    void fontFormat(const QTextCharFormat& format);
    void setStyle(int style);
protected:
    //关闭事件
    void closeEvent(QCloseEvent* event);
private:
    //获取较短的绝对路径
    QString strippedName(const QString& fullFileName);
    void setCurrentFile(const QString& fileName);
    bool saveFile(QString fileName);
    bool wonSave();

private slots:
    void documentWasModified();
};

#endif // CHILDWINDOW_H
