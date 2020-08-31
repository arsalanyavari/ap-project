#-------------------------------------------------
#
# Project created by QtCreator 2020-08-19T01:27:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CRM
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    ../an/add_employee.cpp \
    ../an/addclient.cpp \
    ../an/AddProject.cpp \
    ../an/AddSuggestions.cpp \
    ../an/AddWrong.cpp \
    ../an/Answer.cpp \
    ../an/boss.cpp \
    ../an/bossclass.cpp \
    ../an/bossprofile.cpp \
    ../an/changepassword.cpp \
    ../an/Client.cpp \
    ../an/client_list.cpp \
    ../an/ClientList.cpp \
    ../an/EditClient.cpp \
    ../an/editemployee.cpp \
    ../an/Employee.cpp \
    ../an/employee_list.cpp \
    ../an/Human.cpp \
    ../an/Marketing.cpp \
    ../an/MessageInbox.cpp \
    ../an/NewMessages.cpp \
    ../an/operator.cpp \
    ../an/Profile.cpp \
    ../an/ProjectList.cpp \
    ../an/send_box.cpp \
    ../an/SendBox.cpp \
    ../an/SuggestionsList.cpp \
    ../an/Support.cpp \
    ../an/SureWarning.cpp \
    ../an/warning.cpp \
    ../an/WrongList.cpp

HEADERS += \
        mainwindow.h \
    ../an/add_employee.h \
    ../an/addclient.h \
    ../an/AddProject.h \
    ../an/AddSuggestions.h \
    ../an/AddWrong.h \
    ../an/Answer.h \
    ../an/boss.h \
    ../an/bossclass.h \
    ../an/bossprofile.h \
    ../an/changepassword.h \
    ../an/Client.h \
    ../an/client_list.h \
    ../an/ClientList.h \
    ../an/EditClient.h \
    ../an/editemployee.h \
    ../an/Employee.h \
    ../an/employee_list.h \
    ../an/employeeslist.h \
    ../an/Human.h \
    ../an/Marketing.h \
    ../an/MessageInbox.h \
    ../an/NewMessages.h \
    ../an/operator.h \
    ../an/Profile.h \
    ../an/ProjectList.h \
    ../an/send_box.h \
    ../an/SendBox.h \
    ../an/SuggestionsList.h \
    ../an/Support.h \
    ../an/SureWarning.h \
    ../an/warning.h \
    ../an/WrongList.h

FORMS += \
        mainwindow.ui \
    ../an/add_employee.ui \
    ../an/addclient.ui \
    ../an/AddProject.ui \
    ../an/AddSuggestions.ui \
    ../an/AddWrong.ui \
    ../an/Answer.ui \
    ../an/boss.ui \
    ../an/bossprofile.ui \
    ../an/changepassword.ui \
    ../an/client_list.ui \
    ../an/ClientList.ui \
    ../an/EditClient.ui \
    ../an/editemployee.ui \
    ../an/employee_list.ui \
    ../an/Marketing.ui \
    ../an/MessageInbox.ui \
    ../an/NewMessages.ui \
    ../an/Operator.ui \
    ../an/Profile.ui \
    ../an/ProjectList.ui \
    ../an/send_box.ui \
    ../an/SendBox.ui \
    ../an/SuggestionsList.ui \
    ../an/Support.ui \
    ../an/SureWarning.ui \
    ../an/warning.ui \
    ../an/WrongList.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../an/file.json \
    ../an/message.json \
    ../an/calls.pro.user

RESOURCES += \
    ../an/resources.qrc
