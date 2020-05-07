#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tube.h"
#include <QtCharts/QtCharts>
#include <math.h>
#include <string>
#include <fstream>
#include <QDesktopServices>
#include "mpi.h"   // подключаем библиотеку для работы с mpi

using namespace QtCharts;

QChartView *chartView;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{

	ui->setupUi(this);
	QChartView *chartViewp = new QChartView(this);
	chartViewp->hide();
	// Добавляем его в горизонтальный Layout
	chartView = chartViewp;
	ui->pushButton_2->setVisible(false);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	tube result;
	result.temperature.resize(5);
	bool changing_x0_xn = false;
	double Umax = 1000;
	double dx = 0.01;
	int number_int;
	if(ui->radioButton->isChecked() == true){
		// изменённая часть ------------------------
		/*   была такой  
			for(int i=0; i<5; i++)
				result.temperature[i].resize(101);
			for(int i=0; i<51; i++){
				result.temperature[0][i] = 2*Umax*dx*i;
			}
			for(int i=51; i<101; i++){
				result.temperature[0][i] = 2*Umax - 2*Umax*dx*i;
			}
		*/

		// изменил на такое -------------------------------------
		vector<double> buffer;
		buffer.resize(101, 0);

		for(int i = 0; i < 5; i++){
			result.temperature[i].resize(101, 0);
		}

		int errorCode;
		if ((errorCode = MPI_Init(0, 0)) != 0){
			cout << "Ошибка запуска, выполнение остановлено " << endl;
			MPI_Abort(MPI_COMM_WORLD, errorCode);
			return errorCode;
		}
		int myid;
		MPI_Comm_rank(MPI_COMM_WORLD,&myid);  //  получаем в myid - id нащего процесса

		if(myid == 0){
			for(int i = 0; i < 51; i++){
				buffer[i] = 2. * Umax * dx * i;
			}
		} else if(myid == 1){
			for(int i = 51; i < 101; i++){
				buffer[i] = 2. * Umax  - 2. * Umax * dx * i;
			}
		}

		MPI_Reduce(&(*buffer.begin()), &(*result.temperature[0].begin()), 101,  MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
		MPI_Finalize();


	}
	if(ui->radioButton_2->isChecked() == true){
		for(int i=0; i<5; i++)
			result.temperature[i].resize(101);
		for(int i=0; i<101; i++){
			result.temperature[0][i] = sin(3.14159265*i*dx);
		}
	}
	if(ui->radioButton_3->isChecked() == true){
		dx = 0.05;
		for(int i=0; i<5; i++)
			result.temperature[i].resize(81);
		for(int i=0; i<81; i++){
			result.temperature[0][i] = 2*i*dx+1;
		}
	}
	if(ui->radioButton_4->isChecked() == true){
		changing_x0_xn = true;
		for(int i=0; i<5; i++)
			result.temperature[i].resize(501);
		for(int i=0; i<501; i++){
			result.temperature[0][i] = (i*dx)*(i*dx)/2;
		}
	}
	if(ui->radioButton_5->isChecked() == true){
		for(int i=0; i<5; i++)
			result.temperature[i].resize(101);
		for(int i=0; i<101; i++){
			result.temperature[0][i] = (i*dx)*4*(1-dx*i);
		}
	}
	if(ui->radioButton_6->isChecked() == true){
		dx = 0.05;
		for(int i=0; i<5; i++)
			result.temperature[i].resize(41);
		for(int i=0; i<41; i++){
			result.temperature[0][i] = (i*dx)*(i*dx)/4;
		}
	}
	result.solve(dx, changing_x0_xn);
	chartView->show();
	ui->gridLayout->addWidget(chartView);
	QChart *chart = new QChart();
	QLineSeries *series = new QLineSeries();
	QLineSeries *series2 = new QLineSeries();
	QLineSeries *series3 = new QLineSeries();
	QLineSeries *series4 = new QLineSeries();
	QLineSeries *series5 = new QLineSeries();
	for (int i=0;i<result.temperature[0].size();i++)
	{
		series->append(dx*i, result.temperature[0][i]);
		series2->append(dx*i, result.temperature[1][i]);
		series3->append(dx*i, result.temperature[2][i]);
		series4->append(dx*i, result.temperature[3][i]);
		series5->append(dx*i, result.temperature[4][i]);
	}
	//name it
	series->setName("dt = 0");
	series2->setName("dt = 1000");
	series3->setName("dt = 5000");
	series4->setName("dt = 10000");
	series5->setName("dt = 20000");
	chart->addSeries(series);
	chart->addSeries(series2);
	chart->addSeries(series3);
	chart->addSeries(series4);
	chart->addSeries(series5);
	// Настройка осей графика
	QValueAxis *axisX = new QValueAxis();
	axisX->setTitleText("x, у.е.");
	axisX->setLabelFormat("%g");
	axisX->setTickCount(1);
	chart->addAxis(axisX, Qt::AlignBottom);
	series->attachAxis(axisX);
	series2->attachAxis(axisX);
	series3->attachAxis(axisX);
	series4->attachAxis(axisX);
	series5->attachAxis(axisX);
	QValueAxis *axisY = new QValueAxis();
	axisY->setTitleText("U, у.е.");
	axisY->setLabelFormat("%g");
	axisY->setTickCount(5);
	chart->addAxis(axisY, Qt::AlignLeft);
	series->attachAxis(axisY);
	series2->attachAxis(axisY);
	series3->attachAxis(axisY);
	series4->attachAxis(axisY);
	series5->attachAxis(axisY);
	// Устанавливаем график в представление
	chartView->setChart(chart);
	//Запись в файл результатов
	string line;
	std::ofstream out; // поток для записи
	out.open("result.txt"); // окрываем файл для записи
	if (out.is_open())
	{
		out <<"dt = "<<0.1*dx*dx<<" U(x,t)" << endl;
		out << "J dt = 0 dt = 1000 dt = 5000 dt = 10000 dt = 20000"<<endl<<endl;
		//out <<line<<endl;
		for(int i=0; i<result.temperature[0].size(); i++){
			//out << i+1;
			line = to_string(i+1);
			out<<line;
			for(int k=0; k<7-line.size(); k++){
				out<<" ";
			}
			for(int j=0; j<result.temperature.size(); j++){
				//out <<result.temperature[j][i];
				//number_int = result.temperature[j][i];
				line = to_string(result.temperature[j][i]);
				out<<line;
				for(int k=0; k<18-line.size(); k++){
					out<<" ";
				}
			}
			out<<endl;
		}
	}
	ui->pushButton_2->setVisible(true);

}

void MainWindow::on_pushButton_2_clicked()
{
	QDesktopServices openfile;
	openfile.openUrl(QUrl("file:///C:/Users/Serega/Desktop/Labs_numerical_methods/build-lab2_tube-Desktop_Qt_5_13_2_MinGW_32_bit-Debug/result.txt", QUrl::TolerantMode));
}
