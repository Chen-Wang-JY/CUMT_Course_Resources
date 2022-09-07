#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include "ui_Form_reselection.h"
#include "ui_Form_choseimg.h"
#include "ui_Form_original.h"
#include "ui_Form_records.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    l=new QLabel;
    //默认加载img1.jpg
    flag=1;
    //创建计时器
    timer=new QTimer(this);
    timeRun=false;
    //读取本地记录
    this->readRecords();
    //信号与槽函数连接
    connect(ui->Button_reselection,&QPushButton::clicked,this,&MainWindow::Form_reselection_Open);
    connect(form_reselection.ui->Button_easy,&QPushButton::clicked,this,&MainWindow::Form_reselection_Button_easy);
    connect(form_reselection.ui->Button_hard,&QPushButton::clicked,this,&MainWindow::Form_reselection_Button_hard);
    connect(form_reselection.ui->Button_hell,&QPushButton::clicked,this,&MainWindow::Form_reselection_Button_hell);
    connect(form_reselection.ui->Button_confirm,&QPushButton::clicked,this,&MainWindow::Form_reselection_Button_confirm);
    connect(ui->Button_chooseimg,&QPushButton::clicked,this,&MainWindow::Form_choseimg_Open);
    connect(form_choseimg.ui->Button_1,&QPushButton::clicked,this,&MainWindow::Form_choseimg_Button_1);
    connect(form_choseimg.ui->Button_2,&QPushButton::clicked,this,&MainWindow::Form_choseimg_Button_2);
    connect(form_choseimg.ui->Button_3,&QPushButton::clicked,this,&MainWindow::Form_choseimg_Button_3);
    connect(form_choseimg.ui->Button_4,&QPushButton::clicked,this,&MainWindow::Form_choseimg_Button_4);
    connect(ui->Button_original,&QPushButton::clicked,this,&MainWindow::Form_original_Open);
    connect(ui->Button_local_img,&QPushButton::clicked,this,&MainWindow::chooseLocalImg);
    connect(ui->Button_upset,&QPushButton::clicked,this,&MainWindow::upsetImg);
    connect(timer,&QTimer::timeout,this,&MainWindow::setTime);
    connect(ui->Button_records,&QPushButton::clicked,this,&MainWindow::Form_records_Open);
    connect(form_records.ui->pushButton,&QPushButton::clicked,this,&MainWindow::Zero);
}

MainWindow::~MainWindow()
{
    delete ui;
}



/*-----------------------------------------加载拼图--------------------------------------------*/
void MainWindow::Load(){
    //计时器清零，计步器清零
    timer->stop();
    ui->label_time->setText("00:00:00");
    timeRun=false;
    ui->label_steps->setText("0");

    //根据flag选择加载哪一张图片
    switch (flag) {
    case 1:    pix0.load(":/picture/img1.jpg");break;
    case 2:    pix0.load(":/picture/img2.jpg");break;
    case 3:    pix0.load(":/picture/img3.jpg");break;
    case 4:    pix0.load(":/picture/img4.jpg");break;
    default:   pix0.load(path);break;
    }
    ui->label_picture->setPixmap(pix0);
    ui->label_picture->setVisible(false);

    PC=1;

    //初始化label矩阵、pix矩阵为N*N
    pix=new QPixmap*[N];
    label=new QLabel*[N];
    for(int i=0;i<N;i++){
        pix[i]=new QPixmap[N];
        label[i]=new QLabel[N];
    }

    //将pix、label矩阵的成员赋值
    int width=pix0.width(),height=pix0.height();
    int dx=width/N,dy=height/N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            pix[i][j]=pix0.copy(100+i*dx,100+j*dy,dx,dy);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            label[i][j].setParent(this);
            label[i][j].setScaledContents(true);
            label[i][j].setVisible(true);
            label[i][j].setGeometry(100+i*610/N,100+j*610/N,610/N,610/N);
            label[i][j].setPixmap(pix[i][j]);
            label[i][j].setStyleSheet("border: 2px solid  #666666");
        }
    //打乱图片排序
    this->upsetImg();
    //为label注册事件处理器
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            label[i][j].installEventFilter(this);
}


