#include "aboutapplicationdialog.h"
#include "BAVersion.h"
#include "DesignerHelper.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDate>

#include <iostream>

AboutApplicationDialog::AboutApplicationDialog(QWidget *parent)
    : QDialog(parent)

{
    QColor bgColor(240,240,240,255);
    QPalette palette;
    palette.setColor(QPalette::Background, bgColor);
    setAutoFillBackground(true);
    setPalette(palette);

    setFixedSize(550, 250);
    setWindowTitle("About BornAgain");

    //setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    setWindowFlags( Qt::Dialog );


    QFont titleFont;
    titleFont.setPointSize(DesignerHelper::getLabelFontSize() + 2);
    titleFont.setBold(true);

    QFont normalFont;
    normalFont.setPointSize(DesignerHelper::getLabelFontSize());
    normalFont.setBold(false);


    QPixmap logo(":/images/about_icon.png");
    QLabel *logoLabel = new QLabel;
    logoLabel->setPixmap(logo.scaled(120,120,Qt::KeepAspectRatio));


    QLabel *aboutTitleLabel = new QLabel(QString::fromStdString(BornAgain::GetName()).append(" ver. ").append(QString::fromStdString(BornAgain::GetVersionNumber())));
    aboutTitleLabel->setFont(titleFont);
    aboutTitleLabel->setContentsMargins(0,0,0,15);

    QDate date = QDate::currentDate();

    QString copyright = QString("Copyright: Forschungszentrum Jülich GmbH ").append(date.toString("yyyy"));
    QLabel *copyrightLabel = new QLabel(copyright);
    copyrightLabel->setFont(normalFont);
    //copyrightLabel->setWordWrap(true);
    copyrightLabel->setContentsMargins(0,0,0,15);

    QString description = "A software to simulate and fit grazing incidence small angle scattering (GISAS) using distorted wave Born approximation (DWBA).";
    QLabel *descriptionLabel = new QLabel(description);
    descriptionLabel->setFont(normalFont);
    descriptionLabel->setWordWrap(true);


    QLabel *linkLabel = new QLabel();
    linkLabel->setTextFormat(Qt::RichText);
    linkLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    linkLabel->setText("<a href=\"http://www.bornagainproject.org\">www.bornagainproject.org</a>");
    linkLabel->setOpenExternalLinks(true);


    QVBoxLayout *logoLayout = new QVBoxLayout;
    logoLayout->addWidget(logoLabel);
    logoLayout->addStretch(1);
    logoLayout->setContentsMargins(5,5,5,5);

    QVBoxLayout *textLayout = new QVBoxLayout;
    textLayout->addWidget(aboutTitleLabel);
    textLayout->addWidget(descriptionLabel);
    textLayout->addStretch(1);
    textLayout->addWidget(copyrightLabel);
    textLayout->addWidget(linkLabel);
    textLayout->addStretch(1);
    textLayout->setContentsMargins(0,5,5,5);


    QHBoxLayout *detailsLayout = new QHBoxLayout;
    detailsLayout->addLayout(logoLayout);
    detailsLayout->addLayout(textLayout);


    m_closeButton = new QPushButton(tr("Close"));
    connect(m_closeButton, SIGNAL(clicked()), this, SLOT(reject()));

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(m_closeButton);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(detailsLayout);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);
}

