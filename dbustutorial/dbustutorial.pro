
SOURCES += \
    main.cpp \
    demo.cpp \
    src/demoifadaptor.cpp

HEADERS += \
    demo.h \
    src/demoifadaptor.h

CONFIG += \
    qdbus \
    link_pkgconfig

PKGCONFIG += gstreamer-0.10

OTHER_FILES += \
    src/src.pro
