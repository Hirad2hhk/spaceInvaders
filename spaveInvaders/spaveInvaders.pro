QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += multimedia

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Player.cpp \
    block.cpp \
    bullet.cpp \
    bullet2.cpp \
    enemy.cpp \
    game.cpp \
    health.cpp \
    main.cpp \
    score.cpp

HEADERS += \
    Player.h \
    block.h \
    bullet.h \
    bullet2.h \
    enemy.h \
    game.h \
    health.h \
    score.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