/*--------------------------------------鼠标左键事件处理----------------------------------------*/
bool MainWindow::eventFilter(QObject *obj, QEvent *event){

    //如果是鼠标点击事件
    if(event->type()==QEvent::MouseButtonPress){
        //根据PC值不同，判断是第一次点击还是第二次点击，实现不同的事件处理
        if(PC==1){
            //如果是刚开始拼图，则开始计时
            if(!timeRun){
                timer->start(1000);
                timeRun=true;
            }

            //遍历所有label，找到当前点击的label，存储，并改变样式表
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                    if(obj==&label[i][j]){
                        index_i=i;
                        index_j=j;
                        pixFormer=label[i][j].pixmap()->copy();
                        label[i][j].setStyleSheet("border: 5px solid  #FFCC00");
                        break;
                    }
            //处理后，将PC值置为2
            PC=2;
            return true;
        }
        else if(ui->RButton_click->isChecked()&&PC==2){
            //遍历，找到当前点击的label，与上一次点击的label交换图片
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                    if(obj==&label[i][j]){
                        pixLatter=label[i][j].pixmap()->copy();
                        label[i][j].setPixmap(pixFormer);
                        label[index_i][index_j].setPixmap(pixLatter);
                        label[index_i][index_j].setStyleSheet("border: 2px solid  #666666");
                        //两次点击图片不同，计步器加一
                        if(i!=index_i||j!=index_j)
                        {
                            int step=ui->label_steps->text().toUtf8().toInt();
                            step++;
                            ui->label_steps->setText(QString::number(step));
                        }
                        break;
                    }
            //处理后，将PC值置为1，并改样式表为初态
            PC=1;
            //判断当前移动后，是否拼图完成
            if(isSuccessful()){
                timer->stop();
                timeRun=false;
                QMessageBox::about(this,"提示","恭喜您，挑战成功！");
                //计算时间、步数
                QString str=ui->label_time->text();
                QStringList strlist=str.split(":");
                int h=strlist[0].toUtf8().toInt();
                int m=strlist[1].toUtf8().toInt();
                int s=strlist[2].toUtf8().toInt();
                double time=h*3600+m*60+s;
                double steps=ui->label_steps->text().toUtf8().toInt();
                //计算得分
                double scores=50*N/time+50*N/steps;
                records.append(scores);
                QMessageBox::about(this,"提示","您的本次得分为："+QString::number(scores));
                //更新本地记录文件
                this->writeRecords();
            }
            return true;
        }
    }
    else if(ui->RButton_drag->isChecked()&&event->type() == QEvent::MouseMove)
    {
        QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);
        l->setVisible(true);
        l->setParent(this);
        int x=610/N;
        QPointF P=mouse->windowPos();
        QPoint dp(P.x()-x/2,P.y()-x/2);
        QRect rec(dp,QSize(x,x));
        l->setGeometry(rec);
        l->setPixmap(label[index_i][index_j].pixmap()->copy());
        l->setScaledContents(true);
        l->setWindowFlags(Qt::WindowStaysOnTopHint);
        l->show();
    }
    else if(ui->RButton_drag->isChecked()&&event->type()==QEvent::MouseButtonRelease){
        l->setVisible(false);
        QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);
        double mx=mouse->windowPos().x();
        double my=mouse->windowPos().y();
        int i=int(mx-100)/(610/N);
        int j=int(my-100)/(610/N);
        if(mx<=100|mx>=710|my<=100|my>=710)
        {
            label[index_i][index_j].setStyleSheet("border: 2px solid  #666666");
            PC=1;
            return true;
        }

        pixLatter=label[i][j].pixmap()->copy();
        label[i][j].setPixmap(pixFormer);
        label[index_i][index_j].setPixmap(pixLatter);
        label[index_i][index_j].setStyleSheet("border: 2px solid  #666666");
        if(i!=index_i||j!=index_j)
        {
            int step=ui->label_steps->text().toUtf8().toInt();
            step++;
            ui->label_steps->setText(QString::number(step));
        }
        PC=1;
        if(isSuccessful()){
            timer->stop();
            timeRun=false;
            QMessageBox::about(this,"提示","恭喜您，挑战成功！");
            //计算时间、步数
            QString str=ui->label_time->text();
            QStringList strlist=str.split(":");
            int h=strlist[0].toUtf8().toInt();
            int m=strlist[1].toUtf8().toInt();
            int s=strlist[2].toUtf8().toInt();
            double time=h*3600+m*60+s;
            double steps=ui->label_steps->text().toUtf8().toInt();
            //计算得分
            double scores=50*N/time+50*N/steps;
            records.append(scores);
            QMessageBox::about(this,"提示","您的本次得分为："+QString::number(scores));
            //更新本地记录文件
            this->writeRecords();
        }
        return true;
    }
    else
        return QObject::eventFilter(obj,event);
}

/*--------------------------------------判断拼图是否完成----------------------------------------*/
bool MainWindow::isSuccessful(){
    bool flag=true;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(pix[i][j].toImage()!=label[i][j].pixmap()->toImage()){
                flag=false;
                break;
            }
    return flag;
}


/*----------------------------------------释放内存---------------------------------------------*/
void MainWindow::Delete(){
    for(int i=0;i<N;i++)
    {
        delete[] pix[i];
        delete[] label[i];
    }
    delete l;
    delete pix;
    delete label;
    l=new QLabel;
}


/*-------------------------------------“难度重选”窗体相关---------------------------------------*/
void MainWindow::Form_reselection_Open(){
    form_reselection.show();
}
void MainWindow::Form_reselection_Button_easy(){
    this->Delete();
    form_reselection.close();
    //重新初始化
    N=3;
    this->Load();
}
void MainWindow::Form_reselection_Button_hard(){
    this->Delete();
    form_reselection.close();
    //重新初始化
    N=4;
    this->Load();
}
void MainWindow::Form_reselection_Button_hell(){
    this->Delete();
    form_reselection.close();
    //重新初始化
    N=5;
    this->Load();
}
void MainWindow::Form_reselection_Button_confirm(){
    this->Delete();
    form_reselection.close();
    //重新初始化
    N=form_reselection.ui->Edit_custom->text().toUtf8().toInt();
    this->Load();
}


