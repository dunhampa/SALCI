#ifndef PANEL_H
#define PANEL_H

#define arraySize 16 


struct PANEL {
    int channel;
    int toggle_delay;
    double sensitvity;
    int anIns[arraySize];
    int data[arraySize];
    int ambient[arraySize];
    int keyval[arraySize];
    bool pintog[arraySize];
    bool lastval[arraySize];
    bool toggle;
};

#endif
