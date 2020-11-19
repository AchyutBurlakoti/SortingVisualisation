QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    elements/button.cpp \
    renderer/canvas.cpp \
    elements/combobox.cpp \
    main.cpp \
    renderer/rectangle.cpp \
    renderer/renderer.cpp \
    elements/slider.cpp \
    sorting.cpp \
    elements/widget.cpp \
    window/window.cpp

HEADERS += \
    sortings/bubblesort.h \
    elements/button.h \
    renderer/canvas.h \
    elements/combobox.h \
    sortings/mergesort.h \
    sortings/quicksort.h \
    renderer/rectangle.h \
    renderer/renderer.h \
    elements/slider.h \
    sorting.h \
    elements/widget.h \
    window/window.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