/*-------------------------------------“图片重选”窗体相关---------------------------------------*/
void MainWindow::Form_choseimg_Open(){
    form_choseimg.show();
}
void MainWindow::Form_choseimg_Button_1()
{
    flag=1;
    form_choseimg.close();
    this->Delete();
    this->Load();
}
void MainWindow::Form_choseimg_Button_2()
{
    flag=2;
    form_choseimg.close();
    this->Delete();
    this->Load();
}
void MainWindow::Form_choseimg_Button_3()
{
    flag=3;
    form_choseimg.close();
    this->Delete();
    this->Load();
}
void MainWindow::Form_choseimg_Button_4()
{
    flag=4;
    form_choseimg.close();
    this->Delete();
    this->Load();
}


/*-------------------------------------“查看原图”窗体相关---------------------------------------*/
void MainWindow::Form_original_Open(){
    form_original.ui->label->setPixmap(pix0);
    form_original.show();
}

/*-------------------------------------“选择本地图片”相关---------------------------------------*/
void MainWindow::chooseLocalImg(){
    path=QFileDialog::getOpenFileName(nullptr,"选择本地图片",".","*.jpg *.png ");
    //用户选择关闭，直接return
    if(path=="")
        return;
    else{
        flag=5;
        this->Delete();
        this->Load();
    }
    if(pix0.isNull()){
        QMessageBox::warning(this,"警告","不支持所选图片！");
        QMessageBox::information(this,"提示","请重新选择图片或使用本地图片。");
    }
}


/*-------------------------------------图片打乱重排列---------------------------------------*/
void MainWindow::upsetImg(){
    //计时器清零，计步器清零
    timer->stop();
    ui->label_time->setText("00:00:00");
    timeRun=false;
    ui->label_steps->setText("0");

    //（这里应该是平方关系而非简单线性关系）
    srand((unsigned int)time(nullptr));
    for(int i=0;i<N*N*1.5;i++){
        int a=rand()%N;
        int b=rand()%N;
        int c=rand()%N;
        int d=rand()%N;
        if(label[c][d].pixmap()->toImage()!=pix[a][b].toImage()&&
                label[a][b].pixmap()->toImage()!=pix[c][d].toImage()){
            QPixmap tmp=label[a][b].pixmap()->copy();
            label[a][b].setPixmap(label[c][d].pixmap()->copy());
            label[c][d].setPixmap(tmp);
        }
    }
}


/*-------------------------------------计时器槽函数---------------------------------------*/
void MainWindow::setTime(){
    QString str=ui->label_time->text();
    QStringList strlist=str.split(":");
    int h=strlist[0].toUtf8().toInt();
    int m=strlist[1].toUtf8().toInt();
    int s=strlist[2].toUtf8().toInt();
    s++;
    if(s==60){
        s=0;
        m++;
    }
    if(m==60){
        m=0;
        h++;
    }
    QString time;
    if(h<10)
        time=time+"0"+QString::number(h);
    else
        time+=QString::number(h);
    time+=":";
    if(m<10)
        time+="0"+QString::number(m);
    else
        time+=QString::number(m);
    time+=":";
    if(s<10)
        time+="0"+QString::number(s);
    else
        time+=QString::number(s);

    ui->label_time->setText(time);
}

/*-------------------------------------本地记录---------------------------------------*/
void MainWindow::readRecords(){
    QFile file("record.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return;
    }
    while(!file.atEnd()){
        QString x=file.readLine();
        x.chop(1);
        records.append(x.toDouble());
    }
    file.close();
}

void MainWindow::writeRecords(){
    QFile file("record.txt");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QMessageBox::warning(this,"警告","本地记录更新失败！");
        exit(0);
    }
    for(int i=0;i<records.length();i++){
        int index=i;
        for(int j=i+1;j<records.length();j++)
            if(records[index]<records[j])
                index=j;
        double tmp=records[i];
        records[i]=records[index];
        records[index]=tmp;
    }
    for(int i=0;i<records.length();i++){
        file.write(QString::number(records[i]).toUtf8());
        file.write(QString('\n').toUtf8());
    }
    file.close();
}

void MainWindow::Form_records_Open(){
    form_records.show();
    form_records.ui->Table_records->setRowCount(records.length());
    for(int i=0;i<records.length();i++){
        form_records.ui->Table_records->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
        form_records.ui->Table_records->setItem(i,1,new QTableWidgetItem(QString::number(records[i])));
    }
}

void MainWindow::Zero(){
    records.clear();
    form_records.ui->Table_records->clearContents();
    form_records.ui->Table_records->setRowCount(0);
    readRecords();
}
