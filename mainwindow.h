#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <tuple>
#include <complex>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void calcData( QVector<double> &, double);
public slots:
    void newPlot();

signals:
    void dataChange();
private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_pause_clicked();

    void on_lineEdit_t_textEdited(const QString &arg1);

    void on_pushButton_plot_clicked();

    void on_lineEdit_kArray_textEdited(const QString &arg1);

    void on_pushButton_emass_clicked();

    void on_checkBox_sqrt_toggled(bool checked);

    void on_checkBox_comp_toggled(bool checked);

    void on_checkBox_pdf_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    double c;
    int max_it;

    int speed{5};

    bool start = false;

    QVector<double> x;
    QVector<double> y, y_2,y_3, y_0;
    QVector<std::complex<double>> y_comp;
    QVector<double> p;

    QVector<double> waveNumber;
};

#endif // MAINWINDOW_H
