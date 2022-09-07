#include "Childwindow.h"

ChildWindow::ChildWindow()
{
    //在关闭时将窗口释放，不占用资源
    this->setAttribute(Qt::WA_DeleteOnClose);
    //设置该子窗体未被保存过
    this->isUntitled=true;
    connect(document(),SIGNAL(contentsChanged()),this,SLOT(documentWasModified()));
}
ChildWindow::~ChildWindow(){

}
void ChildWindow::newFile(){
    //设置窗口编号（每一个均+1）
    static int Number=1;
    //文档未被保存过
    isUntitled=true;
    //以文档标题作为相对路径地址。
    curFile=tr("文档 %1").arg(Number++);//更改文档标题
    qDebug()<<"这里是新建文件时的curFile"<<curFile;
    this->setWindowTitle(curFile+"[*]");
}
void ChildWindow::documentWasModified()
{
    setWindowModified(document()->isModified());
}


QString ChildWindow::userFriendlyCurrentFile()
{
    return strippedName(curFile);
}
//获取绝对路径
QString ChildWindow::strippedName(const QString &fullFileName){
    return QFileInfo(fullFileName).fileName();
}


void ChildWindow::closeEvent(QCloseEvent *event)
{
    if(wonSave())
        //成功保存，接受关闭事件
        event->accept();
    else
        //否则不接受关闭事件
        event->ignore();
}
bool ChildWindow::wonSave(){
    //文档没有任何修改，即已经成功保存
    if(!document()->isModified())
        return true;//同意关闭
    QMessageBox::StandardButton ans;
    ans=QMessageBox::warning(this,"警告",QString("文档'%1'已被修改,保存吗?").arg(userFriendlyCurrentFile()),QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    //如果用户选择“保存”，返回true，执行save()函数
    if(ans==QMessageBox::Save)
        return save();//同意保存，即为同意关闭
    //如果用户选择“取消"，返回false
    else if(ans==QMessageBox::Cancel)
        return false;//不同意关闭
    //用户选择“不保存”，返回true;
    else
        return true;//同意关闭
}
bool ChildWindow::save(){
    //如果文件还未保存过（无保存路径），则执行“另存为”
    if(isUntitled)
        return saveAnother();
    //否则，直接保存到当前路径
    else
        return saveFile(curFile);
}
bool ChildWindow::saveAnother(){
    //默认保存为html文档
    QString fileName=QFileDialog::getSaveFileName(this,"另存为",curFile,"HTML文档(*.htm *.html）;;所有文件（*.*）");
    qDebug()<<"这里是另存为的路径"<<fileName;
    //如果用户选择了“取消”，则保存失败，返回false
    if(fileName.isEmpty())
        return false;
    //选择“确定”，则以用户选择的路径saveFile
    return saveFile(fileName);
}

bool ChildWindow::saveFile(QString fileName){
    // 如果保存时没有指定拓展名，则默认保存为html文档
    if (!(fileName.endsWith(".htm", Qt::CaseInsensitive) || fileName.endsWith(".html", Qt::CaseInsensitive))) {
        fileName += ".html";
    }
    QTextDocumentWriter writer(fileName);
    qDebug()<<this->document();
    //将该文档写入指定路径，写入成功则返回true
    bool flag=writer.write(this->document());
    //如果写入成功，则该文档当前路径需要更新。并且需要更新其为保存的状态
    if(flag)
        setCurrentFile(fileName);
    else {
        QMessageBox::warning(this,"警告","保存失败！");
    }
    return flag;
}
void ChildWindow::setCurrentFile(const QString &fileName)
{
    curFile = QFileInfo(fileName).canonicalFilePath();
    qDebug()<<"这里是setCurrentFile的路径"<<curFile;

    //使未保存的*消失
    isUntitled = false;
    document()->setModified(false);
    setWindowModified(false);
    setWindowTitle(userFriendlyCurrentFile() + "[*]");
}


bool ChildWindow::loadFile(const QString &fileName)
{
    if (!fileName.isEmpty())
    {
        if (!QFile::exists(fileName))
            return false;
        QFile file(fileName);
        if (!file.open(QFile::ReadOnly))
            return false;

        QByteArray data = file.readAll();
        QTextCodec *codec = Qt::codecForHtml(data);
        QString str = codec->toUnicode(data);
        if (Qt::mightBeRichText(str)) {
            this->setHtml(str);
        } else {
            str = QString::fromLocal8Bit(data);
            this->setPlainText(str);
        }
        setCurrentFile(fileName);
        connect(document(), SIGNAL(contentsChanged()),this, SLOT(documentWasModified()));
        return true;
    }
    else
        return false;
}

void ChildWindow::fontFormat(const QTextCharFormat &format){
    QTextCursor cursor=this->textCursor();
    if(!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
    this->mergeCurrentCharFormat(format);
}
