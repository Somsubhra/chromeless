! include( ../common.pri ) { error( Could not find the common.pri file! ) }

QT += widgets \
    webkitwidgets

TEMPLATE = app

SOURCES += \
    main.cpp \
    controlpanel.cpp \
    appwindow.cpp \
    appview.cpp \
    appreader.cpp \
    application.cpp

HEADERS += \
    controlpanel.h \
    appwindow.h \
    appview.h \
    appreader.h \
    application.h

# --- QuaZip ---
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../third-party/quazip/release/ -lquazip
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../third-party/quazip/debug/ -lquazip
else:unix: LIBS += -L$$OUT_PWD/../third-party/quazip/ -lquazip

INCLUDEPATH += $$PWD/../third-party/quazip
DEPENDPATH += $$PWD/../third-party/quazip

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../third-party/quazip/release/libquazip.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../third-party/quazip/debug/libquazip.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../third-party/quazip/release/quazip.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../third-party/quazip/debug/quazip.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../third-party/quazip/libquazip.a

# --- zlib ---
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../third-party/zlib/release/ -lzlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../third-party/zlib/debug/ -lzlib
else:unix: LIBS += -L$$OUT_PWD/../third-party/zlib/ -lzlib

INCLUDEPATH += $$PWD/../third-party/zlib
DEPENDPATH += $$PWD/../third-party/zlib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../third-party/zlib/release/libzlib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../third-party/zlib/debug/libzlib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../third-party/zlib/release/zlib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../third-party/zlib/debug/zlib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../third-party/zlib/libzlib.a