#ifndef PAGESTATE_H
#define PAGESTATE_H

/**
 * @brief The PageState enum Page flag state for the main-contentWidget of MainWindow.
 */
enum PageState
{
    Start, Help, Module, Warning, LabView, LabViewDock, Scanner, CNC, Printer, ScannerLaser, ScannerPrimesense, ConfigurCNC, DynamicTest, Update
};
/**
 * @brief The ReturnDialog enum <DERP>
 */
enum ReturnDialog
{
    Close, Save
};

#endif // PAGESTATE_H
