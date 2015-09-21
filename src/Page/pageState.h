#ifndef PAGESTATE_H
#define PAGESTATE_H

/**
 * @brief The PageState enum Page flag state for the main-contentWidget of MainWindow.
 */
enum PageState
{

    Start, Module, Help , Warning, LabView, LabViewDock, Scanner, CNC, Printer, ScannerLaser, ScannerPrimesense, Horus, FabScan, ConfigureCNC, Update, CalibratePlate, DockPage, Monitoring
};
/**
 * @brief The ReturnDialog enum <DERP>
 */
enum ReturnDialog
{
    Close, Save
};

#endif // PAGESTATE_H
