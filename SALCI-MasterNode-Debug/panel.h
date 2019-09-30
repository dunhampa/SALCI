#ifndef PANEL_H
#define PANEL_H

struct PANEL {
    int addr;
    int channel;
    int toggle_delay;
    double sensitvity;
    int anIns[12];
    int data[12];
    int ambient[12];
    int keyval[12];
    bool pintog[12];
    bool lastval[12];
    bool toggle;
};

#endif
