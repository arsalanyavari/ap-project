QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddProject.cpp \
    AddSuggestions.cpp \
    AddWrong.cpp \
    Answer.cpp \
    Client.cpp \
    ClientList.cpp \
    EditClient.cpp \
    Marketing.cpp \
    MessageInbox.cpp \
    NewMessages.cpp \
    Operator.cpp \
    ProjectList.cpp \
    SendBox.cpp \
    SuggestionsList.cpp \
    Support.cpp \
    SureWarning.cpp \
    WrongList.cpp \
    bossclass.cpp \
    bossprofile.cpp \
    client_list.cpp \
    editemployee.cpp \
    main.cpp \
    mainwindow.cpp \
    boss.cpp \
    send_box.cpp \
    add_employee.cpp \
    employee_list.cpp \
    human.cpp \
    employee.cpp \
    operator.cpp \
    profile.cpp \
    changepassword.cpp \
    warning.cpp \
    addclient.cpp

HEADERS += \
    AddProject.h \
    AddSuggestions.h \
    AddWrong.h \
    Answer.h \
    Client.h \
    ClientList.h \
    EditClient.h \
    Marketing.h \
    MessageInbox.h \
    NewMessages.h \
    Operator.h \
    ProjectList.h \
    SendBox.h \
    SuggestionsList.h \
    Support.h \
    SureWarning.h \
    WrongList.h \
    bossclass.h \
    bossprofile.h \
    client_list.h \
    editemployee.h \
    mainwindow.h \
    boss.h \
    send_box.h \
    add_employee.h \
    employee_list.h \
    human.h \
    employee.h \
    operator.h \
    profile.h \
    changepassword.h \
    warning.h \
    addclient.h

FORMS += \
    AddProject.ui \
    AddSuggestions.ui \
    AddWrong.ui \
    Answer.ui \
    ClientList.ui \
    EditClient.ui \
    Marketing.ui \
    MessageInbox.ui \
    NewMessages.ui \
    Operator.ui \
    ProjectList.ui \
    SendBox.ui \
    SuggestionsList.ui \
    Support.ui \
    SureWarning.ui \
    WrongList.ui \
    bossprofile.ui \
    client_list.ui \
    editemployee.ui \
    mainwindow.ui \
    boss.ui \
    send_box.ui \
    add_employee.ui \
    employee_list.ui \
    operator.ui \
    profile.ui \
    changepassword.ui \
    warning.ui \
    addclient.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc \
    resources.qrc
