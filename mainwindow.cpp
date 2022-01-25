#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include <cmath>

#include <QTimer>
#include <QString>
#include "consts.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    ui->figure_2->addGraph();
    ui->figure_2->xAxis->setLabel("x");
    ui->figure_2->yAxis->setLabel("phase");
    ui->figure_2->xAxis->setRange(-M_PI, M_PI);

    ui->figure->addGraph();
    ui->figure->xAxis->setLabel("x");
    ui->figure->yAxis->setLabel("amplitude");
    ui->figure->xAxis->setRange(-M_PI, M_PI);


    ui->doubleSpinBox_xl->setValue(-M_PI);
    ui->doubleSpinBox_xh->setValue(+M_PI);
    ui->spinBox_pints->setValue(200);


    ui->lineEdit_mass->setText(QString::number(mathQM::electroneMass));
    connect(timer, &QTimer::timeout, this, &MainWindow::newPlot);
    c=0;
    max_it=1000;

    ui->lineEdit_t->setText(QString::number(c));
    this->ui->figure->yAxis->setRange(0, 0.1);
    this->ui->figure_2->yAxis->setRange(0, 0.1);
    connect(this, &MainWindow::dataChange, [this](){

        double max_y = * std::max_element(std::begin(this->y), std::end(this->y));
        double min_y = * std::min_element(std::begin(this->y), std::end(this->y));


        double max_p = * std::max_element(std::begin(this->p), std::end(this->p));
        double min_p = * std::min_element(std::begin(this->p), std::end(this->p));

        this->ui->figure->graph(0)->setData(this->x,this->y);

        this->ui->figure_2->graph(0)->setData(this->x,this->p);

//        qDebug() << max_y << ui->figure->yAxis->range().maxRange;
        this->ui->figure->yAxis->setRange(std::min(min_y, ui->figure->yAxis->range().lower), std::max(max_y,ui->figure->yAxis->range().upper));
        this->ui->figure_2->yAxis->setRange(std::min(min_p, ui->figure_2->yAxis->range().lower), std::max(max_p,ui->figure_2->yAxis->range().upper));

        this->ui->figure->replot();
        this->ui->figure_2->replot();

        if(start){
            c = c + ui->spinBox_speed->value();
            ui->lineEdit_t->setText(QString::number(c));
        }
    });

}



MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::calcData( QVector<double> &waveNumber, double t)
{

//    y(x.size()), p(x.size());

    size_t N{waveNumber.size()};

    QVector<double> frequency;

    for( const double &k: waveNumber){
        bool ok = false;
        double mass = ui->lineEdit_mass->text().toDouble(&ok);
        if(!ok){
            QMessageBox messageBox;
            messageBox.critical(0,"Error","the mass is invalid(not a number)");
            messageBox.setFixedSize(500,200);
            emit on_pushButton_pause_clicked();
            return;
        }
        double omega {std::pow(k,2) * mathQM::hbar / (2*mathQM::electroneMass)};
        frequency.push_back(omega);
    }


    for(size_t i{}; i<x.size(); i++){
        y[i] = 0;
        p[i] = 0;

        double sines{}, cosines{};

        for(size_t n{}; n<N; n++){
            for(size_t m{n+1}; m<N; m++){
                y[i] += std::cos((waveNumber[n] - waveNumber[m]) * x[i]  - (frequency[n]-frequency[m]) *t);
            }

            sines += std::sin(waveNumber[n]*x[i] - frequency[n]*t);
            cosines += std::cos(waveNumber[n]*x[i] - frequency[n]*t);
        }

        p[i] = std::atan(sines/cosines);

        y[i] = std::sqrt((2.0/static_cast<double>(N)) * y[i] + 1);

    }
}

void MainWindow::newPlot()
{
    double t{c};

    calcData(waveNumber, t);

    emit dataChange();
    if(!start){
        timer->stop();
    }

}

void MainWindow::on_pushButton_start_clicked()
{
    start = true;
    timer->start(10);
}

void MainWindow::on_pushButton_pause_clicked()
{
    start = false;
    timer->stop();
}

void MainWindow::on_lineEdit_t_textEdited(const QString &arg1)
{
    bool ok = false;
    double tmp = ui->lineEdit_t->text().toDouble(&ok);
//    double tmp = arg1.toDouble(&ok);
    if (ok){
        c = tmp;
        newPlot();
    }
}

void MainWindow::on_pushButton_plot_clicked()
{
    x.resize(ui->spinBox_pints->value());

    double xl = ui->doubleSpinBox_xl->value();
    double xh = ui->doubleSpinBox_xh->value();
    if(xh <= xl){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","heigher x should be greater than the lower x");
        messageBox.setFixedSize(500,200);
        emit on_pushButton_pause_clicked();
        return;
    }
    for(size_t i{}; i<x.size(); i++){
        x[i] = (xh-xl) * i/static_cast<double>(ui->spinBox_pints->value()) + xl;
    }
    y.resize(ui->spinBox_pints->value());
    p.resize(ui->spinBox_pints->value());


    this->ui->figure->yAxis->setRange(0, 0.1);
    this->ui->figure_2->yAxis->setRange(0, 0.1);
    ui->figure->xAxis->setRange(xl, xh);
    ui->figure_2->xAxis->setRange(xl, xh);

    waveNumber.clear();
    QStringList ks = ui->lineEdit_kArray->text().split(",");

    for( QString &k: ks){
        bool ok = false;
        double tmp = k.toDouble(&ok);
        if(ok){
            waveNumber.push_back(tmp);
        }
    }
    ui->spinBox_N->setValue(waveNumber.size());
    if(waveNumber.size() == 0){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","All input values for K are invalid(not a number)");
        messageBox.setFixedSize(500,200);
        emit on_pushButton_pause_clicked();
        return;
    }
    newPlot();

}

void MainWindow::on_lineEdit_kArray_textEdited(const QString &arg1)
{
    ui->spinBox_N->setValue(arg1.split(",").size());
}

void MainWindow::on_pushButton_emass_clicked()
{
    ui->lineEdit_mass->setText(QString::number(mathQM::electroneMass));
}
