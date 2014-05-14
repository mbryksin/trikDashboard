#include "customplotwidget.h"

CustomPlotWidget::CustomPlotWidget(int axis, QString title) :
    DashboardWidget(axis, title)
{
    connect(paintTimer, &QTimer::timeout, this, &CustomPlotWidget::paintWidget);

    labelNumders = new QLabel("");
    labelNumders->setAlignment(Qt::AlignCenter);

//    layout->addWidget(titleLabel);

    plot = new QCustomPlot();
    plot->setWindowTitle(title);
    layout->addWidget(plot);

    layout->addWidget(labelNumders);

    setLayout(layout);

    init();
}

void CustomPlotWidget::addGraph(int n, QColor color)
{

    plot->addGraph();
    plot->graph(2*n)->setPen(QPen(color));
    plot->addGraph();
    plot->graph(2*n+1)->setPen(QPen(color));
    plot->graph(2*n+1)->setLineStyle(QCPGraph::lsNone);
    plot->graph(2*n+1)->setScatterStyle(QCP::ssDisc);

}

void CustomPlotWidget::init()
{
//    include this section to fully disable antialiasing for higher performance:
    /*
    plot->setNotAntialiasedElements(QCP::aeAll);
    QFont font;
    font.setStyleStrategy(QFont::NoAntialias);
    plot->xAxis->setTickLabelFont(font);
    plot->yAxis->setTickLabelFont(font);
    plot->legend->setFont(font);
    */

    plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    plot->xAxis->setDateTimeFormat("mm:ss");
    plot->xAxis->setAutoTickStep(false);
    plot->xAxis->setTickStep(1);
    plot->setupFullAxesBox();
//    make left and bottom axes transfer their ranges to right and top axes:
    connect(plot->xAxis, SIGNAL(rangeChanged(QCPRange)),
            plot->xAxis2, SLOT(setRange(QCPRange)));
    connect(plot->yAxis, SIGNAL(rangeChanged(QCPRange)),
            plot->yAxis2, SLOT(setRange(QCPRange)));

    for (int i = 0; i < axis; i++)
    {
        addGraph(i, colors[i]);
    }

}

void CustomPlotWidget::paintWidget()
{
    QString buf;
    buf.sprintf("%g %g %g", data[0], data[1], data[2]);
    labelNumders->setText(buf);

    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    for (int n = 0; n < axis; n++)
    {
        plot->graph(2*n)->addData(key, data[n]);
        plot->graph(2*n+1)->clearData();
        plot->graph(2*n+1)->addData(key, data[n]);
        plot->graph(2*n)->removeDataBefore(key - 5);
        plot->graph(2*n)->rescaleValueAxis(true);
        plot->xAxis->setRange(key + 0.2, 5, Qt::AlignRight);
        plot->replot();
    }

}