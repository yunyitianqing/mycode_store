LIBS += /usr/local/lib/libopencv_core.so \
    /usr/local/lib/libopencv_highgui.so \
    /usr/local/lib/libopencv_ml.so \
    /usr/local/lib/libopencv_imgproc.so \
    /usr/local/lib/libzmq.so

SOURCES += \
    img_pro.cpp \
    img_show.cpp \
    main.cpp

HEADERS += \
    img_pro.h \
    img_show.h
