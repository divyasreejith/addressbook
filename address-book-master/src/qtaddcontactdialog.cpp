#include "contact.h"
#include "qtaddcontactdialog.h"
#include <QDialog>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QColor>

QtAddContactDialog::QtAddContactDialog(Contact &c, QWidget *parent, Qt::WindowFlags f) :
            QDialog(parent, f), contactForm(new QtContactForm()), outContact(c)
{
    QVBoxLayout *mainContainer = new QVBoxLayout();
    mainContainer->addLayout(contactForm);

    QHBoxLayout *buttonContainer = new QHBoxLayout();
    QPushButton *addButton = new QPushButton("ADD");
    QPushButton *cancelButton = new QPushButton("CANCEL");
    
    buttonContainer->addWidget(addButton);
    buttonContainer->addWidget(cancelButton);
    mainContainer->addLayout(buttonContainer);

    connect(addButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    setLayout(mainContainer);
    setWindowTitle("New Contact");
}
/*
QPushButton *backgroundColourButton;
QColor *backgroundColour;
backgroundColour->setRgb(0,25,0); //example colour, I could later manage to utilize this variable with a QColorDialog
QPalette Pal(palette());
Pal.setColor(QPalette::Button, backgroundColour->rgb());
backgroundColourButton->setAutoFillBackground(true);
backgroundColourButton->setPalette(Pal);
*/
void QtAddContactDialog::accept()
{
    outContact.firstName = contactForm->firstNameField->text().toStdString();
    outContact.lastName = contactForm->lastNameField->text().toStdString();
    outContact.address = contactForm->addressField->text().toStdString();
    outContact.phoneNumber = contactForm->phoneNumberField->text().toStdString();
    outContact.email = contactForm->emailField->text().toStdString();
    outContact.zipcode = contactForm->zipcodeField->text().toStdString();
    QDialog::accept();
}
